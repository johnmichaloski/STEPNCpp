//
// SymbolTable.cpp
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.




template <class SymbolT>
_variant_t CSymbolTableT<SymbolT>::GetValue(CString tag)
{
	SymbolsIterator it = m_symbols.find(tag);
	if(it!=m_symbols.end())
		return (*it).second->m_value;
	return _variant_t((BSTR) "");
}
template <class SymbolT>
CStringVector	CSymbolTableT<SymbolT>::GetUnsortedSectionSymbols(CString section)
{
	SymbolsIterator it =  m_symbols.find(section);
	if(it == m_symbols.end())
		return CStringVector();

	return sectionsmap.Find(section);
}

/// returns list of parameters in a section. Parameter name is returned, not with section prepended.
template <class SymbolT>
CStringVector CSymbolTableT<SymbolT>::GetSectionSymbols(CString section)
{
	CStringVector symbols;
	// FIXME: this is wrong. Maybe reason for tree...
	SymbolsIterator it =  m_symbols.find(section);
	if(it != m_symbols.end())
	{
		it++;
		for(; it!=m_symbols.end(); it++)
		{
			if((*it).second->m_type!=SymbolTable::LEAF)
				break;
			symbols.push_back((*it).second->m_name);
		}

	}
	return symbols;
}


template <class SymbolT>
_variant_t CSymbolTableT<SymbolT>::GetSymbolValue(CString section, CString tag, variant_t var)
{
	CString szTag = section + "." + tag;
	CSymbolPtr symbol = GetSymbol(szTag);
	if(symbol!=NULL)
	{
		return symbol->m_value; 
	}
	return  var;
}

template <class SymbolT>
HRESULT CSymbolTableT<SymbolT>::SetSymbolValue(CString section, CString tag, variant_t var)
{	
	CString szTag = section + "." + tag;
	CSymbolPtr symbol;
	if((symbol=GetSymbol(szTag))!=NULL)
	{
		symbol->m_value=var;
		return S_OK;
	}
	return E_FAIL;

}


template <class SymbolT>
CString CSymbolTableT<SymbolT>::ToString(CString section)
{

	//// FIXME:
	CString tmp;
	SymbolsIterator it, endit;
	if(section.IsEmpty())
	{
		it=m_symbols.begin();
		endit=m_symbols.end();

	}
	else
	{
		it =  m_symbols.find(section);
		if(it==m_symbols.end() ||  endit==m_symbols.end())
			return _T("");
	}

	for(; it!=endit; it++)
	{
		if((*it).second->m_type== SymbolTable::ROOT )
		{
			continue;
		}
		else if((*it).second->m_type== SymbolTable::BRANCH )
		{
			tmp+=StrFormat(_T("[%s]\n"),   (*it).second->m_section);
		}	
		else
		{
			try {
					tmp+=StrFormat(_T("%s=%s\n"),   (*it).second->m_name, (LPCTSTR) (_bstr_t)  (*it).second->m_value);
			}
			catch(...){}

		}

	}
	return tmp;
}

template <class SymbolT>
HRESULT CSymbolTableT<SymbolT>::AddSymbolItem(CString section, CString parameter, CString value, VARTYPE vt, CString sDefaultValue)
{
	CSymbolPtr symbol = new SymbolT(SymbolTable::LEAF,section, parameter) ;
	try 
	{
		symbol->m_value= _variant_t((LPCTSTR) value);
		//m_tree
		if(vt!=VT_EMPTY)
			symbol->vt = vt;

		if(symbol->vt != VT_USERDEFINED )
			symbol->m_value.ChangeType(symbol->vt);

		if(sDefaultValue.GetLength()>0)
		{
			symbol->m_defaultValue=_variant_t((LPCTSTR)sDefaultValue);
			symbol->m_defaultValue.ChangeType(symbol->vt);
		}
		m_symbols[parameter] = symbol;
		sectionsmap.Add(section, parameter);
	}
	catch(...)
	{
		return E_FAIL;
	}
	return S_OK;
}
#if 0
template <class SymbolPtr>
CString CSymbolTableT<SymbolPtr>::ParseSection(CString iniSection)
{
	CString errstr="";
	//iniSection.Replace(";", "\n", "");
	unsigned int i;

	CString tmp = iniSection.Mid(1, iniSection.Find(_T("]")) +1);
	tmp.Trim();

	CString section = GetIniSectionName(tmp);

	m_symbols[section] = new SymbolT(CSymbol::BRANCH, section, section) ;

	if( OnBeforeParseSection(section, iniSection))
		return errstr;

	CStringVector lines = _Tokenize(iniSection,"\n");
	for(i=0; i< lines.size(); i++)
	{
		GetIniSetting(section, lines[i]);

	}
	return errstr;
}
#endif
template <class SymbolT>
CString CSymbolTableT<SymbolT>::GetIniSectionName(CString &line)
{
	line.Trim();
	if(line.Find(L'[')!=0)
		return _T("");
	if(line.ReverseFind(L']')<0)
		return _T("");
	line.Replace(_T("["), _T(""));
	line.Replace(_T("]"), _T(""));
	line.Trim();
	return line;

}
template <class SymbolT>
HRESULT CSymbolTableT<SymbolT>::GetIniSetting(CString section, CString line)
{
	CStringVector tokens(2, CString(), CString());
	CSymbolPtr symbol;
	int n;
	if( OnBeforeParseLine(section,  line))
		return S_OK;

	if((n=line.Find(_T("=")))<0)
		return E_FAIL;

	//tokens = _Tokenize(line,"=");

	//if(tokens.size()<1)
	//	return E_FAIL;

	//if(tokens.size()==1) // May be blank
	//	tokens.push_back("");
	tokens[0]=line.Mid(0,n);
	tokens[1]=line.Mid(n+1);

	tokens[0].Trim();
	tokens[1].Trim();

	if(tokens[0].GetLength() < 1)
		return E_FAIL;

	CString parameter = tokens[0];
	symbol = new SymbolT(SymbolTable::LEAF,section, parameter) ;
	try 
	{
		//tokens[1].Replace(_T("\""), _T("")); // placeholder - remove double quotes, just for concept for now.
		symbol->m_value= _variant_t((LPCTSTR) tokens[1]);
	}
	catch(...)
	{
		return E_FAIL;
	}

	//OutputDebugString(StrFormat(_T("Add symbol %s \n"), section + _T(".") + parameter));
	m_symbols[section+ _T(".") + parameter] = symbol;
	sectionsmap.Add(section, parameter);
	return S_OK;
}

