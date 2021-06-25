//
// FeatureCycles.h
//
#pragma once
#include "atlstr.h"
#include "Misc.h"
#include <boost/intrusive_ptr.hpp>
#include "linalg3d.h"
#include "stepnc_schemaClassDefinitions.h"

//#include "machining_schemaClassDefinitions.h"
//#include "milling_schemaClassDefinitions.h"
using namespace Express;

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
extern CWorldModel  gWm;


class IFeature 
{
public:
	//private:
	int _refs; //! reference count
	friend inline void intrusive_ptr_release(IFeature* pThis)
	{
		if(--pThis->_refs == 0 ) { 
			delete pThis;
		}
	}
	friend inline void intrusive_ptr_add_ref(IFeature* pThis)
	{
		pThis->_refs++;
	}
	friend inline void intrusive_ptr_release(const IFeature* pThis)
	{
		if(--const_cast<IFeature*>(pThis)->_refs == 0 ) { 
			delete const_cast<IFeature*>(pThis);
		}
	}
	friend inline void intrusive_ptr_add_ref(const IFeature* pThis)
	{
		const_cast<IFeature*>(pThis)->_refs++;

	}
};

class IFeatureCycle  : public IFeature
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
	IFeatureCycle(CWorldModel & wm);
	virtual ~IFeatureCycle() {}

	virtual CString ToGCode(int nDialect, int eRoughFinish=0) { return ""; }
	virtual HRESULT Verify(){return S_OK; }
	virtual HRESULT DeriveParameters(IStepNodePtr pFeature, Emachining_operationPtr pOpItem);

	IMPLEMENT_PARAMETER(CString, Name, _sName);  // Name of feature-based operation
	IMPLEMENT_PARAMETER(CString, Comment, _sComment);  // comment, if any
	IMPLEMENT_PARAMETER(long, ToolNum, _nToolNum);  // tool number for posting
	IMPLEMENT_PARAMETER(CString, ToolClassname, _szToolClassname);  // tool classname
	IMPLEMENT_PARAMETER(CString, MachineopClass, _szMachineopClass);  // Machine op classname
	IMPLEMENT_PARAMETER(CString, FeatureClassname, _szFeatureClassname);  // Feature classname
	
	

	IMPLEMENT_PARAMETER(CANON_PLANE, Plane, _nPlane);  // xy=1, yz=2, xz=3
	IMPLEMENT_PARAMETER(CANON_UNITS, Units, _nUnits);  // xy=1, yz=2, xz=3
	IMPLEMENT_PARAMETER(double, ToolRadius, _dToolRadius);
	IMPLEMENT_PARAMETER(double, Feedrate, _dFeedrate);  // Feedrate for machining
	IMPLEMENT_PARAMETER(double, InfeedFeedrate, _dInfeedFeedrate);  // Infeed Feedrate for machining
	IMPLEMENT_PARAMETER(double, SpindleSpeed, _dSpindleSpeed);  // Feedrate for machining

	IMPLEMENT_PARAMETER(double, ApproachPlane, _dApproachPlane);
	IMPLEMENT_PARAMETER(double, RetractPlane, _dRetractPlane);
	IMPLEMENT_PARAMETER(double, SafetyPlane, _dSafetyPlane);
	IMPLEMENT_PARAMETER(double, ReferencePlane, _dReferencePlane); //z0
	IMPLEMENT_PARAMETER(CycleTypeEnum, CycleType, _eCycleType);

	FEATURECLASSDEF(IFeatureCycle);

	CWorldModel & _wm;


};
FEATURE_DECLARE_SMARTPOINTER(IFeatureCycle);

class CFeatureCycles : public std::vector<IFeatureCyclePtr>,  public IFeature
{
public:
	enum CANON_FEATURE { 
		FACEMILL=1, 
		POCKETRECTANGULAR, 
		DRILLCENTERING,
		REAMING};

		enum CANON_STOCK { BLOCK=1, CYLINDER=2 };

	CFeatureCycles(CWorldModel & wm) : _wm(wm) { }
	virtual ~CFeatureCycles(void){}

	///////////////////////////////////////////////////////

