//
// FeatureCycles.h
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#pragma once
#define _USE_MATH_DEFINES 
#include <math.h>
#include "atlstr.h"
#include "Misc.h"
#include <boost/intrusive_ptr.hpp>
#include "linalg3d.h"

#include "CannedCyles.h"
class IFeature;
class IWorkCycle;
class IWorkCycles;
class CWorldModel;
extern CWorldModel  gWm;
extern IStepNode * gProject;



#define NaN HUGE_VAL
#define IMPLEMENT_PARAMETER(TYPE, prop, name) \
	public: TYPE name;\
	public: TYPE Get##prop() { return name; }\
	public: void Set##prop(TYPE name) { this->name= name; };
#define IMPLEMENT_STATIC_PARAMETER(TYPE, prop, name) \
	public: static TYPE name;\
	public: static TYPE Get##prop() { return name; }\
	public: static void Set##prop(TYPE name) { this->name= name; };

#define FEATURE_EXT_CLASS 
#define FEATURE_DECLARE_SMARTPOINTER(className)                                             \
	typedef FEATURE_EXT_CLASS boost::intrusive_ptr<className> className##Ptr;              \
	typedef FEATURE_EXT_CLASS boost::intrusive_ptr<const className> className##ConstPtr;

#define FEATURECLASSDEF(X)	private: X(const X&); void operator=(const X&);	public:

//static UnaryOpMap mapUnaryOps(initUnaryOpPair, initUnaryOpPair + sizeof (dimension_of ( initUnaryOpPair )) );

class CWorldModel
{
public:

	enum CANON_PLANE {CANON_PLANE_XY=1, CANON_PLANE_YZ, CANON_PLANE_XZ} ;
	enum CANON_UNITS {CANON_UNITS_INCHES=1, CANON_UNITS_MM, CANON_UNITS_CM} ;
	IMPLEMENT_PARAMETER(CANON_PLANE, Plane, _nPlane);  // xy=1, yz=2, xz=3
	IMPLEMENT_PARAMETER(CANON_UNITS, Units, _nUnits);  // xy=1, yz=2, xz=3
	IMPLEMENT_PARAMETER(int, BlockNum, _nBlockNum);  // depth of total cut
	IMPLEMENT_PARAMETER(int, BlockIncrement, _nBlockIncr);  // depth of total cut
	IMPLEMENT_PARAMETER(bool, UseBlockNums, _bUseBlockNums);  // depth of total cut
	IMPLEMENT_PARAMETER(int, FloatingPrecision, nFPrecision);  // depth of total cut
	IMPLEMENT_PARAMETER(double, GlobalTolerance, _dGlobalTolerance); //z0
	CWorldModel()
	{
		_nPlane=CANON_PLANE_XY;
		_nUnits=CANON_UNITS_MM;
		SetUseBlockNums(true);  // depth of total cut
		nFPrecision=3;
		_nBlockIncr=10;
	}


};


class  CXMLItems  
{
public:
	CCannedCycleItems* GetXMLMap() { return &xmlitems; }
	CCannedCycleItems xmlitems;
};

class  CStepNCItems 
{
public:
	CCannedCycleItems* GetStepMap() { return &items; }
//private:
	CCannedCycleItems items;
	IStepNodePtr _pExecutable;
	IStepNodePtr _pFeature;
	IStepNodePtr _pOpItem;
	//HRESULT SetVariable(tstring var, tstring value)
	//{
	//	if(items.FindItem(var.c_str()) == NULL)
	//		return E_FAIL;
	//	items.SetVariable(var.c_str(), Variant(value.c_str()));
	//	return S_OK;
	//}
	HRESULT SetVariable(tstring var, Variant value)
	{
		if(items.FindItem(var.c_str()) == NULL)
			return E_FAIL;
		items.SetVariable(var.c_str(), value);
		return S_OK;
	}
	bool IsVariable(tstring var)
	{
		if(items.FindItem(var.c_str()) == NULL)
			return false;
		return true;
	}
	virtual HRESULT LoadIntoStep()  { return S_OK; }
	virtual IStepNodePtr StepRoot(CCannedCycleItem * pItem)
	{
		if(pItem->m_step== Cycle::Project) 
			return gProject; // <--- FIXME

		else if(pItem->m_step== Cycle::Feature)
			return _pFeature;

		else  if(pItem->m_step== Cycle::Operation)
			return _pOpItem;

		else  if(pItem->m_step== Cycle::Executable)
			return _pExecutable;
		//else
		//	throw std::exception("CCannedCycleItems : IStepNode Root unknown type");
		return NULL;
	}

};

