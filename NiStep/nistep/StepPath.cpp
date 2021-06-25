//
// StepPath.cpp : Implementation of CStepPath
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#include "stdafx.h"
#include "StepPath.h"
#include "Part21Parser.cpp"
#include "Globals.h"
#include "Resource.h"
#include <atlsafe.h>

extern CPart21Generator * _gPart21gen;

// CStepPath
CStepPath::CStepPath()
{
	_gPart21gen = &_part21gen;
	GlobalsInit();
	stepncvardefs.push_back(_gPart21gen->GetHeaderVarDef());
	projectvardef = new CVarDef(NULL, _T("project"), entity_, (DWORD) &gProject, _T("Eproject"), 0 );
	stepncvardefs.push_back(projectvardef);
	projectvardefs.push_back(projectvardef);
	
}

STDMETHODIMP CStepPath::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IStepPath
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

/**
* reads and parses a valid STEPNC Part21 file given as a bstring. 
* Produces tree of step nodes. 
* project entity is the root node.
* @param  bstrStep  part21 file given as bstring .
* @param  pVal  pointer to variant bool to store t/f flag indicating success.
*/
STDMETHODIMP CStepPath::loadStep(/*[in*/ BSTR bstrStep, /*[out,retval]*/ VARIANT_BOOL* isSuccessful)
{
	ParseString((LPCTSTR) _bstr_t(bstrStep));
	*isSuccessful = VARIANT_TRUE;
	return S_OK;
}

/**
* reads a file and parses a valid STEPNC Part21 file. 
* Produces tree of step nodes. 
* project entity is the root node.
* @param  bstrFilename  part21 filename, assumes complete path.
* @param  pVal  pointer to variant bool to store t/f flag indicating success.
*/
STDMETHODIMP CStepPath::loadFile(/*[in*/ BSTR bstrFilename, /*[out,retval]*/  VARIANT_BOOL* isSuccessful)
{
	szP21filename = bstrFilename; 
	if(szP21filename.size() <= 0)
		return AtlReportError(CLSID_StepPath, IDS_ERRBADFILENAME, IID_IStepPath, E_INVALIDARG);
	if(GetFileExists(szP21filename.c_str()))
		return AtlReportError(CLSID_StepPath, IDS_ERRFILENAMEDOESNTEXIST, IID_IStepPath, E_INVALIDARG);

	tifstream ifs(szP21filename.c_str());
	tstringstream buffer;
	buffer << ifs.rdbuf();

	ParseString(buffer.str());
	*isSuccessful = VARIANT_TRUE;
	return S_OK;
}

STDMETHODIMP CStepPath::saveFile(/*[in]*/  BSTR bstrFilename, /*[out, retval]*/ VARIANT_BOOL* isSuccessful)
{
	szP21filename = (LPCTSTR) _bstr_t( bstrFilename); 
	if(szP21filename.size() <= 0)
		return AtlReportError(CLSID_StepPath, IDS_ERRBADFILENAME, IID_IStepPath, E_INVALIDARG);
	_part21gen.SaveP21(gProject, szP21filename.c_str());
	return S_OK;
}


STDMETHODIMP CStepPath::clearStep()
{
	gProject=NULL; // this should do it right?
	return S_OK;
}

STDMETHODIMP CStepPath::CreateNewProject(/*[out, retval]*/ INode ** ppNode)
{
	gProject = CClassGenerators::gClassGenerators.CreateClass((LPCTSTR) _bstr_t(L"project"),_T(""));

	::CloneCVarDefs(_gPart21gen->DefaultHeader()->GetVarDefs(), _gPart21gen->Header()->GetVarDefs());
	OutputDebugString(::DumpCVarDefs(_gPart21gen->Header()->GetVarDefs()));

	if(gProject==NULL)
		return E_FAIL;
	return gProject->QueryInterface(IID_INode, (void**) ppNode );
}

STDMETHODIMP CStepPath::TranslateP21ToHtml(/*[in]*/ BSTR bstrFilename, /*[out, retval]*/ BSTR * bstrHtml)
{
	CString str = _part21gen.P21AsHtml((LPCTSTR) _bstr_t( bstrFilename));
	*bstrHtml = str.AllocSysString();
	return S_OK;
}


/**
* Verifies the step  nodes tree against the Express schema optional requirements. 
* Returns a list of error bstring wrapped as a safearray in a variant.
*/
STDMETHODIMP CStepPath::Verify(/*[out, retval]*/ VARIANT * stringsafearray)
{
	_verifyerrors.clear();
	_part21gen.CompileCVarDefs(projectvardefs, _verifyerrors, _T(""));

	if(_verifyerrors.size()>0)
	{
		SAFEARRAYBOUND bound [] = {_verifyerrors.size(), 0 };
		CComSafeArray<BSTR> errmsgs(bound,1);
		for(int i=0; i< _verifyerrors.size(); i++)
		{
			errmsgs.SetAt(i, _bstr_t(_verifyerrors[i].errmsg));
		}

		CComVariant tmp((LPSAFEARRAY) errmsgs.Detach());
		tmp.Detach(stringsafearray);
	}

#if 0
* @param  pdwCount  output count of errors.
* @param  ppErrorIds  output list of error ids, list of size pdwCount.
* @param  ppDescriptions  output list of error descriptions, list of size pdwCount.
	* pdwCount=0;
	ppErrorIds = (DWORD**) CoTaskMemAlloc(sizeof(DWORD)  * _verifyerrors.size());		
	ppDescriptions = (BSTR**) CoTaskMemAlloc(sizeof(BSTR)  * _verifyerrors.size());		

	for(int i=0; i< _verifyerrors.size(); i++)
	{
		*ppErrorIds[i]=E_FAIL;
		*ppDescriptions[i]=SysAllocString(_verifyerrors[i].errmsg);
	}
#endif


	return S_OK;
}