	// Feature factory. Each cnc overrides to create specialized handlers
	virtual IFeatureCyclePtr CreateFeature(CANON_FEATURE eType);
	virtual HRESULT UseToolingDatabase(CString szToolfile){ return S_OK; }
	virtual HRESULT StockDefinition(CANON_STOCK type, CString szMaterial, Vector origin, Vector extents);

	virtual void AddCommand(IFeatureCyclePtr cmd) { push_back(cmd); }
	virtual CString GenerateNCProgram();

	IMPLEMENT_PARAMETER(CANON_STOCK, StockType, _eStockType); //stock shape
	IMPLEMENT_PARAMETER(CString, StockMaterial, _szStockMaterial); //stock material name 
	IMPLEMENT_PARAMETER(Vector, StockOrigin, _vStockOrigin); //origin of stock (needs to be corner position)
	IMPLEMENT_PARAMETER(Vector, StockExtents, _vStockExtents); //length, width, height

	/////////////////////////////////////////////////////
	CWorldModel &_wm;
};
FEATURE_DECLARE_SMARTPOINTER(CFeatureCycles);

class FaceMill : public  IFeatureCycle
{
public:
	FaceMill(CWorldModel & wm);
	virtual ~FaceMill() {}
	FEATURECLASSDEF(FaceMill);  // prevents copy constructors

	virtual CString ToGCode(int nDialect, int eRoughFinish=0) { return ""; }
	virtual CString TestCode() { return ""; }
	virtual HRESULT Verify(){return S_OK; }

};
FEATURE_DECLARE_SMARTPOINTER(FaceMill);

class PocketRectangular : public  IFeatureCycle
{
public:
	PocketRectangular(CWorldModel & wm);
	virtual ~PocketRectangular(){}
	FEATURECLASSDEF(PocketRectangular);  // prevents copy constructors

	virtual CString ToGCode(int nDialect, int eRoughFinish=0){ return ""; }
	virtual CString TestCode(){ return ""; }
	virtual HRESULT Verify(std::vector<EnumErrors>&){ return S_OK; }
};
FEATURE_DECLARE_SMARTPOINTER(PocketRectangular);

class DrillCentering : public  IFeatureCycle
{
public:
	DrillCentering(CWorldModel & wm);
	virtual ~DrillCentering(){}
	FEATURECLASSDEF(DrillCentering);  // prevents copy constructors

	virtual CString ToGCode(int nDialect, int eRoughFinish=0){ return "CYCLE81 (RTP, RFP, SDIS, DP, DPR)"; }
	virtual CString TestCode(){ return ""; }
	virtual HRESULT Verify(std::vector<EnumErrors>&) { return S_OK; }
	// Would have crucial common parameters  - but unclear the representation - just derive from STEP

};

FEATURE_DECLARE_SMARTPOINTER(DrillCentering);

class DrillCounterbore : public  IFeatureCycle
{
public:
	DrillCounterbore(CWorldModel & wm): IFeatureCycle(wm){ _sName="DrillCounterbore"; }

	virtual ~DrillCounterbore(){}
	FEATURECLASSDEF(DrillCounterbore);  // prevents copy constructors
	IMPLEMENT_PARAMETER(double, Dwell, _dDwell);  // Dwell time at final drilling depth

	virtual CString ToGCode(int nDialect, int eRoughFinish=0){ return ""; }
	virtual CString TestCode(){ return ""; }
	virtual HRESULT Verify(std::vector<EnumErrors>&) { return S_OK; }
	// Would have crucial common parameters  - but unclear the representation - just derive from STEP


};

FEATURE_DECLARE_SMARTPOINTER(DrillCounterbore);

class Reaming : public  IFeatureCycle
{
public:
	Reaming(CWorldModel & wm);

	virtual ~Reaming(){}
	FEATURECLASSDEF(Reaming);  // prevents copy constructors

	virtual CString ToGCode(int nDialect, int eRoughFinish=0){ return "CYCLE85 (RTP, RFP, SDIS, DP, DPR, DTB, FFR, RFF)"; }
	virtual CString TestCode(){ return ""; }
	virtual HRESULT Verify(std::vector<EnumErrors>&) { return S_OK; }
	// Would have crucial common parameters  - but unclear the representation - just derive from STEP

};

FEATURE_DECLARE_SMARTPOINTER(Reaming);