//
// CreateCPPClasses.cpp
//
#include "stdafx.h"
#include "CreateCPPClasses.h"
#include "boost/lexical_cast.hpp"
static CString szNamespace="Express";

// not sure about #defines. Guess you can undefine them...
static CStringVector cppkeywords(CString("asm"), CString("auto"), CString("bool"), CString("break"), 
								 CString("case"), CString("catch"),   
								 CString("char"), CString("class"), CString("const"), CString("const_cast"), CString("continue"),		
								 CString("default"), CString("delete"), CString("do"), CString("double"), CString("dynamic_cast"),	
								 CString("else"), CString("enum"), CString("explicit"), CString("export"), CString("extern"), CString("false"),   
								 CString("float"), CString("for"), CString("friend"), CString("goto"), CString("if"), CString("inline"), CString("int"),  
								 CString("long"), CString("mutable"), CString("namespace"), CString("new"), CString("operator"), CString("private"),   
								 CString("protected"), CString("public"), CString("register"), CString("reinterpret_cast"), CString("return"), 
					 			 CString("short"), CString("signed"), CString("sizeof"), CString("static"), CString("static_cast"), CString("struct"),   
								 CString("switch"), CString("template"), CString("this"), CString("throw"), CString("true"), CString("try"),  
								 CString("typedef"),  CString("typeid"), CString("typename"), CString("union"), CString("unsigned"),  
								 CString("using"), CString("virtual"),  CString("void"), CString("volatile"), CString("wchar_t"), CString("while"), 
								 CString("pascal"),  CString("sealed"), CString("safecast") , CString("nullptr"),  // microsoft nullptr
								 CString("nothrow"),  CString("noreturn"), CString("novtable") , CString("noinline"),  // microsoft nullptr
								 CString("interface"),  CString("gcnew"), CString("generic") , CString("finally"),  // microsoft nullptr
								 CString("deprecated"),  CString("delegate"), CString("dllexport") , CString("dllimport"),  // microsoft nullptr
								 CString("abstract"),  CString("array"),   // microsoft nullptr
								 CString() ); 

static CString Sanitize(CString keyword)
{
	CStringVector::iterator it = std::find(cppkeywords.begin(), cppkeywords.end(), keyword);
	if(it == cppkeywords.end())
		return keyword;
	return "E__" + keyword;  // allow us to figure out that it is bad later

}
///////////////////
class CStepNodeTypes
{
public:
	static std::map<StepNodeType, CString> StepNodeTypes;
	static int Setup()
	{
		StepNodeTypes[unknown_] = "unknown_";	
		StepNodeTypes[special_] = "special_";	
		StepNodeTypes[this_] = "this_";	
		StepNodeTypes[integer_] = "integer_";	
		StepNodeTypes[real_] = "real_";	
		StepNodeTypes[string_] = "string_";	
		StepNodeTypes[binary_] = "binary_";	
		StepNodeTypes[boolean_] = "boolean_";	
		StepNodeTypes[logical_] = "logical_";	
		StepNodeTypes[number_] = "number_";	
		StepNodeTypes[generic_] = "generic_";	
		StepNodeTypes[aggregate_] = "aggregate_";	
		StepNodeTypes[array_] = "array_";	
		StepNodeTypes[bag_] = "bag_";	
		StepNodeTypes[set_] = "set_";	
		StepNodeTypes[list_] = "list_";	
		StepNodeTypes[list_item_] = "list_item_";	
		StepNodeTypes[oneof_] = "oneof_";	
		StepNodeTypes[entity_] = "entity_";	
		StepNodeTypes[entity_list_] = "entity_list_";	
		StepNodeTypes[enumeration_] = "enumeration_";	
		StepNodeTypes[select_] = "select_";	
		StepNodeTypes[reference_] = "reference_";	
		StepNodeTypes[query_] = "query_";	
		StepNodeTypes[op_] = "op_";	
		StepNodeTypes[inverse_] = "inverse_";	
		StepNodeTypes[identifier_] = "identifier_";	
		StepNodeTypes[attribute_] = "attribute_";	
		StepNodeTypes[derived_] = "derived_";	
		StepNodeTypes[funcall_] = "funcall_";	
		StepNodeTypes[vardef_] = "vardef_";	
		StepNodeTypes[typereference_] = "typereference_";	
		StepNodeTypes[underlying_type_] = "underlying_type_";	
		StepNodeTypes[constant_] = "constant_";	
		StepNodeTypes[index_] = "index_";	
		StepNodeTypes[rename_] = "rename_";	
		StepNodeTypes[typelist_] = "typelist_";	
		StepNodeTypes[typemultilist_] = "typemultilist_";	
		return 0;
	}
	CString Get(StepNodeType type) { return StepNodeTypes[type]; }

};

