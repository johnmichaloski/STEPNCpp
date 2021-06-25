#include "StdAfx.h"
#include "IniParser.h"
#include "OutDebug.h"
#include "atlstr.h"
#include "Misc.h"

std::string str="[SECTION1]\n"
		"; Comments goes here \n"
		"A=1\n"
		"B=99\n"
		"C=\"Hello World\"\n\n"
		"[SECTION2]\n"
				"A=111\n"
;
template<typename TreeIter>
int evaluate(const TreeIter& i)
{
	if(i->value.id() == CIniParser::InifileID)
	{
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++)
		{
			OutputDebugString("<SECTION>\n");\
				evaluate(it);
			OutputDebugString(StrFormat("</SECTION>\n"));
		}

	}
	else if((i->value.id() == CIniParser::SectionID))
	{
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++)
			evaluate(it);
	}
	else if((i->value.id() == CIniParser::IndentifierID) )
	{
		OutputDebugString(StrFormat("%s=", string(i->value.begin(), i->value.end()).c_str()));

	}
	else if((i->value.id() == CIniParser::SectionHdrID) )
	{
		TreeIter it = i->children.begin();
		str=std::string(it->value.begin(), it->value.end()).c_str();
		OutputDebugString(StrFormat("%s\n", str.c_str()));

	}
	else if((i->value.id() == CIniParser::PropertyID))
	{
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++)
			evaluate(it);
	}
	else if((i->value.id() == CIniParser::ParameterID))
	{
		OutputDebugString(StrFormat("\t%s\n", string(i->value.begin(), i->value.end()).c_str()));
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++)
			evaluate(it);
	}
	else if(i->value.id() == CIniParser::DblQuotedStrID )
	{
		CString str;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++)
			str+=string(it->value.begin(), it->value.end()).c_str();
		
		OutputDebugString(StrFormat("%s\n", str));

	}
	return 0;
}
 


void IniParseIt()
{

//	  if (parse(str.c_str(), iniparser, blank_p).full)
	CIniParser iniparser;
	ini_skip_grammar skip;
	Fstream outputfile(CString(GetExeDirectory() + "output.txt"));
	//std::string str="[SECTION1]\n";
	tree_parse_info<const char*> info =
		ast_parse(str.c_str(), iniparser, skip);
	if(info.full)
	{
		evaluate(info.trees.begin());
		//tree_to_xml(outputfile.fp, info.trees, str.c_str(), iniparser.rule_names);
		OutputDebugString("Ini File Parse Succeeded \n");
	}
	else
	{
		OutputDebugString("Ini File Parse Failed \n");

	}

}
