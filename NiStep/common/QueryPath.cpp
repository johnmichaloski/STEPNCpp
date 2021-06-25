//
// QueryPath.cpp
//

#include "StdAfx.h"
#include "QueryPath.h"
#include "Misc.h"



CQueryPath::CQueryPath(void)
{
}

CQueryPath::~CQueryPath(void)
{
}

void CQueryPath::Close()
{

	pXMLDom.Release();

}
HRESULT CQueryPath::Open(CString filename)
{
	HRESULT hr;
	try {
		if(FAILED(hr= pXMLDom.CreateInstance(__uuidof(MSXML2::DOMDocument40))))
		{
			throw std::exception("Failed to instantiate an XML DOM.\n");
			return hr;
		}

		pXMLDom->async = VARIANT_FALSE; // default - true,

		if(pXMLDom->load(_variant_t((LPCTSTR) filename))!=VARIANT_TRUE)
		{
			throw std::exception(bstrFormat(_T("Failed to load stocks.xml:\n%s\n"),
				(LPCSTR)pXMLDom->parseError->Getreason()));
		}
		OutputDebugString(bstrFormat(_T("XML DOM loaded from stocks.xml:\n%s\n"), 
			(LPCSTR)pXMLDom->xml));

	}
	catch(std::exception e)
	{
		OutputDebugString(_bstr_t(e.what()));
		return hr;

	}
	return S_OK;
}


int CQueryPath::QuerySize(CString path)
{
	HRESULT hr;
	try
	{
		MSXML2::IXMLDOMNodeListPtr pnl = pXMLDom->selectNodes((LPCTSTR) path);
		return pnl->length; 
	}
	catch(...) {}

	return -1;
}
MSXML2::IXMLDOMNodeListPtr CQueryPath::QueryNodes(CString path, MSXML2::IXMLDOMNodePtr start)
{
	HRESULT hr;
	try
	{
		if(start==NULL)
			return pXMLDom->selectNodes((LPCTSTR) path);
		return start->selectNodes((LPCTSTR) path);
	}
	catch(...) {}

	return NULL;
}
CString CQueryPath::QueryValue(CString path, CString szDefault)
{
	HRESULT hr;
	try {
	  // Query a single node.
//	  if((pNode = pXMLDom->selectSingleNode("//PROJECT/Operations/Operation[1]/Type")) == NULL) // works
	  if((pNode = pXMLDom->selectSingleNode((LPCTSTR) path)) == NULL)
	  {
		  throw std::exception(bstrFormat(_T("Invalid node fetched.\n%s\n"),
			  (LPCTSTR)pXMLDom->parseError->Getreason()));
	  }
	  else
	  {
		  OutputDebugString(bstrFormat(_T("Result from selectSingleNode:\nNode, <%s>:\n\t%s\n\n"),
			  (LPCTSTR)pNode->nodeName, (LPCSTR)pNode->xml));
		  return  (LPCTSTR)pNode->text;
	  }

	  //// Query a node-set.
	  //pnl = pXMLDom->selectNodes("//PROJECT/Setup/*");
	  //OutputDebugString("Results from selectNodes:\n");
	  //for (int i=0; i<pnl->length; i++)
	  //{
		 // pNode = pnl->item[i];
		 // OutputDebugString(StrFormat("Node (%d), <%s>:\n\t%s\n", 
			//  i, (LPCSTR)pNode->nodeName, (LPCSTR)pnl->item[i]->xml));
	  //}
  
   }
   catch(std::exception e)
   {

	   OutputDebugString(_bstr_t(e.what()));
	   return _T("");

   }
   return _T("");
}

MSXML2::IXMLDOMNodePtr CQueryPath::QueryNode(CString path, MSXML2::IXMLDOMNodePtr start)
{
	if(start==NULL)
		return pXMLDom->selectSingleNode((LPCTSTR) path) ;
	return start->selectSingleNode((LPCTSTR) path);
}

CString CQueryPath::QueryXML(CString path, MSXML2::IXMLDOMNodePtr start)
{
	MSXML2::IXMLDOMNodePtr node = QueryNode(path, start);
	if(node==NULL)
		return CString();
	return (LPCTSTR) node->xml;

}


HRESULT  CQueryPath::Read(CString xmlmarkup)
{
	HRESULT hr;

	try {
		if(FAILED(hr= pXMLDom.CreateInstance(__uuidof(MSXML2::DOMDocument60))))
		{
			return hr;
		}
		pXMLDom->async = VARIANT_FALSE;
		pXMLDom->validateOnParse = VARIANT_TRUE;
		pXMLDom->preserveWhiteSpace = VARIANT_TRUE;    

		//load markup into XML document
		if(pXMLDom->loadXML(_bstr_t(xmlmarkup))!=VARIANT_TRUE)
			return E_FAIL;
	}
	catch(std::exception e)
	{
		OutputDebugString(_bstr_t(e.what()));
		return hr;

	}
	return S_OK;
}
