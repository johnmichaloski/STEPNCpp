//
// Step21Parser.cpp
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.


#include "stdafx.h"
#include "Step21Parser.h"

#include "OutDebug.h"
#include "boost/lexical_cast.hpp"

#include "atlstr.h"
#include "Misc.h"
//#include "Part21Generator.h"
//#include "StepNC.h"
//extern CPart21Generator * _gPart21gen;
#include "Globals.h"
using namespace Express;

static	std::fstream outputfile;
int linenumber;

//
//#include "machining_schemaClassDefinitions.h"
//#include "milling_schemaClassDefinitions.h"

IStepNodePtr project;
static CString szWarnings;

struct  CStep21BoostParser :
	public boost::spirit::grammar<CStep21BoostParser>
{

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

	enum { SEMICOLONID=1, GrammarID,

		LOGICALTRUEID, LOGICALFALSEID, LOGICALUNKWNID,
		IDENTID, ENUMID, USER_DEFINED_KEYWORDID, BINARYID,
		Entity_exportID, EntityReferencesID, EmbeddedListID, ListID, ListEntryID,
		ParametersID, ParameterID, Subsuper_Record_List_ElementID, Simple_RecordID,
		Subsuper_Record_ListID, Subsuper_RecordID,Entity_Instance_RHSID,
		EntityNameID, EntityReferenceID, HeaderEntityID, HeaderSectionID,
		HeaderEntitiesID, ReqHdrEntitiesID, OptHdrEntitiesID, DataSectionID,
		DataEntityID, DataEntitiesID, ENTITY_NAMEID, HEADERID,
		KEYWORDID, STRINGID, MISSINGID, REALID, INTEGERID, LOGICALID

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

		
		rule<ScannerT, parser_context<>, parser_tag<LOGICALID> > LOGICAL;

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
		rule<ScannerT, parser_context<>, parser_tag<REALID> >REAL;
		rule<ScannerT, parser_context<>, parser_tag<INTEGERID> >INTEGER;



		rule<ScannerT> ExchangeFile ;
		rule<ScannerT> EQUALS, SEMICOLON, LEFT_PAREN,RIGHT_PAREN, SLASH, REDEFINE ;
		rule<ScannerT> SCOPE, ISO_10303_21, END_ISO_10303_21, ENDSEC, ENDSCOPE,DATA, COMMA ;


		symbols<>voidcommands;

		//assertion_t expect_semicolon, expect_close_bracket;

		definition( CStep21BoostParser const &self )
		{   

			ExchangeFile= ISO_10303_21 >> SEMICOLON >>
				HeaderSection  >>	
				DataSection >>  
				END_ISO_10303_21 ;


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
			END_ISO_10303_21 = str_p("END-ISO-10303-21")>> SEMICOLON  >> lexeme_d[*space_p]; 	
			ENDSEC = str_p("ENDSEC"); 	
			ENDSCOPE = str_p("ENDSCOPE"); 	
			DATA = str_p("DATA"); 	
			LOGICALTRUE = str_p(".T.");
			LOGICALFALSE = str_p(".F.");
			LOGICALUNKWN = str_p(".U.");
			LOGICAL = LOGICALTRUE | LOGICALFALSE | LOGICALUNKWN ;

			ENUM =  leaf_node_d[lexeme_d[ch_p('.') >> +range_p('A','Z') >> *(alnum_p|'_') >> ch_p('.')]] ;
			USER_DEFINED_KEYWORD =  ch_p('!') >> IDENT  ;
			//ENTITY_NAME = leaf_node_d[lexeme_d[ch_p('#') >>+range_p('0','9')]];
			ENTITY_NAME = lexeme_d[leaf_node_d[ch_p('#') >>+range_p('0','9')]];
			//ENTITY_NAME = lexeme_d[ch_p('#') >>+range_p('0','9')];

			KEYWORD = 	 ENDSCOPE |  ENDSEC | 
				str_p("FILE_DESCRIPTION") | str_p("FILE_NAME") 	| str_p("FILE_SCHEMA")
				| IDENT;
			// Have to keep '' because empty will not populate the tree...
			STRING		= leaf_node_d[ ch_p('\'') >> *( anychar_p - ch_p('\'') ) >> ch_p('\'')]; //[&write]
			REAL = leaf_node_d[real_p];
			INTEGER  = leaf_node_d[int_p]; 
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


			Parameter	= 
				leaf_node_d[MISSING]
				| REDEFINE
				| REAL
				| INTEGER
				| LOGICAL
				| ENUM
				| STRING
				| BINARY
				| EntityReference
				| EmbeddedList;

			Entity_export   = *(SLASH >> EntityReferences >> SLASH);

			EntityReferences= EntityReference | EntityReferences >> COMMA >> EntityReference;
			EmbeddedList	= discard_node_d[LEFT_PAREN] >>  *list_p( Parameter, ',' ) >> ch_p(')') ;

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
				
				  confix_p("//",*anychar_p,eol_p)  
				| confix_p("/*",*anychar_p,"*/") 
				| space_p
				

				;
		}

		rule<ScannerT> skip, skip_until_eol;
		rule<ScannerT> const& start() const { return skip; }
	};
};