template <class SymbolT>
CStringVector CSymbolTableT<SymbolT>::ParseIni(CString &contents)
{
	int last =0;
	CString section;
	int i;

	for( i=0; i< contents.GetLength(); i++)
	{ 
		while(::isspace(contents[i]) && i< contents.GetLength()) i++;
		if(contents[i]=='[')
		{
			int start = i;
			while(contents[i]!='\n' && contents[i]!=']' && i< contents.GetLength()) i++;
			if(contents[i]==']')
			{
				if(_Sections.size()>0)
				{
					_Sections.back()._end=start-1;
					Section _section = _Sections.back();
					OnAfterReadSection(section, contents.Mid(_section._first,_section._end-_section._first+1));
				}

				section=contents.Mid(start+1, i-start-1); // omits [  ]
				section.Trim();
				_szSections.push_back(section);
				_Sections.push_back(Section ( section, start));
				m_symbols[section]= new SymbolT(SymbolTable::BRANCH,section, _T("")) ;

				while(contents[i]!='\n' && i< contents.GetLength()) i++;
				_Sections.back()._first=i+1;

			}
		}
		else
		{
			int mark=i;
			// parse parameter=value pair?
			while(contents[i]!='\n' && i< contents.GetLength()) i++;
			GetIniSetting(section, contents.Mid(mark, i-mark+1));


		}

	}

	if(_Sections.size()>0)
	{
		_Sections.back()._end=contents.GetLength()-1;
		Section _section = _Sections.back();
		OnAfterReadSection(section, contents.Mid(_section._first,_section._end-_section._first+1));
	}

	return _szSections;
}
template <class SymbolT>
CStringVector CSymbolTableT<SymbolT>::GetLines(CString sectionname)
{
	CString sectionstr = GetIniSection(sectionname);
	CStringVector lines = CStringVector::Tokenize(sectionstr, "\n");
	for(int i=0; i< lines.size(); i++)
	{
		lines[i].Trim();
		if(lines[i].GetLength() < 1)
		{
			lines.erase(lines.begin() + i);
			i--;
		}
	}
	//if(lines.size() > 0)
	//	lines.erase(lines.begin());
	return lines;
}
template <class SymbolT>
CString CSymbolTableT<SymbolT>::GetIniSection(CString section)
{
	for(int i=0; i< _Sections.size(); i++)
	{
		if(_Sections[i]._name == section)
			return _contents.Mid(_Sections[i]._first,_Sections[i]._end-_Sections[i]._first+1);
	}
	return "";
}
template <class SymbolT>
CString CSymbolTableT<SymbolT>::FromInifile(CString szProgramIniFile)
{
	CString sTmp;

	try {
		if(ATL::ATLPath::FileExists(szProgramIniFile))
		{
			_contents = ReadAFile(szProgramIniFile);
			ReplacePattern(_contents, _T("#"), _T("\n"), _T("\n"));
			_contents.Replace(_T("\r"), _T(""));
			int n =_contents.Find(_T("\\\n"));
			 n = _contents.Replace(_T("\\\n"), _T(" "));
			OutputDebugString(_contents);

			if(_contents.IsEmpty())
				throw StrFormat(_T("Items Ini file %s is empty?\n"), szProgramIniFile);

			ParseIni( _contents);
		}
	}catch(CString err)
	{
		OutputDebugString(err);
	}
	return sTmp;
}

template <class SymbolT>
HRESULT CSymbolTableT<SymbolT>::SetItemValue(CString tag,_variant_t val)
{
	CSymbolPtr item = GetSymbol(tag);
	if(item==NULL)
		return E_FAIL;
	item->m_lastvalue=item->m_value;
	item->m_value=val;
	return S_OK;
}
template <class SymbolT>
_variant_t CSymbolTableT<SymbolT>::GetItemValue(CString tag)
{
	CSymbolPtr item ;
	try {
		item = GetSymbol(tag);
		if(item==NULL)
			return _variant_t();
	}
	catch(...)
	{
		OutputDebugString(StrFormat(_T("GetItemValue %s Failed\n"), tag));
		return _variant_t();
	}
	return item->m_value;

}
