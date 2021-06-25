// AttributeList.h : Declaration of the CAttributeList

#pragma once
#include "resource.h"       // main symbols

#include "NiStep_i.h"
#include "ExpressUtils.h"

// CAttributeList

class  ATL_NO_VTABLE  CAttributeList :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAttributeList, &CLSID_AttributeList>,
	public IDispatchImpl<IAttributeList, &IID_IAttributeList, &LIBID_NiStepLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CVarDefs *_vars;
	long _nCurIndex;

	CAttributeList() 
	{
	}
	void Init(CVarDefs *vars) 
	{
		_nCurIndex=0;  
		_vars=vars; 
	}

BEGIN_COM_MAP(CAttributeList)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IAttributeList)
END_COM_MAP()

// ISupportsErrorInfo


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		_nCurIndex=0;
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:

	STDMETHODIMP get_item(LONG index, IAttribute ** listItem);
	STDMETHODIMP get_length(LONG* pVal);
	STDMETHODIMP reset(void);
	STDMETHODIMP nextAttribute(IAttribute ** nextItem);
	STDMETHODIMP get__newEnum(IUnknown ** pVal);
	STDMETHODIMP back(IAttribute ** listItem);
	STDMETHODIMP size(/*[out, retval]*/ LONG* pVal);
};
typedef CComObject<CAttributeList>  CComAttributeList;

