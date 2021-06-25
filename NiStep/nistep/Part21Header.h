// Part21Header.h : Declaration of the CPart21Header

#pragma once
#include "resource.h"       // main symbols

#include "NiStep_i.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CPart21Header

class ATL_NO_VTABLE CPart21Header :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPart21Header, &CLSID_Part21Header>,
	public IDispatchImpl<IPart21Header, &IID_IPart21Header, &LIBID_NiStepLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CPart21Header()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_PART21HEADER)

DECLARE_NOT_AGGREGATABLE(CPart21Header)

BEGIN_COM_MAP(CPart21Header)
	COM_INTERFACE_ENTRY(IPart21Header)
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

public:

};

OBJECT_ENTRY_AUTO(__uuidof(Part21Header), CPart21Header)
