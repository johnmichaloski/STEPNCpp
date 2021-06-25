//
// ExpressUtils.h
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.


#pragma once
#include "atlstr.h"
#include <map>
#include <vector>
#include <algorithm>

#include "Misc.h"
//#include "Globals.h"
// we use the boost library for implementing share pointers
#include <boost/shared_ptr.hpp>
#include <boost/intrusive_ptr.hpp>
#include "boost/multi_array.hpp"
#include <cassert>
#include <boost/tuple/tuple.hpp>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>


//#include "NiStep_i.h"
#include "StepNode.h"

//#include <boost/spirit/symbols/symbols.hpp>


#define INHERITANCEDEF(X) \
	public IStepNode

#define CLASSDEF(X) \
	public:\
	long m_atom;\
	X();\
	virtual ~X(){}\
	static IStepNodePtr Create(const TCHAR * name) \
{IStepNode  * ptr= (IStepNode  *) new X(); ptr->Classname() = #X; ptr->Name()=name; return ptr;}\
	DWORD GetVarRef(const TCHAR * name){ return CVarDef::Find(m_vars, name); }\
	public:\
	std::vector<CVarDefPtr> m_vars;\
	std::vector<CVarDefPtr> m_instancevars;\
	virtual std::vector<CVarDefPtr> & GetVarDefs() { return m_vars; }\
	virtual std::vector<CVarDefPtr> & GetInstanceVars() { return m_instancevars; }\
	virtual std::vector<CVarDefPtr> * GetInstanceVarsPtr() { return &m_instancevars; }\
	virtual std::vector<CVarDefPtr> * GetVarDefsPtr() { return &m_vars; }\
	virtual ULONG STDMETHODCALLTYPE AddRef() { return ULONG(1); }\
	virtual ULONG STDMETHODCALLTYPE Release() { return ULONG(1); }\
	STDMETHOD_(HRESULT, QueryInterface)( REFIID iid, LPVOID* ppInterface)\
	{\
		if ( ppInterface == NULL)\
			return E_INVALIDARG;\
		*ppInterface = NULL;	\
		if ( iid == IID_IUnknown )\
			*ppInterface = (IUnknown*) (IDispatch*)  (IStepNode*)  this;\
		else if ( iid == IID_INode)\
			*ppInterface =  this;\
		else if ( iid == IID_IDispatch)\
			*ppInterface = (IDispatch*) this;\
		else return E_FAIL;\
		return S_OK;\
	}

extern bool IsEnumeration(LPCTSTR item);   // is in express format .T.
extern bool IsString(LPCTSTR item);			// is in express format 'string'.
extern bool IsNumber(LPCTSTR item);
extern bool IsKeyword(LPCTSTR item);		// is in express format [a-zA-z][a-zA-Z_]*
extern bool IsEntityReference(LPCTSTR item); // is in express format #[0-9]+
extern void StoreInstance(CVarDefPtr vardef, CString sParameter);

extern void BuildInstanceDef(CVarDefs & vars, CVarDefs &instances, CStringVector &vVisitedClasses);
extern HRESULT Store(CVarDefPtr vardef, IStepNodePtr val); 
extern IStepNodePtr GetThis(CVarDefPtr  vardef);
extern HRESULT ImportXmlParameterList(CVarDefPtr vardef, CString xmlstring);
extern bool TypeCheckXmlParameterList(CVarDefPtr vardef, CString xmlstring);

extern CString DumpCVarDefs(CVarDefs &vars, CString &tabs=CString(_T("")));
extern CString DumpCVarDef(CVarDefPtr vardef, CString &tabs);


template <class T>
class EListT : public IStepNode, public std::vector<T>
{
public: 
	int m_min;   // e.g., 0 or 1
	int m_max;  // -1 infinite
	typedef typename std::vector<T>::iterator Iterator;
	typedef typename std::map<T, Iterator >::iterator RefmapIterator;
	

	EListT<T>(){ this->m_eType= bag_; this->_refs++; /* is never pointer now */}
	virtual ~EListT<T>() 
	{ 
		//DebugBreak(); // should never be deleted in current scenario
	} 
	std::vector<CVarDefPtr> m_vars;
	std::vector<CVarDefPtr> m_instancevars;
	virtual std::vector<CVarDefPtr> & GetVarDefs() { return m_vars; }
	virtual std::vector<CVarDefPtr> & GetInstanceVars() { return m_instancevars; }
	virtual std::vector<CVarDefPtr> * GetInstanceVarsPtr() { return &m_instancevars; }
	virtual std::vector<CVarDefPtr> * GetVarDefsPtr() {
		return &m_vars; 
	}

	bool IsASimpleListType(CString classname=L"");
	operator std::vector<T> & () { return this; }

	void clear() { std::vector<T>::clear(); m_vars.clear();}
	int size() { return std::vector<T>::size(); }
	void Swap(int n1, int n2)
	{
		if(n1<0 || n1>= size())
			return;
		if(n2<0 || n2>= size())
			return;
		std::swap(begin() + n1, begin() + n2);

	}

	HRESULT Store(int i, IStepNodePtr val)
	{
		if(i<0  || i>= size() )
			return E_INVALIDARG;
		at(i)= val.get();
		m_vars[i]->m_ref= (DWORD) val.get();
		m_vars[i]->Classname() = val->Classname();
		return S_OK;
	}
	void push_back(T t, CString varname)
	{
		Iterator it = end();
		std::vector<T>::push_back(t);
		if(!ISymbolBase::IsSimpleListType())
		{
			CString classname = (t!=NULL) ? t->Classname() : _T("");
			CString name = StrFormat(_T("%s[%d]"), varname, size()-1);
			m_vars.push_back(new CVarDef(this, name, index_, (DWORD) t.get(), classname, 0));
			m_vars.back()->Init(1, (StepNodeType)  22, this->ListClassname());
			m_instancevars=m_vars;
			m_vars.back()->_parentListPtr=this;
		}
	}
	int GetIndex(CVarDefPtr vardef)
	{
		for(int i=0; i< size(); i++)
			//if( ( (T::element_type *) vardef->m_ref)== ((T::element_type *) this->at(i).get()))
			if(  vardef== m_vars[i].get())
				return i;
		return -1;
	}

	HRESULT DeleteChild(IStepNode * step)
	{
		for(int i=0; i< size(); i++)
		{
			IStepNode * ptr= (IStepNode *)  at(i).get();
			if((IStepNode *) ptr == step)
			{
				erase(i);
				return S_OK;
			}
		}
		return E_FAIL;
	}

	Iterator erase(int i)
	{
		if(i<0 || i > m_vars.size())
			return this->end();
		m_vars.erase(m_vars.begin() + i);
		return	std::vector<T>::erase(begin()+i);
	}

	virtual CString GetVarString(CString separator=_T(""))
	{ 
		CString tmp;
		tmp+="(";
		for(int i=0; i< size(); i++)
		{
			if(i>0)
				tmp+=separator;
			
			if(IsASimpleListType(ListClassname()) && this->at(i)!=NULL)  // this is what i need...
				tmp+=this->at(i)->GetVarString();
			else if(this->at(i)!=NULL)
				tmp+="$";

		}
		tmp+=")";
		return tmp; 
	}
	virtual HRESULT SetVarString(CString str) ;
	// THIS IS NOT REALLY CREATABLE?
	static IStepNodePtr Create(const char * name) { return (IStepNode *)  new EList(); }
	void Init(CString classname, StepNodeType eListType )
	{
		this->m_eType= bag_;
		this->m_eListType=eListType;
		this->Classname() = StrFormat("EListT<%s>", classname);
		m_sListClassname=classname;
	}
	IStepNodePtr InsertItem(Iterator it);
	virtual ULONG STDMETHODCALLTYPE AddRef() { return ULONG(1); }
	virtual ULONG STDMETHODCALLTYPE Release() { return ULONG(1); }
	STDMETHOD_(HRESULT, QueryInterface)( REFIID iid, LPVOID* ppInterface)
	{
		if ( ppInterface == NULL)
			return E_INVALIDARG;
		*ppInterface = NULL;	
		if ( iid == IID_IUnknown )
			*ppInterface = (IUnknown*) (IDispatch*)  (IStepNode*)  this;
		else if ( iid == IID_INode)
			*ppInterface =  this;
		else if ( iid == IID_INodeList)
			*ppInterface =  this;
		else if ( iid == IID_IDispatch)
			*ppInterface = (IDispatch*) this;
		else return E_FAIL;
		return S_OK;
	}
};
typedef EListT<IStepNodePtr> EStepNodeList;
EXP_DECLARE_SMARTPOINTER(EStepNodeList) 

// FIXME: std::vector<EStepNodeListPtr> should be templatized to allow 3-dimensional arrays..
class EStepArray   : 
	public std::vector<EStepNodeListPtr>,
INHERITANCEDEF(EStepArray)
{
	CLASSDEF(EStepArray);

	typedef std::vector<EStepNodeListPtr> EStepNodeListPtrVector;
	void Init()
	{
		this->_refs++; 
		this->Type()= bag_;
		this->Classname() = "EStepArray";
		this->Dimension()  = 2;
	}
	void push_back(EStepNodeListPtr nodelist, CVarDefPtr vardef)
	{
		EStepNodeListPtrVector::push_back(nodelist);
		CString classname = (nodelist!=NULL) ? nodelist->Classname() : _T("");
		CString name = StrFormat(_T("%s[%d]"), vardef->Name(), size()-1);
		m_vars.push_back(new CVarDef(this, name, bag_, (DWORD) nodelist.get(), classname, 0));
		m_vars.back()->Init(1, (StepNodeType)  22, vardef->ListClassname());
		m_instancevars=m_vars;
	}
} ;
class EReal   :
INHERITANCEDEF(EReal)
{
	CLASSDEF(EReal);
	double val; 
	operator double() { return val; }
	double & operator() () { return val; }
	static CString szDefaultFmt;
	virtual CString GetVarString(CString fmt=_T("")) 
	{if(fmt.IsEmpty()) fmt=szDefaultFmt; return StrFormat(fmt, val); }
	virtual HRESULT SetVarString(CString str) {	try { double dVal = _tstof(str);  val=dVal; } catch(...) { return 	ReturnErrMessage(_T("Bad real string")); } return S_OK; }
	virtual EXPVariant GetValue() { return val; }


	EReal(double val) 
	{ 
		this->val = val; 
		Init();
	}
	void Init()
	{
		this->Type()= real_;
		this->Classname() = _T("Ereal");
		m_vars.push_back(new CVarDef(this, _T("real") ,(StepNodeType) real_, (DWORD) &(this->val), _T("real")));
		m_instancevars=m_vars;
	}
} ;


class EInteger : 
INHERITANCEDEF(EInteger)
{
	CLASSDEF(EInteger);

public: 
	long val; 
	//CLASSDEF(EInteger);
	operator long() { return val; }
	long & operator ()() { return val; }
	virtual CString GetVarString(CString fmt=_T("")) { if(fmt==_T("")) fmt=_T("%d"); return StrFormat(fmt, val); }
	virtual HRESULT SetVarString(CString str) {	try { long nVal = _tstoi(str);  val=nVal; } catch(...) { return ReturnErrMessage(_T("Bad integer string")); } return S_OK; }
	virtual EXPVariant GetValue() { return val; }
	static IStepNodePtr Create(const char * name) { return (IStepNode *)  new EInteger(); }
	EInteger(long val) 
	{ 
		this->val = val; 
		Init();
	}
	void Init()
	{
		this->Type()= integer_;
		this->Classname() = _T("Einteger");
		m_vars.push_back(new CVarDef(this, _T("integer") ,(StepNodeType) integer_, (DWORD) &(this->val), _T("integer")));
		m_instancevars=m_vars;
	}
};

class EString : 
	INHERITANCEDEF(EString)
{
	CLASSDEF(EString);
public: 
	CString val; 
	operator CString() { return val; }
	virtual CString GetVarString(CString fmt=_T("")) {if(fmt==_T("")) fmt=_T("'%s'"); return StrFormat(fmt, val); }
	virtual HRESULT SetVarString(CString str) {	val=str; return S_OK; }
	virtual EXPVariant GetValue() { return val; }
	CString operator() () {return val; }
	EString(CString val) 
	{ 
		this->val = val; 
		Init();
	}
	void Init()
	{
		this->Type()= string_;
		this->ExpressClassname() = _T("string");
		this->Classname() = _T("Estring");
		m_vars.push_back(new CVarDef(this, _T("string") ,(StepNodeType) string_, (DWORD) &(this->val), _T("string")));
		m_instancevars=m_vars;
	}
};

class EEnum :
	INHERITANCEDEF(EEnum)
{
	CLASSDEF(EEnum);
public: 
	long m_nSelection;
	operator long() { return m_nSelection; }
	long & operator ()() { return m_nSelection; }
	virtual CString GetVarString(CString fmt=_T("")) 
	{
		CString str =  GetEnum2String(m_nSelection);
		str.MakeUpper();
		if(str[0]!=_T('.'))
			str=_T('.')+str;
		if(str[str.GetLength()-1] != _T('.'))
			str+=_T('.');
		return str;
	}
	virtual HRESULT SetVarString(CString str) 
	{	
		if(str[0]!='.')
		{
			str=_T('.')+str;
			str+=_T('.');
		}
		SetString2Enum(str); 
		return S_OK; 
	}
	virtual EXPVariant GetValue() { return m_nSelection; }

	virtual CString GetEnum2String(int e){ return _T(""); }
	virtual long GetString2Enum(CString szEnum){ return 0; }
	virtual void SetString2Enum(CString szEnum){ m_nSelection=GetString2Enum(szEnum); }
	EEnum(long val) 
	{ 
		this->m_nSelection = val; 
		Init();
	}
	void Init()
	{
		this->Type()= enumeration_;
		this->Classname() = _T("Eenum");
		this->ExpressClassname() = _T("enum");
		m_vars.push_back(new CVarDef(this, _T("enum") ,(StepNodeType) integer_, (DWORD) &(this->m_nSelection), _T("enum")));
		m_instancevars=m_vars;
	}
};

class EBoolean : 
	public EEnum
{
	CLASSDEF(EBoolean);
public:
	static const int nEnums =3;
	enum EBooleanEnum
	{
		efalse=0,
		etrue,
		eunknown,
	} ;
	virtual CString GetVarString(CString fmt=_T("")) {
		return GetEnum2String(m_nSelection); }
	virtual HRESULT SetVarString(CString str) { 
		return EEnum::SetVarString(str); }
	void SetSelection(EBooleanEnum nSelection) {   m_nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static TCHAR * szEnums[nEnums]={_T(".F."), _T(".T."), _T(".U.")};
		if(e>=nEnums) return _T("$"); return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) 
	{
		szEnum.MakeUpper();
		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
		}
		return 0; // fixme
	}
	void Init()
	{
		this->Type()= boolean_;
		this->Classname() = _T("EBoolean");
		this->ExpressClassname() = _T("boolean");
		m_vars.push_back(new CVarDef(this, _T("enum") ,(StepNodeType) boolean_, (DWORD) &(this->m_nSelection), _T("enum")));
		m_instancevars=m_vars;
	}
};


