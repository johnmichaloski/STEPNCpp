//
// Seimens840D.h
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.


#pragma once
#include "FeatureCycles.h"
#include "boost/tuple/tuple.hpp"

class Seimens840D;
class SiemensFaceMill;

class Seimens840D : public CFeatureCycles
{
public:
	Seimens840D(CWorldModel &wm);
	virtual ~Seimens840D(void);
	
	// Feature defining helpers
	virtual void NewWorkingStep(){}
	virtual IFeatureCyclePtr CreateFeature(CANON_FEATURE eType);

	// Program helpers
	virtual CString GenerateNCProgram();
	virtual CString NewBlock(CString line);
	virtual CString SpindleCommand(double spindlespeed);
	virtual CString ToolChange(int toolnum);

	// Siemens tools for now
	enum ToolEnums { Ballhead=100, Endmill=120, EndmillCornerRadius=120, AngleHeadCutter=130,AngleHeadCutterCornerRadius=131,
		FacingTool=140, Sidemill=150, 
		TwistDrill=200, SolidDrill=205, BoringBar=210, CenterDrill=220, Countersink=230, Counterbore=231, 
		TapRegular=240, TapFind=241, TapWhitworth=242, Reamer=250};

	int  DefineTool(ToolEnums type, double length, double radius, double cornerradius);
	typedef boost::tuple<ToolEnums, double, double, double> ToolingTuple; 
	std::vector<ToolingTuple> _toollist;
};
FEATURE_DECLARE_SMARTPOINTER(Seimens840D);

////////////////////////////////////////////////////////////////////////
class SiemensFaceMill : public  FaceMill
{
public:
	SiemensFaceMill::SiemensFaceMill(Seimens840D * owner, CWorldModel & wm) : _parent(owner), FaceMill(wm){}

	virtual CString ToGCode(int nDialect, int eRoughFinish=0);
	virtual CString TestCode();
	virtual HRESULT Verify(){return S_OK; }
	virtual HRESULT DeriveParameters(IStepNodePtr pFeature, Emachining_operationPtr pOpItem);
	Seimens840D * _parent;
	///////////////////
		IMPLEMENT_PARAMETER(double, Depth, _dDepth);  // depth of total cut
	IMPLEMENT_PARAMETER(double, StartAbscissa, _dStartAbscissa);  // x0
	IMPLEMENT_PARAMETER(double, StartOrdinate, _dStartOrdinate);   // y0

	/* Length of the rectangle in the 1st axis, incrementally.
	The corner from which dimensioning is carried out results from the sign.*/
	IMPLEMENT_PARAMETER(double, Length, _dLength);  

	/*Length of the rectangle in the 2nd axis, incrementally.
	The corner from which dimensioning is carried out results from the sign.*/
	IMPLEMENT_PARAMETER(double, Width, _dWidth);  

	/*Angle between the longitudinal axis of the rectangle and the first axis of
	the plane (abscissa, enter without sign);*/
	IMPLEMENT_PARAMETER(double, Angle, _dAngle);   // range 0<=angle<180

	IMPLEMENT_PARAMETER(double, MaxInfeedDepth, _dMaxInfeedDepth);   //  no sign
	IMPLEMENT_PARAMETER(double, MaxInfeedWidth, _dMaxInfeedWidth);   // Maximum infeed width value for machining in the plane (enter without sign)
	// If this parameter is not programmed or has value 0, the cycle will internally use 80% of the milling tool diameter as the maximum infeed width.
	//Retraction travel in cutting direction (incremental, enter without sign)
	IMPLEMENT_PARAMETER(double, RetractionTravel, _dRetractionTravel);   // Maximum infeed width value for machining in the plane (enter without sign)
	IMPLEMENT_PARAMETER(double, FinishAllowance, _dFinishAllowance);  // Finishing machining allowance in plane
	IMPLEMENT_PARAMETER(double, FinishAllowanceDepth, _dFinishAllowanceDepth);  // Finishing machining allowance in depth

