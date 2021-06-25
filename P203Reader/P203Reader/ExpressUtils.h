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
// we use the boost library for implementing share pointers
#include <boost/shared_ptr.hpp>
#include <boost/intrusive_ptr.hpp>
#include "boost/multi_array.hpp"
#include <boost/spirit/symbols/symbols.hpp>
#include <cassert>
#include <boost/tuple/tuple.hpp>
#include <boost/function.hpp>
#include <boost/shared_ptr.hpp>
#include "boost/lexical_cast.hpp"

#define EXP_EXT_CLASS 
#define EXP_DECLARE_SMARTPOINTER(className)                                             \
	typedef EXP_EXT_CLASS boost::intrusive_ptr<className> className##Ptr;              \
	typedef EXP_EXT_CLASS boost::intrusive_ptr<const className> className##ConstPtr;
//#define EXP_DECLARE_SMARTPOINTER(className)                                             \
//	typedef className * className##Ptr;              \
//	typedef const className * className##ConstPtr;

struct CClassNode;
class IStepNode;
class CVarsDefsPtr;
struct CVarDef;
class CClassGenerators;
class CVarDef2Part21;
class StepTable;

EXP_DECLARE_SMARTPOINTER(CVarDef) 
EXP_DECLARE_SMARTPOINTER(IStepNode) 

inline CString ExpMangle(CString classname) 
{
	if(classname.GetAt(0)=='E') 
		return classname; 
	return StrFormat("E%s" ,(const char *) classname); 
}
inline CString ExpDemangle(CString classname) {if(classname.GetAt(0)=='E') return classname.Mid(1); else return classname;}

typedef std::vector<CVarDefPtr> CVarDefs;

struct IOglPlotter;
#define PDONE -2
#define PERROR -1
#define POK 0

#define CLASSDEF(X) \
	long _atom;\
	virtual LONG Draw(IOglPlotter * m_plotter) { return POK; }\
	X();\
	virtual ~X(){}\
	static IStepNodePtr Create(const char * name) {IStepNode  * ptr= (IStepNode  *) new X(); ptr->Name()=name; return ptr;}\
	std::string getActualClassName() const{ return typeid(*this).name(); }\
	std::vector<CVarDefPtr> vars;\
	std::vector<CVarDefPtr> instancevars;\
	CClassNode m_def;\
	DWORD GetVarRef(const char * name){ return CVarDef::Find(vars,name); }\
	virtual std::vector<CVarDefPtr> & GetVarDefs() { return vars; }\
	virtual std::vector<CVarDefPtr> & GetInstanceVars() { return instancevars; }\
	private:\
	X(const X&);\
	void operator=(const X&);\
	public:


class IExpress 
{
public:
	IExpress() : _refs(0) {}
	//! destructor
	virtual ~IExpress(){};
//private:
	int _refs; //! reference count
	friend inline void intrusive_ptr_release(IExpress* pThis)
	{
		if(--pThis->_refs == 0 ) { 
			delete pThis;
		}
	}
	friend inline void intrusive_ptr_add_ref(IExpress* pThis)
	{
		pThis->_refs++;
	}
	friend inline void intrusive_ptr_release(const IExpress* pThis)
	{
		if(--const_cast<IExpress*>(pThis)->_refs == 0 ) { 
			delete const_cast<IExpress*>(pThis);
		}
	}
	friend inline void intrusive_ptr_add_ref(const IExpress* pThis)
	{
		const_cast<IExpress*>(pThis)->_refs++;

	}
};


/* these are all orthogonal types */
enum StepNodeType {
	unknown_ = 0,	/* 0 catches uninit. errors */
	special_=1,	/* placeholder, given meaning by it's owner, */
	this_=2,

	integer_=3,
	real_=4,
	string_=5,
	binary_=6,
	boolean_=7,
	logical_=8,

	/* formals-only */
	number_=9,
	generic_=10,

	/* aggregates */
	aggregate_=11,	/* as a formal */
	array_=12,
	bag_=13,
	set_=14,
	list_=15,
	list_item_=16,/* not real, just for easier computation */

	oneof_=17,

