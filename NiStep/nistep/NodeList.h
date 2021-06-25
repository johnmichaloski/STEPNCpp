// NodeList.h : Declaration of the CNodeList

#pragma once
#include "resource.h"       // main symbols

#include "NiStep_i.h"
#include "ExpressUtils.h"

#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CNodeList

class ATL_NO_VTABLE CNodeList :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CNodeList, &CLSID_NodeList>,
	public IDispatchImpl<INodeList, &IID_INodeList, &LIBID_NiStepLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	EListT<IStepNodePtr>  * _nodes;
	long _nCurIndex;


	CNodeList()
	{
	}

DECLARE_NOT_AGGREGATABLE(CNodeList)

BEGIN_COM_MAP(CNodeList)
	COM_INTERFACE_ENTRY(INodeList)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

	void Init(EListT<IStepNodePtr>  * nodes) 
	{
		_nCurIndex=0;  
		_nodes=nodes; 
	}
public:
	STDMETHODDECL IsSimpleType(/*[out, retval]*/VARIANT_BOOL* flag) ;
	STDMETHODDECL IsListType(/*[out, retval]*/VARIANT_BOOL* flag);
	STDMETHODDECL get_ListClassname(/*[out, retval]*/BSTR* pVal);
	STDMETHODDECL get_Name(/*[out, retval]*/BSTR* pVal);
	STDMETHODDECL get_Classname(/*[out, retval]*/BSTR* pVal);
	STDMETHODDECL get_Type(/*[out, retval]*/StepNodeType* pVal);
	STDMETHODDECL get_ListType(/*[out, retval]*/StepNodeType* pVal);


	STDMETHODDECL get_item(LONG index, INode ** listItem);
	STDMETHODDECL get_length(LONG* pVal);
	STDMETHODDECL reset(void);
	STDMETHODDECL nextNode(INode ** nextItem);
	STDMETHODDECL get__newEnum(IUnknown ** pVal);
	STDMETHODDECL back(INode ** listItem);
	STDMETHODDECL size(LONG* pVal);
	STDMETHODDECL push_back(/*[in]*/ BSTR bstrClassname,/*[in]*/BSTR bstrName, /*[out,retval]*/ INode ** newListItem);

	// List methods
	STDMETHODDECL DeleteChild(/*[in]*/ INode * pNode);
	STDMETHODDECL SwapListItems(/*[in]*/ LONG index1, /*[in]*/ LONG index);
	STDMETHODDECL SetListItem(/*[in]*/ LONG nVal, /*[in]*/ INode * pNode);
	STDMETHODDECL IsSimpleListType(/*[out, retval]*/ VARIANT_BOOL* flag);
	STDMETHODDECL IsASimpleListType(/*[in]*/ BSTR bstrVal, /*[out, retval]*/  VARIANT_BOOL* flag);
	STDMETHODDECL GetIndex(/*[in]*/ IAttribute * pAttr, /*[out, retval]*/ LONG * pVal);
	STDMETHODDECL SetListVarString(/*[in]*/ BSTR bstr, /*[in]*/ BSTR bstrDelimiter);
	STDMETHODDECL GetListVarString(/*[in]*/ BSTR bstrDelimiter, /*[out, retval]*/ BSTR* pVal);
	STDMETHODDECL GetStepNode(/*[out, retval]*/ INode ** ppNode);
	STDMETHODDECL GetAttributeList(/*[out, retval]*/ IAttributeList ** pVal) ;
};

typedef CComObject<CNodeList>  CComNodeList;