typedef EBoolean ELogical;

class ESelection : 
	INHERITANCEDEF(ESelection)
{
	CLASSDEF(ESelection)
public: 
	IStepNodePtr m_pSelection;
	ESelection(IStepNodePtr pClass) 
	{ 
		m_pSelection=pClass;
	}
	void Init()
	{
		this->Type()= select_;
		this->Classname() = _T("ESelect");
	}
	void SetSelection(IStepNodePtr pSelection) {  m_pSelection=pSelection; }
	IStepNodePtr GetSelection() { return m_pSelection; }
};


typedef EInteger Enumber;
typedef EInteger EBinary;


EXP_DECLARE_SMARTPOINTER(Enumber) 
EXP_DECLARE_SMARTPOINTER(EString) 
EXP_DECLARE_SMARTPOINTER(EInteger) 
EXP_DECLARE_SMARTPOINTER(EReal) 
EXP_DECLARE_SMARTPOINTER(EBoolean) 
EXP_DECLARE_SMARTPOINTER(ELogical) 
EXP_DECLARE_SMARTPOINTER(EEnum) 
EXP_DECLARE_SMARTPOINTER(EBinary) 





//extern int GetVarItemSize(IStepNodePtr pNode, CString itemBranch);
// extern CVarDefPtr GetVarDef(IStepNodePtr pNode, CString itemBranch);
//extern void StoreCVarDef(CVarDefPtr vardef, CString &val);