	/* while they are really used for different */
	/* purposes, it might be worth considering */
	/* collapsing entity_ and entity_list_ */
	entity_=18,	/* single entity */
	entity_list_=19,	/* linked list of entities */
	enumeration_=20,
	select_=21,
	reference_=22,	/* something only defined by a base type, i.e., a */
	/* type reference */
	query_=23,
	op_=24,		/* something with an operand */
	inverse_=25,	/* is? an inverse */

	identifier_=26,	/* simple identifier in an expression */
	attribute_=27,	/* attribute reference (i.e., expr->u.variable) */
	derived_=28,/*?*/
	funcall_=29,	/* a function call and actual parameters */
//	selection_=30,
	self_=31,
	vardef_=32,
	typereference_=33,
	underlying_type_=34,
	constant_=35,
	index_=36,
	rename_=37,
	typelist_=38,
	typemultilist_=39
};

class ISymbol : public IExpress
{
public:

	ISymbol(){_bVisited=0; _eType=(StepNodeType) -1; m_eListType=unknown_; _nDimension=0;}
	virtual ~ISymbol() {}

	CString & Name() { return _sName; }
	CString & Namespace() { return _sNamespace; }
	CString & Classname() { return m_sClassname; }
	CString & ListClassname() { return _sListClassname; }

	StepNodeType & Type () { return _eType; }
	StepNodeType & ListType () { return m_eListType; }
	bool IsSimpleType() { return (_eType==integer_ || _eType==real_ || _eType == number_ || _eType == boolean_ || _eType == logical_ || _eType==string_ || _eType==enumeration_); }
	int GetVisited() { return _bVisited; }
	void SetVisited(int bval) { _bVisited = (int) bval; }
	///////////////////////////////////////////////////////////////////////
	CString _sName;
	CString _sNamespace;
	CString m_sClassname;
	CString _sListClassname;
	CString _sFile;
	int _nLine;
	StepNodeType _eType;

	StepNodeType m_eListType;
	int _nDimension;
	std::vector<int> vLowerBounds;
	std::vector<int> vUpperBounds;

	int _bVisited;
	// vs IExpress * _parent; //???

};
EXP_DECLARE_SMARTPOINTER(ISymbol);


struct CVarDef : public ISymbol
{
	CVarDef() {m_ref=0; }
	CVarDef(IStepNode * owner, CString name, StepNodeType type=unknown_, DWORD ref=0, CString sClassname=L"", int bOptional=0)
	{ 
		_owner=owner;
		_sName=name; 
		_eType=type; 
		this->m_ref=ref; 
		this->m_sClassname=sClassname;

		this->m_optBaseClassVars=new CVarDefs;
		this->m_eListType=unknown_;
		m_bOptional= (bool) bOptional;
	} 
	~CVarDef() {  }

	StepNodeType & ListType() { return m_eListType; }
	StepNodeType & Type() { return _eType; }
	CString & Classname() { return m_sClassname; }
	CString & ListClassname() { return _sListClassname; }
	CString &  TypeClassName()  { return m_sClassname; }
	void Init(int nDimension, StepNodeType eListType , CString listclassname, int min=1, int max=-1)
	{
		_sListClassname= listclassname;
		this->_nDimension=nDimension;
		m_eListType=eListType;
			
	}
	virtual CString GetVarString(CString fmt="") ;

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
			if(vars[i]->_eType == special_)
			{
				if((var= FindVarDef((CVarDefs &) *(CVarDefs*)vars[i]->m_ref, name))  != NULL)
					return  var;
			}
			if(vars[i]->Name()==name) 
				return vars[i];
		}
		return NULL;
	}
	bool IsSimpleType() 
	{  
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

	bool IsListType() { return _eType== list_ || _eType== set_ || _eType== aggregate_ || _eType== array_ || _eType== bag_; }
	static bool IsListType(StepNodeType type ) { return type== list_ || type== set_ || type== aggregate_ || type== array_ || type== bag_; }

	bool IsSimpleListType() ;
	IStepNode * GetOwnerPtr() { return  _owner; }
	IStepNode * GetStepNodePtr() ;

	////////////////////////////////////////////////////////////////////////////////
	IStepNode * _owner;
	DWORD m_ref;
	CVarDefs * m_optBaseClassVars;
	bool m_bOptional;
	// type information
	CString m_sReferenceChain;
	bool m_bAmbiguous;
	DWORD m_dwAtom;  // maybe make this a property list ...


};