static CStepNodeTypes _StepNodeTypes;
std::map<StepNodeType, CString> CStepNodeTypes::StepNodeTypes;
static int dummy___ = CStepNodeTypes::Setup();
///////////////////

CCreateCPPClasses::CCreateCPPClasses(SymbolTable &symbols) 
:
_symbols(symbols),
_namedentities(symbols.NamedEntities()) , 
_entities( symbols.Entities()) , 
_namedtypes(symbols.NamedTypes()),
_types(symbols.Types()),
_entitysuperclassesof(symbols.EntitySuperClassesof())
{	

}

void CCreateCPPClasses::CreateHeaderDeclarationFile(CString szSchemaname)
{
	std::fstream headerdeclfile;

	NamedEntityIterator it;
	CString szFilename= StrFormat("%sSchemaDeclarations.h", GetExeDirectory() + szSchemaname );

	headerdeclfile.open (szFilename, std::fstream::out );

	headerdeclfile<< StrFormat("//\n//\n//\n#pragma once\n\n");
	headerdeclfile<< StrFormat("namespace %s{\n", szNamespace);

	/////////////////////////////////////////////////////
	// class declarations
	for(it= _namedentities.begin(); it!=_namedentities.end(); it++)
	{
		headerdeclfile<< StrFormat("class %s;\n", (*it).first);
		headerdeclfile<< StrFormat("EXP_DECLARE_SMARTPOINTER(%s);\n\n", (*it).first);   
	}
	/////////////////////////////////////////////////////
	// type definitions
	for(int i=0; i<_types.size(); i++)
		_types[i]->SetVisited(0);

	for(int i=0; i<_types.size(); i++)
	{
		headerdeclfile<< StrFormat("class %s ; \n", _types[i]->Name()) ;
		headerdeclfile<< StrFormat("EXP_DECLARE_SMARTPOINTER(%s);\n\n", _types[i]->Name());   
		//CreateTypeDeclarationItem(headerdeclfile,_types[i]);

	}
	/////////////////////////////////////////////////////
	// List enumerations...?
#if 0
	headerdeclfile<< StrFormat("enum {\n");
	for(std::map<CString,int>::iterator eit=_enums.begin(); eit!=_enums.end(); eit++)
	{
		if(eit!=_enums.begin()) headerdeclfile<< StrFormat(",\n\t");
		headerdeclfile<< StrFormat("%s", (*eit).first);
	}
	headerdeclfile<< StrFormat("};\n");
#endif 


	/////////////////////////////////////////////////////

	headerdeclfile<< StrFormat("} /* End namespace %s*/\n", szNamespace);

	headerdeclfile.close();

}