// Create a 3D array that is 3 x 4 x 2
typedef boost::multi_array<IStepNodePtr, 3> array_type;
typedef array_type::index index;
extern array_type A;


typedef boost::tuples::tuple<CString, IStepNodePtr> TItem;

template <class T, class W>
class FcnVariables : public std::vector<boost::tuples::tuple<T, W> >
{
public:
	typedef boost::tuples::tuple<T, W>  MyPair;
	FcnVariables() {}
	FcnVariables(MyPair t) { push_back(t); }
	FcnVariables(MyPair t1, MyPair t2) { push_back(t1); push_back(t2);}
	FcnVariables(MyPair t1, MyPair t2, MyPair t3) { push_back(t1); push_back(t2); push_back(t3);}
	FcnVariables(MyPair t1, MyPair t2, MyPair t3, MyPair t4) { push_back(t1); push_back(t2); push_back(t3); push_back(t4);}
	//operator T * () { return &this->operator[]; }

};

typedef FcnVariables<CString, IStepNodePtr> StepVars;
extern void Load(CVarDefs & vars, StepVars &);

extern CStringVector ClassSupertypeHierarchy(CString classname);
extern bool IsSimpleType(CString classname);
extern IStepNodePtr CreateExpressBaseClass(CString classname, CString name) ;


