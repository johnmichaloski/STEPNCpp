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
#include "OutDebug.h"
#include "boost/lexical_cast.hpp"
#include "StdStringFcn.h"

typedef std::vector<std::string> StringVector;
typedef std::vector<StringVector> StringTable;

//typedef std::pair<std::string, IStepNodePtr> EntryNamePair;
//std::map<std::string, IStepNodePtr> Entries;

std::map<std::string, std::string> Entries;
std::map<std::string, std::string> Parameters;
std::map<std::string, std::string> Resolved;
struct XmlEntry
{
	std::string poundentry;
	std::string entityname;
	std::string rawparameters;
	std::string xmlparameters;
	bool bCompleted;
	bool bVisited;
	XmlEntry() {bVisited= bCompleted=false; }
};
class XmlEntries : public std::vector<XmlEntry>
{
public:
	int Find(std::string poundnum)
	{
		for(int i=0; i< size(); i++)
		{
			if(this->at(i).poundentry == poundnum)
				return i;
		}
		return -1;
	}
};

XmlEntries entries;
static int linenum; 

static int StartsWith(std::string &str, std::string s2)
{
	if(str.find(s2)==0)
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

int SkipQuotes(std::string & line)
{
	if(line[0]!='\'')
		return 0;
	for(int i=1; i< line.size(); i++)
		if(line[i]=='\'')
			return i;
	throw std::exception("unmatched ' quote ");
	// this is an error...
	return 0;
}
std::string FindQuotedString(std::string & line)
{
	int i;
	if(line[0]!='\'')
		return "";
	for(i=1; i< line.size(); i++)
		if(line[i]=='\'')
			break;
	if(line[i]!='\'')
		throw std::exception("unmatched ' quote ");
	// this is an error...
	std::string result = line.substr(0, i+1);
	line=line.substr(i+1);
	return result;
}
int SkipSpace(std::string & line)
{
	for(int i=0; i< line.size(); i++)
	{
		if(!isspace(line[i]))
			return i;
		if(line[i]=='\n')
			linenum++;
	}

	return 0;
}

int FindNextToken(std::string & line, std::string delimiter, std::string & token)
{
	token="";
	int j;
	for(int i=SkipSpace(line); i< line.size(); i++)
	{

		if(j=SkipQuotes(line.substr(i)))
		{
			token+=line.substr(i, j+1);
			i+=j;
			continue;
		}
		if(delimiter == line.substr(i, delimiter.size()) )
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

int Scanner(std::string & line, std::string delimiter, std::string & token)
{
	int j;
	if((j=FindNextToken(line,  delimiter,  token))<1)
		return 0;
	line=line.substr(j+delimiter.size());
	token=Trim(token);
	return j;
}



int GetListElements(std::string & line, StringTable &items, TCHAR  delimiter=_T(','))
{
	TrimLeft(line);
	if(!StartsWith(line, _T("(")))
		return 0;
	int i=1, j=1, k=1;
	items.push_back(StringVector());
	for(; j>0 && i<line.size(); i++)
	{
		if(line[i]==_T('('))
		{
			j++; k++;
			items.push_back(StringVector());
		}
		else if(line[i]==_T(')'))
		{
			j--;
			if(i-k>0)
				items.back().push_back(line.substr(k, i-k));
			k=i+1;
		}
		else if(line[i]==_T('\''))
		{
			// skip over commas and parens
			i++;
			for(; i<line.size() && line[i]!=_T('\''); i++);
		}
		else if(line[i]==delimiter)
		{
			items.back().push_back(line.substr(k, i-k));
			k=i+1;
		}
	}
	if(i==line.size() && j!=0)
		throw std::exception("unmatched paren");
	if(i<line.size())
		line = line.substr(i+1);
	else line ="";
	return i+1;
}

static bool IsEntityReference(std::string item)
{
	TrimLeft(item);
	if(item[0]==_T('#'))
		return true;
	else return false;

}
static bool IsKeyword(std::string item)
{
	if(!isalpha(item[0]))
		return false;
	for(int i=1; i<item.size(); i++)
		if(!isalpha(item[i]) || item[i]!=_T('_'))
			return false;
	return true;

}

static bool IsNumber(std::string item)
{
	TrimLeft(item);
	TCHAR * endptr;
	LPCTSTR lpstr = (LPCTSTR) item.c_str();
	double d = _tcstod (lpstr, &endptr);
	if(lpstr!=endptr)
		return true;
	return false;

}

static bool IsString(std::string item)
{
	TrimLeft(item);
	if(item[0]==_T('\'') && item[item.size() -1]=='\'')
		return true;
	return false;

}
static bool IsEnumeration(std::string item)
{
	TrimLeft(item);
	if(item.size() < 2)
		return false;
	int n = item.size() -1;
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
static bool IsMissing(std::string item)
{
	TrimLeft(item);
	if(item[0]=='$' || item[0]=='*')
		return true;
	return false;

}
#if 0
void StoreInstance(CVarDefPtr vardef, std::string sParameter, int nPass=1)
{
	IStepNodePtr pDerivedClass;
	std::string classname;

	if(sParameter.size() < 1)
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
		sParameter=sParameter.Left(sParameter.size()-1);
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

bool ParseParameterList(std::string entity, std::string line, int nPass=1)
{
	std::string sParameter;



	if(vardef->ISymbolBase::IsListType())
	{
		std::stringTable items;
		if(GetListElements( line, items))
		{
			for(int j=0; j< items.size(); j++)
			{
				if(vardef->m_nDimension==2)
				{
					EStepArray &list = * (EStepArray *) vardef->m_ref;
					list.push_back(new EStepNodeList(), vardef);
				}
				std::stringVector strings = items[j];
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
}
catch(CString errmsg)
{

	OutputDebugString(errmsg);
	DebugBreak();

}
	}
	return true;
};
#endif

std::vector<std::string> SplitTokens(std::string str)
{
	std::vector<std::string> tokens;
	bool bSkip=false;
	bool bPSkip=false;
	int i;
	for(i=0; i< str.size(); i++)
	{
		if(str[i]=='\'')
		{
			bSkip=!bSkip;
			if(bSkip)
				continue;
		}
		if(bSkip)
			continue;
		if(str[i]=='(')
		{
			bPSkip=true;
		}
		if(str[i]==')')
		{
			bPSkip=false;
		}		
		if(bPSkip)
			continue;

		if(str[i]==',')
		{
			tokens.push_back(Trim(str.substr(0,i)));
			str=str.substr(i+1); i=-1; 

		}
	}
	if(str.size() > 0)
		tokens.push_back(str.substr(0,i));
	return tokens;
}

void ParseEntities(std::string tabs, std::string pound, std::string & xml, std::string strin)
{
	strin=strin.substr(1); // skip leading ( TrimLeft(strin,"(");
	strin=strin.substr(0,strin.size()-1);	//  may be more than 1 ) TrimRight(strin,")");

	
	std::vector<std::string> tokens = SplitTokens(strin); // Split(strin, ',');
	int m;
	if((m= entries.Find(pound))<0)	
		return;

	if(entries[m].bVisited==true)
		return;
	entries[m].bVisited=true;

	tabs+="\t";
	for(int i=0; i< tokens.size(); i++)
	{	
		std::string s=tokens[i];
		Trim(s);
		// Embedded list
		if(s[0]=='(')
		{
			s=s.substr(1); // skip leading ( TrimLeft(s,"(");
			s=s.substr(0,s.size()-1);	//  may be more than 1 ) TrimRight(s,")");
			if(s.empty())
				continue;
			std::vector<std::string> items = SplitTokens(s); // Split(strin, ',');

			if(StartsWith(items[0], "#"))		
				tokens.insert(tokens.begin() + i +1, items.begin(), items.end());
			else		
				for(int j=0; j<items.size(); j++)
					xml  += items[j] + " ";
	
		}
		else if(s[0]=='$')
		{
			//skip
		}
		else if(s[0]=='#')
		{
			int n;
			if((n= entries.Find(s))>=0)
			{
				XmlEntry & entry(entries[n]);
				if(!entry.bCompleted)
				{
					ParseEntities(tabs, entry.poundentry,entry.xmlparameters, entry.rawparameters);
				}
	
					//xml+= entry.xmlparameters; // ParseEntities(entry.poundentry, entry.xmlparameters, entry.rawparameters);
					xml  += tabs+ "<"+entry.entityname+">\n"+tabs+entry.xmlparameters+"\n"+tabs+"</"+entry.entityname+">\n";
				
			}
			continue;
		}
		else if(s[0]=='\'')
		{
			std::string  token;
			xml  +=   s   + " ";
		}

		else if(IsNumber(s))
		{
			float fnum;
			sscanf(s.c_str(), "%f", &fnum);
			xml  += ConvertToString<float>(fnum) + " ";
		}
		else if(s[0]=='.')
		{
			std::string  token;
			xml  +=   s   + " ";
		}
		else
		{
			DebugBreak();
		}

	}
	if((m= entries.Find(pound))>=0)
	{
		//OutputDebugString(StrFormat("Completed %s=%s %s\n",  entries[m].poundentry.c_str(), entries[m].entityname.c_str(), entries[m].xmlparameters.c_str()));
		entries[m].bCompleted=true;
	}
	tabs.substr(1); // delete tab

}


void ParseString(tstring string)
{

	int i,j;

	Entries.clear();

	//std::string string = instring;
	BlankOutComments( string);
	//	CString string = (LPCTSTR) sstring.c_str();
	//	int n=string.size();
	int n=string.size();
	//ReplacePattern(input,"ISO-10303-21;", "DATA;", "");
	linenum=0;
	std::vector<std::string> parameters;
	//	std::vector<IStepNodePtr> nodes;
	//	std::vector<std::string> entries;
	std::vector<std::string> nodes;

	XmlEntry first;

	for( i=0; i< n; )
	{
		std::string line;
		std::string entityname;
		std::string keyword;
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
			while((i<string.size()) && isspace(string[i])) i++;

			Trim(line);
			//line.Replace(_T("\n"), _T(" ") );
			line=replaceAll(line, _T("\r"), _T("") );
			//OutputDebugString(StrFormat("%d:%s\n", oldnum, line));

			if(line[0]!= _T('#')) 
			{
				Scanner(line, _T("("), keyword);
				if(keyword == _T("FILE_DESCRIPTION"))
				{
					//IStepNodePtr step = _gPart21gen->Header()->CreateAttributeNode(_T("file_description"), _T("file_description"));
					//ParseParameterList(step, line);
				}
				if(keyword == _T("FILE_NAME"))
				{
					//IStepNodePtr step = _gPart21gen->Header()->CreateAttributeNode(_T("file_name"),_T("file_name"));
					//ParseParameterList(step, line);
				}
				if(keyword == _T("FILE_SCHEMA"))
				{
					//IStepNodePtr step = _gPart21gen->Header()->CreateAttributeNode(_T("file_schema"),_T("file_schema"));
					//ParseParameterList(step, line);
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
				Entries[entityname]=keyword;
				Parameters[entityname]=Trim(line);
				//IStepNodePtr step = CClassGenerators::gClassGenerators.CreateClass((LPCTSTR) keyword, _T(""));
				//if(step == NULL)
				//{
				//	DebugBreak();
				//}
				//Entries.insert(EntryNamePair( entityname, step));


				//nodes.push_back(step);
				nodes.push_back(keyword);
				parameters.push_back(Trim(line));

				XmlEntry e;
				e.entityname = keyword;
				e.poundentry=entityname;
				e.rawparameters = Trim("(" + line);
				entries.push_back(e);

				if(MakeUpper(keyword) == _T("PROJECT"))
				{
					first=e;
				}
			

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

	try {

		//for(int i=0; i< entries.size() ; i++)
		//{
		//	if(!entries[i].bCompleted)
		//		ParseEntities(entries[i].poundentry, entries[i].xmlparameters, entries[i].rawparameters);
		//}
			ParseEntities("",first.poundentry, first.xmlparameters, first.rawparameters);
			first.xmlparameters=MakeXMLtag(first.entityname, first.xmlparameters);
			OutputDebugString(first.xmlparameters.c_str());
			std::string filename = ::GetExeDirectory()  + "New example1-07.xml";
			WriteFile(filename, first.xmlparameters);

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