void CCreateCPPClasses::CreateTypeDeclarationItem(std::fstream &headerdeclfile, IStepNodePtr type)
{
	if(type==NULL) // probably an entity typedef
		return;
	if(type->GetVisited())
		return;

	if(type->Type()==enumeration_)
	{
		headerdeclfile<< StrFormat("class %s : /*enumeration*/ \n", type->Name()) ;
		headerdeclfile<<StrFormat(		"\tpublic EEnum\n");
		headerdeclfile<< StrFormat("{\npublic:\n") ;
		headerdeclfile<<StrFormat("		\tCLASSDEF(%s); \n", type->Name());
		headerdeclfile<<StrFormat("		\tenum %sEnum\n\t{\n", type->Name());
		for(int j=0; j< type->_enums.size(); j++)
		{	
			if(j>0)  headerdeclfile<< ",\n";
			headerdeclfile<<StrFormat("\t%s", type->_enums[j]);
			if(j==0)  headerdeclfile<< "=0";
		}
		headerdeclfile<< StrFormat("} ;\n", type->Name()) ;
		headerdeclfile<<StrFormat("\tvoid SetSelection(%sEnum nSelection) {   _nSelection=(int) nSelection;; }\n", type->Name());

		headerdeclfile<< StrFormat("\tvirtual CString GetEnum2String(int e) {\n",  type->Name()) ;
		headerdeclfile<< StrFormat("\t\tstatic int nEnums = %d;\n", type->_enums.size()) ;
		headerdeclfile<< StrFormat("\t\tstatic char * szEnums[%d]={\n", type->_enums.size()) ;
		for(int j=0; j< type->_enums.size(); j++)
		{	
			if(j>0)  headerdeclfile<< ",\n";
			headerdeclfile<<StrFormat("\"%s\"", type->_enums[j]);
		}			
		headerdeclfile<< StrFormat("};\n\tif(e>=nEnums) return \"$\"; return szEnums[(int) e];\n\t}\n") ;

		headerdeclfile<< StrFormat("\tvirtual long GetString2Enum(CString szEnum) {\n",  type->Name()) ;
		headerdeclfile<< StrFormat("\t\tszEnum.MakeLower();\n") ;
		headerdeclfile<< StrFormat("\t\tstatic int nEnums = %d;", type->_enums.size()) ;
		headerdeclfile<< StrFormat("\t\tfor(int i=0; i<nEnums; i++){\n");
		headerdeclfile<< StrFormat("\t\t\tif(GetEnum2String(i)==szEnum) return i; \n\t}\n") ;
		headerdeclfile<< StrFormat("\t\treturn 0;\n\t}\n") ;

		headerdeclfile<< StrFormat("};\n") ;

	}
	else if(type->_eType==select_)
	{
		headerdeclfile<< StrFormat("class %s : /*select*/ \n", type->Name()) ;
		headerdeclfile<<StrFormat("\tpublic ESelection\n");
		headerdeclfile<< StrFormat("{\npublic:\n") ;
		headerdeclfile<<StrFormat("\tCLASSDEF(%s); \n", type->Name());

		for(int j=0; j< type->_szSelections.size(); j++)
		{
			headerdeclfile<< StrFormat("\t%sPtr _%s;\n", type->_szSelections[j], type->_szSelections[j]);
		}
		headerdeclfile<< StrFormat("};\n") ;

	}
	else if(type->Type()==typelist_ || type->Type()== typemultilist_)
	{
		headerdeclfile<< StrFormat("class %s : public %s /*typedef to list or multilist*/\n", 
			type->Name(), type->m_sClassname);
		headerdeclfile<< StrFormat("{\npublic:\n") ;

		headerdeclfile<<StrFormat("\tCLASSDEF(%s); \n", type->Name());
		headerdeclfile<< StrFormat("};\n") ;
		type->SetVisited(true);

	}

	else if(type->Type()==typereference_ || type->Type()==real_ || type->Type()==string_ || type->Type()==integer_ || type->Type()==number_ || type->Type()==boolean_ || type->Type()==logical_)
	{
		// Declare parent first
		CString szParent = type->m_sClassname; // parent's name
		if(!(szParent=="Einteger" || szParent =="Estring"  || szParent =="Ereal" || szParent =="Eboolean" || szParent =="Elogical"))
			CreateTypeDeclarationItem(headerdeclfile,	_namedtypes[type->m_sClassname]);

		headerdeclfile<< StrFormat("class %s : public %s /*typedef*/\n",  type->Name(), type->m_sClassname);
		headerdeclfile<< StrFormat("{\npublic:\n") ;

		headerdeclfile<<StrFormat("\tCLASSDEF(%s); \n", type->Name());
		headerdeclfile<< StrFormat("};\n") ;
		type->SetVisited(true);

	}
}

static bool cmp(const IStepNodePtr  a, const IStepNodePtr b)
{
	return a->_sName < b->_sName;
}

