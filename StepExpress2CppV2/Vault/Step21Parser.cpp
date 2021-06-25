//
//
//
#include "stdafx.h"
#include "Step21Parser.h"

#include "OutDebug.h"
#include "boost/lexical_cast.hpp"

#include "atlstr.h"
#include "Misc.h"
static	std::fstream outputfile;
//(CString(GetExeDirectory() + "output.txt"));

CStep21Parser::CStep21Parser(void)
{
	rule_names[GrammarID]             = "Part21";
	rule_names[LOGICALTRUEID]             = "LOGICALTRUE";
	rule_names[LOGICALFALSEID]             = "LOGICALFALSE";
	rule_names[LOGICALUNKWNID]             = "LOGICALUNKWN";
	rule_names[IDENTID]					   = "IDENT";
	rule_names[ENUMID]					 = "ENUM";
	rule_names[USER_DEFINED_KEYWORDID]             = "USER_DEFINED_KEYWORD";
	rule_names[BINARYID]             = "BINARY";
	rule_names[Entity_exportID]             = "Entity_exporD";
	rule_names[EntityReferencesID]             = "EntityReferences";
	rule_names[EmbeddedListID]             = "EmbeddedList";
	rule_names[ListID]             = "List";
	rule_names[ListEntryID]             = "ListEntry";
	rule_names[ParametersID]             = "Parameters";
	rule_names[ParameterID]             = "Parameter";
	rule_names[Subsuper_Record_List_ElementID]             = "Subsuper_Record_List_Element";
	rule_names[Simple_RecordID]             = "Simple_Record";
	rule_names[Subsuper_Record_ListID]             = "Subsuper_Record_List";
	rule_names[Subsuper_RecordID]             = "Subsuper_Record";
	rule_names[Entity_Instance_RHSID]             = "Entity_Instance_RHS";
	rule_names[EntityNameID]             = "EntityName";
	rule_names[EntityReferenceID]             = "EntityReference";
	rule_names[EntityReferenceID]             = "EntityReference";
	rule_names[HeaderEntityID]             = "HeaderEntity";
	rule_names[HeaderSectionID]             = "HeaderSection";
	rule_names[HeaderEntitiesID]             = "HeaderEntities";
	rule_names[ReqHdrEntitiesID]             = "ReqHdrEntities";
	rule_names[OptHdrEntitiesID]             = "OptHdrEntities";
	rule_names[DataSectionID]             = "DataSection";
	rule_names[DataEntityID]             = "DataEntity";
	rule_names[DataEntitiesID]             = "DataEntities";
	rule_names[KEYWORDID]             = "KEYWORD";
	rule_names[STRINGID]             = "STRING";

}
typedef std::vector<parser_id> TreeNodes;
static std::map<CString, CString> NamedEntities;
static CString tabs("");

