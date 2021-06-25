//
// Part21Generator.cpp
//
#include "stdafx.h"
#include "Part21Generator.h"

EP21Header::EP21Header()
{


	m_def.m_pClass=(DWORD)this;
	Classname()="EP21Header";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 

	vars.push_back(new CVarDef(this, "file_description" ,(StepNodeType) entity_, (DWORD) &(this->file_description), "Efile_description", 0));
	vars.push_back(new CVarDef(this, "file_name" ,(StepNodeType) entity_, (DWORD) &(this->file_name), "Efile_name", 0));
	vars.push_back(new CVarDef(this, "file_schema" ,(StepNodeType) entity_, (DWORD) &(this->file_schema), "Efile_schema", 0));

#if 0


	vars.push_back(new CVarDef(this, "file_description" ,(StepNodeType) bag_, (DWORD) &(this->file_description), "EList", 0));
	vars.back()->Init(1, (StepNodeType)  string_, "EString");
	vars.push_back(new CVarDef(this, "implementation_level" ,(StepNodeType) 22, (DWORD) &(this->implementation_level), "EString", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");

	vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "EString", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");

	vars.push_back(new CVarDef(this, "timestamp" ,(StepNodeType) 22, (DWORD) &(this->timestamp), "EString", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");

	vars.push_back(new CVarDef(this, "authors" ,(StepNodeType) bag_, (DWORD) &(this->authors), "EList", 0));
	vars.back()->Init(1, (StepNodeType)  string_, "EString");

	vars.push_back(new CVarDef(this, "organizations" ,(StepNodeType) bag_, (DWORD) &(this->organizations), "EList", 0));
	vars.back()->Init(1, (StepNodeType)  string_, "EString");

	vars.push_back(new CVarDef(this, "preprocessor_version" ,(StepNodeType) 22, (DWORD) &(this->preprocessor_version), "EString", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");

	vars.push_back(new CVarDef(this, "originating_system" ,(StepNodeType) 22, (DWORD) &(this->originating_system), "EString", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");

	vars.push_back(new CVarDef(this, "authorisation" ,(StepNodeType) 22, (DWORD) &(this->authorisation), "EString", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");

#endif
	file_description = new Efile_description ;
	file_name = new Efile_name ;
	file_schema = new Efile_schema ;

	file_description->description.push_back(new EString("Nothing yet")); 
	file_description->implementation_level= (Eheader_text *) new EString("1");

	file_name->author.push_back(new EString("Tom Kramer"));
	file_name->author.push_back(new EString("John Michaloski"));
	file_name->organization.push_back(new EString("NIST")); 
	file_name->organization.push_back(new EString("Boeing")); 

	file_name->name= (Eheader_text *) new EString("");
	file_name->preprocessor_version=(Eheader_text *) new EString("");
	file_name->originating_system= (Eheader_text *)new EString("StepNC++");
	file_name->authorization= (Eheader_text *)new EString("");
	
	file_schema->schema_identifiers.push_back((Eschema_name *)  new EString("MILLING_SCHEMA"));
	file_schema->schema_identifiers.push_back((Eschema_name *) new EString("MACHINING_SCHEMA"));

}

/**   Init reinitializes the generations. Resets entity number (n) and clears the lines */	

void CPart21Generator::Init()
{
	n=1;
	lines.clear();
}
CPart21Generator::CPart21Generator()
{
	//m_sImplementation_level=_header->implementation_level->GetVarString(); // "1";
	//m_sPreprocessor_version=_header->preprocessor_version->GetVarString();  //"$";
	//m_sAuthorisation=_header->authorisation->GetVarString(); // "$";
	//m_sOriginating_system=_header->originating_system->GetVarString(); // "Nist STEPNC++";


	Init();
	_header= new EP21Header;
	_vardef = new CVarDef(NULL, "HEADER",entity_, (DWORD) &(this->_header), "EP21Header", 0 );
	vars.push_back(_vardef);
}


//CString CPart21Generator::GenerateList(CString comment, CStringVector & items)
//{
//	CString tmp;
//	tmp.AppendFormat("%-40s", StrFormat("/*%s*/", comment));
//	for(int i=0; i< items.size(); i++)
//	{
//		if(i==0) tmp.AppendFormat("(");
//		if(i>0) tmp.AppendFormat(", ");
//		if(i>0 ) tmp.AppendFormat("%s%-40s", (items[i-1].GetLength()>40 )? "\n": "", " ");
//		tmp.AppendFormat("'%s'", items[i]);
//	}
//	tmp.AppendFormat(" ),\n");
//	return tmp;
//}

CString CPart21Generator::GenerateString(CString s)
{
	if(s=="$") 
		return s;
	return StrFormat("'%s'", s);
}

/**   Generate a string containing all the Part 21 header information up to the FILE_SCHEMA
@return a CString containing the header */	
CString CPart21Generator::GenerateHeader()
{
	time_t rawtime;
	time ( &rawtime );

	_header->file_name->time_stamp= (Eheader_text *) new EString(asctime (localtime ( &rawtime )));
	_header->file_name->time_stamp->val.Replace("\n", "");

	CString tmp;
	tmp.AppendFormat("ISO-10303-21;\n\nHEADER;\n");
	tmp.AppendFormat("FILE_DESCRIPTION(\n");
	tmp.AppendFormat("%-40s %s,\n","/*description*/",_header->file_description->description.GetVarString(",")); 
	tmp.AppendFormat("%-40s %s);\n\n", "/*implementation*/", _header->file_description->implementation_level->GetVarString()) ; 
	tmp.AppendFormat("FILE_NAME(\n");
	tmp.AppendFormat("%-40s %s,\n", "/* name */", _header->file_name->name->GetVarString()) ; 
	tmp.AppendFormat("%-40s %s,\n", "/* time_stamp */",_header->file_name->time_stamp->GetVarString()) ;
	///* author */ ('TOM KRAMER', 'YONG TAK HYUN','JOCHEN WOLF'),
	tmp.AppendFormat("%-40s %s,\n", "authors", _header->file_name->author.GetVarString(",")); 
	tmp.AppendFormat("%-40s %s,\n", "organizations", _header->file_name->organization.GetVarString(",")); 
	tmp.AppendFormat("%-40s %s,\n", "/* preprocessor_version */", _header->file_name->preprocessor_version->GetVarString()) ; 
	tmp.AppendFormat("%-40s %s,\n", "/* originating_system */", _header->file_name->originating_system->GetVarString()) ;
	tmp.AppendFormat("%-40s %s);\n", "/* authorisation */",  _header->file_name->authorization->GetVarString()) ;

	return tmp;
}


/**   Adds an entity (#nnn) or return an entity #nnn if an existing string matches the input string. */	
CString CPart21Generator::AddEntity(CString szEntity, CString szData) 
{ 
	CString szEntitynum;
	szData.Trim();
	szData=szData.Mid(0, szData.GetLength()-1); // remove last comma

	CString szEntry = StrFormat("%s(%s);\n", szEntity.MakeUpper(), szData);
	if(sortedlines.find(szEntry)!=sortedlines.end())
	{
		szEntitynum=sortedlines[szEntry];
	}
	else
	{
		// FIXME check to see if existing entry exists.
		lines[n]= StrFormat("#%d=%s(%s);\n", n, szEntity.MakeUpper(), szData);
		szEntitynum=StrFormat("#%d", n++);

		sortedlines[szEntry]=szEntitynum;
	}

	return szEntitynum;
}

/**   Saves the project StepNC++ StepNode. into the file szFilename  */	

void CPart21Generator::SaveP21(IStepNodePtr project , CString szFilename)
{
#if 0
	CVarDefs &vars=project->GetVarDefs();
	DumpCVarDefs(vars);
#else
	/**   Creates a vardef from StepNC++ project StepNC++ to allow Vardef navigation of project tree.  */	
	CVarDefPtr vardef = new CVarDef(NULL, "#1",entity_, (DWORD) &project, "Eproject", 0 );
	Generate(vardef);
#endif

	outputfile.open (szFilename, std::fstream::out );
	outputfile <<  GenerateHeader();
	outputfile << StrFormat("FILE_SCHEMA(( ");
#if 0
	// add schemas
	for(int i=0; i<m_sSchemas.size(); i++)
	{
		if(i>0)
			outputfile << ", ";
		outputfile << StrFormat("'%s'", m_sSchemas[i]);

	}
#endif
	outputfile << StrFormat("));\nENDSEC;\n\n");

	// Data section header
	outputfile << StrFormat("DATA;\n");
#if 0
	for(std::map<int, CString>::iterator it= lines.begin(); it !=lines.end(); it++)
	{
		outputfile << (*it).second;
	}
#else
	for(std::map<CString, CString>::iterator it= sortedlines.begin(); it !=sortedlines.end(); it++)
	{
		CString str=StrFormat("%-6s = %s", (*it).second, (*it).first);
		//outputfile << (*it).second << "=" << (*it).first;
		outputfile << str;
	}
#endif
	outputfile << StrFormat("ENDSEC;\n");
	outputfile << StrFormat("END-ISO-10303-21;\n");
	// Data section trailer
	outputfile.close();
}

CString CPart21Generator::DumpCVarDefs(CVarDefs &vars)
{
	CString tmp;
	for(int i=0; i<vars.size(); i++)
	{
		CVarDefPtr  vardef = vars[i];
		tmp+=Generate(vardef);
	}
	return tmp;

}

/** Will create a Part 21 entry for an Express item. If primitive or simple type, will generate text. If entity or list of entities will call
DumpCVarDefs on all the entity attribute Vardef definitions.*/	
CString CPart21Generator::Generate(CVarDefPtr  vardef)
{
	CString tmp;
	OUTPUT_DEBUG_STRING(StrFormat("ENTER: Item = %s Class = %s Type=%d\n",   vardef->Name(),   vardef->m_sClassname, vardef->Type()));
	if(vardef==NULL)
	{
		OUTPUT_DEBUG_STRING("!!!!!!!Bad vardef\n");
	}

	if(vardef->Type() == 	integer_)
	{
		EInteger * nVal=  * (EInteger **) vardef->m_ref;
		if(nVal==NULL)
		{
			if(!vardef->m_bOptional)
				OUTPUT_ERROR_STRING(StrFormat("PROBLEM with %s logical or boolean\n", vardef->Name()));
			tmp.AppendFormat("$, ");
			goto done;
		}	
		tmp.AppendFormat("%d, ",  nVal->val);
	}
	else if(vardef->Type() == 	logical_ ||  vardef->Type() == 	boolean_)
	{
		EInteger * iVal= * (EInteger **) vardef->m_ref;
		if(iVal==NULL)
		{
			if( !vardef->m_bOptional)
				OUTPUT_ERROR_STRING(StrFormat("PROBLEM with %s logical or boolean\n", vardef->Name()));
			tmp.AppendFormat("$, ");
			goto done;
		}	

		long val = iVal->val;
		CString str = (val==0) ? "FALSE" : (val==1) ? "TRUE" : "UNKOWN"; 
		tmp.AppendFormat(".%s., ",  str);
		//tmp.AppendFormat("%s", str);
	}
	else if(vardef->Type() == 	typereference_)
	{
		IStepNodePtr step=  *(IStepNode **) vardef->m_ref;
		if(step!=NULL) 
		{
			CString sz = DumpCVarDefs(step->GetVarDefs());
			tmp.AppendFormat("%s ", sz);

		}
		else
			tmp.AppendFormat("$ ");
	}
	else if(vardef->Type() == 	enumeration_)
	{
		EEnum * eVal=  (EEnum *) vardef->m_ref;
		if(eVal==NULL )
		{
			if( !vardef->m_bOptional)
				OUTPUT_ERROR_STRING(StrFormat("PROBLEM with %s empty non-optional logical or boolean\n", vardef->Name()));
			tmp.AppendFormat("$, ");
			goto done;
		}	
		tmp.AppendFormat(".%s., ",  eVal->GetEnum2String(eVal->_nSelection).MakeUpper());
	}
	else if(vardef->Type() == 	real_)
	{
		// optional real not handled properly yet.
		double  rVal= *(double *) vardef->m_ref;
		tmp.AppendFormat("%.3f, ",  rVal);
	}
	else if(vardef->Type() == 	select_)
	{
		ESelection * sVal= *(ESelection **) vardef->m_ref;
		IStepNodePtr pSel =sVal-> GetSelection();
		CString szenum = DumpCVarDefs(pSel->GetVarDefs());
		tmp.AppendFormat("%s, ", szenum);
	}
	else if(vardef->Type() == 	string_)
	{
		CString * s= (CString *)vardef->m_ref;
		if(s==NULL)
		{
			if(!vardef->m_bOptional)
				OUTPUT_ERROR_STRING(StrFormat("PROBLEM with %s empty non-optional string\n", vardef->Name()));
			tmp.AppendFormat("$, ");
			goto done;
		}
		tmp.AppendFormat("\'%s\', ", *s);
	}
	else if(vardef->Type() == 	entity_  || (vardef->Type() == 	reference_) )
	{
		IStepNodePtr step=  *(IStepNode **) vardef->m_ref;
		if(step!=NULL) 
		{
			int n;
			CString sz = DumpCVarDefs(step->GetVarDefs());

			// Note can be an empty defintion entity.
			CString szClassname = ExpDemangle(step->m_sClassname);
			if(szClassname.GetLength()< 1) // typedef's don't have classnames for now...
				szClassname= ExpDemangle(vardef->m_sClassname);
			if(step->IsKindOf("Eenum") )
			{
				tmp.AppendFormat("%s ", sz);
			}
			else if( step->m_sClassname == "Einteger" 
				||  step->m_sClassname == "Ereal"  
				|| step->m_sClassname == "Estring" 
				|| step->m_sClassname == "Eenum")
			{
				tmp.AppendFormat("%s", sz);

			}

			else
			{
				CString szNumId = AddEntity(szClassname, sz) ;
				tmp.AppendFormat("%s, ", szNumId);
			}


		}
		else
			tmp.AppendFormat("$, ");

	}
	else if(vardef->Type() == 	special_)
	{
		tmp.AppendFormat("%s", DumpCVarDefs((CVarDefs) *(CVarDefs*)vardef->m_ref));
	}
	else if(vardef->Type() == 	bag_ )
	{
		tmp.AppendFormat("(");
		if(vardef->_nDimension==1)
		{
			EListT<IStepNodePtr > &list= *(EListT<IStepNodePtr > *)  vardef->m_ref;
			CString szClassname = ExpDemangle(vardef->_sListClassname);
			if(list.size()>0)
			{

				CString sz;
				if(IsSimpleType(list.m_eListType))
				{
					tmp+=list.GetVarString(",");
				}
				else
				{
					for (int i = 0; i<list.size(); i++)
					{
						IStepNodePtr step = list[i] ;
						sz=DumpCVarDefs(step->GetVarDefs());
						// fixme: potential typedef problem...
						CString szClassname = ExpDemangle(step->Classname());
						CString szNumId = AddEntity(szClassname, sz) ;
						tmp.AppendFormat("%s, ", szNumId);

					}
					if( tmp[tmp.GetLength()-1] == ',')
						tmp=tmp.Mid(0,tmp.GetLength()-1); // remove last ,
				}
			}
			tmp.Trim();
			tmp.AppendFormat("), ");

		}
	}
	else if(vardef->Type() == 	set_ || vardef->Type() ==  list_)
	{
		//		std::vector<IStepNC *> * items=(std::vector<IStepNC *> *)  vars[i].m_ref;
		tmp.AppendFormat("(");
		if(vardef->_nDimension==1)
		{

			// FIXME: if primitive array or is-kind of primitive (real, int, string) collapse definition?
			std::vector<IStepNodePtr > &list= *(std::vector<IStepNodePtr> *)  vardef->m_ref;
			//IStepNodePtr step=  *(IStepNode **) vardef->m_ref;
			CString szClassname = ExpDemangle(vardef->_sListClassname);
			if(list.size()>0)
			{

				CString sz;
				for (int i = 0; i<list.size(); i++)
				{
					IStepNodePtr step = list[i] ;
					sz=DumpCVarDefs(step->GetVarDefs());
					if(step->IsSimpleType())
					{
						tmp.AppendFormat("%s", sz);
					}
					else
					{
						// fixme: potential typedef problem...
						CString szClassname = ExpDemangle(step->Classname());
						CString szNumId = AddEntity(szClassname, sz) ;
						tmp.AppendFormat("%s, ", szNumId);

					}
				}
			}
		}
		else  if(vardef->_nDimension==2)
		{
			std::vector< std::vector<IStepNodePtr > > &list = *( std::vector< std::vector<IStepNodePtr > > *) vardef->m_ref;
			CString sz;
			for (int i = 0; i<list.size(); i++)
			{
				// how to distinguish  new row/col items
				for (int j = 0; j<list[i].size(); j++) 
				{
					IStepNodePtr step = list[i][j] ;
					tmp.AppendFormat("%s", DumpCVarDefs(step->GetVarDefs()));
				}
			}
		}
		else if(vardef->_nDimension>2)
		{
			OUTPUT_DEBUG_STRING("Too many list dimensions\n");
			::DebugBreak();
		}
		tmp.Trim();
		if( tmp[tmp.GetLength()-1] == ',')
			tmp=tmp.Mid(0,tmp.GetLength()-1); // remove last ,
		tmp.AppendFormat("), ");


	}
	else
	{
		::DebugBreak();
	}
	OUTPUT_DEBUG_STRING(StrFormat("EXIT: Item = %s Class = %s\n",   vardef->Name(),   vardef->m_sClassname));
done:
	return tmp;

}


void CPart21Generator::CompileCVarDefs(CVarDefs &vars ,CErrPairs & errs,  CString chain)
{
	CString tmp;
	for(int i=0; i<vars.size(); i++)
	{
		CVarDefPtr  vardef = vars[i];
		Compile(vardef, errs, chain);
	}

}

void CPart21Generator::Compile(CVarDefPtr  vardef, CErrPairs & errs, CString chain)
{
	CString tmp;
	//OUTPUT_DEBUG_STRING(StrFormat("ENTER: Item = %s Class = %s Type=%d\n",   vardef->Name(),   vardef->m_sClassname, vardef->Type()));
	if(vardef==NULL)
	{
		OUTPUT_DEBUG_STRING("!!!!!!!Bad vardef\n");
	}

	if(vardef->IsSimpleType())
	{
		CString val = vardef->GetVarString();
		if(val=="$" && !vardef->m_bOptional)
		{
			 errs.push_back(CErrPair(vardef, StrFormat("Non-optional %s/%s \n", chain, vardef->Name())));
			 return;
		}

	}
	else if(vardef->Type() == 	special_)
	{
		CompileCVarDefs((CVarDefs) *(CVarDefs*)vardef->m_ref, errs, chain + "/"+ vardef->Name());
	}
	else if(vardef->Type() == 	typereference_)
	{
		IStepNodePtr step=  *(IStepNode **) vardef->m_ref;
		if(step!=NULL) 
		{
			CompileCVarDefs(step->GetVarDefs(), errs, chain + "/"+ vardef->Name());

		}
		else if(!vardef->m_bOptional)
		{
			 errs.push_back(CErrPair(vardef, StrFormat("Non-optional %s/%s \n", chain, vardef->Name())));
			 return;			
		}
	}

	else if(vardef->Type() == 	select_)
	{
		ESelection * sVal= *(ESelection **) vardef->m_ref;
		IStepNodePtr pSel =sVal-> GetSelection();
		CompileCVarDefs(pSel->GetVarDefs(), errs, chain + "/"+ vardef->Name());
	}

	else if(vardef->Type() == 	entity_  || (vardef->Type() == 	reference_) )
	{
		IStepNodePtr step=  *(IStepNode **) vardef->m_ref;
		if(step!=NULL) 
		{
			return  CompileCVarDefs(step->GetVarDefs(),errs,  chain + "/"+ vardef->Name());


		}
		else if(!vardef->m_bOptional)
		{
			 errs.push_back(CErrPair(vardef, StrFormat("Non-optional %s/%s \n", chain, vardef->Name())));
			 return;
			
		}

	}

	else if(vardef->IsListType() && ! vardef->IsSimpleListType())
	{
		if(vardef->_nDimension==1)
		{
			EListT<IStepNodePtr > &list= *(EListT<IStepNodePtr > *)  vardef->m_ref;
			for (int i = 0; i<list.size(); i++)
			{
				IStepNodePtr step = list[i] ;
				CompileCVarDefs(step->GetVarDefs(), errs, chain + "/"+ StrFormat("%s[%d]", vardef->Name(), i));
			}

		}
		return;
	}
	else if(vardef->IsSimpleListType())
	{

	}
	else
	{
		::DebugBreak();
	}
	//OUTPUT_DEBUG_STRING(StrFormat("EXIT: Item = %s Class = %s\n",   vardef->Name(),   vardef->m_sClassname));
done:
	return ;

}

////////////////////////////////////////////////////////////////////////////////
namespace Express{
////////////////////////////////////////////////////////////////////////////////
Efile_description::Efile_description(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Efile_description";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "description" ,(StepNodeType) 13, (DWORD) &(this->description), "EListT<EStringPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  5, "EString");
	description.ListClassname()="EString"; 
	description.ListType()=(StepNodeType)  5; 
	vars.push_back(new CVarDef(this, "implementation_level" ,(StepNodeType) 22, (DWORD) &(this->implementation_level), "Eheader_text", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	CStringVector vVisitedClasses;
	BuildInstanceDef(vars, instancevars,vVisitedClasses);
} /* End Efile_description*/
////////////////////////////////////////////////////////////////////////////////
Efile_name::Efile_name(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Efile_name";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "name" ,(StepNodeType) 22, (DWORD) &(this->name), "Eheader_text", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "time_stamp" ,(StepNodeType) 22, (DWORD) &(this->time_stamp), "Eheader_text", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "author" ,(StepNodeType) 13, (DWORD) &(this->author), "EListT<EStringPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  5, "EString");
	author.ListClassname()="EString"; 
	author.ListType()=(StepNodeType)  5; 
	vars.push_back(new CVarDef(this, "organization" ,(StepNodeType) 13, (DWORD) &(this->organization), "EListT<EStringPtr>", 0));
	vars.back()->Init(1, (StepNodeType)  5, "EString");
	organization.ListClassname()="EString"; 
	organization.ListType()=(StepNodeType)  5; 
	vars.push_back(new CVarDef(this, "preprocessor_version" ,(StepNodeType) 22, (DWORD) &(this->preprocessor_version), "Eheader_text", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "originating_system" ,(StepNodeType) 22, (DWORD) &(this->originating_system), "Eheader_text", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	vars.push_back(new CVarDef(this, "authorization" ,(StepNodeType) 22, (DWORD) &(this->authorization), "Eheader_text", 0));
	vars.back()->Init(0, (StepNodeType)  0, "");
	CStringVector vVisitedClasses;
	BuildInstanceDef(vars, instancevars, vVisitedClasses);
} /* End Efile_name*/
////////////////////////////////////////////////////////////////////////////////
Efile_schema::Efile_schema(){
	m_def.m_pClass=(DWORD)this;
	Classname()="Efile_schema";
	m_def.m_pVars=&vars;
	parents.clear(); 
	supertypes.clear(); 
	m_bAbstract=false ; 
	vars.push_back(new CVarDef(this, "schema_identifiers" ,(StepNodeType) 13, (DWORD) &(this->schema_identifiers), "EListT<Eschema_namePtr>", 0));
	vars.back()->Init(1, (StepNodeType)  22, "Eschema_name");
	schema_identifiers.ListClassname()="Eschema_name"; 
	schema_identifiers.ListType()=(StepNodeType)  22; 
	CStringVector vVisitedClasses;
	BuildInstanceDef(vars, instancevars,vVisitedClasses);
} /* End Efile_schema*/
Eheader_text::Eheader_text()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Eheader_text";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EString" ,(StepNodeType) 1, (DWORD) &(this->EString::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("EString"); 
}
Eschema_name::Eschema_name()
{
 	this->_eType= typereference_; 
	m_def.m_pClass=(DWORD)this;
	Classname()="Eschema_name";
	m_def.m_pVars=&vars;
	vars.push_back(new CVarDef(this, "EString" ,(StepNodeType) 1, (DWORD) &(this->EString::vars),"Baseclass"));
	parents.clear(); 
	parents.push_back("EString"); 
}
static IStepNodePtr Createstepnc_schemaClass(CString classname, CString name) 
 {
	classname=ExpMangle(classname.MakeLower());
	if(classname=="Efile_description") return Efile_description::Create(name);
	if(classname=="Efile_name") return Efile_name::Create(name);
	if(classname=="Efile_schema") return Efile_schema::Create(name);
	if(classname=="Eheader_text") return  (IStepNodePtr) new Eheader_text;
	if(classname=="Eschema_name") return  (IStepNodePtr) new Eschema_name;
	return NULL; 
}
static int cCcCc = CClassGenerators::gClassGenerators.AddGenerator(&Createstepnc_schemaClass);
	static CStringVector svEntities(3, 
	CString("Efile_description"),
	CString("Efile_name"),
	CString("Efile_schema"));
 CStringVector GetAllPart21_schemaEntities(){ return svEntities;}
} /* End namespace Express*/
