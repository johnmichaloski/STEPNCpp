//
// StepParser.h
//
#pragma once
//#define BOOST_SPIRIT_DEBUG
//#define BOOST_SPIRIT_DEBUG_TRACENODE          (true)
//#define BOOST_SPIRIT_DEBUG_FLAGS  BOOST_SPIRIT_DEBUG_FLAGS_NODES 
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
//#include <boost/spirit/tree/tree_to_xml.hpp>
//#include <boost/spirit/phoenix/binders.hpp>
//#include <boost/lambda/lambda.hpp>
//#include <boost/lambda/bind.hpp>

//#include "comdef.h"
//#include "atlstr.h"

using namespace std;
using namespace boost;
using namespace boost::spirit;


class CStepNCParser
{
public:
	void ExpressParseIt();

};
