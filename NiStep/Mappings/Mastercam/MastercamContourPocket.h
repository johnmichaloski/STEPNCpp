//
// MastercamContourPocket.h
//


// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#pragma once
#include "FeatureCycles.h"

//using namespace Cycle;

/* TODO
	allow 2nd item of stepnc vector to be created/stored.


*/

class MastercamContourPocket : 
	public  MastercamTooling<IWorkCycle>
{
public:
	MastercamContourPocket(IWorkCycles * owner);
	virtual ~MastercamContourPocket(){}
	FEATURECLASSDEF(MastercamContourPocket);  // prevents copy constructors
#if 1
	BEGIN_STEP_PARAMETER_MAP(MastercamContourPocket)
		STEPNC_PARAMETER_ENTRY(_T("Location"),				Cycle::Feature,		Cycle::Vector,		_T("feature_placement/location/coordinates"))

		STEPNC_PARAMETER_ENTRY(_T("ReferencePlane"),		Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[2]"))
		STEPNC_PARAMETER_ENTRY(_T("RetractPlane"),			Cycle::Operation,	Cycle::Position,	_T("retract_plane"))
		STEPNC_PARAMETER_ENTRY(_T("SafetyPlane"),			Cycle::Operation,	Cycle::Length,		_T("its_secplane/position/location/coordinates[2]"))
		STEPNC_PARAMETER_ENTRY(_T("AbsDepth"),				Cycle::Feature,		Cycle::Position,	_T("depth/position/location/coordinates[2]"))
		STEPNC_PARAMETER_ENTRY(_T("MaxOneInfeedDepth"),		Cycle::Feature,		Cycle::Position,	_T("axial_cutting_depth"))
		STEPNC_PARAMETER_ENTRY(_T("StepFeedrate"),			Cycle::Operation,	Cycle::Feed,		_T("its_technology/feedrate"))
		STEPNC_PARAMETER_ENTRY(_T("StepSpeed"),			Cycle::Operation,	Cycle::Speed,		_T("its_technology/spindle"))
		STEPNC_PARAMETER_ENTRY(_T("Speed"),					Cycle::Compute,		Cycle::Speed,		_T("SpindleSpeed = SpindleDir * Speed;"))
		STEPNC_PARAMETER_ENTRY(_T("SpindleDir"),			Cycle::Compute,		Cycle::Speed,		_T("SpindleDir = if ccw then -1 else 1;"))
#if 0
		STEPNC_PARAMETER_ENTRY(_T("StartAbscissa"),			Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[0]"))
		STEPNC_PARAMETER_ENTRY(_T("StartOrdinate"),			Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[1]"))
		STEPNC_PARAMETER_ENTRY(_T("MaxOneInfeedDepth"),		Cycle::Operation,	Cycle::Length,		_T("axial_cutting_depth"))
		STEPNC_PARAMETER_ENTRY(_T("Stepdown"),				Cycle::Operation,	Cycle::Length,		_T("axial_cutting_depth"))
		STEPNC_PARAMETER_ENTRY(_T("Stepover"),				Cycle::Operation,	Cycle::Length,		_T("radial_cutting_depth"))

		STEPNC_PARAMETER_ENTRY(_T("Location"),				Cycle::Feature,		Cycle::Vector,		_T("feature_placement/location/coordinates"))
		STEPNC_PARAMETER_ENTRY(_T("Axis"),					Cycle::Feature,		Cycle::Vector,		_T("feature_placement/axis/direction_ratios"))
		STEPNC_PARAMETER_ENTRY(_T("ReferenceDirection"),	Cycle::Feature,		Cycle::Vector,		_T("feature_placement/ref_direction/direction_ratios"))

		STEPNC_PARAMETER_ENTRY(_T("FeatureName"),		Cycle::Feature,		Cycle::String,		_T("its_id"))
		STEPNC_PARAMETER_ENTRY(_T("CornerRadius"),			Cycle::Feature,		Cycle::Length,		_T("orthogonal_radius/theoretical_size"))
		STEPNC_PARAMETER_ENTRY(_T("CutterComp"),			Cycle::Operation,	Cycle::String,		_T("its_technology/feedrate_reference"))
		STEPNC_PARAMETER_ENTRY(_T("Feature"),				Cycle::Feature,		Cycle::Classname,	_T(""))
		STEPNC_PARAMETER_ENTRY(_T("FinishAllowanceDepth"),	Cycle::Operation,	Cycle::Length,		_T("allowance_bottom"))
		STEPNC_PARAMETER_ENTRY(_T("FinishAllowanceSide"),	Cycle::Operation,	Cycle::Length,		_T("allowance_side"))
		STEPNC_PARAMETER_ENTRY(_T("InfeedFeedrate"),		Cycle::Operation,	Cycle::Feed,		_T("its_technology/feedrate"))
		STEPNC_PARAMETER_ENTRY(_T("Operation"),				Cycle::Operation,	Cycle::Classname,	_T(""))
		STEPNC_PARAMETER_ENTRY(_T("MachiningStrategy"),		Cycle::Operation,	Cycle::Classname,	_T("its_machining_strategy"))
		STEPNC_PARAMETER_ENTRY(_T("MaxOneInfeedDepth"),		Cycle::Operation,	Cycle::Length,		_T("axial_cutting_depth"))
		STEPNC_PARAMETER_ENTRY(_T("PlacementRefDirection"), Cycle::Feature,		Cycle::Vector,		_T("feature_placement/ref_direction/direction_ratios"))
		STEPNC_PARAMETER_ENTRY(_T("StartAbscissa"),			Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[0]"))
		STEPNC_PARAMETER_ENTRY(_T("StartOrdinate"),			Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[1]"))
		STEPNC_PARAMETER_ENTRY(_T("StepFeedrate"),			Cycle::Operation,	Cycle::Feed,		_T("its_technology/feedrate"))

		STEPNC_PARAMETER_ENTRY(_T("Angle"),					Cycle::Compute,		Cycle::Angle,		_T("Angle = acos(Dot(Vector(1,0,0), PlacementRefDirection)) * 180.0 / M_PI;"))
		STEPNC_PARAMETER_ENTRY(_T("CycleType"),				Cycle::Compute,		Cycle::Long,		_T("CycleType = 1.0 + Find(Operation, \")finish\_T(")")) 
		STEPNC_PARAMETER_ENTRY(_T("FeedrateSurface"),		Cycle::Compute,		Cycle::Feed,		_T("FeedrateSurface = StepFeedrate * 1000.0 * 60.0 ;"))
		STEPNC_PARAMETER_ENTRY(_T("FeedrateInfeed"),		Cycle::Compute,		Cycle::Feed,		_T("FeedrateInfeed = StepFeedrate * 1000.0 * 60.0 ;"))
		STEPNC_PARAMETER_ENTRY(_T("MillingDirection"),		Cycle::Compute,		Cycle::Long,		_T("MillingDirection = 1.0;")) 
		STEPNC_PARAMETER_ENTRY(_T("RetractionTravel"),		Cycle::Compute,		Cycle::Length,		_T("RetractionTravel=0.0;")) 
		STEPNC_PARAMETER_ENTRY(_T("SafetyPlane"),			Cycle::Compute,		Cycle::Length,		_T("SafetyPlane	= 2.0;"))
		STEPNC_PARAMETER_ENTRY(_T("Speed"),					Cycle::Compute,		Cycle::Speed,		_T("Speed = fabs(SpindleSpeed);"))
		STEPNC_PARAMETER_ENTRY(_T("SpindleDir"),			Cycle::Compute,		Cycle::Long,		_T("SpindleDir=( 3.0 + (SpindleSpeed>=0));")) 

		STEPNC_PARAMETER_ENTRY(_T("CurveType"),				Cycle::Feature,		Cycle::Classname,	_T("feature_boundary/closed_profile_shape")) 

		STEPNC_PARAMETER_ENTRY(_T("RoughingTolerance"),		Cycle::Compute,		Cycle::Length,		_T("")) 
		STEPNC_PARAMETER_ENTRY(_T("FinishingTolerance"),	Cycle::Compute,		Cycle::Length,		_T("")) 

		STEPNC_PARAMETER_ENTRY(_T("PocketRoutine"),			Cycle::Compute,		Cycle::String,		_T(""))
#endif
	END_STEP_PARAMETER_MAP(MastercamContourPocket)
#endif
	BEGIN_XML_PARAMETER_MAP(MastercamContourPocket)
		STEPNC_XML_ENTRY(_T("ReferencePlane"),			Cycle::Operation,	Cycle::Length,		_T("OpCommon/FeedPlane"))
		STEPNC_XML_ENTRY(_T("ReferencePlaneIncrFlag"),	Cycle::Operation,	Cycle::Long,		_T("OpCommon/FeedPlaneIncremental"))

		STEPNC_XML_ENTRY(_T("SafetyPlane"),				Cycle::Operation,	Cycle::Length,		_T("OpCommon/ClearancePlane"))
		STEPNC_XML_ENTRY(_T("SafetyPlaneIncrFlag"),		Cycle::Operation,	Cycle::Long,		_T("OpCommon/ClearanceInc"))
		STEPNC_XML_ENTRY(_T("SafetyPlaneOnFlag"),		Cycle::Operation,	Cycle::Long,		_T("OpCommon/ClearanceOn"))

		STEPNC_XML_ENTRY(_T("RetractPlane"),			Cycle::Operation,	Cycle::Length,		_T("OpCommon/RetractPlane"))
		STEPNC_XML_ENTRY(_T("RetractPlaneIncrFlag"),	Cycle::Operation,	Cycle::Long,		_T("OpCommon/RetractIncremental"))
		STEPNC_XML_ENTRY(_T("RetractPlaneOnFlag"),		Cycle::Operation,	Cycle::Long,		_T("OpCommon/RetractOn"))
		STEPNC_XML_ENTRY(_T("RapidRetractFlag"),		Cycle::Operation,	Cycle::Long,		_T("OpCommon/RapidRretract"))

 		STEPNC_XML_ENTRY(_T("AbsDepth"),				Cycle::Operation,	Cycle::Length,		_T("OpCommon/DepthInZOfToolpath"))
		STEPNC_XML_ENTRY(_T("IncrDepthFlag"),			Cycle::Operation,	Cycle::Long,		_T("OpCommon/DepthInZOfToolpathIncremental"))

		STEPNC_XML_ENTRY(_T("DepthOfRoughingCuts"),		Cycle::Operation,	Cycle::Length,		_T("OpMultiCuts/DepthOfRoughingCuts")) /* a*/
		STEPNC_XML_ENTRY(_T("MaxOneInfeedDepth"),		Cycle::Operation,	Cycle::Length,		_T("OpMultiCuts/DepthOfRoughingCuts")) /* b */

	//	STEPNC_XML_ENTRY(_T("DepthOfFinishingCuts"),	Cycle::Operation,	Cycle::Length,		_T("OpMultiCuts/DepthOfFinishCuts"))
		STEPNC_XML_ENTRY(_T("DepthOfFinishingCuts"),	Cycle::Operation,	Cycle::Length,		_T("OpDepthCuts/ZDepthOfFinishCuts"))

		STEPNC_XML_ENTRY(_T("FeedrateSurface"),			Cycle::Operation,	Cycle::Feed,		_T("ToolInfo/Feedrate"))
		STEPNC_XML_ENTRY(_T("FeedrateInfeed"),			Cycle::Operation,	Cycle::Feed,		_T("ToolInfo/Plungerate"))
		STEPNC_XML_ENTRY(_T("RetractRate"),				Cycle::Operation,	Cycle::Feed,		_T("ToolInfo/Retractrate"))
		STEPNC_XML_ENTRY(_T("Speed"),					Cycle::Compute,		Cycle::Speed,		_T("StepSpeed"))

		STEPNC_XML_ENTRY(_T("FinishAllowanceDepth"),	Cycle::Operation,	Cycle::Length,		_T("allowance_bottom"))
		STEPNC_XML_ENTRY(_T("FinishAllowanceSide"),		Cycle::Operation,	Cycle::Length,		_T("allowance_side"))

		STEPNC_XML_ENTRY(_T("Stepover"),				Cycle::Operation,	Cycle::Length,		_T("Pocketing/RoughingStepSize"))
		STEPNC_XML_ENTRY(_T("StepoverPercentage"),		Cycle::Operation,	Cycle::Double,		_T("Pocketing/RoughingStepPercent"))
		STEPNC_XML_ENTRY(_T("MachiningType"),			Cycle::Operation,	Cycle::Long,		_T("Pocketing/ClimbMill"))
#if 0
		STEPNC_XML_ENTRY(_T("CutterComp"),				Cycle::Operation,	Cycle::String,		_T("its_technology/feedrate_reference"))

#endif
#if 0
		// geometry
		STEPNC_XML_ENTRY(_T("CornerRadius"),			Cycle::Feature,		Cycle::Length,		_T("orthogonal_radius/theoretical_size"))
		STEPNC_XML_ENTRY(_T("StartAbscissa"),			Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[0]"))
		STEPNC_XML_ENTRY(_T("StartOrdinate"),			Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[1]"))
		STEPNC_XML_ENTRY(_T("Location"),				Cycle::Feature,		Cycle::Vector,		_T("feature_placement/location/coordinates"))
		STEPNC_XML_ENTRY(_T("Axis"),					Cycle::Feature,		Cycle::Vector,		_T("feature_placement/axis/direction_ratios"))
		STEPNC_XML_ENTRY(_T("ReferenceDirection"),	Cycle::Feature,		Cycle::Vector,		_T("feature_placement/ref_direction/direction_ratios"))

		STEPNC_XML_ENTRY(_T("FeatureName"),		Cycle::Feature,		Cycle::String,		_T("its_id"))
		STEPNC_XML_ENTRY(_T("Feature"),				Cycle::Feature,		Cycle::Classname,	_T(""))

		STEPNC_XML_ENTRY(_T("Operation"),				Cycle::Operation,	Cycle::Classname,	_T(""))
		STEPNC_XML_ENTRY(_T("MachiningStrategy"),		Cycle::Operation,	Cycle::Classname,	_T("its_machining_strategy"))
		STEPNC_XML_ENTRY(_T("MaxOneInfeedDepth"),		Cycle::Operation,	Cycle::Length,		_T("axial_cutting_depth"))
		STEPNC_XML_ENTRY(_T("PlacementRefDirection"), Cycle::Feature,		Cycle::Vector,		_T("feature_placement/ref_direction/direction_ratios"))
		STEPNC_XML_ENTRY(_T("StepSpeed"),			Cycle::Operation,	Cycle::Speed,		_T("its_technology/spindle"))
		STEPNC_XML_ENTRY(_T("StepFeedrate"),			Cycle::Operation,	Cycle::Feed,		_T("its_technology/feedrate"))

		STEPNC_XML_ENTRY(_T("Angle"),					Cycle::Compute,		Cycle::Angle,		_T("Angle = acos(Dot(Vector(1,0,0), PlacementRefDirection)) * 180.0 / M_PI;"))
		STEPNC_XML_ENTRY(_T("CycleType"),				Cycle::Compute,		Cycle::Long,		_T("CycleType = 1.0 + Find(Operation, \")finish\_T(")")) 
		STEPNC_XML_ENTRY(_T("FeedrateSurface"),		Cycle::Compute,		Cycle::Feed,		_T("FeedrateSurface = StepFeedrate * 1000.0 * 60.0 ;"))
		STEPNC_XML_ENTRY(_T("FeedrateInfeed"),		Cycle::Compute,		Cycle::Feed,		_T("FeedrateInfeed = StepFeedrate * 1000.0 * 60.0 ;"))
		STEPNC_XML_ENTRY(_T("MillingDirection"),		Cycle::Compute,		Cycle::Long,		_T("MillingDirection = 1.0;")) 
		STEPNC_XML_ENTRY(_T("RetractionTravel"),		Cycle::Compute,		Cycle::Length,		_T("RetractionTravel=0.0;")) 
		STEPNC_XML_ENTRY(_T("Speed"),					Cycle::Compute,		Cycle::Speed,		_T("Speed = fabs(SpindleSpeed);"))
		STEPNC_XML_ENTRY(_T("SpindleDir"),			Cycle::Compute,		Cycle::Long,		_T("SpindleDir=( 3.0 + (SpindleSpeed>=0));")) 

		STEPNC_XML_ENTRY(_T("CurveType"),				Cycle::Feature,		Cycle::Classname,	_T("feature_boundary/closed_profile_shape")) 
#endif

		STEPNC_XML_ENTRY(_T("RoughingTolerance"),		Cycle::Compute,		Cycle::Length,		_T("")) 
		STEPNC_XML_ENTRY(_T("FinishingTolerance"),	Cycle::Compute,		Cycle::Length,		_T("")) 

		STEPNC_XML_ENTRY(_T("PocketRoutine"),			Cycle::Compute,		Cycle::String,		_T(""))
	END_XML_PARAMETER_MAP(MastercamContourPocket)

	BEGIN_OUTPUT_PARAMETER_MAP(MastercamContourPocket)
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("G0  F2000 "), _T(""), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("X%.3f "), _T("StartAbscissa"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("Y%.3f "), _T("StartOrdinate"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("Z%.3f\n"), _T("RetractPlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("F%.3f"), _T("FeedrateInfeed"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("M0%d"), _T("SpindleDir"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("S%.3f\n"), _T("Speed"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Rough"),  _T("CYCLE832(%.3f,1003)\n"), _T("RoughingTolerance"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Finish"), _T("CYCLE832(%.3f,102001)\n"), _T("FinishingTolerance"), _T(""))

		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%s"), _T("PocketRoutine"), _T(""))

		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("CYCLE73("), _T(""), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%d, "), _T("MachiningType"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("\"%s\", "), _T("DrillProgram"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("\"%s\", "), _T("PocketMillProgram"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("\"%d\", "), _T("ToolNumber"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("RetractPlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("ReferencePlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("SafetyPlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("AbsDepth"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T(" , "), _T(""), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("MaxOneInfeedDepth"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("Stepover"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("FinishAllowanceSide"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("FinishAllowanceDepth"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("FeedrateSurface"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("FeedrateInfeed"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("0, "), _T("MillingDirection"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("0, "), _T(""), _T(""))  //Start point in first axis (only with manual selection of start point)
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("0, "), _T(""), _T(""))  //Start point in second axis (only with manual selection of start point)
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("0, "), _T(""), _T(""))  // Radius of center point path for insertion along helical path or max. insertion angle for oscillating insertion
//		STEPNC_OUTPUT_ENTRY(_T("Both"), _T(" , "), _T(""), _T(""))  // _DP1 real Insertion depth per 360° revolution on insertion along helical path
//		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%d "), _T("ToolOffsetNumber"), _T("")) //Tool offset number of stock removal tool (D number)
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T(")\n"), _T(""), _T(""))
	END_OUTPUT_PARAMETER_MAP(MastercamContourPocket)

	BEGIN_VERIFY_PARAMETER_MAP(MastercamContourPocket)
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("CutterComp != \"TCP\""), _T(""))
		STEPNC_VERIFY_ENTRY(_T("Warning"), _T("Both"), _T("RetractPlane == 0.0") ,_T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("RetractPlane <= ReferencePlane") , _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("ReferencePlane <= AbsDepth") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Toolradius >= CornerRadius") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Toolradius  > Width") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("FeedrateSurface <= 0.0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("FeedrateInfeed <= 0.0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Speed <= 0.0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("CornerRadius <= 0.0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Toollength < (ReferencePlane - AbsDepth)") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Toollength < ((ReferencePlane - AbsDepth) - 10)") ,  _T(""))
	END_VERIFY_PARAMETER_MAP(MastercamContourPocket)

private:
	std::vector<Vector> vContourPoints;
	int _nMyContourNumber;

};
FEATURE_DECLARE_SMARTPOINTER(MastercamContourPocket);


//////////////////////////////////////////////////////////////////////////////////////////
MastercamContourPocket::MastercamContourPocket(IWorkCycles * owner):   MastercamTooling(owner)
{
	//SetName(_T("MastercamContourPocket"));
	_parent=owner;
	InitMastercamItems(this);
//	InitOutputs(this);
	InitTests(this);

}

#if 0
HRESULT MastercamContourPocket::DeriveParameters(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem) 
{
	IWorkCycle::DeriveParameters(pExecutable, pFeature, pOpItem);
	CCannedCycleItems * items = GetStepMap();  // initialize output for now...	

	items->SetVariable(_T("Angle"),  (double) acos(Dot(Vector(1,0,0),  items->GetValue<Vector>(_T("PlacementRefDirection")))) * 180.0 / M_PI);
	
	items->SetVariable(_T("FeedrateSurface"), items->GetValue<double>(_T("StepFeedrate")) * 1000.0 * 60.0) ;
	items->SetVariable(_T("FeedrateInfeed"), items->GetValue<double>(_T("StepFeedrate")) * 1000.0 * 60.0) ;

	items->SetVariable(_T("RetractPlane"), items->GetValue<double>(_T("ReferencePlane"))+ 10.0) ;
	items->SetVariable(_T("SafetyPlane"), 2.0) ;
	items->SetVariable(_T("Speed"), fabs(items->GetValue<double>(_T("StepSpeed")))) ;
	items->SetVariable(_T("SpindleDir"), 3.0 + (items->GetValue<double>(_T("StepSpeed"))>=0)) ;

	items->SetVariable(_T("Toolradius"), items->GetValue<double>(_T("Tooldiameter")) / 2.0) ;

	items->SetVariable(_T("ToolTypeNumber"), Seimens840D::GetToolNumber(items->GetValue<tstring>(_T("Tooltype")).c_str())) ;
	items->SetVariable(_T("ToolOffsetNumber"), 1) ;  //  Tool D Number


	_toolnum = _parent->LookupTool(items->GetValue<long>(_T("ToolTypeNumber")),
		items->GetValue<double>(_T("Toollength")),
		items->GetValue<double>(_T("Toolradius")),
		0);
	items->SetVariable(_T("ToolNumber"),(long) _toolnum) ;

	items->SetVariable(_T("RoughingTolerance"), (double) 0.01) ;
	items->SetVariable(_T("FinishingTolerance"), (double) 0.001) ;

	items->SetVariable(_T("SolidMachiningTool"), _T("2")) ;  // FIXME: Tool number string - this is fixed and is wrong.
	

	_nMyContourNumber=_parent->GetContourNumber();
	items->SetVariable(_T("PocketMillProgram"), (LPCTSTR)  StrFormat(_T("PocketMill%d"), _nMyContourNumber));
	items->SetVariable(_T("PocketRoutine"), (LPCTSTR) StrFormat(_T("REPEAT CONTOUR%d ENDLABEL%d\n"), _nMyContourNumber, _nMyContourNumber));

	/* Mill direction for machining the pocket: (enter without sign)
	Values: 
	0: Down-cut milling (corresponds to direction of spindle rotation)
	1: Down-cut milling
	2: with G2 (independent of spindle direction)
	3: with G3
	*/
	items->SetVariable(_T("MillingDirection"), (long) 2) ;

	/*
	Machining type: (enter without sign)
	_VARI integer
	Values:
	UNITS DIGIT: Machining process
		1: Roughing (solid machining) from solid material
		2: Roughing of residual material
		3: Finishing of edge
		4: Finishing of base
		5: Predrilling
	TENS DIGIT: Insertion strategy
		1: Perpendicular to G1
		2: On helical path
		3: Oscillation
	HUNDREDS DIGIT: Lift-off mode
		0: on retraction plane (_RTP)
		1: by amount of safety clearance (_SDIS) over reference plane(_RFP)
	THOUSANDS DIGIT: Start point
		1: automatic
		2: manual
	*/
	
	CString Operation =(LPCTSTR) items->GetValue<tstring>(_T("Operation")).c_str();
	items->SetVariable(_T("CycleType"),  1.0 + (Operation.Find(_T("finish"))>=0)) ;
	items->SetVariable(_T("MachiningType"), 1001) ;


	// general_closed_profile implies  closed_pocket
	Eclosed_pocketPtr pPocket = (Eclosed_pocket *) pFeature.get();
	Egeneral_closed_profilePtr pProfile =(Egeneral_closed_profile *) pPocket->feature_boundary.get();
	tstring szCurveType = items->GetValue<tstring>(_T("CurveType"));

	if(szCurveType == _T("polyline"))
	{
		EpolylinePtr pCurve = (Epolyline *) pProfile->closed_profile_shape.get();

		// There will be points, as this is not a pointer, may be empty though
		EListT<Ecartesian_pointPtr> points = pCurve->points;
		// Change vector of pointer to doubles to actual math vector
		for(int i=0; i< points.size(); i++) 
		{ 
			vContourPoints.push_back (  ToVector(points[i]->coordinates)); 
			OUTPUT_DEBUG_STRING(vContourPoints.back().ToString());

		}
		if(vContourPoints[0]!= vContourPoints[vContourPoints.size()-1] )  // should  be since its a closed profile! 
		{


		}
	}

	debugstream << GetStepMap()->ToString();
	return S_OK;

}

#endif