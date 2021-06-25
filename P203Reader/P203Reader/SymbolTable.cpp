//
// SymbolTable.cpp
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#include "StdAfx.h"
#include "symboltable.h"
#include "atlstr.h"
#include "Misc.h"
//#define BOOST_SPIRIT_DEBUG

#include <map>



CSymbolTable::CSymbolTable()
{

}

CSymbolTable::~CSymbolTable(void)
{
}

_variant_t CSymbolTable::GetValue(CString tag)
{
	SymbolsIterator it = m_symbols.find(tag);
	if(it!=m_symbols.end())
		return (*it).second->m_value;
	return _variant_t((BSTR) "");
}

/// returns list of parameters in a section. Parameter name is returned, not with section prepended.
CStringVector CSymbolTable::GetSectionSymbols(CString section)
{
	CStringVector symbols;
	// FIXME: this is wrong. Maybe reason for tree...
	SymbolsIterator it =  m_symbols.find(section);
	if(it != m_symbols.end())
	{
		it++;
		for(; it!=m_symbols.end(); it++)
		{
			if((*it).second->m_type!=CSymbol::LEAF)
				break;
			symbols.push_back((*it).second->m_name);
		}

	}
	return symbols;
}


_variant_t CSymbolTable::GetSymbolValue(CString section, CString tag, variant_t var)
{
	CString szTag = section + "." + tag;
	CSymbolPtr symbol = GetSymbol(szTag);
	if(symbol!=NULL)
	{
		return symbol->m_value; 
	}
	return  _variant_t(VT_NULL);
}

HRESULT CSymbolTable::SetSymbolValue(CString section, CString tag, variant_t var)
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

CSymbolPtr  CSymbolTable::GetSymbol(CString tag)
{
	SymbolsIterator it =  m_symbols.find(tag);
	if(it != m_symbols.end())
		return (*it).second;
	return NULL;

}

CString CSymbolTable::ToString()
{
	CString tmp;
	SymbolsIterator it;

	for(it=m_symbols.begin(); it!=m_symbols.end(); it++)
	{
		if((*it).second->m_type== CSymbol::ROOT )
		{
			continue;
		}
		else if((*it).second->m_type== CSymbol::BRANCH )
		{
			tmp.Append(StrFormat("[%s]\n",   (*it).second->m_section));
		}	
		else
		{
			try {
				tmp.Append(StrFormat("%s = %S\n",  (*it).second->m_name, (BSTR) (_bstr_t)  (*it).second->m_value));
			}
			catch(...){}

		}

	}
	return tmp;
}

HRESULT CSymbolTable::AddSymbolItem(CString section, CString parameter, CString value, VARTYPE vt, CString sDefaultValue)
{
	CSymbolPtr symbol = new CSymbol(CSymbol::LEAF,section, parameter) ;
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
	}
	catch(...)
	{
		return E_FAIL;
	}
	return S_OK;
}
CString CSymbolTable::ParseSection(CString iniSection)
{
	CString errstr="";
	//iniSection.Replace(";", "\n", "");
	unsigned int i;

	CString tmp = iniSection.Mid(1, iniSection.Find("]") +1);
	tmp.Trim();

	CString section = GetIniSectionName(tmp);

	m_symbols[section] = new CSymbol(CSymbol::BRANCH, section, section) ;


	CStringVector lines = CStringVector::Tokenize(iniSection,"\n");
	for(i=0; i< lines.size(); i++)
	{
		GetIniSetting(section, lines[i]);
		
	}
	return errstr;
}
CString CSymbolTable::GetIniSectionName(CString &line)
{
	line.Trim();
	if(line.Find('[')!=0)
		return "";
	if(line.ReverseFind(']')<0)
		return "";
	line.Replace("[", "");
	line.Replace("]", "");
	line.Trim();
	return line;

}
HRESULT CSymbolTable::GetIniSetting(CString section, CString line)
{
	CStringVector tokens;
	CSymbolPtr symbol;

	tokens = CStringVector::Tokenize(line,"=");

	if(tokens.size()<1)
		return E_FAIL;

	if(tokens.size()==1) // May be blank
		tokens.push_back("");

	tokens[0].Trim();
	tokens[1].Trim();

	if(tokens[0].GetLength() < 1)
		return E_FAIL;

	CString parameter = tokens[0];
	symbol = new CSymbol(CSymbol::LEAF,section, parameter) ;
	try 
	{
		tokens[1].Replace("\"", ""); // placeholder - remove double quotes, just for concept for now.
		symbol->m_value= _variant_t((LPCTSTR) tokens[1]);
	}
	catch(...)
	{
		return E_FAIL;
	}

	OutputDebugString(StrFormat("Add symbol %s \n", section+ "." + parameter));
	m_symbols[section+ "." + parameter] = symbol;
	return S_OK;
}

CStringVector CSymbolTable::ParseIni(CString &contents)
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
			int end;
			while(contents[i]!='\n' && contents[i]!=']' && i< contents.GetLength()) i++;
			if(contents[i]==']')
			{
				if(_Sections.size()>0)
					_Sections.back()._end=start-1;

				section=contents.Mid(start+1, i-start-1); // omits [  ]
				section.Trim();
				_szSections.push_back(section);
				_Sections.push_back(Section( section, start));
				m_symbols[section]= new CSymbol(CSymbol::BRANCH,section, "") ;

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
		_Sections.back()._end=contents.GetLength()-1;

	return _szSections;
}

CString CSymbolTable::GetIniSection(CString section)
{
	for(int i=0; i< _Sections.size(); i++)
	{
		if(_Sections[i]._name == section)
			return _contents.Mid(_Sections[i]._first,_Sections[i]._end-_Sections[i]._first+1);
	}
	return "";
}

CString CSymbolTable::FromInifile(CString szProgramIniFile)
{
	CString sTmp;

	try {

		if(GetFileExists(szProgramIniFile))
		{
			_contents = ReadAFile(szProgramIniFile);
			ReplacePattern(_contents, "#", "\n", "\n");
			ReplacePattern(_contents, ";", "\n", "\n");

			if(_contents.IsEmpty())
				throw StrFormat("Items Ini file %s is empty?\n", szProgramIniFile);

			ParseIni( _contents);
		}
	}catch(CString err)
	{
		OutputDebugString(err);
	}
	return sTmp;
}

HRESULT CSymbolTable::SetItemValue(CString tag,_variant_t val)
{
	CSymbolPtr item = GetSymbol(tag);
	if(item==NULL)
		return E_FAIL;
	item->m_lastvalue=item->m_value;
	item->m_value=val;
	return S_OK;
}
_variant_t CSymbolTable::GetItemValue(CString tag)
{
	CSymbolPtr item ;
	try {
		item = GetSymbol(tag);
		if(item==NULL)
			return _variant_t();
	}
	catch(...)
	{
		OutputDebugString(StrFormat("GetItemValue %s Failed\n", tag));
		return _variant_t();
	}
	return item->m_value;

}