// StepNode.h : Declaration of the CStepNode

#pragma once
#include "resource.h"       // main symbols

#include "NiStep_i.h"
#include "Symbol.h"
#include "Variable.h"

//Base Class for all entity/class Declarations

class IStepList : public  std::vector<IStepNodePtr> 
{
public:
	CString DumpNodes() ;
};

typedef IStepList IStepElements;

class IStepNodeBase  : 
	public ISymbolBase,
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<IStepNode, &CLSID_Node>,
	public ISupportErrorInfo,
	public IDispatchImpl<INode, &IID_INode, &LIBID_NiStepLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	typedef IDispatchImpl<INode, &IID_INode, &LIBID_NiStepLib, /*wMajor =*/ 1, /*wMinor =*/ 0> DispatchImpl;

	IStepNodeBase()
	{		
		m_bAbstract=false;
		m_parent=NULL;
	}
	virtual ~IStepNodeBase() {}
	bool IsPrimitive();
	bool & Abstract() { return m_bAbstract; }
	CString tagName () { return Name(); }
	CString dataType() { return Classname();  }  // 
	StepNodeType nodeType() { return Type(); }

	virtual Variables & GetVarDefs() { return m_vars; }
	virtual Variables & GetInstanceVars() { return m_instancevars; }
	virtual Variables * GetInstanceVarsPtr() { return &m_instancevars; }
	virtual Variables * GetVarDefsPtr() { return &m_vars; }

	virtual CString GetVarString(CString fmt=_T("")) {return _T("None"); }
	virtual HRESULT SetVarString(CString str) { return E_NOTIMPL; }
	virtual EXPVariant GetValue() { return (long) 0; }

	virtual CStringVector GetInheritanceChain() { return m_parents; }
	virtual CStringVector GetSupertypesChain()  { return m_supertypes; }

	CVarDefPtr GetVarDef(int n) 
	{ 
		if(n>=GetVarDefs().size())
		{
			::DebugBreak();
		}
		return GetVarDefs()[n]; 
	}
	CVarDefPtr GetInstanceVar(int n) 
	{ 
		if(n>=GetInstanceVars().size())
		{
			// Fixme: could be storing string into EString... which doesn't have instance vars.
			::DebugBreak();
		}
		return this->GetInstanceVars()[n]; 
	}
	//	virtual CString DumpVars() { return DumpCVarDefs(*GetVarDefs()); }
	CVarDefPtr FindVarDef(CString name) 
	{ 	
		return CVarDef::FindVarDef(this->GetVarDefs(), name); 
	}

	virtual bool hasChildNodes() { return m_vars.size() > 0; }
	IStepNodePtr firstChild() { if(m_vars.size() > 0) return m_vars[0]->GetStepNodePtr(); return NULL; }
	IStepNodePtr lastChild()  { if(m_vars.size() > 0) return m_vars[m_vars.size()-1]->GetStepNodePtr(); return NULL; }
	IStepList  childNodes() {IStepList nodes; for(int i=0; i< m_vars.size(); i++) nodes.push_back((IStepNode *) m_vars[i]->m_ref); return nodes; }


	bool IsExistingAttribute(CString attrname);
	_variant_t GetAttributeValue(CString attrname,_variant_t vDefault);
	IStepNode * GetAttribute(CString attrname);
	CString GetAttributeExpClassname(CString attrname, CString strDefault);

	std::vector<double> ToVector(CString attrname);
	HRESULT SetAttributeValue(CString attrname, CString value);
	HRESULT AddAttribute(CString attrname){ if(QueryAttribute(attrname)==NULL) return E_FAIL; return S_OK; }
	IStepNodePtr QueryAttribute(CString attrname);
	IStepNodePtr QueryAttributeBranch(CString attrname, IStepElements & elements);
	IStepElements Branch(CString attrname);

	CString QueryAttributePaths(CVarDefPtr vardef);
	IStepNodePtr SelectNode(CString attrname);
	CVarDefPtr SelectAttribute(CString attrname);

	CVarDefs getElementsByTagName(CString tagname);

	void getElementsByCVarDefs(CVarDefs &vars, CStringVector &visited, CString tagname, CVarDefs & list);
	void getElementByCVarDef(CVarDefPtr var, CStringVector &visited, CString tagname, CVarDefs & list);

	int selectElementsByTagName(VarTable &table, CStringVector columns, CString fromnodes,  int bDistinct=false);
	bool getItemByCVarDefs(CVarDefs &vars,  CStringVector tagnames, VarList & list);
	_variant_t GetVarDefVal(CVarDefPtr  vardef);


	HRESULT ReturnErrMessage(CString errmsg) {DebugBreak(); m_errmsg=errmsg; return E_FAIL; }
	CString GetErrMessage() { return m_errmsg; }

	CStringVector & Parents() { return m_parents; }
	CStringVector & Subtypes() { return m_parents; }
	CStringVector & Supertypes() { return m_supertypes; }
	IStepNode * &Parent() { return m_parent; }
	//IStepNodePtr parentNode() { return m_parent; } 
	// can there be mutliple parents?
	//void SetParent(IStepNodePtr parent) {  m_parent=parent; }
	//IStepNodePtr GetParent() { return m_parent; }

	///////////////////////////////////////////////////////////////////////////////
	long m_atom;
	bool m_bAbstract;
	CString m_sType;
	std::vector<CVarDefPtr> m_vars;
	std::vector<CVarDefPtr> m_instancevars;
	std::vector<CVarDefPtr>  m_optBaseClassVars;
	std::vector<int> m_bounds;

	// THIS IS TYPE INFORMATION ADDED FOR SIMPLICITY
		CString declaration;
	CStringVector m_enums;
	CStringVector m_szSelections;
	CStringVector m_parents; // classes this class is derived from...
	private:
	CString m_errmsg;
	IStepNode * m_parent;
	CStringVector m_supertypes; // classes downcast to, supertype of 

