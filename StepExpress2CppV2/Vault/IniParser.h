//
//
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

#include <iostream>
#include <stack>
#include <functional>
#include <string>

//#ifdef BOOST_SPIRIT_DUMP_PARSETREE_AS_XML
#include <boost/spirit/tree/tree_to_xml.hpp>

#include "comdef.h"

using namespace std;
using namespace boost;
using namespace boost::spirit;

//  Here's our comment rule
struct ini_skip_grammar : public grammar<ini_skip_grammar>
{
    template <typename ScannerT>
    struct definition
    {
        definition(ini_skip_grammar const& /*self*/)
        {
            skip
                =   blank_p
                |   ";" >> *(anychar_p - '\n') >> '\n'     // C++ comment
                ;
        }

        rule<ScannerT> skip;
        rule<ScannerT> const& start() const { return skip; }
    };
};

struct  CIniParser :
	public boost::spirit::grammar<CIniParser>
{

	CIniParser(void)
	{
		rule_names[SectionID]             = "Section";
		rule_names[ParameterID]             = "Parameter";
		rule_names[PropertyID]             = "Property";
		rule_names[IndentifierID]             = "Identifier";
		rule_names[DblQuotedStrID]			="QuotedString";

	}
	~CIniParser(void){}
	typedef spirit::symbols<double> var_table_t;
	// var_table_t & vars;

	std::map<parser_id, std::string> rule_names;
	static const int SectionID = 1;
	static const int PropertyID = 2;
	static const int ParameterID = 3;
	static const int IndentifierID = 4;
	static const int DblQuotedStrID=5;
	static const int InifileID=6;
	static const int SectionHdrID=7;
	template <typename ScannerT>
	struct definition
	{
	public:

		rule<ScannerT, parser_context<>, parser_tag<InifileID> > Inifile;
		rule<ScannerT, parser_context<>, parser_tag<SectionHdrID> > SectionHdr;
		rule<ScannerT, parser_context<>, parser_tag<SectionID> > Section;
		rule<ScannerT, parser_context<>, parser_tag<ParameterID> > Parameter;
		rule<ScannerT, parser_context<>, parser_tag<PropertyID> > Property;
		rule<ScannerT, parser_context<>, parser_tag<IndentifierID> > Identifier;
		rule<ScannerT, parser_context<>, parser_tag<DblQuotedStrID> > DblQuotedStr;
		rule<ScannerT, parser_context<>, parser_tag<DblQuotedStrID> > STRING_LITERAL;
		rule<ScannerT>  Start;

		const boost::spirit::rule<ScannerT> &start() const { return Start; }

		definition( CIniParser const &self )
		{   
			STRING_LITERAL		= inner_node_d[ chlit<>('\"') >> *( strlit<>("\\\"") | anychar_p - chlit<>('\"') ) >> chlit<>('\"')]; //[&write]
			DblQuotedStr		= +STRING_LITERAL;	
			SectionHdr			= leaf_node_d	['[' >>  +alnum_p  >> ']'] >>  '\n' ; 
			Identifier			= lexeme_d	[ +alnum_p ];
			Section				= SectionHdr >> *(Property | (*blank_p >> '\n')); 
			Parameter			= leaf_node_d[ +alnum_p ] ;
			Property			= Identifier >> '=' >>   (Parameter | STRING_LITERAL) >> '\n';
			Inifile				= *Section; 
			Start				= Inifile;


			BOOST_SPIRIT_DEBUG_RULE(Identifier);
			BOOST_SPIRIT_DEBUG_RULE(Parameter);
			BOOST_SPIRIT_DEBUG_RULE(Section);
			BOOST_SPIRIT_DEBUG_RULE(Property);
			BOOST_SPIRIT_DEBUG_RULE(Inifile);

		}
	};
};
