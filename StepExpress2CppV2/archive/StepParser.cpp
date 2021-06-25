//
//
//
#include "stdafx.h"
#include "StepParser.h"

#include "OutDebug.h"
#include "boost/lexical_cast.hpp"

#include "atlstr.h"
#include "Misc.h"
#include "ExpressUtils.h"
#include "CreateCPPClasses.h"

static	std::fstream outputfile;
//(CString(GetExeDirectory() + "output.txt"));
static SymbolTable symtable;

//static std::map<CString,IStepNC *> namedentities;
//static std::vector<IStepNC *> entities;
static std::vector<StepNodeType> _attr_type;
static CStringVector szEnums;
static CStringVector szSelections;
static CStringVector szTypes;
static std::vector<int> vLowerBounds;
static std::vector<int> vUpperBounds;static CString tabs("");
static std::vector<CString> szVarnames;
static int bOptional=0;
typedef std::vector<parser_id> TreeNodes;


struct CStepParser;
typedef string::iterator iter_t;

extern	int linenumber;
///////////////////////////////////////////////////////////////////////////
//
//  eol_parser class (contributed by Martin Wille)
//
///////////////////////////////////////////////////////////////////////////
inline void write(char const *begin, char const *end)
{
	std::string str(begin, end );
	OutputDebugString( str.c_str());
}
struct  CStepParser :
	public boost::spirit::grammar<CStepParser>
{

	CStepParser(void);
	~CStepParser(void){}
	typedef spirit::symbols<double> var_table_t;

	std::map<parser_id, std::string> rule_names;

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

		paren_expressionID


	};

	template <typename ScannerT>
	struct definition		
	{
	public:


		const boost::spirit::rule<ScannerT> &start() const { return schema_block; }

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

		rule<ScannerT, parser_context<>, parser_tag<subtype_listID> >  subtype_list;	

	
		rule<ScannerT>  generalized_types, general_aggregation_types, general_array_type,
general_bag_type, general_list_type,  general_set_type, ident;

		rule<ScannerT> IDENT, ENTITY_NAME, STRING , entity_constructor, primary;

		//assertion_t expect_semicolon, expect_close_bracket;

		definition( CStepParser const &self )
		{   

			IDENT	=  +range_p('A','Z') >> *(alnum_p|'_');
			ENTITY_NAME = ch_p('#') >>+range_p('0','9');
			STRING		= inner_node_d[ ch_p('\'') >> *( anychar_p - ch_p('\'') ) >> ch_p('\'')]; //[&write]
			add_like_op     =  ch_p('+') | ch_p('-') | str_p("OR") | str_p("XOR") ;
			binary_literal  =  ch_p('%') >> +bit ;
			bit        =  ch_p('0') | ch_p('1') ;
			character  =  digit | letter | special ;
			digit      =  digit_p ;
			digits     =  +digit ;
			integer_literal  =  int_p ;
			letter  =   range_p('a','z');  
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
			simple_id  =   leaf_node_d[lexeme_d[range_p('a','z') >> *( alnum_p |  ch_p('_') )]] ;
			//simple_id  =  leaf_node_d[ ident ];
			special  =  not_paren_star_special | ch_p('*') | ch_p('(') | ch_p(')') ;
			star_not_rparen  =  ch_p('*') >> not_rparen ;
			string_literal  =  STRING ;
			actual_parameter_list  =  ch_p('(') >> list_p(parameter , ',' )>> ch_p(')') ;
			aggregate_initializer  = ch_p('[') >> list_p(element , ',') >>  ch_p(']') ;
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

			attribute_qualifier  =  ch_p('.') >> attribute_ref ;
			attribute_ref  =  attribute_id ;
			bag_type  =  str_p("BAG") >> !( bound_spec ) >> str_p("OF") >> base_type ;
			base_type  =  aggregation_types | simple_types |  named_types ;
			binary_type  =  str_p("BINARY") >> !( ch_p('(') >>width >> ch_p(')') >> !( str_p("FIXED"))) ;
			boolean_type  =  str_p("BOOLEAN"); 
			bound_l  =  simple_expression ;
			bound_2  =  simple_expression ;
			bound_spec  =  ch_p('[') >> bound_l >>ch_p(':')>> bound_2  >>ch_p(']') ;
			built_in_constant  = str_p("CONST_E") | str_p("PI") | str_p("SELF") | ch_p('?');

			built_in_function  =  str_p("ABS") | str_p("ACOS") | str_p("ASIN") | str_p("ATAN") | 
				str_p("BLENGTH") | str_p("COS") | str_p("EXISTS") | str_p("EXP") |
				str_p("FORMAT") | str_p("HIBOUND") | str_p("HIINDEX") |
				str_p("LENGTH") | str_p("LOBOUND") | str_p("LOINDEX") | 
				str_p("LOG") | str_p("LOG2") | str_p("LOG10") | str_p("NVL") |
				str_p("ODD") | str_p("ROLESOF") | str_p("SIN") | str_p("SIZEOF") |
				str_p("SQRT") | str_p("TAN") | str_p("TYPEOF") | str_p("USEDIN") | str_p("VALUE");

			built_in_procedure  =  str_p("INSERT") | str_p("REMOVE"); 
			case_action  =  list_p(case_label , ',' ) >> ch_p(':') >> stmt ;
			case_label  =  expression ;
			case_stmt  =  str_p("CASE") >> selector >> str_p("OF") >> *( case_action )
				>> !( str_p("OTHERWISE") >> ch_p(':') >> stmt ) >> str_p("END_CASE") >> ch_p(';') ;
			compound_stmt  =  str_p("BEGIN") >> *( stmt ) >> str_p("END") >>  ch_p(';') ;
			conformant_aggregate  =  conformant_type  >> !( bound_spec)>> str_p("OF") >> parameter_type ;
			conformant_type  =   str_p("ARRAY") |  str_p("BAG") |  str_p("LIST")  | str_p("SET"); 
			constant_decl  =   str_p("CONSTANT") >> *( constant_body ) >>  str_p("END_CONSTANT") >> ch_p(';') ;
			constant_body  =  constant_id >> ch_p(':') >> base_type >> str_p(":=") >> expression >> ch_p(';') ;
			constant_factor  =  built_in_constant | constant_ref ;
			constant_id  =  simple_id ;
			constant_ref  =  constant_id ;
			declaration  =  entity_block[&write] | function_block[&write] | procedure_block[&write] | type_decl[&write] ;
			derived_attr  =  attribute_decl >> ch_p(':') >> base_type >> ch_p(':-') >> expression >>ch_p(';');
			//derive_clause  =  str_p("DERIVE") >>  *( derived_attr ) ;
			derive_clause  =  str_p("DERIVE") >>  *( anychar_p -  str_p("END_ENTITY") ) ;
			element  =  expression >> !( ch_p( ':') >> repetition ) ;
			embedded_remark  =  str_p("(*") >> *( not_lparen_star | lparen_not_star | 	star_not_rparen | 	embedded_remark ) >> ch_p('*)') ;
			entity_block  =  entity_head >>entity_body>> discard_node_d[str_p("END_ENTITY")] >> discard_node_d[ch_p(';')] ;
			entity_body  =  *( explicit_attr ) >> !( derive_clause )>> !( inverse_clause) >>!( unique_clause) >>!(where_clause) ;
			entity_head  =  discard_node_d[str_p("ENTITY")] >> entity_id >> !( subsuper) >> ch_p(';') ;
			entity_id  =  simple_id ;
			entity_init  =  entity_ref >>'(' >> !(list_p( expression, ',')) >> ch_p( ')') ;
			entity_or_rename  =  entity_ref >> !( str_p("AS") >> entity_id ) ;
			entity_ref  =  entity_id ;
			enumeration_id  =  leaf_node_d[lexeme_d[alpha_p >> *(alnum_p | ch_p('_')) ]]; // most people expect cap for enums
			enumeration_ref  =  !( type_ref >> '.' ) >>  enumeration_id ;
			enumeration_type  =  str_p("ENUMERATION") >> str_p("OF") >> '(' >> list_p(enumeration_id, ',') >> ch_p(')');
			escape_stmt  =  str_p("ESCAPE") >> ch_p(';') ;
			explicit_attr  = attribute_decl >> *(discard_node_d[ch_p( ',')] >>attribute_decl ) >> discard_node_d[ch_p(':')] 
							>> !( str_p("OPTIONAL")) >> base_type >> discard_node_d[ch_p( ';')] ;
			expression  =  simple_expression >> !( rel_op_extended >> simple_expression ) ;
			factor  =  simple_factor >> !( str_p("**") >>  simple_factor ) ;
			formal_parameter  =  list_p(parameter_id ,  ','  ) >>  ch_p(':') >> parameter_type ;
#if 1
			function_block  =  str_p("FUNCTION") >>  function_id >> *(anychar_p - str_p("END_FUNCTION")) >> str_p("END_FUNCTION") >> ch_p( ';') ;

#else
			function_block  =  function_head >> !(algorithm_head) >> *( stmt ) >> str_p("END_FUNCTION") >> ch_p( ';') ;
			function_call  =  ( built_in_function | function_ref ) >> !( actual_parameter_list ) ;
			function_head  =  str_p("FUNCTION") >>  function_id >> !( ch_p( '(') >> 
				list_p(formal_parameter , ';' ) >> ch_p(')')   ) >> ch_p(':')  >> parameter_type >> ch_p(';') ;
#endif
			function_id  =  simple_id ;
			function_ref  =  function_id ;

			generalized_types=	aggregate_type | general_aggregation_types | generic_type;
			general_aggregation_types=	general_array_type | general_bag_type | general_list_type | general_set_type;
			general_array_type=	str_p("ARRAY") >> !( bound_spec) >> str_p("OF")>> ! ( str_p("OPTIONAL")) >> ! ( str_p("UNIQUE")) >> parameter_type;
			general_bag_type=str_p("BAG") >> !(bound_spec) >>  str_p("OF")>> parameter_type;
			general_list_type=	str_p("LIST")>>!( bound_spec) >> str_p("OF")>> ! ( str_p("UNIQUE")) >> parameter_type;
			general_ref=parameter_ref | variable_ref;
			general_set_type= 	str_p("SET") >>!( bound_spec) >>str_p("OF")>> parameter_type;

			//general_ref  =  alias_ref | parameter_ref | variable_ref ;
			generic_type  =  str_p("GENERIC") >> !( ch_p(':') >> type_label) ;
			group_qualifier  =  ch_p('\\') >> entity_ref ;
			if_stmt  =  str_p("IF") >> expression >> str_p("THEN") >> +stmt >> !(str_p("ELSE") >> * stmt ) >> str_p("END_IF") >> ch_p(';') ;
			increment  =  simple_expression ;
			increment_control  =  variable_id >> str_p(":=") >> bound_l >> str_p("to") >> bound_2 >> !( str_p("by") >>  increment ) ;
			index  =  simple_expression ;
			index_qualifier  =  ch_p('(') >> index >> ch_p(']') ;
			initializer  =  aggregate_initializer |  subsuper_init ;
			integer_type  =  str_p("INTEGER") ;
			interface_specification  =  reference_clause | use_clause ;
			interval  =  ch_p('{') >> bound_l  >>interval_op >> interval_item >> interval_op >> bound_2 >> ch_p('}') ;
			interval_item  =  simple_expression ;
			interval_op  = str_p("<=") | ch_p('<')  ;
			inverse_attr  =  attribute_id >> ch_p(':') >> !( ( str_p("SET") | str_p("BAG") ) >> !( bound_spec ) >> str_p("OF")) >> entity_ref >> str_p("FOR") >> attribute_ref >> ch_p(';') ;
			//inverse_clause= str_p("INVERSE") >> *( inverse_attr ) ;
			inverse_clause  =  str_p("INVERSE") >>  *( anychar_p -  str_p("END_ENTITY") ) ;

			label = range_p('A', 'Z') >> *( range_p('A', 'Z') | digit | ch_p('_') ) ; //simple_id ;

			labelled_attrib_list = !( label >> ch_p(':') ) >> list_p( referenced_attribute , ',' ) ;
			labelled_expression = !( label >> ch_p(':') ) >> expression ;
			list_type = str_p("LIST") >> !(bound_spec ) >> str_p("OF") >> !(str_p("UNIQUE")) >> base_type ;
			literal_p = binary_literal | integer_literal | logical_literal | real_literal | string_literal ;
			local_decl = str_p("LOCAL") >> +( local_variable ) >> str_p("END_LOCAL") >> ch_p( ';') ;
			local_variable = list_p(variable_id , ',' ) >> ch_p(':') >> parameter_type  >> !(str_p(":=" ) >> expression) >>  ch_p(';');
			logical_expression =expression; 
			logical_type =str_p("LOGICAL") ;
			named_types =entity_ref | type_ref ;
			null_stmt =str_p(";") ;
			number_type =str_p("NUMBER") ;
			parameter =expression ;
			parameter_id =simple_id ;
			parameter_ref =parameter_id ;
			parameter_type =generalized_types | named_types | simple_types ;
			//parameter_type =aggregate_type | conformant_aggregate | generic_type | named_types | simple_types ;
			precision_spec =simple_expression ;
#if 1
			procedure_block =str_p("PROCEDURE") >>  function_id >> *(anychar_p - str_p("END_PROCEDURE")) >> str_p("END_PROCEDURE") >> ch_p( ';') ;
#else
			procedure_block =procedure_head>> algorithm_head >> *( stmt ) >> str_p("END_PROCEDURE") >> ';' ;
			procedure_call_stmt = ( built_in_procedure | procedure_ref ) >> !( actual_parameter_list ) >> ch_p(';') ;
			procedure_head = str_p("PROCEDURE") >> procedure_id >> !( ch_p( '(') >> !( list_p(str_p("VAR")  >> formal_parameter , ';') >>ch_p( ')') ) )  >> ch_p(';') ;
#endif
			procedure_id =simple_id ;
			procedure_ref =procedure_id ;
			qualifier =attribute_qualifier | group_qualifier | index_qualifier | subcomponent_qualifier ;
			qualifiable_factor =attribute_ref | constant_factor | function_call | general_ref ;
			qualified_attribute = str_p("SELF") >>  group_qualifier >> attribute_qualifier ;
			query_expression = str_p("QUERY") >> ch_p('(') >> variable_id >> str_p("<*") >> aggregate_source >> ch_p('|') >> logical_expression >> ch_p(')') ;
			real_type = str_p("REAL") >> !( ch_p( '(') >> precision_spec >> ch_p( ')')) ;
			reference_clause = str_p("REFERENCE") >> str_p("FROM") >> schema_ref >> !( ch_p('(') >> 
				resource_or_rename >> *( ch_p( ',') >> resource_or_rename ) >> ch_p( ')') )  >> ch_p(';') ;
			referenced_attribute = attribute_ref | qualified_attribute ;
			rel_op_extended = rel_op | str_p("IN") | str_p("LIKE"); 
			remark = embedded_remark | tail_remark ;
			rename_id =entity_id | function_id | procedure_id | type_id ;
			repeat_control = !( increment_control ) >> !( while_control ) >> !( until_control ) ;
			repeat_stmt = str_p("REPEAT") >>  repeat_control  >> ch_p(';') >> *stmt>> str_p("END_REPEAT") >> ch_p(';') ;
			repetition = simple_expression ;
			resource_or_rename = resource_ref >> !( str_p("AS") >> rename_id ) ;
			resource_ref = constant_ref | entity_ref | function_ref | procedure_ref | type_ref ;
			return_stmt = str_p("RETURN") >> !( ch_p('(') >> expression >> ch_p(')') ) >> ch_p(';') ;
#if 1
			rule_block = str_p("RULE") >>  rule_id >> *(anychar_p-str_p("END_RULE")) >> str_p("END_RULE") >> ch_p( ';') ;

#else
			rule_block = rule_head >> algorithm_head >> *stmt >>  where_clause >> str_p("END_RULE")  >> ch_p(';') ;
			rule_head = str_p("RULE") >> rule_id >> str_p("FOR") >> ch_p( '(') >> entity_ref >> *(ch_p( ',') >> entity_ref) >> ch_p( ');') ;
#endif
			rule_id =simple_id;
			schema_block = str_p("SCHEMA") >> schema_id >> ch_p(';') >>  schema_body >> str_p("END_SCHEMA") >> ch_p(';') >> *anychar_p ;
			schema_body = *( interface_specification ) >> !( constant_decl ) >> *( declaration | rule_block );
			schema_id =simple_id;
			schema_ref =schema_id ;
			select_type = str_p("SELECT") >> ch_p('(') >> list_p(named_types, ',' ) >> ch_p( ')') ;
			selector =expression;
			set_type = str_p("SET") >> !( bound_spec ) >> str_p("OF") >>  base_type ;
			simple_expression = term >> * ( add_like_op >> term ); 
			////////->
#define PERL
#ifdef PERL
			entity_constructor=		entity_ref >> ch_p('(') >> !list_p( expression , ','  ) >> ch_p(')');
			primary=	literal_p | ( qualifiable_factor >> *( qualifier ) );
			simple_factor=	 entity_constructor | enumeration_ref 
				| (!(unary_op) >> ( ch_p('(') >> expression >> ch_p(')') | primary ) )
				| initializer  | interval | query_expression ;
#else
			paren_expression = ch_p('(') >> expression >> ch_p(')');
			simple_factor =  literal_p |  paren_expression |  enumeration_ref  
				| initializer |  interval |  qualifiable_factor>> *( qualifier ) | query_expression  
//				| entity_constructor
 				| !(unary_op)  >> simple_factor 
//				| !(unary_op) >> ( '(' >> expression >> ')' | primary )
				;
#endif

			simple_types = binary_type | boolean_type | integer_type | logical_type | number_type | real_type | string_type ;
			skip_stmt = str_p("SKIP")  >> ch_p(';') ;
			stmt = alias_stmt | assignment_stmt | case_stmt | compound_stmt | escape_stmt 
				| if_stmt | null_stmt | procedure_call_stmt | repeat_stmt | return_stmt 
				| skip_stmt ;
			string_type = str_p("STRING") >> !( ch_p( '(' ) >> width >> ch_p(')')>> !( str_p("fixed")));  
			subcomponent_qualifier = ch_p('(') >>  index >> ch_p( ':') >> index >> ch_p(')') ;

			subsuper =	!supertype_declaration  >> ! subtype_declaration;

			one_of = str_p("ONEOF") >> ch_p('(') >> list_p(supertype_expression , ',') >> ch_p(')') ;

			subsuper_init = entity_init >> *( str_p("||") >> entity_init) ;
			subtype_declaration =str_p("SUBTYPE") >> str_p("OF") >> ch_p('(')>>  subtype_list >> ch_p( ')') ;
			subtype_list = entity_ref >> *( discard_node_d[ch_p(',')] >> entity_ref) ; // list_p(entity_ref , ',' ) ;
//			supertype_declaration = !str_p("ABSTRACT")>> str_p("SUPERTYPE") >> *(anychar_p - (str_p("SUBTYPE") | ch_p(';'))); 
			supertype_declaration = 
				 ( !str_p("ABSTRACT" ) >> str_p("SUPERTYPE") >> discard_node_d[str_p("OF")] >> discard_node_d[ch_p('(')] >> supertype_expression >> ch_p( ')') ) 
				 | (str_p("ABSTRACT")  >> str_p("SUPERTYPE")) ;
			supertype_expression =	 supertype_factor >>  *( ( str_p("ANDOR") | str_p("AND") ) >> supertype_factor ) ;
			supertype_factor =entity_ref | one_of | ( discard_node_d[ch_p('(')] >> supertype_expression >> 
				*(discard_node_d[ch_p(',')] >> supertype_expression) 
				>> discard_node_d[ch_p( ')')] );

			//tail_remark = str_p("--") >> *( ch_p('\a') \ ch_p('\s'))  >> eol_p ;
			tail_remark = str_p("--") >> *( anychar_p - eol_p)  >> eol_p ;
			term = factor  >> *( multiplication_like_op >> factor ) ;
//			type_decl =str_p("TYPE") >>  type_id >> ch_p('=') >> underlying_type >> ch_p(';') >> !( where_clause ) 				>> str_p("END_TYPE") >> ch_p(';') ;
			type_decl =discard_node_d[str_p("TYPE")] >>  type_id >> discard_node_d[ch_p('=')] >> underlying_type >> 
				discard_node_d[ch_p(';')] >> discard_node_d[*(anychar_p-str_p("END_TYPE"))]	>> discard_node_d[str_p("END_TYPE")] >> discard_node_d[ch_p(';')] ;
			type_id =simple_id ;
			type_label =simple_id ;
			type_ref =type_id ;
			unary_op = ch_p('+') | ch_p('-') | str_p("NOT"); 
			underlying_type =enumeration_type | select_type | aggregation_types | simple_types | type_ref ;
			unique_clause =str_p("UNIQUE") >> labelled_attrib_list >> ch_p( ';') >> *(labelled_attrib_list >> ';' ) ;
			until_control = str_p("UNTIL") >> expression ;
			use_clause = str_p("USE") >> str_p("FROM") >> schema_ref >>
				!( ch_p( '(') >> list_p(entity_or_rename , ',') >> ch_p( ')' )) >> ch_p(';') ;
			variable_id =simple_id ;
			variable_ref =variable_id ;

//			where_clause =str_p("WHERE") >> +(labelled_expression >> ';' ) ;
			where_clause =str_p("WHERE") >> *(anychar_p-str_p("END_ENTITY"))  ;
			while_control =str_p("WHILE") >> expression ;
			width =simple_expression ;

			BOOST_SPIRIT_DEBUG_RULE(entity_constructor); 
			BOOST_SPIRIT_DEBUG_RULE(simple_id); 
			BOOST_SPIRIT_DEBUG_RULE(subsuper); 
			BOOST_SPIRIT_DEBUG_RULE(subsuper_init); 
			BOOST_SPIRIT_DEBUG_RULE(subtype_declaration); 
			BOOST_SPIRIT_DEBUG_RULE(supertype_declaration); 
			BOOST_SPIRIT_DEBUG_RULE(supertype_expression); 
			BOOST_SPIRIT_DEBUG_RULE(supertype_factor); 
			BOOST_SPIRIT_DEBUG_RULE(entity_block); 
			BOOST_SPIRIT_DEBUG_RULE(entity_body); 
			BOOST_SPIRIT_DEBUG_RULE(entity_head); 
			BOOST_SPIRIT_DEBUG_RULE(entity_id); 
			BOOST_SPIRIT_DEBUG_RULE(entity_init); 
			BOOST_SPIRIT_DEBUG_RULE(entity_or_rename); 
			BOOST_SPIRIT_DEBUG_RULE(entity_ref); 

			BOOST_SPIRIT_DEBUG_RULE(one_of); 
#if 0
			BOOST_SPIRIT_DEBUG_RULE(primary); 
			BOOST_SPIRIT_DEBUG_RULE(generalized_types); 
			BOOST_SPIRIT_DEBUG_RULE(general_aggregation_types); 
			BOOST_SPIRIT_DEBUG_RULE(general_array_type); 
			BOOST_SPIRIT_DEBUG_RULE(general_bag_type); 
			BOOST_SPIRIT_DEBUG_RULE(general_list_type); 
			BOOST_SPIRIT_DEBUG_RULE(general_ref); 
			BOOST_SPIRIT_DEBUG_RULE(general_set_type); 

			BOOST_SPIRIT_DEBUG_RULE(paren_expression); 
	//		BOOST_SPIRIT_DEBUG_RULE(add_like_op); 
	//		BOOST_SPIRIT_DEBUG_RULE(binary_literal); 
	//		BOOST_SPIRIT_DEBUG_RULE(bit); 
	//		BOOST_SPIRIT_DEBUG_RULE(character); 
	//		BOOST_SPIRIT_DEBUG_RULE(digit); 
	//		BOOST_SPIRIT_DEBUG_RULE(digits); 
	//		BOOST_SPIRIT_DEBUG_RULE(integer_literal); 
	//		BOOST_SPIRIT_DEBUG_RULE(letter); 
	//		BOOST_SPIRIT_DEBUG_RULE(logical_literal); 
	//		BOOST_SPIRIT_DEBUG_RULE(lparen_not_star); 
	//		BOOST_SPIRIT_DEBUG_RULE(multiplication_like_op); 
	//		BOOST_SPIRIT_DEBUG_RULE(not_lparen_star); 
	//		BOOST_SPIRIT_DEBUG_RULE(not_paren_star); 
	//		BOOST_SPIRIT_DEBUG_RULE(not_paren_star_special); 
	//		BOOST_SPIRIT_DEBUG_RULE(not_rparen); 
	//		BOOST_SPIRIT_DEBUG_RULE(not_star); 
	//		BOOST_SPIRIT_DEBUG_RULE(real_literal); 
			BOOST_SPIRIT_DEBUG_RULE(rel_op); 
			BOOST_SPIRIT_DEBUG_RULE(sign); 
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
#endif

		}

	};

};

