   //
// CreateCPPClasses.cpp
//
#include "stdafx.h"
#include "CreateCPPClasses.h"
#include "boost/lexical_cast.hpp"
static CString szNamespace="Express";

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
		headerdeclfile<< StrFormat("class %s : /*select headache*/ \n", type->Name()) ;
		headerdeclfile<<StrFormat("\tpublic EEnum\n");
		headerdeclfile<< StrFormat("{\npublic:\n") ;
		headerdeclfile<<StrFormat("\tCLASSDEF(%s); \n", type->Name());
		headerdeclfile<<StrFormat("\tenum %sEnum\n\t{\n", type->Name());
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
		headerdeclfile<< StrFormat("class %s : /*select headache*/ \n", type->Name()) ;
		headerdeclfile<<StrFormat("\tpublic ESelection\n");
		headerdeclfile<< StrFormat("{\npublic:\n") ;
		headerdeclfile<<StrFormat("\tCLASSDEF(%s); \n", type->Name());

		for(int j=0; j< type->_szSelections.size(); j++)
		{
			headerdeclfile<< StrFormat("\t%sPtr _%s;\n", type->_szSelections[j], type->_szSelections[j]);
		}
		headerdeclfile<< StrFormat("};\n") ;

	}
	else if(type->Type()==typereference_ || type->Type()==real_ || type->Type()==string_ || type->Type()==integer_ || type->Type()==boolean_ || type->Type()==logical_)
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
	headerdeclfile<< StrFormat("class %s :\n\t", entity->Name());
	k=0;
	for(j=0; j<entity->vars.size(); j++)
	{
		CVarDefPtr  var = entity->vars[j];
		if(var->Type()!=special_)
			continue;
		if(k>0) headerdeclfile<<  "," ;
		headerdeclfile<<StrFormat("public  %s\n" , var->Name());
		k++;
	}
	if(k==0)
	{
		headerdeclfile<<StrFormat("\tpublic IStepNode\n");
	}
	headerdeclfile<< StrFormat("{\npublic:\n");
	headerdeclfile<<StrFormat("\tCLASSDEF(%s); \n", entity->Name());
	for(j=0; j<entity->vars.size(); j++)
	{
		CVarDefPtr  var = entity->vars[j];
		if(var->Type()==special_) // already declared as inherited class
			continue;
#if 1
		if(var->Type()==list_ || var->Type()==aggregate_ || var->Type()==bag_ || var->Type()==array_ || var->Type()==set_)
		{
			headerdeclfile<<StrFormat("\t%s %s; \n" , var->m_sClassname, var->Name());
			continue; // specialized non new for now.
		}
		headerdeclfile<<StrFormat("\t%sPtr %s; \n" , var->m_sClassname, var->Name());
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
	for(i=0; i< _symbols._schemas.size(); i++) //  ADD OTHER SCHEMA INCLUDES
		headerdeclfile<< StrFormat("#include \"%sSchemaDeclarations.h\"\n\n", _symbols._schemas[i] );

	headerdeclfile<< StrFormat("#include \"%sSchemaDeclarations.h\"\n\n", szSchemaname );

	headerdeclfile<< StrFormat("namespace %s{\n", szNamespace);
	headerdeclfile<< StrFormat("extern CStringVector GetAll%sEntities();\n", szSchemaname );

	for(i=0; i<_entities.size(); i++)
		_entities[i]->SetVisited(0);
	for(i=0; i<_entities.size(); i++)
		CreateClassDeclarationItem(headerdeclfile, _entities[i]);

	/////////////////////////////////////////////////////
	// Select typedef enumeration and selection class creation 
	for(i=0; i<_types.size(); i++)
		_types[i]->SetVisited(0);
	for(int i=0; i<_types.size(); i++)
		CreateTypeDeclarationItem(headerdeclfile, _types[i]);

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
	for(i=0; i< _symbols._schemas.size(); i++) //  ADD OTHER SCHEMA INCLUDES
		cppImplFile<< StrFormat("#include \"%sClassDefinitions.h\"\n\n", _symbols._schemas[i] );

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
		cppImplFile<< StrFormat("\tm_def.m_pClass=(DWORD)this;\n");
		cppImplFile<< StrFormat("\tClassname()=\"%s\";\n", entity->Name());;
		cppImplFile<< StrFormat("\tm_def.m_pVars=&vars;\n");

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

		cppImplFile<<StrFormat("\tparents.clear(); \n");  // otherwise inherited classes will also initialize
		GenerateBaseClasses(cppImplFile, entity->vars );

		//GenerateSuperclasses();
		cppImplFile<<StrFormat("\tsupertypes.clear(); \n");  // otherwise supertype classes will also initialize
		CStringVector supertypes = this->_entitysuperclassesof[entity->Name()];
		for(j=0; j<supertypes.size(); j++)
			cppImplFile<<StrFormat("\tsupertypes.push_back(\"%s\") ; \n" , supertypes[j]);

		cppImplFile<<StrFormat("\tm_bAbstract=%s ; \n" , entity->m_bAbstract? "true" : "false");

		//cppImplFile<<StrFormat("\tvars.push_back(new CVarDef(this, \"%s\" ,(StepNodeType) %d, (DWORD) this,\"%s\"));\n", 
		//			entity->Name(), this_, entity->Name(), _T("THIS"));

		for(j=0; j<entity->vars.size(); j++)
		{
			CVarDefPtr  var = entity->vars[j];
			if(var->Type()==special_)  // special is inheritance
			{
				cppImplFile<<StrFormat("\tvars.push_back(new CVarDef(this, \"%s\" ,(StepNodeType) %d, (DWORD) &(this->%s::vars),\"%s\"));\n", 
//				cppImplFile<<StrFormat("\tvars.push_back(new CVarDef(this, \"%s\" ,(StepNodeType) %d, (DWORD) static_cast<%s *>( this),\"%s\"));\n", 
					var->Name(),var->Type(), var->Name(), _T("Baseclass"));
				continue;
			}
			// fixme if list type
			cppImplFile<<StrFormat("\tvars.push_back(new CVarDef(this, \"%s\" ,(StepNodeType) %d, (DWORD) &(this->%s), \"%s\", %d));\n", 
				var->Name(), var->Type(), var->Name(), var->m_sClassname, var->m_bOptional   );

			cppImplFile<<StrFormat("\tvars.back()->Init(%d, (StepNodeType)  %d, \"%s\");\n", var->_nDimension, var->m_eListType, var->ListClassname());


		}
		cppImplFile<< StrFormat("\tBuildInstanceDef(vars, instancevars);\n");
		cppImplFile<< StrFormat("} /* End %s*/\n", entity->Name());
#if 0
		CStringVector bases;
		GenerateBaseClasses(entity->vars  , bases);
		cppImplFile<< StrFormat("CStringVector %s::GetInheritanceChain(){ \n", entity->Name());

		cppImplFile<< StrFormat("\tCStringVector v;\n");
		for(int i=0; i< bases.size(); i++)
			cppImplFile<< StrFormat("v.push_back(\"%s\");", bases[i]);
		cppImplFile<< StrFormat("\treturn v;\n");
		cppImplFile<< StrFormat("}/* End GetInheritanceChain()*/ \n");
		//cppImplFile<< StrFormat("CStringVector %s::GetSupertypesChain(){return supertypes; } \n", entity->Name());
#endif
		

		/////////////////////////////////////////////////////
		// Impl Creation of a classes
#if 0
		cppImplFile<< StrFormat("DWORD %s::Create(const char * name)\n", entity->Name());
		cppImplFile<< "{\n";
		cppImplFile<< StrFormat("\t%s * szHeaderFile = new %s();\n", entity->Name(), entity->Name());
		cppImplFile<< "\treturn (DWORD) szHeaderFile;\n";
		cppImplFile<< "}\n";
#endif

	}


	for(int i=0; i<_types.size(); i++)
	{
		IStepNodePtr type = _types[i];
#if 1
		if(_types[i]->Type()==typereference_ || type->Type()==real_ || type->Type()==string_ || type->Type()==integer_ || type->Type()==boolean_ || type->Type()==logical_)
		{

			cppImplFile<< StrFormat("%s::%s()\n{\n ", _types[i]->Name(), _types[i]->Name()) ;
			cppImplFile<< StrFormat("\tthis->_eType= typereference_; \n", _types[i]->Name(), _types[i]->Name()) ;
			cppImplFile<<StrFormat("\tm_def.m_pClass=(DWORD)this;\n");
			cppImplFile<<StrFormat("\tClassname()=\"%s\";\n", _types[i]->Name());
			cppImplFile<<StrFormat("\tm_def.m_pVars=&vars;\n");
			cppImplFile<<StrFormat("\tvars.push_back(new CVarDef(this, \"%s\" ,(StepNodeType) %d, (DWORD) &(this->%s::vars),\"%s\"));\n", 
				_types[i]->Classname(), special_, _types[i]->Classname(), _T("Baseclass"));
			cppImplFile<<StrFormat("\tparents.clear(); \n");  // otherwise inherited classes will also initialize
			cppImplFile<<StrFormat("\tparents.push_back(\"%s\"); \n", _types[i]->Classname());  // otherwise inherited classes will also initialize
			cppImplFile<<StrFormat("}\n");
		//cppImplFile<< StrFormat("CStringVector %s::GetSupertypesChain(){return supertypes; } \n", entity->Name());

		}
#endif
			if(_types[i]->Type()==enumeration_)
		{
			cppImplFile<< StrFormat("%s::%s()\n{\n ", _types[i]->Name(), _types[i]->Name()) ;
			cppImplFile<< StrFormat("\tthis->_eType= enumeration_; \n") ;
			cppImplFile<< StrFormat("\tthis->_nSelection= %d; \n", _types[i]->_enums.size()) ;

			cppImplFile<<StrFormat("\tparents.clear(); \n");  // otherwise inherited classes will also initialize
			cppImplFile<<StrFormat("\tparents.push_back(\"Eenum\"); \n");  // otherwise inherited classes will also initialize
			cppImplFile<<StrFormat("\tsupertypes.clear(); \n");  // otherwise supertype classes will also initialize
			cppImplFile<<StrFormat("\tsupertypes.push_back(\"Eenum\"); \n");  // otherwise supertype classes will also initialize
			
			cppImplFile<<StrFormat("\tm_def.m_pClass=(DWORD)this;\n");
			cppImplFile<<StrFormat("\tClassname()=\"%s\";\n", _types[i]->Name());
			cppImplFile<<StrFormat("\tm_def.m_pVars=&vars;\n", _types[i]->Name());
			cppImplFile<<StrFormat("\tvars.push_back(new CVarDef(this, \"EEnum\" ,(StepNodeType) enumeration_, (DWORD) this,\"Baseclass\"));\n");
			cppImplFile<<StrFormat("}\n");
		//cppImplFile<< StrFormat("CStringVector %s::GetSupertypesChain(){return supertypes; } \n", entity->Name());
		}
		else if(_types[i]->_eType==select_)
		{
			cppImplFile<< StrFormat("\t%s::%s()\n", _types[i]->Name(), _types[i]->Name());
			cppImplFile<< StrFormat("{\n") ;
			
			cppImplFile<<StrFormat("\n\tthis->_eType= select_; \n");


			for(int j=0; j< _types[i]->_szSelections.size(); j++)
			{
				CString szVarname = StrFormat("_%s", _types[i]->_szSelections[j]);
				// cyclic definitions cause new havoc
				//cppImplFile<< StrFormat("\t%s = new %s;\n", szVarname, _types[i]->_szSelections[j]);
				StepNodeType t = _symbols.FindVarType( _types[i]->_szSelections[j]);
				cppImplFile<<StrFormat("\tvars.push_back(new CVarDef(this, \"%s\" ,(StepNodeType) %d, (DWORD) &(this->%s),\"%s\"));\n", 
					szVarname, t, szVarname, szVarname);
				if(j==0)
					cppImplFile<<StrFormat("\n\tSetSelection(%s); \n", szVarname);
			}
			cppImplFile<< StrFormat("}\n") ;
		//	cppImplFile<< StrFormat("CStringVector %s::GetSupertypesChain(){return supertypes; } \n", entity->Name());

		}
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
	cppImplFile<<StrFormat("static int cCcCc = gClassGenerators.AddGenerator(&Create%sClass);\n", szSchemaname); 

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
