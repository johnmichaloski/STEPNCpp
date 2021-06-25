//
// StepParser.h
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

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

#include "ExpressUtils.h"


extern std::map<CString, CString> NamedEntities;
extern std::map<CString, IStepNodePtr> entityInstances;
extern std::vector<IStepNodePtr> entities;
extern std::vector<long> variables;

extern IStepNodePtr project;

struct  CStep21Parser :
	public boost::spirit::grammar<CStep21Parser>
{

	CStep21Parser(void);
	~CStep21Parser(void){}
	HRESULT Step21ParseIt(CString filename);
	CString & P21filename() { return _p21filename; }
	CString _p21filename;

};


extern	int linenumber;
typedef string::iterator iter_t;
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