class IWorkCycle  : 
public ISmartPointer<IWorkCycle>,
	public CStepNCItems, 
	public CXMLItems
{
public:
	enum CycleTypeEnum { Unknown =0, Roughing, Finishing, Chamfering } ;
	enum CANON_PLANE {NOPLANE=0, CANON_PLANE_XY=1, CANON_PLANE_YZ, CANON_PLANE_XZ} ;
	enum CANON_UNITS {NOUNITS=0, CANON_UNITS_INCHES=1, CANON_UNITS_MM, CANON_UNITS_CM} ;
	enum EnumErrors 
	{
		E_LENGTH_NOT_POSITIVE,
		E_WIDTH_NOT_POSITIVE,
		E_CORNER_RADIUS_NOT_POSITIVE,
		E_FINISHING_ALLOWANCE_NOT_POSITIVE,
		E_UNINIITALIZED_PARAMETER,
		E_TOOL_LARGER_THAN_HOLE,
		E_Z_STEP_LARGER_THAN_TOOL_DIAMETER
	};	

	IWorkCycle(IWorkCycles * owner) 
	{
		_parent=owner;
		_nPlane=IWorkCycle::NOPLANE;
		_nUnits=IWorkCycle::NOUNITS;

	};

	~IWorkCycle() {}
	virtual CString ToGCode(int nDialect, int eRoughFinish=0);
	virtual CString ToString() { return GetStepMap()->ToString(); }
	virtual CString ToXmlString() { return GetStepMap()->ToXmlString(); }
	virtual HRESULT Verify(std::vector<CString>& errors);
	virtual HRESULT DeriveParameters(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem);
	virtual HRESULT SanityCheck() ;
	virtual HRESULT LoadWSIntoStep(IStepNodePtr project) ;
	virtual HRESULT SetVariablePairs(LPCTSTR szVar,...);

	IMPLEMENT_PARAMETER(CString, Name, _sName);  // Name of feature-based operation
	IMPLEMENT_PARAMETER(CString, Comment, _sComment);  // comment, if any
	IMPLEMENT_PARAMETER(int, Toolnum, _toolnum);  // tool number for posting
	IMPLEMENT_PARAMETER(CString, ToolClassname, _szToolClassname);  // tool classname

	IMPLEMENT_PARAMETER(CANON_PLANE, Plane, _nPlane);  // xy=1, yz=2, xz=3
	IMPLEMENT_PARAMETER(CANON_UNITS, Units, _nUnits);  // xy=1, yz=2, xz=3

	FEATURECLASSDEF(IWorkCycle);
	CWorldModel & WorldModel() ;

	CCannedCycleItem* GetItem(CString name) {CCannedCycleItem* item = GetStepMap()->FindItem(name); if(item==NULL) throw std::exception(); return item;}
	template<typename T>
	T GetItemValue(tstring item) 
	{
		CCannedCycleItem *  test = GetStepMap()->FindItem(item.c_str());
		if(test==NULL)
			return Variant().get<T>();
		return test->GetValue().get<T>();
	}
	Matrix DirectionMatrix(Vector axis, Vector ref_dir)
	{
		Vector cross_dir = Cross(axis, ref_dir).Normalize();
		return Matrix  (ref_dir.x, ref_dir.y, ref_dir.z, 0,
			cross_dir.x, cross_dir.y, cross_dir.z, 0,
			axis.x, axis.y, axis.z, 0,
			0,0,0,1);
	}

	std::vector<CString> & Errors() { return errors; }
	IWorkCycles * _parent;
	std::vector<CString> errors;
	CStringVector errmsgs;

};

FEATURE_DECLARE_SMARTPOINTER(IWorkCycle);

class IWorkCycles : 
	public std::vector<IWorkCyclePtr>,  
	public ISmartPointer<IWorkCycles>
{
public:
	enum CANON_FEATURE { 
		FACEMILL=1, 
		POCKETRECTANGULAR, 
		POCKETCIRCULAR, 
		DRILLCENTERING,
		REAMING,
		CONTOURPOCKET,
		LOADTOOL,
		MULTISTEPDRILLING,
		SLOT
	};

	enum CANON_STOCK { BLOCK=1, CYLINDER=2 };

	// Methods
	IWorkCycles(CWorldModel & wm) : _wm(wm)  {}
	virtual ~IWorkCycles(void){}

	// Feature factory. Each cnc overrides to create specialized handlers
	virtual IWorkCyclePtr CreateFeature(CANON_FEATURE eType);
	virtual HRESULT UseToolingDatabase(CString szToolfile){ return S_OK; }
	virtual HRESULT StockDefinition(CANON_STOCK type, CString szMaterial, Vector origin, Vector extents);

	virtual CString GenerateNCProgram();
	CString GenerateNCErrors();
	virtual CString GenerateNCHeader(){ return _T("");}
	virtual void AddCommand(IWorkCyclePtr cmd) { push_back(cmd); }
	virtual CString PostBlock(CString line);
	virtual CString SpindleCommand(double spindlespeed){ return ""; }
	virtual CString PostToolDefinition(int toolnum, int tooledge=1){ return ""; }
	virtual CString PostToolChange(int toolnum){ return ""; }
	virtual int  LookupTool(int type, double length, double radius, double cornerradius) { return -1; }
	virtual int GetContourNumber() 	{ return _nContour++; }
	virtual HRESULT ParseStepNC(IStepNodePtr gProject, CStringVector &errors) { return E_NOTIMPL; }

	virtual CString GenerateIniString();
	virtual CString GenerateXmlString();
	virtual void ReadIniString(CString inistring);
	virtual void ReadXmlString(CString inistring);

	// Data
	static int _nContour;
	int _opnum;


	IMPLEMENT_PARAMETER(CANON_STOCK, StockType, _eStockType); //stock shape
	IMPLEMENT_PARAMETER(Vector, StockOrigin, _vStockOrigin); //origin of stock (needs to be corner position)
	IMPLEMENT_PARAMETER(Vector, StockExtents, _vStockExtents); //length, width, height
	IMPLEMENT_PARAMETER(double, Tolerance, dTolerance); //length, width, height
	IMPLEMENT_PARAMETER(CString, StockMaterial, szMaterialId); //stock material name 
	IMPLEMENT_PARAMETER(CString, StandardMaterialId, szStandardMaterialId); //stock material name 

	/////////////////////////////////////////////////////
	CWorldModel &_wm;
};


FEATURE_DECLARE_SMARTPOINTER(IWorkCycles);
inline	CWorldModel & IWorkCycle::WorldModel() { return _parent->_wm; }
