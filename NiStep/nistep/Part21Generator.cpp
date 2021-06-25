//
// Part21Generator.cpp
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#include "stdafx.h"
#include "Part21Generator.h"

EP21Header::EP21Header()
{
	Classname()=_T("EP21Header");
	Parents().clear(); 
	Supertypes().clear(); 
	m_bAbstract=false ; 

	m_vars.push_back(new CVarDef(this, _T("file_description") ,(StepNodeType) entity_, (DWORD) &(this->file_description), _T("Efile_description"), 0));
	m_vars.push_back(new CVarDef(this, _T("file_name") ,(StepNodeType) entity_, (DWORD) &(this->file_name), _T("Efile_name"), 0));
	m_vars.push_back(new CVarDef(this, _T("file_schema") ,(StepNodeType) entity_, (DWORD) &(this->file_schema), _T("Efile_schema"), 0));

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

	file_description = new Efile_description ;
	file_name = new Efile_name ;
	file_schema = new Efile_schema ;

	file_description->description.push_back(new EString(_T("Nothing yet")), _T("description")); 
	file_description->implementation_level= (Eheader_text *) new EString(_T("1"));

	file_name->author.push_back(new EString(_T("Tom Kramer")), _T("author"));
	file_name->author.push_back(new EString(_T("John Michaloski")), _T("author"));
	file_name->organization.push_back(new EString(_T("NIST")), _T("organization")); 
	file_name->organization.push_back(new EString(_T("Boeing")), _T("organization")); 

	file_name->name= (Eheader_text *) new EString(_T(""));
	file_name->preprocessor_version=(Eheader_text *) new EString(_T(""));
	file_name->originating_system= (Eheader_text *)new EString(_T("StepNC++"));
	file_name->authorization= (Eheader_text *)new EString(_T(""));
	
	file_schema->schema_identifiers.push_back((Eschema_name *)  new EString(_T("MILLING_SCHEMA")), _T("schema_identifiers"));
	file_schema->schema_identifiers.push_back((Eschema_name *) new EString(_T("MACHINING_SCHEMA")), _T("schema_identifiers"));
#endif

	CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);

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
	_header = new EP21Header;
	_defaultheader = new EP21Header;
	_vardef = new CVarDef(NULL, _T("HEADER"),entity_, (DWORD) &(this->_header), _T("EP21Header"), 0 );
	vars.push_back(_vardef);
}

CString CPart21Generator::GenerateString(CString s)
{
	if(s==_T("$")) 
		return s;
	return StrFormat(_T("'%s'"), s);
}