struct CClassNode
{
	DWORD    m_pClass;
	std::vector<CVarDefPtr> * m_pVars;
//	CString m_sName;
//	CString m_sClassname;
	CString m_sType;
	CClassNode() 
	{ 
		m_pClass=0;
		m_pVars=NULL;
	}


};


//Base Class for all entity/class Declarations

class IStepList : public  std::vector<IStepNodePtr> 
{
public:
	CString DumpNodes() ;
};


class IStepNode  : public ISymbol
{
public:

	IStepNode()
	{		
		m_bAbstract=false;
	}
	virtual ~IStepNode() {}

	virtual std::vector<CVarDefPtr> & GetVarDefs() { return vars; }
	virtual std::vector<CVarDefPtr> & GetInstanceVars() { return instancevars; }

	virtual CString GetVarString(CString fmt="") {return "None"; }
	virtual HRESULT SetVarString(CString str) { return E_NOTIMPL; }

	virtual CStringVector GetInheritanceChain() { return parents; }
	virtual CStringVector GetSupertypesChain()  { return supertypes; }

	// can there be mutliple parents?
	void SetParent(IStepNodePtr parent) {  _parent=parent; }
	IStepNodePtr GetParent() { return _parent; }

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


	virtual bool hasChildNodes() { return vars.size() > 0; }
	IStepNodePtr firstChild() { if(vars.size() > 0) return vars[0]->GetStepNodePtr(); return NULL; }
	IStepNodePtr lastChild()  { if(vars.size() > 0) return vars[vars.size()-1]->GetStepNodePtr(); return NULL; }
	CString dataType() { return Classname();  }  // 
	StepNodeType nodeType() { return Type(); }
	IStepList  childNodes() {IStepList nodes; for(int i=0; i< vars.size(); i++) nodes.push_back((IStepNode *) vars[i]->m_ref); return nodes; }
	bool & Abstract() { return m_bAbstract; }

	CString tagName () { return Name(); }
	IStepNode * getPreviousSibling(IStepNodePtr node) 
	{ 
		if(_parent==NULL)
			return NULL;
		CVarDefs & vars = _parent->GetVarDefs();
		int i;
		for(i=0; i<vars.size(); i++)
		{
			if(vars[i]->m_ref==(DWORD) node.get())
				break;
		}
		if(i<1 || i>=vars.size())
			return NULL;
		return (IStepNode *) vars[i-1]->m_ref; 
		
	}
	IStepNode * getNextSibling(IStepNodePtr node) 
	{ 
		if(_parent==NULL)
			return NULL;
		CVarDefs & vars = _parent->GetVarDefs();
		int i;
		for(i=0; i<vars.size(); i++)
		{
			if(vars[i]->m_ref==(DWORD) node.get())
				break;
		}
		if((i+1)>= (vars.size()-1))
			return NULL;
		return (IStepNode *) vars[i+1]->m_ref; 
		
	}

	bool IsKindOf(CString classname, IStepNodePtr node = NULL)
	{
		if(node==NULL)
			node=this;
		if(node->Classname() == classname)
			return true;
		CStringVector::iterator it = find(node->parents.begin(), node->parents.end(),classname);
		if(it!=node->parents.end())
			return true;

		return false;
	}


	IStepNodePtr previousSibling () { return getPreviousSibling(this);; }
	IStepNodePtr nextSibling () { return getNextSibling(this); }
	IStepNodePtr parentNode() { return _parent; } 

	CVarDefs getElementsByTagName(CString tagname);

	void getElementsByCVarDefs(CVarDefs &vars, CStringVector &visited, CString tagname, CVarDefs & list);
	void getElementByCVarDef(CVarDefPtr var, CStringVector &visited, CString tagname, CVarDefs & list);

