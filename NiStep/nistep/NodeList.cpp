// NodeList.cpp : Implementation of CNodeList

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#include "stdafx.h"
#include "NodeList.h"
#include "AttributeList.h"


// CNodeList

/** COM property for Step Node's list classname. @param[out] pVal pointer to bstring pointer to store list classname.*/
STDMETHODIMP CNodeList::get_ListClassname(/*[out, retval]*/BSTR* pVal){	*pVal=_nodes->ExpressListClassname().AllocSysString();	return S_OK;}

/** COM property for Step Node's Name, such as #1. @param[out] pVal pointer to bstring pointer to store name.*/
STDMETHODIMP CNodeList::get_Name(/*[out, retval]*/BSTR* pVal){	*pVal=_nodes->Name().AllocSysString();	return S_OK; }

/** COM property for Step Node's express schema classname. @param[out] pVal pointer to bstring pointer to store classname.*/
STDMETHODIMP CNodeList::get_Classname(/*[out, retval]*/BSTR* pVal){	*pVal=_nodes->ExpressClassname().AllocSysString();	return S_OK; }

/** COM property for Step Node's express schema type. @param[out] pVal pointer to StepNodeType to store type.*/
STDMETHODIMP CNodeList::get_Type(/*[out, retval]*/StepNodeType* pVal){	*pVal = _nodes->Type(); return S_OK; } 

/** COM property for Step Node list's express schema type. Node's type is list. @param[out] pVal pointer to StepNodeType to store  list type.*/
STDMETHODIMP CNodeList::get_ListType(/*[out, retval]*/StepNodeType* pVal){	*pVal = _nodes->ListType(); return S_OK; }

/** COM method to determine if Step Node type is simple type. 
Simple types are: string_,  integer_, real_, boolean_, number_, logical_, enumeration_.
@param[out] pVal pointer to variant bool to store true if it is false otherwise.*/
STDMETHODIMP CNodeList::IsSimpleType(/*[out, retval]*/VARIANT_BOOL* flag) { *flag = _nodes->IsSimpleType()? VARIANT_TRUE : VARIANT_FALSE; return S_OK; }

/** COM method to determine if Step Node type is list. @param[out] pVal pointer to variant bool to store true if it is false otherwise.*/
STDMETHODIMP CNodeList::IsListType(/*[out, retval]*/VARIANT_BOOL* flag){*flag = _nodes->ISymbolBase::IsListType()? VARIANT_TRUE : VARIANT_FALSE; return S_OK;}


STDMETHODIMP CNodeList::get_item(LONG index, INode ** listItem)
{
	if(index < 0 || index >= _nodes->size())
		return E_INVALIDARG;

	IStepNodePtr node = _nodes->at(index);
	*listItem=NULL;
	if(node!=NULL)
		return node->QueryInterface(IID_INode, (void**)listItem );
	return S_OK;
}

STDMETHODIMP CNodeList::get_length(LONG* pVal)
{
	return size(pVal);
}

STDMETHODIMP CNodeList::size(LONG* pVal)
{
	*pVal = _nodes->size();
	return S_OK;
}

STDMETHODIMP CNodeList::reset(void)
{
	_nCurIndex=0;
	return S_OK;
}

STDMETHODIMP CNodeList::nextNode(INode ** nextItem)
{
	// what happens when 
	if(_nCurIndex >= _nodes->size())
		return E_FAIL;
	_nCurIndex++;
	return get_item(_nCurIndex-1, nextItem); 
}

STDMETHODIMP CNodeList::get__newEnum(IUnknown ** pVal)
{
	CComNodeList * list = new CComNodeList();
	list->Init(_nodes);
	return list->QueryInterface(IID_INodeList, (void**) pVal );
}


STDMETHODIMP CNodeList::back(INode ** listItem)
{
	*listItem =NULL;
	if(_nodes->size() < 1)
		return S_OK;
	return get_item(_nodes->size() -1 , listItem); 
}

STDMETHODIMP CNodeList::push_back(/*[in]*/ BSTR bstrClassname,/*[in]*/BSTR bstrName, /*[out,retval]*/ INode ** newListItem)
{
	*newListItem = NULL;
	IStepNodePtr pNode =   CClassGenerators::gClassGenerators.CreateClass((LPCTSTR) bstr_t(bstrClassname), _T(""));
	if(pNode==NULL)
		return E_INVALIDARG;
	pNode->_refs++;  // push back should increment it..
	_nodes->push_back(pNode, (LPCTSTR) _bstr_t(bstrName)); 
	*newListItem = (INode *) pNode.get();
	return S_OK;

}



/**
 * Deletes the  child node from the Node list described by the Node pointer. 
 * Must be node list or returns E_FAIL;
 * @param  pNode in pointer to store COM Node pointer.
*/
STDMETHODIMP CNodeList::DeleteChild(/*[in]*/ INode * pNode)
{
	_nodes->DeleteChild((IStepNode *)pNode);
	return S_OK;
}

