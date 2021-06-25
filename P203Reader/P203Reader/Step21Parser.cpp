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

#include <boost/preprocessor.hpp>
#include <boost/preprocessor/cat.hpp>
#include <boost/preprocessor/seq/for_each.hpp>
#define TO_STR(unused,data,elem) BOOST_PP_STRINGIZE(elem) ,



//-----------------------


using namespace Express;

static	std::fstream outputfile;
int linenumber;
typedef std::vector<parser_id> TreeNodes;
static CString tabs("");
typedef std::map<CString, CStringVector>::iterator NamedEntitiesIterator;
std::map<CString, CStringVector> NamedEntities;
std::map<CString, std::vector<IStepNodePtr>> entityInstances;
typedef std::map<CString, std::vector<IStepNodePtr>>::iterator EntityInstanceIterator; 
std::vector<IStepNodePtr> entities;
std::vector<long> variables;

//
//#include "machining_schemaClassDefinitions.h"
//#include "milling_schemaClassDefinitions.h"

IStepNodePtr project;
static CString szWarnings;
inline void write(const char * begin,const char * end)
{
	std::string str(begin, end );
	OutputDebugString( str.c_str());
}
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

	//std::map<parser_id, std::string> rule_names;
#define SEQ	(LOGICALTRUEID)(LOGICALFALSEID)(LOGICALUNKWNID)\
		(IDENTID)(ENUMID)(USER_DEFINED_KEYWORDID) (BINARYID)(INTEGERID)(LOGICALID)\
		(ComplexEntityInstanceID)(DataEntitiesID)(DataSectionID) \
		(EntityInstanceID)(EntityInstanceNameID)(EntityNameID) \
		(EntityReferenceID)(HeaderEntitiesID)(HeaderEntityID) \
		(HeaderSectionID)(KEYWORDID)(ListID) (MISSINGID)(OmittedParameterID)(OptHdrEntitiesID)\
		(ParameterID)(ParametersID)(ParameterListID) (REALID)(ReqHdrEntitiesID)(Simple_RecordID)\
		(SimpleEntityInstanceID)(SimpleEntityListID)(SimpleRecordListID) (STRINGID)\
		(ISO_10303_21ID)(END_ISO_10303_21D)(EQUALSID) (SEMICOLONID)\
		(LEFT_PARENID)(RIGHT_PARENID)(COMMAID)\
		(Subsuper_RecordID)(TypedParameterID)(UntypedParameterID)(LastID)

	enum parser_ids { BOOST_PP_SEQ_ENUM(SEQ) };
	static CString GetRuleString(parser_ids i)
	{
		parser_ids ids=LastID;
		if(i>ids)
			return "";
		static const char * rule_names[]={ BOOST_PP_SEQ_FOR_EACH(TO_STR,~,SEQ) };
		return rule_names[i];
	}



#if 0
	enum { SEMICOLONID=1, GrammarID,

		LOGICALTRUEID, LOGICALFALSEID, LOGICALUNKWNID,
		IDENTID, ENUMID, USER_DEFINED_KEYWORDID, BINARYID, INTEGERID, LOGICALID,

		//Entity_exportID, EmbeddedListID,  

		ComplexEntityInstanceID=12,  DataEntitiesID=13,  DataSectionID=14,  
		EntityInstanceID=15,  EntityInstanceNameID=16,   EntityNameID,
		EntityReferenceID,  HeaderEntitiesID,  HeaderEntityID=20,    
		HeaderSectionID,   KEYWORDID=22,  ListID, MISSINGID, OmittedParameterID,  OptHdrEntitiesID,  
		ParameterID=27, ParametersID, ParameterListID,  REALID,  ReqHdrEntitiesID,  Simple_RecordID,  
		SimpleEntityInstanceID=33,  SimpleEntityListID,  SimpleRecordListID,  STRINGID,  
		Subsuper_RecordID, TypedParameterID, UntypedParameterID,  

	};