public:
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);
DECLARE_REGISTRY_RESOURCEID(IDR_STEPNODE)

DECLARE_NOT_AGGREGATABLE(IStepNode)

BEGIN_COM_MAP(IStepNodeBase)
	COM_INTERFACE_ENTRY(INode)
	COM_INTERFACE_ENTRY(IDispatch )
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

#if 0
	__if_exists(_GetAttrEntries) {{NULL, (DWORD_PTR)_GetAttrEntries, _ChainAttr }, }\
{NULL, 0, 0}}; return &_entries[1];}

// Object lifetime is managed locally. Not by COM
	STDMETHOD_(ULONG, AddRef)() {return S_OK; }
	STDMETHOD_(ULONG, Release)()
	{
		return S_OK; 
	}
	//if _InternalQueryInterface is undefined then you forgot BEGIN_COM_MAP
	STDMETHOD(QueryInterface)(REFIID iid, void ** ppvObject) throw()
	{return _InternalQueryInterface(iid, ppvObject);}
#endif
	STDMETHODIMP get_ListClassname(BSTR* pVal){	*pVal=ExpressListClassname().AllocSysString();	return S_OK;}
	STDMETHODIMP get_Name(BSTR* pVal){	*pVal=Name().AllocSysString();	return S_OK; }
	STDMETHODIMP get_Classname(BSTR* pVal){	*pVal=ExpressClassname().AllocSysString();	return S_OK; }
	STDMETHODIMP get_Type(StepNodeType* pVal){	*pVal = Type(); return S_OK; } 
	STDMETHODIMP get_ListType(StepNodeType* pVal){	*pVal = ListType(); return S_OK; }
	STDMETHODIMP GetVarString(BSTR* pVal){	CString str = this->GetVarString();	*pVal = str.AllocSysString(); return S_OK;}
	STDMETHODIMP SetVarString(BSTR bstr) {	this->SetVarString((LPCWSTR) bstr);	return S_OK;}
	STDMETHODIMP isSimpleType(VARIANT_BOOL* flag) { *flag = IsSimpleType()? VARIANT_TRUE : VARIANT_FALSE; return S_OK; }
	STDMETHODIMP isListType(VARIANT_BOOL* flag){*flag = ISymbolBase::IsListType()? VARIANT_TRUE : VARIANT_FALSE; return S_OK;}
	STDMETHODIMP isSimpleListType(VARIANT_BOOL* flag){*flag = ISymbolBase::IsListType()? VARIANT_TRUE : VARIANT_FALSE; return S_OK;}
	STDMETHODIMP GetListVarString(BSTR bstrDelimiter, BSTR* pVal){	CString str = this->GetVarString((LPCTSTR) _bstr_t(bstrDelimiter));	*pVal = str.AllocSysString(); return S_OK;}

	STDMETHODIMP SelectSubnode( BSTR bstrVal, /*[out, retval]*/ INode ** ppNode)
	{
		IStepNodePtr step = SelectNode((LPCWSTR) bstrVal);
		step->QueryInterface(IID_INode, (void**)ppNode );
		return S_OK;

	}
	STDMETHODIMP GetAttributeValue(/*[in]*/ BSTR attrname, /*[in]*/ VARIANT vDefault, /* [out, retval]*/ VARIANT * pVal)
	{
		_variant_t val = this->GetAttributeValue((LPCWSTR) attrname, vDefault);
		* pVal = val.Detach();
		return S_OK;
	}


	STDMETHODIMP GetAttribute(/*[in]*/ BSTR attrname,  /*[out, retval]*/ IAttribute ** pVal);
	STDMETHODIMP GetAttributeList(/*[out, retval]*/ IAttributeList ** pVal) ;
	STDMETHODIMP DeleteChild(/*[in]*/ INode * pNode);
	STDMETHODIMP GetIndex(/*[in]*/ IAttribute * pAttr, /*[out, retval]*/ LONG * pVal);
	STDMETHODIMP GetSize(/*[out, retval]*/ LONG* pVal);
	STDMETHODIMP isASimpleListType(/*[in]*/ BSTR bstrVal, /*[out, retval]*/  VARIANT_BOOL* flag);
	STDMETHODIMP GetListItem(/*[in]*/ LONG nVal,  /*[out, retval]*/ INode ** ppNode);
	STDMETHODIMP SwapListItems(/*[in]*/ LONG index1, /*[in]*/ LONG index);
	STDMETHODIMP SetListItem(/*[in]*/ LONG nVal, /*[in]*/ INode * pNode);
	STDMETHODIMP push_back(/*[in]*/  INode * pNode,/*[in]*/  BSTR bstrName);
};

class IStepNode : public CComObject<IStepNodeBase>
{

	bool IsKindOf(CString classname, IStepNodePtr node = NULL)
	{
		if(node==NULL)
			node=this;
		if(node->Classname() == classname)
			return true;
		CStringVector::iterator it = find(node->m_parents.begin(), node->m_parents.end(),classname);
		if(it!=node->m_parents.end())
			return true;

		return false;
	}
	static IStepNode * GetThisRef(CVarDefPtr  vardef, int index=-2);

};
//OBJECT_ENTRY_AUTO(__uuidof(Node), IStepNode)