void CCreateCPPClasses::CreateClassDeclarationItem(std::fstream &headerdeclfile, IStepNodePtr entity)
{
	int j,k;
	if(entity==NULL)
	{
		//DebugBreak();
		// Entity from other schema - how to handle?
		return;

	}
	if(entity->GetVisited())
		return;
	// Declare parents first
	for(j=0; j<entity->vars.size(); j++)
	{
		CVarDefPtr var = entity->vars[j];
		if(var->Type()==special_)
		{
			CreateClassDeclarationItem(headerdeclfile,	_namedentities[var->Name()]);
		}
	}
	// Now declare entity
	headerdeclfile<< StrFormat("class %s : public IStepNode\n", entity->Name());


	headerdeclfile<< StrFormat("{\npublic:\n");

	headerdeclfile<<  "//// Inherited classes \n" ;
	k=0;
	for(j=0; j<entity->vars.size(); j++)
	{
		CVarDefPtr  var = entity->vars[j];
		if(var->Type()!=special_)
			continue;
		
		headerdeclfile<<StrFormat("\t%s _%s;\n" , var->Name(), ExpDemangle(var->Name()));
	}


	headerdeclfile<<StrFormat("\tCLASSDEF(%s); \n", entity->Name());
	for(j=0; j<entity->vars.size(); j++)
	{
		CVarDefPtr  var = entity->vars[j];
		if(var->Type()==special_) // already declared as inherited class
			continue;
#if 1
		if(var->Type()==list_ || var->Type()==aggregate_ || var->Type()==bag_ || var->Type()==array_ || var->Type()==set_)
		{
			headerdeclfile<<StrFormat("\t%s %s; \n" , var->m_sClassname, Sanitize(var->Name()));
			continue; // specialized non new for now.
		}
		headerdeclfile<<StrFormat("\t%sPtr %s; \n" , var->m_sClassname, Sanitize(var->Name()));
#else
		if(var->Type()==entity_) // FIXME: what about select an enumeration, and typedef entities
		{
			//headerdeclfile<<StrFormat("\t%sPtr * %s; \n" , var->m_sClassname, var->Name());
			headerdeclfile<<StrFormat("\t%sPtr %s; \n" , var->m_sClassname, var->Name());
			continue;
		}
		if(var->Type()==reference_)
		{
			StepNodeType t = _symbols.FindVarType(var->m_sClassname);
			if(t==entity_ || t== select_)
			{
				headerdeclfile<<StrFormat("\t%sPtr %s; \n" , var->m_sClassname, var->Name());
				continue;
			}
		}
		headerdeclfile<<StrFormat("\t%s %s; \n" , var->m_sClassname, var->Name());
#endif
	}

	headerdeclfile<< StrFormat("};\n");

	entity->SetVisited(true);
}


void CCreateCPPClasses::CreateClassDeclarationFile(CString szSchemaname)
{
	int i;
	std::fstream headerdeclfile;
	CString szFilename= StrFormat("%sClassDefinitions.h", GetExeDirectory() + szSchemaname );
	headerdeclfile.open (szFilename, std::fstream::out );

	headerdeclfile<< StrFormat("//\n//\n//\n#pragma once\n\n");
	headerdeclfile<< StrFormat("#include \"ExpressUtils.h\"\n", szSchemaname);

	// These declare their own namespaces which will collide with our namespace {}
	//	for(i=0; i< _symbols._schemas.size(); i++) //  ADD OTHER SCHEMA INCLUDES
	//		headerdeclfile<< StrFormat("#include \"%sSchemaDeclarations.h\"\n", _symbols._schemas[i] );

	headerdeclfile<< StrFormat("#include \"%sSchemaDeclarations.h\"\n\n", szSchemaname );

	headerdeclfile<< StrFormat("namespace %s{\n", szNamespace);
	headerdeclfile<<StrFormat("// FIXME: Add ClassGenerators::gClassGenerators.AddGenerator(&Create%sClass);\n", szSchemaname); 
	headerdeclfile<< StrFormat("extern IStepNodePtr Create%sClass(CString classname, CString name) ;\n", szSchemaname);
	headerdeclfile<< StrFormat("extern CStringVector GetAll%sEntities();\n", szSchemaname );

	/////////////////////////////////////////////////////
	// Select typedef enumeration and selection class declaration 
	for(i=0; i<_types.size(); i++)
		_types[i]->SetVisited(0);
	for(int i=0; i<_types.size(); i++)
		CreateTypeDeclarationItem(headerdeclfile, _types[i]);

	/////////////////////////////////////////////////////
	// Entity class declaration 
	for(i=0; i<_entities.size(); i++)
		_entities[i]->SetVisited(0);
	for(i=0; i<_entities.size(); i++)
		CreateClassDeclarationItem(headerdeclfile, _entities[i]);

	headerdeclfile<< StrFormat("} /* End namespace %s*/\n", szNamespace);
	headerdeclfile.close();

}
// generate list of base classes D -|> C --|> B --|> A
void CCreateCPPClasses::GenerateBaseClasses(std::fstream &cppdeclfile, CVarDefs & vars )
{
	for(int j=0; j<vars.size(); j++)
	{
		CVarDefPtr  vardef = vars[j];
		if(vardef==NULL)
			continue;
		if(vardef->Type()!=special_)
			continue;
		cppdeclfile<<StrFormat("\tparents.push_back(\"%s\") ; \n" , vardef->Name());
		IStepNodePtr node = _symbols.FindNamedEntity(vardef->Name())  ;
		if(node!=NULL)
			GenerateBaseClasses(cppdeclfile, node->vars );
	}
}

