//
// Part21Parser.cpp
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

// spirit-1.8.5

#include "stdafx.h"
#include <map>
#include <vector>
#include "Misc.h"
#include "Globals.h"
#include "ExpressUtils.h"
#include "stepnc_schemaClassDefinitions.h"
#include "OutDebug.h"
#include "boost/lexical_cast.hpp"
#include "StdString.h"

typedef std::vector<CStdString> CStdStringVector;
typedef std::vector<CStdStringVector> CStdStringTable;

typedef std::pair<CStdString, IStepNodePtr> EntryNamePair;
std::map<CStdString, IStepNodePtr> Entries;


static int linenum; 
extern IStepNodePtr gProject;;
extern CPart21Generator * _gPart21gen;

static int StartsWith(CStdString &str, CStdString s2)
{
	if(str.Find(s2)==0)
		return 1;
	return 0;
}

int BlankOutComments(tstring  & text)
{
	int i,j;
	for(i=0; i< text.size()-1; i++)
	{
		if((text[i]==_T('/') && text[i+1]==_T('*')))
		{
			text[i] =  _T(' ');
			text[i+1] = _T(' ');
			for(j=i+2; j< text.size()-1; j++)
			{
				if(text[j]==_T('*') && text[j+1]==_T('/'))
					break;
				if(text[j]!=_T('\n'))
					text[j] = _T(' ');
			}
			text[j] =  _T(' ');
			text[j+1] =  _T(' ');
			i=j+1;
		}
		if((text[i]==_T('/') && text[i+1]==_T('/')))
		{
			text[i] =  _T(' ');
			text[i+1] = _T(' ');
			for(j=i+2; j< text.size()-1; j++)
			{
				if(text[j]==_T('\n'))
					break;
				text[j] =  _T(' ');
			}
			text[j] =  _T(' ');
			i=j;
		}
	}
	return 0;
}

int SkipQuotes(CStdString & line)
{
	if(line[0]!='\'')
		return 0;
	for(int i=1; i< line.GetLength(); i++)
		if(line[i]=='\'')
			return i;
	throw std::exception("unmatched ' quote ");
	// this is an error...
	return 0;
}

int SkipSpace(CStdString & line)
{
	for(int i=0; i< line.GetLength(); i++)
	{
		if(!isspace(line[i]))
			return i;
		if(line[i]=='\n')
			linenum++;
	}
	
	return 0;
}

int FindNextToken(CStdString & line, CStdString delimiter, CStdString & token)
{
	token.Empty();
	int j;
	for(int i=SkipSpace(line); i< line.GetLength(); i++)
	{

		if(j=SkipQuotes(line.Mid(i)))
		{
			token+=line.Mid(i, j+1);
			i+=j;
			continue;
		}
		if(delimiter == line.Mid(i, delimiter.GetLength()) )
		{
			return i;
		}	
		else if(line[i]=='\n')
		{
			linenum++;
		}
		else if(line[i]=='\t')
		{
			token+=_T(" ");
		}		
		else 
		{
			token+=line[i];
		}
	}
	return 0;
}

int Scanner(CStdString & line, CStdString delimiter, CStdString & token)
{
	int j;
	if((j=FindNextToken(line,  delimiter,  token))<1)
		return 0;
	line=line.Mid(j+delimiter.GetLength());
	token.Trim();
	return j;
}



bool GetListElements(CStdString & line, CStdStringTable &items, TCHAR  delimiter=_T(','))
{
	line.TrimLeft();
	if(!StartsWith(line, _T("(")))
		return false;
	int i=1, j=1, k=1;
	items.push_back(CStdStringVector());
	for(; j>0 && i<line.GetLength(); i++)
	{
		if(line[i]==_T('('))
		{
			j++; k++;
			items.push_back(CStdStringVector());
		}
		else if(line[i]==_T(')'))
		{
			j--;
			if(i-k>0)
				items.back().push_back(line.Mid(k, i-k));
			k=i+1;
		}
		else if(line[i]==_T('\''))
		{
			// skip over commas and parens
			i++;
			for(; i<line.GetLength() && line[i]!=_T('\''); i++);
		}
		else if(line[i]==delimiter)
		{
			items.back().push_back(line.Mid(k, i-k));
			k=i+1;
		}
	}
	if(i==line.GetLength())
		throw std::exception("unmatched paren");
	line = line.Mid(i+1);
	return true;
}

