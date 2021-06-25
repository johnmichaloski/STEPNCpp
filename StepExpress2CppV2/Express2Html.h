//
//
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#pragma once
#include "StepParser.h"

class CExpress2Html
{
public:
	CExpress2Html(CStepNCParser & parser );
	~CExpress2Html(void);
	void Express2Html();
	void Express2XmlHelp();
	HRESULT Express2HtmlHelp(std::string helppath);
	HRESULT Xml2StdMap(std::string xmlfilename, std::string cppfilename );

	std::string _helppath;
	CString schema;
	CStepNCParser &_parser;
	std::map<CString,CString> xmldescriptions;
	std::fstream htmlfile;


	CString _szEntityName;
	CString _szEntitySupertype;
	CString _szEntitySubtype;
	CStringVector _szEntityAttr;
	CStringVector _szEntityAttrType;

};
