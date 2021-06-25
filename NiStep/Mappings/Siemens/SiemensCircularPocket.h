//
// SiemensCircularPocket.h
//


// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#pragma once
#include "FeatureCycles.h"



/*
	Untested
*/



class SiemensCircularPocket : public   IWorkCycle
{
public:
	SiemensCircularPocket(IWorkCycles * owner);
	virtual ~SiemensCircularPocket(){}
	FEATURECLASSDEF(SiemensCircularPocket);  // prevents copy constructors

	virtual HRESULT DeriveParameters(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem) ;

	BEGIN_STEP_MAP(SiemensCircularPocket)

		ENTRYSET(_T("Type"),			Cycle::Compute,		Cycle::String,		_T(""), _T("CircularPocket"))
		ENTRY(_T("PocketRadius"),		_T("Feature"),		_T("Length"),	_T("FIXME!!!!!!!!!!!"))
		ENTRY(_T("CenterAbscissa"),		_T("Feature"),		_T("Position"),	_T("feature_placement/location/coordinates[0]"))
		ENTRY(_T("CenterOrdinate"),		_T("Feature"),		_T("Position"),	_T("feature_placement/location/coordinates[1]"))
		ENTRY(_T("MaxOneInfeedDepth"),	_T("Operation"),	_T("Length"),	_T("axial_cutting_depth"))
		ENTRY(_T("Stepover"),			_T("Operation"),	_T("Length"),	_T("radial_cutting_depth"))
		ENTRY(_T("MachiningType"),		_T("Compute"),		_T("Long"),		_T(""))


		ENTRY(_T("FeatureName"),		_T("Feature"),		_T("String"),	_T("its_id"))
		ENTRY(_T("PocketDepth"),		_T("Feature"),		_T("Length"),	_T("depth/position/location/coordinates[2]"))
		ENTRY(_T("CycleType"),			_T("Compute"),		_T("Long"),		_T(""))
		ENTRY(_T("CutterComp"),			_T("Operation"),	_T("String"),	_T("its_technology/feedrate_reference"))
		ENTRY(_T("Feature"),			_T("Feature"),		_T("Classname"), _T(""))
		ENTRY(_T("FinishAllowanceDepth"),_T("Operation"),	_T("Length"),	_T("allowance_bottom"))
		ENTRY(_T("FinishAllowanceSide"),_T("Operation"),	_T("Length"),	_T("allowance_side"))
		ENTRY(_T("Operation"),			_T("Operation"),	_T("Classname"), _T(""))
		ENTRY(_T("MachiningStrategy"),	_T("Operation"),	_T("Classname"), _T("its_machining_strategy"))
		ENTRY(_T("MaxOneInfeedDepth"),	_T("Operation"),	_T("Length"),	_T("axial_cutting_depth"))
		ENTRY(_T("ReferencePlane"),		_T("Feature"),		_T("Position"),	_T("feature_placement/location/coordinates[2]"))
		ENTRY(_T("RetractPlane"),		_T("Operation"),	_T("Position"),	_T("retract_plane"))
		ENTRY(_T("StepSpeed"),		_T("Operation"),	_T("Speed"),	_T("its_technology/spindle"))
		ENTRY(_T("StepFeedrate"),		_T("Operation"),	_T("Feed"),		_T("its_technology/feedrate"))