	/*Milling direction
	1: parallel to the abscissa, in one direction
	2: parallel to the ordinate, in one direction
	3: parallel to the abscissa, with alternating direction
	4: parallel to the ordinate, with alternating direction
	*/
	IMPLEMENT_PARAMETER(int, MillingDirection, _nMillingDirection);  
	void SetMillingDirection(Vector v); 
	// Retraction travel in cutting direction (incremental, enter without sign)

	IMPLEMENT_PARAMETER(double, Overrun, _dOverrun);   // Overrun travel in direction of plane infeed (incremental, enter without sign)
};

FEATURE_DECLARE_SMARTPOINTER(SiemensFaceMill);

////////////////////////////////////////////////////////////////////////
template<class T>
class SiemensBasicDrilling
{
public:
	virtual ~SiemensBasicDrilling(){}
	IMPLEMENT_PARAMETER(double, AbsFinalDepth, _dAbsFinalDepth);  // Final drilling depth (absolute)
	IMPLEMENT_PARAMETER(double, RelFinalDepth, _dRelFinalDepth);  // Final drilling depth (relative)
	IMPLEMENT_PARAMETER(double, CenterAbscissa, _dStartAbscissa);  // x centerpoint (absolute)
	IMPLEMENT_PARAMETER(double, CenterOrdinate, _dStartOrdinate);   // y centerpoint (absolute)
	IMPLEMENT_PARAMETER(double, HoleRadius, _dHoleRadius);   // drilling hole radius for comparison to tool diameter
	SiemensBasicDrilling()
	{
		SetAbsFinalDepth(NaN);  // Final drilling depth (absolute)
		SetRelFinalDepth(NaN);  // Final drilling depth (relative)
		SetCenterAbscissa(NaN);  // x centerpoint (absolute)
		SetCenterOrdinate(NaN);   // y centerpoint (absolute)
	}
	HRESULT DeriveBasicParameters(IStepNodePtr pFeature, Emachining_operationPtr pOpItem)
	{
		Vector vDepth ;				// 3D description of depth plane...
		Vector location;			// hole location(not cutter starting location)
		double dDiameter;
		double dRetract;			// retract in z plane from reference point (z0)
		T * pThis= (T *) this;

		pThis->IFeatureCycle::DeriveParameters( pFeature,  pOpItem);
		double dRetractionFeedrate=0.0;
		Eround_holePtr pHole= (Eround_hole*) pFeature.get();
		//Etoleranced_length_measurePtr diameter; 
		//Etaper_selectPtr change_in_diameter; 
		//Ehole_bottom_conditionPtr bottom_condition; 

		// Quick check to see that minimum data we need is available.
		if(!pHole || !pHole->diameter || !pHole->diameter->theoretical_size 
			|| !pHole->feature_placement 
			|| !pHole->feature_placement->location 
			|| (pHole->feature_placement->location->coordinates.size() < 3) 
			|| !pHole->depth
			|| !pHole->depth->position
			|| !pHole->depth->position->location)
		{
			OutputDebugString("Error: Insufficient information to drill hole\n");
			DebugBreak();
			return E_FAIL;
		}
		// Drilling Operation
		//Elength_measurePtr cutting_depth; 
		//Elength_measurePtr previous_diameter; 
		//Etime_measurePtr dwell_time_bottom; 
		//Epositive_ratio_measurePtr feed_on_retract; 
		//Edrilling_type_strategyPtr its_machining_strategy; 
		//Edrilling_type_strategy :
		//	Epositive_ratio_measurePtr reduced_cut_at_start; 
		//	Epositive_ratio_measurePtr reduced_feed_at_start; 
		//	Elength_measurePtr depth_of_start; 
		//	Epositive_ratio_measurePtr reduced_cut_at_end; 
		//	Epositive_ratio_measurePtr reduced_feed_at_end; 
		//	Elength_measurePtr depth_of_end; 

		dDiameter  = pHole->diameter->theoretical_size->val;
		location = ToVector(pHole->feature_placement->location->coordinates); // starting position also?
		vDepth = ToVector(pHole->depth->position->location->coordinates);

		dRetract =  (pOpItem->retract_plane!=NULL) ? pOpItem->retract_plane->val: location.z+10;

		pThis->SetRetractPlane(dRetract);
		pThis->SetReferencePlane(location.z);
		pThis->SetSafetyPlane(2); // _SDIS Safety clearance 2 mm 
		pThis->SetAbsFinalDepth(vDepth.z);
		pThis->SetCenterAbscissa(location.x);
		pThis->SetCenterOrdinate(location.y);   // y0

		pThis->SetHoleRadius(dDiameter/2.0);

		return S_OK;

	}

};
////////////////////////////////////////////////////////////////////////
class SiemensDrillCentering : public  DrillCentering, public SiemensBasicDrilling<SiemensDrillCentering>
{
public:
	SiemensDrillCentering(Seimens840D * owner, CWorldModel & wm) ;
	virtual ~SiemensDrillCentering(){}
	virtual CString ToGCode(int nDialect, int eRoughFinish=0);
	virtual HRESULT Verify(std::vector<EnumErrors>&);
	virtual HRESULT DeriveParameters(IStepNodePtr pFeature, Emachining_operationPtr pOpItem);

private:
	Seimens840D * _parent;

};
FEATURE_DECLARE_SMARTPOINTER(SiemensDrillCentering);