	int selectElementsByTagName(VarTable &table, CStringVector columns, CString fromnodes,  int bDistinct=false);
	bool getItemByCVarDefs(CVarDefs &vars,  CStringVector tagnames, VarList & list);
	_variant_t GetVarDefVal(CVarDefPtr  vardef);


	HRESULT ReturnErrMessage(CString errmsg) {DebugBreak(); _errmsg=errmsg; return E_FAIL; }
	CString GetErrMessage() { return _errmsg; }

	long _atom;
	virtual LONG Draw(IOglPlotter * m_plotter) { return POK; }

	///////////////////////////////////////////////////////////////////////////////
	bool m_bAbstract;
	IStepNodePtr _parent;
	CString m_sType;
	std::vector<CVarDefPtr> vars;
	std::vector<CVarDefPtr> instancevars;
	std::vector<CVarDefPtr>  m_optBaseClassVars;
	std::vector<int> _bounds;

	CString _errmsg;

	CStringVector parents; // classes this class is derived from...
	CStringVector supertypes; // classes downcast to, supertype of 

	// THIS IS TYPE INFORMATION ADDED FOR SIMPLICITY
		CString declaration;
	CStringVector _enums;
	CStringVector _szSelections;
};

inline 	bool IsSimpleType(StepNodeType eType) 
{  

	if( eType == string_  ||  eType == integer_  ||  eType == real_ ||  eType == boolean_  ||  eType == logical_ ||  eType == enumeration_ )
		return true;
	return false;

}



template <class T>
class EListT : public IStepNode, public std::vector<T>
{
public: 
	int min;   // e.g., 0 or 1
	int max;  // -1 infinite
	typedef typename std::vector<T>::iterator Iterator;
	typedef typename std::map<T, Iterator >::iterator RefmapIterator;
	 

	EListT<T>(){ this->_eType= bag_; }
	virtual ~EListT<T>() { } 
	bool IsSimpleListType(CString classname=L"");

	void clear() { std::vector<T>::clear(); vars.clear();}
	int size() { return std::vector<T>::size(); }
	void push_back(T t)
	{
		Iterator it = end();
		std::vector<T>::push_back(t);
		if(!IsSimpleListType())
		{
			CString classname = (t!=NULL) ? t->Classname() : "";
			vars.push_back(new CVarDef(this, StrFormat("%s[%d]",this->Name(), size()), index_, (DWORD) t.get(), classname, 0));
			vars.back()->Init(1, (StepNodeType)  22, this->ListClassname());
			instancevars=vars;
		}
	}
	int GetIndex(CVarDefPtr vardef)
	{
		for(int i=0; i< size(); i++)
			if( ( (T::element_type *) vardef->m_ref)== ((T::element_type *) this->at(i).get()))
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
		vars.erase(vars.begin() + i);
		return		std::vector<T>::erase(begin()+i);
	}

	virtual CString GetVarString(CString separator="") 
	{ 
		CString tmp;
		tmp+="(";
		for(int i=0; i< size(); i++)
		{
			if(i>0)
				tmp+=separator;
			
			if(IsSimpleListType(ListClassname()) && this->at(i)!=NULL)  // this is what i need...
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
		this->_eType= bag_;
		this->m_eListType=eListType;
		this->Classname() = StrFormat("EListT<%s>", classname);
		_sListClassname=classname;
	}
	IStepNodePtr InsertItem(Iterator it);
};

typedef boost::tuples::tuple<IStepNodePtr, IStepNodePtr> IStepTable;

//vector<vector<IStepNodePtr> > table (numRows, vector<IStepNodePtr>(numCols)) 
typedef TResizingTable<IStepNodePtr>  StepPtrTable;

class EReal   : public IStepNode
{
public: 
	double val; 
	operator double() { return val; }
	double & operator() () { return val; }
	virtual CString GetVarString(CString fmt="") {if(fmt=="") fmt="%f"; return StrFormat(fmt, val); }
	CLASSDEF(EReal);
	virtual HRESULT SetVarString(CString str) {	try { double dVal = boost::lexical_cast<double>(str);  val=dVal; } catch(...) { return 	ReturnErrMessage("Bad real string"); } return S_OK; }