/**
 * Returns the list index matching the given attribute descriptor. 
 * Must be node list or returns E_FAIL;
 * @param  pAttr attribute COM pointer
 * @param  pVal pointer to long to store index.
*/
STDMETHODIMP CNodeList::GetIndex(/*[in]*/ IAttribute * pAttr, /*[out, retval]*/ LONG * pVal)
{
	*pVal = _nodes->GetIndex((CVarDef*) pAttr); 
	return S_OK;
}


/**
 * Returns a t/f if classname described by bstring is simple list type. 
  * @param  bstrClassname  classname described by bstring
* @param  flag pointer to boolean variant to store flag.
*/
STDMETHODIMP CNodeList::IsASimpleListType(/*[in]*/ BSTR bstrClassname, /*[out, retval]*/  VARIANT_BOOL* flag)
{
	CString szClassname((LPCSTR) _bstr_t(bstrClassname));
	IStepNodePtr step =  CClassGenerators::gClassGenerators.CreateClass(szClassname, _T(""));
	*flag = VARIANT_FALSE;
	if(step==NULL)
		return E_INVALIDARG;

	if(_nodes->IsASimpleListType(szClassname))  
		*flag = VARIANT_TRUE;
	return S_OK;
}


/**
 * Stores  INode list item into given index position. 
 * Must be node list or returns E_FAIL;
  * Must be valid index or returns E_INVALIDARG;
 * @param  nVal  index into list.
 * @param  pNode  COM Node pointer to put into list at index nVal.
*/
STDMETHODIMP CNodeList::SetListItem(/*[in]*/ LONG nVal, /*[in]*/ INode * pNode)
{
	if(nVal< 0 || nVal >= _nodes->size())
		return E_INVALIDARG;
	_nodes->at(nVal)= (IStepNode *) pNode; 
	return S_OK;
}


/**
 * swaps two items in a Step node list. 
 * Must be step node list or returns E_FAIL;
  * Index1 Must be valid index or returns E_INVALIDARG;
  * Index2 Must be valid index or returns E_INVALIDARG;
 * @param  index1  valid index into list.
 * @param  index2  valid index into list.
*/
STDMETHODIMP CNodeList::SwapListItems(/*[in]*/ LONG index1, /*[in]*/ LONG index2)
{
	if(index1 < 0 || index1 >= _nodes->size())
		return E_INVALIDARG;
	if(index2 < 0 || index2 >= _nodes->size())
		return E_INVALIDARG;
	if(index1==index2)
		return S_OK;
	_nodes->Swap(index1, index2);
	return S_OK;

}


/********************************************************************************* 
COM method to determine if Step Node type is simple list type (int, real, string etc). 
@param[out] pVal pointer to variant bool to store true if it is false otherwise.
*/
STDMETHODIMP CNodeList::IsSimpleListType(/*[out, retval]*/VARIANT_BOOL* flag)
{
	*flag = _nodes->ISymbolBase::IsSimpleListType()? VARIANT_TRUE : VARIANT_FALSE; 
	return S_OK;
}


/********************************************************************************* 
COM method that returns Simple list variable's value as string. 
@param[in] bstrDelimiter as field separator 
@param[out] pVal pointer to bstring to store value.*/
STDMETHODIMP CNodeList::GetListVarString(/*[in*/BSTR bstrDelimiter, /*[out, retval]*/BSTR* pVal)
{	
	CString str = _nodes->GetVarString((LPCTSTR) _bstr_t(bstrDelimiter));	
	*pVal = str.AllocSysString(); 
	return S_OK;
}
/********************************************************************************* 
COM method that set a STEP node variable using input string. 
@param[in] bstr bstring containg value to store.
@param[in] bstrDelimiter as field separator 
*/
STDMETHODIMP CNodeList::SetListVarString(/*[in*/ BSTR bstr, /*[in*/BSTR bstrDelimiter) 
{	
	// FIXME: no delimiter use...
	_nodes->SetVarString((LPCWSTR) bstr);	
	return S_OK;
}


STDMETHODIMP CNodeList::GetStepNode(/*[out, retval]*/ INode ** ppNode)
{

	if(ppNode==NULL)
		return E_INVALIDARG;
	if(_nodes == NULL)
		return E_FAIL;
	return _nodes->QueryInterface(IID_INode, (void**) ppNode );
}


/**
 * get the attributes associated with this Step Node. List can be zero length. 
 * Will create a new  IAttributeList COM instance to return.
 * @param  pVal  pointer to attribute list pointer to store list.
*/
STDMETHODIMP CNodeList::GetAttributeList(/*[out, retval]*/ IAttributeList ** pVal) 
{ 
	// this
	//CComAttributeList * list = new CComAttributeList();
	CComAttributeList * list ;
	if(FAILED( CComAttributeList::CreateInstance(&list)))
		return E_FAIL;
	list->AddRef();
	std::vector<CVarDefPtr> * ptr = _nodes->GetVarDefsPtr();
	list->Init(ptr);
	return list->QueryInterface(IID_IAttributeList, (void**) pVal );
}
