//
// Part21Generator.h: interface for the CPart21Header class.
//


#pragma once
#include "atlstr.h"
#include "ExpressUtils.h"
#include <time.h>
#include "OutDebug.h"

///////////////////////////////////////////////////////////////////////////////
// Classes in this file:
//
// Efile_description
// Efile_name
// Efile_schema
// Eheader_text
// Eschema_name
// EP21Header

namespace Express
{
	class Efile_description;
	EXP_DECLARE_SMARTPOINTER(Efile_description);

	class Efile_name;
	EXP_DECLARE_SMARTPOINTER(Efile_name);

	class Efile_schema;
	EXP_DECLARE_SMARTPOINTER(Efile_schema);

	class Eschema_name ; 
	EXP_DECLARE_SMARTPOINTER(Eschema_name);

	class Eheader_text ;  // this is a hack for now. No express attribute defs use EStringPtr only derived type.
	EXP_DECLARE_SMARTPOINTER(Eheader_text);

	extern CStringVector GetAllPart21_schemaEntities();

	class Efile_description :
		public IStepNode
	{
	public:
		CLASSDEF(Efile_description); 
		EListT<EStringPtr> description; 
		Eheader_textPtr implementation_level; 
	};
	class Efile_name :
		public IStepNode
	{
	public:
		CLASSDEF(Efile_name); 
		Eheader_textPtr name; 
		Eheader_textPtr time_stamp; 
		EListT<EStringPtr> author; 
		EListT<EStringPtr> organization; 
		Eheader_textPtr preprocessor_version; 
		Eheader_textPtr originating_system; 
		Eheader_textPtr authorization; 
	};
	class Efile_schema :
		public IStepNode
	{
	public:
		CLASSDEF(Efile_schema); 
		EListT<Eschema_namePtr> schema_identifiers; 
	};
	class Eheader_text : public EString /*typedef*/
	{
	public:
		CLASSDEF(Eheader_text); 
	};
	class Eschema_name : public EString /*typedef*/
	{
	public:
		CLASSDEF(Eschema_name); 
	};
} /* End namespace Express*/
using namespace Express;
/**
Provides support for STEP Part 21 header as defined in a StepNC++ StepNode/VarDef tree.
*/
class EP21Header :
	public IStepNode
{
public:
	CLASSDEF(EP21Header); 
	//std::vector<EStringPtr> file_description; 


	Efile_descriptionPtr file_description;
	Efile_namePtr file_name;
	Efile_schemaPtr file_schema;

};
EXP_DECLARE_SMARTPOINTER(EP21Header) 

class CErrPair
{
public:
	CErrPair() {}
	CErrPair(CVarDefPtr _vardef, CString _errmsg) : vardef(_vardef),  errmsg(_errmsg) {}
	CVarDefPtr vardef;
	CString errmsg;

};
class CErrPairs : public std::vector<CErrPair>
{
public:
};

/**
Generates a STEP Part21 file from a  StepNC++ project defined in a StepNode/VarDef  tree.
*/

class CPart21Generator  
{
public:
	CPart21Generator();
	virtual ~CPart21Generator(){}
	//CString & Name() { return m_sName; }
	//CStringVector & Authors() { return m_sAuthors; }
	//CStringVector & Organizations() { return m_sOrganizations; }
	//CStringVector & FileDescriptions() { return m_sFile_description; }
	//CString GenerateList(CString comment, CStringVector & items);
	CString GenerateString(CString s);
	CString GenerateHeader();

	void Init();
	CString AddEntity(CString szEntity, CString szData);

	CString DumpCVarDefs(CVarDefs &vars);
	CString Generate(CVarDefPtr  vardef);

	void SaveP21(IStepNodePtr project, CString szFilename);
	CVarDefPtr GetHeaderVarDef() { return _vardef; }
	virtual std::vector<CVarDefPtr> & GetVarDefs() { return vars; }
	EP21HeaderPtr Header() { return _header; }


	void CompileCVarDefs(CVarDefs &vars, CErrPairs & errs, CString chain="");
	void Compile(CVarDefPtr  vardef, CErrPairs & errs, CString chain="");
	////////////////////////////////////////////////////////////////
private:
	int n;
	CVarDefs vars;

	CVarDefPtr _vardef;
	std::map<int, CString> lines;
	std::map< CString, CString> sortedlines;
	std::fstream outputfile;
	EP21HeaderPtr _header;
};