void CCreateCPPClasses::GenerateBaseClasses(CVarDefs & vars , CStringVector &classes)
{
	for(int j=0; j<vars.size(); j++)
	{
		CVarDefPtr  vardef = vars[j];
		if(vardef==NULL)
			continue;
		if(vardef->Type()!=special_)
			continue;
		classes.push_back(vardef->Name());
		IStepNodePtr node = _symbols.FindNamedEntity(vardef->Name())  ;
		if(node!=NULL)
			GenerateBaseClasses(node->vars,classes );
	}
}

void CCreateCPPClasses::CreateClassImplFile(CString szSchemaname)
{
	int i,j,k;
	std::fstream cppImplFile;
	CString szFilename= StrFormat("%sClassImplementation.cpp", GetExeDirectory() + szSchemaname );
	cppImplFile.open (szFilename, std::fstream::out );

	sort(_entities.begin(), _entities.end(), cmp);

	cppImplFile<< StrFormat("//\n//\n//\n#include \"stdafx.h\"\n");
	cppImplFile<< StrFormat("#include \"ExpressUtils.h\"\n", szSchemaname);
	//	for(i=0; i< _symbols._schemas.size(); i++) //  ADD OTHER SCHEMA INCLUDES
	//		cppImplFile<< StrFormat("#include \"%sClassDefinitions.h\"\n", _symbols._schemas[i] );

	cppImplFile<< StrFormat("#include \"%sClassDefinitions.h\"\n", szSchemaname);
	//	cppImplFile<< StrFormat("using namespace %s;\n", szSchemaname);
	cppImplFile<< StrFormat("namespace %s{\n", szNamespace);

	for(i=0; i<_entities.size(); i++)
	{

		IStepNodePtr entity = _entities[i];
		for(int m=0; m<40; m++) cppImplFile<< "//";
		cppImplFile<< "\n";

		cppImplFile<< StrFormat("%s::%s()", entity->Name(), entity->Name());
		cppImplFile<< "{\n";
		cppImplFile<< StrFormat("\t m_def.m_pClass=(DWORD)this;\n");
		cppImplFile<< StrFormat("\t Classname()=\"%s\";\n", entity->Name());;
		cppImplFile<< StrFormat("\t m_def.m_pVars=&vars;\n");

		for(j=0; j<entity->vars.size(); j++)
		{
			CVarDefPtr  var = entity->vars[j];

			if(var->Type()==special_)
				continue;

			if(var->Type()==list_ || var->Type()==aggregate_ || var->Type()==bag_ || var->Type()==array_ || var->Type()==set_)
			{

				continue;
			}
			if(var->Type()==reference_)
			{
				StepNodeType t = _symbols.FindVarType(var->m_sClassname);
				if(t==list_ || t==aggregate_ || t==bag_ || t==array_ || t==set_)
					continue; // specialized non new for now.
			}
			// no new as express could have cycling construction!!!
			//cppImplFile<<StrFormat("\t%s = new %s();\n", var->Name(), var->m_sClassname );
		}

		cppImplFile<<StrFormat("\t parents.clear(); \n");  // otherwise inherited classes will also initialize
		GenerateBaseClasses(cppImplFile, entity->vars );

		//GenerateSuperclasses();
		cppImplFile<<StrFormat("\t supertypes.clear(); \n");  // otherwise supertype classes will also initialize
		CStringVector supertypes = this->_entitysuperclassesof[entity->Name()];
		for(j=0; j<supertypes.size(); j++)
			cppImplFile<<StrFormat("\t supertypes.push_back(\"%s\") ; \n" , supertypes[j]);

		cppImplFile<<StrFormat("\t m_bAbstract=%s ; \n" , entity->m_bAbstract? "true" : "false");

		//cppImplFile<<StrFormat("\tvars.push_back(new CVarDef(this, \"%s\" ,(StepNodeType) %d, (DWORD) this,\"%s\"));\n", 
		//			entity->Name(), this_, entity->Name(), _T("THIS"));

		for(j=0; j<entity->vars.size(); j++)
		{
			CVarDefPtr  var = entity->vars[j];
			if(var->Type()==special_)  // special is inheritance
			{
				cppImplFile<<StrFormat("\t vars.push_back(new CVarDef(this, \"%s\" ,(StepNodeType) %d, (DWORD) &(this->_%s.vars),\"%s\"));\n", 
					//				cppImplFile<<StrFormat("\tvars.push_back(new CVarDef(this, \"%s\" ,(StepNodeType) %d, (DWORD) static_cast<%s *>( this),\"%s\"));\n", 
					Sanitize(var->Name()),var->Type(), ExpDemangle(var->Name()), _T("Baseclass"));
				continue;
			}
			// fixme if list type
			cppImplFile<<StrFormat("\t vars.push_back(new CVarDef(this, \"%s\" ,(StepNodeType) %d, (DWORD) &(this->%s), \"%s\", %d));\n", 
				Sanitize(var->Name()), var->Type(), Sanitize(var->Name()), var->m_sClassname, var->m_bOptional   );

			cppImplFile<<StrFormat("\t vars.back()->Init(%d, (StepNodeType)  %d, \"%s\");\n", var->_nDimension, var->m_eListType, var->ListClassname());
			if(var->IsListType() && var->vUpperBounds.size() ==1)
			{

				cppImplFile<<StrFormat("\t %s.ListClassname()=\"%s\"; \n", Sanitize(var->Name()), var->ListClassname());
				cppImplFile<<StrFormat("\t %s.ListType()=(StepNodeType)  %d; \n", Sanitize(var->Name()),  var->m_eListType);
			}
		}
		cppImplFile<< StrFormat("\t CStringVector vVisitedClasses;\n");
		cppImplFile<< StrFormat("\t BuildInstanceDef(vars, instancevars, vVisitedClasses);\n");
		cppImplFile<< StrFormat("} /* End %s*/\n", entity->Name());

	}


	// Implement type classes
	for(int i=0; i<_types.size(); i++)
	{
		IStepNodePtr type = _types[i];

		// Type constructor definition
		cppImplFile<< StrFormat("%s::%s()\n", _types[i]->Name(), _types[i]->Name());
		cppImplFile<< StrFormat("{\n") ;
		cppImplFile<<StrFormat("\t m_def.m_pClass=(DWORD)this;\n");
		cppImplFile<<StrFormat("\t m_def.m_pVars=&vars;\n");
		cppImplFile<<StrFormat("\t Classname()=\"%s\";\n", _types[i]->Name());
		cppImplFile<<StrFormat("\t parents.clear(); \n");  // otherwise inherited classes will also initialize
		cppImplFile<<StrFormat("\t supertypes.clear(); \n");  // otherwise supertype classes will also initialize
		cppImplFile<<StrFormat("\t this->Type()= %s; \n", _StepNodeTypes.Get( _types[i]->Type()));
		cppImplFile<<StrFormat("\t this->ListType()= %s; \n", _StepNodeTypes.Get(_types[i]->ListType()));

		if(_types[i]->Type()==typereference_ || type->Type()==real_ || type->Type()==number_  || type->Type()==string_ || type->Type()==integer_ || type->Type()==boolean_ || type->Type()==logical_)
		{
			cppImplFile<< StrFormat("\t this->Type()= typereference_; \n") ; // reaasign?

			cppImplFile<<StrFormat("\t vars.push_back(new CVarDef(this, \"%s\" ,(StepNodeType) %d, (DWORD) &(this->%s::vars),\"%s\"));\n", 
				_types[i]->Classname(), special_, _types[i]->Classname(), _T("Baseclass"));

			cppImplFile<<StrFormat("\t parents.push_back(\"%s\"); \n", _types[i]->Classname());  // otherwise inherited classes will also initialize
		}
		else if(_types[i]->Type()==enumeration_)
		{
			cppImplFile<< StrFormat("\t this->_nSelection= %d; \n", _types[i]->_enums.size()) ;

			cppImplFile<<StrFormat("\t parents.push_back(\"Eenum\"); \n");  // otherwise inherited classes will also initialize
			cppImplFile<<StrFormat("\t supertypes.push_back(\"Eenum\"); \n");  // ??? otherwise supertype classes will also initialize

			cppImplFile<<StrFormat("\t vars.push_back(new CVarDef(this, \"EEnum\" ,(StepNodeType) enumeration_, (DWORD) this,\"Baseclass\"));\n");
		}
		else if(_types[i]->_eType==typelist_ || _types[i]->_eType==typemultilist_)
		{

		}
		else if(_types[i]->_eType==select_)
		{
			for(int j=0; j< _types[i]->_szSelections.size(); j++)
			{
				CString szVarname = StrFormat("_%s", _types[i]->_szSelections[j]);
				// cyclic definitions cause new havoc
				//cppImplFile<< StrFormat("\t%s = new %s;\n", szVarname, _types[i]->_szSelections[j]);
				StepNodeType t = _symbols.FindVarType( _types[i]->_szSelections[j]);
				cppImplFile<<StrFormat("\t vars.push_back(new CVarDef(this, \"%s\" ,(StepNodeType) %d, (DWORD) &(this->%s),\"%s\"));\n", 
					szVarname, t, szVarname, szVarname);
				if(j==0)
					cppImplFile<<StrFormat("\n\t SetSelection(%s); \n", szVarname);
			}

		}
		cppImplFile<< StrFormat("\t CStringVector vVisitedClasses;\n");
		cppImplFile<< StrFormat("\t BuildInstanceDef(vars, instancevars, vVisitedClasses);\n");
		cppImplFile<<StrFormat("}\n");
	}

	/////////////////////////////////////////////////////
	// Dynamic creation of a classes 
	cppImplFile<<StrFormat("IStepNodePtr Create%sClass(CString classname, CString name) \n {\n", szSchemaname);
	cppImplFile<<StrFormat("\tclassname=ExpMangle(classname.MakeLower());\n");
	static char * szBaseClasses[6] = {"integer", "real", "string", "enum", "logical", "boolean" }; 
	//for(i=0; i<6; i++)
	//	cppImplFile<<StrFormat("\tif(classname==\"%s\") return %s::Create(name);\n", ExpMangle(CString(szBaseClasses[i])), ExpMangle(szBaseClasses[i])); 

	for(i=0; i<_entities.size(); i++)
	{
		cppImplFile<<StrFormat("\tif(classname==\"%s\") return %s::Create(name);\n", _entities[i]->Name(), _entities[i]->Name()); 
	}
	for(int i=0; i<_types.size(); i++)
	{
		//if(_types[i]->Name() == "Elabel")
		//	DebugBreak();

		if(_types[i]->Type()==enumeration_)
		{
			cppImplFile<<StrFormat("\tif(classname==\"%s\") return %s::Create(name);\n", _types[i]->Name(), _types[i]->Name()); 

		}
		else if(_types[i]->Type()==typereference_ || _types[i]->Type()==underlying_type_)
		{
			cppImplFile<<StrFormat("\tif(classname==\"%s\") return  (IStepNodePtr) new %s;\n", _types[i]->Name(), _types[i]->Name()); 

		}
		else
		{
			cppImplFile<<StrFormat("\tif(classname==\"%s\") return  (IStepNodePtr) new %s;\n", _types[i]->Name(), _types[i]->Name()); 

		}
	}
	cppImplFile<<StrFormat("\treturn NULL; \n}\n");

	cppImplFile<< StrFormat("\tstatic CStringVector svEntities(%d, \n", _entities.size() );
	for(i=0; i<_entities.size(); i++)
	{
		if(i>0) cppImplFile<< ",\n";
		cppImplFile<<StrFormat("\tCString(\"%s\")", _entities[i]->Name()); 
	}
	cppImplFile<< StrFormat(");\n" );
	cppImplFile<< StrFormat(" CStringVector GetAll%sEntities(){ return svEntities;}\n", szSchemaname );


	cppImplFile<< StrFormat("} /* End namespace %s*/\n", szNamespace);
}
