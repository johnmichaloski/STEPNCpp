//
// Variable.cpp : Implementation of CVariable
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#include "stdafx.h"
#include "Variable.h"
#include "ExpressUtils.h"
#include "Stepnode.h"
#include "AttributeList.h"
#include "NodeList.h"


// CVarDef

STDMETHODIMP CVarDef::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IAttribute
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}



/**
* Produces xml representation of the step nodes tree. 
* project entity is the root node.
* @param  bstrString  pointer to bstrString to store xml representation.
*/
STDMETHODIMP CVarDef::ToXmlString(/*[out,retval]*/  BSTR* bstrString)
{
	if(bstrString==NULL)
		return E_INVALIDARG;

	bstr_t tmp;

#if 0
	IStepNodePtr pNode=GetStepNodePtr();

	if(pNode!=NULL)
	{
		tmp+=bstrFormat(_T("<%s classname=\"%s\">\n"), (LPCTSTR) this->Name(),(LPCTSTR) pNode->ExpressClassname());
		tmp+=(LPCTSTR) DumpCVarDefs(pNode->GetVarDefs(), true);
		tmp+=bstrFormat(_T("</%s>\n"), this->Name());
	}
#endif
	CString tabs;
	tmp+=(LPCTSTR) DumpCVarDef(this, tabs);

	*bstrString=tmp.Detach(); // WSTRClone(tmp);
	return S_OK;
}

/**
* Parses bstring XML representation to create a STEPNC instance tree into the attribute's node.
* @param  bstrString   XML string representing step instance tree.
*/
STDMETHODIMP CVarDef::FromXmlString(/*[in]*/ BSTR bstrString)
{
	ImportXmlParameterList(this, (LPCTSTR) bstrString);
	return S_OK;

}

/**
* Type checks the bstring XML representation against the the given STEPNC variable instance definition.
* @param[in] bstrString   XML string representing step instance tree.
* @param[out] flag pointer to variant bool to store true type check matches, false otherwise.
*/
STDMETHODIMP CVarDef::TypeCheckXmlString(/*[in]*/ BSTR bstrString, /*[out,retval]*/ VARIANT_BOOL *bResult)
{
	if(bResult==NULL)
		return E_INVALIDARG;

	*bResult = TypeCheckXmlParameterList(this, (LPCTSTR) bstrString) ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}

/**
 * If the attribute variable definition is a list, clears the list (deletes all the items). 
 * If attribute is not a list, deletes the attributes node pointer.
 * Will not delete list index items. Use deletechild instead.
*/

STDMETHODIMP CVarDef::Clear()
{
	if(ISymbolBase::IsListType())
	{
		EListT<IStepNodePtr> * step=  (EListT<IStepNodePtr> *) m_ref;
		step->clear();
	}
	else if(Type() == index_ )
	{

	}
	else
	{
		IStepNodePtr & step=  *(IStepNodePtr *) m_ref;
		step = NULL;
	}
	return S_OK;
}

/**
 * Returns the owner of this attribute variable instance. 
 * If no owner, returns E_FAIL.
 * @param  ppNode  pointer to node pointer to store owner.
*/
STDMETHODIMP CVarDef::Owner(/*[out, retval]*/ INode ** ppNode)
{
	*ppNode=NULL;
	IStepNodePtr step = this->Owner() ;
	if(step!=NULL)
		return step->QueryInterface(IID_INode, (void**)ppNode );
	return E_FAIL;
}

/**
 * Returns the attribute variable pointer to a step node instance. 
 * If no instance, returns NULL.
 * @param  ppNode  pointer to node pointer to store step node.
*/
STDMETHODIMP CVarDef::GetStepNode(/*[out, retval]*/ INode ** ppNode)
{
	*ppNode=NULL;
	IStepNodePtr step = GetStepNodePtr() ;
	if(step!=NULL)
		step->QueryInterface(IID_INode, (void**)ppNode );
	return S_OK;
}
/**
 * Returns the a step node list  instance. 
 * If not  a list, returns NULL and fails.
 * @param  ppNode  pointer to node pointer to store step node.
*/
HRESULT CVarDef::GetNodeList(/*[out, retval]*/ INodeList ** pNodeList)
{
	// this
	*pNodeList=NULL;
	IStepNodePtr step = GetStepNodePtr() ;
	if(!step->IsListType())
		return E_FAIL;

	//CComAttributeList * list = new CComAttributeList();
	CComNodeList * list ;
	if(FAILED( CComNodeList::CreateInstance(&list)))
		return E_FAIL;
	list->AddRef();
	list->Init((EListT<IStepNodePtr>  *)(IStepNode *) step.get());
	return list->QueryInterface(IID_INodeList, (void**) pNodeList );

}

/**
 * Sets the   attribute variable pointer to the given step node COM instance. 
 * Instance can be null. FIxme - is this a refcnt problem.
 * @param  pNode  pointer to step node to set this attribute to.
*/
STDMETHODIMP CVarDef::SetStepNode(/*[in]*/ INode * pNode)
{
	this->m_ref=(DWORD) pNode;
	return S_OK;
}

/**
 * Gets the   attribute variable value. 
 * Uses the  attribute step node COM instance to retrieve value. 
 * Instance can be null. FIxme - is this a refcnt problem.
 * @param  pVal  pointer to bstring pointer to store value.
*/
STDMETHODIMP CVarDef::GetVarString(/*[out, retval]*/ BSTR* pVal)
{
	CString str = this->GetVarString();
	*pVal = str.AllocSysString();
	return S_OK;
}

