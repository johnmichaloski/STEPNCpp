//
// SiemensFacing.h
//


// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

/*
Issues:
	bidirectional not tested
	only 1st quadrant tested (0,0) -> (100, 120)
	not tested 2nd, 3rd,4th quadrant tested (0,0) -> (-100, 120), etc.
	how to handle final overcut
	how to handle per raster overcut

STEP NC "Errors"
	14649 has example1 with finish facing and depth at 10mm, axial depth of cut 2.5 mm - can't do in one pass?

*/
#pragma once
#include "FeatureCycles.h"
#include "Siemens/Seimens840D.h"

class SiemensFaceMill : public   IWorkCycle
{
public:
	SiemensFaceMill::SiemensFaceMill(IWorkCycles * owner) :   IWorkCycle(owner)
	{
		_parent=owner;
		InitStepItems(&items);
		InitOutputs(this);
		InitTests(this);

	}

	virtual HRESULT DeriveParameters(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem);

	BEGIN_STEP_MAP(SiemensFaceMill)
		ENTRYSET(_T("Type"),				Cycle::Compute,		Cycle::String,		_T(""), _T("Facing"))
		ENTRY(_T("FeatureName"),			Cycle::Feature,		Cycle::String,		_T("its_id"))
		ENTRY(_T("Feature"),				Cycle::Feature,		Cycle::Classname,	_T(""))
		ENTRY(_T("Operation"),				Cycle::Operation,	Cycle::Classname,	_T(""))