static bool IsEntityReference(CStdString item)
{
	item.TrimLeft();
	if(item[0]==_T('#'))
		return true;
	else return false;

}
static bool IsKeyword(CStdString item)
{
	if(!isalpha(item[0]))
		return false;
	for(int i=1; i<item.GetLength(); i++)
		if(!isalpha(item[i]) || item[i]!=_T('_'))
			return false;
	 return true;

}

static bool IsNumber(CStdString item)
{
	item.TrimLeft();
	TCHAR * endptr;
	LPCTSTR lpstr = (LPCTSTR) item;
	double d = _tcstod (lpstr, &endptr);
	if(lpstr!=endptr)
		return true;
	return false;

}

static bool IsString(CStdString item)
{
	item.TrimLeft();
	if(item[0]==_T('\'') && item[item.GetLength() -1]=='\'')
		return true;
	return false;

}
static bool IsEnumeration(CStdString item)
{
	item.TrimLeft();
	if(item.GetLength() < 2)
		return false;
	int n = item.GetLength() -1;
	if(item[0]!= _T('.') && item[n] != _T('.'))
		return false;
	if(item[0]== _T('.') && item[n] == _T('.'))
		return true;
	if(item[0]== _T('.') && item[n] != _T('.'))
		throw std::exception("unmatched paren");
	if(item[0]!= _T('.') && item[n] == _T('.'))
		throw std::exception("unmatched paren");
	return false;

}
static bool IsMissing(CStdString item)
{
	item.TrimLeft();
	if(item[0]=='$' || item[0]=='*')
		return true;
	return false;

}

void StoreInstance(CVarDefPtr vardef, CStdString sParameter, int nPass=1)
{
	IStepNodePtr pDerivedClass;
	CStdString classname;

	if(sParameter.GetLength() < 1)
	{
		DebugBreak();
	}

	classname=vardef->Classname();
	if(vardef->ISymbolBase::IsListType())
		classname=vardef->ListClassname();

	if(IsEntityReference(sParameter))
	{
		// g.g., #123 reference
		if(Entries.find(sParameter)!=Entries.end())
		{
			pDerivedClass=Entries[sParameter];
		}
		else
		{
			DebugBreak();
			throw std::exception("Unresolved Reference\n");
			return;
		}
	}
	else
	{
		// create simple type class: string, real, integer, etc.
		pDerivedClass =  CClassGenerators::gClassGenerators.CreateClass(ExpDemangle((LPCTSTR) classname), _T(""));
	}

	if(!pDerivedClass)
		DebugBreak();

	if(IsString(sParameter))
	{
		// Fixme: check for badly formed string
		sParameter=sParameter.Mid(1);
		sParameter=sParameter.Left(sParameter.GetLength()-1);
		pDerivedClass->SetVarString((LPCTSTR) sParameter);
	}
	else if( IsNumber(sParameter))
	{
		pDerivedClass->SetVarString((LPCTSTR) sParameter);
	}
	else if(IsEnumeration(sParameter))
	{
		EEnum*instance = (EEnum*) pDerivedClass.get();
		instance->SetString2Enum((LPCTSTR) sParameter);
	}
	else if(sParameter[0]==_T('#') &&  IsNumber(sParameter.Mid(1)))
	{
	}
	else
	{
		DebugBreak();
	}


	Store(vardef, pDerivedClass);
}

bool ParseParameterList(IStepNodePtr step, CStdString line, int nPass=1)
{
	CStdString sParameter;

	if(step==NULL)
		return false;

	CVarDefs vars = step->GetInstanceVars();
	for(int i=0; i< vars.size(); i++)
	{
		CVarDefPtr vardef = vars[i];
		try {

			if(vardef->ISymbolBase::IsListType())
			{
				CStdStringTable items;
				if(GetListElements( line, items))
				{
					for(int j=0; j< items.size(); j++)
					{
						if(vardef->m_nDimension==2)
						{
							EStepArray &list = * (EStepArray *) vardef->m_ref;
							list.push_back(new EStepNodeList(), vardef);
						}
						CStdStringVector strings = items[j];
						for(int k=0; k<strings.size(); k++)
							StoreInstance(vardef, strings[k].Trim(), nPass);
					}
				}
				else
				{
					throw StrFormat(_T("Bad STEP list on line %d\n"), i);
				}
				continue;
			}
			if((i<vars.size()-1) && !Scanner(line, _T(","), sParameter) )
				throw StrFormat(_T("Missing , in parameter list on line %d\n"), i);
			if((i==(vars.size()-1)) && !Scanner(line, _T(")"), sParameter))
				throw StrFormat(_T("Missing ) formed parameter list on line %d\n"), i);
			sParameter.Trim();

			if(IsMissing(sParameter))
			{
				//check to see if vardef->optional
				continue;
			}
			else 
			{
				StoreInstance(vardef, sParameter, nPass);
			}
		}
		catch(CString errmsg)
		{

			OutputDebugString(errmsg);
			DebugBreak();

		}
	}
	return true;
};