/**   Generate a string containing all the Part 21 header information up to the FILE_SCHEMA
@return a CString containing the header */	
CString CPart21Generator::GenerateHeader()
{
	time_t rawtime;
	time ( &rawtime );

	_header->file_name->time_stamp= (Eheader_text *) new EString(_tasctime (localtime ( &rawtime )));
	_header->file_name->time_stamp->val.Replace(_T("\n"), _T(""));

	CString tmp;
	tmp.AppendFormat(_T("ISO-10303-21;\n\nHEADER;\n"));
	tmp+=_T("File produced by STEPNC++ software developed by U.S. Government employees as part of\n")
		_T("their official duties and is not subject to copyright. No warranty implied or intended.\n") ;

	// /bug fixme: uses all links to get values. If any link fails, disaster.
	tmp.AppendFormat(_T("FILE_DESCRIPTION(\n"));
#if 0
	tmp.AppendFormat(_T("%-40s %s,\n"),_T("/*description*/"),_header->file_description->description.IStepNode::GetVarString(_T(","))); 
	tmp.AppendFormat(_T("%-40s %s);\n\n"),_T( "/*implementation*/"), _header->file_description->implementation_level->IStepNode::GetVarString()) ; 
	tmp.AppendFormat(_T("FILE_NAME(\n"));
	tmp.AppendFormat(_T("%-40s %s,\n"), _T("/* name */"), _header->file_name->name->IStepNode::GetVarString()) ; 
	tmp.AppendFormat(_T("%-40s %s,\n"), _T("/* time_stamp */"),_header->file_name->time_stamp->IStepNode::GetVarString()) ;
	tmp.AppendFormat(_T("%-40s %s,\n"), _T("/*authors*/"), _header->file_name->author.GetVarString(_T(","))); 
	tmp.AppendFormat(_T("%-40s %s,\n"), _T("/*organizations*/"), _header->file_name->organization.IStepNode::GetVarString(_T(","))); 
//	tmp.AppendFormat(_T("%-40s %s,\n"), _T("/* preprocessor_version */"), _header->file_name->preprocessor_version->IStepNode::GetVarString()) ; 
	tmp.AppendFormat(_T("%-40s %s,\n"), _T("/* preprocessor_version */"), _T("NIST STEPNC++ V1.2")) ; 
	tmp.AppendFormat(_T("%-40s %s,\n"), _T("/* originating_system */"), _header->file_name->originating_system->IStepNode::GetVarString()) ;
	tmp.AppendFormat(_T("%-40s %s);\n"), _T("/* authorisation */"),  _header->file_name->authorization->IStepNode::GetVarString()) ;
#endif
	tmp.AppendFormat(_T("%-40s %s,\n"),_T("/*description*/"),_header->GetAttributeValue(_T("file_description/description"))); 
	tmp.AppendFormat(_T("%-40s %s);\n\n"),_T( "/*implementation*/"), (LPCTSTR) _header->GetAttributeValue(_T("file_description/implementation_level"))) ; 
	tmp.AppendFormat(_T("FILE_NAME(\n"));
	tmp.AppendFormat(_T("%-40s %s,\n"), _T("/* name */"), _header->GetAttributeValue(_T("file_name/name"))) ; 
	tmp.AppendFormat(_T("%-40s %s,\n"), _T("/* time_stamp */"),_header->GetAttributeValue(_T("file_name/time_stamp"))) ;
	tmp.AppendFormat(_T("%-40s %s,\n"), _T("/*authors*/"), _header->GetAttributeValue(_T("file_name/author"))); 
	tmp.AppendFormat(_T("%-40s %s,\n"), _T("/*organizations*/"), _header->GetAttributeValue(_T("file_name/organization"))); 
//	tmp.AppendFormat(_T("%-40s %s,\n"), _T("/* preprocessor_version */"), _header->GetAttributeValue(_T("file_name/preprocessor_version))) ; 
	tmp.AppendFormat(_T("%-40s %s,\n"), _T("/* preprocessor_version */"), _T("'NIST STEPNC++ V1.2'")) ; 
	tmp.AppendFormat(_T("%-40s %s,\n"), _T("/* originating_system */"), _header->GetAttributeValue(_T("file_name/originating_system"))) ;
	tmp.AppendFormat(_T("%-40s %s);\n"), _T("/* authorisation */"),  _header->GetAttributeValue(_T("file_name/authorization"))) ;
	tmp.AppendFormat(_T("FILE_SCHEMA(\n"));
	tmp.AppendFormat(_T("%-40s %s\n"), _T("/* schemas */"),  _header->GetAttributeValue(_T("file_schema/schema_identifiers"))) ;
	tmp.AppendFormat(_T(");\nENDSEC;\n\n"));

	return tmp;
}


