//
// StepParser.h
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.


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
#include <boost/spirit/iterator/position_iterator.hpp>

#include <iostream>
#include <stack>
#include <functional>
#include <string>
#include "Misc.h"
#include "CreateCPPClasses.h"

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
typedef position_iterator<char const*> iterator_t;

class CExpressTokens
{
public:
	
	enum  { STRING_LITERALID=1,DblQuotedStrID, SEMICOLONID, GrammarID,
		add_like_opID, binary_literalID, bitID, characterID, digitID, digitsID, 
		integer_literalID, letterID, logical_literalID, lparen_not_starID, 
		multiplication_like_opID, not_lparen_starID, not_paren_starID, 
		not_paren_star_specialID, not_rparenID, not_starID, real_literalID, 
		rel_opID, signID, simple_idID, specialID, star_not_rparenID, 
		string_literalID, actual_parameter_listID, aggregate_initializerID, 
		aggregate_sourceID, aggregate_typeID, aggregation_typesID, 
		algorithm_headID, alias_idID, alias_refID, alias_stmtID, 
		array_typeID, assignment_stmtID, attribute_declID, 
		attribute_idID, attribute_qualifierID, attribute_refID, bag_typeID, 
		base_typeID, binary_typeID, boolean_typeID, bound_lID, 
		bound_2ID, bound_specID, built_in_constantID, 
		built_in_functionID, built_in_procedureID, 
		case_actionID, case_labelID, case_stmtID, 
		compound_stmtID, conformant_aggregateID, conformant_typeID, 
		constant_declID, constant_bodyID, constant_factorID, 
		constant_idID, constant_refID, declarationID, 
		derived_attrID, derive_clauseID, elementID, 
		embedded_remarkID, entity_blockID, entity_bodyID, 
		entity_headID, entity_idID, entity_initID, entity_or_renameID, entity_refID, 
		enumeration_idID, enumeration_refID, enumeration_typeID, escape_stmtID,
		explicit_attrID, expressionID, factorID, formal_parameterID, function_blockID,
		function_callID, function_headID, function_idID, function_refID, general_refID, 
		generic_typeID, group_qualifierID, if_stmtID, incrementID, increment_controlID, 
		indexID, index_qualitierID, initializerID, integer_typeID, interface_specificationID, 
		intervalID, interval_itemID, interval_opID, inverse_attrID, inverse_clauseID, labelID, 
		labelled_attrib_listID, labelled_expressionID, list_typeID, literal_pID, 
		local_declID, local_variableID,	logical_expressionID, logical_typeID, named_typesID, 
		null_stmtID, number_typeID, one_ofID, parameterID, parameter_idID, parameter_refID, 
		parameter_typeID, precision_specID, procedure_blockID, procedure_call_stmtID,
		procedure_headID, procedure_idID, procedure_refID, qualifierID, qualifiable_factorID, 
		qualified_attributeID, query_expressionID, real_typeID, reference_clauseID, referenced_attributeID, 
		rel_op_extendedID, remarkID, rename_idID, repeat_controlID, repeat_stmtID, repetitionID, 
		resource_or_renameID, resource_refID, return_stmtID, rule_blockID, rule_headID, 
		rule_idID, schema_blockID, schema_bodyID, schema_idID, schema_refID, select_typeID, 
		selectorID, set_typeID, simple_expressionID, simple_factorID, simple_typesID, 
		skip_stmtID, stmtID, string_typeID, subcomponent_qualifierID, subsuperID, subsuper_initID, 
		subtype_declarationID, supertype_declarationID, supertype_expressionID, 
		supertype_factorID, tail_remarkID, termID, type_declID, type_idID, type_labelID, 
		type_refID, unary_opID, underlying_typeID, unique_clauseID, until_controlID, 
		use_clauseID, variable_idID, variable_refID, where_clauseID, while_controlID, widthID,

		subtype_listID,

		paren_expressionID,
		semicolonID,
		ErrorLineID


	};
};

inline std::vector<parser_id> & Nodes(std::vector<parser_id> & nodes, parser_id p1, ...)
{
  va_list list;
   va_start(list,p1); 
   nodes.clear();
   for(;;)
   { 
	   parser_id p=va_arg(list,parser_id);
	   if(p== 0)
		   break;
	   nodes.push_back(p); 
   }
   va_end(list); // cleanup , set 'lsit' to NULL
   return nodes;
}

template<typename TreeIter>
int findNode(const TreeIter &i, TreeIter& findit, int  n, std::vector<parser_id> & nodes )
{
	for(TreeIter it = i->children.begin();it!=i->children.end(); it++) 
	{  
		if(n>=nodes.size() || n<0)
			return 0;
		// fixme add wild card.
		int node  = it->value.id().to_long();
		if( nodes[n] == node  )
		{
			n++;
			if(n==nodes.size())
			{
				findit=it;
				return 1;
			}
			if (findNode(it, findit, n, nodes))
				return 1;
		}
	}
	return 0;
}
// depth search of tree for matching parser id.
template<typename TreeIter>
int findANode(const TreeIter &i, TreeIter& findit, parser_id id)
{
	for(TreeIter it = i->children.begin();it!=i->children.end(); it++) 
	{  
		// fixme add wild card.
		int node  = it->value.id().to_long();
		if( id == node  )
		{
			findit=it;
			return 1;
		}
		if (findANode(it, findit, id))
			return 1;
	}
	return 0;
}

// depth search of tree for matching parser id.
template<typename TreeIter>
std::string getText(const TreeIter &i, std::string separator)
{
	std::string tmp;
	for(TreeIter it = i->children.begin();it!=i->children.end(); it++) 
	{  
		std::string str = std::string(it->value.begin(), it->value.end());
		if(str.size() > 0)
		{
			tmp+=str;
			tmp+=separator;

		}
		tmp+=getText(it, separator);

	}
	return tmp;
}


class CStepNCParser
{
public:
	void Clear() 
	{ 
		symtable.Clear();
		info.trees.clear();

	}	
	
	HRESULT ExpressParseIt(CStringVector szSchema);
	void CreateCPPClasses(CString szSchema);


	tree_parse_info<iterator_t> info;
	//tree_parse_info<const char*> info;
	SymbolTable symtable;

};
