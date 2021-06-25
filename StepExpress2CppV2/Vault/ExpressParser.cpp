//
//
//
#include "stdafx.h"
#include "ExpressParser.h"

#include "OutDebug.h"
#include "boost/lexical_cast.hpp"

#include "atlstr.h"
#include "Misc.h"
static	std::fstream outputfile;
//(CString(GetExeDirectory() + "output.txt"));

CExpressParser::CExpressParser(void)
{
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

}
static CString tabs("");

template<typename TreeIter>
int evalExpress(const TreeIter& i)
{
	tabs+="\t";
	int n =  i->value.id().to_long();
#if 0

	if(n==CExpressParser::add_like_opID) {
		outputfile <<(StrFormat("%s add_like_op %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}
	else if(n==CExpressParser::binary_literalID) {
		outputfile <<(StrFormat("%s binary_literal %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::bitID) {
		outputfile <<(StrFormat("%s bit %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::characterID) {
		outputfile <<(StrFormat("%s character %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}
	else if(n==CExpressParser::digitID) {
		outputfile <<(StrFormat("%s digit %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::digitsID) {
		outputfile <<(StrFormat("%s LOGICALTRUE %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::integer_literalID) {
		outputfile <<(StrFormat("%s integer_literal %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::letterID) {
		outputfile <<(StrFormat("%s letter %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::logical_literalID) {
		outputfile <<(StrFormat("%s logical_literal %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::lparen_not_starID) {
		outputfile <<(StrFormat("%s lparen_not_star %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::multiplication_like_opID) {
		outputfile <<(StrFormat("%s multiplication_like_op %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::not_lparen_starID) {
		outputfile <<(StrFormat("%s not_lparen_star %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::not_paren_starID) {
		outputfile <<(StrFormat("%s not_paren_star %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::not_paren_star_specialID) {
		outputfile <<(StrFormat("%s not_paren_star_special %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::not_rparenID) {
		outputfile <<(StrFormat("%s not_rparen %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::not_starID) {
		outputfile <<(StrFormat("%s not_star %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::real_literalID) {
		outputfile <<(StrFormat("%s real_literal %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::rel_opID) {
		outputfile <<(StrFormat("%s rel_op %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::signID) {
		outputfile <<(StrFormat("%s sign %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::simple_idID) {
		outputfile <<(StrFormat("%s simple_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::specialID) {
		outputfile <<(StrFormat("%s special %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::star_not_rparenID) {
		outputfile <<(StrFormat("%s star_not_rparen %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::string_literalID) {
		outputfile <<(StrFormat("%s string_literal %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::actual_parameter_listID) {
		outputfile <<(StrFormat("%s actual_parameter_list %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::aggregate_initializerID) {
		outputfile <<(StrFormat("%s aggregate_initializer %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::aggregate_sourceID) {
		outputfile <<(StrFormat("%s aggregate_source %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::aggregate_typeID) {
		outputfile <<(StrFormat("%s aggregate_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::aggregation_typesID) {
		outputfile <<(StrFormat("%s aggregation_types %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::algorithm_headID) {
		outputfile <<(StrFormat("%s algorithm_head %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::alias_idID) {
		outputfile <<(StrFormat("%s alias_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::alias_refID) {
		outputfile <<(StrFormat("%s alias_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::alias_stmtID) {
		outputfile <<(StrFormat("%s alias_stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::array_typeID) {
		outputfile <<(StrFormat("%s array_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::assignment_stmtID) {
		outputfile <<(StrFormat("%s assignment_stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::attribute_declID) {
		outputfile <<(StrFormat("%s attribute_decl %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::attribute_idID) {
		outputfile <<(StrFormat("%s attribute_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::attribute_qualifierID) {
		outputfile <<(StrFormat("%s attribute_qualifier %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::attribute_refID) {
		outputfile <<(StrFormat("%s attribute_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::bag_typeID) {
		outputfile <<(StrFormat("%s bag_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::base_typeID) {
		outputfile <<(StrFormat("%s base_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::binary_typeID) {
		outputfile <<(StrFormat("%s binary_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::boolean_typeID) {
		outputfile <<(StrFormat("%s boolean_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::bound_lID) {
		outputfile <<(StrFormat("%s bound_l %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::bound_2ID) {
		outputfile <<(StrFormat("%s bound_2 %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::bound_specID) {
		outputfile <<(StrFormat("%s bound_spec %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::built_in_constantID) {
		outputfile <<(StrFormat("%s built_in_constant %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::built_in_functionID) {
		outputfile <<(StrFormat("%s built_in_function %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::built_in_procedureID) {
		outputfile <<(StrFormat("%s built_in_procedure %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::case_actionID) {
		outputfile <<(StrFormat("%s case_action %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::case_labelID) {
		outputfile <<(StrFormat("%s case_label %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::case_stmtID) {
		outputfile <<(StrFormat("%s case_stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::compound_stmtID) {
		outputfile <<(StrFormat("%s compound_stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::conformant_aggregateID) {
		outputfile <<(StrFormat("%s conformant_aggregate %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::conformant_typeID) {
		outputfile <<(StrFormat("%s conformant_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::constant_declID) {
		outputfile <<(StrFormat("%s constant_decl %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::constant_bodyID) {
		outputfile <<(StrFormat("%s constant_body %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::constant_factorID) {
		outputfile <<(StrFormat("%s constant_factor %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::constant_idID) {
		outputfile <<(StrFormat("%s constant_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::constant_refID) {
		outputfile <<(StrFormat("%s constant_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::declarationID) {
		outputfile <<(StrFormat("%s declaration %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::derived_attrID) {
		outputfile <<(StrFormat("%s derived_attr %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::derive_clauseID) {
		outputfile <<(StrFormat("%s derive_clause %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::elementID) {
		outputfile <<(StrFormat("%s element %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::embedded_remarkID) {
		outputfile <<(StrFormat("%s embedded_remark %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::entity_blockID) {
		outputfile <<(StrFormat("%s entity_block %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::entity_bodyID) {
		outputfile <<(StrFormat("%s entity_body %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::entity_headID) {
		outputfile <<(StrFormat("%s entity_head %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::entity_idID) {
		outputfile <<(StrFormat("%s entity_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::entity_initID) {
		outputfile <<(StrFormat("%s entity_init %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::entity_or_renameID) {
		outputfile <<(StrFormat("%s entity_or_rename %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::entity_refID) {
		outputfile <<(StrFormat("%s entity_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::enumeration_idID) {
		outputfile <<(StrFormat("%s enumeration_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::enumeration_refID) {
		outputfile <<(StrFormat("%s enumeration_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::enumeration_typeID) {
		outputfile <<(StrFormat("%s enumeration_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::escape_stmtID) {
		outputfile <<(StrFormat("%s escape_stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::explicit_attrID) {
		outputfile <<(StrFormat("%s explicit_attr %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::expressionID) {
		outputfile <<(StrFormat("%s expression %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::factorID) {
		outputfile <<(StrFormat("%s factor %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::formal_parameterID) {
		outputfile <<(StrFormat("%s formal_parameter %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::function_blockID) {
		outputfile <<(StrFormat("%s function_block %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::function_callID) {
		outputfile <<(StrFormat("%s function_call %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::function_headID) {
		outputfile <<(StrFormat("%s function_head %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::function_idID) {
		outputfile <<(StrFormat("%s function_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::function_refID) {
		outputfile <<(StrFormat("%s function_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::general_refID) {
		outputfile <<(StrFormat("%s general_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::generic_typeID) {
		outputfile <<(StrFormat("%s generic_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::group_qualifierID) {
		outputfile <<(StrFormat("%s group_qualifier %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::if_stmtID) {
		outputfile <<(StrFormat("%s if_stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::incrementID) {
		outputfile <<(StrFormat("%s increment %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::increment_controlID) {
		outputfile <<(StrFormat("%s increment_control %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::indexID) {
		outputfile <<(StrFormat("%s index %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::index_qualitierID) {
		outputfile <<(StrFormat("%s index_qualitier %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::initializerID) {
		outputfile <<(StrFormat("%s initializer %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::integer_typeID) {
		outputfile <<(StrFormat("%s integer_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::interface_specificationID) {
		outputfile <<(StrFormat("%s interface_specification %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::intervalID) {
		outputfile <<(StrFormat("%s interval %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::interval_itemID) {
		outputfile <<(StrFormat("%s interval_item %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::interval_opID) {
		outputfile <<(StrFormat("%s interval_op %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::inverse_attrID) {
		outputfile <<(StrFormat("%s inverse_attr %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::inverse_clauseID) {
		outputfile <<(StrFormat("%s inverse_clause %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::labelID) {
		outputfile <<(StrFormat("%s label %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::labelled_attrib_listID) {
		outputfile <<(StrFormat("%s labelled_attrib_list %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::labelled_expressionID) {
		outputfile <<(StrFormat("%s labelled_expression %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::list_typeID) {
		outputfile <<(StrFormat("%s list_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::literal_pID) {
		outputfile <<(StrFormat("%s literal_p %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::local_declID) {
		outputfile <<(StrFormat("%s local_decl %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::local_variableID) {
		outputfile <<(StrFormat("%s local_variable %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::logical_expressionID) {
		outputfile <<(StrFormat("%s logical_expression %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::logical_typeID) {
		outputfile <<(StrFormat("%s logical_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::named_typesID) {
		outputfile <<(StrFormat("%s named_types %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::null_stmtID) {
		outputfile <<(StrFormat("%s null_stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::number_typeID) {
		outputfile <<(StrFormat("%s number_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::one_ofID) {
		outputfile <<(StrFormat("%s one_of %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::parameterID) {
		outputfile <<(StrFormat("%s parameter %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::parameter_idID) {
		outputfile <<(StrFormat("%s parameter_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::parameter_refID) {
		outputfile <<(StrFormat("%s parameter_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::parameter_typeID) {
		outputfile <<(StrFormat("%s parameter_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::precision_specID) {
		outputfile <<(StrFormat("%s precision_spec %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::procedure_blockID) {
		outputfile <<(StrFormat("%s procedure_block %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::procedure_call_stmtID) {
		outputfile <<(StrFormat("%s procedure_call_stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::procedure_headID) {
		outputfile <<(StrFormat("%s procedure_head %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::procedure_idID) {
		outputfile <<(StrFormat("%s procedure_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::procedure_refID) {
		outputfile <<(StrFormat("%s procedure_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::qualifierID) {
		outputfile <<(StrFormat("%s qualifier %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::qualifiable_factorID) {
		outputfile <<(StrFormat("%s qualifiable_factor %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::qualified_attributeID) {
		outputfile <<(StrFormat("%s qualified_attribute %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::query_expressionID) {
		outputfile <<(StrFormat("%s query_expression %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::real_typeID) {
		outputfile <<(StrFormat("%s real_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::reference_clauseID) {
		outputfile <<(StrFormat("%s reference_clause %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::referenced_attributeID) {
		outputfile <<(StrFormat("%s referenced_attribute %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::rel_op_extendedID) {
		outputfile <<(StrFormat("%s rel_op_extended %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::remarkID) {
		outputfile <<(StrFormat("%s remark %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::rename_idID) {
		outputfile <<(StrFormat("%s rename_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::repeat_controlID) {
		outputfile <<(StrFormat("%s repeat_control %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::repeat_stmtID) {
		outputfile <<(StrFormat("%s repeat_stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::repetitionID) {
		outputfile <<(StrFormat("%s repetition %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::resource_or_renameID) {
		outputfile <<(StrFormat("%s resource_or_rename %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::resource_refID) {
		outputfile <<(StrFormat("%s resource_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::return_stmtID) {
		outputfile <<(StrFormat("%s return_stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::rule_blockID) {
		outputfile <<(StrFormat("%s rule_block %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::rule_headID) {
		outputfile <<(StrFormat("%s rule_head %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::rule_idID) {
		outputfile <<(StrFormat("%s rule_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::schema_blockID) {
		outputfile <<(StrFormat("%s schema_block %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::schema_bodyID) {
		outputfile <<(StrFormat("%s schema_body %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::schema_idID) {
		outputfile <<(StrFormat("%s schema_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::schema_refID) {
		outputfile <<(StrFormat("%s schema_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::select_typeID) {
		outputfile <<(StrFormat("%s select_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::selectorID) {
		outputfile <<(StrFormat("%s selector %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::set_typeID) {
		outputfile <<(StrFormat("%s set_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::simple_expressionID) {
		outputfile <<(StrFormat("%s simple_expression %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::simple_factorID) {
		outputfile <<(StrFormat("%s simple_factor %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::simple_typesID) {
		outputfile <<(StrFormat("%s simple_types %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::skip_stmtID) {
		outputfile <<(StrFormat("%s skip_stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::stmtID) {
		outputfile <<(StrFormat("%s stmt %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::string_typeID) {
		outputfile <<(StrFormat("%s string_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::subcomponent_qualifierID) {
		outputfile <<(StrFormat("%s subcomponent_qualifier %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::subsuperID) {
		outputfile <<(StrFormat("%s subsuper %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::subsuper_initID) {
		outputfile <<(StrFormat("%s subsuper_init %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::subtype_declarationID) {
		outputfile <<(StrFormat("%s subtype_declaration %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::supertype_declarationID) {
		outputfile <<(StrFormat("%s supertype_declaration %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::supertype_expressionID) {
		outputfile <<(StrFormat("%s supertype_expression %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::supertype_factorID) {
		outputfile <<(StrFormat("%s supertype_factor %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::tail_remarkID) {
		outputfile <<(StrFormat("%s tail_remark %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::type_declID) {
		outputfile <<(StrFormat("%s type_decl %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::type_idID) {
		outputfile <<(StrFormat("%s type_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::type_labelID) {
		outputfile <<(StrFormat("%s type_label %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::type_refID) {
		outputfile <<(StrFormat("%s type_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::unary_opID) {
		outputfile <<(StrFormat("%s unary_op %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::underlying_typeID) {
		outputfile <<(StrFormat("%s underlying_type %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::unique_clauseID) {
		outputfile <<(StrFormat("%s unique_clause %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::until_controlID) {
		outputfile <<(StrFormat("%s until_control %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::use_clauseID) {
		outputfile <<(StrFormat("%s use_clause %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::variable_idID) {
		outputfile <<(StrFormat("%s variable_id %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::variable_refID) {
		outputfile <<(StrFormat("%s variable_ref %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::where_clauseID) {
		outputfile <<(StrFormat("%s where_clause %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::while_controlID) {
		outputfile <<(StrFormat("%s while_control %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else if(n==CExpressParser::widthID) {
		outputfile <<(StrFormat("%s width %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalExpress(it); }
	}	
	else
	{
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) 
		{  evalExpress(it); }

	}
#endif
	tabs=tabs.Mid(1, tabs.GetLength()-1);

	return 0;
}

void CExpressParser::ExpressParseIt()
{
	//step_skip_parser skip;
	xpress_skip_grammar skip;
	//ebnf_skip_grammar skip;
	CString file = ReadAFile(CString(GetExeDirectory() + "express.txt"));


	
	std::string str = file;
	outputfile.open (CString(GetExeDirectory() + "output.txt"), std::fstream::out );
	tree_parse_info<const char*> info =
		pt_parse((const char *) file, *this, skip);
	//		ast_parse((const char *) file, *this, skip);
	if(info.full)
	{
		OutputDebugString("Ini File Parse Succeeded \n");
		evalExpress(info.trees.begin());

		//tree_to_xml(outputfile.fp, info.trees, str, this->rule_names);
	}
	else
	{
		OutputDebugString("Ini File Parse Failed \n");

	}

}