/**   Adds an entity (#nnn) or return an entity #nnn if an existing string matches the input string. */	
CString CPart21Generator::AddEntity(CString szEntity, CString szData) 
{ 
	CString szEntitynum;
	szData.Trim();
	szData=szData.Mid(0, szData.GetLength()-1); // remove last comma

	CString szEntry = StrFormat(_T("%s(%s);\n"), szEntity.MakeUpper(), szData);
	if(sortedlines.find(szEntry)!=sortedlines.end())
	{
		szEntitynum=sortedlines[szEntry];
	}
	else
	{
		// FIXME check to see if existing entry exists.
		lines[n]= StrFormat(_T("#%d=%s(%s);\n"), n, szEntity.MakeUpper(), szData);
		szEntitynum=StrFormat(_T("#%d"), n++);

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
	CVarDefPtr vardef = new CVarDef(NULL, _T("#1"),entity_, (DWORD) &project, _T("Eproject"), 0 );
	Generate(vardef);
#endif

	outputfile.open (szFilename, std::fstream::out );
	outputfile << (LPCTSTR) GenerateHeader();
#if 0
	outputfile << (LPCTSTR)  StrFormat(_T("FILE_SCHEMA(( "));
	// add schemas
	for(int i=0; i<m_sSchemas.size(); i++)
	{
		if(i>0)
			outputfile << _T(", ");
		outputfile << StrFormat("'%s'", m_sSchemas[i]);

	}
	outputfile <<  (LPCTSTR)  StrFormat(_T("));\nENDSEC;\n\n"));
#endif

	// Data section header
	outputfile <<  (LPCTSTR)  StrFormat(_T("DATA;\n"));
#if 0
	for(std::map<int, CString>::iterator it= lines.begin(); it !=lines.end(); it++)
	{
		outputfile << (*it).second;
	}
#else
	for(std::map<CString, CString>::iterator it= sortedlines.begin(); it !=sortedlines.end(); it++)
	{
		CString str=StrFormat(_T("%-6s = %s"), (*it).second, (*it).first);
		//outputfile << (*it).second << "=" << (*it).first;
		outputfile <<  (LPCTSTR)  str;
	}
#endif
	outputfile <<  (LPCTSTR)  StrFormat(_T("ENDSEC;\n"));
	outputfile <<  (LPCTSTR)  StrFormat(_T("END-ISO-10303-21;\n"));
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

CString CPart21Generator::GenerateList(EListT<IStepNodePtr > * list)
{
	CString tmp;
	if(list->size()<1)
		return tmp;
	for (int i = 0; i<list->size(); i++)
	{
		IStepNodePtr step = list->at(i) ;
		CString sz=DumpCVarDefs(step->GetVarDefs());
		if(i>0)
			tmp+=_T(",");
		if(list->IsASimpleListType())
		{
			tmp+=sz;
		}
		else
		{
			CString szClassname = ExpDemangle(step->Classname());
			CString szNumId = AddEntity(szClassname, sz) ;
			tmp+=szNumId; // tmp.AppendFormat(" %s,", szNumId);
		}
	}
	tmp.Trim();
	return tmp;
}
/** Will create a Part 21 entry for an Express item. If primitive or simple type, will generate text. If entity or list of entities will call
DumpCVarDefs on all the entity attribute Vardef definitions.*/	
CString CPart21Generator::Generate(CVarDefPtr  vardef)
{
	CString tmp;
	OUTPUT_DEBUG_STRING(StrFormat(_T("ENTER: Item = %s Class = %s Type=%d\n"),   vardef->Name(),   vardef->m_sClassname, vardef->Type()));

	if(vardef==NULL)
	{
		OUTPUT_DEBUG_STRING(_T("!!!!!!!Bad vardef\n"));
	}
	if(vardef->IsSimpleType())
	{
		tmp+=vardef->GetVarString();
		tmp+=_T("");
	
	}

	else if(vardef->Type() == 	typereference_)
	{
		IStepNodePtr step=  *(IStepNode **) vardef->m_ref;
		if(step!=NULL) 
		{
			CString sz = DumpCVarDefs(step->GetVarDefs());
			tmp.AppendFormat(_T("%s "), sz);

		}
		else
			tmp.AppendFormat(_T("$ "));
	}
	else if(vardef->Type() == 	select_)
	{
		ESelection * sVal= *(ESelection **) vardef->m_ref;
		IStepNodePtr pSel =sVal-> GetSelection();
		CString szenum = DumpCVarDefs(pSel->GetVarDefs());
		tmp.AppendFormat(_T("%s, "), szenum);
	}
	else if(vardef->Type() == 	entity_  || (vardef->Type() == 	reference_) )
	{
		IStepNodePtr step=  *(IStepNode **) vardef->m_ref;
		if(step==NULL) 
		{
			tmp.AppendFormat(_T("$, "));
			return tmp;

		}
		int n;
		CString sz = DumpCVarDefs(step->GetVarDefs());

		// Note can be an empty defintion entity.
		CString szClassname = ExpDemangle(step->m_sClassname);
		if(szClassname.GetLength()< 1) // typedef's don't have classnames for now...
			szClassname= ExpDemangle(vardef->m_sClassname);

		// Problem here is primitives have entity above simple type
		if(step->IsPrimitive())
		{
#if 0
			if(step->IsKindOf(_T("Eenum")) )
			{
				tmp.AppendFormat("%s ", sz);
			}
			else if( step->m_sClassname == _T("Einteger" )
				||  step->m_sClassname == T("Ereal")  
				|| step->m_sClassname == T("Estring" )
				|| step->m_sClassname == T("Eenum"))
			{
#endif
				tmp.AppendFormat(_T("%s, "), sz);

			}

			else
			{
				CString szNumId = AddEntity(szClassname, sz) ;
				tmp.AppendFormat(_T("%s, "), szNumId);
			}



	}
	else if(vardef->Type() == 	special_)
	{
		tmp.AppendFormat(_T("%s"), DumpCVarDefs((CVarDefs) *(CVarDefs*)vardef->m_ref));
	}
	else if(vardef->Type() == 	bag_ )
	{
		tmp.AppendFormat(_T("("));
		if(vardef->m_nDimension==1)
		{
			EListT<IStepNodePtr > * list= (EListT<IStepNodePtr > *)  vardef->m_ref;
			tmp+=GenerateList( list);
		}
		else if(vardef->m_nDimension==2)
		{
			std::vector<EListT<IStepNodePtr >> &list= *(std::vector<EListT<IStepNodePtr >> *)  vardef->m_ref;
			for (int i = 0; i<list.size(); i++)
			{
				tmp.AppendFormat(_T("("));
				tmp+=GenerateList( &list[i]);
				tmp.AppendFormat(_T("),"));
			}

		}
		tmp.AppendFormat(_T("),"));
	}

	else
	{
		::DebugBreak();
	}
	OUTPUT_DEBUG_STRING(StrFormat(_T("EXIT: Item = %s Class = %s\n"),   vardef->Name(),   vardef->m_sClassname));
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
		OUTPUT_DEBUG_STRING(_T("!!!!!!!Bad vardef\n"));
	}

	if(vardef->IsSimpleType())
	{
		CString val = vardef->GetVarString();
		if(val=="$" && !vardef->Optional())
		{
			 errs.push_back(CErrPair(vardef, StrFormat(_T("Non-optional %s/%s \n"), chain, vardef->Name())));
			 return;
		}

	}
	else if(vardef->Type() == 	special_)
	{
		CompileCVarDefs((CVarDefs) *(CVarDefs*)vardef->m_ref, errs, chain + _T("/") + vardef->Name());
	}
	else if(vardef->Type() == 	typereference_)
	{
		IStepNodePtr step=  *(IStepNode **) vardef->m_ref;
		if(step!=NULL) 
		{
			CompileCVarDefs(step->GetVarDefs(), errs, chain + "/"+ vardef->Name());

		}
		else if(!vardef->Optional())
		{
			 errs.push_back(CErrPair(vardef, StrFormat(_T("Non-optional %s/%s \n"), chain, vardef->Name())));
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
		else if(!vardef->Optional())
		{
			 errs.push_back(CErrPair(vardef, StrFormat(_T("Non-optional %s/%s \n"), chain, vardef->Name())));
			 return;
			
		}

	}

	else if(vardef->ISymbolBase::IsListType() && ! vardef->IsSimpleListType())
	{
		if(vardef->m_nDimension==1)
		{
			EListT<IStepNodePtr > &list= *(EListT<IStepNodePtr > *)  vardef->m_ref;
			for (int i = 0; i<list.size(); i++)
			{
				IStepNodePtr step = list[i] ;
				CompileCVarDefs(step->GetVarDefs(), errs, chain + "/"+ StrFormat(_T("%s[%d]"), vardef->Name(), i));
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
	Classname()=_T("Efile_description");
	Parents().clear(); 
	Supertypes().clear(); 
	m_bAbstract=false ; 
	m_vars.push_back(new CVarDef(this, _T("description") ,(StepNodeType) 13, (DWORD) &(this->description), _T("EListT<EStringPtr>"), 0));
	m_vars.back()->Init(1, (StepNodeType)  5, _T("EString"));
	description.ListClassname()=_T("EString"); 
	description.ListType()=(StepNodeType)  5; 
	m_vars.push_back(new CVarDef(this, _T("implementation_level") ,(StepNodeType) 22, (DWORD) &(this->implementation_level), _T("Eheader_text"), 0));
	m_vars.back()->Init(0, (StepNodeType)  0, _T(""));
	CStringVector vVisitedClasses;
	BuildInstanceDef(m_vars, m_instancevars,vVisitedClasses);
} /* End Efile_description*/
////////////////////////////////////////////////////////////////////////////////
Efile_name::Efile_name(){
	Classname()=_T("Efile_name");
	Parents().clear(); 
	Supertypes().clear(); 
	m_bAbstract=false ; 
	m_vars.push_back(new CVarDef(this, _T("name") ,(StepNodeType) 22, (DWORD) &(this->name), _T("Eheader_text"), 0));
	m_vars.back()->Init(0, (StepNodeType)  0, _T(""));
	m_vars.push_back(new CVarDef(this, _T("time_stamp") ,(StepNodeType) 22, (DWORD) &(this->time_stamp), _T("Eheader_text"), 0));
	m_vars.back()->Init(0, (StepNodeType)  0, _T(""));
	m_vars.push_back(new CVarDef(this, _T("author") ,(StepNodeType) 13, (DWORD) &(this->author), _T("EListT<EStringPtr>"), 0));
	m_vars.back()->Init(1, (StepNodeType)  5, _T("EString"));
	author.ListClassname()=_T("EString"); 
	author.ListType()=(StepNodeType)  5; 
	m_vars.push_back(new CVarDef(this, _T("organization") ,(StepNodeType) 13, (DWORD) &(this->organization), _T("EListT<EStringPtr>"), 0));
	m_vars.back()->Init(1, (StepNodeType)  5, _T("EString"));
	organization.ListClassname()=_T("EString"); 
	organization.ListType()=(StepNodeType)  5; 
	m_vars.push_back(new CVarDef(this, _T("preprocessor_version") ,(StepNodeType) 22, (DWORD) &(this->preprocessor_version), _T("Eheader_text"), 0));
	m_vars.back()->Init(0, (StepNodeType)  0, _T(""));
	m_vars.push_back(new CVarDef(this, _T("originating_system") ,(StepNodeType) 22, (DWORD) &(this->originating_system), _T("Eheader_text"), 0));
	m_vars.back()->Init(0, (StepNodeType)  0, _T(""));
	m_vars.push_back(new CVarDef(this, _T("authorization") ,(StepNodeType) 22, (DWORD) &(this->authorization), _T("Eheader_text"), 0));
	m_vars.back()->Init(0, (StepNodeType)  0, _T(""));
	CStringVector vVisitedClasses;
	BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
} /* End Efile_name*/
////////////////////////////////////////////////////////////////////////////////
Efile_schema::Efile_schema(){
	Classname()=_T("Efile_schema");
	Parents().clear(); 
	Supertypes().clear(); 
	m_bAbstract=false ; 
	m_vars.push_back(new CVarDef(this, _T("schema_identifiers") ,(StepNodeType) 13, (DWORD) &(this->schema_identifiers), _T("EListT<Eschema_namePtr>"), 0));
	m_vars.back()->Init(1, (StepNodeType)  22, _T("Eschema_name"));
	schema_identifiers.ListClassname()=_T("Eschema_name"); 
	schema_identifiers.ListType()=(StepNodeType)  22; 
	CStringVector vVisitedClasses;
	BuildInstanceDef(m_vars, m_instancevars,vVisitedClasses);
} /* End Efile_schema*/

Eheader_text::Eheader_text()
{
 	this->Type()= typereference_; 
	Classname()=_T("Eheader_text");
	m_vars.push_back(new CVarDef(this, _T("EString") ,(StepNodeType) 1, (DWORD) &(this->EString::m_vars),_T("Baseclass")));
	Parents().clear(); 
	Parents().push_back(_T("EString")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
Eschema_name::Eschema_name()
{
 	this->Type()= typereference_; 
	Classname()=_T("Eschema_name");
	m_vars.push_back(new CVarDef(this, _T("EString") ,(StepNodeType) 1, (DWORD) &(this->EString::m_vars),_T("Baseclass")));
	Parents().clear(); 
	Parents().push_back(_T("EString")); 
	 CStringVector vVisitedClasses;
	 BuildInstanceDef(m_vars, m_instancevars, vVisitedClasses);
}
IStepNodePtr Createpart21header_schemaClass(CString classname, CString name) 
 {
	classname=ExpMangle(classname.MakeLower());
	if(classname==_T("Efile_description")) return Efile_description::Create(name);
	if(classname==_T("Efile_name")) return Efile_name::Create(name);
	if(classname==_T("Efile_schema")) return Efile_schema::Create(name);
	if(classname==_T("Eheader_text")) return  (IStepNodePtr) new EString;
	if(classname==_T("Eschema_name")) return  (IStepNodePtr) new Eschema_name;
	return NULL; 
}
	static CStringVector svEntities(3, 
	CString(_T("Efile_description")),
	CString(_T("Efile_name")),
	CString(_T("Efile_schema")));
 CStringVector GetAllPart21_schemaEntities(){ return svEntities;}
} /* End namespace Express*/


CString CPart21Generator::P21AsHtml(CString sFilename)
{
	
	CString szHtml;
	FILE * fd=NULL;
	TCHAR str[2056];
	int Size=0;

	// Open file to read
	if((fd=_tfopen(sFilename,_T("r")))==NULL)
	{
		return false;
	}

	szHtml.AppendFormat(_T("<html>\n"));

	szHtml.AppendFormat(_T("<head> \n"));
	szHtml.AppendFormat(_T("<script language=\"JavaScript\">\n"));
	szHtml.AppendFormat(_T("var lastobj=null\n"));
 
	szHtml.AppendFormat(_T("function highlight(id) \n"));
	szHtml.AppendFormat(_T("{ \n"));
	szHtml.AppendFormat(_T("if(lastobj != null) \n"));
	szHtml.AppendFormat(_T("{\n"));
	szHtml.AppendFormat(_T("	lastobj.style.backgroundColor = \"white\"; \n"));
	szHtml.AppendFormat(_T("}\n"));
	szHtml.AppendFormat(_T("var obj = document.getElementById(id); \n"));
	szHtml.AppendFormat(_T("obj.style.backgroundColor = \"yellow\"; \n"));
	szHtml.AppendFormat(_T("lastobj =obj\n"));
	szHtml.AppendFormat(_T("} \n"));
	szHtml.AppendFormat(_T("</script> \n"));
	szHtml.AppendFormat(_T("</head>\n"));

	szHtml.AppendFormat(_T("<body><code>\n"));

	for(int i=0; ; i++)
	{
		if(NULL== _fgetts(str, 2056, fd))
			break;
		szHtml.AppendFormat(_T("<A NAME=\"#Line%-d\"></A>"),i+1);
		CString line=str;
		line.Replace(_T("\n"),_T("<BR>\n"));
		CString tmp;
		CString label;
		CString rightpart;
		int n =  line.Find(_T("="));
		if(n<0)
		{
			szHtml+=line;
			continue;
		}
		CString leftpart =line.Mid(0,n);
		label=leftpart;
		label.Replace(_T("#"), _T(""));
		szHtml.AppendFormat(_T("<DIV id=\"div%s\">"), label.Trim());
		szHtml.AppendFormat(_T("<A NAME=\"#Label%s\">%s</A>"), label.Trim(), leftpart);

		rightpart=line.Mid(n);
		while(1)
		{
			int m;
			int j;
			n = rightpart.Find(_T("#"));
			if(n<0)
			{
				szHtml+=rightpart;
				break;
			}
			szHtml.AppendFormat(rightpart.Mid(0,n));

			rightpart=rightpart.Mid(n);
			CString num;
			for(j=1; iswdigit(rightpart[j]) && j < line.GetLength() ; j++)
			{
				num+=rightpart[j];
			}
			szHtml.AppendFormat(_T("<A HREF=\"#Label%s\" onClick=\"highlight('div%s')\">#%s</A>"), num, num, num);

			rightpart =rightpart.Mid(j);

		}
		szHtml.AppendFormat(_T("</DIV>"));
	}
	szHtml.AppendFormat(_T("</CODE> </BODY></HTML>\n"));
	fclose(fd);
	return szHtml;
}
