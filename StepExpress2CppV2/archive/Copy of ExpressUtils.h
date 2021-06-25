//
// ExpressUtils.h
//

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

extern CClassGenerators  gClassGenerators;
EXP_DECLARE_SMARTPOINTER(CVarDef) 
EXP_DECLARE_SMARTPOINTER(IStepNode) 
inline CString ExpMangle(CString classname) {if(classname.GetAt(0)=='E') return classname; return 'E' + classname; }
inline CString ExpDemangle(CString classname) {if(classname.GetAt(0)=='E') return classname.Mid(1); else return classname;}

typedef std::vector<CVarDefPtr> CVarDefs;

//static DWORD Create(const char * name);

#define CLASSDEF(X) \
	X();\
	virtual ~X(){}\
	X* _Self;\
	IStepNodePtr Self() { return _Self; }\
	static IStepNodePtr Create(const char * name) {IStepNode  * ptr= new X(); ptr->Name()=name; return ptr;}\
	static CStringVector GetInheritanceChain();\
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

//	virtual CString DumpVars() { return DumpCVarDefs(this->vars); }\

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
	typereference_=33
};

class ISymbol : public IExpress
{
public:

	ISymbol(){_eType=(StepNodeType) -1; m_eListType=unknown_; _nDimension=0;}
	virtual ~ISymbol() {}
	CString & Name() { return _sName; }
	CString & Namespace() { return _sNamespace; }
	CString & Classname() { return m_sClassname; }
	CString & ListClassname() { return _sListClassname; }

	StepNodeType & Type () { return _eType; }
	bool IsSimpleType() { return (_eType==integer_ || _eType==real_ || _eType == logical_ || _eType==string_ || _eType==enumeration_); }
	int GetVisited() { return _bVisited; }
	void SetVisited(int bval) { _bVisited = (int) bval; }


	StepNodeType m_eListType;
	int _nDimension;
	std::vector<int> vLowerBounds;
	std::vector<int> vUpperBounds;


	CString _sName;
	CString _sNamespace;
	CString m_sClassname;
	CString _sListClassname;
	CString _sFile;
	int _nLine;
	StepNodeType _eType;
	int _bVisited;
	// vs IExpress * _parent; //???

};
EXP_DECLARE_SMARTPOINTER(ISymbol);


struct CVarDef : public ISymbol
{
	IStepNode * _owner;
	DWORD m_ref;
	CVarDefs * m_optBaseClassVars;
	bool m_bOptional;
	// type information
	CString m_sReferenceChain;
	bool m_bAmbiguous;

	CVarDef() {m_ref=0;}
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
	IStepNode * GetStepNodePtr() { return (IStepNode *) m_ref; }
	IStepNode * GetOwnerPtr() { return  _owner; }

	StepNodeType & eType() { return _eType; }
	CString & TypeClassName() { return m_sClassname; }
	void Init(int nDimension, StepNodeType eListType , CString listclassname, int min=1, int max=-1)
	{
		_sListClassname= listclassname;
		this->_nDimension=nDimension;
		m_eListType=eListType;
			
	}

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
	bool IsList() { return _eType== list_ || _eType== set_ || _eType== aggregate_ || _eType== array_ || _eType== bag_; }
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
		if( _eType== string_  ||  _eType== integer_  ||  _eType== real_)
			return true;
		return false;
	}
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

struct TypeNode : public ISymbol
{
	CString declaration;
	CStringVector parents;
	CStringVector _enums;
	CStringVector _szSelections;
	std::map<CString, StepNodeType> VarDefs;
};
EXP_DECLARE_SMARTPOINTER(TypeNode) 