//  Here's our  old comment rule
struct express_skip_grammar : public grammar<express_skip_grammar>
{
	template <typename ScannerT>
	struct definition
	{
		definition(express_skip_grammar const& /*self*/)
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

CStepParser::CStepParser(void)
{
#if 0
	rule_names[add_like_opID] =	"add_like_op";
	rule_names[binary_literalID] =	"binary_literal";
	rule_names[bitID] =	"bit";
	rule_names[characterID] =	"character";
	rule_names[digitID] =	"digit";
	rule_names[digitsID] =	"digits";
	rule_names[integer_literalID] =	"integer_literal";
	rule_names[letterID] =	"letter";
	rule_names[logical_literalID] =	"logical_literal";
	rule_names[lparen_not_starID] =	"lparen_not_star";
	rule_names[multiplication_like_opID] =	"multiplication_like_op";
	rule_names[not_lparen_starID] =	"not_lparen_star";
	rule_names[not_paren_starID] =	"not_paren_star";
	rule_names[not_paren_star_specialID] =	"not_paren_star_special";
	rule_names[not_rparenID] =	"not_rparen";
	rule_names[not_starID] =	"not_star";
	rule_names[real_literalID] =	"real_literal";
	rule_names[rel_opID] =	"rel_op";
	rule_names[signID] =	"sign";
	rule_names[simple_idID] =	"simple_";
	rule_names[specialID] =	"special";
	rule_names[star_not_rparenID] =	"star_not_rparen";
	rule_names[string_literalID] =	"string_literal";
	rule_names[actual_parameter_listID] =	"actual_parameter_list";
	rule_names[aggregate_initializerID] =	"aggregate_initializer";
	rule_names[aggregate_sourceID] =	"aggregate_source";
	rule_names[aggregate_typeID] =	"aggregate_type";
	rule_names[aggregation_typesID] =	"aggregation_types";
	rule_names[algorithm_headID] =	"algorithm_head";
	rule_names[alias_idID] =	"alias_";
	rule_names[alias_refID] =	"alias_ref";
	rule_names[alias_stmtID] =	"alias_stmt";
	rule_names[array_typeID] =	"array_type";
	rule_names[assignment_stmtID] =	"assignment_stmt";
	rule_names[attribute_declID] =	"attribute_decl";
	rule_names[attribute_idID] =	"attribute_";
	rule_names[attribute_qualifierID] =	"attribute_qualifier";
	rule_names[attribute_refID] =	"attribute_ref";
	rule_names[bag_typeID] =	"bag_type";
	rule_names[base_typeID] =	"base_type";
	rule_names[binary_typeID] =	"binary_type";
	rule_names[boolean_typeID] =	"boolean_type";
	rule_names[bound_lID] =	"bound_l";
	rule_names[bound_2ID] =	"bound_2";
	rule_names[bound_specID] =	"bound_spec";
	rule_names[built_in_constantID] =	"built_in_constant";
	rule_names[built_in_functionID] =	"built_in_function";
	rule_names[built_in_procedureID] =	"built_in_procedure";
	rule_names[case_actionID] =	"case_action";
	rule_names[case_labelID] =	"case_label";
	rule_names[case_stmtID] =	"case_stmt";
	rule_names[compound_stmtID] =	"compound_stmt";
	rule_names[conformant_aggregateID] =	"conformant_aggregate";
	rule_names[conformant_typeID] =	"conformant_type";
	rule_names[constant_declID] =	"constant_decl";
	rule_names[constant_bodyID] =	"constant_body";
	rule_names[constant_factorID] =	"constant_factor";
	rule_names[constant_idID] =	"constant_";
	rule_names[constant_refID] =	"constant_ref";
	rule_names[declarationID] =	"declaration";
	rule_names[derived_attrID] =	"derived_attr";
	rule_names[derive_clauseID] =	"derive_clause";
	rule_names[elementID] =	"element";
	rule_names[embedded_remarkID] =	"embedded_remark";
	rule_names[entity_blockID] =	"entity_block";
	rule_names[entity_bodyID] =	"entity_body";
	rule_names[entity_headID] =	"entity_head";
	rule_names[entity_idID] =	"entity_";
	rule_names[entity_initID] =	"entity_init";
	rule_names[entity_or_renameID] =	"entity_or_rename";
	rule_names[entity_refID] =	"entity_ref";
	rule_names[enumeration_idID] =	"enumeration_";
	rule_names[enumeration_refID] =	"enumeration_ref";
	rule_names[enumeration_typeID] =	"enumeration_type";
	rule_names[escape_stmtID] =	"escape_stmt'";
	rule_names[explicit_attrID] =	"explicit_attr";
	rule_names[expressionID] =	"expression";
	rule_names[factorID] =	"factor";
	rule_names[formal_parameterID] =	"formal_parameter";
	rule_names[function_blockID] =	"function_block";
	rule_names[function_callID] =	"function_call";
	rule_names[function_headID] =	"function_head";
	rule_names[function_idID] =	"function_";
	rule_names[function_refID] =	"function_ref";
	rule_names[general_refID] =	"general_ref";
	rule_names[generic_typeID] =	"generic_type";
	rule_names[group_qualifierID] =	"group_qualifier";
	rule_names[if_stmtID] =	"if_stmt";
	rule_names[incrementID] =	"increment";
	rule_names[increment_controlID] =	"increment_control";
	rule_names[indexID] =	"index";
	rule_names[index_qualitierID] =	"index_qualitier";
	rule_names[initializerID] =	"initializer";
	rule_names[integer_typeID] =	"integer_type";
	rule_names[interface_specificationID] =	"interface_specification";
	rule_names[intervalID] =	"interval";
	rule_names[interval_itemID] =	"interval_item";
	rule_names[interval_opID] =	"interval_op";
	rule_names[inverse_attrID] =	"inverse_attr";
	rule_names[inverse_clauseID] =	"inverse_clause";
	rule_names[labelID] =	"label";
	rule_names[labelled_attrib_listID] =	"labelled_attrib_list";
	rule_names[labelled_expressionID] =	"labelled_expression";
	rule_names[list_typeID] =	"expressionlist_type";
	rule_names[literal_pID] =	"literal_p";
	rule_names[local_declID] =	"local_decl";
	rule_names[local_variableID] =	"local_variable";
	rule_names[logical_expressionID] =	"logical_expression";
	rule_names[logical_typeID] =	"logical_type";
	rule_names[named_typesID] =	"named_types";
	rule_names[null_stmtID] =	"null_stmt";
	rule_names[number_typeID] =	"number_type";
	rule_names[one_ofID] =	"one_of";
	rule_names[parameterID] =	"parameter";
	rule_names[parameter_idID] =	"parameter_";
	rule_names[parameter_refID] =	"parameter_ref";
	rule_names[parameter_typeID] =	"parameter_type";
	rule_names[precision_specID] =	"precision_spec";
	rule_names[procedure_blockID] =	"procedure_block";
	rule_names[procedure_call_stmtID] =	"procedure_call_stmt";
	rule_names[procedure_headID] =	"procedure_head";
	rule_names[procedure_idID] =	"procedure_";
	rule_names[procedure_refID] =	"procedure_ref";
	rule_names[qualifierID] =	"qualifier";
	rule_names[qualifiable_factorID] =	"qualifiable_factor";
	rule_names[qualified_attributeID] =	"qualified_attribute";
	rule_names[query_expressionID] =	"query_expression";
	rule_names[real_typeID] =	"real_type";
	rule_names[reference_clauseID] =	"reference_clause";
	rule_names[referenced_attributeID] =	"referenced_attribute";
	rule_names[rel_op_extendedID] =	"rel_op_extended";
	rule_names[remarkID] =	"remark";
	rule_names[rename_idID] =	"rename_";
	rule_names[repeat_controlID] =	"repeat_control";
	rule_names[repeat_stmtID] =	"repeat_stmt";
	rule_names[repetitionID] =	"repetition";
	rule_names[resource_or_renameID] =	"resource_or_rename";
	rule_names[resource_refID] =	"resource_ref";
	rule_names[return_stmtID] =	"return_stmt";
	rule_names[rule_blockID] =	"rule_block";
	rule_names[rule_headID] =	"rule_head";
	rule_names[rule_idID] =	"rule_";
	rule_names[schema_blockID] =	"schema_block";
	rule_names[schema_bodyID] =	"schema_body";
	rule_names[schema_idID] =	"schema_";
	rule_names[schema_refID] =	"schema_ref";
	rule_names[select_typeID] =	"select_type";
	rule_names[selectorID] =	"selector";
	rule_names[set_typeID] =	"set_type";
	rule_names[simple_expressionID] =	"simple_expression";
	rule_names[simple_factorID] =	"simple_factor";
	rule_names[simple_typesID] =	"simple_types";
	rule_names[skip_stmtID] =	"skip_stmt";
	rule_names[stmtID] =	"stmt";
	rule_names[string_typeID] =	"string_type";
	rule_names[subcomponent_qualifierID] =	"subcomponent_qualifier";
	rule_names[subsuperID] =	"subsuper";
	rule_names[subsuper_initID] =	"subsuper_init";
	rule_names[subtype_listID] =	"subtype_list";
	
	rule_names[subtype_declarationID] =	"subtype_declaration";
	rule_names[supertype_declarationID] =	"supertype_declaration";
	rule_names[supertype_expressionID] =	"supertype_expression";
	rule_names[supertype_factorID] =	"supertype_factor";
	rule_names[tail_remarkID] =	"tail_remark";
	rule_names[type_declID] =	"type_decl";
	rule_names[type_idID] =	"type_";
	rule_names[type_labelID] =	"type_label";
	rule_names[type_refID] =	"type_ref";
	rule_names[unary_opID] =	"unary_op";
	rule_names[underlying_typeID] =	"underlying_type";
	rule_names[unique_clauseID] =	"unique_clause";
	rule_names[until_controlID] =	"until_control";
	rule_names[use_clauseID] =	"use_clause";
	rule_names[variable_idID] =	"variable_";
	rule_names[variable_refID] =	"variable_ref";
	rule_names[where_clauseID] =	"where_clause";
	rule_names[while_controlID] =	"while_control";
	rule_names[widthID] =	"width";
#endif

}



//static TypeNodes types;

static std::vector<parser_id> & Nodes(std::vector<parser_id> & nodes, parser_id p1, ...)
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
static int findNode(const TreeIter &i, TreeIter& findit, int  n, std::vector<parser_id> & nodes )
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


template<typename TreeIter>
int evalExpression(const TreeIter& i)
{
	TreeIter findit;
	TreeNodes nodes;

		if(n==CStepParser::expressionID) {
			outputfile <<(StrFormat("%s expression %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		}	
		else if(n==CStepParser::simple_expressionID) {
			outputfile <<(StrFormat("%s simple_expression %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		}	
		else  if(n==CStepParser::simple_factorID) {
			outputfile <<(StrFormat("%s simple_factor %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		}	
		else if(n==CStepParser::literal_pID) {
			outputfile <<(StrFormat("%s literal_p %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		}	

		else  if(n==CStepParser::paren_expressionID) {
			outputfile <<(StrFormat("%s paren_expression %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		}
		else  if(n==CStepParser::binary_literalID) {
			outputfile <<(StrFormat("%s binary_literal %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		}
		else  if(n==CStepParser::integer_literalID) {
			outputfile <<(StrFormat("%s integer_literal %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		}
		else  if(n==CStepParser::logical_literalID) {
			outputfile <<(StrFormat("%s logical_literal %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		}
		else  if(n==CStepParser::real_literalID) {
			outputfile <<(StrFormat("%s real_literal %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		}
		else  if(n==CStepParser::string_literalID) {
			outputfile <<(StrFormat("%s real_literal %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		}
	
}
template<typename TreeIter>
int evalExpress(const TreeIter& i)
{
	TreeIter findit;
	TreeNodes nodes;
	tabs+="\t";
	int n =  i->value.id().to_long();
	{
		if(n==CStepParser::schema_idID) 
		{
			TreeIter it = i->children.begin();   // simpleid
			it = it->children.begin();           // character set
			symtable._szSchema= std::string(it->value.begin(), it->value.end()).c_str();
			symtable.szNamespace.push_back(symtable._szSchema);
			outputfile <<(StrFormat("%s schema_id %s\n", tabs, symtable.szNamespace.back() )); ;
		}	


		if(n==CStepParser::simple_idID) {
			TreeIter it = i->children.begin(); 
			outputfile <<(StrFormat("%s simple_id %s\n", tabs, std::string(it->value.begin(), it->value.end()).c_str())); ;
			goto done;
		}	
		if(n==CStepParser::entity_blockID) 
		{
			CString szEntity;
			TreeIter it;
			int j=0;
			if(findNode(i->children.begin(), findit, 0, Nodes(nodes, CStepParser::entity_headID, CStepParser::entity_idID, CStepParser::simple_idID, 0)))
			{
				it = findit->children.begin();           // characters
				szEntity = std::string(it->value.begin(), it->value.end()).c_str();
			    //namedentities[szEntity] = entity;
				symtable.CreateEntityDef(szEntity,"machining", entity_);
			}
			else
			{
				OutputDebugString("ERROR NO ENTITY NAME FOUND\n");
				_asm int 3;
				goto done;
			}
			if(findNode(i->children.begin(), findit, 0, Nodes(nodes, CStepParser::entity_headID, CStepParser::subsuperID, 0)))
			{
				// found subtypes
				evalExpress(findit);           
			}
			it = i->children.begin();
			for(it++ ;it!=i->children.end(); it++) 
			{  
				evalExpress(it);  
			}
			outputfile <<(StrFormat("%s entity_block %s\n", tabs, szEntity)) ;			
			goto done;
		}	

		if(n==CStepParser::entity_idID) 
		{
			CString szEntity;
			TreeIter it = i->children.begin();  // simpleid
			it = i->children.begin();			// character set
			if(findNode(i->children.begin(), findit, 0, Nodes(nodes, CStepParser::simple_idID, 0)))
			{
				 szEntity = std::string(findit->children.begin()->value.begin(), findit->children.begin()->value.end()).c_str();
			}
			outputfile <<(StrFormat("%s entity_id %s\n", tabs, szEntity)); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }

		}	
#if 0
		if(n==CStepParser::supertype_declarationID) 
		{
			outputfile <<(StrFormat("%s supertype_declaration %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			goto done;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
#endif
		// entity_head,subsuper,subtype_declaration
		if(n==CStepParser::subtype_listID) 
		{
			if(findNode(i->children.begin(), findit, 0, Nodes(nodes, CStepParser::entity_refID, CStepParser::entity_idID, CStepParser::simple_idID, 0)))
			{
				TreeIter it = findit->children.begin();			// character set
				CString szEntity = std::string(it->value.begin(), it->value.end()).c_str();
				szEntity=ExpMangle(szEntity);
				outputfile <<(StrFormat("%s subtype_list %s\n", tabs, std::string(it->value.begin(), it->value.end()).c_str())); ;
				IStepNodePtr entity= symtable.Entities().back(); 
				CVarDefPtr var = symtable.CreateVarDef(szEntity, StrFormat("Machining::%s", entity->_sName), special_);
				entity->vars.push_back(var);

				// Clearly this is a hack to get all the is-a supertypes of a class. Select complicates stuff.
				symtable.EntitySuperClassesof()[szEntity].push_back(entity->Name());
			}

			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}
		///////////////////////////////////////////
		///aggregate type d ecl
		if(n==CStepParser::aggregate_typeID) 
		{
			// look for bounds?
		}	
		if(n==CStepParser::bound_lID) {
			outputfile <<(StrFormat("%s bound_l %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//int n = lexical_cast<int>(string(i->value.begin(), i->value.end())) ;
			::vLowerBounds.push_back(0);
			goto done;
		}	
		if(n==CStepParser::bound_2ID) {
			outputfile <<(StrFormat("%s bound_2 %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//int n = lexical_cast<int>(string(i->value.begin(), i->value.end())) ;
			::vUpperBounds.push_back(-1);
			goto done;
		}	
		if(n==CStepParser::bound_specID) {
			outputfile <<(StrFormat("%s bound_spec %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		}	

		///////////////////////////////////////////
		///aggregate types
		if(n==CStepParser::array_typeID) {
			outputfile <<(StrFormat("%s array_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			 _attr_type.push_back(array_);
		}	
		if(n==CStepParser::bag_typeID) {
			outputfile <<(StrFormat("%s bag_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			 _attr_type.push_back(bag_);
		}			
		if(n==CStepParser::list_typeID) {
			outputfile <<(StrFormat("%s list_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			 _attr_type.push_back(list_);
		}	
		if(n==CStepParser::set_typeID) {
			outputfile <<(StrFormat("%s set_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			 _attr_type.push_back(set_);
		}	

		///////////////////////////////////////////
		// named entity types

		if(n==CStepParser::named_typesID) {
			outputfile <<(StrFormat("%s named_types %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			///////????????????
			if(findNode(i->children.begin(), findit, 0, Nodes(nodes, CStepParser::entity_refID, CStepParser::entity_idID, CStepParser::simple_idID, 0)))
			{
				_attr_type.push_back(reference_); // entity_ is wrong - need to determine actual type...
				CString szType = std::string(findit->children.begin()->value.begin(), findit->children.begin()->value.end()).c_str();
				szTypes.push_back(szType);
			}
			 goto done;
		}	

		if(n==CStepParser::entity_refID) 
		{

			CString szEntity;
			if(findNode(i->children.begin(), findit, 0, Nodes(nodes, CStepParser::entity_idID, CStepParser::simple_idID, 0)))
			{
				CString szEntity = std::string(findit->children.begin()->value.begin(), findit->children.begin()->value.end()).c_str();
				szTypes.push_back(szEntity);

			}
			outputfile <<(StrFormat("%s entity_ref %s\n", tabs, szEntity)); ;
			goto done;
		}	

		if(n==CStepParser::base_typeID) {
			outputfile <<(StrFormat("%s base_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		}	
		///////////////////////////////////////////
		// simple types
		if(n==CStepParser::binary_typeID) {
			outputfile <<(StrFormat("%s binary_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			 _attr_type.push_back(binary_);
			szTypes.push_back(_T("EBinary"));
			goto done;
		}	
		if(n==CStepParser::boolean_typeID) {
			outputfile <<(StrFormat("%s boolean_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			 _attr_type.push_back(boolean_);
			szTypes.push_back(_T("EBoolean"));
			goto done;
		}
		if(n==CStepParser::logical_typeID) {
			outputfile <<(StrFormat("%s logical_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			 _attr_type.push_back(logical_);
			szTypes.push_back(_T("ELogical"));
			goto done;
		}	
		if(n==CStepParser::number_typeID) {
			outputfile <<(StrFormat("%s number_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			 _attr_type.push_back(number_);
			szTypes.push_back(_T("ENumber"));
			goto done;
		}	
		if(n==CStepParser::real_typeID) {
			outputfile <<(StrFormat("%s real_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			 _attr_type.push_back(real_);
			szTypes.push_back(_T("EReal"));
			goto done;

		}	
		if(n==CStepParser::string_typeID) {
			outputfile <<(StrFormat("%s string_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			 _attr_type.push_back(string_);
			szTypes.push_back(_T("EString"));
			goto done;
		}	
		if(n==CStepParser::integer_typeID) {
			outputfile <<(StrFormat("%s integer_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			 _attr_type.push_back(integer_);
			szTypes.push_back(_T("EInteger"));
			goto done;
		}	
		if(n==CStepParser::attribute_declID) {
			if(findNode(i->children.begin(), findit, 0, Nodes(nodes, CStepParser::attribute_idID, CStepParser::simple_idID, 0)))
			{
				szVarnames.push_back( std::string(findit->children.begin()->value.begin(), findit->children.begin()->value.end()).c_str());
			}
			outputfile <<(StrFormat("%s attribute_decl %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			goto done;
		}	

		if(n==CStepParser::explicit_attrID) 
		{
			TreeIter it;
			CString szVartype;

			// skip OPTIONAL for now, handle differently
			CString str = std::string(i->value.begin(), i->value.end()).c_str();
			if(str == "OPTIONAL")
			{
				bOptional=1;
				goto done;
			}

			szVarnames.clear();
			_attr_type.clear(); // should be no embedded definitions
			szTypes.clear();
			vLowerBounds.clear();
			vUpperBounds.clear();
			bOptional=0;

			for(it = i->children.begin(); it!=i->children.end(); it++) 
			{  
				evalExpress(it);  
			}

			IStepNodePtr entity= symtable.Entities().back(); 
			for(int j=0; j< szVarnames.size(); j++)
			{
				CString _classname;
				CString sListClassname;
				if(szTypes.size()>0)
					_classname=ExpMangle(szTypes[0]);

				if(_attr_type.size()<1)
				{
					OutputDebugString(StrFormat("ERROR - %s no type determined\n", entity->Name()));
					_asm int 3;
					break;
				}

				//CVarDef vardef(szVarnames[j]);

				StepNodeType _type = _attr_type.back();
				StepNodeType eListType = unknown_;
				if(_attr_type.size() > 1)
				{
					sListClassname=_classname;
					eListType= _type;
					_attr_type.pop_back();
					// list, set, array or bag of _classname
					_type= _attr_type.back();
					_type= bag_; // h ack for now
					_classname=StrFormat("EListT<%sPtr>", _classname); // classname is array type
					for(int i=1; i< ::vUpperBounds.size(); i++)
					{
						_classname=StrFormat("std::vector< %s >", _classname);
						_type= list_; // h ack for now
					}

				}
				CVarDef * var = symtable.CreateVarDef(szVarnames[j], StrFormat("Machining::%s::%s",entity->_sName,szVarnames[j] ), _type);
				var->m_eListType=eListType;
				var->TypeClassName()=_classname;
				var->_nDimension=::vUpperBounds.size();
				var->_sListClassname=sListClassname;
				var->m_bOptional=bOptional;
				var->vUpperBounds=::vUpperBounds;
				//if(bOptional)
				//	var->m_bOptional=bOptional;
				entity->vars.push_back(var);
			}
			outputfile <<(StrFormat("%s explicit_attr %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			goto done;
		}	
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// TYPE

		if(n==CStepParser::select_typeID) {
			_attr_type.push_back(select_);
			outputfile <<(StrFormat("%s select_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		}	
		if(n==CStepParser::selectorID) {
			outputfile <<(StrFormat("%s selector %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			CString	szSelection= std::string(i->children.begin()->value.begin(), i->children.begin()->value.end()).c_str();
			szSelection=ExpMangle(szSelection);
			szSelections.push_back(szSelection);
			goto done;
		}	


		if(n==CStepParser::enumeration_typeID) {
			_attr_type.push_back(enumeration_);
			outputfile <<(StrFormat("%s enumeration_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		}	
		if(n==CStepParser::underlying_typeID) {
			_attr_type.push_back(underlying_type_);
				outputfile <<(StrFormat("%s underlying_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		}
		
		if(n==CStepParser::enumeration_idID) {
			outputfile <<(StrFormat("%s enumeration_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			CString	szEnumname= std::string(i->children.begin()->value.begin(), i->children.begin()->value.end()).c_str();
			szEnums.push_back(szEnumname);
			goto done;
		}	
		if(n==CStepParser::type_refID) { // type_idID) {
			CString szType;
			if(findNode(i->children.begin(), findit, 0, Nodes(nodes, CStepParser::type_idID, CStepParser::simple_idID, 0)))
			{
				szType = std::string(findit->children.begin()->value.begin(), findit->children.begin()->value.end()).c_str();
				szType=ExpMangle(szType);
				szTypes.push_back(szType);
				_attr_type.push_back(typereference_);

			}
			outputfile <<(StrFormat("%s type_id %s\n", tabs, szType)); ;
			goto done;
		}	
		if(n==CStepParser::type_declID) {
			TreeIter it;
			CString szTypename;
			if(findNode(i->children.begin(), findit, 0, Nodes(nodes, CStepParser::type_idID,  CStepParser::simple_idID, 0)))
			{
				szTypename= std::string(findit->children.begin()->value.begin(), findit->children.begin()->value.end()).c_str();
				symtable.CreateTypeNode(szTypename);
			}
			else
			{
				OutputDebugString("ERROR BAD TYPE NAME\n");
				goto done;

			}
			szEnums.clear();
			szVarnames.clear();
			szTypes.clear();
			vLowerBounds.clear();
			vUpperBounds.clear();
			_attr_type.clear(); // should be no embedded definitions
			for(it = i->children.begin(); it!=i->children.end(); it++) 
			{  
				evalExpress(it);  
			}
			IStepNodePtr type= symtable.Types().back();

			if(_attr_type.size()<1)
			{
				OutputDebugString(StrFormat("ERROR - Type %s no basetype determined\n", szTypename));
				_asm int 3;
				goto done;

			}
			type->_eType= _attr_type.back();

			// Fixme could be TypeNode to list.
			type->_nDimension = ::vUpperBounds.size();

			OutputDebugString(StrFormat("%s type_decl %s\n", tabs, szTypename));
			if(szTypes.size()>0)
				type->m_sClassname=szTypes[0];

			if(szEnums.size()>0)
			{
				type->_enums=szEnums;
			}
			if(szTypes.size()>0)
			{
				for(int i=0; i< szTypes.size();i++) szTypes[i] = ExpMangle(szTypes[i]);
				type->_szSelections=szTypes;
			}
			outputfile <<(StrFormat("%s type_decl %s\n", tabs, szTypename));

			goto done;

		}	


		
		if(n==CStepParser::reference_clauseID) 
		{
			CString szSchema;
			TreeIter it=i->children.begin(); it++; it++; // REFERENCE (0) FROM(1) name(2)
			if(findNode(it->children.begin(), findit, 0, Nodes(nodes, CStepParser::schema_idID, CStepParser::simple_idID, 0)))
			{
				szSchema = std::string(findit->children.begin()->value.begin(), findit->children.begin()->value.end()).c_str();
				symtable._schemas.push_back(szSchema);
			}

			outputfile <<(StrFormat("%s reference_clause %s\n", tabs, szSchema)); 
			goto done;

		}

		if(n==CStepParser::use_clauseID) {
			// RENAMES ARE A PROBLEM...
			outputfile <<(StrFormat("%s use_clause %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	


		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#if 0
		if(n==CStepParser::add_like_opID) {
			outputfile <<(StrFormat("%s add_like_op %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}

		if(n==CStepParser::bitID) {
			outputfile <<(StrFormat("%s bit %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::characterID) {
			outputfile <<(StrFormat("%s character %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}

		if(n==CStepParser::digitID) {
			outputfile <<(StrFormat("%s digit %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::digitsID) {
			outputfile <<(StrFormat("%s LOGICALTRUE %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::integer_literalID) {
			outputfile <<(StrFormat("%s integer_literal %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::letterID) {
			outputfile <<(StrFormat("%s letter %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::binary_literalID) {
			outputfile <<(StrFormat("%s binary_literal %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			goto done;
		}	
		if(n==CStepParser::logical_literalID) {
			outputfile <<(StrFormat("%s logical_literal %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			goto done;
		}	
		if(n==CStepParser::real_literalID) {
			outputfile <<(StrFormat("%s real_literal %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			goto done;
		}	
		if(n==CStepParser::lparen_not_starID) {
			outputfile <<(StrFormat("%s lparen_not_star %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::multiplication_like_opID) {
			outputfile <<(StrFormat("%s multiplication_like_op %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::not_lparen_starID) {
			outputfile <<(StrFormat("%s not_lparen_star %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::not_paren_starID) {
			outputfile <<(StrFormat("%s not_paren_star %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::not_paren_star_specialID) {
			outputfile <<(StrFormat("%s not_paren_star_special %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::not_rparenID) {
			outputfile <<(StrFormat("%s not_rparen %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::not_starID) {
			outputfile <<(StrFormat("%s not_star %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	

		if(n==CStepParser::rel_opID) {
			outputfile <<(StrFormat("%s rel_op %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::signID) {
			outputfile <<(StrFormat("%s sign %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	

		if(n==CStepParser::specialID) {
			outputfile <<(StrFormat("%s special %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::star_not_rparenID) {
			outputfile <<(StrFormat("%s star_not_rparen %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::string_literalID) {
			outputfile <<(StrFormat("%s string_literal %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::actual_parameter_listID) {
			outputfile <<(StrFormat("%s actual_parameter_list %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::aggregate_initializerID) {
			outputfile <<(StrFormat("%s aggregate_initializer %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::aggregate_sourceID) {
			outputfile <<(StrFormat("%s aggregate_source %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::aggregation_typesID) {
			outputfile <<(StrFormat("%s aggregation_types %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::algorithm_headID) {
			outputfile <<(StrFormat("%s algorithm_head %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::alias_idID) {
			outputfile <<(StrFormat("%s alias_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::alias_refID) {
			outputfile <<(StrFormat("%s alias_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::alias_stmtID) {
			outputfile <<(StrFormat("%s alias_stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	

		if(n==CStepParser::assignment_stmtID) {
			outputfile <<(StrFormat("%s assignment_stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	

		if(n==CStepParser::attribute_idID) {
			outputfile <<(StrFormat("%s attribute_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::attribute_qualifierID) {
			outputfile <<(StrFormat("%s attribute_qualifier %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::attribute_refID) {
			outputfile <<(StrFormat("%s attribute_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	

		if(n==CStepParser::built_in_constantID) {
			outputfile <<(StrFormat("%s built_in_constant %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::built_in_functionID) {
			outputfile <<(StrFormat("%s built_in_function %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
			goto done;
		}	
		if(n==CStepParser::built_in_procedureID) {
			outputfile <<(StrFormat("%s built_in_procedure %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::case_actionID) {
			outputfile <<(StrFormat("%s case_action %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::case_labelID) {
			outputfile <<(StrFormat("%s case_label %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::case_stmtID) {
			outputfile <<(StrFormat("%s case_stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::compound_stmtID) {
			outputfile <<(StrFormat("%s compound_stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::conformant_aggregateID) {
			outputfile <<(StrFormat("%s conformant_aggregate %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::conformant_typeID) {
			outputfile <<(StrFormat("%s conformant_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::constant_declID) {
			outputfile <<(StrFormat("%s constant_decl %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::constant_bodyID) {
			outputfile <<(StrFormat("%s constant_body %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::constant_factorID) {
			outputfile <<(StrFormat("%s constant_factor %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::constant_idID) {
			outputfile <<(StrFormat("%s constant_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::constant_refID) {
			outputfile <<(StrFormat("%s constant_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::declarationID) {
			outputfile <<(StrFormat("%s declaration %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::derived_attrID) {
			outputfile <<(StrFormat("%s derived_attr %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			goto done;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::derive_clauseID) {
			outputfile <<(StrFormat("%s derive_clause %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			goto done;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::elementID) {
			outputfile <<(StrFormat("%s element %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::embedded_remarkID) {
			outputfile <<(StrFormat("%s embedded_remark %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::entity_bodyID) {
			outputfile <<(StrFormat("%s entity_body %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::entity_headID) {
			outputfile <<(StrFormat("%s entity_head %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	

		if(n==CStepParser::entity_initID) {
			outputfile <<(StrFormat("%s entity_init %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::entity_or_renameID) {
			outputfile <<(StrFormat("%s entity_or_rename %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	

		if(n==CStepParser::enumeration_refID) {
			outputfile <<(StrFormat("%s enumeration_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	

		if(n==CStepParser::escape_stmtID) {
			outputfile <<(StrFormat("%s escape_stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	

		if(n==CStepParser::expressionID) {
			outputfile <<(StrFormat("%s expression %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::factorID) {
			outputfile <<(StrFormat("%s factor %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::formal_parameterID) {
			outputfile <<(StrFormat("%s formal_parameter %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::function_blockID) {
			outputfile <<(StrFormat("%s function_block %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
			goto done;
		}	
		if(n==CStepParser::function_callID) {
			outputfile <<(StrFormat("%s function_call %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::function_headID) {
			outputfile <<(StrFormat("%s function_head %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
			goto done;
		}	
		if(n==CStepParser::function_idID) {
			outputfile <<(StrFormat("%s function_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
			goto done;
		}	
		if(n==CStepParser::function_refID) {
			outputfile <<(StrFormat("%s function_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
			goto done;
		}	
		if(n==CStepParser::general_refID) {
			outputfile <<(StrFormat("%s general_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::generic_typeID) {
			outputfile <<(StrFormat("%s generic_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::group_qualifierID) {
			outputfile <<(StrFormat("%s group_qualifier %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::if_stmtID) {
			outputfile <<(StrFormat("%s if_stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::incrementID) {
			outputfile <<(StrFormat("%s increment %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::increment_controlID) {
			outputfile <<(StrFormat("%s increment_control %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::indexID) {
			outputfile <<(StrFormat("%s index %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::index_qualitierID) {
			outputfile <<(StrFormat("%s index_qualitier %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::initializerID) {
			outputfile <<(StrFormat("%s initializer %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	

		if(n==CStepParser::interface_specificationID) {
			outputfile <<(StrFormat("%s interface_specification %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::intervalID) {
			outputfile <<(StrFormat("%s interval %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::interval_itemID) {
			outputfile <<(StrFormat("%s interval_item %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::interval_opID) {
			outputfile <<(StrFormat("%s interval_op %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::inverse_attrID) {
			outputfile <<(StrFormat("%s inverse_attr %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
			goto done;
		}	
		if(n==CStepParser::inverse_clauseID) {
			outputfile <<(StrFormat("%s inverse_clause %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			goto done;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::labelID) {
			outputfile <<(StrFormat("%s label %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::labelled_attrib_listID) {
			outputfile <<(StrFormat("%s labelled_attrib_list %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::labelled_expressionID) {
			outputfile <<(StrFormat("%s labelled_expression %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::literal_pID) {
			outputfile <<(StrFormat("%s literal_p %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::local_declID) {
			outputfile <<(StrFormat("%s local_decl %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::local_variableID) {
			outputfile <<(StrFormat("%s local_variable %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::logical_expressionID) {
			outputfile <<(StrFormat("%s logical_expression %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	

		if(n==CStepParser::null_stmtID) {
			outputfile <<(StrFormat("%s null_stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::one_ofID) {
			outputfile <<(StrFormat("%s one_of %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::parameterID) {
			outputfile <<(StrFormat("%s parameter %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::parameter_idID) {
			outputfile <<(StrFormat("%s parameter_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::parameter_refID) {
			outputfile <<(StrFormat("%s parameter_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::parameter_typeID) {
			outputfile <<(StrFormat("%s parameter_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::precision_specID) {
			outputfile <<(StrFormat("%s precision_spec %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::procedure_blockID) {
			outputfile <<(StrFormat("%s procedure_block %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::procedure_call_stmtID) {
			outputfile <<(StrFormat("%s procedure_call_stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::procedure_headID) {
			outputfile <<(StrFormat("%s procedure_head %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::procedure_idID) {
			outputfile <<(StrFormat("%s procedure_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::procedure_refID) {
			outputfile <<(StrFormat("%s procedure_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::qualifierID) {
			outputfile <<(StrFormat("%s qualifier %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::qualifiable_factorID) {
			outputfile <<(StrFormat("%s qualifiable_factor %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::qualified_attributeID) {
			outputfile <<(StrFormat("%s qualified_attribute %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::query_expressionID) {
			outputfile <<(StrFormat("%s query_expression %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	

		if(n==CStepParser::referenced_attributeID) {
			outputfile <<(StrFormat("%s referenced_attribute %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::rel_op_extendedID) {
			outputfile <<(StrFormat("%s rel_op_extended %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::remarkID) {
			outputfile <<(StrFormat("%s remark %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::rename_idID) {
			outputfile <<(StrFormat("%s rename_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::repeat_controlID) {
			outputfile <<(StrFormat("%s repeat_control %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::repeat_stmtID) {
			outputfile <<(StrFormat("%s repeat_stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::repetitionID) {
			outputfile <<(StrFormat("%s repetition %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::resource_or_renameID) {
			outputfile <<(StrFormat("%s resource_or_rename %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::resource_refID) {
			outputfile <<(StrFormat("%s resource_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::return_stmtID) {
			outputfile <<(StrFormat("%s return_stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	

		if(n==CStepParser::rule_blockID) {
			outputfile <<(StrFormat("%s rule_block %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
			goto done;
		}	
		if(n==CStepParser::rule_headID) {
			outputfile <<(StrFormat("%s rule_head %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
			goto done;
		}	
		if(n==CStepParser::rule_idID) {
			outputfile <<(StrFormat("%s rule_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
			goto done;
		}	

		if(n==CStepParser::schema_blockID) {
			outputfile <<(StrFormat("%s schema_block %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::schema_bodyID) {
			outputfile <<(StrFormat("%s schema_body %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	

		if(n==CStepParser::schema_refID) {
			outputfile <<(StrFormat("%s schema_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::simple_expressionID) {
			outputfile <<(StrFormat("%s simple_expression %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::simple_factorID) {
			outputfile <<(StrFormat("%s simple_factor %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::simple_typesID) {
			outputfile <<(StrFormat("%s simple_types %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::skip_stmtID) {
			outputfile <<(StrFormat("%s skip_stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::stmtID) {
			outputfile <<(StrFormat("%s stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	

		if(n==CStepParser::subcomponent_qualifierID) {
			outputfile <<(StrFormat("%s subcomponent_qualifier %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::subsuperID) {
			outputfile <<(StrFormat("%s subsuper %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::subsuper_initID) {
			outputfile <<(StrFormat("%s subsuper_init %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::subtype_declarationID) {
			outputfile <<(StrFormat("%s subtype_declaration %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	

		if(n==CStepParser::supertype_expressionID) {
			outputfile <<(StrFormat("%s supertype_expression %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::supertype_factorID) {
			outputfile <<(StrFormat("%s supertype_factor %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::tail_remarkID) {
			outputfile <<(StrFormat("%s tail_remark %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	

		if(n==CStepParser::type_labelID) {
			outputfile <<(StrFormat("%s type_label %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::type_refID) {
			outputfile <<(StrFormat("%s type_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::unary_opID) {
			outputfile <<(StrFormat("%s unary_op %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	

		if(n==CStepParser::unique_clauseID) {
			outputfile <<(StrFormat("%s unique_clause %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::until_controlID) {
			outputfile <<(StrFormat("%s until_control %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::variable_idID) {
			outputfile <<(StrFormat("%s variable_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::variable_refID) {
			outputfile <<(StrFormat("%s variable_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::where_clauseID) {
			outputfile <<(StrFormat("%s where_clause %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			goto done;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::while_controlID) {
			outputfile <<(StrFormat("%s while_control %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
		if(n==CStepParser::widthID) {
			outputfile <<(StrFormat("%s width %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
		}	
#endif
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) 
		{  evalExpress(it); 
		}

	}
done:
	tabs=tabs.Mid(1, tabs.GetLength()-1);

	return 0;
}

int linenumber;


struct step_skip_parser : public parser<step_skip_parser>
{ 
	typedef step_skip_parser self_t;

	step_skip_parser() {linenumber=0;}

	template <typename ScannerT>
	typename parser_result<self_t, ScannerT>::type
		parse(ScannerT const& scan) const
	{
		typename ScannerT::iterator_t save = scan.first;
		std::size_t len = 0;
		chseq<char*> comment("(*");
		chseq<char*> str("*)");
		int incomment=0;

		for( ;!scan.at_end(); )   
		{
			if (!incomment && comment.parse(scan))
			{
				len+=2; 
				incomment=1;
				continue;

			}
			if(!incomment && (*scan == '\r' || *scan == ' ' || *scan == '\t'  || *scan == '\n'))  
			{
				if(*scan == '\n')
					++linenumber;
				++scan.first;
				++len;
				continue;
			}
			if (incomment &&  str.parse(scan))
			{
				len+=2; 
				incomment=0;
				continue; // may be space after the end of the comment
			}
			if(incomment)
			{
				if(*scan == '\n')
					++linenumber;
				++scan.first;
				++len;
				continue;
			}
			break;
		}

		if (len)
			return scan.create_match(len, nil_t(), save, scan.first);
		return scan.no_match();
	}
};
#define SCHEMAS 1
void CStepNCParser::ExpressParseIt()
{
	//step_skip_parser skip;
	express_skip_grammar skip;
//	CString file = ReadAFile(CString(GetExeDirectory() + "milling_schema.exp"));
//	static char * szSchema[3] = {  "express", "machining_schema" , "milling_schema"};
//	static char * szSchema[3] = {   "machining_schema" , "milling_schema", "part21Header"};
	static char * szSchema[SCHEMAS] = {  "part21Header"};
	CStepParser parser;

	for(int i=0; i< SCHEMAS; i++)
	{

		CString file = ReadAFile(CString(GetExeDirectory() + szSchema[i] + CString(".exp")));
		std::string str = file;

		outputfile.open (CString(GetExeDirectory() + StrFormat("%sOutput.txt", szSchema[i])), std::fstream::out );

		//symtable.Clear(); // maybe omit and make super colossal header cpp files
#ifndef DEBUGGRAMMAR
		tree_parse_info<const char*> info = pt_parse((const char *) file, parser, skip);
#else
		// use this to watch how parsing is going. Not real easy, but...
		parse_info<> info =	boost::spirit::parse((const char *) file, *this, skip);
#endif

		//tree_parse_info<const char*> info =		ast_parse((const char *) file, *this, skip);
		if(info.full)
		{
			OutputDebugString("Ini File Parse Succeeded \n");


#ifndef DEBUGGRAMMAR
			evalExpress(info.trees.begin());
			
#endif
			//tree_to_xml(outputfile, info.trees, str, this->rule_names);

 
		}
		else
		{
			OutputDebugString("Ini File Parse Failed \n");

		}
		outputfile.close();
	}
	OutputDebugString( symtable.DumpSymbols());
	CCreateCPPClasses cgen(symtable);
	cgen.CreateHeaderDeclarationFile("stepnc_schema");
	cgen.CreateClassDeclarationFile("stepnc_schema");
	cgen.CreateClassImplFile("stepnc_schema" );

}