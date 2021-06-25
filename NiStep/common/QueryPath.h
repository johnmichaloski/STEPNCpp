//
// QueryPath.h
//

// DISCLAIMER: 
//  This software was produced by the National Institute of Standards 
//  and Technology (NIST), an agency of the U.S. government, and by statute is 
//  not subject to copyright in the United States.  Recipients of this 
//  software assume all responsibility associated with its operation,
//  modification,maintenance, and subsequent redistribution. 
//
//  See NIST Administration Manual 4.09.07 b and Appendix I. 

#pragma once
#import <msxml6.dll>
#include "atlstr.h"


class CQueryPath
{
public:
	MSXML2::IXMLDOMDocumentPtr pXMLDom;
	MSXML2::IXMLDOMNodePtr pNode;
	MSXML2::IXMLDOMNodePtr pRoot;
	MSXML2::IXMLDOMNodeListPtr pnl;

	CQueryPath(void);
	~CQueryPath(void);
	HRESULT Open(CString filename);
	HRESULT Read(CString xmlmarkup);
	void Close();
	CString QueryValue(CString path, CString szDefault);
	int QuerySize(CString path);
	MSXML2::IXMLDOMNodePtr QueryNode(CString path, MSXML2::IXMLDOMNodePtr start = NULL);
	MSXML2::IXMLDOMNodeListPtr QueryNodes(CString path, MSXML2::IXMLDOMNodePtr start=NULL);
	CString QueryXML(CString path, MSXML2::IXMLDOMNodePtr start = NULL);
};

