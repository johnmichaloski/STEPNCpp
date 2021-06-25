#pragma once
#include <map>
#include "Misc.h"

// HelpInfo.h : Declaration of the CHelpInfo

#pragma once
#include "resource.h"       // main symbols

#include "NiStep_i.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

// CHelpInfo

class ATL_NO_VTABLE CHelpInfo :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CHelpInfo, &CLSID_HelpInfo>,
	public IDispatchImpl<IHelpInfo, &IID_IHelpInfo, &LIBID_NiStepLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	std::map<CString, CString> description;


	CHelpInfo();
	~CHelpInfo(void);

DECLARE_REGISTRY_RESOURCEID(IDR_HELPINFO)

DECLARE_NOT_AGGREGATABLE(CHelpInfo)

BEGIN_COM_MAP(CHelpInfo)
	COM_INTERFACE_ENTRY(IHelpInfo)
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
	STDMETHODDECL GetVariableDescription(/*[in]*/ BSTR classname, /*[in]*/ BSTR variablename, /*[out, retval]*/  BSTR * pVal);
	STDMETHODDECL GetClassDescription(/*[in]*/ BSTR classname, /*[out, retval]*/  BSTR * pVal);

};

OBJECT_ENTRY_AUTO(__uuidof(HelpInfo), CHelpInfo)
