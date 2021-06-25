// AttributeList.cpp : Implementation of CAttributeList

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#include "stdafx.h"
#include "AttributeList.h"


// CAttributeList


STDMETHODIMP CAttributeList::get_item(LONG index, IAttribute ** listItem)
{
	CVarDefPtr var = _vars->at(index);
	*listItem=NULL;
	if(var!=NULL)
		return var->QueryInterface(IID_IAttribute, (void**)listItem );
	return S_OK;
}

STDMETHODIMP CAttributeList::get_length(LONG* pVal)
{
	*pVal = _vars->size();
	return S_OK;
}

STDMETHODIMP CAttributeList::reset(void)
{
	_nCurIndex=0;
	return S_OK;
}

STDMETHODIMP CAttributeList::nextAttribute(IAttribute ** nextItem)
{
	if(_nCurIndex >= _vars->size())
		return E_FAIL;
	_nCurIndex++;
	return get_item(_nCurIndex-1, nextItem); 
}

STDMETHODIMP CAttributeList::get__newEnum(IUnknown ** pVal)
{
	CComAttributeList * list = new CComAttributeList();
	list->Init(_vars);
	return list->QueryInterface(IID_IAttributeList, (void**) pVal );
}


STDMETHODIMP CAttributeList::back(IAttribute ** listItem)
{
	*listItem =NULL;
	if(_vars->size() < 1)
		return S_OK;
	return get_item(_vars->size() -1 , listItem); 
}

STDMETHODIMP CAttributeList::size(/*[out, retval]*/ LONG* pVal)
{
	if(_vars==NULL)
		return E_FAIL;
	*pVal = _vars->size();
	return S_OK;

}
