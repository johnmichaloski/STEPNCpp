// Variable.h : Declaration of the CVariable

#pragma once
#include "resource.h"       // main symbols

#include "NiStep_i.h"
#include "Symbol.h"
#include "Misc.h"
#include <atlstr.h>
#include <vector>
#include "Globals.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif


class CVarDef : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CVarDef, &CLSID_Attribute>,
	public IDispatchImpl<IAttribute, &IID_IAttribute, &LIBID_NiStepLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public ISymbolBase

{
public:
	CVarDef() {m_ref=0; }
	CVarDef(IStepNode * owner, CString name, StepNodeType type=unknown_, DWORD ref=0, CString sClassname=L"", int bOptional=0)
	{ 
		m_owner=owner;
		m_sName=name; 
		m_eType=type; 
		this->m_ref=ref; 
		this->m_sClassname=sClassname;

		this->m_optBaseClassVars=new CVarDefs;
		this->m_eListType=unknown_;
		m_bOptional= (bool) bOptional;
		parentvardef=NULL;
		_parentListPtr=NULL;
	} 
	~CVarDef() {  }
	CString & Name() { return m_sName; }
	CString & Classname() { return m_sClassname; }
	CString & ListClassname() { return m_sListClassname; }
	StepNodeType & Type() { return m_eType; }
	StepNodeType & ListType() { return m_eListType; }

#if 0
	StepNodeType & ListType() { return m_eListType; }
	StepNodeType & Type() { return m_eType; }
	CString & Classname() { return m_sClassname; }
	CString & ListClassname() { return m_sListClassname; }
	CString &  TypeClassName()  { return m_sClassname; }
	CString   ExpressClassname() { return ExpDemangle(Classname()); }
	CString   ExpressListClassname() { return ExpDemangle(m_sListClassname); }
	bool IsListType() { return Type()== list_ || Type()== set_ || Type()== aggregate_ || Type()== array_ || Type()== bag_; }
#endif
	void Init(int nDimension, StepNodeType eListType , CString listclassname, int min=1, int max=-1)
	{
		m_sListClassname= listclassname;
		this->m_nDimension=nDimension;
		m_eListType=eListType;
			
	}
	virtual CString GetVarString(CString fmt=_T("")) ;
	virtual HRESULT SetVarString(CString val) ;

	static DWORD Find(CVarDefs &vars, CString name)
	{
		CVarDefPtr vardef;
		if(NULL!=(vardef= FindVarDef(vars, name)))
			return vardef->m_ref;

		return NULL;
	}
	static CVarDefPtr FindVarDef(CVarDefs &vars, CString &name)
	{
		CVarDefPtr var;
		for(int i=0; i<vars.size(); i++)
		{
			if(vars[i]->Type() == special_)
			{
				if((var= FindVarDef((CVarDefs &) *(CVarDefs*)vars[i]->m_ref, name))  != NULL)
					return  var;
			}
			if(vars[i]->Name()==name) 
				return vars[i];
		}
		return NULL;
	}
	bool IsSimpleType(StepNodeType _eType=nulltype_) 
	{
		if(_eType == nulltype_) 
			_eType=m_eType; 
		if(_eType == special_)
		{
			CVarDefs & vars = *(CVarDefs*) this->m_ref;
			if(vars.size() > 1)
				return false;
			if(vars.size() )
				return vars[0]->IsSimpleType() ;
		}
		if( _eType == string_  ||  _eType == integer_  ||  _eType == real_ ||  _eType == boolean_ ||  _eType == number_  ||  _eType == logical_ ||  _eType == enumeration_ )
			return true;
		return false;
	}

	//static bool IsListType(StepNodeType type ) { return type== list_ || type== set_ || type== aggregate_ || type== array_ || type== bag_; }

	bool IsSimpleListType() ;

	IStepNode * GetStepNodePtr() ;
	CVarDefPtr GetPrimitiveVarDef();
	IStepNode *	&Owner() { return  m_owner; }
	bool & Optional() { return m_bOptional; }
	long & Atom() { return m_dwAtom; }
	CVarDef * & Parent() { return parentvardef;  }

	////////////////////////////////////////////////////////////////////////////////
	DWORD m_ref;
	LONG m_dwAtom;  // maybe make this a property list ...
	IStepNode * _parentListPtr ;
private:
	CVarDef * parentvardef;
	IStepNode * m_owner;
	CVarDefs * m_optBaseClassVars;
	bool m_bOptional;
	// type information
	CString m_sReferenceChain;


public:
// Object lifetime is managed locally. Not by COM
	STDMETHOD_(ULONG, AddRef)() { return 1; }
	STDMETHOD_(ULONG, Release)(){ return 1; 	}
	STDMETHOD_(HRESULT, QueryInterface)( REFIID iid, LPVOID* ppInterface)\
	{\
		if ( ppInterface == NULL)\
			return E_INVALIDARG;\
		*ppInterface = NULL;	\
		if ( iid == IID_IUnknown )\
			*ppInterface = (IUnknown*) (IDispatch*)  (CVarDef*)  this;\
		else if ( iid == IID_IAttribute)\
			*ppInterface =  this;\
		else if ( iid == IID_IDispatch)\
			*ppInterface = (IDispatch*) this;\
		else return E_FAIL;\
		return S_OK;\
	}

// ISupportsErrorInfo
	STDMETHODDECL InterfaceSupportsErrorInfo (REFIID riid);


	STDMETHODDECL IsSimpleType (VARIANT_BOOL* flag) { *flag = IsSimpleType()? VARIANT_TRUE : VARIANT_FALSE; return S_OK; }
	STDMETHODDECL IsListType (VARIANT_BOOL* flag){*flag = ISymbolBase::IsListType()? VARIANT_TRUE : VARIANT_FALSE; return S_OK;}
	STDMETHODDECL get_Name (BSTR* pVal) {	*pVal=Name().AllocSysString(); return S_OK; }
	STDMETHODDECL get_Classname (BSTR* pVal) { *pVal=ExpressClassname().AllocSysString(); return S_OK; }
	STDMETHODDECL get_Type (StepNodeType* pVal) { *pVal=Type();  return S_OK; }
	STDMETHODDECL get_ListType (StepNodeType* pVal) { *pVal=ListType(); return S_OK; }
	STDMETHODDECL get_ListClassname (BSTR* pVal) { *pVal=ExpressListClassname().AllocSysString(); return S_OK; }
	//STDMETHODDECL Type(BSTR* pVal) { *pVal = Type();  return S_OK; }
	//STDMETHODDECL Classname(BSTR* pVal) { *pVal=Classname().AllocSysString(); return S_OK; }
	//STDMETHODDECL ListType(BSTR* pVal) { *pVal=ListType();  return S_OK; }
	STDMETHODDECL get_Atom (/*[out, retval]*/ LONG * pVal) { *pVal = this->m_dwAtom; return S_OK; }
	STDMETHODDECL put_Atom (/*in*/ LONG val){ m_dwAtom=val; return S_OK; }
	STDMETHODDECL get_Dimension (LONG * pVal) { *pVal=this->m_nDimension; return S_OK; }
	STDMETHODDECL IsSimpleListType (VARIANT_BOOL* flag){*flag = ISymbolBase::IsSimpleListType()? VARIANT_TRUE : VARIANT_FALSE; return S_OK;}
	STDMETHODDECL IsASimpleType(/*[in]*/ BSTR bstrClassname, /*[out, retval]*/  VARIANT_BOOL* flag);

	STDMETHODDECL GetVarString (/*[out, retval]*/ BSTR* pVal);
	STDMETHODDECL GetStepNode (/*[out, retval]*/ INode ** ppNode);
	STDMETHODDECL Owner (/*[out, retval]*/ INode ** ppNode);
	STDMETHODDECL Clear ();
	STDMETHODDECL SetStepNode (/*[in]*/ INode * pNode);
	STDMETHODDECL Clone (/*[in]*/  IAttribute * pTo);
	STDMETHODDECL GetInheritedAttributeList(/*[out, retval]*/ IAttributeList ** pVal);
	STDMETHODDECL GetNodeList(/*[out, retval]*/ INodeList ** pVal);
	STDMETHODDECL CreateNode(/*[in]*/ BSTR classname, /*[out, retval]*/ INode ** ppNode);
	STDMETHODDECL ToXmlString(/*[out, retval]*/ BSTR* bstrString);
	STDMETHODDECL FromXmlString(/*[in]*/ BSTR bstrString);
	STDMETHODDECL TypeCheckXmlString(/*[in]*/ BSTR bstrString, /*[out,retval]*/ VARIANT_BOOL *bResult);

};

typedef std::vector<CVarDefPtr> Variables;