std::vector<parser_id> & Nodes(std::vector<parser_id> & nodes, parser_id p1, ...)
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
template<typename TreeIter>
int evalP21EBNF(const TreeIter& i)
{
	tabs+="\t";
	int n =  i->value.id().to_long();
	TreeIter findit;
	TreeNodes nodes;
	switch(n)
	{

	case CStep21Parser::LOGICALTRUEID:
		outputfile <<(StrFormat("%s LOGICALTRUEID %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;
	case CStep21Parser::LOGICALFALSEID:
		outputfile <<(StrFormat("%s LOGICALFALSEID %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;
	case CStep21Parser::LOGICALUNKWNID:
		outputfile <<(StrFormat("%s LOGICALUNKWNID %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;

	case CStep21Parser::KEYWORDID:
		{
			outputfile <<(StrFormat("%s KEYWORD %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
			break;
		}
	case CStep21Parser::STRINGID:
		{
			outputfile <<(StrFormat("%s STRING %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		}
		break;
	case CStep21Parser::IDENTID:
		{
			outputfile <<(StrFormat("%s IDENTID %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		}
		break;
	case CStep21Parser::ENUMID:
		outputfile <<(StrFormat("%s ENUMID %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;
	case CStep21Parser::USER_DEFINED_KEYWORDID:
		outputfile <<(StrFormat("%s USER_DEFINED_KEYWORD %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;
	case CStep21Parser::BINARYID:
		outputfile <<(StrFormat("%s BINARYID %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;
	case CStep21Parser::Entity_exportID:
		outputfile <<(StrFormat("%s Entity_export %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;	
	case CStep21Parser::EntityReferencesID:
		outputfile <<(StrFormat("%s EntityReferencesID %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;	
	case CStep21Parser::EmbeddedListID:
		outputfile <<(StrFormat("%s EmbeddedListID %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;	
	case CStep21Parser::ListID:
		outputfile <<(StrFormat("%s List %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;	
	case CStep21Parser::ListEntryID:
		outputfile <<(StrFormat("%s ListEntry %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;	
	case CStep21Parser::ParametersID:
		outputfile <<(StrFormat("%s Parameters %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;	
	case CStep21Parser::ParameterID:
		outputfile <<(StrFormat("%s ParameterID %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;	
	case CStep21Parser::Subsuper_Record_List_ElementID:
		outputfile <<(StrFormat("%s Subsuper_Record_List_Element %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;	
	case CStep21Parser::Simple_RecordID:
		outputfile <<(StrFormat("%s Simple_Record %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;	
	case CStep21Parser::Subsuper_Record_ListID:
		outputfile <<(StrFormat("%s Subsuper_Record_List %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;	
	case CStep21Parser::Subsuper_RecordID:
		outputfile <<(StrFormat("%s Subsuper_Record %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;	
	case CStep21Parser::Entity_Instance_RHSID:
		outputfile <<(StrFormat("%s Entity_Instance_RHS %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;	

	case CStep21Parser::EntityReferenceID:
		outputfile <<(StrFormat("%s EntityReference %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;	
	case CStep21Parser::HeaderEntityID:
		outputfile <<(StrFormat("%s HeaderEntity %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;	
	case CStep21Parser::HeaderSectionID:
		outputfile <<(StrFormat("%s HeaderSection %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;	

	case CStep21Parser::HeaderEntitiesID:
		outputfile <<(StrFormat("%s HeaderEntities %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;	
	case CStep21Parser::ReqHdrEntitiesID:
		outputfile <<(StrFormat("%s ReqHdrEntities %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;	
	case CStep21Parser::OptHdrEntitiesID:
		outputfile <<(StrFormat("%s OptHdrEntities %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++){  evalP21EBNF(it); }
		break;	
	case CStep21Parser::DataSectionID:
		outputfile <<(StrFormat("%s DataSection %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;	
	case CStep21Parser::MISSINGID:
		outputfile <<(StrFormat("%s MISSING %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;	


	case CStep21Parser::DataEntitiesID:
		outputfile <<(StrFormat("%s DataEntities %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;

	case CStep21Parser::DataEntityID:
		{
			CString nameid;
			CString entityname;
			TreeIter it;

			it = i->children.begin();
			if(findNode(it, findit, 0, Nodes(nodes, CStep21Parser::EntityNameID,  CStep21Parser::ENTITY_NAMEID, CStep21Parser::ENTITY_NAMEID, 0)))
			{
				nameid=  std::string(findit->value.begin(), findit->value.end()).c_str();
			}	

			it++; 
			// could also be USER_DEFINED_KEYWORD or SCOPE
			if(findNode(it, findit, 0, Nodes(nodes, CStep21Parser::Entity_Instance_RHSID,  CStep21Parser::Simple_RecordID, 
				CStep21Parser::KEYWORDID,  CStep21Parser::IDENTID, CStep21Parser::IDENTID, 0)))
			{
				entityname=  std::string(findit->value.begin(), findit->value.end()).c_str();
			}	
			NamedEntities[nameid]=entityname;

			outputfile <<(StrFormat("%s DataEntity %s=%s\n", tabs, nameid, entityname)); ;
		}
		break;

	case CStep21Parser::EntityNameID:
		{
			CString str;
			if(findNode(i->children.begin(), findit, 0, Nodes(nodes, CStep21Parser::ENTITY_NAMEID, CStep21Parser::ENTITY_NAMEID, 0)))
			{
				 str=  std::string(findit->value.begin(), findit->value.end()).c_str();
			}		
			outputfile <<(StrFormat("%s EntityName %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		}
		goto done;	
	case CStep21Parser::ENTITY_NAMEID:
		outputfile <<(StrFormat("%s ENTITY_NAME %s\n", tabs,std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;	
	case CStep21Parser::HEADERID:
		outputfile <<(StrFormat("%s HEADER %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21EBNF(it); }
		break;	
	default:
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) 
		{  evalP21EBNF(it); }

	}
done:
	tabs=tabs.Mid(1, tabs.GetLength()-1);
	return 0;
}

void CStep21Parser::Step21ParseIt()
{
	step21_skip_parser skip;
	//ebnf_skip_grammar skip;
	CString file = ReadAFile(CString(GetExeDirectory() + "..\\Grammars\\TestPart21.txt"));

	std::string str = file;
	outputfile.open (CString(GetExeDirectory() + "..\\Grammars\\TestPart21Tree.txt"), std::fstream::out );
	tree_parse_info<const char*> info =	pt_parse((const char *) file, *this, skip);
	//		ast_parse((const char *) file, *this, skip);
	if(info.full)
	{
		OutputDebugString("Ini File Parse Succeeded \n");
		evalP21EBNF(info.trees.begin());
		std::map<CString, CString>::iterator it;
		for(it = NamedEntities.begin(); it !=NamedEntities.end(); it++)
		{
			OutputDebugString(StrFormat("%s=%s\n", (*it).first, (*it).second));

		}

		//tree_to_xml(outputfile.fp, info.trees, str, this->rule_names);
	}
	else
	{
		OutputDebugString("Ini File Parse Failed \n");

	}

}