	EReal(double val) 
	{ 
		this->val = val; 
		Init();
	}
	void Init()
	{
		this->_eType= real_;
		this->Classname() = "Ereal";
		vars.push_back(new CVarDef(this, "real" ,(StepNodeType) real_, (DWORD) &(this->val), "real"));
		instancevars=vars;
	}
} ;
class EInteger : public IStepNode
{
public: 
	long val; 
	//CLASSDEF(EInteger);
	EInteger();
	operator long() { return val; }
	long & operator ()() { return val; }
	virtual CString GetVarString(CString fmt="") { if(fmt=="") fmt="%d"; return StrFormat(fmt, val); }
	virtual HRESULT SetVarString(CString str) {	try { long nVal = boost::lexical_cast<long>(str);  val=nVal; } catch(...) { return ReturnErrMessage("Bad integer string"); } return S_OK; }
	static IStepNodePtr Create(const char * name) { return (IStepNode *)  new EInteger(); }
	EInteger(long val) 
	{ 
		this->val = val; 
		Init();
	}
	void Init()
	{
		this->_eType= integer_;
		this->Classname() = "Einteger";
		vars.push_back(new CVarDef(this, "integer" ,(StepNodeType) integer_, (DWORD) &(this->val), "integer"));
		instancevars=vars;
	}
};

class EString : public IStepNode
{
public: 
	CString val; 
	CLASSDEF(EString);
	operator CString() { return val; }
	virtual CString GetVarString(CString fmt="") {if(fmt=="") fmt="'%s'"; return StrFormat(fmt, val); }
	virtual HRESULT SetVarString(CString str) {	val=str; return S_OK; }
	CString operator() () {return val; }
	EString(CString val) 
	{ 
		this->val = val; 
		Init();
	}
	void Init()
	{
		this->_eType= string_;
		this->Classname() = "Estring";
		vars.push_back(new CVarDef(this, "text" ,(StepNodeType) string_, (DWORD) &(this->val), "string"));
		instancevars=vars;

	}
};

class EEnum : public IStepNode
{
public: 
	long _nSelection;
	CLASSDEF(EEnum);
	operator long() { return _nSelection; }
	long & operator ()() { return _nSelection; }
	virtual CString GetVarString(CString fmt="") {return GetEnum2String(_nSelection);}
	virtual HRESULT SetVarString(CString str) {	SetString2Enum(str); return S_OK; }