////////////////////////////////////////////////////////////////////////
class SiemensReaming : public  Reaming, public SiemensBasicDrilling<SiemensReaming>
{
public:
	SiemensReaming(Seimens840D * owner, CWorldModel & wm);

	virtual ~SiemensReaming(){}
	FEATURECLASSDEF(SiemensReaming);  // prevents copy constructors

	virtual CString ToGCode(int nDialect, int eRoughFinish=0);//{ return "CYCLE85 (RTP, RFP, SDIS, DP, DPR, DTB, FFR, RFF)"; }
	virtual HRESULT Verify(std::vector<EnumErrors>&) ;
	virtual HRESULT DeriveParameters(IStepNodePtr pFeature, Emachining_operationPtr pOpItem);

	IMPLEMENT_PARAMETER(double, Dwell, _dDwell);  // Dwell time at final drilling depth
	IMPLEMENT_PARAMETER(double, Feedrate, _dFeedrate);  // Feedrate
	IMPLEMENT_PARAMETER(double, RetractionFeedrate, _dRetractionFeedrate);  //Retraction feedrate

private:
	Seimens840D * _parent;

};
FEATURE_DECLARE_SMARTPOINTER(SiemensDrillCentering);



class SiemensBasicPocketing
{
public:

	static IFeatureCyclePtr DerivePocketingCycle(CFeatureCyclesPtr program, IStepNodePtr pFeature, Emachining_operationPtr pOpItem);

};
////////////////////////////////////////////////////////////////////////
class SiemensPocketBasicRectangular : public  PocketRectangular
{
public:
	public:
	SiemensPocketBasicRectangular(Seimens840D * owner, CWorldModel & wm);
	virtual ~SiemensPocketBasicRectangular(){}
	FEATURECLASSDEF(SiemensPocketBasicRectangular);  // prevents copy constructors

	virtual CString ToGCode(int nDialect, int eRoughFinish=0);
	virtual HRESULT Verify(std::vector<EnumErrors>&);


	////////////////////////////////////////////////////////
	// Parameters
	IMPLEMENT_PARAMETER(double, AbsDepth, _dAbsDepth);  // absolute signed depth of pocket
	IMPLEMENT_PARAMETER(double, RelDepth, _dRelDepth);  // relative depth of pocket
	IMPLEMENT_PARAMETER(double, CenterAbscissa, _dStartAbscissa);  // x centerpoint (absolute)
	IMPLEMENT_PARAMETER(double, CenterOrdinate, _dStartOrdinate);   // y centerpoint (absolute)
	IMPLEMENT_PARAMETER(double, Length, _dLength);   //Pocket length (enter without sign)
	IMPLEMENT_PARAMETER(double, Width, _dWidth);   // Pocket width (enter without sign)
	IMPLEMENT_PARAMETER(double, CornerRadius, _dCornerRadius);  // Corner radius (enter without sign)

	/*Rotational Angle between the longitudinal axis of the rectangle and the first axis of
	the plane (abscissa, enter without sign);*/
	IMPLEMENT_PARAMETER(double, Angle, _dAngle);   // range 0<=angle<180
	IMPLEMENT_PARAMETER(double, MaxOneInfeedDepth, _dMaxOneInfeedDepth);   // Depth or Z Step Maximum infeed depth for one infeed (enter without sign)

