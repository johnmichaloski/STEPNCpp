// StepNode.h : Declaration of the CStepNode

#pragma once
#include "resource.h"       // main symbols

#include "NiStep_i.h"
#include "Symbol.h"
#include "Variable.h"



class IStepList : public  std::vector<IStepNodePtr> 
{
public:
	CString DumpNodes() ;
};

typedef IStepList IStepElements;

/**

IStepNode is the Base Class for all STEPNC entity/class declarations.
IStepNode is the common pointer class for all the step instances in the step tree. IStepNode contains basic symbol information,
name, classname, type and if the node is a list, listclassname and listtype. IStepNode supports a public COM interface INode as well
as support for basic C++ methods to support COM. 

All Express schema clases derive from IStepNode. Express primitives int, real, boolean, etc. are wrapped in a class derived
from StepNode.

Based on the Express schema each StepNode has an attributes list described by m_vars. 

Attribute types are described by the enumeration StepNodeType which describes inherited, simple, list and entity/reference nodes.

Instances described by  m_instancevars is a flattened list of CVarDef attributes. BY constrast, m_vars contains instances that point to another
attribute list that is only an inheritence redirection (no variables in the actual class definition - only inherits variables.)

*/ 
class IStepNode  : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<IStepNode, &CLSID_Node>,
	public IDispatchImpl<INode, &IID_INode, &LIBID_NiStepLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public ISymbolBase 
{
public:
	IStepNode()
	{		
		m_bAbstract=false;
		m_parent=NULL;
	}
	virtual ~IStepNode() {}
	bool IsPrimitive();
	bool & Abstract() { return m_bAbstract; }
	CString tagName () { return Name(); }
	CString dataType() { return Classname();  }  // 
	StepNodeType nodeType() { return Type(); }

	bool IsSimpleType() 
	{
		return (m_eType==integer_ || m_eType==real_ || m_eType == number_ || m_eType == boolean_ || m_eType == logical_ || m_eType==string_ || m_eType==enumeration_); 
	}
	bool IsListType() { return Type()== list_ || Type()== set_ || Type()== aggregate_ || Type()== array_ || Type()== bag_; }

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

	bool IsExistingAttribute(CString attrname);
	_variant_t GetAttributeValue(CString attrname,_variant_t vDefault);
	IStepNode * GetAttribute(CString attrname);
	CString GetAttributeValue(CString attrname);
	CString GetAttributeExpClassname(CString attrname, CString strDefault);

	IStepNodePtr CreateAttributeNode(/*[in]*/ CString spath, /*[in]*/ CString classname);
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
	STDMETHODDECL InterfaceSupportsErrorInfo(REFIID riid);

	STDMETHODDECL IsSimpleType(/*[out, retval]*/VARIANT_BOOL* flag) ;
	STDMETHODDECL IsListType(/*[out, retval]*/VARIANT_BOOL* flag);
	STDMETHODDECL get_ListClassname(/*[out, retval]*/BSTR* pVal);
	STDMETHODDECL get_Name(/*[out, retval]*/BSTR* pVal);
	STDMETHODDECL get_Classname(/*[out, retval]*/BSTR* pVal);
	STDMETHODDECL get_Type(/*[out, retval]*/StepNodeType* pVal);
	STDMETHODDECL get_ListType(/*[out, retval]*/StepNodeType* pVal);
	STDMETHODDECL GetVarString(/*[out, retval]*/BSTR* pVal);
	STDMETHODDECL SetVarString(/*[in]*/ BSTR bstr);

	STDMETHODDECL IsSimpleListType(/*[out, retval]*/ VARIANT_BOOL* flag);

	STDMETHODDECL SelectNode( BSTR bstrVal, /*[out, retval]*/ INode ** ppNode);
	STDMETHODDECL GetAttributeValue(/*[in]*/ BSTR attrname, /*[in]*/ VARIANT vDefault, /* [out, retval]*/ VARIANT * pVal);
	STDMETHODDECL GetAttribute(/*[in]*/ BSTR attrname,  /*[out, retval]*/ IAttribute ** pVal);
	STDMETHODDECL GetAttributeList(/*[out, retval]*/ IAttributeList ** pVal) ;
	STDMETHODDECL ToVector(/*[in]*/ BSTR spath, /*[out, retval]*/ Vector3d* vector);


	// spath attribute methods
	STDMETHODDECL IsKindOf(/*[in]*/ BSTR bstrClassname, /*[out, retval]*/ VARIANT_BOOL* flag);
	STDMETHODDECL AddAttribute(/*[in]*/ BSTR spath, /*[out, retval]*/ VARIANT_BOOL* flag);
	STDMETHODDECL GetNodeList(/*[out, retval]*/ INodeList ** pVal);
	STDMETHODDECL SelectNodeList(/*[in]*/ BSTR spath,  /*[out, retval]*/ INodeList ** ppNodeList);
	STDMETHODDECL SetAttributeValue(/*[in]*/ BSTR spath, /*[in]*/ VARIANT vValue, /*[out, retval]*/ VARIANT_BOOL* flag);
	STDMETHODDECL SetAttributeString(/*[in]*/ BSTR spath, /*[in]*/ BSTR vStrValue, /*[out, retval]*/ VARIANT_BOOL* flag);
	STDMETHODDECL SetAttributeNode(/*[in]*/ BSTR spath, /*[in]*/ INode * pNode,  /*[out, retval]*/ VARIANT_BOOL* flag);
	STDMETHODDECL CreateAttributeNode(/*[in]*/ BSTR spath, /*[in]*/ BSTR classname, /*[out, retval]*/ INode** ppNode);
	STDMETHODDECL GetAttributeNodeList(/*[in]*/ BSTR spath, /*[out, retval]*/  INodeList ** ppNodeList);
	STDMETHODDECL GetAttributeClassname(/*[in]*/ BSTR spath, /*[out, retval]*/ BSTR * pBstr);
	STDMETHODDECL DoesPathExist(/*[in]*/ BSTR bstrPath, /*[out, retval]*/ VARIANT_BOOL* flag);

	//STDMETHODDECL GetIndex(/*[in]*/ IAttribute * pAttr, /*[out, retval]*/ LONG * pVal);

// Object lifetime is managed locally. Not by COM
	STDMETHOD_(ULONG, AddRef)() { return 1; }
	STDMETHOD_(ULONG, Release)(){ return 1; 	}
	STDMETHOD_(HRESULT, QueryInterface)( REFIID iid, LPVOID* ppInterface)
	{
		if ( ppInterface == NULL)
			return E_INVALIDARG;
		*ppInterface = NULL;	
		if ( iid == IID_IUnknown )
			*ppInterface = (IUnknown*) (IDispatch*)  (IStepNode*)  this;
		else if ( iid == IID_INode)
			*ppInterface =  this;
		else if ( iid == IID_IDispatch)
			*ppInterface = (IDispatch*) this;
		else return E_FAIL;
		return S_OK;
	}


};


//OBJECT_ENTRY_AUTO(__uuidof(Node), IStepNode)

