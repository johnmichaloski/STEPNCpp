//
// StepParser.h
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

struct CStep21Parser;
typedef string::iterator iter_t;

///////////////////////////////////////////////////////////////////////////
//
//  eol_parser class (contributed by Martin Wille)
//
///////////////////////////////////////////////////////////////////////////
extern	int linenumber;
struct step21_skip_parser : public parser<step21_skip_parser>
{ 
	typedef step21_skip_parser self_t;

	step21_skip_parser() {linenumber=0;}

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





struct  CStep21Parser :
	public boost::spirit::grammar<CStep21Parser>
{

	CStep21Parser(void);
	~CStep21Parser(void){}
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

	enum { STRING_LITERALID=1,DblQuotedStrID, SEMICOLONID, GrammarID,

		LOGICALTRUEID, LOGICALFALSEID, LOGICALUNKWNID,
		IDENTID, ENUMID, USER_DEFINED_KEYWORDID, BINARYID,
		Entity_exportID, EntityReferencesID, EmbeddedListID, ListID, ListEntryID,
		ParametersID, ParameterID, Subsuper_Record_List_ElementID, Simple_RecordID,
		Subsuper_Record_ListID, Subsuper_RecordID,Entity_Instance_RHSID,
		EntityNameID, EntityReferenceID, HeaderEntityID, HeaderSectionID,
		HeaderEntitiesID, ReqHdrEntitiesID, OptHdrEntitiesID, DataSectionID,
		DataEntityID, DataEntitiesID, ENTITY_NAMEID, HEADERID,
		KEYWORDID, STRINGID, MISSINGID

	};

	template <typename ScannerT>
	struct definition		
	{
	public:


		const boost::spirit::rule<ScannerT> &start() const { return ExchangeFile; }

		rule<ScannerT, parser_context<>, parser_tag<LOGICALTRUEID> > LOGICALFALSE;
		rule<ScannerT, parser_context<>, parser_tag<LOGICALFALSEID> > LOGICALTRUE;
		rule<ScannerT, parser_context<>, parser_tag<LOGICALUNKWNID> > LOGICALUNKWN;
		rule<ScannerT, parser_context<>, parser_tag<IDENTID> > IDENT;
		rule<ScannerT, parser_context<>, parser_tag<ENUMID> > ENUM;
		rule<ScannerT, parser_context<>, parser_tag<BINARYID> > BINARY;

		rule<ScannerT, parser_context<>, parser_tag<USER_DEFINED_KEYWORDID> > USER_DEFINED_KEYWORD;
		rule<ScannerT, parser_context<>, parser_tag<Entity_exportID> > Entity_export;
		rule<ScannerT, parser_context<>, parser_tag<EntityReferencesID> > EntityReferences;
		rule<ScannerT, parser_context<>, parser_tag<EmbeddedListID> > EmbeddedList;
		//		rule<ScannerT, parser_context<>, parser_tag<ListID> > List;
		//		rule<ScannerT, parser_context<>, parser_tag<ListEntryID> > ListEntry;
		rule<ScannerT, parser_context<>, parser_tag<ParametersID> > Parameters;
		rule<ScannerT, parser_context<>, parser_tag<ParameterID> > Parameter;
		rule<ScannerT, parser_context<>, parser_tag<Subsuper_Record_List_ElementID> > Subsuper_Record_List_Element;
		rule<ScannerT, parser_context<>, parser_tag<Simple_RecordID> > Simple_Record;
		rule<ScannerT, parser_context<>, parser_tag<Subsuper_Record_ListID> > Subsuper_Record_List;
		rule<ScannerT, parser_context<>, parser_tag<Subsuper_RecordID> > Subsuper_Record;
		rule<ScannerT, parser_context<>, parser_tag<Entity_Instance_RHSID> > Entity_Instance_RHS;
		rule<ScannerT, parser_context<>, parser_tag<EntityNameID> > EntityName;
		rule<ScannerT, parser_context<>, parser_tag<EntityReferenceID> > EntityReference;
		rule<ScannerT, parser_context<>, parser_tag<HeaderEntityID> > HeaderEntity;
		rule<ScannerT, parser_context<>, parser_tag<HeaderSectionID> > HeaderSection;
		rule<ScannerT, parser_context<>, parser_tag<HeaderEntitiesID> > HeaderEntities;
		rule<ScannerT, parser_context<>, parser_tag<ReqHdrEntitiesID> > ReqHdrEntities;
		rule<ScannerT, parser_context<>, parser_tag<OptHdrEntitiesID> > OptHdrEntities;
		rule<ScannerT, parser_context<>, parser_tag<DataSectionID> > DataSection;
		rule<ScannerT, parser_context<>, parser_tag<DataEntityID> > DataEntity;
		rule<ScannerT, parser_context<>, parser_tag<DataEntitiesID> > DataEntities;

		rule<ScannerT, parser_context<>, parser_tag<ENTITY_NAMEID> > ENTITY_NAME;
		rule<ScannerT, parser_context<>, parser_tag<HEADERID> > HEADER;
		rule<ScannerT, parser_context<>, parser_tag<KEYWORDID> > KEYWORD;
		rule<ScannerT, parser_context<>, parser_tag<MISSINGID> > MISSING;
		rule<ScannerT, parser_context<>, parser_tag<STRINGID> > STRING;



		rule<ScannerT, parser_context<>, parser_tag<STRING_LITERALID> > STRING_LITERAL;
		rule<ScannerT> ExchangeFile ;
		rule<ScannerT> EQUALS, SEMICOLON, LEFT_PAREN,RIGHT_PAREN, SLASH, REDEFINE ;
		rule<ScannerT> SCOPE, ISO_10303_21, END_ISO_10303_21, ENDSEC, ENDSCOPE,DATA, COMMA ;


		symbols<>voidcommands;

		//assertion_t expect_semicolon, expect_close_bracket;

		definition( CStep21Parser const &self )
		{   

			ExchangeFile= ISO_10303_21 >> SEMICOLON >>
				HeaderSection  >>	
				DataSection >>  
				END_ISO_10303_21 >> SEMICOLON  >> *(anychar_p);


			IDENT	=  leaf_node_d[lexeme_d[+range_p('A','Z') >> *(alnum_p|'_')]];
			HEADER = str_p("HEADER");

			EQUALS = str_p("="); 	
			SEMICOLON = str_p(";"); 	
			COMMA = str_p(","); 	
			LEFT_PAREN = str_p("("); 	
			RIGHT_PAREN = str_p(")"); 	
			SLASH = str_p("/"); 	
			MISSING = str_p("$"); 	
			REDEFINE = str_p("*"); 	
			BINARY =   ch_p('\"') >> range_p('0','3') >> *alnum_p >> ch_p('\"');
			SCOPE = str_p("&SCOPE"); 	
			ISO_10303_21 = str_p("ISO-10303-21"); 	
			END_ISO_10303_21 = str_p("END-ISO-10303-21"); 	
			ENDSEC = str_p("ENDSEC"); 	
			ENDSCOPE = str_p("ENDSCOPE"); 	
			DATA = str_p("DATA"); 	
			LOGICALTRUE = str_p(".T.");
			LOGICALFALSE = str_p(".F.");
			LOGICALUNKWN = str_p(".U.");
			ENUM =  leaf_node_d[lexeme_d[ch_p('.') >> +range_p('A','Z') >> *(alnum_p|'_') >> ch_p('.')]] ;
			USER_DEFINED_KEYWORD =  ch_p('!') >> IDENT  ;
			ENTITY_NAME = leaf_node_d[lexeme_d[ch_p('#') >>+range_p('0','9')]];
			STRING_LITERAL		= inner_node_d[ ch_p('\"') >> *( strlit<>("\\\"") | anychar_p - ch_p('\"') ) >> ch_p('\"')]; 

			KEYWORD = 	 ENDSCOPE |  ENDSEC | 
				str_p("FILE_DESCRIPTION") | str_p("FILE_NAME") 	| str_p("FILE_SCHEMA")
				| IDENT;
			STRING		= leaf_node_d[inner_node_d[ ch_p('\'') >> *( anychar_p - ch_p('\'') ) >> ch_p('\'')]]; //[&write]

			HeaderSection	= HEADER >> SEMICOLON >> +HeaderEntity >> ENDSEC >> SEMICOLON ;
			HeaderEntity	= KEYWORD >> LEFT_PAREN >> Parameters  >>RIGHT_PAREN >> SEMICOLON;
			HeaderEntities	= ReqHdrEntities >> *(OptHdrEntities); 
			ReqHdrEntities	= HeaderEntity >> HeaderEntity>> HeaderEntity;
			OptHdrEntities	= *(HeaderEntity >> SEMICOLON);

			DataSection	=  DATA >> SEMICOLON >> +DataEntity >> ENDSEC >> SEMICOLON ;
			DataEntities	= +DataEntity;

			DataEntity	= EntityName >> discard_node_d[EQUALS] >>  Entity_Instance_RHS  >> SEMICOLON
				| EntityName >> discard_node_d[EQUALS] >> SCOPE ;

			EntityName	= ENTITY_NAME;
			EntityReference	= ENTITY_NAME;
			Entity_Instance_RHS	= Simple_Record	| Subsuper_Record 			;
			Subsuper_Record		= LEFT_PAREN >> Subsuper_Record_List >> RIGHT_PAREN;
			Subsuper_Record_List	= +Subsuper_Record_List_Element;

			Subsuper_Record_List_Element	= KEYWORD >> LEFT_PAREN >> Parameters >> RIGHT_PAREN;

			Simple_Record	= KEYWORD >> LEFT_PAREN >> Parameters >> RIGHT_PAREN
				| USER_DEFINED_KEYWORD >> LEFT_PAREN >> Parameters >> RIGHT_PAREN;

			Parameters	=  *list_p(Parameter, ',' );


			Parameter	= leaf_node_d[MISSING]
				| REDEFINE
				| real_p
				| int_p
				| ENUM
				| STRING
				| BINARY
				| EntityReference
				| EmbeddedList;

			Entity_export   = *(SLASH >> EntityReferences >> SLASH);

			EntityReferences= EntityReference | EntityReferences >> COMMA >> EntityReference;
			EmbeddedList	= discard_node_d[LEFT_PAREN] >> *list_p( Parameter, ',' ) >> discard_node_d[RIGHT_PAREN] ;

			BOOST_SPIRIT_DEBUG_RULE(ExchangeFile);
			BOOST_SPIRIT_DEBUG_RULE(ISO_10303_21);
			BOOST_SPIRIT_DEBUG_RULE(KEYWORD);
			BOOST_SPIRIT_DEBUG_RULE(KEYWORD);
			BOOST_SPIRIT_DEBUG_RULE(HeaderSection);
			BOOST_SPIRIT_DEBUG_RULE(HeaderEntity);
			BOOST_SPIRIT_DEBUG_RULE(HEADER);
			BOOST_SPIRIT_DEBUG_RULE(STRING);
			BOOST_SPIRIT_DEBUG_RULE(LEFT_PAREN);
			BOOST_SPIRIT_DEBUG_RULE(RIGHT_PAREN);
			BOOST_SPIRIT_DEBUG_RULE(Parameter);
			BOOST_SPIRIT_DEBUG_RULE(Parameters);
			BOOST_SPIRIT_DEBUG_RULE(EmbeddedList);
			BOOST_SPIRIT_DEBUG_RULE(DataSection);
			BOOST_SPIRIT_DEBUG_RULE(DataEntities);
			BOOST_SPIRIT_DEBUG_RULE(DataEntity);
			BOOST_SPIRIT_DEBUG_RULE(Entity_Instance_RHS);
			BOOST_SPIRIT_DEBUG_RULE(Subsuper_Record);
			BOOST_SPIRIT_DEBUG_RULE(Subsuper_Record_List_Element);
			BOOST_SPIRIT_DEBUG_RULE(Simple_Record);
			BOOST_SPIRIT_DEBUG_RULE(ENTITY_NAME);
			BOOST_SPIRIT_DEBUG_RULE(IDENT);


		}

	};
	void Step21ParseIt();

};

//  Here's our  old comment rule
struct step_skip_grammar : public grammar<step_skip_grammar>
{
	template <typename ScannerT>
	struct definition
	{
		definition(step_skip_grammar const& /*self*/)
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

