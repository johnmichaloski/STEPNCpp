//
// ScriptParser.h
//

// DISCLAIMER: 
//  This software was produced by the National Institute of Standards 
//  and Technology (NIST), an agency of the U.S. government, and by statute is 
//  not subject to copyright in the United States.  Recipients of this 
//  software assume all responsibility associated with its operation,
//  modification,maintenance, and subsequent redistribution. 
//
//  See NIST Administration Manual 4.09.07 b and Appendix I. 

#pragma once

#include <map>
#include <iostream>
#include <stack>
#include <functional>
#include <string>

#include "comdef.h"
#include "atlstr.h"

//#include <boost/regex.hpp>
//#include <boost/archive/xml_oarchive.hpp>

#include <boost/spirit.hpp>
#include <boost/version.hpp>
#include <boost/spirit/core.hpp>
#include <boost/spirit/tree/parse_tree.hpp>
#include <boost/spirit/tree/ast.hpp>
#include <boost/function.hpp>


//#ifdef BOOST_SPIRIT_DUMP_PARSETREE_AS_XML
#include <boost/spirit/tree/tree_to_xml.hpp>
#include <boost/spirit/iterator/position_iterator.hpp>

#include "StepVariant.h"

using namespace std;
using namespace boost;
using namespace boost::spirit;
using boost::spirit::position_iterator;

#ifdef UNICODE
typedef position_iterator<WCHAR const*, file_position_base<tstring> > iterator_t;
#else
typedef position_iterator<char const* > iterator_t;
#endif

class CEvalStack 
{
public:

	void PushOp( int op);
	void PushData(Variant data ) ;
	void EvalStack();
	CString ToString();

	std::vector<Variant> datastack;
	std::vector<int> opstack;
	static int debug;
};

class CScriptParser :
	 public CWindowImpl<CScriptParser, CWindow, CNullTraits> // hidden window to allow WM_TIMER messages
{
public:
	CScriptParser();
	virtual ~CScriptParser();
	typedef tree_match<iterator_t>::container_t::iterator TreeIter;
	
	/////// Overrides

	virtual Variant GetVariable(CString var) 
	{ 
		return _variables[var]; 
	}
	virtual HRESULT SetVariable(CString var,Variant val) 
	{  
		_variables[var]=val; 
		return S_OK;
	}
	virtual void AddVariable(CString var,Variant val) 
	{  
		_variables[var]=val; 
	}
	BEGIN_MSG_MAP(CScriptParser)
		MESSAGE_HANDLER(WM_TIMER, OnTimer)
	END_MSG_MAP()

	LRESULT OnTimer(UINT, WPARAM, LPARAM, BOOL&);

	tree_parse_info<iterator_t> ParseAFile(CString filename);
	tree_parse_info<iterator_t> ParseAString(tstring text, tstring filename);
	//template<typename TreeIter> int evaluate(const TreeIter& i);

	void Clear() { evalstack.opstack.clear();  evalstack.datastack.clear(); }
	int evaluate(const tree_match<iterator_t>::container_t::iterator& i);

	CString ToString();
	CStringVector GetErrorMessages();

	std::map<CString, Variant> _variables;
	CEvalStack  evalstack;
};


//  Here's our comment rule
struct ini_skip_grammar : public grammar<ini_skip_grammar>
{
    template <typename ScannerT>
    struct definition
    {
        definition(ini_skip_grammar const& /*self*/)
        {
            skip
                =   space_p
					|   ch_p('\r')     // carriage return
					|   str_p("//") >> *(anychar_p - '\n') >> '\n'     // C++ comment
				 ;
        }

        rule<ScannerT> skip;
        rule<ScannerT> const& start() const { return skip; }
    };
};

