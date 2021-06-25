//
//	CannedCyles.h
//


// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.


#pragma once
#include "SymbolTable.h"
#include "StepVariant.h"
#include "ScriptParser.h"
#import <msxml6.dll>
#include "iges.h"

class CCannedCycleItem;
class CCannedCycleItems;

namespace Cycle
{
	__declspec(selectany) const TCHAR * Compute=_T("Compute");
	__declspec(selectany) const TCHAR * Feature=_T("Feature");
	__declspec(selectany) const TCHAR * Operation=_T("Operation");
	__declspec(selectany) const TCHAR * Workpiece=_T("Workpiece");
	__declspec(selectany) const TCHAR * Executable=_T("Executable");
	__declspec(selectany) const TCHAR * StepPosition=_T("StepPosition");
	__declspec(selectany) const TCHAR * Project=_T("Project");
	__declspec(selectany) const TCHAR * Header=_T("Header");

	
	// Add Alias, Pointer, Reference
	__declspec(selectany) const TCHAR * String=_T("String");
	__declspec(selectany) const TCHAR * Double=_T("Double");
	__declspec(selectany) const TCHAR * Long=_T("Long");
	__declspec(selectany) const TCHAR * Boolean=_T("Boolean");
	__declspec(selectany) const TCHAR * Classname=_T("Classname");
	__declspec(selectany) const TCHAR * Length=_T("Length");
	__declspec(selectany) const TCHAR * Position=_T("Position");
	__declspec(selectany) const TCHAR * Speed=_T("Speed");
	__declspec(selectany) const TCHAR * Feed=_T("Feed");
	__declspec(selectany) const TCHAR * Angle=_T("Angle");
	__declspec(selectany) const TCHAR * Vector=_T("Vector");
	__declspec(selectany) const TCHAR * Enum=_T("Enum");
	__declspec(selectany) const TCHAR * Polyline=_T("Polyline");
	__declspec(selectany) const TCHAR * CompositeCurve=_T("CompositeCurve");

};

inline Vector FromComVector(Vector3d comVector )
{
	return Vector (comVector.x, comVector.y, comVector.z); 
}


class CCannedCycleItem
{
public:
	CCannedCycleItem(CCannedCycleItems * pParent)
	{
		m_bEnabled=false;
		_l=0;
		_d=0.0;
		_parent= pParent;

	}
	CCannedCycleItem(const TCHAR * name, const TCHAR * stepsubtype, const TCHAR * type, const TCHAR * steppath)
	{

		m_bEnabled=false;
		m_steppath=steppath;
		m_ncdataname=name;
		m_type=type;
		m_step=stepsubtype;
		_l=0;
		_d=0.0;
		m_bDirty=false;


	}
	CString ToString(CString fmt=_T(""));
	void ExtractValue(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem);
	void ExtractXmlValue(MSXML2::IXMLDOMNodePtr pOperation);
	void InjectValue(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem);
	CString & Name() { return m_ncdataname; }
	CString & Type() { return m_type; }
	CString & StepSubtype() { return m_step; }
	CString & StepPath() { return m_steppath; }
	Variant GetValue() ;
	void SetValue(Variant val) ;
	bool & IsDirty() { return m_bDirty; }
	void SetDirty(bool bFlag=true){ m_bDirty=bFlag; }


	CString m_ncdataname;
	CString m_steppath;
	CString m_type;
	CString m_step;


//	union{
	long _l;
	CString _str;
	double _d;
	Vector _v;
	Iges::CompositeCurve curve;

//	};
	bool m_bEnabled;
	bool m_bDirty;
	// Application specific
	tree_parse_info<iterator_t> scripttree;
	CCannedCycleItems *_parent;

};


typedef boost::tuple<CString, CString> OutputTuple; 
typedef std::vector<CString> OutputLine;
typedef std::vector<std::vector<CString> > OutputsType;