/**
* Verifies the step  nodes tree against the Express schema optional requirements. 
* project entity is the root node.
* Returns root node.
* @param  ppNode  pointer to INode to store root Step Node.
*/
STDMETHODIMP CStepPath::GetRoot(/*[out,retval]*/  INode ** ppNode)
{
	IStepNodePtr node = gProject;
	return node->QueryInterface(IID_INode, (void**) ppNode );
}


STDMETHODIMP CStepPath::GetRootAttribute(/*[out,retval]*/  IAttribute ** ppAttribute)
{
	return projectvardef->QueryInterface(IID_IAttribute, (void**) ppAttribute );
}
STDMETHODIMP CStepPath::GetRootAttributeList(/*[out,retval]*/  IAttributeList ** ppAttributeList)
{
	CComAttributeList * list ;
	if(FAILED( CComAttributeList::CreateInstance(&list)))
		return E_FAIL;
	list->AddRef();
	list->Init(&stepncvardefs);
	return list->QueryInterface(IID_IAttributeList, (void**) ppAttributeList );
}

STDMETHODIMP CStepPath::GetP21Header(INode ** ppNode)
{
	IStepNodePtr node = _part21gen.Header(); 
	if(node==NULL)
		return E_FAIL;
	return node->QueryInterface(IID_INode, (void**) ppNode );
}

STDMETHODIMP CStepPath::GetP21HeaderAttribute(/*[out,retval]*/  IAttribute ** ppAttribute)
{
	CVarDefPtr headervardef = _part21gen.GetVarDefs().at(0);
	return headervardef->QueryInterface(IID_IAttribute, (void**) ppAttribute );
}
STDMETHODIMP CStepPath::GetP21HeaderAttributeList(/*[out,retval]*/  IAttributeList ** ppAttributeList)
{
	CComAttributeList * list ;
	if(FAILED( CComAttributeList::CreateInstance(&list)))
		return E_FAIL;
	list->AddRef();
	list->Init(&_part21gen.GetVarDefs());
	return list->QueryInterface(IID_IAttributeList, (void**) ppAttributeList );
}


/**
* Creates and returns a step  node  based on a STEPNC Express schema name. 
* @param  classname  as given by  input bstring .
* @param  ppNode  pointer to INode to store new Step Node.
*/
STDMETHODIMP CStepPath::CreateNode(/*[in]*/ BSTR classname, /*[out,retval]*/ INode ** ppNode)
{
	IStepNodePtr node = CClassGenerators::gClassGenerators.CreateClass((LPCTSTR) _bstr_t(classname),_T(""));
	if(node == NULL)
		return E_FAIL;
	return node->QueryInterface(IID_INode, (void**) ppNode );
}


/** COM method to determine if Step Node type is class name is a simple type (int, real, string etc). 
fails if invalid classname
@param[in] bstrClassname class to test.
@param[out] pVal pointer to variant bool to store true if it is false otherwise.
*/
STDMETHODIMP CStepPath::IsASimpleType(/*[in]*/ BSTR bstrClassname, /*[out, retval]*/  VARIANT_BOOL* flag)
{
	*flag = VARIANT_FALSE;
	IStepNodePtr step =  CClassGenerators::gClassGenerators.CreateClass((LPCTSTR) bstr_t(bstrClassname), _T(""));
	if(step==NULL)
		return E_INVALIDARG;
	if( step->IsSimpleType())
		*flag = VARIANT_TRUE;
	return S_OK;
}

/**
 * Returns a t/f if classname described by bstring is simple list type. 
  * @param  bstrVal  classname described by bstring
* @param  flag pointer to boolean variant to store flag.
*/
STDMETHODIMP CStepPath::IsASimpleListType(/*[in]*/ BSTR bstrClassname, /*[out, retval]*/  VARIANT_BOOL* flag)
{
	IStepNodePtr step =  CClassGenerators::gClassGenerators.CreateClass((LPCTSTR) bstr_t(bstrClassname), _T(""));
	*flag = VARIANT_FALSE;
	if(step==NULL)
		return E_INVALIDARG;

	if(step->ISymbolBase::IsSimpleListType())
		*flag = VARIANT_TRUE;
	return S_OK;
}

/**
 * Returns a 1D safearray of  bstrings of the  supertype classes (i.e., that derive from this class).
  * @param  bstrVal  classname described by bstring
* @stringsafearray  variant pointer to store 1D safearray of  bstrings.
*/
STDMETHODIMP CStepPath::GetClassSupertypeHierarchy(/*[in]*/  BSTR bstrClassname, /*[out, retval]*/  VARIANT * stringsafearray)
{
	CStringVector classes= ClassSupertypeHierarchy((LPCTSTR) bstr_t( bstrClassname));
	for(int i=0; i< classes.size(); i++)
		classes[i]= ExpDemangle(classes[i]);

	SAFEARRAYBOUND bound [] = {classes.size(), 0 };
	CComSafeArray<BSTR> supers(bound,1);
	for(int i=0; i< classes.size(); i++)
	{
		supers.SetAt(i, _bstr_t(classes[i]));
	}

	CComVariant tmp((LPSAFEARRAY) supers.Detach());
	tmp.Detach(stringsafearray);
	return S_OK;

}
