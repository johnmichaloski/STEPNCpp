// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef STRICT
#define STRICT
#endif

#include "targetver.h"

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit

#include "resource.h"
#include <atlbase.h>
#include <atlcom.h>
#include <atlctl.h>

using namespace ATL;
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
#else
typedef std::string  tstring;
typedef	std::ifstream tifstream;
typedef std::stringstream  tstringstream;
typedef std::streambuf tstreambuf;
typedef std::fstream tfstream;

#endif



#define OUTPUT_DEBUG_STRING(X) OutputDebugString(X)

// Hack to allow doxygen to parse methods. STDMETHOD(x) macro gives it fits.
#define STDMETHODDECL virtual COM_DECLSPEC_NOTHROW HRESULT STDMETHODCALLTYPE 

#include "NiStep_i.h"