class CCannedCycleItems : 
	public std::vector<CCannedCycleItem *>,
	public CScriptParser
{
public:

	// Declarations
	typedef std::vector<CCannedCycleItem *>::iterator COPCItemsIterator;
	static const int nOutputTypeIndex=0;
	static const int nFormatIndex=1;
	static const int nVarIndex=2;

	// Data
	CSymbolTable _IniSymbols;
	OutputsType Tests;
	OutputsType Outputs;
	// this may be a bit too all ecompassing
	static const int cMM=1;
	static const int cINCHES=2;
	int _nUnits;


	// Methods
	CCannedCycleItems();
	CCannedCycleItem * FindItem(CString);
	CString ToString();
	CString ToXmlString();
	CString OutputSetupToString();
	CString OutputDataToString();
	CStringVector Verify();
	void ClearDirtyFlags() { for(int i=0; i< size() ; i++) { this->at(i)->SetDirty(false); } }
	bool IsDirty(CString item) { CCannedCycleItem * it= FindItem(item); if(it==NULL) return false; return it->IsDirty(); }
	void Inches() ;
	void MM();
	void SetUnits(int nUnits) { _nUnits= nUnits; }

	// Step NC extractions
	void Extract(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem);
	void Inject(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem);

	// XML extractions
	void ExtractXml(MSXML2::IXMLDOMNodePtr pOperation);

	template<typename T>
	T GetValue(tstring item) 
	{
		CCannedCycleItem *  test = FindItem(item.c_str());
		if(test==NULL)
		{
			DebugBreak();
			return Variant().get<T>();
		}
		return test->GetValue().get<T>();
	}

	template<typename T>
	T GetValue(tstring item, T tDefault) 
	{
		CCannedCycleItem *  test = FindItem(item.c_str());
		if(test==NULL)
		{
			return tDefault;
		}
		return test->GetValue().get<T>();
	}

	bool ItemExists(CString szItem) { return FindItem(szItem)!=NULL; }
	Variant GetItemValue(tstring item, Variant val) 
	{
		CCannedCycleItem *  test = FindItem(item.c_str());
		if(test==NULL)
			return val;
		return test->GetValue();
	}

	void AddItem(CString name, CString type, CString steptype,  CString steppath, Variant val)
	{
		CCannedCycleItem * item;
		if(ItemExists(name))
		{
			DebugBreak();
		}
		item = new CCannedCycleItem(this);
		item->m_ncdataname=name;
		item->m_type=type;
		item->m_step= steptype;
		item->m_steppath=steppath;
		item->SetValue(val);
		push_back(item);
	}
	void Remove(CString itemname)
	{
		for(int i=0; i< size(); i++)
		{
			CCannedCycleItem * item = this->at(i);
			if(item->m_ncdataname == itemname)
			{
				this->erase(this->begin() + i);
			}
		}
	}

	virtual Variant GetVariable(CString var) 
	{ 
		CCannedCycleItem * item  = FindItem((LPCTSTR) var);
		if(item!=NULL)
			return item->GetValue();
		return Variant();
	}
	virtual HRESULT SetVariable(CString var, Variant val) 
	{  
		CCannedCycleItem * item  = FindItem((LPCTSTR) var);
		if(item==NULL)
			return E_FAIL;
		item->SetValue(val);
		return S_OK;
	}
	virtual void AddVariable(CString var, Variant val) 
	{  
		CCannedCycleItem * item = new CCannedCycleItem(this);
		item->m_ncdataname=var;
		item->SetValue(val);
		push_back(item);
	}

};

#define BEGIN_STEP_PARAMETER_MAP(theName) \
	virtual void  InitItems(theName * pThis)\
	{	CCannedCycleItems *pItems= &items;
		//CCannedCycleItems *items = GetMap();\
		//static bool first_time = true;\
		//if(first_time)\
		//{\

#define BEGIN_STEP_MAP(theName) \
	virtual void  InitStepItems(CCannedCycleItems *pItems)\
	{	
		//CCannedCycleItems *items = GetMap();\
		//static bool first_time = true;\
		//if(first_time)\
		//{\

#define ENTRY(name, stepsubtype, type, steppath) \
		pItems->push_back(new CCannedCycleItem(name, stepsubtype, type,  steppath));


#define ENTRYSET(name, stepsubtype, type, steppath, defaultval) \
		pItems->push_back(new CCannedCycleItem(name, stepsubtype, type,  steppath));\
		pItems->SetVariable(name, defaultval) ;


#define LINK(Classname) \
		{ Classname c; c.InitStepItems(pItems);  c.InitValues(pItems);}

#define STEPNC_PARAMETER_ENTRY(name, stepsubtype, type, steppath) \
		items.push_back(new CCannedCycleItem(name, stepsubtype, type,  steppath));

#define END_STEP_MAP(theName) \
	}

#define END_STEP_PARAMETER_MAP(theName) \
	}

#define BEGIN_XML_PARAMETER_MAP(theName) \
	virtual void  InitMastercamItems(theName * pThis)\
	{ CCannedCycleItems *pItems= &xmlitems;
		//CCannedCycleItems *items = GetMap();\
		//static bool first_time = true;\
		//if(first_time)\
		//{\


#define STEPNC_XML_ENTRY(name, stepsubtype, type, steppath) \
		xmlitems.push_back(new CCannedCycleItem(name, stepsubtype, type,  steppath));


#define END_XML_PARAMETER_MAP(theName) \
	}
		//	first_time=false;  \
		//} \
// [ROUGH|FINISH|BOTH] format, dataitem
#define BEGIN_OUTPUT_PARAMETER_MAP(theName) \
	void InitOutputs(theName * pThis)\
	{\
		std::vector<CString> outputs(4);
		//static bool first_time = true;\
		//if(first_time)\
		//{\


#define STEPNC_OUTPUT_ENTRY(type, aformat, dataitem, opt) \
		outputs[0]=type; outputs[1]=aformat; outputs[2]=dataitem; outputs[3]=opt;\
		items.Outputs.push_back(outputs);

#define END_OUTPUT_PARAMETER_MAP(theName) \
	}
	//		first_time=false;  \
	//	} \
	//}

#define BEGIN_VERIFY_PARAMETER_MAP(theName) \
	void InitTests(theName * pThis)\
	{\
		static bool first_time = true;\
		if(first_time)\
		{\
		std::vector<CString> checks(4);


#define STEPNC_VERIFY_ENTRY(type, cycle, test, message) \
		checks[0]=type; checks[1]=cycle; checks[2]=test; checks[3]=message;\
		items.Tests.push_back(checks);

#define END_VERIFY_PARAMETER_MAP(theName) \
			first_time=false;  \
		} \
	}