/**
 * Clones the  attribute variable  (and its branch, i.e. all its subelements). 
 * @param  pTo  pointer to existing attribute variable to store clone values.
*/

STDMETHODIMP CVarDef::Clone(/*[in]*/  IAttribute * pTo)
{
	CloneCVarDef(this, (CVarDef *) pTo);
	return S_OK;
}

/**
 * Returns an attribute list only if attribute is  an special  "inherited" attribute variable which points to an attribute list. 
 * @param  pVal  pointer to  attribute variable list to list.
*/
STDMETHODIMP CVarDef::GetInheritedAttributeList(/*[out, retval]*/ IAttributeList ** pVal) 
{
	*pVal=NULL;

	if(this->Type() != special_)
		return E_FAIL;

	CComAttributeList * list ;
	if(FAILED( CComAttributeList::CreateInstance(&list)))
		return E_FAIL;

	list->AddRef();
	list->Init((CVarDefs *) this->m_ref);
	return list->QueryInterface(IID_IAttributeList, (void**) pVal );

}

	/** COM method to determine if Step Node type is class name is a simple type (int, real, string etc). 
	fails if invalid classname
	@param[in] bstrClassname class to test.
	@param[out] pVal pointer to variant bool to store true if it is false otherwise.
	*/
STDMETHODIMP CVarDef::IsASimpleType(/*[in]*/ BSTR bstrClassname, /*[out, retval]*/  VARIANT_BOOL* flag)
{
	*flag = VARIANT_FALSE;
	IStepNodePtr step =  CClassGenerators::gClassGenerators.CreateClass((LPCTSTR) bstr_t(bstrClassname), _T(""));
	if(step==NULL)
		return E_INVALIDARG;
	if( step->IsSimpleType())
	*flag = VARIANT_TRUE;
	return S_OK;
}


STDMETHODIMP CVarDef::CreateNode(/*[in]*/ BSTR classname, /*[out, retval]*/ INode ** ppNode)
{
	IStepNodePtr step = CClassGenerators::gClassGenerators.CreateClass((LPCTSTR) bstr_t(classname), _T(""));
	step->_refs++; // this is a hack for now...
	if(step==NULL)
		return E_INVALIDARG;
	this->m_ref=(DWORD) step.get();
	return step->QueryInterface(IID_INode, (void **) ppNode);
}



////////////////////////////////////////////////////////////////////////
bool CVarDef::IsSimpleListType() 
{ 		
	if(!ISymbolBase::IsListType())
		return false;
	EListT<IStepNodePtr> * list=  (EListT<IStepNodePtr> *) this->m_ref;
	if(list==NULL)  // should never ever be null.
		return false;
	return list->IsASimpleListType(this->ListClassname());
}

IStepNode * CVarDef::GetStepNodePtr() 
{ 
	if(IsSimpleType() || Type() == typereference_ || Type() == 	entity_  || Type() == 	reference_)
	{
		return  *(IStepNode **) m_ref;
	}
	else if(Type() == 	select_)
	{
		ESelection * sVal= *(ESelection **) m_ref;
		return sVal-> GetSelection().get();
	}
	else if(Type() == 	index_)
	{
		return  (IStepNode *) m_ref; 
	}
	else if(Type() == 	bag_)
	{
		return (IStepNode *) m_ref;
	}
	return (IStepNode *) m_ref; 
}

CVarDefPtr CVarDef::GetPrimitiveVarDef()
{
	IStepNode * step = GetStepNodePtr();
	CVarDefPtr vardef = this;
	if(step==NULL)
		return vardef;

	if(IsSimpleType())
		return vardef;

	while(step->GetVarDefs().size() == 1)
	{
		CVarDefPtr vardef = step->GetVarDefs().at(0);  // do any not have one?
		if(vardef==NULL)
			return vardef;
		if(vardef->IsSimpleType())
			return vardef;
		step= vardef->GetStepNodePtr(); // GetThisRef(vardef, -1);
		if(step==NULL)
			return vardef;
	}
	return vardef;
}
CString CVarDef::GetVarString(CString fmt) 
{
	// this

	if(IsSimpleType())
	{
		return Owner()->GetVarString();
	}
	if(Type() == 	bag_)
	{
		EListT<IStepNodePtr> * list=  (EListT<IStepNodePtr> *) m_ref;
		return list->GetVarString(fmt);
	}
	if(Type() == 	index_)
	{
		IStepNodePtr step=  (IStepNode *) m_ref; 
		return step->GetVarString(fmt);
	}
	IStepNodePtr step=  *(IStepNode **) m_ref;
	if(step==NULL)
		return _T("$");

	return _T("");
}

HRESULT CVarDef::SetVarString(CString val) 
{
	// this  UNTESTED?

	if(IsSimpleType())
	{
		Owner()->SetVarString(val);
	}
	if(Type() == 	bag_)
	{
		EListT<IStepNodePtr> * list=  (EListT<IStepNodePtr> *) m_ref;
		if(list->ISymbolBase::IsSimpleListType())
			list->SetVarString(val);
	}
	if(Type() == 	index_)
	{
		IStepNodePtr step=  (IStepNode *) m_ref; 
		step->SetVarString(val);
	}
	CVarDefPtr vardef = GetPrimitiveVarDef();

	IStepNodePtr step=  vardef->GetStepNodePtr();
	if(step!=NULL)
		step->SetVarString(val);

	return S_OK;
}