		ENTRY(_T("Angle"),				_T("Compute"),		_T("Angle"),	_T("Angle = acos(Dot(Vector(1,0,0), PlacementRefDirection)) * 180.0 / M_PI;"))
		ENTRY(_T("CycleType"),			_T("Compute"),		_T("Long"),		_T("CycleType = 1.0 + Find(Operation, \"finish\")")) 
		ENTRY(_T("FeedrateSurface"),	_T("Compute"),		_T("Feed"),		_T("Feedrate = StepFeedrate * 1000.0 * 60.0 ;"))
		ENTRY(_T("FeedrateInfeed"),		_T("Compute"),		_T("Feed"),		_T("FeedrateInfeed = StepFeedrate * 1000.0 * 60.0 ;"))
		ENTRY(_T("MillingDirection"),	_T("Compute"),		_T("Long"),		_T("MillingDirection = 1.0;")) 
		ENTRY(_T("RetractionTravel"),	_T("Compute"),		_T("Length"),	_T("RetractionTravel=0.0;")) 
		ENTRY(_T("SafetyPlane"),		_T("Compute"),		_T("Position"),	_T("SafetyPlane	= 2.0;"))
		ENTRY(_T("Speed"),				_T("Compute"),		_T("Speed"),	_T("Speed = fabs(SpindleSpeed);"))
		ENTRY(_T("SpindleDir"),			_T("Compute"),		_T("Long"),		_T("SpindleDir=( 3.0 + (SpindleSpeed>=0));")) 

		ENTRY(_T("RoughingTolerance"),	_T("Compute"),		_T("Double"),	_T("")) 
		ENTRY(_T("FinishingTolerance"),	_T("Compute"),		_T("Double"),	_T("")) 


		ENTRY(_T("ToolNumber"),			_T("Compute"),		_T("Long"),			_T(""))
		ENTRY(_T("ToolTypeNumber"),		_T("Compute"),		_T("Long"),		_T(""))
		ENTRY(_T("Toolname"),			_T("Operation"),	_T("Classname"), _T("its_tool/its_tool_body"))
		ENTRY(_T("Toolradius"),			_T("Compute"),		_T("Length"),	_T("Toolradius = Tooldiameter / 2.0;"))
		ENTRY(_T("Tooldiameter"),		_T("Operation"),	_T("Length"),	_T("its_tool/its_tool_body/dimension/diameter"))
		ENTRY(_T("Toollength"),			_T("Operation"),	_T("Length"),	_T("its_tool/its_tool_body/dimension/cutting_edge_length"))

	//	ENTRY(_T("Toollength"), _T("Operation"), _T("Double"), _T("its_tool/its_cutting_edge[1]/tool_offset_length"))
	//	ENTRY(_T("Toollength"), _T("Operation"), _T("Double"), _T("its_tool/overall_assembly_length"))
	END_STEP_MAP(SiemensCircularPocket)