	virtual CString GetEnum2String(int e){ return ""; }
	virtual long GetString2Enum(CString szEnum){ return 0; }
	virtual void SetString2Enum(CString szEnum){ _nSelection=GetString2Enum(szEnum); }
	EEnum(long val) 
	{ 
		this->_nSelection = val; 
		Init();
	}
	void Init()
	{
		this->_eType= enumeration_;
		this->Classname() = "Eenum";
		vars.push_back(new CVarDef(this, "enum" ,(StepNodeType) integer_, (DWORD) &(this->_nSelection), "enum"));
		instancevars=vars;
	}
};

class EBoolean : 
	public EEnum
{
public:
	CLASSDEF(EBoolean); 
	enum EBooleanEnum
	{
		efalse=0,
		etrue,
	} ;
	void SetSelection(EBooleanEnum nSelection) {   _nSelection=(int) nSelection;; }
	virtual CString GetEnum2String(int e) {
		static int nEnums = 2;
		static char * szEnums[2]={".FALSE.", ".TRUE."};
		if(e>=nEnums) return "$"; return szEnums[(int) e];
	}
	virtual long GetString2Enum(CString szEnum) 
	{
		szEnum.MakeLower();
		static int nEnums = 2;	
		for(int i=0; i<nEnums; i++){
			if(GetEnum2String(i)==szEnum) return i; 
		}
		return 0;
	}
};


typedef EInteger ELogical;

class ESelection : public IStepNode
{
public: 
	IStepNodePtr _pSelection;
	CLASSDEF(ESelection);
	ESelection(IStepNodePtr pClass) 
	{ 
		_pSelection=pClass;
	}
	void Init()
	{
		this->_eType= select_;
		this->Classname() = "ESelect";
	}
	void SetSelection(IStepNodePtr pSelection) {  _pSelection=pSelection; }
	IStepNodePtr GetSelection() { return _pSelection; }
};


typedef EInteger ENumber;
typedef EInteger EBinary;


EXP_DECLARE_SMARTPOINTER(ENumber) 
EXP_DECLARE_SMARTPOINTER(EString) 
EXP_DECLARE_SMARTPOINTER(EInteger) 
EXP_DECLARE_SMARTPOINTER(EReal) 
EXP_DECLARE_SMARTPOINTER(EBoolean) 
EXP_DECLARE_SMARTPOINTER(ELogical) 
EXP_DECLARE_SMARTPOINTER(EEnum) 
EXP_DECLARE_SMARTPOINTER(EBinary) 




extern int GetVarItemSize(IStepNodePtr pNode, CString itemBranch);
extern CVarDefPtr GetVarDef(IStepNodePtr pNode, CString itemBranch);
extern IStepNodePtr GetVarItem(IStepNodePtr pNode, CString itemBranch);

extern void BuildInstanceDef(CVarDefs & vars, CVarDefs &instances, CStringVector &vVisitedClasses);
extern void StoreCVarDef(CVarDefPtr vardef, CString &val);
extern HRESULT Store(CVarDefPtr vardef, IStepNodePtr val); 
extern StepNodeType GetBaseType(CVarDefs & vars);

extern IStepNodePtr GetThis(CVarDefPtr  vardef);


extern CString DumpCVarDefs(CVarDefs &vars, int bFirst=0);
extern CString DumpCVarDef(CVarDefPtr vardef);


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

typedef boost::function<IStepNodePtr(CString, CString) >  ClassGeneratorFcn;
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


inline bool CVarDef::IsSimpleListType() 
{ 		
	if(!IsListType())
		return false;
	EListT<IStepNodePtr> * list=  (EListT<IStepNodePtr> *) this->m_ref;
	if(list==NULL)  // should never ever be null.
		return false;
	return list->IsSimpleListType(this->_sListClassname);
}

inline CString IStepList::DumpNodes() 
{
	CString tmp;
	for(int i=0; i<size(); i++)
	{
		IStepNodePtr step = at(i);
		tmp.AppendFormat("%s=%s\n", at(i)->Classname(), at(i)->GetVarString());
	}
	return tmp;
}	

template <typename T>
inline HRESULT EListT<T>::SetVarString(CString str) 
{	
	int i;
	IStepNodePtr step;
	// FIXME: write boost spirit script to parse into tokens.
	str.Replace("(","");
	str.Replace(")","");
	CStringVector tokens = CStringVector::Tokenize(str,",");
	
	// fixme - must be simple list type or kind of simple list type

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

	return S_OK; 
}

template <typename T>
inline IStepNodePtr EListT<T>::InsertItem(Iterator it)
{
	T step = (T::element_type *) (IStepNode *) CClassGenerators::gClassGenerators.CreateClass(ExpDemangle(_sListClassname),"").get();
	if(step==NULL)
		return step; 

	this->insert(it,  step);
	if(!IsSimpleListType())
	{
		vars.push_back(new CVarDef(this, StrFormat("%s[%d]",this->Name(), size()), index_, (DWORD) &back(), ListClassname() , 0));
	}
	return step;
}


template <typename T>
inline 	bool EListT<T>::IsSimpleListType(CString classname)
{
	if(::IsSimpleType(m_eListType))
		return true;

	//if(classname=="Elength_measure")
	//	DebugBreak();

	T step = (T::element_type *) (IStepNode *) CClassGenerators::gClassGenerators.CreateClass(ExpDemangle(classname),"").get();
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
inline	IStepNode * CVarDef::GetStepNodePtr() 
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
extern void CloneCVarDefs(CVarDefs &fromvars, CVarDefs &tovars, int bFirst=false);
extern void CloneCVarDef(CVarDefPtr fromvardef, CVarDefPtr  tovardef);