CStep21Parser::CStep21Parser(void)
{


}
typedef std::vector<parser_id> TreeNodes;
static CString tabs("");

std::map<CString, CString> NamedEntities;
std::map<CString, IStepNodePtr> entityInstances;
std::vector<IStepNodePtr> entities;
std::vector<long> variables;



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
int evalP21DataEntityIds(const TreeIter& i)
{
	tabs+="\t";
	int n =  i->value.id().to_long();
	TreeIter findit;
	TreeNodes nodes;
	switch(n)
	{

	case CStep21BoostParser::DataEntitiesID:
		OUTPUT_DEBUG_STRING(StrFormat("%s DataEntities %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  evalP21DataEntityIds(it); }
		break;

	case CStep21BoostParser::DataEntityID:
		{
			CString nameid;
			CString entityname;
			TreeIter it;

			it = i->children.begin();
			if(findNode(it, findit, 0, Nodes(nodes, CStep21BoostParser::EntityNameID,  CStep21BoostParser::ENTITY_NAMEID, CStep21BoostParser::ENTITY_NAMEID, 0)))
			{
				nameid=  std::string(findit->value.begin(), findit->value.end()).c_str();
			}	

			it++; 
			// FIXME: could also be USER_DEFINED_KEYWORD or SCOPE
			if(findNode(it, findit, 0, Nodes(nodes, CStep21BoostParser::Entity_Instance_RHSID,  CStep21BoostParser::Simple_RecordID, 
				CStep21BoostParser::KEYWORDID,  CStep21BoostParser::IDENTID, CStep21BoostParser::IDENTID, 0)))
			{
				entityname=  std::string(findit->value.begin(), findit->value.end()).c_str();
				entityname.Trim();
			}	
			NamedEntities[nameid]=entityname;
			for(; it!=i->children.end(); it++) 
			{  
				evalP21DataEntityIds(it); 
			}

			OUTPUT_DEBUG_STRING(StrFormat("%s DataEntity %s=%s\n", tabs, nameid, entityname)); ;
		}
		goto done;

	default:
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) 
		{  
			evalP21DataEntityIds(it); 
		}

	}
done:
	tabs=tabs.Mid(1, tabs.GetLength()-1);
	return 0;
}

static HRESULT InstanceStore(IStepNodePtr instance)
{
	if(entities.size()>0)
	{
		IStepNodePtr step = entities.back();
		CVarDefPtr vardef = step->GetInstanceVar(variables.back());
		Store(vardef, instance);
		if(!vardef->IsListType()) variables.back()++;
	}
	else
	{
		OutputDebugString(StrFormat("Warning: InstanceStore missing entity\n"));
		//::DebugBreak();
	}

	return S_OK;
}
template<typename TreeIter>
int storeP21EBNF(const TreeIter& i)
{
	tabs+="\t";
	int n =  i->value.id().to_long();
	TreeIter findit;
	TreeNodes nodes;
	switch(n)
	{

	case CStep21BoostParser::LOGICALTRUEID:
	case CStep21BoostParser::LOGICALFALSEID:
	case CStep21BoostParser::LOGICALUNKWNID:
		{

			OUTPUT_DEBUG_STRING(StrFormat("%s LOGICALTRUEID %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			TreeIter it = i->children.begin();
			CString sval = std::string(it->value.begin(), it->value.end()).c_str();
			long nVal = (sval== ".T.") ? 1 : (sval== ".F.") ? 0 : -1; 
			IStepNodePtr instance =   new EInteger(nVal);
			// error check 
			InstanceStore(instance) ;
#if 0
			OUTPUT_DEBUG_STRING(StrFormat("%s EntityReference %s\n", tabs, nameid));
			IStepNodePtr step = entities.back();
			CVarDef * vardef = step->GetInstanceVar(variables.back());
			Store(vardef, new EInteger(nVal));
			if(!vardef->IsList()) variables.back()++;
#endif
			goto done;
		}
		break;

	case CStep21BoostParser::ENUMID:
		{
			OUTPUT_DEBUG_STRING(StrFormat("%s ENUMID %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			TreeIter it = i->children.begin();
			CString sval = std::string(it->value.begin(), it->value.end()).c_str();
			sval.Replace(".","");
			IStepNodePtr step = entities.back();
			CVarDefPtr vardef = step->GetInstanceVar(variables.back());
			OUTPUT_DEBUG_STRING(StrFormat("Enum class is %s\n", vardef->m_sClassname));
			IStepNodePtr pEnum =  gClassGenerators.CreateClass(ExpDemangle(vardef->m_sClassname), "");
			EEnum*instance = (EEnum*) pEnum.get();
			instance->SetString2Enum(sval);
			// error check 
			InstanceStore((IStepNodePtr) pEnum) ;
		}
		break;

	case CStep21BoostParser::MISSINGID:
		{
			OUTPUT_DEBUG_STRING(StrFormat("%s MISSING %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); 
			// check to see if optional otherwise error
			if(entities.size()>0)
			{
				IStepNodePtr step = entities.back();
				CVarDefPtr vardef = step->GetInstanceVar(variables.back());

				if(!vardef->m_bOptional)
				{
					szWarnings+=StrFormat("Entity \"%s\" Variable \"%s\" Missing Value - Not optional.\n", entities.back()->Classname(), vardef->_sName);
				}
			}

			InstanceStore(NULL) ;
			goto done;
		}
		break;	

	case CStep21BoostParser::EntityReferenceID:
		{
			TreeIter it = i->children.begin();
			it = it->children.begin();
			CString nameid = std::string(it->value.begin(), it->value.end()).c_str();
			IStepNodePtr step = entities.back();
			OUTPUT_DEBUG_STRING(StrFormat("%s Store EntityReference %s\n", tabs, nameid));
			if(nameid=="#126")
			{
				//DebugBreak();
			}

			InstanceStore(entityInstances[nameid]) ;
			goto done;
			//for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		}
		break;	


	case CStep21BoostParser::STRINGID:
		{
			OUTPUT_DEBUG_STRING(StrFormat("%s STRING %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			TreeIter it = i->children.begin();
			CString s = std::string(it->value.begin(), it->value.end()).c_str();
			// Remove beginning and trailing quote '
			s=s.Mid(1);
			s=s.Left(s.GetLength()-1);
			InstanceStore(new EString(s)) ;
			goto done;
		}
		break;

	case CStep21BoostParser::REALID:
	case CStep21BoostParser::INTEGERID:
		{
			TreeIter it = i->children.begin();
			IStepNodePtr step = entities.back();
			CVarDefPtr vardef = step->GetInstanceVar(variables.back());
			// parsed double can be used as integer...
			if(vardef->Type() == integer_)
			{

				OUTPUT_DEBUG_STRING(StrFormat("%s INTEGERID %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
				long nVal = boost::lexical_cast<long>(string(it->value.begin(), it->value.end()));
				InstanceStore(new EInteger(nVal)) ;
			}
			else
			{
				OUTPUT_DEBUG_STRING(StrFormat("%s REAL %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
				double d = boost::lexical_cast<double>(string(it->value.begin(), it->value.end()));
				InstanceStore(new EReal(d)) ;

			}
			goto done;		
		}
		break;

	case CStep21BoostParser::EmbeddedListID:
		{
		OUTPUT_DEBUG_STRING(StrFormat("%s EmbeddedListID %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }

		CString token = std::string(i->value.begin(), i->value.end()).c_str();

		if(token==")" && entities.size()>0)
				variables.back()++;
		}
		break;	


	case CStep21BoostParser::IDENTID:
		{
			OUTPUT_DEBUG_STRING(StrFormat("%s IDENTID %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		}
		break;
	case CStep21BoostParser::USER_DEFINED_KEYWORDID:
		OUTPUT_DEBUG_STRING(StrFormat("%s USER_DEFINED_KEYWORD %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		break;
	case CStep21BoostParser::BINARYID:
		OUTPUT_DEBUG_STRING(StrFormat("%s BINARYID %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		break;
	case CStep21BoostParser::Entity_exportID:
		OUTPUT_DEBUG_STRING(StrFormat("%s Entity_export %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		break;	
	
	case CStep21BoostParser::KEYWORDID:
		{
			OUTPUT_DEBUG_STRING(StrFormat("%s KEYWORD %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
			break;
		}
	case CStep21BoostParser::ListID:
		OUTPUT_DEBUG_STRING(StrFormat("%s List %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		break;	
	case CStep21BoostParser::ListEntryID:
		outputfile <<(StrFormat("%s ListEntry %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		break;	
	case CStep21BoostParser::ParametersID:
		OUTPUT_DEBUG_STRING(StrFormat("%s Parameters %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		break;	
	case CStep21BoostParser::ParameterID:
		OUTPUT_DEBUG_STRING(StrFormat("%s ParameterID %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		break;	
	case CStep21BoostParser::Subsuper_Record_List_ElementID:
		OUTPUT_DEBUG_STRING(StrFormat("%s Subsuper_Record_List_Element %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		break;	
	case CStep21BoostParser::Simple_RecordID:
		OUTPUT_DEBUG_STRING(StrFormat("%s Simple_Record %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		break;	
	case CStep21BoostParser::Subsuper_Record_ListID:
		OUTPUT_DEBUG_STRING(StrFormat("%s Subsuper_Record_List %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		break;	
	case CStep21BoostParser::Subsuper_RecordID:
		OUTPUT_DEBUG_STRING(StrFormat("%s Subsuper_Record %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		break;	
	case CStep21BoostParser::Entity_Instance_RHSID:
		OUTPUT_DEBUG_STRING(StrFormat("%s Entity_Instance_RHS %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		break;	
	case CStep21BoostParser::EntityReferencesID:
		{
		OUTPUT_DEBUG_STRING(StrFormat("%s EntityReferencesID %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }

		}
		break;

	case CStep21BoostParser::HeaderEntityID:
		OUTPUT_DEBUG_STRING(StrFormat("%s HeaderEntity %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		{

			TreeIter it= i->children.begin()->children.begin();
			CString id = std::string(it->value.begin(), it->value.end()).c_str(); 
			if(id=="FILE_DESCRIPTION" || id=="FILE_NAME" || id=="FILE_SCHEMA")
			{
				IStepNodePtr step ;
				// Look up statically P21 header information.
				if(id=="FILE_DESCRIPTION")
					step = _gPart21gen->Header()->file_description = new Efile_description ;
				else if(id=="FILE_NAME")
					step = _gPart21gen->Header()->file_name = new Efile_name ;
				else if(id=="FILE_SCHEMA")
					step = _gPart21gen->Header()->file_schema = new Efile_schema ;


				entities.push_back(step);
				variables.push_back(0);
				
				for(it= i->children.begin()+1; it!=i->children.end(); it++) 
				{  
					storeP21EBNF(it); 
				}
				entities.pop_back();
				variables.pop_back();
			}
			else
				for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }

		}
		break;	
	case CStep21BoostParser::HeaderSectionID:
		OUTPUT_DEBUG_STRING(StrFormat("%s HeaderSection %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		break;	

	case CStep21BoostParser::HeaderEntitiesID:
		OUTPUT_DEBUG_STRING(StrFormat("%s HeaderEntities %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		break;	
	case CStep21BoostParser::ReqHdrEntitiesID:
		OUTPUT_DEBUG_STRING(StrFormat("%s ReqHdrEntities %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		break;	
	case CStep21BoostParser::OptHdrEntitiesID:
		OUTPUT_DEBUG_STRING(StrFormat("%s OptHdrEntities %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++){  storeP21EBNF(it); }
		break;	
	case CStep21BoostParser::DataSectionID:
		OUTPUT_DEBUG_STRING(StrFormat("%s DataSection %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		break;	


	case CStep21BoostParser::DataEntitiesID:
		OUTPUT_DEBUG_STRING(StrFormat("%s DataEntities %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		break;

	case CStep21BoostParser::DataEntityID:
		{
			CString nameid;
			CString entityname;
			TreeIter it;

			it = i->children.begin();
			if(findNode(it, findit, 0, Nodes(nodes, CStep21BoostParser::EntityNameID,  CStep21BoostParser::ENTITY_NAMEID, CStep21BoostParser::ENTITY_NAMEID, 0)))
			{
				nameid=  std::string(findit->value.begin(), findit->value.end()).c_str();
			}	

			it++; 
			// could also be USER_DEFINED_KEYWORD or SCOPE
			if(findNode(it, findit, 0, Nodes(nodes, CStep21BoostParser::Entity_Instance_RHSID,  CStep21BoostParser::Simple_RecordID, 
				CStep21BoostParser::KEYWORDID,  CStep21BoostParser::IDENTID, CStep21BoostParser::IDENTID, 0)))
			{
				entityname=  std::string(findit->value.begin(), findit->value.end()).c_str();
			}	

			OUTPUT_DEBUG_STRING(StrFormat("DataEntityID Name=%s Entity=%s\n",  nameid, entityname));

			if(entityInstances[nameid]==NULL)
			{
				// Hasn't been defined.
				OUTPUT_DEBUG_STRING(StrFormat("ERROR CLASS %s HAS NOT BEEN DEFINED\n", nameid));
				::DebugBreak();
				goto done;
			}
			entities.push_back(entityInstances[nameid]);
			variables.push_back(0);

			for(; it!=i->children.end(); it++) 
			{  
				storeP21EBNF(it); 
			}
			entities.pop_back();
			variables.pop_back();

			outputfile <<(StrFormat("%s DataEntity %s=%s\n", tabs, nameid, entityname)); ;
		}
		break;

	case CStep21BoostParser::EntityNameID:
		{
			CString str;
			if(findNode(i->children.begin(), findit, 0, Nodes(nodes, CStep21BoostParser::ENTITY_NAMEID, CStep21BoostParser::ENTITY_NAMEID, 0)))
			{
				 str=  std::string(findit->value.begin(), findit->value.end()).c_str();
			}		
			OUTPUT_DEBUG_STRING(StrFormat("%s EntityName %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		}
		goto done;	
	case CStep21BoostParser::ENTITY_NAMEID:
		OUTPUT_DEBUG_STRING(StrFormat("%s ENTITY_NAME %s\n", tabs,std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		break;

	case CStep21BoostParser::HEADERID:
		OUTPUT_DEBUG_STRING(StrFormat("%s HEADER %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		break;	
	default:
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) 
		{  storeP21EBNF(it); }

	}
done:
	tabs=tabs.Mid(1, tabs.GetLength()-1);
	return 0;
}

HRESULT CStep21Parser::Step21ParseIt(CString filename)
{
	//step21_skip_parser skip;
	step_skip_grammar skip;
	//ebnf_skip_grammar skip;
	_p21filename=filename; // CString(GetExeDirectory() + "..\\Grammars\\TestPart21.txt");
	CString file = ReadAFile(_p21filename);

	std::string str = file;
	outputfile.open (CString(GetExeDirectory() + ".\\DebugP2Parsing.txt"), std::fstream::out );
	CStep21BoostParser parser;
	tree_parse_info<const char*> info =	pt_parse((const char *) file, parser, skip);
	//		ast_parse((const char *) file, *this, skip);
	if(info.full)
	{
		OutputDebugString("Ini File Parse Succeeded \n");
		evalP21DataEntityIds(info.trees.begin());
		std::map<CString, CString>::iterator it;
		for(it = NamedEntities.begin(); it !=NamedEntities.end(); it++)
		{
			OUTPUT_DEBUG_STRING( StrFormat("%s=%s\n", (*it).first, (*it).second));
			entityInstances[(*it).first] = gClassGenerators.CreateClass((*it).second, (*it).first) ;
			if(entityInstances[(*it).first]==NULL)
			{
				OUTPUT_DEBUG_STRING( StrFormat("%s Entity %s Not Created!\n", (*it).first, (*it).second));
				DebugBreak();
			}


		}

		szWarnings.Empty();
		storeP21EBNF(info.trees.begin());
		OutputDebugString(szWarnings);

		std::map<CString, IStepNodePtr>::iterator eit;
		for(eit = entityInstances.begin(); eit !=entityInstances.end(); eit++)
		{
			if((*eit).second==NULL)
				continue;
			if((*eit).second->m_sClassname==ExpMangle(gStartEntity))
			{
				project = (*eit).second;
				break;
			}
		}

		if(project==NULL)
		{
			OutputDebugString(StrFormat("Part21 Parsing - couldn't find project %s\n" , info.stop));
			return E_FAIL;
		}

		//tree_to_xml(outputfile.fp, info.trees, str, this->rule_names);
	}
	else
	{
		OutputDebugString(StrFormat("Ini File Parse Failed %s\n" , info.stop));
			return E_FAIL;

	}
	return S_OK;

}