// HelpInfo.cpp : Implementation of CHelpInfo

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#include "StdAfx.h"
#include "HelpInfo.h"


CHelpInfo::CHelpInfo(void)
{
#include "Machininghelp.cpp"
#include "Millinghelp.cpp"

}

CHelpInfo::~CHelpInfo(void)
{
}

STDMETHODIMP CHelpInfo::GetVariableDescription(/*[in]*/ BSTR classname, /*[in]*/ BSTR variablename, /*[out, retval]*/  BSTR * pVal)
{

	bstr_t szHelp = (LPCTSTR) description[StrFormat(_T("%s.%s.description"), (LPCTSTR) _bstr_t(classname), (LPCTSTR) _bstr_t(variablename))];
	*pVal =szHelp.Detach();
	return S_OK;

}
STDMETHODIMP CHelpInfo::GetClassDescription(/*[in]*/ BSTR classname, /*[out, retval]*/  BSTR * pVal)
{
	bstr_t szHelp = (LPCTSTR) description[StrFormat(_T("%s.description"), (LPCTSTR) (LPCTSTR) _bstr_t(classname))];
	*pVal =szHelp.Detach();
	return S_OK;

}