template<class T>
struct SetType
{
	int min;   // e.g., 0 or 1
	int max;  // -1 infinite
	CString m_sName;
	CString m_sType;
	CString m_sReferenceChain;
	bool m_bOptional;
	std::vector<T> items;
	StepNodeType m_eListType;
	SetType<T>(){ min=1;max=-1;m_bOptional=0; }
	void Init(CString name, StepNodeType eListType , CString type, CString parent=L"", bool bOptional=true, int min=1, int max=-1)
	{
		this->m_eListType=eListType;
		this-> min=min;   // e.g., 0 or 1
		this->max=max;  // -1 infinite
		this->m_sName=name;
		this->m_sType=type;
		this->m_sReferenceChain=parent;
		this->m_bOptional=bOptional;
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

	//IStepNode(IStepNode * parent=NULL) : _pParent(parent) {}
	virtual ~IStepNode() {}
	virtual std::vector<CVarDefPtr> & GetVarDefs() { return vars; }
	virtual std::vector<CVarDefPtr> & GetInstanceVars() { return instancevars; }
	virtual CString GetVarString(CString fmt="") {return "None"; }

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
			::DebugBreak();
		}
		return GetInstanceVars()[n]; 
	}
	//	virtual CString DumpVars() { return DumpCVarDefs(*GetVarDefs()); }


	virtual bool hasChildNodes() { return vars.size() > 0; }
	IStepNodePtr firstChild() { if(vars.size() > 0) return vars[0]->GetStepNodePtr(); return NULL; }
	IStepNodePtr lastChild()  { if(vars.size() > 0) return vars[vars.size()-1]->GetStepNodePtr(); return NULL; }
	CString dataType() { return Classname();  }  // 
	StepNodeType nodeType() { return Type(); }
	IStepList  childNodes() {IStepList nodes; for(int i=0; i< vars.size(); i++) nodes.push_back((IStepNode *) vars[i]->m_ref); return nodes; }

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

	///////////////////////////////////////////////////////////////////////////////
	IStepNodePtr _parent;
	CString m_sType;
	std::vector<CVarDefPtr> vars;
	std::vector<CVarDefPtr> instancevars;
	std::vector<CVarDefPtr>  m_optBaseClassVars;
	std::vector<int> _bounds;

	CStringVector parents; // classes derived from...
	void getElementsByCVarDefs(CVarDefs &vars, CStringVector &visited, CString tagname, CVarDefs & list);
	void getElementByCVarDef(CVarDefPtr var, CStringVector &visited, CString tagname, CVarDefs & list);

	int selectElementsByTagName(VarTable &table, CStringVector columns, CString fromnodes,  int bDistinct=false);
	bool getItemByCVarDefs(CVarDefs &vars,  CStringVector tagnames, VarList & list);
	_variant_t GetVarDefVal(CVarDefPtr  vardef);
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

	EReal(double val) 
	{ 
		this->val = val; 
		this->_eType= real_;
		this->Classname() = "Ereal";
		vars.push_back(new CVarDef(this, "real" ,(StepNodeType) real_, (DWORD) &(this->val), "real"));
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
	static IStepNodePtr Create(const char * name) { return (IStepNode *)  new EInteger(); }
	EInteger(long val) 
	{ 
		this->val = val; 
		this->_eType= integer_;
		this->Classname() = "Einteger";
		vars.push_back(new CVarDef(this, "integer" ,(StepNodeType) integer_, (DWORD) &(this->val), "integer"));
	}
};

class EString : public IStepNode
{
public: 
	CString val; 
	CLASSDEF(EString);
	operator CString() { return val; }
	virtual CString GetVarString(CString fmt="") {if(fmt=="") fmt="%s"; return StrFormat(fmt, val); }
	CString operator() () {return val; }
	EString(CString val) 
	{ 
		this->val = val; 
		this->_eType= string_;
		this->Classname() = "Estring";
		vars.push_back(new CVarDef(this, "text" ,(StepNodeType) string_, (DWORD) &(this->val), "CString"));

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
	virtual CString GetEnum2String(int e){ return ""; }
	virtual long GetString2Enum(CString szEnum){ return 0; }
	virtual void SetString2Enum(CString szEnum){ _nSelection=GetString2Enum(szEnum); }
	EEnum(long val) 
	{ 
		this->_nSelection = val; 
		this->_eType= enumeration_;
		this->Classname() = "Eenum";
		vars.push_back(new CVarDef(this, "enum" ,(StepNodeType) integer_, (DWORD) &(this->_nSelection), "enum"));
	}
};

typedef EInteger EBoolean;
typedef EInteger ELogical;
typedef EInteger Binary;
typedef EInteger Logical;
typedef EInteger Number;
//TypeNode CString identifier;

typedef EReal length_measure;
typedef length_measure shape_tolerance;
typedef EReal ratio_measure ;

class ESelection : public IStepNode
{
public: 
	IStepNodePtr _pSelection;
	CLASSDEF(ESelection);
	ESelection(IStepNodePtr pClass) 
	{ 
		this->_eType= select_;
		this->Classname() = "ESelect";
		_pSelection=pClass;
	}
	void SetSelection(IStepNodePtr pSelection) {  _pSelection=pSelection; }
	IStepNodePtr GetSelection() { return _pSelection; }
};


typedef EInteger Enumber;

EXP_DECLARE_SMARTPOINTER(Enumber) 
EXP_DECLARE_SMARTPOINTER(EString) 
EXP_DECLARE_SMARTPOINTER(EInteger) 
EXP_DECLARE_SMARTPOINTER(EReal) 
EXP_DECLARE_SMARTPOINTER(EBoolean) 
EXP_DECLARE_SMARTPOINTER(ELogical) 
EXP_DECLARE_SMARTPOINTER(Binary) 
EXP_DECLARE_SMARTPOINTER(Logical) 
EXP_DECLARE_SMARTPOINTER(EEnum) 

class SymbolTable : public IExpress 
{
private:
	typedef std::map<CString, TypeNodePtr>::iterator NamedTypeIterator;
	typedef std::map<CString, IStepNodePtr>::iterator NamedEntityIterator;
	
	std::vector<SymbolTable> _includes;