typedef boost::function<IStepNodePtr(CString, CString) >  ClassGeneratorFcn;

/**
	Contains a mapping of of C++ class names to their class Create functions. 
	Given a classname such as "project", the class name is searched in the list of class generator list,
	and if found the function project::CreateClass(instancename, namespace) is called.
	The class uses global static member gClassGenerators in which to declare 

	Note: It would appear easy to append new class generator lists (name, fcn) to the global static member gClassGenerators 
	during C++ static global initialization. DONT! the static member gClassGenerators may be defined after the  global initialization, and
	chaos can ensue. Instead, use some member to insure safe "gClassGenerators" iniatilizaiton order. This is an oobvious fixme.

*/
class CClassGenerators : public std::vector<ClassGeneratorFcn > 
{
public:
	static CClassGenerators  gClassGenerators;

	int AddGenerator(ClassGeneratorFcn fcn) 
	{ 
		push_back(fcn); 
		return 0; 
	}
	IStepNodePtr CreateClass(CString name, CString sznamespace)
	{
			IStepNodePtr step = NULL;
			for(int i=0; i< this->size(); i++)
			{
				ClassGeneratorFcn fcn= this->at(i);
				step=fcn(name, sznamespace);
				if(step!=NULL)
					return step;
			}
			return step;
	}
};

