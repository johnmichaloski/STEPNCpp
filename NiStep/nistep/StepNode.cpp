// StepNode.cpp : Implementation of CStepNode

#include "stdafx.h"
#include "StepNode.h"
#include "ExpressUtils.h"
#include "StepPath.h"
#include "AttributeList.h"
#include "NodeList.h"

CClassGenerators  CClassGenerators::gClassGenerators;



// CStepNode

/** COM method to determine if interface suppors ErrorInfo @param[in] riid reference to guid describing interface.*/
STDMETHODIMP IStepNode::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_INode
	};

	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP IStepNode::get_ListClassname(/*[out, retval]*/BSTR* pVal){	*pVal=ExpressListClassname().AllocSysString();	return S_OK;}
STDMETHODIMP IStepNode::get_Name(/*[out, retval]*/BSTR* pVal){	*pVal=Name().AllocSysString();	return S_OK; }
STDMETHODIMP IStepNode::get_Classname(/*[out, retval]*/BSTR* pVal){	*pVal=ExpressClassname().AllocSysString();	return S_OK; }

STDMETHODIMP IStepNode::get_Type(/*[out, retval]*/StepNodeType* pVal){	*pVal = Type(); return S_OK; } 

STDMETHODIMP IStepNode::get_ListType(/*[out, retval]*/StepNodeType* pVal){	*pVal = ListType(); return S_OK; }


STDMETHODIMP IStepNode::GetVarString(/*[out, retval]*/BSTR* pVal){	CString str = this->GetVarString();	*pVal = str.AllocSysString(); return S_OK;}


STDMETHODIMP IStepNode::SetVarString(/*[in*/ BSTR bstr) {	this->SetVarString((LPCWSTR) bstr);	return S_OK;}



STDMETHODIMP IStepNode::IsSimpleType(/*[out, retval]*/VARIANT_BOOL* flag) { *flag = IsSimpleType()? VARIANT_TRUE : VARIANT_FALSE; return S_OK; }

/** COM method to determine if Step Node type is list. 
@param[out] flag pointer to variant bool to store true if it is false otherwise.*/
STDMETHODIMP IStepNode::IsListType(/*[out, retval]*/VARIANT_BOOL* flag){*flag = ISymbolBase::IsListType()? VARIANT_TRUE : VARIANT_FALSE; return S_OK;}

/** COM method to determine if Step Node type is simple list type (int, real, string etc). @param[out] flag pointer to variant bool to store true if it is false otherwise.*/
STDMETHODIMP IStepNode::IsSimpleListType(/*[out, retval]*/VARIANT_BOOL* flag){*flag = ISymbolBase::IsSimpleListType()? VARIANT_TRUE : VARIANT_FALSE; return S_OK;}





/**
* Returns the  descriptor for a given attribute.
* @param  attrname attribute name
* @param  pVal pointer to pointer to store IAttribute instance.
*/
STDMETHODIMP IStepNode::GetAttribute(/*[in]*/ BSTR attrname,  /*[out, retval]*/ IAttribute ** pVal)
{ 
	CVarDefPtr vardef = FindVarDef((LPCWSTR) attrname) ;
	if(vardef==NULL)
		return E_FAIL;
	return vardef->QueryInterface(IID_IAttribute, (void**) pVal );
}




/**
 * get the attributes associated with this Step Node. List can be zero length. 
 * Will create a new  IAttributeList COM instance to return.
 * @param  pVal  pointer to attribute list pointer to store list.
*/
STDMETHODIMP IStepNode::GetAttributeList(/*[out, retval]*/ IAttributeList ** pVal) 
{ 
	// this
	//CComAttributeList * list = new CComAttributeList();
	CComAttributeList * list ;
	if(FAILED( CComAttributeList::CreateInstance(&list)))
		return E_FAIL;
	list->AddRef();
	list->Init(this->GetVarDefsPtr());
	return list->QueryInterface(IID_IAttributeList, (void**) pVal );
}


HRESULT IStepNode::GetNodeList(/*[out, retval]*/ INodeList ** pVal)
{
	// this
	if(!this->IsListType())
		return E_FAIL;

	//CComAttributeList * list = new CComAttributeList();
	CComNodeList * list ;
	if(FAILED( CComNodeList::CreateInstance(&list)))
		return E_FAIL;
	list->AddRef();
	list->Init((EListT<IStepNodePtr>  *) this);
	return list->QueryInterface(IID_INodeList, (void**) pVal );

}

