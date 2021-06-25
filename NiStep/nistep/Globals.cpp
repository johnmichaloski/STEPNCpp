//
// Globals.cpp
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#include "stdafx.h"
#include "Globals.h"
#include "ExpressUtils.h"
#include "StepNcAddONs.h"
#include "stepnc_schemaClassDefinitions.h"
#include "Part21Generator.h"
#include <ctime>

//const char *buildString = "This build XXXX was compiled at " __DATE__ ", " __TIME_ ".";

//CString gStartEntity = "shape_definition_representation";  // assign to this if you just want graphics
CString gStartEntity = _T("project");
IStepNodePtr gProject;

std::ofstream debugstream;
CPart21Generator * _gPart21gen;



void GlobalsInit()
{
		static int bFlag=0;
	if(!bFlag)
	{
		CClassGenerators::gClassGenerators.AddGenerator(&Createstepnc_schemaClass);
		CClassGenerators::gClassGenerators.AddGenerator(&CreateExpressBaseClass);
		CClassGenerators::gClassGenerators.AddGenerator(&Createpart21header_schemaClass);
		CClassGenerators::gClassGenerators.AddGenerator(&CreateExpressAddons);
		bFlag;
	}

	time_t timestamp;
	time(&timestamp);

	IStepNodePtr header = (IStepNode*)  _gPart21gen->DefaultHeader().get();
	header->SetAttributeValue(_T("file_description/description[-1]"), _T("Hello World!"));
	header->SetAttributeValue(_T("file_description/description[-1]"), _T("Its a mad mad Hello Kitty World!"));
	header->SetAttributeValue(_T("file_description/implementation_level"), _T("1;2"));

	header->SetAttributeValue(_T("file_name/name"), _T("StepNc File"));
	header->SetAttributeValue(_T("file_name/time_stamp"),_tctime(&timestamp) );
	header->SetAttributeValue(_T("file_name/author[-1]"), _T("John Michaloski"));
	header->SetAttributeValue(_T("file_name/author[-1]"), _T("Tom Kramer"));
	header->SetAttributeValue(_T("file_name/organization[-1]"), _T("NIST"));
	header->SetAttributeValue(_T("file_name/preprocessor_version"), _T("1:2"));
	header->SetAttributeValue(_T("file_name/originating_system"), _T("STEPNC++ 2.1"));
	header->SetAttributeValue(_T("file_name/authorization"), _T(""));

	header->SetAttributeValue(_T("file_schema/schema_identifiers[-1]"), _T("machining_schema"));
	header->SetAttributeValue(_T("file_schema/schema_identifiers[-1]"), _T("milling_schema"));

}