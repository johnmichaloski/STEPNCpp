//
// EBNFParser.h
//
#pragma once
//#define BOOST_SPIRIT_DEBUG

#include <map>
//#include <boost/regex.hpp>
//#include <boost/archive/xml_oarchive.hpp>
#include <boost/spirit.hpp>
#include <boost/version.hpp>
#include <boost/spirit/core.hpp>

#if BOOST_VERSION <= 103200
#define BOOST_SPIRIT_NO_REGEX_LIB
#endif

#include <boost/spirit/tree/parse_tree.hpp>
#include <boost/spirit/tree/ast.hpp>
#include <boost/spirit/error_handling.hpp>

#include <iostream>
#include <stack>
#include <functional>
#include <string>

//#ifdef BOOST_SPIRIT_DUMP_PARSETREE_AS_XML
#include <boost/spirit/tree/tree_to_xml.hpp>
#include <boost/spirit/phoenix/binders.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/lambda/bind.hpp>

//#include "comdef.h"
//#include "atlstr.h"

using namespace std;
using namespace boost;
using namespace boost::spirit;
using namespace boost::lambda;

struct CEBNFParser;
typedef string::iterator iter_t;

///////////////////////////////////////////////////////////////////////////
//
//  eol_parser class (contributed by Martin Wille)
//
///////////////////////////////////////////////////////////////////////////
extern	int linenumber;
struct ebnf_skip_parser : public parser<ebnf_skip_parser>
{ 
	typedef ebnf_skip_parser self_t;

	ebnf_skip_parser() {linenumber=0;}

	template <typename ScannerT>
	typename parser_result<self_t, ScannerT>::type
		parse(ScannerT const& scan) const
	{
		typename ScannerT::iterator_t save = scan.first;
		std::size_t len = 0;

		while (!scan.at_end())   // CR
		{
			if( *scan != '\r' && *scan != ' ' && *scan != '\t'  && *scan != '\n')  
				break;
			if(*scan == '\n')
				++linenumber;
			++scan.first;
			++len;
		}


		chseq<char*> str("/*");
		if (str.parse(scan)) //!scan.at_end() &&  *scan == '/') 
		{
			len+=2; 
			for( ;!scan.at_end(); ++scan.first,++len )
			{
				if(*scan != '*')
					continue;
				chseq<char*> str("*/");
				if (str.parse(scan))
					break;

			}
		}

		if (len)
			return scan.create_match(len, nil_t(), save, scan.first);
		return scan.no_match();
	}
};