		ENTRY(_T("AbsDepth"),				Cycle::Feature,		Cycle::Position,	_T("depth/position/location/coordinates[2]"))
		ENTRY(_T("CutterComp"),				Cycle::Operation,	Cycle::String,		_T("its_technology/feedrate_reference"))
		ENTRY(_T("FinishAllowanceDepth"),	Cycle::Operation,	Cycle::Length,		_T("allowance_bottom"))
		ENTRY(_T("FinishAllowanceSide"),	Cycle::Operation,	Cycle::Length,		_T("allowance_side"))
		ENTRY(_T("InfeedFeedrate"),			Cycle::Operation,	Cycle::Feed,		_T("its_technology/feedrate"))
		ENTRY(_T("Length"),					Cycle::Feature,		Cycle::Length,		_T("removal_boundary/profile_length/its_parameter_value"))
		ENTRY(_T("Location"),				Cycle::Operation,	Cycle::Vector,		_T("feature_placement/location/coordinates"))
		ENTRY(_T("MachiningStrategy"),		Cycle::Operation,	Cycle::Classname,	_T("its_machining_strategy"))
		ENTRY(_T("MaxOneInfeedDepth"),		Cycle::Operation,	Cycle::Length,		_T("axial_cutting_depth"))
		ENTRY(_T("Overlap"),				Cycle::Operation,	Cycle::Length,		_T("its_machining_strategy/overlap"))
		ENTRY(_T("Overrun"),				Cycle::Operation,	Cycle::Length,		_T("overcut_length"))
		ENTRY(_T("PlacementRefDirection"),	Cycle::Feature,		Cycle::Vector,		_T("feature_placement/ref_direction/direction_ratios"))
		ENTRY(_T("ReferencePlane"),			Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[2]"))
		ENTRY(_T("RetractPlane"),			Cycle::Operation,	Cycle::Position,	_T("retract_plane"))
		ENTRY(_T("StepSpeed"),			Cycle::Operation,	Cycle::Speed,		_T("its_technology/spindle"))
		ENTRY(_T("StartAbscissa"),			Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[0]"))
		ENTRY(_T("StartOrdinate"),			Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[1]"))
		ENTRY(_T("StepFeedrate"),			Cycle::Operation,	Cycle::Feed,		_T("its_technology/feedrate"))
		ENTRY(_T("WidthDirection"),			Cycle::Feature,		Cycle::Double,		_T("course_of_travel/its_direction/direction_ratios[1]"))
		ENTRY(_T("WidthMagnitude"),			Cycle::Feature,		Cycle::Long,		_T("course_of_travel/distance/theoretical_size"))
		ENTRY(_T("XCourseOfTravelDirection"), Cycle::Feature,	Cycle::Double,		_T("course_of_travel/its_direction/direction_ratios[0]"))
		ENTRY(_T("XFeedDirection"),			Cycle::Operation,	Cycle::Double,		_T("its_machining_strategy/feed_direction/direction_ratios[0]"))
		ENTRY(_T("YFeedDirection"),			Cycle::Operation,	Cycle::Double,		_T("its_machining_strategy/feed_direction/direction_ratios[1]"))

		ENTRY(_T("Angle"),					Cycle::Compute,		Cycle::Angle,		_T("Angle = acos(Dot(Vector(1,0,0), PlacementRefDirection)) * 180.0 / M_PI;"))
		ENTRY(_T("CycleType"),				Cycle::Compute,		Cycle::Long,		_T("CycleType = 1.0 + Find(Operation, \"finish\")")) 
		ENTRY(_T("Feedrate"),				Cycle::Compute,		Cycle::Feed,		_T("Feedrate = StepFeedrate * 1000.0 * 60.0 ;"))
		ENTRY(_T("InfeedFeedrate"),			Cycle::Compute,		Cycle::Feed,		_T("InfeedFeedrate = StepFeedrate * 1000.0 * 60.0 ;"))
		ENTRY(_T("MillingDirection"),		Cycle::Compute,		Cycle::Long,		_T("MillingDirection = 1.0;")) 
		ENTRY(_T("RetractionTravel"),		Cycle::Compute,		Cycle::Length,		_T("RetractionTravel=0.0;")) 
		ENTRY(_T("SafetyPlane"),			Cycle::Compute,		Cycle::Position,	_T("SafetyPlane	= 2.0;"))
		ENTRY(_T("Speed"),					Cycle::Compute,		Cycle::Speed,		_T("Speed = fabs(SpindleSpeed);"))
		ENTRY(_T("SpindleDir"),				Cycle::Compute,		Cycle::Long,		_T("SpindleDir=( 3.0 + (SpindleSpeed>=0));")) 
		ENTRY(_T("Stepover"),				Cycle::Compute,		Cycle::Length,		_T("Stepover =  Tooldiameter - (Overlap * Tooldiameter);"))
		ENTRY(_T("Toolradius"),				Cycle::Compute,		Cycle::Length,		_T("Toolradius = Tooldiameter / 2.0;"))
		ENTRY(_T("Width"),					Cycle::Compute,		Cycle::Length,		_T("Width = (WidthDirection == 1.0) * WidthMagnitude;")) 
		ENTRY(_T("MachiningType"),			Cycle::Compute,		Cycle::Long,		_T(""));
		LINK(StepNCTooling)
		LINK(SiemensTool)

		//ENTRY(_T("Toollength"), Cycle::Operation, _T("Double"), _T("its_tool/its_tool_body/dimension/cutting_edge_length"))
	//	ENTRY(_T("Toollength"), Cycle::Operation, _T("Double"), _T("its_tool/overall_assembly_length"))

	END_STEP_MAP(SiemensFaceMill)
	BEGIN_OUTPUT_PARAMETER_MAP(SiemensFaceMill)
		
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("G0  F2000 "), _T(""), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("X%.3f "), _T("StartAbscissa"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("Y%.3f "), _T("StartOrdinate"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("Z%.3f\n"), _T("RetractPlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("F%.3f"), _T("Feedrate"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("M0%d"), _T("SpindleDir"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("S%.3f\n"), _T("Speed"), _T(""))
		
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("CYCLE71("), _T(""), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("RetractPlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("ReferencePlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("SafetyPlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("AbsDepth"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("StartAbscissa"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("StartOrdinate"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("Length"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("Width"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("Angle"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("MaxOneInfeedDepth"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("Stepover"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("RetractionTravel"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("FinishAllowanceDepth"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("Feedrate"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%d, "), _T("MachiningType"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T(")\n"), _T(""), _T(""))
	END_OUTPUT_PARAMETER_MAP(SiemensFaceMill)

	BEGIN_VERIFY_PARAMETER_MAP(SiemensFaceMill)
	END_VERIFY_PARAMETER_MAP(SiemensFaceMill)

	//	BEGIN_STEP_PARAMETER_MAP(SiemensTooling)
	//	ENTRY(_T("Toolname"), Cycle::Operation, _T("Double"), _T("its_tool/its_tool_body"))
	//	ENTRY(_T("Tooldiameter"), Cycle::Operation, _T("Double"), _T("its_tool/its_tool_body/dimension/diameter"))
	//	ENTRY(_T("Toollength"), Cycle::Operation, _T("Double"), _T("its_tool/its_cutting_edge[1]/tool_offset_length"))
	////	ENTRY(_T("Toollength"), Cycle::Operation, _T("Double"), _T("its_tool/its_cutting_edge[1]/tool_offset_length"))
	//	ENTRY(_T("Toollength"), Cycle::Operation, _T("Double"), _T("its_tool/overall_assembly_length"))
	//	END_STEP_PARAMETER_MAP(SiemensTooling)


};



HRESULT SiemensFaceMill::DeriveParameters(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem)
{

	IWorkCycle::DeriveParameters(pExecutable, pFeature, pOpItem);
	CCannedCycleItems * items = GetStepMap();  // initialize output for now...	

	items->SetVariable(_T("Angle"),  (double) acos(Dot(Vector(1,0,0),  items->GetValue<Vector>(_T("PlacementRefDirection")))) * 180.0 / M_PI);

	CString Operation =(LPCTSTR) items->GetValue<tstring>(_T("Operation")).c_str();
	items->SetVariable(_T("CycleType"),  1.0 + (Operation.Find(_T("finish"))>=0)) ;
	
	items->SetVariable(_T("Feedrate"), items->GetValue<double>(_T("StepFeedrate")) * 1000.0 * 60.0) ;
	items->SetVariable(_T("InfeedFeedrate"), items->GetValue<double>(_T("StepFeedrate")) * 1000.0 * 60.0) ;
	items->SetVariable(_T("MillingDirection"), (long) 1) ;
	items->SetVariable(_T("RetractionTravel"), 0.0) ;
	items->SetVariable(_T("SafetyPlane"), 2.0) ;
	items->SetVariable(_T("Speed"), fabs(items->GetValue<double>(_T("StepSpeed")))) ;
	items->SetVariable(_T("SpindleDir"), 3.0 + (items->GetValue<double>(_T("StepSpeed"))>=0)) ;
	items->SetVariable(_T("Stepover"), items->GetValue<double>(_T("Tooldiameter")) - 
		( items->GetValue<double>(_T("Overlap")) * items->GetValue<double>(_T("Tooldiameter")))) ;
	items->SetVariable(_T("Width"), (items->GetValue<double>(_T("WidthDirection")) > 0) ? items->GetValue<double>(_T("WidthMagnitude")) :
		-items->GetValue<double>(_T("WidthMagnitude")));

	items->SetVariable(_T("Stepover"), (double) items->GetValue<double>(_T("Tooldiameter")) -  (items->GetValue<double>(_T("Overlap")) * items->GetValue<double>(_T("Tooldiameter"))/100.0) );

	long nMachiningType =  		(long) (1.0 + (Operation.Find(_T("finish"))>=0) +
		 (10.0*items->GetValue<double>(_T("XFeedDirection")) * (items->GetValue<tstring>(_T("MachiningStrategy")) == _T("unidirectional")))
		+ (20.0*items->GetValue<double>(_T("YFeedDirection")) * (items->GetValue<tstring>(_T("MachiningStrategy")) == _T("unidirectional")))
		+ (30.0*items->GetValue<double>(_T("XFeedDirection")) * (items->GetValue<tstring>(_T("MachiningStrategy")) == _T("bidirectional")))
		+ (40.0*items->GetValue<double>(_T("YFeedDirection")) * (items->GetValue<tstring>(_T("MachiningStrategy")) == _T("bidirectional"))))
		;

	items->SetVariable(_T("MachiningType"), nMachiningType);

	// if tooling is wrong revise items list before calling this.
	SiemensTool tool;
	_toolnum= tool.DeriveToolParameters(_parent, items, pFeature,  pOpItem);

	debugstream << GetStepMap()->ToString();
	return S_OK;
}




