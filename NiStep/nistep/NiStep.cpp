// NiStep.cpp : Implementation of DLL Exports.


#include "stdafx.h"
#include "resource.h"
#include "NiStep_i.h"
#include "dllmain.h"
#include "dlldatax.h"


/*! \mainpage STEPNC++ Index Page
 *
 * \section intro_sec Introduction
 *
	STEPNC++ is an open-source software package for translating feature-based STEP-NC CAM files into feature-based CNC programs in a portable, standard manner. 
    STEP-NC is the colloquial term that refers to both International Organisation for Standardisation (ISO) 14649 and ISO 10303-AP238, where ISO 14649 is the Application Reference Model (ARM) schema, and  ISO 10303 AP238, is the reinterpretation of ISO 14649 into the fully-integrated Application Integrated Model (AIM) schema. 
    STEPNC++ currently only works with the ISO 14649 family of machining standards.

	STEPNC++ contains a Microsoft COM component to read/parse STEP NC Part 21 files, and then generates a STEPNC instance tree based on the Express schema.
	This component can be used by C++, Visual Basic or C# to parse the Part 21.

The STEPNC++ COM component allow one to create, read, and write ISO Part 21 files based on ISO 14649 Parts 10 and 11 schemas. 
However, the critical STEPNC++ functionality is the ability to traverse the STEPNC++ instance hierarchy and extract the desired feature-based CNC knowledge based on SPath, 
which is tree travesal language similar to XML XPath. 
EXPRESS relies heavily on the inheritance class hierarchy, which uses supertype and subtype relationships to refine parameterization. 
Often, EXPRESS defines a supertype from which subtypes derive, many times in a long, multi-pronged inheritance chain. 
STEPNC++ provides EXPRESS tree path and query navigation SPath tool as well as Entity metaclass knowledge, such as the class name, and super and subtype inheritance hierarchy. 
STEPNC++ also provides access to knowledge about the entity variables and methods as well as operations for creating new objects of the class.

STEPNC++ provides Spath and similar API to the XML Document Object Model (DOM) Core API, which allows population of a Document object using only DOM API calls; 
creating the skeleton Document and saving it persistently is left to the product that implements the DOM API. 

 * \section install_sec Installation
 *
 * \subsection step1 Step 1: Opening the box
 *  
 * etc...
 */



// Used to determine whether the DLL can be unloaded by OLE
STDAPI DllCanUnloadNow(void)
{
#ifdef _MERGE_PROXYSTUB
    HRESULT hr = PrxDllCanUnloadNow();
    if (hr != S_OK)
        return hr;
#endif
    return _AtlModule.DllCanUnloadNow();
}


// Returns a class factory to create an object of the requested type
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
#ifdef _MERGE_PROXYSTUB
    if (PrxDllGetClassObject(rclsid, riid, ppv) == S_OK)
        return S_OK;
#endif
    return _AtlModule.DllGetClassObject(rclsid, riid, ppv);
}


// DllRegisterServer - Adds entries to the system registry
STDAPI DllRegisterServer(void)
{
    // registers object, typelib and all interfaces in typelib
    HRESULT hr = _AtlModule.DllRegisterServer();
#ifdef _MERGE_PROXYSTUB
    if (FAILED(hr))
        return hr;
    hr = PrxDllRegisterServer();
#endif
	return hr;
}


// DllUnregisterServer - Removes entries from the system registry
STDAPI DllUnregisterServer(void)
{
	HRESULT hr = _AtlModule.DllUnregisterServer();
#ifdef _MERGE_PROXYSTUB
    if (FAILED(hr))
        return hr;
    hr = PrxDllRegisterServer();
    if (FAILED(hr))
        return hr;
    hr = PrxDllUnregisterServer();
#endif
	return hr;
}

// DllInstall - Adds/Removes entries to the system registry per user
//              per machine.	
STDAPI DllInstall(BOOL bInstall, LPCWSTR pszCmdLine)
{
    HRESULT hr = E_FAIL;
    static const wchar_t szUserSwitch[] = _T("user");

    if (pszCmdLine != NULL)
    {
    	if (_wcsnicmp(pszCmdLine, szUserSwitch, _countof(szUserSwitch)) == 0)
    	{
    		AtlSetPerUserRegistration(true);
    	}
    }

    if (bInstall)
    {	
    	hr = DllRegisterServer();
    	if (FAILED(hr))
    	{	
    		DllUnregisterServer();
    	}
    }
    else
    {
    	hr = DllUnregisterServer();
    }

    return hr;
}