struct  CEBNFParser :
	public boost::spirit::grammar<CEBNFParser>
{

	CEBNFParser(void)
	{
		rule_names[GrammarID]             = "EBNF";
		rule_names[OptionalID]             = "Optional";
		rule_names[ExpressionID]             = "Expression";
		rule_names[TerminalListID]             = "TerminalList";
		rule_names[ProductionID]             = "Production";
		rule_names[DefinitionListID]             = "DefinitionList";
		rule_names[DefinitionID]             = "Definition";
		rule_names[ExpressionListID]             = "ExpressionList";
		rule_names[ProductionListID]             = "ProductionList";
		rule_names[ISID]             = "ISID";
		rule_names[ONECHARID]             = "ONECHAR";
		rule_names[DIGITID]             = "DIGIT";
		rule_names[STRING_LITERALID]             = "STRING_LITERAL";
		rule_names[CommentID]             = "Comment";

	}
	~CEBNFParser(void){}
	typedef spirit::symbols<double> var_table_t;

	// var_table_t & vars;
	// A production can have an associated closure, to store information
	// for that production.
	struct value_closure : boost::spirit::closure<value_closure, void *>
	{
		member1 value;
	};
	struct expression_closure :
		boost::spirit::closure<expression_closure, std::string, std::string>
	{
		member1 name;
		member2 value;
	};

	std::map<parser_id, std::string> rule_names;

	enum { STRING_LITERALID=1,DblQuotedStrID, TERMINALID, NONTERMINALID,
		DIGITID, SEMICOLONID, ISID, THREEDOTSID, ORID, ONECHARID, 
		leftSideID, GrammarID, OptionalID, ExpressionID, TerminalListID, 
		ProductionID,ProductionListID, DefinitionListID, DefinitionID , ExpressionListID, CommentID,
		OptionalNID, OptionalDotsID};

	template <typename ScannerT>
	struct definition		
	{
	public:


		rule<ScannerT, parser_context<>, parser_tag<STRING_LITERALID> > STRING_LITERAL;
		rule<ScannerT, parser_context<>, parser_tag<DblQuotedStrID> > DblQuotedStr;
		rule<ScannerT, parser_context<>, parser_tag<TERMINALID> > TERMINAL;
		rule<ScannerT, parser_context<>, parser_tag<NONTERMINALID> > NONTERMINAL;
		rule<ScannerT, parser_context<>, parser_tag<DIGITID> > DIGIT;
		rule<ScannerT, parser_context<>, parser_tag<ISID> > IS;
		rule<ScannerT, parser_context<>, parser_tag<THREEDOTSID> > THREEDOTS;
		rule<ScannerT, parser_context<>, parser_tag<ONECHARID> > ONECHAR;
		rule<ScannerT, parser_context<>, parser_tag<leftSideID> > leftSide;
		rule<ScannerT, parser_context<>, parser_tag<OptionalID> > Optional;
		rule<ScannerT, parser_context<>, parser_tag<ExpressionID> > Expression;
		rule<ScannerT, parser_context<>, parser_tag<TerminalListID> > TerminalList;
		rule<ScannerT, parser_context<>, parser_tag<ProductionID> > Production;
		rule<ScannerT, parser_context<>, parser_tag<DefinitionListID> > DefinitionList;
		rule<ScannerT, parser_context<>, parser_tag<DefinitionID> > Definition;
		rule<ScannerT, parser_context<>, parser_tag<ExpressionListID> > ExpressionList;
		rule<ScannerT, parser_context<>, parser_tag<ProductionListID> > ProductionList;
		rule<ScannerT, parser_context<>, parser_tag<CommentID> > Comment;
		rule<ScannerT> Grammar ;
		const boost::spirit::rule<ScannerT> &start() const { return Grammar; }

		//assertion_t expect_semicolon, expect_close_bracket;

		definition( CEBNFParser const &self )
		{   
			assertion<std::string> expect_semi("Semicolorn expected.");
			guard<std::string> guard_production;

			STRING_LITERAL		= inner_node_d[ chlit<>('\"') >> *( strlit<>("\\\"") | anychar_p - chlit<>('\"') ) >> chlit<>('\"')]; //[&write]
			DblQuotedStr		= +STRING_LITERAL;	
			TERMINAL			= leaf_node_d[+(alpha_p|'_')];  
			NONTERMINAL			=  leaf_node_d[inner_node_d['<' >> alpha_p >> +(alnum_p | '_') 	>>    str_p( ">" ) ]];
			DIGIT				=  leaf_node_d[+range_p('0','9')];
			IS					= leaf_node_d[str_p("::=")];
			THREEDOTS			= str_p("...");
			ONECHAR				=  leaf_node_d[inner_node_d['\'' >> (anychar_p-chlit<>('\n') )>> '\'']];
			leftSide = 	NONTERMINAL>> IS;


			Grammar =  *(Production | Comment | eol_p) ; //{ $$ = 0;}		;

			Optional =
				discard_node_d[chlit<>('[')] >>+(Expression)>> discard_node_d[chlit<>(']')] // 	{$$ = optional::NewOptional($2, -1);}
			| discard_node_d[chlit<>('[')] >>+(Expression) >>THREEDOTS >>discard_node_d[chlit<>(']')]							//	{$$ = optional::NewOptional($2, 0);}
			| discard_node_d[chlit<>('[')] >>+(Expression) >>THREEDOTS >>DIGIT>> discard_node_d[chlit<>(']')]					//	{$$ = optional::NewOptional($2, $4);}
			;

			Expression =
				NONTERMINAL		// {$$ = expression::NewExpression(NONTERMINAL, $1, NULL);}
				| TERMINAL			// {$$ = expression::NewExpression(TERMINAL, $1, NULL);	recordTerminal($1);}
				| ONECHAR			// 	{char * aray; 	aray = Stringy::NewString("  "); aray[0] = $1; 	aray[1] = 0;$$ = expression::NewExpression(ONECHAR, aray, NULL);}
				| Optional			// 	{$$ = expression::NewExpression(OR, NULL, $1);}
				//	{$$ = expression::NewExpression(ENDLINE, NULL, NULL);}
				;
			//errors =
			//	NONTERMINAL  MISSINGSEMICOLON { yyerror("Production Rule Missing Terminating ;\n"); }
			//| NONTERMINAL  BADIS { yyerror("Bad production assignment operator\n"); }
			//| error UNTERMINATEDDBLQUOTESTRING { yyerror("Unterminated \" string\n"); }
			//| error SEMICOLON { yyerror("Undetermined error\n"); }
			//| PRODUCTIONALREADYEXISTS {  }
			//;

			TerminalList= +TERMINAL;  // recordLexToken($1)
			//ProductionList = +Production;

			DefinitionList = 	+(root_node_d[Definition]); 		
			Definition = 	ExpressionList  >> 
				*( discard_node_d[chlit<>('|')] >>ExpressionList); //	{/*1*/ = defList:: NewDefList($1);} /*2*/ $$ = $1;			$1->pushBack($3);}
			//DefinitionList = 	Definition  >> *( '|' >>Definition); //	{/*1*/ = defList:: NewDefList($1);} /*2*/ $$ = $1;			$1->pushBack($3);}
			//Definition = 	ExpressionList; // 	{$$ = definition::NewDefinition($1); }
			////ExpressionList =	Expression[bind(&CEBNFParser::do_expression,self, expList::NewExpList(), "hel"  )]	
			ExpressionList =	+Expression	;
			Production = leftSide >>DefinitionList >>  ch_p(';') ;
			/*		guard_production
			(
			Production = leftSide >>DefinitionList >>  expect_semi(ch_p(';')) ;
			)
			[
			error_handler()
			];*/


		}

	};
	void EbnfParseIt();

};

//  Here's our  old comment rule
struct ebnf_skip_grammar : public grammar<ebnf_skip_grammar>
{
	template <typename ScannerT>
	struct definition
	{
		definition(ebnf_skip_grammar const& /*self*/)
		{
			skip_until_eol = *(('\\' >> eol_p) | (anychar_p - eol_p)),

				skip = 
				+( confix_p("//",*anychar_p,eol_p)  
				| confix_p("/*",*anychar_p,"*/") 
				| space_p  
				)

				;
		}

		rule<ScannerT> skip, skip_until_eol;
		rule<ScannerT> const& start() const { return skip; }
	};
};

