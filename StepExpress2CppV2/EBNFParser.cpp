//
//
//
#include "stdafx.h"
#include "EBNFParser.h"

#include "OutDebug.h"
#include "ebnfClasses.h"
#include "boost/lexical_cast.hpp"

int linenumber;

std::vector<EBNF::optional *> _optionals;
std::vector<EBNF::expList *> _expressions;
std::vector<EBNF::defList *> _defLists;
/*
enum { STRING_LITERALID=1,DblQuotedStrID=2, TERMINALID=3, NONTERMINALID=4,
DIGITID=5, SEMICOLONID=6, ISID=7, THREEDOTSID=8, ORID=9, ONECHARID=10, 
leftSideID=11, GrammarID=12, OptionalID=13, ExpressionID=14, TerminalListID=16, 
ProductionID=16,ProductionListID=18, DefinitionListID=19, DefinitionID =20, ExpressionListID=21, CommentID};
*/
// A definition is a list of expressions.
CString tabs("");
template<typename TreeIter>
int evalEBNF(const TreeIter& i)
{
	tabs+="\t";
	int n =  i->value.id().to_long();
	switch(n)
	{
	case CEBNFParser::ProductionID:
		{
			// $$ = production::NewProduction($1, $2);
			TreeIter it = i->children.begin();  // 1st child is lhs
			it = it->children.begin()->children.begin();  // lhs->non-terminal -> string
			std::string leftside = std::string(it->value.begin(), it->value.end()).c_str();
			EBNF::defList * defs = EBNF::defList::NewDefList();
			EBNF::production * prod = EBNF::production::NewProduction(leftside.c_str(), defs);	
			EBNF::productions.push_back(prod);
			_defLists.push_back(defs);
			OutputDebugString(StrFormat("Production=%s\n", leftside.c_str()));
			it = i->children.begin(); 
			it++;
			//for(; it!= it->children.end(); it++)
			evalEBNF(it);

			_defLists.pop_back();
		}
		break;
	case CEBNFParser::ExpressionListID: 
		{
			OutputDebugString(StrFormat("%s ExpressionListID %d\n", tabs, i->value.id()));
			EBNF::expList * _ExpList = EBNF::expList::NewExpList();

			// Add the expression list as a new definition, then add to definitions list
			EBNF::defList * defs = _defLists.back();
			EBNF::definition * def = EBNF::definition::NewDefinition(_ExpList);
			defs->push_back(def);

			// Now add the expressions to expression list
			_expressions.push_back(_ExpList);
			for(TreeIter it = i->children.begin(); it!=i->children.end(); it++)
			{
				evalEBNF(it);
			}
			_expressions.pop_back();
		}
		break;

	case CEBNFParser::NONTERMINALID:
		{
			// 			{$$ = expression::NewExpression(NONTERMINAL, $1, NULL);}
			TreeIter it = i->children.begin(); 
			std::string	 str=std::string(it->value.begin(), it->value.end()).c_str();
			EBNF::expression * exp =  EBNF::expression::NewExpression(NONTERMINAL, str.c_str(), NULL);	
			EBNF::expList * _explist =_expressions.back();
			_explist->push_back(exp);
			OutputDebugString(StrFormat("%s NONTERMINALID=%s\n", tabs, str.c_str()));
		}
		break;
	case CEBNFParser::TERMINALID:
		{
			// 	{$$ = expression::NewExpression(TERMINAL, $1, NULL);	recordTerminal($1);}
			TreeIter it = i->children.begin(); 
			std::string	 str=std::string(it->value.begin(), it->value.end()).c_str();
			EBNF::recordTerminal(str.c_str());
			EBNF::expression * exp = EBNF::expression::NewExpression(TERMINAL,   str.c_str() , NULL);	
			EBNF::expList * _explist =_expressions.back();
			_explist->push_back(exp);
			OutputDebugString(StrFormat("%s TERMINALID=%s\n", tabs, str.c_str()));

		}
		break;
	case CEBNFParser::ONECHARID:
		{
			// 	{char * aray; 	aray = Stringy::NewString("  "); aray[0] = $1; 	aray[1] = 0;$$ = expression::NewExpression(ONECHAR, aray, NULL);}
			TreeIter it = i->children.begin(); 
			std::string	 str=std::string(it->value.begin(), it->value.end()).c_str();
			EBNF::expression * exp = EBNF::expression::NewExpression(ONECHAR, str.c_str(), NULL);	
			EBNF::expList * _explist =_expressions.back();
			_explist->push_back(exp);
			OutputDebugString(StrFormat("%s ONECHAR=%s\n", tabs, str.c_str()));

		}	
		break;
	case CEBNFParser::OptionalID:
		{
			OutputDebugString(StrFormat("Optional=\n"));
			//	'[' >>ExpressionList>> ']'  // 		{$$ = optional::NewOptional($2, -1);}
			//	| '[' >>ExpressionList >>THREEDOTS >>']' //			{$$ = optional::NewOptional($2, 0);}
			//	| '[' >>ExpressionList >>THREEDOTS >>DIGIT>> ']'  //			{$$ = optional::NewOptional($2, $4);}
			// 	{$$ = expression::NewExpression(OR, NULL, $1);}
			EBNF::expList * _ExpList = EBNF::expList::NewExpList();
			EBNF::optional * opt = EBNF::optional::NewOptional(_ExpList, -1); 
			_expressions.push_back(_ExpList);
			_optionals.push_back(opt);
			for(TreeIter it = i->children.begin(); it!=i->children.end(); it++)
			{
				evalEBNF(it);
			}
			_expressions.pop_back();
			_optionals.pop_back();
			EBNF::expression * exp = EBNF::expression::NewExpression(OR, "", opt);	
			EBNF::expList * _explist =_expressions.back();
			_explist->push_back(exp);

		}	
		break;
	case CEBNFParser::THREEDOTSID:
		{
			OutputDebugString(StrFormat("%s THREEDOTSID\n", tabs)); 			
			EBNF::optional * opt = _optionals.back();
			opt->SetDigit (0);
			break;

		}
	case CEBNFParser::DIGITID:
		{
			OutputDebugString(StrFormat("%s DIGITID\n", tabs));
			EBNF::optional * opt = _optionals.back();
			TreeIter it = i->children.begin(); 
			int n = lexical_cast<int>(string(it->value.begin(), it->value.end())) ;
			opt->SetDigit (n);
			break;
		}
	case CEBNFParser::STRING_LITERALID:
		OutputDebugString(StrFormat("%s STRING_LITERALID\n", tabs)); break;
	case CEBNFParser::DblQuotedStrID:
		OutputDebugString(StrFormat("%s DblQuotedStrID\n", tabs)); break;
	case CEBNFParser::SEMICOLONID:
		OutputDebugString(StrFormat("%s SEMICOLONID\n", tabs)); break;
	case CEBNFParser::ISID:
		OutputDebugString(StrFormat("%s ISID\n", tabs)); break;

	case CEBNFParser::ORID:
		OutputDebugString(StrFormat("%s ORID\n", tabs)); break;
	case CEBNFParser::leftSideID:
		OutputDebugString(StrFormat("%s leftSideID\n", tabs)); break;
	case CEBNFParser::ExpressionID:
		OutputDebugString(StrFormat("%s ExpressionID\n", tabs)); 
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++)
		{
			evalEBNF(it);
		}
		break;
	case CEBNFParser::TerminalListID: 
		OutputDebugString(StrFormat("%s TerminalListID\n", tabs)); break;
	case CEBNFParser::ProductionListID: 
		OutputDebugString(StrFormat("%s ProductionListID\n", tabs)); break;
	case CEBNFParser::CommentID:
				OutputDebugString(StrFormat("%s CommentID\n", tabs)); break;
	case CEBNFParser::OptionalNID:
			OutputDebugString(StrFormat("%s OptionalNID\n", tabs)); break;
		
	case  CEBNFParser::DefinitionID:
	case CEBNFParser::DefinitionListID:
		{
			if(n==CEBNFParser::DefinitionID) 
				OutputDebugString(StrFormat("%s DefinitionID\n", tabs)); 
			if(n==CEBNFParser::DefinitionListID) 
				OutputDebugString(StrFormat("%s DefinitionListID\n", tabs)); 
			for(TreeIter it = i->children.begin(); it!=i->children.end(); it++)
			{
				evalEBNF(it);
			}
		}
		break;
	case CEBNFParser::GrammarID:
		OutputDebugString(StrFormat("%s GrammarID\n", tabs)); break;
	default:
		OutputDebugString(StrFormat("%s 0 ID\n", tabs)); 
		{
			for(TreeIter it = i->children.begin(); it!=i->children.end(); it++)
			{
				evalEBNF(it);
			}
		}
	}
	tabs=tabs.Mid(1, tabs.GetLength()-1);
	return 0;
}


void CEBNFParser::EbnfParseIt()
{
	ebnf_skip_parser skip;
	//ebnf_skip_grammar skip;
	Fstream outputfile(CString(GetExeDirectory() + "output.txt"));
	CString file = ReadAFile(CString(GetExeDirectory() + "ippdme.ebnf"));
	tree_parse_info<const char*> info =
		pt_parse((const char *) file, *this, skip);
	//		ast_parse((const char *) file, *this, skip);
	if(info.full)
	{
		OutputDebugString("Ini File Parse Succeeded \n");
		evalEBNF(info.trees.begin());
		EBNF::replaceOptProductions();
		FILE * bnffile = fopen(CString(GetExeDirectory() + "ippdme.bnf"), "w");
		EBNF::bLex=false;
		if(bnffile)
		{
			EBNF::printProductions(bnffile);
			fclose(bnffile);
		}
		EBNF::bLex=true;
		HRESULT hr = EBNF::AZTestFile( CString(GetExeDirectory() + "ippdme.tst"));

		//tree_to_xml(outputfile.fp, info.trees, str.c_str(), ebnfparser.rule_names);
	}
	else
	{
		OutputDebugString("Ini File Parse Failed \n");

	}

}