void ParseString(tstring string)
{

	int i,j;

	Entries.clear();

	//CStdString string = instring;
	BlankOutComments( string);
//	CString string = (LPCTSTR) sstring.c_str();
//	int n=string.GetLength();
	int n=string.size();
	//ReplacePattern(input,"ISO-10303-21;", "DATA;", "");
	linenum=0;
	std::vector<CStdString> parameters;
	std::vector<IStepNodePtr> nodes;

	for( i=0; i< n; )
	{
		CStdString line;
		CStdString entityname;
		CStdString keyword;
		try{
			int oldnum = linenum;
			for(j=i; j<n; j++)
			{
				if(string[j]==_T('\''))
				{
					while((j< n) && string[++j]!=_T('\'') ) ;
				}

				if(string[j]==_T(';'))
					break;
				if(string[j]==_T('\n'))
					linenum++;
			}
			if(j==n)
				throw StrFormat(_T("Missing ; at line %d\n"), oldnum);
			//			line = string.Mid(i, j-i);
			line = string.substr(i, j-i);
			i=j+1;  // skip ;
			// skip leading spaces until next item...
			while(isspace(string[i]) && (i<n)) i++;

			line.Trim();
			//line.Replace(_T("\n"), _T(" ") );
			line.Replace(_T("\r"), _T("") );
			//OutputDebugString(StrFormat("%d:%s\n", oldnum, line));

			if(line[0]!= _T('#')) 
			{
				Scanner(line, _T("("), keyword);
				if(keyword == _T("FILE_DESCRIPTION"))
				{
					IStepNodePtr step = _gPart21gen->Header()->CreateAttributeNode(_T("file_description"), _T("file_description"));
					ParseParameterList(step, line);
				}
				if(keyword == _T("FILE_NAME"))
				{
					IStepNodePtr step = _gPart21gen->Header()->CreateAttributeNode(_T("file_name"),_T("file_name"));
					ParseParameterList(step, line);
				}
				if(keyword == _T("FILE_SCHEMA"))
				{
					IStepNodePtr step = _gPart21gen->Header()->CreateAttributeNode(_T("file_schema"),_T("file_schema"));
					ParseParameterList(step, line);
				}
				continue;

			}

			if(!Scanner(line, _T("="), entityname))
				throw StrFormat(_T("Missing = on line %d\n"), oldnum);

			//if(entityname == _T("#59"))
			//	DebugBreak();

			if(Scanner(line, _T("("), keyword))
			{
				// Fixme: check well-formed keyword: ident [a-z][a-z_]*
				if(IsKeyword(keyword))
					throw StrFormat(_T("Illegal Keyword %s at line %d\n"),keyword,  oldnum);

				IStepNodePtr step = CClassGenerators::gClassGenerators.CreateClass((LPCTSTR) keyword, _T(""));
				if(step == NULL)
				{
					DebugBreak();
				}
				Entries.insert(EntryNamePair( entityname, step));

				if(ExpDemangle((LPCTSTR)keyword).MakeLower() == _T("project"))
				{
					gProject= step;
					step->_refs++;
				}

				nodes.push_back(step);
				parameters.push_back(line.Trim());
			}

		}
		catch(CString errmsg)
		{
			OutputDebugString(errmsg);
			DebugBreak();

		}
		catch(...)
		{
			DebugBreak();

		}
	}
	for( i=0; i< parameters.size(); i++)
	{
		CStdString parameter=parameters[i];

		try 
		{
			parameter.Trim();
			//OutputDebugString(StrFormat(_T("ParseParameterList: %s %s\n"), (LPCTSTR) nodes[i]->ExpressClassname(), parameter.c_str()));
			//if(nodes[i]->ExpressClassname() == _T("endmill"))
			//{
			//	DebugBreak();
			//}
			ParseParameterList(nodes[i], parameter);
		}
		catch(CString errmsg)
		{
			OutputDebugString(errmsg);
			DebugBreak();

		}	
	}

	// std::fstream outputfile;
	//outputfile.open (::GetExeDirectory() + "debug.txt", std::fstream::out );
	//if(gProject)
	//	outputfile << DumpCVarDefs(gProject->GetInstanceVars());
	//outputfile.close();
}