	BEGIN_OUTPUT_PARAMETER_MAP(SiemensCircularPocket)
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("G0  F2000 "), _T(""), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("X%.3f "), _T("CenterAbscissa"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("Y%.3f "), _T("CenterOrdinate"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("Z%.3f\n"), _T("RetractPlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("F%.3f"), _T("Feedrate"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("M0%d"), _T("SpindleDir"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("S%.3f\n"), _T("Speed"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Rough"),  _T("CYCLE832(%.3f,1003)\n"), _T("RoughingTolerance"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Finish"), _T("CYCLE832(%.3f,102001)\n"), _T("FinishingTolerance"), _T(""))

		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("POCKET4("), _T(""), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("RetractPlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("ReferencePlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("SafetyPlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("PocketDepth"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("PocketRadius"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("CenterAbscissa"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("CenterOrdinate"), _T(""))
		//Maximum infeed depth or maximum pitch with _VARI = helical (enter without sign)
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("InfeedFeedrate"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("FinishAllowanceSide"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("FinishAllowanceDepth"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("FeedrateSurface"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("FeedrateInfeed"), _T(""))
		//Values: 0: Down-cut milling (corresponds to direction of spindle rotation)
		//1: Down-cut milling
		//2: with G2 (independent of spindle direction)
		//3: with G3
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%d, "), _T("MillingDirection"), _T(""))

		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%d, "), _T("MachiningType"), _T(""))
		// The other parameters can be selected as options. They define the insertion strategy and overlapping for solid machining:
		//STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("MaxOneInfeedDepth"), _T(""))
		//_AP1 real Blank pocket radius dimension in reference plane (incremental)
		//_AD real Blank pocket depth dimension from reference plane (incremental)
		//_RAD1 real Radius of the helical path during insertion (referred to the tool center point path)
		//_DP1 real Insertion depth per 360° revolution on insertion along helical path


		STEPNC_OUTPUT_ENTRY(_T("Both"), _T(")\n"), _T(""), _T(""))
	END_OUTPUT_PARAMETER_MAP(SiemensCircularPocket)

	BEGIN_VERIFY_PARAMETER_MAP(SiemensCircularPocket)
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("RetractPlane <= ReferencePlane") , _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("ReferencePlane <= PocketDepth") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Toolradius  > Width") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Feedrate <= 0.0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Speed <= 0.0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Toollength <= 0.0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Toolradius <= 0.0") , _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("PocketRadius <= 0.0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Toollength < (ReferencePlane - AbsDepth)") ,  _T(""))
	END_VERIFY_PARAMETER_MAP(SiemensRectangularPocket)

};
FEATURE_DECLARE_SMARTPOINTER(SiemensCircularPocket);


//////////////////////////////////////////////////////////////////////////////////////////
SiemensCircularPocket::SiemensCircularPocket(IWorkCycles * owner):  IWorkCycle(owner)
{
	_parent=owner;
	InitStepItems(&items);
	InitOutputs(this);
	InitTests(this);
}

HRESULT SiemensCircularPocket::DeriveParameters(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem) 
{
	IWorkCycle::DeriveParameters(pExecutable, pFeature, pOpItem);
	CCannedCycleItems * items = GetStepMap();  // initialize output for now...	

	double d = Dot(Vector(1,0,0),  items->GetValue<Vector>(_T("PlacementRefDirection"))); 
	items->SetVariable(_T("Angle"), (double) acos( d ) * 180.0 / M_PI);
	
	items->SetVariable(_T("FeedrateSurface"), items->GetValue<double>(_T("StepFeedrate")) * 1000.0 * 60.0) ;
	items->SetVariable(_T("FeedrateInfeed"), items->GetValue<double>(_T("StepFeedrate")) * 1000.0 * 60.0) ;
	items->SetVariable(_T("RetractPlane"), items->GetValue<double>(_T("ReferencePlane"))+ 10.0) ;
	items->SetVariable(_T("SafetyPlane"), 2.0) ;
	items->SetVariable(_T("Speed"), fabs(items->GetValue<double>(_T("StepSpeed")))) ;
	items->SetVariable(_T("SpindleDir"), 3.0 + (items->GetValue<double>(_T("StepSpeed"))>=0)) ;
	items->SetVariable(_T("Toolradius"), items->GetValue<double>(_T("Tooldiameter")) / 2.0) ;
	items->SetVariable(_T("RoughingTolerance"), (double) 0.01) ;
	items->SetVariable(_T("FinishingTolerance"), (double) 0.001) ;

	CString Operation =(LPCTSTR) items->GetValue<tstring>(_T("Operation")).c_str();
	items->SetVariable(_T("CycleType"),  1.0 + (Operation.Find(_T("finish"))>=0)) ;

	_toolnum = _parent->LookupTool(items->GetValue<long>(_T("ToolTypeNumber")),
		items->GetValue<double>(_T("Toollength")),
		items->GetValue<double>(_T("Toolradius")),
		0);


	/* Mill direction for machining the pocket: (enter without sign)
	Values: 
	0: Down-cut milling (corresponds to direction of spindle rotation)
	1: Down-cut milling
	2: with G2 (independent of spindle direction)
	3: with G3
	*/
	items->SetVariable(_T("MillingDirection"), (long) 2) ;

	/* MachiningType FIXME:???????????
	UNITS DIGIT: Machining process
		1: Roughing
		2: Finishing
	TENS DIGIT: Infeed
		0: Perpendicular to pocket center with G0
		1: Perpendicular to pocket center with G1
		2: On helical path:
	THOUSANDS DIGIT: Milling technology
		0: Plane-wise
		1: Helical
	*/

	long nMachiningType =  		(long) (1.0 + (Operation.Find(_T("finish"))>=0));
	items->SetVariable(_T("MachiningType"), nMachiningType);

	debugstream << GetStepMap()->ToString();
	return S_OK;

}