/**
 * Selects a Step Node List given an SPATH describing a step variable branch, and returns a IStepNodeList enumeration. 
 * Will create attribute nodes if not already defined. See SPATH for details.
 * @param  bstrPath  path describing attribute node to return. eg. for the root node, "main_workplan/its_elements[1]".
 * @param  ppNodeList  pointer to node list to store node.
*/
STDMETHODIMP IStepNode::SelectNodeList(/*[in]*/ BSTR bstrPath,  /*[out, retval]*/ INodeList ** ppNodeList)
{
	IStepNodePtr step = SelectNode((LPCWSTR) bstrPath);
	if(step==NULL)
		return E_FAIL;
	if(!step->IsListType())
		return E_FAIL;
	return step->GetNodeList(ppNodeList);
}



/**
 * Selects and returns a Step Node pointer given an SPATH describing a step variable branch. 
 * Will create attribute nodes if not already defined. See SPATH for details.
 * Example: If project is the current node:
	[in] SPath: "/main_workplan/its_elements[0]"
	[out]classname:  machining_workingstep
 * @param  bstrPath  path describing attribute node to return. eg. for the root node, "main_workplan/its_elements[1]".
 * @param  ppNode  pointer to pointer to store node.
*/
STDMETHODIMP IStepNode::SelectNode( BSTR bstrPath, /*[out, retval]*/ INode ** ppNode)
{
	IStepNodePtr step = SelectNode((LPCWSTR) bstrPath);
	if(step==NULL)
		return E_INVALIDARG;
	return step->QueryInterface(IID_INode, (void**)ppNode );
}


STDMETHODIMP IStepNode::GetAttributeClassname(/*[in]*/ BSTR bstrPath, /*[out, retval]*/ BSTR * pBstrClassname)
{

	IStepNodePtr step = SelectNode((LPCWSTR) bstrPath);
	if(step==NULL)
		return E_INVALIDARG;
	*pBstrClassname = _bstr_t(step->ISymbolBase::ExpressClassname()).Detach();
	return S_OK;

}

STDMETHODIMP IStepNode::SetAttributeNode(/*[in]*/ BSTR spath, /*[in]*/ INode * pNode,  /*[out, retval]*/ VARIANT_BOOL* flag)
{
	*flag = VARIANT_FALSE;
	CVarDefPtr vardef = SelectAttribute((LPCWSTR) spath);
	if(vardef==NULL)
		return S_OK;
	*flag = VARIANT_TRUE;	
	return vardef->SetStepNode(pNode);
}

STDMETHODIMP IStepNode::CreateAttributeNode(/*[in]*/ BSTR spath, /*[in]*/ BSTR classname, /*[out, retval]*/ INode ** ppNode)
{
	IStepNodePtr	step =   CClassGenerators::gClassGenerators.CreateClass((LPCTSTR) bstr_t(classname), _T(""));
	if(step==NULL)
		return E_INVALIDARG;
	CVarDefPtr vardef = SelectAttribute((LPCWSTR) spath);
	if(vardef==NULL)
		return E_INVALIDARG;
	
	Store(vardef, step);
	step->_refs++;
	return step->QueryInterface(IID_INode, (void**)ppNode );
}


STDMETHODIMP IStepNode::GetAttributeNodeList(/*[in]*/ BSTR spath, /*[out, retval]*/  INodeList ** ppNodeList)
{

	IStepNodePtr step = SelectNode((LPCWSTR) spath);
	if(step==NULL)
		return E_FAIL;

	return step->GetNodeList(ppNodeList);

}


/**
 * Selects and returns a Step Node pointer given an SPATH describing a step variable branch. 
 * Will create attribute nodes if not already defined. See SPATH for details.
 * @param  bstrPathVal   path describing attribute node to return. eg. for the root node, "main_workplan/its_elements[1]".
* @param  flag pointer to boolean variant to store flag.
*/
STDMETHODIMP IStepNode::AddAttribute(/*[in]*/ BSTR bstrPathVal, /*[out, retval]*/ VARIANT_BOOL* flag)
{

	if(FAILED(this->AddAttribute((LPCTSTR) _bstr_t(bstrPathVal))))
		*flag = VARIANT_FALSE;
	else
		*flag = VARIANT_TRUE;

	return S_OK;
}