inline bool ISymbolBase::IsSimpleListType() 
{ 		
	if(!IsListType())
		return false;
	EListT<IStepNodePtr> * list=  (EListT<IStepNodePtr> *) this;
	if(list==NULL)  // should never ever be null.
		return false;
	return list->IsASimpleListType(this->ListClassname());
}


inline CString IStepList::DumpNodes() 
{
	CString tmp;
	for(int i=0; i<size(); i++)
	{
		IStepNodePtr step = at(i);
		tmp.AppendFormat(_T("%s=%s\n"), at(i)->Classname(), at(i)->GetVarString());
	}
	return tmp;
}	

template <typename T>
inline HRESULT EListT<T>::SetVarString(CString str) 
{	
	int i;
	IStepNodePtr step;
	// FIXME: write boost spirit script to parse into tokens.
	str.Replace(_T("("),_T(""));
	str.Replace(_T(")"),_T(""));
	CStringVector tokens = CStringVector::Tokenize(str,_T(","));
	
	// fixme - must be simple list type or kind of simple list type

	std::vector<T>::clear();
	for(i=0; i<tokens.size() ;  i++)
	{
		if(InsertItem(end())==NULL)
			return ReturnErrMessage(_T("Couldn't create and insert class of list element type"));
		step = this->at(i);
		tokens[i].Trim(); // trim outside the ' ' string
		tokens[i].Replace(_T("'"),_T("")); // FIXME: shortcut hack
		if(FAILED(step->SetVarString(tokens[i])))
			return ReturnErrMessage(StrFormat(_T("Bad list element at %d"), i));
	}
#if 0
	// Resize vectors to match
	for(i=size(); i<tokens.size() ;  i++)
	{
		if(InsertItem(end())==NULL)
			return ReturnErrMessage("Couldn't create and insert class of list element type");
	}
	for( i=tokens.size(); i<size() ;  i++)
		std::vector<T>::erase(begin());


	for(i=0; i< size(); i++)
	{
		step = this->at(i);
		tokens[i].Trim(); // trim outside the ' ' string
		tokens[i].Replace("'","");
		if(FAILED(step->SetVarString(tokens[i])))
			return ReturnErrMessage(StrFormat("Bad element at %d", i));
	}
#endif
	return S_OK; 
}