	std::vector<ISymbolPtr> _symbols;

	std::vector<TypeNodePtr>  types;
	std::map<CString, TypeNodePtr>  namedtypes;
	std::vector<IStepNodePtr>  entities;
	std::map<CString, IStepNodePtr>  namedentities;
public:
	std::vector<CString> szNamespace;
	CString _szSchema;
	std::vector<CString> _schemas;

	void Clear() 
	{ 
		szNamespace.clear(); _schemas.clear(); 
		types.clear(); namedtypes.clear(); 
		entities.clear(); namedentities.clear();
		_symbols.clear(); _includes.clear(); 
	}

	std::vector<TypeNodePtr> & Types() { return types;}
	std::map<CString, TypeNodePtr> &  NamedTypes() { return  namedtypes; }
	std::map<CString, IStepNodePtr> & NamedEntities() { return namedentities; }
	std::vector<IStepNodePtr> & Entities() { return entities; }
	void AddSymbol(ISymbolPtr symbol)
	{	
		_symbols.push_back(symbol);	
	}
	ISymbolPtr FindSymbol(CString name, CString anamespace=_T("") )
	{
		for(int i=0; i<_symbols.size(); i++) 
		{
			ISymbolPtr symbol = _symbols.at(i);
			if(symbol->_sName == name)
			{
				if(anamespace=="")
					return symbol;
				if(symbol->_sNamespace == anamespace)
					return symbol;
			}

		}
	}

	IStepNodePtr FindNamedEntity(CString name)
	{
		NamedEntityIterator it = namedentities.find(name);
		if(it!= namedentities.end())
			return (*it).second;
		return NULL;
	}

	StepNodeType FindType(CString name)
	{
		for(int i=0; i<_symbols.size(); i++) 
		{
			ISymbolPtr symbol = _symbols.at(i);
			if(symbol->_sName == name)
				return symbol->_eType;
		}
		return (StepNodeType) 0;
	}

	StepNodeType FindVarType(CString name)
	{
		NamedTypeIterator typeit;
		NamedEntityIterator entityit;
		typeit=namedtypes.find(name);

		if(typeit !=namedtypes.end())
		{
			if((*typeit).second==NULL)
				DebugBreak();
			return (*typeit).second->_eType;
		}

		entityit= namedentities.find(name);
		if(entityit != namedentities.end() )
		{
			if((*entityit).second==NULL)
				DebugBreak();
			return (*entityit).second->_eType;
		}

		return (StepNodeType) 0;
	}

	StepNodeType GetType(ISymbol * symbol) { if(symbol==NULL) return (StepNodeType) 0; return symbol->_eType; }

	CVarDef * CreateVarDef(CString name, CString anamespace, StepNodeType type)
	{
		CVarDef * var = new CVarDef;
		var->_sName=name; 
		var->_eType=type; 
		var->_sNamespace=anamespace; 
		AddSymbol((ISymbol *)var);
		return var;

	}
	TypeNodePtr CreateTypeNode(CString name, CString basetype="", StepNodeType type=unknown_)
	{
		TypeNode * var = new TypeNode;
		name = ExpMangle(name); 
		types.push_back(var);
		var->Name()=name; 
		namedtypes[name]= var; 
		var->_eType=type;
		//var->_basetype=basetype;
		AddSymbol((ISymbol *) var);
		return var;
	}
	IStepNodePtr CreateEntityDef(CString name, CString anamespace, StepNodeType type=unknown_)
	{
		IStepNodePtr var = new IStepNode;
		name = ExpMangle(name); 
		entities.push_back(var);
		var->Name()= name; 
		namedentities[name]= var; 
		var->Namespace()=anamespace;
		var->_eType=type;
		AddSymbol((ISymbolPtr) var);
		return var;
	}
	CString DumpSymbols()
	{
		CString tmp;
		for(int i=0; i< _symbols.size(); i++)
		{
			ISymbolPtr symbol = _symbols.at(i);
			tmp.AppendFormat("%s Type=%d  ClassDef=%s\n", symbol->_sName, symbol->_eType, symbol->m_sClassname);

		}
		return tmp;
	}
	// extern CString DumpEntities ();
};
EXP_DECLARE_SMARTPOINTER(SymbolTable) 




extern CString DumpCVarDefs(CVarDefs &vars, int bFirst=0);
extern CString DumpCVarDef(CVarDefPtr vardef);

extern void BuildInstanceDef(CVarDefs & vars, CVarDefs &instances);
extern void StoreCVarDef(CVarDefPtr vardef, CString &val);
extern HRESULT Store(CVarDefPtr vardef, IStepNodePtr val); 

extern IStepNodePtr GetThis(CVarDefPtr  vardef);

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



typedef boost::function<IStepNodePtr(CString, CString) >  ClassGeneratorFcn;
class CClassGenerators : public std::vector<ClassGeneratorFcn > 
{
public:

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
