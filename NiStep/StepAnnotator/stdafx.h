// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#pragma once

// Change these values to use different versions
#define WINVER		0x0500
#define _WIN32_WINNT	0x0501
#define _WIN32_IE	0x0501
#define _RICHEDIT_VER	0x0200

#include <atlbase.h>
#include <atlapp.h>

extern CAppModule _Module;

#include <atlcom.h>
#include <atlhost.h>
#include <atlwin.h>
#include <atlctl.h>

#include <atlframe.h>
#include <atlctrls.h>
#include <atldlgs.h>
#include <atlctrlx.h>
#include <atlsplit.h>
#include <atlsafe.h>

#if defined _M_IX86
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
  #pragma comment(linker, "/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#pragma warning(disable: 4800) //warning C4800: forcing value to bool 'true' or 'false' (performance warning)
#pragma warning(disable: 4018) //warning C4018: '<' : signed/unsigned mismatch
#pragma warning(disable: 4244) //warning C4244: 'argument' : conversion from 'double' to 'LPARAM', possible loss of data
#pragma warning(disable: 4267) //warning C4244: 'argument' : conversion from 'double' to 'LPARAM', possible loss of data
#pragma warning(disable: 4312) //warning C4244: conversion from 'OPCHANDLE' to 'OPCItem *' of greater size
#pragma warning(disable: 4800) //warning C4800: forcing value to bool 'true' or 'false' (performance warning)
#pragma warning(disable: 4018) //warning C4018: '<' : signed/unsigned mismatch
#pragma warning(disable: 4996) 
#pragma warning(disable: 4311)
#pragma warning(disable: 4996)
#pragma warning(disable: 4541)

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <sstream>
#include <iosfwd>
#ifdef UNICODE
typedef std::wstring  tstring;
typedef	std::wifstream tifstream;
typedef std::wstringstream  tstringstream;
typedef std::wstreambuf tstreambuf;
typedef std::wfstream tfstream;
typedef	std::wofstream tofstream;
#define t_str w_str
#else
typedef std::string  tstring;
typedef	std::ifstream tifstream;
typedef std::stringstream  tstringstream;
typedef std::streambuf tstreambuf;
typedef std::fstream tfstream;
#define t_str c_str
typedef	 std::ofstream tofstream;
#define A2T(X) X

#endif

//#import "NiStep.dll"
//#include "c:\Program Files\NIST\proj\Tests\NiStep\NiStep\NiStep_i.h"
#import "c:\Program Files\NIST\proj\STEPNCPP\NiStep\NiStep\Debug\NiStep.tlb"
#include "Debug\NiStep.tlh"

#if 1
typedef CComPtr<NiStepLib::IAttribute> CVarDefPtr;
typedef NiStepLib::IAttribute CVarDef;
typedef NiStepLib::INode IStepNode;
typedef NiStepLib::IAttributeList CVarDefs;
using namespace NiStepLib;
typedef NiStepLib::INodePtr IStepNodePtr;

#else

typedef CComPtr<IAttribute> CVarDefPtr;
typedef IAttribute CVarDef;
typedef CComPtr<INode> IStepNodePtr;
typedef INode IStepNode;
typedef IAttributeList CVarDefs;
#endif

#define GetVarDefs   GetAttributeList
#define  ExpressClassname Classname
#define Swap SwapListItems
//#define IsListType isListType
//#define IsASimpleListType isASimpleListType
//#define IsSimpleListType  isSimpleListType
//#define IsSimpleType isSimpleType

std::ofstream  __declspec(selectany)	debugstream;

#define OUTPUT_DEBUG_STRING(X) OutputDebugString(X)
#define OUTPUT_ERROR_STRING(X) OutputDebugString(X)

LPCTSTR __declspec(selectany) lpcstrXmlFilter = 
	_T("Xml Files (*.xml)|*.xml||")
	_T("");