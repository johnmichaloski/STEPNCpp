#include "StdAfx.h"
#include "Syntax.h"
#include "atlstr.h"
#include "Misc.h"

stack<long> evaluation_stack;
stack<_variant_t> variant_stack;


void TreeIt()
{
	CSyntax syntax;
	std::string str="00070 EnumProp(Tool.PtMeasPar())\n";
	tree_parse_info<const char*> info =
		ast_parse(str.c_str(), syntax, space_p);
	if (info.full)
		OutputDebugString(StrFormat("Succeeded:%s", str.c_str()));
	else
		OutputDebugString(StrFormat("Failed:%s", str.c_str()));

}

void ParseIt()
{
	CSyntax syntax;
	//char * str="00310 StartSession (   )\n";
	//char * str="00310 DeleteCoordSystem (  \"Whammy\" )\n";
	//	char * str="00310 EnumProp(Tool.Name())\n";
	std::string str="00070 EnumProp(Tool.PtMeasPar())\n";
	CString file = ReadAFile("C:\\Program Files\\NIST\\proj\\Tests\\Spirit\\test.txt");
	file += ReadAFile("C:\\Program Files\\NIST\\proj\\Tests\\Spirit\\testebnf.txt");
	std::vector<CString> lines;
	lines=Tokenize(file, "\n");
	int j=0;
	for(int i=0; i<lines.size(); i++)
	{
		CString s;
		str= (const char *) lines[i];
		if(str.length() < 2)
			continue;
		if (parse(str.c_str(), syntax, space_p).full)
		{
			//s.Format("Succeeded:%s", str.c_str());
			evaluation_stack.pop();
		}
		else
		{
			s.Format("Failed: %s", str.c_str());
			j++;
		}
		if(s.GetLength() > 2)
			OutputDebugString(s) ;
	}
	OutputDebugString(StrFormat("Tests Failed = %d\n", j));
}