#endif
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

		//		rule<ScannerT, parser_context<>, parser_tag<ListID> > List;
		//		rule<ScannerT, parser_context<>, parser_tag<ListEntryID> > ListEntry;
		rule<ScannerT, parser_context<>, parser_tag<Simple_RecordID> > Simple_Record;
		rule<ScannerT, parser_context<>, parser_tag<Subsuper_RecordID> > Subsuper_Record;


		rule<ScannerT, parser_context<>, parser_tag<EntityNameID> > EntityName;
		rule<ScannerT, parser_context<>, parser_tag<HeaderEntityID> > HeaderEntity;
		rule<ScannerT, parser_context<>, parser_tag<HeaderSectionID> > HeaderSection;
		rule<ScannerT, parser_context<>, parser_tag<HeaderEntitiesID> > HeaderEntities;
		rule<ScannerT, parser_context<>, parser_tag<ReqHdrEntitiesID> > ReqHdrEntities;
		rule<ScannerT, parser_context<>, parser_tag<OptHdrEntitiesID> > OptHdrEntities;
		rule<ScannerT, parser_context<>, parser_tag<DataSectionID> > DataSection;
		rule<ScannerT, parser_context<>, parser_tag<DataEntitiesID> > DataEntities;


		rule<ScannerT, parser_context<>, parser_tag<KEYWORDID> > KEYWORD;



		rule<ScannerT, parser_context<>, parser_tag<ParameterListID> > ParameterList;

		rule<ScannerT, parser_context<>, parser_tag<TypedParameterID> > TypedParameter;
		rule<ScannerT, parser_context<>, parser_tag<UntypedParameterID> > UntypedParameter;
		rule<ScannerT, parser_context<>, parser_tag<OmittedParameterID> > OmittedParameter;
		rule<ScannerT, parser_context<>, parser_tag<MISSINGID> > MISSING;
		rule<ScannerT, parser_context<>, parser_tag<STRINGID> > STRING;
		rule<ScannerT, parser_context<>, parser_tag<REALID> >REAL;
		rule<ScannerT, parser_context<>, parser_tag<INTEGERID> >INTEGER;
		rule<ScannerT, parser_context<>, parser_tag<EntityInstanceNameID> > EntityInstanceName;
		rule<ScannerT, parser_context<>, parser_tag<ParameterID> > Parameter;
		rule<ScannerT, parser_context<>, parser_tag<ListID> > List;
		rule<ScannerT, parser_context<>, parser_tag<EntityInstanceID> > EntityInstance;
		rule<ScannerT, parser_context<>, parser_tag<SimpleEntityListID> > SimpleEntityList;
		rule<ScannerT, parser_context<>, parser_tag<ComplexEntityInstanceID> > ComplexEntityInstance;
		rule<ScannerT, parser_context<>, parser_tag<SimpleEntityInstanceID> > SimpleEntityInstance;
		rule<ScannerT, parser_context<>, parser_tag<SimpleRecordListID> > SimpleRecordList;
		rule<ScannerT, parser_context<>, parser_tag<ParametersID> > Parameters;
		rule<ScannerT, parser_context<>, parser_tag<EntityReferenceID> > EntityReference;


		rule<ScannerT, parser_context<>, parser_tag<ISO_10303_21ID> > ISO_10303_21;
		rule<ScannerT, parser_context<>, parser_tag<END_ISO_10303_21D> > END_ISO_10303_21;
		rule<ScannerT, parser_context<>, parser_tag<EQUALSID> > EQUALS;
		rule<ScannerT, parser_context<>, parser_tag<SEMICOLONID> > SEMICOLON;
		rule<ScannerT, parser_context<>, parser_tag<LEFT_PARENID> > LEFT_PAREN;
		rule<ScannerT, parser_context<>, parser_tag<RIGHT_PARENID> > RIGHT_PAREN;
		rule<ScannerT, parser_context<>, parser_tag<COMMAID> > COMMA;


		rule<ScannerT> ExchangeFile, SLASH, REDEFINE, ENDSEC, DATA ;

		symbols<>voidcommands;

		// assertion_t expect_semicolon, expect_close_bracket;
		//ENTITY_INSTANCE_NAME = "#" DIGIT { DIGIT }
		//KEYWORD = USER_DEFINED_KEYWORD | STANDARD_KEYWORD .
		//USER_DEFINED_KEYWORD = "!" UPPER { UPPER | DIGIT } .
		//STANDARD_KEYWORD = UPPER { UPPER | DIGIT } .

		definition( CStep21BoostParser const &self )
		{   


			IDENT	=  leaf_node_d[lexeme_d[+range_p('A','Z') >> *(alnum_p|'_')]];

			EQUALS = str_p("="); 	
			SEMICOLON = str_p(";"); 	
			COMMA = str_p(","); 	
			LEFT_PAREN = str_p("("); 	
			RIGHT_PAREN = str_p(")"); 	
			SLASH = str_p("/"); 	
			MISSING = str_p("$"); 	
			REDEFINE = str_p("*"); 	
			BINARY =   ch_p('\"') >> range_p('0','3') >> *alnum_p >> ch_p('\"');
			ISO_10303_21 = str_p("ISO-10303-21;"); 	
			END_ISO_10303_21 = str_p("END-ISO-10303-21;")>> lexeme_d[*space_p]; 	
			ENDSEC = str_p("ENDSEC"); 	
			DATA = str_p("DATA"); 	
			LOGICALTRUE = str_p(".T.");
			LOGICALFALSE = str_p(".F.");
			LOGICALUNKWN = str_p(".U.");
			LOGICAL = LOGICALTRUE | LOGICALFALSE | LOGICALUNKWN ;

			ENUM =  leaf_node_d[lexeme_d[ch_p('.') >> +range_p('A','Z') >> *(alnum_p|'_') >> ch_p('.')]] ;
			//ENUM =  lexeme_d[ch_p('.') >> +range_p('A','Z') >> *(alnum_p|'_') >> ch_p('.')] ;
			USER_DEFINED_KEYWORD =  ch_p('!') >> IDENT  ;
			//EntityName = leaf_node_d[lexeme_d[ch_p('#') >>+range_p('0','9')]];
			EntityName = lexeme_d[leaf_node_d[ch_p('#') >>+range_p('0','9')]];


			//EntityName = lexeme_d[ch_p('#') >>+range_p('0','9')];

			KEYWORD = 	str_p("FILE_DESCRIPTION") | str_p("FILE_NAME") 	| str_p("FILE_SCHEMA") | IDENT ; // IDENT[&write]; 
			//	|  ENDSCOPE |  ENDSEC | str_p("FILE_DESCRIPTION") | str_p("FILE_NAME") 	| str_p("FILE_SCHEMA");
			// Have to keep '' because empty will not populate the tree...
			STRING		= leaf_node_d[ ch_p('\'') >> *( anychar_p - ch_p('\'') ) >> ch_p('\'')]; //[&write]
			REAL = leaf_node_d[real_p];
			INTEGER  = leaf_node_d[int_p]; 

			///////////////////////////////////////////////////////////////
			ExchangeFile= ISO_10303_21 >> 
				HeaderSection  >>	
				+(DataSection) >>  
				END_ISO_10303_21 ;

			HeaderSection	= str_p("HEADER;") >> HeaderEntities >> str_p("ENDSEC;") ;
			HeaderEntities	= ReqHdrEntities >> *(HeaderEntity); 
			ReqHdrEntities	= HeaderEntity >> HeaderEntity>> HeaderEntity;
			HeaderEntity	= KEYWORD >> LEFT_PAREN >> ParameterList  >>RIGHT_PAREN >> SEMICOLON;

			ParameterList	= Parameter >> *( str_p(",") >> Parameter ) ;
			Parameter		= UntypedParameter | TypedParameter | OmittedParameter;
			Parameters		=  *list_p(Parameter, ',' );
			TypedParameter  = KEYWORD >> ch_p('(') >> Parameter >> ch_p(')');

			EntityReference = EntityInstanceName;
			UntypedParameter= 
				leaf_node_d[MISSING]
				| REDEFINE
				| REAL
				| INTEGER
				| LOGICAL
				| ENUM
				| STRING
				| BINARY
				| EntityReference
				| List;

			OmittedParameter		= ch_p('*');
			List					= ch_p('(') >> *( Parameter >> *(ch_p(',') >> Parameter)) >> ch_p(')');

			DataSection				= DATA >>  *(ParameterList) >> SEMICOLON >> +EntityInstance >> ENDSEC >> SEMICOLON ;
			EntityInstance			= SimpleEntityInstance | ComplexEntityInstance;
			SimpleEntityInstance	= EntityInstanceName >> ch_p('=')  >> Simple_Record >> SEMICOLON;
			ComplexEntityInstance	= EntityInstanceName >> ch_p('=') >> Subsuper_Record >> SEMICOLON;
			EntityInstanceName		= lexeme_d[leaf_node_d[ch_p('#') >>+range_p('0','9')]];

			Simple_Record			= KEYWORD >> LEFT_PAREN >> Parameters >> RIGHT_PAREN;

			Subsuper_Record			= LEFT_PAREN >> SimpleRecordList >> RIGHT_PAREN;
			SimpleRecordList		= +Simple_Record;



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
			BOOST_SPIRIT_DEBUG_RULE(List);
			BOOST_SPIRIT_DEBUG_RULE(DataSection);
			BOOST_SPIRIT_DEBUG_RULE(DataEntities);
			BOOST_SPIRIT_DEBUG_RULE(DataEntity);
			BOOST_SPIRIT_DEBUG_RULE(SimpleEntityInstance);
			BOOST_SPIRIT_DEBUG_RULE(EntityInstanceName);
			BOOST_SPIRIT_DEBUG_RULE(Simple_Record);
			BOOST_SPIRIT_DEBUG_RULE(Subsuper_Record);
			BOOST_SPIRIT_DEBUG_RULE(EntityName);
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


// FIXED: this now starts with the first item. Does not ignore it.
std::vector<parser_id> & Nodes(std::vector<parser_id> & nodes, parser_id p1, ...)
{
	va_list list;
	va_start(list,p1); 
	parser_id p=p1;
	nodes.clear();
	for(;;)
	{ 
		nodes.push_back(p); 
		p=va_arg(list,parser_id);
		if(p== 0)
			break;
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
std::vector<CString> InstanceEntityIds;
template<typename TreeIter>
int evalP21DataEntityIds(const TreeIter& i)
{
	tabs+="\t";
	int n =  i->value.id().to_long();
	TreeIter findit;
	TreeIter it;
	TreeNodes nodes;
	CString nameid;			// #n
	CString entityname;		// entityname(parameter,list,..)

	switch(n)
	{

	case CStep21BoostParser::Simple_RecordID:
		{
			if(findNode(i, findit, 0, Nodes(nodes, CStep21BoostParser::KEYWORDID,  CStep21BoostParser::IDENTID, 
				CStep21BoostParser::IDENTID, 0)))
			{
				// 32, 22, 6
				entityname=  std::string(findit->value.begin(), findit->value.end()).c_str();
				entityname.Trim();
			}	
			nameid=InstanceEntityIds.back();
			NamedEntities[nameid].push_back(entityname);
			goto done;
		}

	case CStep21BoostParser::ComplexEntityInstanceID:
		{
			if(i->children.size() <1)
				goto done;
			
			it= i->children.begin();

			if(findNode(it, findit, 0, Nodes(nodes, CStep21BoostParser::EntityInstanceNameID, 0)))
			{
				nameid=  std::string(findit->value.begin(), findit->value.end()).c_str();
			}	
			InstanceEntityIds.push_back(nameid);
			for(; it!=i->children.end(); it++) 
			{  
				evalP21DataEntityIds(it); 
			}
			InstanceEntityIds.pop_back();
		}
		goto done;
	case CStep21BoostParser::SimpleEntityInstanceID:
		{
			
			it= i->children.begin();

			if(findNode(it, findit, 0, Nodes(nodes, CStep21BoostParser::EntityInstanceNameID, 0)))
			{
				nameid=  std::string(findit->value.begin(), findit->value.end()).c_str();
			}	

			it+=2; // move past "="
			// FIXME: could also be USER_DEFINED_KEYWORD or SCOPE
			// it => CStep21BoostParser::Simple_RecordID,
			if(findNode(it, findit, 0, Nodes(nodes, CStep21BoostParser::KEYWORDID,  CStep21BoostParser::IDENTID, 
				CStep21BoostParser::IDENTID, 0)))
			{
				// 32, 22, 6
				entityname=  std::string(findit->value.begin(), findit->value.end()).c_str();
				entityname.Trim();
			}	
			NamedEntities[nameid].push_back(entityname);
			//for(; it!=i->children.end(); it++) 
			//{  
			//	evalP21DataEntityIds(it); 
			//}

			OutputDebugString(StrFormat("%s DataEntity %s=%s\n", tabs, nameid, entityname)); ;
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
		if(!vardef->IsListType()) 
			variables.back()=variables.back()+1;
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

	CString sval = std::string(i->value.begin(), i->value.end()).c_str();
	OUTPUT_DEBUG_STRING(StrFormat("%s Enter %s Value=%s\n", tabs, CStep21BoostParser::GetRuleString((CStep21BoostParser::parser_ids)n), sval )); 

	switch(n)
	{

	case CStep21BoostParser::LOGICALTRUEID:
	case CStep21BoostParser::LOGICALFALSEID:
	case CStep21BoostParser::LOGICALUNKWNID:
		{

			CString sval = std::string(i->value.begin(), i->value.end()).c_str();
			OUTPUT_DEBUG_STRING(StrFormat("%s LOGICALTRUEID %s\n", tabs, sval)); 
			//TreeIter it = i->children.begin();
			long nVal = (sval== ".T.") ? 1 : (sval== ".F.") ? 0 : -1; 
			IStepNodePtr instance =   new EInteger(nVal);
			// error check 
			InstanceStore(instance) ;
		}
		goto done;

	case CStep21BoostParser::ENUMID:
		{
			TreeIter it = i->children.begin();
			CString sval = std::string(it->value.begin(), it->value.end()).c_str();
			OUTPUT_DEBUG_STRING(StrFormat("%s ENUMID %s\n", tabs, sval));
			sval.Replace(".","");
			IStepNodePtr step = entities.back();
			CVarDefPtr vardef = step->GetInstanceVar(variables.back());
			OUTPUT_DEBUG_STRING(StrFormat("Enum class is %s\n", vardef->m_sClassname));
			IStepNodePtr pEnum =  CClassGenerators::gClassGenerators.CreateClass(ExpDemangle(vardef->m_sClassname), "");
			EEnum*instance = (EEnum*) pEnum.get();
			instance->SetString2Enum(sval);
			// error check 
			InstanceStore((IStepNodePtr) pEnum) ;
		}
		goto done;	

	case CStep21BoostParser::OmittedParameterID:
		{
			OUTPUT_DEBUG_STRING(StrFormat("%s OMITTED %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); 

			if(entities.size()>0)
			{
				IStepNodePtr step = entities.back();
				CVarDefPtr vardef = step->GetInstanceVar(variables.back());

				if(!vardef->m_bOptional)
				{
					szWarnings+=StrFormat("Entity \"%s\" Variable \"%s\" Omitted Value - ?????.\n", entities.back()->Classname(), vardef->_sName);
				}
			}
			InstanceStore(NULL) ; // value will be derived inside entity...
		}
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
		}
		goto done;

	case CStep21BoostParser::EntityReferenceID:
		{
			TreeIter it = i->children.begin();
			it = it->children.begin();
			CString nameid = std::string(it->value.begin(), it->value.end()).c_str();
			IStepNodePtr step = entities.back();
			OUTPUT_DEBUG_STRING(StrFormat("%s Store EntityReference %s\n", tabs, nameid));

			// Compile in debugbreak 
			if(nameid=="#126")
			{
				//DebugBreak();
			}

			std::vector<IStepNodePtr> pNodes= entityInstances[nameid]; 
			if(pNodes.size() ==1)
			{
				InstanceStore(pNodes[0]) ;
			}
			else
			{
				InstanceStore(pNodes.back()) ; // we will work out the complex stuff in the related ComplexEntityInstanceID branch

			}
		}
		goto done;


	case CStep21BoostParser::STRINGID:
		{
			TreeIter it = i->children.begin();
			CString s = std::string(it->value.begin(), it->value.end()).c_str();
			OUTPUT_DEBUG_STRING(StrFormat("%s STRING = %s\n", tabs,s)); 
			// Remove beginning and trailing quote '
			s=s.Mid(1);
			s=s.Left(s.GetLength()-1);
			InstanceStore(new EString(s)) ;
		}
		goto done;		

	case CStep21BoostParser::REALID:
	case CStep21BoostParser::INTEGERID:
		{
			TreeIter it = i->children.begin();
			if(entities.size()>0)
			{

				IStepNodePtr step = entities.back();
				CVarDefPtr vardef = step->GetInstanceVar(variables.back());
				// parsed double can be used as integer...
				if(vardef->Type() == integer_)
				{

					OUTPUT_DEBUG_STRING(StrFormat("%s INTEGER= %s\n", tabs, std::string(it->value.begin(), it->value.end()).c_str())); ;
					long nVal = boost::lexical_cast<long>(string(it->value.begin(), it->value.end()));
					InstanceStore(new EInteger(nVal)) ;
				}
				else
				{
					OUTPUT_DEBUG_STRING(StrFormat("%s REAL= %s\n", tabs, std::string(it->value.begin(), it->value.end()).c_str())); ;
					double d = boost::lexical_cast<double>(string(it->value.begin(), it->value.end()));
					InstanceStore(new EReal(d)) ;

				}
			}
		}
		goto done;		

	case CStep21BoostParser::ListID:
		{
			OUTPUT_DEBUG_STRING(StrFormat("%s ListID %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }

			CString token = std::string(i->value.begin(), i->value.end()).c_str();

			if(token==")" && entities.size()>0)
					variables.back()=variables.back()+1;
		}
		goto done;	

	case CStep21BoostParser::TypedParameterID:
		{
			CString token = std::string(i->value.begin(), i->value.end()).c_str();
			OUTPUT_DEBUG_STRING(StrFormat("%s TypedParameter %s \n", tabs, token)); ;

			if(findNode(i, findit, 0, Nodes(nodes, CStep21BoostParser::KEYWORDID,  CStep21BoostParser::IDENTID, CStep21BoostParser::IDENTID, 0)))
			{
				// create new instance
				CString entityname=  std::string(findit->value.begin(), findit->value.end()).c_str();
				entityname.Trim();
				IStepNodePtr step = CClassGenerators::gClassGenerators.CreateClass(entityname, "##");
				InstanceStore(step) ;
				entities.push_back(step);
				variables.push_back(0);

				for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) 
				{  
					storeP21EBNF(it); 
				}
				entities.pop_back();
				variables.pop_back();			
				goto done;
			}	
			if(token==")" )
			{
				//DebugBreak();
			}
		}
		
		break;


	case CStep21BoostParser::HeaderEntityID:
		OUTPUT_DEBUG_STRING(StrFormat("%s HeaderEntity %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		if( i->children.size()>0)
		{
			TreeIter it= i->children.begin()->children.begin();
			CString id = std::string(it->value.begin(), it->value.end()).c_str(); 
			OUTPUT_DEBUG_STRING(StrFormat("%s HeaderEntity %s\n", tabs, id)); 
			if(id=="FILE_DESCRIPTION" || id=="FILE_NAME" || id=="FILE_SCHEMA")
			{
				IStepNodePtr step ;
				// FIXME: if(_gPart21gen==NULL)


				// Look up statically P21 header information.
				if(_gPart21gen!=NULL && id=="FILE_DESCRIPTION")
					step = _gPart21gen->Header()->file_description = new Efile_description ;
				else if(_gPart21gen!=NULL && id=="FILE_NAME")
					step = _gPart21gen->Header()->file_name = new Efile_name ;
				else if(_gPart21gen!=NULL && id=="FILE_SCHEMA")
					step = _gPart21gen->Header()->file_schema = new Efile_schema ;
				if(step!=NULL)
				{

					entities.push_back(step);
					variables.push_back(0);

					for(it= i->children.begin()+1; it!=i->children.end(); it++) 
					{  
						storeP21EBNF(it); 
					}
					entities.pop_back();
					variables.pop_back();
				}
				goto done;	
			}
		}
		break;
	case CStep21BoostParser::ComplexEntityInstanceID:
		{

		}
		goto done;

	case CStep21BoostParser::SimpleEntityInstanceID:
		{
			CString nameid;
			CString entityname;
			CString  str = std::string(i->value.begin(), i->value.end()).c_str();
			TreeIter it= i->children.begin();
			if(findNode(it, findit, 0, Nodes(nodes, CStep21BoostParser::EntityInstanceNameID,   0)))
			{
				nameid=  std::string(findit->value.begin(), findit->value.end()).c_str();
			}	

			it+=2; // skip #n = 
			// could also be USER_DEFINED_KEYWORD or SCOPE
			// it is at  CStep21BoostParser::Simple_RecordID
			if(findNode(it, findit, 0, Nodes(nodes, CStep21BoostParser::KEYWORDID,  CStep21BoostParser::IDENTID, CStep21BoostParser::IDENTID, 0)))
			{
				entityname=  std::string(findit->value.begin(), findit->value.end()).c_str();
			}	

			OUTPUT_DEBUG_STRING(StrFormat("DataEntityID Name=%s Entity=%s\n",  nameid, entityname));

			// should only be one entityinstance for simple entity instance ID...
			if(entityInstances[nameid].back()==NULL)
			{
				// Hasn't been defined.
				OUTPUT_DEBUG_STRING(StrFormat("ERROR CLASS %s HAS NOT BEEN DEFINED\n", nameid));
				::DebugBreak();
				goto done;
			}

			// should only be one entityinstance for simple entity instance ID...
			entities.push_back(entityInstances[nameid].back());
			variables.push_back(0);

			for(; it!=i->children.end(); it++) 
			{  
				storeP21EBNF(it); 
			}
			entities.pop_back();
			variables.pop_back();

			outputfile <<(StrFormat("%s DataEntity %s=%s\n", tabs, nameid, entityname)); ;
		}
		goto done;	

	case CStep21BoostParser::EntityNameID:
		{
			CString str;
			if(findNode(i->children.begin(), findit, 0, Nodes(nodes, CStep21BoostParser::EntityNameID, CStep21BoostParser::EntityNameID, 0)))
			{
				str=  std::string(findit->value.begin(), findit->value.end()).c_str();
			}		
			OUTPUT_DEBUG_STRING(StrFormat("%s EntityName %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		}
		goto done;	

#if 0
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

	case CStep21BoostParser::KEYWORDID:
		{
			OUTPUT_DEBUG_STRING(StrFormat("%s KEYWORD %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
			for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
			break;
		}
	case CStep21BoostParser::ParameterID:
		OUTPUT_DEBUG_STRING(StrFormat("%s ParameterID %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		break;	
	case CStep21BoostParser::Simple_RecordID:
		OUTPUT_DEBUG_STRING(StrFormat("%s Simple_Record %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		break;	
	case CStep21BoostParser::Subsuper_RecordID:
		OUTPUT_DEBUG_STRING(StrFormat("%s Subsuper_Record %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
		break;	
	case CStep21BoostParser::EntityInstanceNameID:
		OUTPUT_DEBUG_STRING(StrFormat("%s Entity_Instance_RHS %s\n", tabs, std::string(i->value.begin(), i->value.end()).c_str())); ;
		for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) {  storeP21EBNF(it); }
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

#endif

	}
	for(TreeIter it = i->children.begin(); it!=i->children.end(); it++) 
	{
		storeP21EBNF(it); 
	}

done:
	OUTPUT_DEBUG_STRING(StrFormat("%s Leave %s VarIndex=%d\n", tabs, CStep21BoostParser::GetRuleString((CStep21BoostParser::parser_ids)n), (variables.size()>0)? variables.back() : -1 )); 
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
	//parse_info<const char*> info =	boost::spirit::parse((const char *) file, parser, skip);
	Eedge_loopPtr edge_loop = new Eedge_loop();
	tree_parse_info<const char*> info =	boost::spirit::pt_parse((const char *) file, parser, skip);
	//		ast_parse((const char *) file, *this, skip);
	if(info.full)
	{
		OutputDebugString("Ini File Parse Succeeded \n");

		evalP21DataEntityIds(info.trees.begin());
		std::map<CString, CStringVector>::iterator it;
		for(it = NamedEntities.begin(); it !=NamedEntities.end(); it++)
		{
			CStringVector instances = (*it).second;
			for(int i=0; i<instances.size(); i++)
			{
				CString szInstance = instances[i];
				OUTPUT_DEBUG_STRING( StrFormat("%s=%s\n", (*it).first, szInstance));
				entityInstances[(*it).first].push_back( CClassGenerators::gClassGenerators.CreateClass(szInstance, (*it).first)) ;
				if(entityInstances[(*it).first].back() == NULL)
				{
					OUTPUT_DEBUG_STRING( StrFormat("%s Entity %s Not Created!\n", (*it).first, szInstance));
					DebugBreak();
				}
			}


		}

		szWarnings.Empty();
		storeP21EBNF(info.trees.begin());
		OutputDebugString(szWarnings);

		CString szStartEntity = ExpMangle(gStartEntity);
		project=NULL;

		for(EntityInstanceIterator eit = entityInstances.begin(); eit !=entityInstances.end(); eit++)
		{
			if((*eit).second.size()==0)
				continue;
			if((*eit).second.back()->m_sClassname==ExpMangle(gStartEntity))
			{
				project = (*eit).second.back();
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
		// FIXME: back out line from stopping point...
		OutputDebugString(StrFormat("Ini File Parse Failed %s\n" , info.stop));
		return E_FAIL;

	}
	return S_OK;

}