STDMETHODIMP IStepNode::ToVector(/*[in]*/ BSTR bstrPathVal, /*[out, retval]*/ Vector3d* vector)
{

	std::vector<double> v = this->ToVector((LPCTSTR)  bstrPathVal);
	if(v.size() < 3)
		return E_FAIL;
	(*vector).x = v[0];
	(*vector).y = v[1];
	(*vector).z = v[2];

	return S_OK;

}

/**
 * Given an SPATH describing a step variable branch, will return the value at the given node. 
 * End node must be Express simple types: integer, string, boolean, real, enumeration. 
 * End node given as list of simple types also allowed.
 * Will create attribute nodes if not already defined. See SPATH for details.
 * @param  attrname  path describing attribute node to return. eg. for the root node, "main_workplan/its_elements[1]".
 * @param  vDefault  variant describing default value, if node does not exist.
 * @param  pVal  pointer to pointer to store variant value.
*/

STDMETHODIMP IStepNode::GetAttributeValue(/*[in]*/ BSTR attrname, /*[in]*/ VARIANT vDefault, /* [out, retval]*/ VARIANT * pVal)
{
	_variant_t val = this->GetAttributeValue((LPCWSTR) attrname, vDefault);
	* pVal = val.Detach();
	return S_OK;
}

STDMETHODIMP IStepNode::SetAttributeValue(/*[in]*/ BSTR attrname, /*[in]*/ VARIANT vValue,/*[out, retval]*/ VARIANT_BOOL* flag)
{

	CString  str(_T(""));
	try  {	str = (LPCTSTR)(_bstr_t)_variant_t(vValue); }  catch(...) { return E_INVALIDARG ; }
	*flag= VARIANT_TRUE;
	if(FAILED(this->SetAttributeValue((LPCWSTR) attrname, str)))
		*flag= VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP IStepNode::SetAttributeString(/*[in]*/ BSTR attrname, /*[in]*/ BSTR vStrValue, /*[out, retval]*/ VARIANT_BOOL* flag)
{
	*flag= VARIANT_TRUE;
	if(FAILED(this->SetAttributeValue((LPCWSTR) attrname, (LPCWSTR) vStrValue)))
		*flag= VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP IStepNode::IsKindOf(/*[in]*/ BSTR bstrClassname, /*[out, retval]*/ VARIANT_BOOL* flag)
{
	*flag = IsKindOf((LPCWSTR) bstrClassname)  ? VARIANT_TRUE : VARIANT_FALSE; 
	return S_OK;
}


STDMETHODIMP IStepNode::DoesPathExist(/*[in]*/ BSTR bstrPath, /*[out, retval]*/ VARIANT_BOOL* flag)
{
	*flag = IsExistingAttribute((LPCTSTR) _bstr_t(bstrPath))   ? VARIANT_TRUE : VARIANT_FALSE; 
	return S_OK;
}



CVarDefs IStepNode::getElementsByTagName(CString tagname)
{
	CVarDefs list;
	CStringVector visited;
	getElementsByCVarDefs(this->GetVarDefs(), visited, tagname, list);
	return list;
}


void IStepNode::getElementsByCVarDefs(CVarDefs &vars, CStringVector &visited, CString tagname, CVarDefs & list)
{
	CString tmp;
	for(int i=0; i<vars.size(); i++)
	{
		CVarDefPtr  vardef = vars[i];
		getElementByCVarDef(vardef, visited, tagname,  list);
	}
}

void IStepNode::getElementByCVarDef(CVarDefPtr vardef, CStringVector &visited, CString tagname, CVarDefs & list)
{

	visited.push_back('/'+ vardef->Name());
	OUTPUT_DEBUG_STRING(StrFormat(_T("**ENTER: %s  : %s \n"),     visited.ToString(_T("")), vardef->Name()));

	// special
	if((vardef->Name() == tagname) || (ExpDemangle( vardef->m_sClassname)== tagname))
	{
		list.push_back(vardef);
		goto done;

	}
	else if(vardef->Name() == tagname)
	{
		IStepNodePtr node = CClassGenerators::gClassGenerators.CreateClass(vardef->Classname(), _T("")); 
		if(node && node->IsKindOf(tagname))
		{
			list.push_back(vardef);
			goto done;
		}

	}
	else if(vardef->ListClassname() == tagname)
	{
		if(vardef->ListClassname()!="")
		{
			IStepNodePtr node = CClassGenerators::gClassGenerators.CreateClass(vardef->ListClassname(), _T("")); 

			if(node && node->IsKindOf(tagname))
			{
				list.push_back(vardef);
				goto done;
			}
		}

	}
	//if(vardef->Name()=="Eworkingstep")
	//	DebugBreak();

	if(vardef->Type() == 	special_)
	{
		getElementsByCVarDefs((CVarDefs) *(CVarDefs*)vardef->m_ref , visited, tagname,  list);
	}
	else if(vardef->Type() == 	entity_  || (vardef->Type() == 	reference_) )
	{
		IStepNodePtr child = *(IStepNode **) vardef->m_ref;
		if(child==NULL)
			goto done;
		getElementsByCVarDefs(child->GetVarDefs(), visited, tagname,  list);
	}
	else if((vardef->Type() == 	set_) || (vardef->Type() ==  list_))
	{
		if(vardef->m_nDimension==1)
		{
			std::vector<IStepNodePtr > &items= *(std::vector<IStepNodePtr> *)  vardef->m_ref;

			for (int i = 0; i<items.size(); i++)
			{
				if(items[i]==NULL) /* could be optional - but then how appended to list?*/
					continue;
				if(items[i]->Classname() == tagname || items[i]->IsKindOf(tagname) )
				{
					CVarDefPtr listvardef = new CVarDef(vardef->Owner(), vardef->Name(), list_item_,(DWORD) items[i].get(), items[i]->Classname());
					list.push_back(listvardef);
				}
				getElementsByCVarDefs( items[i]->GetVarDefs(), visited, tagname,  list);
			}
		}
	}
done:
	OUTPUT_DEBUG_STRING(StrFormat(_T("**EXIT: %s  : %s \n"),     visited.ToString(_T("")), vardef->Name()));
	visited.pop_back();

}


////////////////////////////////////////////////////////////////
int IStepNode::selectElementsByTagName(VarTable &table,CStringVector columns, CString fromnode,  int bDistinct)
{
	int i,j, k;
	VarList varlist;
	table.clear();
	CVarDefs list = getElementsByTagName(fromnode);
#if 1
	VarList values;
#else
	std::vector<VarList> values;
#endif
	for(j=0, k=0; k< list.size(); k++)
	{
		IStepNode  * node = GetThis(list[k]).get();
		values.clear();
		for(i=0; i< columns.size(); i++)
		{
			varlist.clear();
			CStringVector fields=CStringVector::Tokenize(columns[i], _T("."));

			// Case where already a simple type
			if(node==NULL)
				continue;

			getItemByCVarDefs(node->GetVarDefs(),  fields, varlist);
#if 1
			if(varlist.size()>0)
			{
				values.push_back(varlist[0]);
			}
			else
			{
				values.push_back("N/A");

			}
#else
			values.push_back(varlist);
#endif
		}
		if(bDistinct && table.isDuplicate(values))
			continue;
		table[j++]=values;
	}
	return 0;
}

bool IStepNode::getItemByCVarDefs(CVarDefs &vars,  CStringVector tagnames, VarList & list)
{

	for(int i=0; i<vars.size(); i++)
	{
		CVarDefPtr  vardef = vars[i];

		if(vardef->Type() == 	special_)
		{
			if(getItemByCVarDefs(*(CVarDefs *)vardef->m_ref, tagnames,  list))
				return true;
		}
		if(vardef->Name() == tagnames[0])
		{
			if(tagnames.size() == 1 )
			{
				// get value if simpletype
				list.push_back(GetVarDefVal( vardef));
				return true;
			}
			tagnames.erase(tagnames.begin());
			if(vardef->Type() == 	entity_  || (vardef->Type() == 	reference_))
			{
				IStepNodePtr child = *(IStepNode **) vardef->m_ref ; 
				if(child==NULL)
					return false;
				return getItemByCVarDefs(child->GetVarDefs(),  tagnames,  list);
			}
			// FIXME: could be list - would need to create a table of instances.
			if(vardef->Type() == 	set_ || vardef->Type() ==  list_)
			{
				std::vector<IStepNodePtr > &items= *(std::vector<IStepNodePtr> *)  vardef->m_ref;
				bool bFlag=false;
				for (int i = 0; i<items.size(); i++)
				{
					IStepNodePtr step = items[i] ;		
					bFlag |=getItemByCVarDefs(step->GetVarDefs(),  tagnames,  list);

				}
				return bFlag;
			}
		}
	}
	return false;
}
_variant_t IStepNode::GetVarDefVal(CVarDefPtr  vardef)
{
	if(vardef==NULL)
	{
		OUTPUT_DEBUG_STRING(_T("WARNING IStepNode::GetVarDefVal - Bad CVarDefPtr for  vardef\n"));
		return _variant_t();
	}

	if(vardef->Type() == 	integer_)
	{
		long * nVal=  (long *) vardef->m_ref;
		if(nVal==NULL )
			return _variant_t((const TCHAR *) _T("$"));
		return _variant_t((long)  *nVal);
	}
	else if(vardef->Type() == 	logical_ ||  vardef->Type() == 	boolean_)
	{
		CString str = vardef->GetVarString();
		return _variant_t((const TCHAR *)  str);
	}
	else if(vardef->Type() == 	enumeration_)
	{
		EEnum * eVal=  (EEnum *) vardef->m_ref;
		if(eVal==NULL )
			return _variant_t((const TCHAR *) _T("$"));
		return _variant_t((const TCHAR *)  eVal->GetEnum2String(eVal->m_nSelection).MakeUpper());
	}
	else if(vardef->Type() == 	real_)
	{
		return _variant_t((double)  *(double *) vardef->m_ref);
	}
	//else if(vardef->Type() == 	select_)
	//{
	//	ESelection * sVal= *(ESelection **) vardef->m_ref;
	//	IStepNodePtr pSel =sVal-> GetSelection();
	//	CString szenum = DumpCVarDefs(pSel->GetVarDefs());
	//	tmp.AppendFormat("%s, ", szenum);
	//}
	else if(vardef->Type() == 	string_)
	{
		CString * s= (CString *)vardef->m_ref;
		if(s==NULL)
			return _variant_t((const TCHAR *) _T("$"));
		return _variant_t((const TCHAR *) *s);
	}
	else if( (vardef->Type() == 	entity_)  || (vardef->Type() == 	reference_) )
	{
		IStepNodePtr step=  *(IStepNode **) vardef->m_ref;
		if(step==NULL)
			return 0;
		if(step->m_vars.size() > 0)
			return GetVarDefVal(step->GetVarDef(0));
		else
		{
			// honestly maybe typedefs should be made into separate classes with special_ inheritance chain.
			return _bstr_t(step->GetVarString());
		}
	}
	else if(vardef->Type() == 	list_item_   )
	{
		IStepNodePtr step=  (IStepNode *) vardef->m_ref;
		return GetVarDefVal(step->GetVarDef(0));
	}
	return _variant_t(VT_NULL);
}



bool IStepNode::IsExistingAttribute(CString attrname)
{
	CExpQueryParser attrs(attrname);
	IStepNodePtr step = this;
	std::vector<CVarDefPtr> * vars;

	for(int i=0; i< attrs.size(); i++)
	{
		CVarDefPtr vardef =  CVarDef::FindVarDef(step->GetInstanceVars(), attrs[i]);
		if(vardef == NULL)
			return false;

		step= GetThisRef(vardef);
		if(vardef == NULL)
			return false;

	}
	return true;

}
IStepNode * IStepNode::GetAttribute(CString attrname)
{
	CExpQueryParser attrs(attrname);
	IStepNode * _step = this;
	std::vector<CVarDefPtr> * vars;
	CVarDefPtr vardef;
	for(int i=0; i< attrs.size(); i++)
	{
		int n= attrs.Index(i);
		vardef =  CVarDef::FindVarDef(_step->GetInstanceVars(), attrs[i]);
		if(vardef == NULL)
			return NULL;

		_step= GetThisRef(vardef,n);
		if(_step == NULL)
			return  NULL;;

	}
	OutputDebugString(StrFormat(_T("%x\n"), _step));
	return _step;
 
}

CString IStepNode::GetAttributeExpClassname(CString attrname, CString strDefault)
{
	IStepNodePtr step = GetAttribute(attrname);
	if(step==NULL)
		return strDefault;

	return step->ExpressClassname();
}

CString IStepNode::GetAttributeValue(CString attrname)
{
#if 0
	// Works but string are not enclosed in '..' lists dont work either
	_variant_t val = this->GetAttributeValue((LPCWSTR) attrname, _variant_t((BSTR) L""));
	CString tmp;
	try{
	tmp = (LPCTSTR) (_bstr_t) val;
	}
	catch(...)
	{
		return tmp;
	}
	return tmp;
#endif
#if 1
	// Problem here is doesn't work well if not lowest primitive
	CVarDefPtr vardef = SelectAttribute(attrname);
	vardef = vardef->GetPrimitiveVarDef();
	CString tmp;
	if(vardef==NULL)
		tmp= _T("");
	else if(vardef->IsSimpleListType())
		tmp = vardef->GetVarString(_T(","));
	else
		tmp = vardef->GetVarString();
	return tmp;
#endif
}
_variant_t IStepNode::GetAttributeValue(CString attrname,_variant_t vDefault)
{
	CExpQueryParser attrs(attrname);
	IStepNode * step = this;   // must be IStepNode * since EListT will be deleted.
	std::vector<CVarDefPtr> * vars;
	CVarDefPtr vardef;
	int n;


	for(int i=0; i< attrs.size(); i++)
	{
		n= attrs.Index(i);

		vardef =  CVarDef::FindVarDef(step->GetInstanceVars(), attrs[i]);
		if(vardef == NULL)
			return vDefault;

		step= GetThisRef(vardef, n);

		if(step == NULL)
			return  vDefault;;

	}

	// This should get to simple type superchild
	while(vardef!=NULL && !vardef->IsSimpleType())
	{
		step= GetThisRef(vardef, n);
		if(step==NULL)
			return  vDefault;
		if(step->GetInstanceVars().size()< 1)
			return  vDefault;
		vardef = step->GetInstanceVars().at(0);  // do any not have one?

	}

	//  must have value;
	return GetVarDefVal(vardef);
	//IStepNodePtr step = GetThisRef(CVarDefPtr  vardef)	;
	//return step->GetValue();

}
bool IStepNode::IsPrimitive()
{
	IStepNode * step = this;

	if(step->Classname() ==  "length_measure")
	{
		DebugBreak();
	}
	if(step->IsSimpleType())
		return true;
	while(step->GetVarDefs().size() == 1)
	{
		//		CVarDefPtr vardef = step->GetInstanceVars().at(0);  // why isn't this instance vars?
		CVarDefPtr vardef = step->GetVarDefs().at(0);  // do any not have one?
		if(vardef==NULL)
			return false;
		if(vardef->IsSimpleType())
			return true;
		step= GetThisRef(vardef, -1);
		if(step==NULL)
			return false;
	}
	return false;
}


IStepNode * IStepNode::GetThisRef(CVarDefPtr  vardef, int index)
{
	if(vardef==NULL)
		return NULL;
	try {
		if(vardef->IsSimpleType())
		{
			return vardef->Owner();
		}
		else if(vardef->Type() == 	special_)
		{
			CVarDefs * vars = (CVarDefs *)vardef->m_ref;
			if(vars==NULL)
				return NULL;
			return vars->at(0)->Owner();
		}
		if(vardef->Type() == 	select_)
		{
			return *(IStepNode **) vardef->m_ref; // ESelection
		}
		else if(vardef->Type() == 	entity_ )
		{
			return *(IStepNode **) vardef->m_ref;
		}
		else if(vardef->Type() == 	reference_)
		{
			return *(IStepNode **) vardef->m_ref;
		}
		else if(vardef->Type() == 	index_)
		{
			EListT<IStepNodePtr> & list =  *(EListT<IStepNodePtr> *)vardef->Owner();
			int j = list.GetIndex(vardef);
			return list[j].get() ;
		}
		else if(vardef->Type() == 	bag_ )
		{
			EListT<IStepNodePtr > &items= *(EListT<IStepNodePtr > *)  vardef->m_ref;
			if(index<0 || index>=items.size())
			{
				return (EListT<IStepNodePtr > *)  vardef->m_ref;
			}
			return items[index].get() ;	
		}
		// assume simple type
		else return NULL;

	}
	catch(...)
	{

	}
	return NULL;
}



std::vector<double> IStepNode::ToVector(CString attrname)
{
	std::vector<double> v;
	IStepNode * step = GetAttribute(attrname);
	if(step==NULL)
		return v;
	if(step->ListType() == unknown_)
		return v;

	EListT<IStepNodePtr > &list= *(EListT<IStepNodePtr > *)  step;
	for(int i=0; i< list.size(); i++)
	{
		if(list[i]!=NULL)
			v.push_back(boost::get<double>(list[i]->GetValue()));
	}
	return v;
};


HRESULT IStepNode::SetAttributeValue(CString attrname, CString value)
{
	IStepNodePtr step = QueryAttribute(attrname); 
	if(step==NULL)
		return E_FAIL;
	step->SetVarString(value);
	return S_OK;

}

IStepNodePtr IStepNode::CreateAttributeNode(/*[in]*/ CString spath, /*[in]*/ CString classname)
{
	IStepNodePtr step =   CClassGenerators::gClassGenerators.CreateClass((LPCTSTR) classname, _T(""));
	if(step==NULL)
		return NULL;
	CVarDefPtr vardef = SelectAttribute((LPCWSTR) spath);
	if(vardef==NULL)
		return NULL;
	Store(vardef, step);
	return step;
}
IStepElements IStepNode::Branch(CString attrname)
{
	IStepElements elements;
	QueryAttributeBranch(attrname, elements);
	return elements;

}
IStepNodePtr IStepNode::QueryAttribute(CString attrname)
{
	IStepElements elements;
	IStepNodePtr step = QueryAttributeBranch(attrname, elements);
	return step;

}

IStepNodePtr IStepNode::QueryAttributeBranch(CString attrname, IStepElements & elements)
{
	CExpQueryParser attrs(attrname);
	IStepNodePtr step = this;   
	std::vector<CVarDefPtr> * vars;
	CVarDefPtr vardef;
	CString classname;
	int n;
	
	for(int i=0; i< attrs.size(); i++)
	{
		n= attrs.Index(i);
		classname= attrs.Classname(i);

		vardef =  CVarDef::FindVarDef(step->GetInstanceVars(), attrs[i]);
		if(vardef == NULL)
		{

			return NULL; // there must be an instance var unless there isn't a step
		}

		step= GetThisRef(vardef, n);

		// problem here - retrieve list, list item, what if list empty
		// FIXME: this should automatically add items if not there...
		if(vardef->ISymbolBase::IsListType() && n==CExpQueryParser::cNewListItem)
		{
			EListT<IStepNodePtr > &list= *(EListT<IStepNodePtr > *)  step.get();
			if(classname.GetLength()<1)
				classname=vardef->ExpressListClassname();
			step =   CClassGenerators::gClassGenerators.CreateClass(classname, _T(""));
			if(step == NULL)
				return  NULL;
			Store(vardef, step);
		}
		else if(step == NULL)
		{
			if(classname.IsEmpty())
				classname=vardef->ExpressClassname();
			step =   CClassGenerators::gClassGenerators.CreateClass(classname, _T(""));
			if(step == NULL)
				return  NULL;
			Store(vardef, step);
		}
		elements.push_back(step);
	}
	return step;

}

IStepNodePtr IStepNode::SelectNode(CString attrname)
{ 
	IStepNodePtr step = QueryAttribute(attrname); 
	if(step==NULL) 
		throw std::exception(); 
	return step; 
}


CVarDefPtr IStepNode::SelectAttribute(CString attrname)
{
	int n;
	CString parent, child;
	CExpQueryParser::ParentChild(attrname, parent, child);
	IStepNodePtr step = this;
	if(!parent.IsEmpty())
	{
		step = SelectNode(parent);
		if(step==NULL)
			return NULL;
	}
	CExpQueryParser::Prune(child);
	return CVarDef::FindVarDef(step->GetInstanceVars(), child);
}

CString IStepNode::QueryAttributePaths(CVarDefPtr vardef)
{
	CString szPath;

	std::vector<int> itstack;
	std::vector<Variables *> varstack;
	CStringVector treepath;

	std::vector<CVarDefPtr>  * vars= this->GetInstanceVarsPtr() ;
	treepath.push_back(vardef->Name());
	int it=0;

	while(1)
	{


		for(; it<vars->size(); )
		{
			//CString szTreePath;
			//for(int j=0; j<itstack.size(); j++)
			//{
			//	int k = itstack[j];
			//	szTreePath+=_T("/") + varstack.at(j)->at(k)->Name() ;
			//}
			if(vars->at(it)->IsSimpleType() || vars->at(it)->IsSimpleListType())
			{
				IStepNodePtr step = this->GetThisRef(vars->at(it));
				CString path;
				if(vars->at(it)->IsSimpleType())
					path =_T("/") + treepath.ToString(_T("/")) + _T(" = ") + step->GetVarString() + _T("\n");
				else
					path =_T("/") + treepath.ToString(_T("/")) + _T(" = ") + step->GetVarString(_T(",")) + _T("\n");
				szPath+=path;
				OutputDebugString(path);

				it=itstack.back();
				itstack.pop_back();
				vars=varstack.back();
				varstack.pop_back();
				treepath.pop_back();
				it++;

			}
			else
			{
				if(this->GetThisRef(vars->at(it))!=NULL)
				{
					IStepNodePtr step = this->GetThisRef(vars->at(it));
					CString path = vars->at(it)->Name();
					if(step->Classname() != vars->at(it)->Classname() ) 
						path+=StrFormat(_T("{@classname=%s}"), step->ExpressClassname());
					treepath.push_back(path);
					itstack.push_back(it);
					varstack.push_back(vars);
					vars = step->GetInstanceVarsPtr();
					it=0;
					continue;
				}
				else 
				{
					CString path=_T("/") + treepath.ToString(_T("/")) + _T("/") +  vars->at(it)->Name() +  _T("= NULL\n");
					szPath+=path;
					OutputDebugString(path);

					it++;
				}
			}

		}
		if(varstack.size()>0)
		{
			it=itstack.back();
			itstack.pop_back();
			vars=varstack.back();
			varstack.pop_back();
			treepath.pop_back();
			it++;

		}
		else break;

	}

	return szPath;
}

/** \fn STDMETHODIMP IStepNode::get_Classname([out, retval] BSTR* pVal)

COM property for Step Node's express schema classname. 
@param[out] pVal pointer to bstring pointer to store classname.
*/


/** \fn STDMETHODIMP IStepNode::get_ListType( [out, retval] StepNodeType* pVal)
COM property for Step Node list's express schema type. Node's type is list. 
@param[out] pVal pointer to StepNodeType to store  list type.
*/

/** \fn STDMETHODIMP IStepNode::get_Type([out, retval] StepNodeType* pVal) 
COM property for Step Node's express schema type. 
@param[out] pVal pointer to StepNodeType to store type.
*/

/** \fn STDMETHODIMP IStepNode::get_ListClassname( [out, retval] BSTR* pVal)

COM property for Step Node's list classname. 
@param[out] pVal pointer to bstring pointer to store list classname.
*/

/** \fn STDMETHODIMP IStepNode::GetVarString( [out, retval] BSTR* pVal)
COM method that returns Simple list variable's value as string. 
@param[out] pVal pointer to bstring to store true if it is false otherwise.
*/

/** \fn STDMETHODIMP IStepNode::SetVarString( [in]  BSTR bstr)
COM method that set a STEP node variable using input string. 
@param[in] bstr bstring containg value to store.
*/

/** \fn STDMETHODIMP IStepNode::IsSimpleType( [out, retval] VARIANT_BOOL* flag)
COM method to determine if Step Node type is simple type. 
Simple types are: string_,  integer_, real_, boolean_, number_, logical_, enumeration_.
@param[out] flag pointer to variant bool to store true if it is false otherwise.
*/

/** \fn STDMETHODIMP IStepNode::get_Name( [out, retval] BSTR* pVal)

COM property for Step Node's Name, such as #1. 
@param[out] pVal pointer to bstring pointer to store name.
*/

/** \fn STDMETHODIMP IStepNode::GetAttributeClassname ([in] BSTR bstrPath,[out, retval] BSTR * pBstrClassname)

* Using an SPATH describing a step variable branch returns the classname of the existing step node. 
* Step node must exist or E_INVALIDARG returned. See SPATH for details.
* \code Example: If the STEPNC root instance "project" is the current node:
[in] SPath: "/main_workplan/its_elements[0]"
[out]classname:  machining_workingstep
\endcode
* @param  bstrPath  path describing attribute node to return. eg. for the root node, "main_workplan/its_elements[1]".
* @param  pBstrClassname  pointer to bstr to store classname.
*/