template <typename T>
inline IStepNodePtr EListT<T>::InsertItem(Iterator it)
{
	T step = (T::element_type *) (IStepNode *) CClassGenerators::gClassGenerators.CreateClass(ExpDemangle(m_sListClassname),_T("")).get();
	if(step==NULL)
		return step; 

	this->insert(it,  step);
	if(!ISymbolBase::IsSimpleListType())
	{
		// FIXME: name may be blank..., pass in name and size wrong too.
		m_vars.push_back(new CVarDef(this, StrFormat(_T("%s[%d]"),this->Name(), size()), index_, (DWORD) &back(), ListClassname() , 0));
	}
	return step;
}


template <typename T>
inline 	bool EListT<T>::IsASimpleListType(CString classname)
{
	// THIS IS A MESS...
	//if(::IsSimpleType(m_eListType))
	if(this->IsSimpleType())
		return true;

	//if(classname=="Elength_measure")
	//	DebugBreak();
	if(classname.IsEmpty())
		classname = this->ListClassname();

	T step = (T::element_type *) (IStepNode *) CClassGenerators::gClassGenerators.CreateClass(ExpDemangle(classname),_T("")).get();
	if(step==NULL)
	{
		//DebugBreak();
		return false;
	}
	 std::vector<CVarDefPtr> &  vardefs = step->GetVarDefs();
	 // check to see if inherited from
	if(vardefs.size()>0)
		return vardefs[0]->IsSimpleType();
	return false;

}
extern void CloneCVarDefs(CVarDefs &fromvars, CVarDefs &tovars, int bFirst=false);
extern void CloneCVarDef(CVarDefPtr fromvardef, CVarDefPtr  tovardef);
