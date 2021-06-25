//
// ExpressParser.h
//
#pragma once
#define BOOST_SPIRIT_DEBUG

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

struct CExpressParser;
typedef string::iterator iter_t;

///////////////////////////////////////////////////////////////////////////
//
//  eol_parser class (contributed by Martin Wille)
//
///////////////////////////////////////////////////////////////////////////
extern	int linenumber;
struct express_skip_parser : public parser<express_skip_parser>
{ 
	typedef express_skip_parser self_t;

	express_skip_parser() {linenumber=0;}

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


		chseq<char*> str("(*");
		if (str.parse(scan)) //!scan.at_end() &&  *scan == '/') 
		{
			len+=2; 
			for( ;!scan.at_end(); ++scan.first,++len )
			{
				if(*scan != '*')
					continue;
				chseq<char*> str("*)");
				if (str.parse(scan))
					break;

			}
		}

		if (len)
			return scan.create_match(len, nil_t(), save, scan.first);
		return scan.no_match();
	}
};





struct  CExpressParser :
	public boost::spirit::grammar<CExpressParser>
{

	CExpressParser(void);
	~CExpressParser(void){}
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

		paren_expressionID,

		 abstract_supertype_declarationID, subtype_constraintID, width_specID, bound_1ID, numeric_expressionID,
			constructed_typesID, entity_declID, function_declID, procedure_declID, domain_ruleID, index_1ID, index_2ID,
			interval_highID, interval_lowID, named_type_or_renameID,rule_declID, populationID, simple_string_literalID,
			encoded_string_literalID, supertype_constraintID, supertype_ruleID, supertype_termID, syntaxID, schema_declID,
			type_label_idID, type_label_refID, unique_ruleID

	};

	template <typename ScannerT>
	struct definition		
	{
	public:


		const boost::spirit::rule<ScannerT> &start() const { return syntax; }

		rule<ScannerT, parser_context<>, parser_tag<add_like_opID> >  add_like_op;
		rule<ScannerT, parser_context<>, parser_tag<binary_literalID> >  binary_literal;
		rule<ScannerT, parser_context<>, parser_tag<bitID> >  bit;
		rule<ScannerT, parser_context<>, parser_tag<characterID> >  character;
		rule<ScannerT, parser_context<>, parser_tag<digitID> >  digit;
		rule<ScannerT, parser_context<>, parser_tag<digitsID> >  digits;
		rule<ScannerT, parser_context<>, parser_tag<integer_literalID> > integer_literal;
		rule<ScannerT, parser_context<>, parser_tag<letterID> >  letter;
		rule<ScannerT, parser_context<>, parser_tag<logical_literalID> >  logical_literal;
		rule<ScannerT, parser_context<>, parser_tag<lparen_not_starID> >  lparen_not_star;
		rule<ScannerT, parser_context<>, parser_tag<multiplication_like_opID> >  multiplication_like_op;
		rule<ScannerT, parser_context<>, parser_tag<not_lparen_starID> >  not_lparen_star;
		rule<ScannerT, parser_context<>, parser_tag<not_paren_starID> >  not_paren_star;
		rule<ScannerT, parser_context<>, parser_tag<not_paren_star_specialID> >  not_paren_star_special;
		rule<ScannerT, parser_context<>, parser_tag<not_rparenID> >  not_rparen;
		rule<ScannerT, parser_context<>, parser_tag<not_starID> >  not_star;
		rule<ScannerT, parser_context<>, parser_tag<real_literalID> >  real_literal;
		rule<ScannerT, parser_context<>, parser_tag<rel_opID> >  rel_op;
		rule<ScannerT, parser_context<>, parser_tag<signID> >  sign;
		rule<ScannerT, parser_context<>, parser_tag<simple_idID> >  simple_id;
		rule<ScannerT, parser_context<>, parser_tag<specialID> >  special;
		rule<ScannerT, parser_context<>, parser_tag<star_not_rparenID> >  star_not_rparen;
		rule<ScannerT, parser_context<>, parser_tag<string_literalID> >  string_literal;
		rule<ScannerT, parser_context<>, parser_tag<actual_parameter_listID> >  actual_parameter_list;
		rule<ScannerT, parser_context<>, parser_tag<aggregate_initializerID> >  aggregate_initializer;
		rule<ScannerT, parser_context<>, parser_tag<aggregate_sourceID> >  aggregate_source;
		rule<ScannerT, parser_context<>, parser_tag<aggregate_typeID> >  aggregate_type;
		rule<ScannerT, parser_context<>, parser_tag<aggregation_typesID> >  aggregation_types;
		rule<ScannerT, parser_context<>, parser_tag<algorithm_headID> >  algorithm_head;
		rule<ScannerT, parser_context<>, parser_tag<alias_idID> >  alias_id;
		rule<ScannerT, parser_context<>, parser_tag<alias_refID> >  alias_ref;
		rule<ScannerT, parser_context<>, parser_tag<alias_stmtID> >  alias_stmt;
		rule<ScannerT, parser_context<>, parser_tag<array_typeID> >  array_type;
		rule<ScannerT, parser_context<>, parser_tag<assignment_stmtID> > assignment_stmt ;
		rule<ScannerT, parser_context<>, parser_tag<attribute_declID> >  attribute_decl;
		rule<ScannerT, parser_context<>, parser_tag<attribute_idID> >  attribute_id;
		rule<ScannerT, parser_context<>, parser_tag<attribute_qualifierID> >  attribute_qualifier;
		rule<ScannerT, parser_context<>, parser_tag<attribute_refID> >  attribute_ref;
		rule<ScannerT, parser_context<>, parser_tag<bag_typeID> >  bag_type;
		rule<ScannerT, parser_context<>, parser_tag<base_typeID> >  base_type;
		rule<ScannerT, parser_context<>, parser_tag<binary_typeID> >  binary_type;
		rule<ScannerT, parser_context<>, parser_tag<boolean_typeID> >  boolean_type;
		rule<ScannerT, parser_context<>, parser_tag<bound_lID> >  bound_l;
		rule<ScannerT, parser_context<>, parser_tag<bound_2ID> >  bound_2;
		rule<ScannerT, parser_context<>, parser_tag<bound_specID> >  bound_spec;
		rule<ScannerT, parser_context<>, parser_tag<built_in_constantID> >  built_in_constant;
		rule<ScannerT, parser_context<>, parser_tag<built_in_functionID> >  built_in_function;
		rule<ScannerT, parser_context<>, parser_tag<built_in_procedureID> >  built_in_procedure;
		rule<ScannerT, parser_context<>, parser_tag<case_actionID> >  case_action;
		rule<ScannerT, parser_context<>, parser_tag<case_labelID> >  case_label;
		rule<ScannerT, parser_context<>, parser_tag<case_stmtID> >  case_stmt;
		rule<ScannerT, parser_context<>, parser_tag<compound_stmtID> >  compound_stmt;
		rule<ScannerT, parser_context<>, parser_tag<conformant_aggregateID> >  conformant_aggregate;
		rule<ScannerT, parser_context<>, parser_tag<conformant_typeID> >  conformant_type;
		rule<ScannerT, parser_context<>, parser_tag<constant_declID> >  constant_decl;
		rule<ScannerT, parser_context<>, parser_tag<constant_bodyID> >  constant_body;
		rule<ScannerT, parser_context<>, parser_tag<constant_factorID> >  constant_factor;
		rule<ScannerT, parser_context<>, parser_tag<constant_idID> >  constant_id;
		rule<ScannerT, parser_context<>, parser_tag<constant_refID> >  constant_ref;
		rule<ScannerT, parser_context<>, parser_tag<declarationID> >  declaration;
		rule<ScannerT, parser_context<>, parser_tag<derived_attrID> >  derived_attr;
		rule<ScannerT, parser_context<>, parser_tag<derive_clauseID> >  derive_clause;
		rule<ScannerT, parser_context<>, parser_tag<elementID> >  element;
		rule<ScannerT, parser_context<>, parser_tag<embedded_remarkID> >  embedded_remark;
		rule<ScannerT, parser_context<>, parser_tag<entity_blockID> >  entity_block;
		rule<ScannerT, parser_context<>, parser_tag<entity_bodyID> >  entity_body;
		rule<ScannerT, parser_context<>, parser_tag<entity_headID> >  entity_head;
		rule<ScannerT, parser_context<>, parser_tag<entity_idID> >  entity_id;
		rule<ScannerT, parser_context<>, parser_tag<entity_initID> >  entity_init;
		rule<ScannerT, parser_context<>, parser_tag<entity_or_renameID> >  entity_or_rename;
		rule<ScannerT, parser_context<>, parser_tag<entity_refID> >  entity_ref;
		rule<ScannerT, parser_context<>, parser_tag<enumeration_idID> >  enumeration_id;
		rule<ScannerT, parser_context<>, parser_tag<enumeration_refID> >  enumeration_ref;
		rule<ScannerT, parser_context<>, parser_tag<enumeration_typeID> > enumeration_type ;
		rule<ScannerT, parser_context<>, parser_tag<escape_stmtID> >  escape_stmt;
		rule<ScannerT, parser_context<>, parser_tag<explicit_attrID> >  explicit_attr;
		rule<ScannerT, parser_context<>, parser_tag<expressionID> >  expression;

		rule<ScannerT, parser_context<>, parser_tag<factorID> >  factor;
		rule<ScannerT, parser_context<>, parser_tag<formal_parameterID> > formal_parameter ;
		rule<ScannerT, parser_context<>, parser_tag<function_blockID> >  function_block;
		rule<ScannerT, parser_context<>, parser_tag<function_callID> >  function_call;
		rule<ScannerT, parser_context<>, parser_tag<function_headID> >  function_head;
		rule<ScannerT, parser_context<>, parser_tag<function_idID> >  function_id;
		rule<ScannerT, parser_context<>, parser_tag<function_refID> >  function_ref;
		rule<ScannerT, parser_context<>, parser_tag<general_refID> >  general_ref;
		rule<ScannerT, parser_context<>, parser_tag<generic_typeID> >  generic_type;
		rule<ScannerT, parser_context<>, parser_tag<group_qualifierID> >  group_qualifier;
		rule<ScannerT, parser_context<>, parser_tag<if_stmtID> >  if_stmt;
		rule<ScannerT, parser_context<>, parser_tag<incrementID> >  increment;
		rule<ScannerT, parser_context<>, parser_tag<increment_controlID> >  increment_control;
		rule<ScannerT, parser_context<>, parser_tag<indexID> >  index;
		rule<ScannerT, parser_context<>, parser_tag<index_qualitierID> >  index_qualifier;
		rule<ScannerT, parser_context<>, parser_tag<initializerID> >  initializer;
		rule<ScannerT, parser_context<>, parser_tag<integer_typeID> >  integer_type;
		rule<ScannerT, parser_context<>, parser_tag<interface_specificationID> >  interface_specification;
		rule<ScannerT, parser_context<>, parser_tag<intervalID> >  interval;
		rule<ScannerT, parser_context<>, parser_tag<interval_itemID> >  interval_item;
		rule<ScannerT, parser_context<>, parser_tag<interval_opID> >  interval_op;
		rule<ScannerT, parser_context<>, parser_tag<inverse_attrID> >  inverse_attr;
		rule<ScannerT, parser_context<>, parser_tag<inverse_clauseID  > > inverse_clause;
		rule<ScannerT, parser_context<>, parser_tag<labelID> >  label;
		rule<ScannerT, parser_context<>, parser_tag<labelled_attrib_listID> >  labelled_attrib_list;
		rule<ScannerT, parser_context<>, parser_tag<labelled_expressionID> >  labelled_expression;
		rule<ScannerT, parser_context<>, parser_tag<list_typeID> >  list_type;
		rule<ScannerT, parser_context<>, parser_tag<literal_pID> >  literal_p;
		rule<ScannerT, parser_context<>, parser_tag<local_declID> >  local_decl;
		rule<ScannerT, parser_context<>, parser_tag<local_variableID> >   local_variable;
		rule<ScannerT, parser_context<>, parser_tag<logical_expressionID> >  logical_expression;
		rule<ScannerT, parser_context<>, parser_tag<logical_typeID> >  logical_type;
		rule<ScannerT, parser_context<>, parser_tag<named_typesID> >  named_types;
		rule<ScannerT, parser_context<>, parser_tag<null_stmtID> >  null_stmt;
		rule<ScannerT, parser_context<>, parser_tag<number_typeID> >  number_type;
		rule<ScannerT, parser_context<>, parser_tag<one_ofID> >  one_of;
		rule<ScannerT, parser_context<>, parser_tag<parameterID> >  parameter;
		rule<ScannerT, parser_context<>, parser_tag<parameter_idID> >  parameter_id;
		rule<ScannerT, parser_context<>, parser_tag<parameter_refID> >  parameter_ref;
		rule<ScannerT, parser_context<>, parser_tag<parameter_typeID> >  parameter_type;
		rule<ScannerT, parser_context<>, parser_tag<precision_specID> >  precision_spec;
		rule<ScannerT, parser_context<>, parser_tag<procedure_blockID> >  procedure_block;
		rule<ScannerT, parser_context<>, parser_tag<procedure_call_stmtID> >  procedure_call_stmt;
		rule<ScannerT, parser_context<>, parser_tag<procedure_headID > > procedure_head;
		rule<ScannerT, parser_context<>, parser_tag<procedure_idID> >  procedure_id;
		rule<ScannerT, parser_context<>, parser_tag<procedure_refID> >  procedure_ref;
		rule<ScannerT, parser_context<>, parser_tag<qualifierID> >  qualifier;
		rule<ScannerT, parser_context<>, parser_tag<qualifiable_factorID> >  qualifiable_factor;
		rule<ScannerT, parser_context<>, parser_tag<qualified_attributeID> >  qualified_attribute;
		rule<ScannerT, parser_context<>, parser_tag<query_expressionID> >  query_expression;
		rule<ScannerT, parser_context<>, parser_tag<real_typeID> >  real_type;
		rule<ScannerT, parser_context<>, parser_tag<reference_clauseID> >  reference_clause;
		rule<ScannerT, parser_context<>, parser_tag<referenced_attributeID> >  referenced_attribute;
		rule<ScannerT, parser_context<>, parser_tag<rel_op_extendedID> >  rel_op_extended;
		rule<ScannerT, parser_context<>, parser_tag<remarkID> >  remark;
		rule<ScannerT, parser_context<>, parser_tag<rename_idID> >  rename_id;
		rule<ScannerT, parser_context<>, parser_tag<repeat_controlID> >  repeat_control;
		rule<ScannerT, parser_context<>, parser_tag<repeat_stmtID> >  repeat_stmt;
		rule<ScannerT, parser_context<>, parser_tag<repetitionID> >  repetition;
		rule<ScannerT, parser_context<>, parser_tag<resource_or_renameID> >  resource_or_rename;
		rule<ScannerT, parser_context<>, parser_tag<resource_refID> >  resource_ref;
		rule<ScannerT, parser_context<>, parser_tag<return_stmtID> >  return_stmt;
		rule<ScannerT, parser_context<>, parser_tag<rule_blockID> >  rule_block;
		rule<ScannerT, parser_context<>, parser_tag<rule_headID> >  rule_head;
		rule<ScannerT, parser_context<>, parser_tag<rule_idID> >  rule_id;
		rule<ScannerT>  schema_block;
		rule<ScannerT, parser_context<>, parser_tag<schema_bodyID> >  schema_body;
		rule<ScannerT, parser_context<>, parser_tag<schema_idID> >  schema_id;
		rule<ScannerT, parser_context<>, parser_tag<schema_refID> >  schema_ref;
		rule<ScannerT, parser_context<>, parser_tag<select_typeID> >  select_type;
		rule<ScannerT, parser_context<>, parser_tag<selectorID> >  selector;
		rule<ScannerT, parser_context<>, parser_tag<set_typeID> >  set_type;
		rule<ScannerT, parser_context<>, parser_tag<simple_expressionID> >  simple_expression;
		rule<ScannerT, parser_context<>, parser_tag<simple_factorID> >  simple_factor;
		rule<ScannerT, parser_context<>, parser_tag<simple_typesID> >  simple_types;
		rule<ScannerT, parser_context<>, parser_tag<skip_stmtID> >  skip_stmt;
		rule<ScannerT, parser_context<>, parser_tag<stmtID> >  stmt;
		rule<ScannerT, parser_context<>, parser_tag<string_typeID> >  string_type;
		rule<ScannerT, parser_context<>, parser_tag<subcomponent_qualifierID> >  subcomponent_qualifier;
		rule<ScannerT, parser_context<>, parser_tag<subsuperID> >  subsuper;
		rule<ScannerT, parser_context<>, parser_tag<subsuper_initID> >  subsuper_init;
		rule<ScannerT, parser_context<>, parser_tag<subtype_declarationID> >  subtype_declaration;
		rule<ScannerT, parser_context<>, parser_tag<supertype_declarationID> >  supertype_declaration;
		rule<ScannerT, parser_context<>, parser_tag<supertype_expressionID> >  supertype_expression;
		rule<ScannerT, parser_context<>, parser_tag<supertype_factorID> >  supertype_factor;
		rule<ScannerT, parser_context<>, parser_tag<tail_remarkID> >  tail_remark;
		rule<ScannerT, parser_context<>, parser_tag<termID> >  term;
		rule<ScannerT, parser_context<>, parser_tag<type_declID> >  type_decl;
		rule<ScannerT, parser_context<>, parser_tag<type_idID> >  type_id;
		rule<ScannerT, parser_context<>, parser_tag<type_labelID> >  type_label;
		rule<ScannerT, parser_context<>, parser_tag<type_refID> >  type_ref;
		rule<ScannerT, parser_context<>, parser_tag<unary_opID> >  unary_op;
		rule<ScannerT, parser_context<>, parser_tag<underlying_typeID> >  underlying_type;
		rule<ScannerT, parser_context<>, parser_tag<unique_clauseID > > unique_clause;
		rule<ScannerT, parser_context<>, parser_tag<until_controlID> >  until_control;
		rule<ScannerT, parser_context<>, parser_tag<use_clauseID> >  use_clause;
		rule<ScannerT, parser_context<>, parser_tag<variable_idID> >  variable_id;
		rule<ScannerT, parser_context<>, parser_tag<variable_refID> >  variable_ref;
		rule<ScannerT, parser_context<>, parser_tag<where_clauseID> >  where_clause;
		rule<ScannerT, parser_context<>, parser_tag<while_controlID> >  while_control;
		rule<ScannerT, parser_context<>, parser_tag<widthID> >  width;	

		rule<ScannerT, parser_context<>, parser_tag<paren_expressionID> >  paren_expression;	


		rule<ScannerT>  generalized_types, general_aggregation_types, general_array_type,
			general_bag_type, general_list_type,  general_set_type, enumeration_reference
			;

		rule<ScannerT> IDENT, ENTITY_NAME, STRING , entity_constructor, primary, syntax;

		// new perl rules
		rule<ScannerT, parser_context<>, parser_tag<abstract_supertype_declarationID> >  abstract_supertype_declaration;	
		rule<ScannerT, parser_context<>, parser_tag<subtype_constraintID> >  subtype_constraint;	
		rule<ScannerT, parser_context<>, parser_tag<width_specID> >  width_spec;	
		rule<ScannerT, parser_context<>, parser_tag<bound_1ID> >  bound_1;	
		rule<ScannerT, parser_context<>, parser_tag<numeric_expressionID> >  numeric_expression;	
		rule<ScannerT, parser_context<>, parser_tag<constructed_typesID> >  constructed_types;	
		rule<ScannerT, parser_context<>, parser_tag<entity_declID> >  entity_decl;	
		rule<ScannerT, parser_context<>, parser_tag<function_declID> >  function_decl;	
		rule<ScannerT, parser_context<>, parser_tag<procedure_declID> >  procedure_decl;	
		rule<ScannerT, parser_context<>, parser_tag<domain_ruleID> >  domain_rule;	
		rule<ScannerT, parser_context<>, parser_tag<index_1ID> >  index_1;	
		rule<ScannerT, parser_context<>, parser_tag<index_2ID> >  index_2;	
		rule<ScannerT, parser_context<>, parser_tag<interval_highID> >  interval_high;	
		rule<ScannerT, parser_context<>, parser_tag<interval_lowID> >  interval_low;	
		rule<ScannerT, parser_context<>, parser_tag<named_type_or_renameID> >  named_type_or_rename;	
		rule<ScannerT, parser_context<>, parser_tag<rule_declID> >  rule_decl;	
		rule<ScannerT, parser_context<>, parser_tag<populationID> >  population;	
		rule<ScannerT, parser_context<>, parser_tag<simple_string_literalID> >  simple_string_literal;	
		rule<ScannerT, parser_context<>, parser_tag<encoded_string_literalID> >  encoded_string_literal;	
		rule<ScannerT, parser_context<>, parser_tag<supertype_constraintID> >  supertype_constraint;	
		rule<ScannerT, parser_context<>, parser_tag<supertype_ruleID> >  supertype_rule;	
		rule<ScannerT, parser_context<>, parser_tag<supertype_termID> >  supertype_term;	
		rule<ScannerT, parser_context<>, parser_tag<schema_declID> >  schema_decl;	
		rule<ScannerT, parser_context<>, parser_tag<type_label_idID> >  type_label_id;	
		rule<ScannerT, parser_context<>, parser_tag<type_label_refID> >  type_label_ref;	
		rule<ScannerT, parser_context<>, parser_tag<unique_ruleID> >  unique_rule;	

		//assertion_t expect_semicolon, expect_close_bracket;

		definition( CExpressParser const &self )
		{   

			IDENT	=  +range_p('A','Z') >> *(alnum_p|'_');
			ENTITY_NAME = chlit<>('#') >>+range_p('0','9');
			STRING		= inner_node_d[ chlit<>('\'') >> *( anychar_p - chlit<>('\'') ) >> chlit<>('\'')]; //[&write]
			add_like_op     =  ch_p('+') | ch_p('-') | str_p("OR") | str_p("XOR") ;
			binary_literal  =  ch_p('%') >> +bit ;
			bit        =  ch_p('0') | ch_p('1') ;
			character  =  digit | letter | special ;
			digit      =  digit_p ;
			digits     =  +digit ;
			integer_literal  =  int_p ;
			letter  = range_p('a','z');  
			logical_literal  =  str_p("FALSE") | str_p("TRUE") | str_p("UNKNOWN") ;
			lparen_not_star  =  ch_p('(') >> not_star ;
			multiplication_like_op  =  ch_p('*') | ch_p('/') | str_p("DIV") | str_p("MOD") | str_p("AND");
			not_lparen_star  =  not_paren_star | ch_p(')') ;
			not_paren_star  =  letter | digit |  not_paren_star_special ;
			not_paren_star_special = range_p('!', '\'') |  range_p('+', '/') |  range_p(':', '@') |
				range_p('[', '_')  |  range_p('{', '~') ;

			not_rparen  =  not_paren_star | ch_p('*') | ch_p('(') ;
			not_star  =  not_paren_star | ch_p('(') | ch_p(')') ;
			real_literal  =  digits >> '.' >> !( digits) >> !( ch_p('e') >> !( sign)  >> digits ) ;
			rel_op  =   str_p("<=") | str_p(">=") | str_p("<>") | ch_p('=') |
				str_p(":<>:") | str_p(":=:")| str_p("||")| ch_p('<') | ch_p('>')  ;
			sign  =  ch_p('+') | ch_p('-') ;
			simple_id  =  letter >> *( letter | digit | ch_p('_') ) ;
			special  =  not_paren_star_special | ch_p('*') | ch_p('(') | ch_p(')') ;
			star_not_rparen  =  ch_p('*') >> not_rparen ;
			string_literal  =  STRING ;
			simple_string_literal=  STRING ;
//			octet=		(digit | range_p('A','F')) >> (digit | range_p('A','F'));
//			encoded_character=		octet >> octet >> octet >> octet;
//			encoded_string_literal= ch_p('"') >> +encoded_character >>ch_p( '"');

			attribute_ref= attribute_id;
			constant_ref= constant_id;
			entity_ref=	entity_id;
			enumeration_ref= enumeration_id;
			function_ref= function_id;
			parameter_ref= parameter_id;
			procedure_ref= procedure_id;
			schema_ref=	schema_id;
			type_label_ref=	type_label_id;
			type_ref= type_id;
			variable_ref= variable_id;

			actual_parameter_list  =  ch_p('(') >> list_p(parameter , ',' )>> ch_p(')') ;
			aggregate_initializer  = ch_p('[') >> !list_p(element , ',') >>  ch_p(']') ;
			aggregate_source  =  expression ;
			aggregate_type  =  str_p("AGGREGATE") >> !( ch_p(':') >> type_label) >> str_p("OF") >> parameter_type ;
			aggregation_types  =  array_type | bag_type | list_type | set_type ;
			algorithm_head  =  *( declaration ) >> !( constant_decl ) >> !(local_decl ) ; // ? {declaration}
			alias_id  =  simple_id ;
			alias_ref  =  alias_id ;
			alias_stmt  =  str_p("ALIAS") >> alias_id >> str_p("FOR") >> general_ref >> *( qualifier) >> ch_p(';') >>  *( stmt ) >> str_p("END_ALIAS") >> ch_p(';') ;
			array_type  =  str_p("ARRAY") >> '[' >> bound_spec >> ']' >> str_p("OF") >> !( str_p("OPTIONAL"))>>!(str_p("UNIQUE")) >> base_type ;
			assignment_stmt  =  general_ref >> *( qualifier ) >> ch_p(':-') >> expression  >> ch_p(';') ;
			attribute_decl  =  attribute_id | referenced_attribute ;
			attribute_id  =  simple_id ;


			abstract_supertype_declaration=
				str_p("ABSTRACT") >>str_p("SUPERTYPE") >>!subtype_constraint;
			actual_parameter_list=
				ch_p('(') >> list_p(parameter , ',' ) >>ch_p(')');
			add_like_op=	ch_p('+') | ch_p('-') | str_p("OR") | str_p("XOR");
			aggregate_initializer=
				ch_p('[') >>!( list_p(element , ',' ) )>> ch_p(']');
			aggregate_source=
				simple_expression;
			aggregate_type=	str_p("AGGREGATE") >>!( ch_p(':') >>type_label )>> str_p("OF") >>parameter_type;
			aggregation_types=
				array_type | bag_type | list_type | set_type;
			algorithm_head=	*declaration>> ! constant_decl>>!local_decl;
			alias_stmt=	str_p("ALIAS") >>variable_id >>str_p("FOR")>> general_ref >>*qualifier>> ch_p(';') >>*stmt>> str_p("END_ALIAS") >>ch_p(';');
			array_type=	str_p("ARRAY") >> bound_spec >>str_p("OF") >>!( str_p("OPTIONAL") )>>! ( str_p("UNIQUE") )>> base_type;
			assignment_stmt=
				general_ref >>*qualifier >> str_p(":=")>> expression >>ch_p(';');
			attribute_decl=	attribute_id | qualified_attribute;
			attribute_id=	simple_id;

			attribute_qualifier=
				ch_p('.') >>attribute_ref;
			bag_type=	str_p("BAG") >>!bound_spec>> str_p("OF")>> base_type;
			base_type=	aggregation_types | simple_types | named_types;
			binary_type=	str_p("BINARY") >>!width_spec;
			boolean_type=	str_p("BOOLEAN");
			bound_1=	numeric_expression;
			bound_2=	numeric_expression;
			bound_spec=	ch_p('[') >> bound_1 >>ch_p(':')>> bound_2 >>ch_p(']');
			built_in_constant=
				str_p("CONST_E") | str_p("PI") | str_p("SELF") | '?';
			built_in_function=
				str_p("ABS") | str_p("ACOS") | str_p("ASIN") | str_p("ATAN") | str_p("BLENGTH") | str_p("COS") | str_p("EXISTS") | str_p("EXP") 
				| str_p("FORMAT") | str_p("HIBOUND") | str_p("HIINDEX") | str_p("LENGTH") | str_p("LOBOUND") | str_p("LOINDEX") 
				| str_p("LOG2") | str_p("LOG10") | str_p("LOG") | str_p("NVL") | str_p("ODD") | str_p("ROLESOF") | str_p("SIN") | str_p("SIZEOF") 
				| str_p("SQRT") | str_p("TAN") | str_p("TYPEOF") | str_p("USEDIN") | str_p("VALUE_IN") | str_p("VALUE_UNIQUE") | str_p("VALUE") ;
			built_in_procedure=
				str_p("INSERT") | str_p("REMOVE");

			case_action=	list_p(case_label , ',' ) >> ch_p(':') >> stmt;
			case_label=	expression;
			case_stmt=	str_p("CASE") >>selector >>str_p("OF") >>*case_action>> !( str_p("OTHERWISE") >>ch_p(':') >>stmt )>> str_p("END_CASE")>> ch_p(';');
			compound_stmt=	str_p("BEGIN") >>*stmt>> str_p("END") >>ch_p(';');
			constant_body=	constant_id >>ch_p(':')>> base_type >>str_p(":=") >>expression>> ch_p(';');
			constant_decl=	str_p("CONSTANT")>> +constant_body >>str_p("END_CONSTANT")>> ch_p(';');
			constant_factor=
				built_in_constant | constant_ref;
			constant_id=	simple_id;

			constructed_types=
				enumeration_type | select_type;
			declaration=	entity_decl | function_decl | procedure_decl | type_decl;

			derived_attr=	attribute_decl >> ch_p(':') >> base_type >>str_p(":=")>> expression>> ch_p(';');
			derive_clause=	str_p("DERIVE") >>*derived_attr;
			domain_rule=	!( label >>ch_p(':') )>> logical_expression;
			element=	expression >> !( ch_p(':') >> repetition );
			entity_body=	*explicit_attr>>!derive_clause >> ! inverse_clause>> ! unique_clause >> ! where_clause;
			entity_constructor=		entity_ref >> '(' >> !list_p( expression , ',' ) >>  ch_p(')');
			entity_decl=	entity_head >>entity_body >>str_p("END_ENTITY") >>ch_p(';');
			entity_head=	str_p("ENTITY") >>entity_id >>!subsuper>> ch_p(';');
			entity_id=	simple_id ;
			enumeration_id=	simple_id;
			enumeration_reference=	!( type_ref >>'.' )>> enumeration_id;
			enumeration_type=
				str_p("ENUMERATION") >>str_p("OF") >>ch_p('(') >>list_p(enumeration_id , ','  )  >> ch_p(')');
			escape_stmt=	str_p("ESCAPE") >> ch_p(';');
			explicit_attr=	list_p(attribute_decl , ',') >> ':' >>!( str_p("OPTIONAL") )>> base_type >>ch_p(';');
			expression=	simple_expression >>!( rel_op_extended >>simple_expression);
			factor=		simple_factor>> !( str_p("**") >> simple_factor );
			formal_parameter=
				list_p(parameter_id , ',' )>> ch_p(':') >>parameter_type;
			function_call=	( built_in_function | function_ref ) >>!actual_parameter_list;
			function_decl=	function_head >> !algorithm_head >>*stmt >>str_p("END_FUNCTION") >>			ch_p(';');
			function_head=	str_p("FUNCTION") >>function_id >>	!( '(' >> !list_p(formal_parameter , ';') >>
				ch_p(')') ) >> ch_p(':') >> parameter_type >>ch_p(';');

			function_id=	simple_id;

			generalized_types=
				aggregate_type | general_aggregation_types | generic_type;
			general_aggregation_types=
				general_array_type | general_bag_type | general_list_type | general_set_type;
			general_array_type=
				str_p("ARRAY")>> !bound_spec >>str_p("OF")>>! ( str_p("OPTIONAL") )>> !( str_p("UNIQUE") )>> parameter_type;
			general_bag_type=
				str_p("BAG") >>!bound_spec >>str_p("OF") >>parameter_type;
			general_list_type=
				str_p("LIST") >> !bound_spec >>str_p("OF") >>!( str_p("UNIQUE") )>> parameter_type;
			general_ref=	parameter_ref | variable_ref;
			general_set_type= 
				str_p("SET") >>!bound_spec>> str_p("OF") >>parameter_type;
			generic_type=	str_p("GENERIC")>>! ( ch_p(':') >>type_label );
			group_qualifier= '\\' >>entity_ref;

			if_stmt=	str_p("IF") >>logical_expression >>str_p("THEN") >>*stmt>>! ( str_p("ELSE") >>*stmt )>> str_p("END_IF") >>ch_p(';');
			increment=	numeric_expression;
			increment_control=
				variable_id >>str_p(":=")>> bound_1 >>str_p("TO") >>bound_2 >>!( str_p("BY") >>increment );
			index=		numeric_expression;
			index_1=	index;
			index_2=	index;
			index_qualifier=ch_p('[') >>index_1 >>!( ':'>> index_2 )>> ch_p(']');
			integer_type=	str_p("INTEGER");
			interface_specification=
				reference_clause | use_clause;
			interval=	ch_p('{') >>interval_low >>interval_op >>interval_item >>interval_op >>interval_high >>'}';

			interval_high=	simple_expression;
			interval_item=	simple_expression;
			interval_low=	simple_expression;
			interval_op=	str_p("<=") | ch_p('<') ;
			inverse_attr=	attribute_decl >>':' >>!( ( str_p("SET") | str_p("BAG") ) >> !bound_spec >>str_p("OF") ) >> entity_ref >> str_p("FOR") >> attribute_ref >> ch_p(';');
			inverse_clause=	str_p("INVERSE") >> +inverse_attr;
			label=		simple_id;

			list_type=	str_p("LIST") >> !bound_spec >>str_p("OF") >> !( str_p("UNIQUE") )>> base_type;
			literal_p=	binary_literal | integer_literal | logical_literal | real_literal | string_literal;

			local_decl=	str_p("LOCAL") >> +local_variable >>str_p("END_LOCAL") >>ch_p(';');

			local_variable=	list_p(variable_id , ',' )>> ch_p(':') >>parameter_type >> !( str_p(":=") >>expression )>> ch_p(';');
			logical_expression=
				expression;
			logical_literal=
				str_p("FALSE") | str_p("TRUE") | str_p("UNKNOWN");
			logical_type=	str_p("LOGICAL");
			multiplication_like_op=
				ch_p('*') | ch_p('/') | str_p("DIV") | str_p("MOD") | str_p("AND") | str_p("||");
			named_types=	entity_ref | type_ref;
			named_type_or_rename=
				named_types >> !( str_p("AS")>> ( entity_id | type_id ) );
			null_stmt=	ch_p(';');
			number_type=	str_p("NUMBER");
			numeric_expression=
				simple_expression;
			one_of=		str_p("ONEOF") >>ch_p('(') >> list_p(supertype_expression , ',' ) >>ch_p(')');
			parameter=	expression;
			parameter_id=	simple_id;

			parameter_type=	generalized_types | named_types | simple_types;
			population=	entity_ref;
			precision_spec=	numeric_expression;
			primary=	literal_p | ( qualifiable_factor >> *qualifier );
			procedure_call_stmt=
				( built_in_procedure | procedure_ref ) >> !(actual_parameter_list) >>ch_p(';');
			procedure_decl=	procedure_head >>!algorithm_head>>* stmt>> str_p("END_PROCEDURE") >>ch_p(';');
			procedure_head=	str_p("PROCEDURE") >>procedure_id >> ( ch_p('(') >>!( str_p("VAR") )>> formal_parameter 
				>>!( ch_p(';')>> ( str_p("VAR") )>>* formal_parameter )>> ch_p(')') )>> ch_p(';');

			procedure_id=	simple_id;
			qualifiable_factor=	
				attribute_ref | constant_factor | function_call | general_ref | population;
			qualified_attribute=
				str_p("SELF")>> group_qualifier >>attribute_qualifier;
			qualifier=	attribute_qualifier | group_qualifier | index_qualifier;
			query_expression=
				str_p("QUERY") >> ch_p('(') >>variable_id>> str_p("<*")>> aggregate_source >>ch_p('|')>> logical_expression>> ch_p(')');
			real_type=	str_p("REAL") >> !( ch_p('(') >>precision_spec >>ch_p(')') );
			referenced_attribute=
				attribute_ref | qualified_attribute;
			reference_clause=
				str_p("REFERENCE") >>str_p("FROM") >>schema_ref >> !('(' >> list_p(resource_or_rename, ',') >> ch_p(')') ) >> ch_p(';');
			rel_op=		str_p("<>") | str_p("<=") | str_p(">=") | ch_p('<') | ch_p('>') | ch_p('=') | str_p(":<>:") | str_p(":=:");
			rel_op_extended= rel_op | str_p("IN") | str_p("LIKE");

			rename_id=	constant_id | entity_id | function_id | procedure_id | type_id;
			repeat_control=	!increment_control >>!while_control >>!until_control;
			repeat_stmt=	str_p("REPEAT") >>repeat_control >>':' >>*stmt>> str_p("END_REPEAT") >>ch_p(';');
			repetition=	numeric_expression;
			resource_or_rename=	//# This rule is only used in reference_clause.
				resource_ref >> !( str_p("AS") >> rename_id );

			resource_ref=	constant_ref | entity_ref | function_ref | procedure_ref | type_ref;
			return_stmt=	str_p("RETURN")>> !( ch_p('(') >>expression >>ch_p(')') ) >> ch_p(';');
			rule_decl=	rule_head >> !algorithm_head >> *stmt >> where_clause >> str_p("END_RULE") >> ch_p(';');
			rule_head=	str_p("RULE")>> rule_id>> str_p("FOR")>> ch_p('(') >> list_p(entity_ref , ',' ) >> ')'>> ch_p(';');
			rule_id=	simple_id;


			schema_body=	*interface_specification>> !constant_decl >> *( declaration | rule_decl );
			schema_decl=	str_p("SCHEMA") >> schema_id >> ch_p(';') >>schema_body >>str_p("END_SCHEMA")>> ch_p(';');
			schema_id=	simple_id;
			selector=	expression;
			select_type=	str_p("SELECT") >>ch_p('(') >> list_p(named_types, ',' ) >> ch_p(')');
			set_type=	str_p("SET") >> !bound_spec >> str_p("OF") >> base_type;
			sign=		ch_p('+') | ch_p('-');
			simple_expression=
				term >> *( add_like_op >> term );
			simple_factor=	aggregate_initializer | entity_constructor | 
				enumeration_reference 
				| interval | query_expression | 
				( !unary_op >>( ch_p('(') >>expression>> ch_p(')') | primary ) );
			simple_types=	binary_type | boolean_type | integer_type | logical_type | 
				number_type | real_type | string_type;



			skip_stmt=	str_p("SKIP") >> ch_p(';');
			stmt=		alias_stmt | assignment_stmt | case_stmt | compound_stmt | escape_stmt | 
				if_stmt | null_stmt | procedure_call_stmt | repeat_stmt | return_stmt | 
				skip_stmt;
			string_literal=	simple_string_literal | encoded_string_literal;
			// #string_type=	str_p("STRING") >> width_spec(?);
			//#Hm. What do they mean in the iso document? My version is here:
			string_type=	( str_p("STRING") | simple_id 		)  >>!width_spec;
			subsuper=	!supertype_constraint  >> !subtype_declaration;
			subtype_constraint=
				str_p("OF")  >> ch_p('(')  >>supertype_expression >> ch_p(')');
			subtype_declaration=
				str_p("SUBTYPE") >> str_p("OF") >> '(' >> list_p(entity_ref , ',' ) >>ch_p(')');
			supertype_constraint=
				abstract_supertype_declaration | supertype_rule;
			supertype_expression=
				supertype_factor >> *( str_p("ANDOR") >> supertype_factor );
			supertype_factor=
				supertype_term >> *( str_p("AND") >> supertype_term );

			supertype_rule=	str_p("SUPERTYPE") >> subtype_constraint;
			supertype_term=	entity_ref | one_of | '(' >> supertype_expression >> ')';
			syntax=		+schema_decl ;
			term=		factor >> *( multiplication_like_op >> factor );
			type_decl=	str_p("TYPE") >> type_id >> '=' >> underlying_type >> ch_p(';') >> !(where_clause) >> str_p("END_TYPE") >>ch_p(';');
			type_id=	simple_id;

			type_label=	type_label_id | type_label_ref;
			type_label_id=	simple_id;

			unary_op=	ch_p('+') | ch_p('-') | str_p("NOT");
			underlying_type=	constructed_types | aggregation_types | simple_types | type_ref;

			unique_clause=	str_p("UNIQUE")>> +( unique_rule >> ch_p(';') );
			unique_rule=	!( label >> ':' ) >> !list_p(referenced_attribute , ',' );
			until_control=	str_p("UNTIL")>> logical_expression;
			use_clause=	str_p("USE") >>str_p("FROM") >>schema_ref >> !( ch_p('(') >> list_p(named_type_or_rename, ',') >> ')' ) >> ch_p(';');
			variable_id=	simple_id;

			where_clause=	str_p("WHERE") >> list_p(domain_rule ,';' );
			while_control=	str_p("WHILE") >>logical_expression;
			width=	numeric_expression;
			width_spec=	ch_p('(') >> width>> ch_p(')') >> !( str_p("FIXED") );

			BOOST_SPIRIT_DEBUG_RULE(abstract_supertype_declaration); 
			BOOST_SPIRIT_DEBUG_RULE(subtype_constraint); 
			BOOST_SPIRIT_DEBUG_RULE(width_spec); 
			BOOST_SPIRIT_DEBUG_RULE(bound_1); 
			BOOST_SPIRIT_DEBUG_RULE(numeric_expression); 
			BOOST_SPIRIT_DEBUG_RULE(constructed_types); 
			BOOST_SPIRIT_DEBUG_RULE(entity_decl); 
			BOOST_SPIRIT_DEBUG_RULE(function_decl); 
			BOOST_SPIRIT_DEBUG_RULE(procedure_decl); 
			BOOST_SPIRIT_DEBUG_RULE(domain_rule); 
			BOOST_SPIRIT_DEBUG_RULE(index_1); 
			BOOST_SPIRIT_DEBUG_RULE(index_2); 
			BOOST_SPIRIT_DEBUG_RULE(interval_high); 
			BOOST_SPIRIT_DEBUG_RULE(interval_low); 
			BOOST_SPIRIT_DEBUG_RULE(named_type_or_rename); 
			BOOST_SPIRIT_DEBUG_RULE(rule_decl); 
			BOOST_SPIRIT_DEBUG_RULE(population); 
			BOOST_SPIRIT_DEBUG_RULE(simple_string_literal); 
			BOOST_SPIRIT_DEBUG_RULE(encoded_string_literal); 
			BOOST_SPIRIT_DEBUG_RULE(supertype_constraint); 
			BOOST_SPIRIT_DEBUG_RULE(supertype_rule); 
			BOOST_SPIRIT_DEBUG_RULE(supertype_term); 
			BOOST_SPIRIT_DEBUG_RULE(syntax); 
			BOOST_SPIRIT_DEBUG_RULE(schema_decl); 
			BOOST_SPIRIT_DEBUG_RULE(type_label_id); 
			BOOST_SPIRIT_DEBUG_RULE(type_label_ref); 
			BOOST_SPIRIT_DEBUG_RULE(unique_rule); 


			BOOST_SPIRIT_DEBUG_RULE(entity_constructor); 
			BOOST_SPIRIT_DEBUG_RULE(primary); 
			BOOST_SPIRIT_DEBUG_RULE(generalized_types); 
			BOOST_SPIRIT_DEBUG_RULE(general_aggregation_types); 
			BOOST_SPIRIT_DEBUG_RULE(general_array_type); 
			BOOST_SPIRIT_DEBUG_RULE(general_bag_type); 
			BOOST_SPIRIT_DEBUG_RULE(general_list_type); 
			BOOST_SPIRIT_DEBUG_RULE(general_ref); 
			BOOST_SPIRIT_DEBUG_RULE(general_set_type); 

			BOOST_SPIRIT_DEBUG_RULE(paren_expression); 
			BOOST_SPIRIT_DEBUG_RULE(add_like_op); 
			BOOST_SPIRIT_DEBUG_RULE(binary_literal); 
			BOOST_SPIRIT_DEBUG_RULE(bit); 
			BOOST_SPIRIT_DEBUG_RULE(character); 
			BOOST_SPIRIT_DEBUG_RULE(digit); 
			BOOST_SPIRIT_DEBUG_RULE(digits); 
			BOOST_SPIRIT_DEBUG_RULE(integer_literal); 
			BOOST_SPIRIT_DEBUG_RULE(letter); 
			BOOST_SPIRIT_DEBUG_RULE(logical_literal); 
			BOOST_SPIRIT_DEBUG_RULE(lparen_not_star); 
			BOOST_SPIRIT_DEBUG_RULE(multiplication_like_op); 
			BOOST_SPIRIT_DEBUG_RULE(not_lparen_star); 
			BOOST_SPIRIT_DEBUG_RULE(not_paren_star); 
			BOOST_SPIRIT_DEBUG_RULE(not_paren_star_special); 
			BOOST_SPIRIT_DEBUG_RULE(not_rparen); 
			BOOST_SPIRIT_DEBUG_RULE(not_star); 
			BOOST_SPIRIT_DEBUG_RULE(real_literal); 
			BOOST_SPIRIT_DEBUG_RULE(rel_op); 
			BOOST_SPIRIT_DEBUG_RULE(sign); 
			BOOST_SPIRIT_DEBUG_RULE(simple_id); 
			BOOST_SPIRIT_DEBUG_RULE(simple_types); 
			BOOST_SPIRIT_DEBUG_RULE(special); 
			BOOST_SPIRIT_DEBUG_RULE(star_not_rparen); 
			BOOST_SPIRIT_DEBUG_RULE(string_literal); 
			BOOST_SPIRIT_DEBUG_RULE(actual_parameter_list); 
			BOOST_SPIRIT_DEBUG_RULE(aggregate_initializer); 
			BOOST_SPIRIT_DEBUG_RULE(aggregate_source); 
			BOOST_SPIRIT_DEBUG_RULE(aggregate_type); 
			BOOST_SPIRIT_DEBUG_RULE(aggregation_types); 
			BOOST_SPIRIT_DEBUG_RULE(algorithm_head); 
			BOOST_SPIRIT_DEBUG_RULE(alias_id); 
			BOOST_SPIRIT_DEBUG_RULE(alias_ref); 
			BOOST_SPIRIT_DEBUG_RULE(alias_stmt); 
			BOOST_SPIRIT_DEBUG_RULE(array_type); 
			BOOST_SPIRIT_DEBUG_RULE(assignment_stmt); 
			BOOST_SPIRIT_DEBUG_RULE(attribute_decl); 
			BOOST_SPIRIT_DEBUG_RULE(attribute_id); 
			BOOST_SPIRIT_DEBUG_RULE(attribute_qualifier); 
			BOOST_SPIRIT_DEBUG_RULE(attribute_ref); 
			BOOST_SPIRIT_DEBUG_RULE(bag_type); 
			BOOST_SPIRIT_DEBUG_RULE(base_type); 
			BOOST_SPIRIT_DEBUG_RULE(binary_type); 
			BOOST_SPIRIT_DEBUG_RULE(boolean_type); 
			BOOST_SPIRIT_DEBUG_RULE(bound_l); 
			BOOST_SPIRIT_DEBUG_RULE(bound_2); 
			BOOST_SPIRIT_DEBUG_RULE(bound_spec); 
			BOOST_SPIRIT_DEBUG_RULE(built_in_constant); 
			BOOST_SPIRIT_DEBUG_RULE(built_in_function); 
			BOOST_SPIRIT_DEBUG_RULE(built_in_procedure); 
			BOOST_SPIRIT_DEBUG_RULE(case_action); 
			BOOST_SPIRIT_DEBUG_RULE(case_label); 
			BOOST_SPIRIT_DEBUG_RULE(case_stmt); 
			BOOST_SPIRIT_DEBUG_RULE(compound_stmt); 
			BOOST_SPIRIT_DEBUG_RULE(conformant_aggregate); 
			BOOST_SPIRIT_DEBUG_RULE(conformant_type); 
			BOOST_SPIRIT_DEBUG_RULE(constant_decl); 
			BOOST_SPIRIT_DEBUG_RULE(constant_body); 
			BOOST_SPIRIT_DEBUG_RULE(constant_factor); 
			BOOST_SPIRIT_DEBUG_RULE(constant_id); 
			BOOST_SPIRIT_DEBUG_RULE(constant_ref); 
			BOOST_SPIRIT_DEBUG_RULE(declaration); 
			BOOST_SPIRIT_DEBUG_RULE(derived_attr); 
			BOOST_SPIRIT_DEBUG_RULE(derive_clause); 
			BOOST_SPIRIT_DEBUG_RULE(element); 
			BOOST_SPIRIT_DEBUG_RULE(embedded_remark); 
			BOOST_SPIRIT_DEBUG_RULE(entity_block); 
			BOOST_SPIRIT_DEBUG_RULE(entity_body); 
			BOOST_SPIRIT_DEBUG_RULE(entity_head); 
			BOOST_SPIRIT_DEBUG_RULE(entity_id); 
			BOOST_SPIRIT_DEBUG_RULE(entity_init); 
			BOOST_SPIRIT_DEBUG_RULE(entity_or_rename); 
			BOOST_SPIRIT_DEBUG_RULE(entity_ref); 
			BOOST_SPIRIT_DEBUG_RULE(enumeration_id); 
			BOOST_SPIRIT_DEBUG_RULE(enumeration_ref); 
			BOOST_SPIRIT_DEBUG_RULE(enumeration_type); 
			BOOST_SPIRIT_DEBUG_RULE(escape_stmt); 
			BOOST_SPIRIT_DEBUG_RULE(explicit_attr); 
			BOOST_SPIRIT_DEBUG_RULE(expression); 
			BOOST_SPIRIT_DEBUG_RULE(factor); 
			BOOST_SPIRIT_DEBUG_RULE(formal_parameter); 
			BOOST_SPIRIT_DEBUG_RULE(function_block); 
			BOOST_SPIRIT_DEBUG_RULE(function_call); 
			BOOST_SPIRIT_DEBUG_RULE(function_head); 
			BOOST_SPIRIT_DEBUG_RULE(function_id); 
			BOOST_SPIRIT_DEBUG_RULE(function_ref); 
			BOOST_SPIRIT_DEBUG_RULE(general_ref); 
			BOOST_SPIRIT_DEBUG_RULE(generic_type); 
			BOOST_SPIRIT_DEBUG_RULE(group_qualifier); 
			BOOST_SPIRIT_DEBUG_RULE(if_stmt); 
			BOOST_SPIRIT_DEBUG_RULE(increment); 
			BOOST_SPIRIT_DEBUG_RULE(increment_control); 
			BOOST_SPIRIT_DEBUG_RULE(index); 
			BOOST_SPIRIT_DEBUG_RULE(index_qualifier); 
			BOOST_SPIRIT_DEBUG_RULE(initializer); 
			BOOST_SPIRIT_DEBUG_RULE(integer_type); 
			BOOST_SPIRIT_DEBUG_RULE(interface_specification); 
			BOOST_SPIRIT_DEBUG_RULE(interval); 
			BOOST_SPIRIT_DEBUG_RULE(interval_item); 
			BOOST_SPIRIT_DEBUG_RULE(interval_op); 
			BOOST_SPIRIT_DEBUG_RULE(inverse_attr); 
			BOOST_SPIRIT_DEBUG_RULE(inverse_clause); 
			BOOST_SPIRIT_DEBUG_RULE(label); 
			BOOST_SPIRIT_DEBUG_RULE(labelled_attrib_list); 
			BOOST_SPIRIT_DEBUG_RULE(labelled_expression); 
			BOOST_SPIRIT_DEBUG_RULE(list_type);   
			BOOST_SPIRIT_DEBUG_RULE(literal_p); 
			BOOST_SPIRIT_DEBUG_RULE(local_decl); 
			BOOST_SPIRIT_DEBUG_RULE(local_variable); 
			BOOST_SPIRIT_DEBUG_RULE(logical_expression); 
			BOOST_SPIRIT_DEBUG_RULE(logical_type); 
			BOOST_SPIRIT_DEBUG_RULE(named_types); 
			BOOST_SPIRIT_DEBUG_RULE(null_stmt); 
			BOOST_SPIRIT_DEBUG_RULE(number_type); 
			BOOST_SPIRIT_DEBUG_RULE(one_of); 
			BOOST_SPIRIT_DEBUG_RULE(parameter); 
			BOOST_SPIRIT_DEBUG_RULE(parameter_id); 
			BOOST_SPIRIT_DEBUG_RULE(parameter_ref); 
			BOOST_SPIRIT_DEBUG_RULE(parameter_type); 
			BOOST_SPIRIT_DEBUG_RULE(precision_spec); 
			BOOST_SPIRIT_DEBUG_RULE(procedure_block); 
			BOOST_SPIRIT_DEBUG_RULE(procedure_call_stmt); 
			BOOST_SPIRIT_DEBUG_RULE(procedure_head); 
			BOOST_SPIRIT_DEBUG_RULE(procedure_id); 
			BOOST_SPIRIT_DEBUG_RULE(procedure_ref); 
			BOOST_SPIRIT_DEBUG_RULE(qualifier); 
			BOOST_SPIRIT_DEBUG_RULE(qualifiable_factor); 
			BOOST_SPIRIT_DEBUG_RULE(qualified_attribute); 
			BOOST_SPIRIT_DEBUG_RULE(query_expression); 
			BOOST_SPIRIT_DEBUG_RULE(real_type); 
			BOOST_SPIRIT_DEBUG_RULE(reference_clause); 
			BOOST_SPIRIT_DEBUG_RULE(referenced_attribute); 
			BOOST_SPIRIT_DEBUG_RULE(rel_op_extended); 
			BOOST_SPIRIT_DEBUG_RULE(remark); 
			BOOST_SPIRIT_DEBUG_RULE(rename_id); 
			BOOST_SPIRIT_DEBUG_RULE(repeat_control); 
			BOOST_SPIRIT_DEBUG_RULE(repeat_stmt); 
			BOOST_SPIRIT_DEBUG_RULE(repetition); 
			BOOST_SPIRIT_DEBUG_RULE(resource_or_rename); 
			BOOST_SPIRIT_DEBUG_RULE(resource_ref); 
			BOOST_SPIRIT_DEBUG_RULE(return_stmt); 
			BOOST_SPIRIT_DEBUG_RULE(rule_block); 
			BOOST_SPIRIT_DEBUG_RULE(rule_head); 
			BOOST_SPIRIT_DEBUG_RULE(rule_id); 
			BOOST_SPIRIT_DEBUG_RULE(schema_block); 
			BOOST_SPIRIT_DEBUG_RULE(schema_body); 
			BOOST_SPIRIT_DEBUG_RULE(schema_id); 
			BOOST_SPIRIT_DEBUG_RULE(schema_ref); 
			BOOST_SPIRIT_DEBUG_RULE(select_type); 
			BOOST_SPIRIT_DEBUG_RULE(selector); 
			BOOST_SPIRIT_DEBUG_RULE(set_type); 
			BOOST_SPIRIT_DEBUG_RULE(simple_expression); 
			BOOST_SPIRIT_DEBUG_RULE(simple_factor); 
			BOOST_SPIRIT_DEBUG_RULE(simple_types); 
			BOOST_SPIRIT_DEBUG_RULE(skip_stmt); 
			BOOST_SPIRIT_DEBUG_RULE(stmt); 
			BOOST_SPIRIT_DEBUG_RULE(string_type); 
			BOOST_SPIRIT_DEBUG_RULE(subcomponent_qualifier); 
			BOOST_SPIRIT_DEBUG_RULE(subsuper); 
			BOOST_SPIRIT_DEBUG_RULE(subsuper_init); 
			BOOST_SPIRIT_DEBUG_RULE(subtype_declaration); 
			BOOST_SPIRIT_DEBUG_RULE(supertype_declaration); 
			BOOST_SPIRIT_DEBUG_RULE(supertype_expression); 
			BOOST_SPIRIT_DEBUG_RULE(supertype_factor); 
			BOOST_SPIRIT_DEBUG_RULE(tail_remark); 
			BOOST_SPIRIT_DEBUG_RULE(term); 
			BOOST_SPIRIT_DEBUG_RULE(type_decl); 
			BOOST_SPIRIT_DEBUG_RULE(type_id); 
			BOOST_SPIRIT_DEBUG_RULE(type_label); 
			BOOST_SPIRIT_DEBUG_RULE(type_ref); 
			BOOST_SPIRIT_DEBUG_RULE(unary_op); 
			BOOST_SPIRIT_DEBUG_RULE(underlying_type); 
			BOOST_SPIRIT_DEBUG_RULE(unique_clause); 
			BOOST_SPIRIT_DEBUG_RULE(until_control); 
			BOOST_SPIRIT_DEBUG_RULE(use_clause); 
			BOOST_SPIRIT_DEBUG_RULE(variable_id); 
			BOOST_SPIRIT_DEBUG_RULE(variable_ref); 
			BOOST_SPIRIT_DEBUG_RULE(where_clause); 
			BOOST_SPIRIT_DEBUG_RULE(while_control); 
			BOOST_SPIRIT_DEBUG_RULE(width); 




		}

	};
	void ExpressParseIt();

};

//  Here's our  old comment rule
struct xpress_skip_grammar : public grammar<xpress_skip_grammar>
{
	template <typename ScannerT>
	struct definition
	{
		definition(xpress_skip_grammar const& /*self*/)
		{
			skip_until_eol = *(('\\' >> eol_p) | (anychar_p - eol_p)),

				skip = 
				+( confix_p("--",*anychar_p,eol_p)
				| confix_p("(*",*anychar_p,"*)") 
				| space_p  
				)

				;
		}

		rule<ScannerT> skip, skip_until_eol;
		rule<ScannerT> const& start() const { return skip; }
	};
};