	enum EMillingDirection{ G2=2, G3=3 }; 
	IMPLEMENT_PARAMETER(EMillingDirection, MillingDirection, _nMillingDirection);  
	IMPLEMENT_PARAMETER(double, FinishAllowanceSide, _dFinishAllowanceSide);  // Finishing allowance at the pocket edge
	IMPLEMENT_PARAMETER(double, FinishAllowanceBottom, _dFinishAllowanceBottom);  // Finishing allowance at the pocket bottom
	IMPLEMENT_PARAMETER(double, FinishFeed, _dFinishFeed);    // Feedrate for finishing
	IMPLEMENT_PARAMETER(double, FinishSpeed, _dFinishSpeed);    // Speed for finishing
private:
	Seimens840D * _parent;
};
FEATURE_DECLARE_SMARTPOINTER(SiemensPocketBasicRectangular);

class SiemensPocketRectangular : public  PocketRectangular
{
	SiemensPocketRectangular(Seimens840D * owner, CWorldModel & wm);
	virtual ~SiemensPocketRectangular(){}
	FEATURECLASSDEF(SiemensPocketRectangular);  // prevents copy constructors

	virtual CString ToGCode(int nDialect, int eRoughFinish=0);
	virtual CString TestCode();
	virtual HRESULT Verify(std::vector<EnumErrors>&);


	////////////////////////////////////////////////////////
	// Parameters
	IMPLEMENT_PARAMETER(double, AbsDepth, _DP);  // absolute signed depth of pocket
	//IMPLEMENT_PARAMETER(double, RelDepth, );  // relative depth of pocket
	IMPLEMENT_PARAMETER(double, CenterAbscissa, _PA);  // x centerpoint (absolute)
	IMPLEMENT_PARAMETER(double, CenterOrdinate, _PO);   // y centerpoint (absolute)
	IMPLEMENT_PARAMETER(double, Length, _LENG);   //Pocket length (enter without sign)
	IMPLEMENT_PARAMETER(double, Width, _WID);   // Pocket width (enter without sign)
	IMPLEMENT_PARAMETER(double, CornerRadius, _CRAD);  // Corner radius (enter without sign)

	/*Rotational Angle between the longitudinal axis of the rectangle and the first axis of
	the plane (abscissa, enter without sign);*/
	IMPLEMENT_PARAMETER(double, Angle, _STA);   // range 0<=angle<180
	IMPLEMENT_PARAMETER(double, MaxOneInfeedDepth, _dMaxOneInfeedDepth);   // Maximum infeed depth for one infeed (enter without sign)

	enum EMillingDirection{ G2=2, G3=3 }; 
	IMPLEMENT_PARAMETER(EMillingDirection, MillingDirection, _CDIR);  
	IMPLEMENT_PARAMETER(double, FinishAllowance, _FAL);  // Finishing allowance at the pocket edge
	IMPLEMENT_PARAMETER(double, FinishAllowanceBase, _FALD);  // Finishing allowance at base depth
	
	IMPLEMENT_PARAMETER(double, MaxInfeedDepth, _dMaxInfeedDepth);   // Maximum infeed depth for finishing
	IMPLEMENT_PARAMETER(double, FinishFeed, _dFinishFeed);    // Feedrate for finishing
	IMPLEMENT_PARAMETER(double, FinishSpeed, _dFinishSpeed);    // Speed for finishing
private:
	Seimens840D * _parent;
/*
The other parameters can be selected as options. They define the insertion strategy and overlapping
for solid machining:
_MIDA real Maximum infeed width as a value in solid machining in the plane
_AP1 real Blank dimension of pocket length
_AP2 real Blank dimension of pocket width
_AD real Blank pocket depth dimension from reference plane
_RAD1 real Radius of the helical path on insertion (relative to the tool center point
path) or maximum insertion angle for reciprocating motion
_DP1 real Insertion depth per 360° revolution on insertion along helical path
*/
};
FEATURE_DECLARE_SMARTPOINTER(SiemensPocketRectangular);