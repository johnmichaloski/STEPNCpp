//
// SiemensMultistepDrilling.h
//

// Status: UNIMPLEMENTED/UNTESTED

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#pragma once
#include "FeatureCycles.h"
#include "Siemens/Seimens840D.h"

/*

drilling_type_operation.cutting_depth: 
The depth of the cut of this operation, which may differ from the depth of the hole as
such. The NC controller will not check if cutting_depth violates the boundaries of
the associated hole feature. If omitted, the total depth of the feature will be drilled.
In case of center drilling operation, the cutting_depth is measured from the lowest
point of the cutting tip to the highest point of the hole. In other cases, it is measured
from the starting point of cylindrical part of the tool.(Or, tapered cylindrical part in
case of tapered drill.)

drilling_type_operation.previous_diameter: 
If the operation is performed on a pre-drilled or pre-cast hole, this value, if given,
specifies the diameter of the existing hole. It thus describes the amount of material
which the tool as to remove and is for information only.

drilling_type_operation.dwell_time_bottom: 
Possible dwell time at the bottom of the hole.

feed_on_retract: 
Feed used for retract to the retract_plane as ratio of the drilling feed. If not specified,
the drilling feed is used.

drilling_type_operation.its_machining_strategy: 
Description of the strategy to be used when executing the operation. In case the
attribute its_toolpath of the supertype operation is specified, the strategy is for
information only.
----

drilling_type_strategy.reduced_cut_at_start. Reduced cutting speed at the beginning of the cut as a percentage of the programmed
value.

drilling_type_strategy.reduced_feed_at_start: Reduced feed at the beginning of the cut as a percentage of the programmed value.

drilling_type_strategy.depth_of_start: Depth to which the reduced values at the start are valid.

drilling_type_strategy.reduced_cut_at_end. Reduced cutting speed at the end of the cut as a percentage of the programmed
value.

drilling_type_strategy.reduced_feed_at_end: Reduced feed at the end of the cut as a percentage of the programmed value.
depth_of_end: Depth from which the reduced values at the end are valid.

----

multistep_drilling.retract_distance: If retract_distance is a positive value, the tool is retracted this value between steps to
enable chip breaking. If it is zero or negative, the tool is retracted to the retract plane
between steps to clear the hole of chips.

multistep_drilling.first_depth: Depth of the first step.

multistep_drilling.depth_of_step: Depth of each additional step (repeated until the depth of the hole is reached).

multistep_drilling.dwell_time_step: Dwell time between steps.

*/
class SiemensMultistepDrilling : public   IWorkCycle
{
public:
	SiemensMultistepDrilling(IWorkCycles * owner) ;
	virtual ~SiemensMultistepDrilling(){}
	virtual HRESULT DeriveParameters(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem);

	BEGIN_STEP_MAP(SiemensMultistepDrilling)
		ENTRYSET(_T("Type"),			Cycle::Compute,		Cycle::String,		_T(""), _T("MultistepDrilling"))
		ENTRY(_T("FeatureName"),		Cycle::Feature,		Cycle::String,		_T("its_id"))
		ENTRY(_T("Feature"),			Cycle::Feature,		Cycle::Classname,	_T(""))
		ENTRY(_T("Operation"),			Cycle::Operation,	Cycle::Classname,	_T(""))
		ENTRY(_T("CenterX"),			Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[0]"))
		ENTRY(_T("CenterY"),			Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[1]"))

		ENTRY(_T("FirstDrillingDepth"),Cycle::Operation,	Cycle::Position,	_T("first_depth"))
		ENTRY(_T("FinalDrillingDepth"),Cycle::Operation,	Cycle::Position,	_T("cutting_depth"))
		ENTRY(_T("MinimumDrillingDepth"),Cycle::Operation,	Cycle::Position,	_T("depth_of_step"))
		ENTRY(_T("DwellTimeChipBreakage"),Cycle::Operation,Cycle::Double,		_T("dwell_time_step"))
		ENTRY(_T("DwellTimeChipRemoval"),Cycle::Operation,	Cycle::Double,		_T("dwell_time_step"))
		ENTRY(_T("FeedrateFactorFirstDrill"),Cycle::Operation,	Cycle::Double,	_T("reduced_feed_at_start"))

		ENTRY(_T("RetractDistance"),	Cycle::Operation,	Cycle::Double,		_T("retract_distance"))
		

		ENTRY(_T("Diameter"),			Cycle::Operation,	Cycle::Double,			_T("diameter/theoretical_size"))


		ENTRY(_T("MachiningType"),				Cycle::Compute,	Cycle::Long,		_T(""))
		ENTRY(_T("ProgrammableLimitDistance"),	Cycle::Compute,	Cycle::Length,		_T(""))
		ENTRY(_T("VariableRetractionValue"),	Cycle::Compute,	Cycle::Length,		_T(""))
		ENTRY(_T("ToolAxis"),				Cycle::Compute,	Cycle::Long,		_T(""))


		// dwell type issues...
		ENTRY(_T("DoDwell"),			Cycle::Operation,	Cycle::Boolean,		_T("spindle_stop_at_bottom"))  
		ENTRY(_T("Dwell"),				Cycle::Operation,	Cycle::Double,		_T("dwell_time_bottom"))  

		ENTRY(_T("ReferencePlane"),	Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[2]"))
		ENTRY(_T("RetractPlane"),		Cycle::Operation,	Cycle::Position,	_T("retract_plane"))
		ENTRY(_T("SafetyPlane"),		Cycle::Compute,		Cycle::Position,	_T("SafetyPlane	= 2.0;"))

		ENTRY(_T("CycleType"),			Cycle::Compute,		Cycle::Long,		_T("CycleType = 1.0 + Find(Operation, \"finish\")")) 

		ENTRY(_T("StepFeedrate"),		Cycle::Operation,	Cycle::Feed,		_T("its_technology/feedrate"))
		ENTRY(_T("Feedrate"),			Cycle::Compute,		Cycle::Feed,		_T("Feedrate = StepFeedrate * 1000.0 * 60.0 ;"))
		ENTRY(_T("RetractionFeedrate"),Cycle::Compute,		Cycle::Feed,		_T("Feedrate = StepFeedrate * 1000.0  * 60.0 ;"))
		
		ENTRY(_T("StepSpeed"),		Cycle::Operation,	Cycle::Speed,		_T("its_technology/spindle"))
		ENTRY(_T("Speed"),				Cycle::Compute,		Cycle::Speed,		_T("Speed = fabs(SpindleSpeed);"))
		ENTRY(_T("SpindleDir"),		Cycle::Compute,		Cycle::Long,		_T("SpindleDir=( 3.0 + (SpindleSpeed>=0));")) 
		LINK(SiemensTool)

		//	ENTRY(_T("Toollength"),	_T("Operation"), _T("Double"), _T("its_tool/its_tool_body/dimension/cutting_edge_length"))
	//	ENTRY(_T("Toollength"), _T("Operation"), _T("Double"), _T("its_tool/its_cutting_edge[1]/tool_offset_length"))
	//	ENTRY(_T("Toollength"), _T("Operation"), _T("Double"), _T("its_tool/overall_assembly_length"))
	END_STEP_MAP(SiemensMultistepDrilling)

	BEGIN_OUTPUT_PARAMETER_MAP(SiemensMultistepDrilling)
		// Approach
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("G0  F2000 "), _T(""), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("X%.3f "), _T("CenterX"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("Y%.3f "), _T("CenterY"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("Z%.3f\n"), _T("RetractPlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("F%.3f"), _T("Feedrate"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("M0%d"), _T("SpindleDir"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("S%.3f\n"), _T("Speed"), _T(""))

		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("CYCLE83("), _T(""), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("RetractPlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("ReferencePlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("SafetyPlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("FinalDrillingDepth"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T(" , "), _T(""), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("FirstDrillingDepth"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T(" , "), _T(""), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T(" 0, "), _T(""), _T(""))  // FIXME: degression
		// Dwell time:  Values: > 0: in seconds < 0: in revolutions
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("DwellTimeChipBreakage"), _T("")) 
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("DwellTimeChipRemoval"), _T("")) 
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("FeedrateFactorFirstDrill"), _T(""))   // 0.001 to 1
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%d, "), _T("MachiningType"), _T(""))   //  0: chip breakage 1: chip removal
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%d, "), _T("ToolAxis"), _T(""))   //  1: 1st geometrical axis 2: 2ndgeometrical axis otherwise 3rd
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("MinimumDrillingDepth"), _T(""))  
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("VariableRetractionValue"), _T("")) //  chip breakage  > 0, if  0: 1 mm set
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("Dwell"), _T(""))  // Dwell time at final drilling depth
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f "), _T("ProgrammableLimitDistance"), _T(""))  //  for reimmersion in the drill hole (for chip removal if =0, automatic calculation
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T(")\n "), _T(""), _T(""))
	END_OUTPUT_PARAMETER_MAP(SiemensMultistepDrilling)

	BEGIN_VERIFY_PARAMETER_MAP(SiemensMultistepDrilling)
	END_VERIFY_PARAMETER_MAP(SiemensMultistepDrilling)

};
FEATURE_DECLARE_SMARTPOINTER(SiemensMultistepDrilling);

SiemensMultistepDrilling::SiemensMultistepDrilling(IWorkCycles * owner) :  IWorkCycle(owner)
{ 
	_parent=owner;
	InitStepItems(&items);
	InitOutputs(this);
	InitTests(this);

}
HRESULT SiemensMultistepDrilling::DeriveParameters(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem)
{
	IWorkCycle::DeriveParameters(pExecutable, pFeature, pOpItem);
	CCannedCycleItems * items = GetStepMap();  // initialize output for now...	

	items->SetVariable(_T("CycleType"),  1) ;

	items->SetVariable(_T("Feedrate"), items->GetValue<double>(_T("StepFeedrate")) * 1000.0 * 60.0) ;
	items->SetVariable(_T("RetractionFeedrate"), items->GetValue<double>(_T("StepFeedrate")) * 1000.0 * 60.0) ;
	items->SetVariable(_T("SafetyPlane"), 2.0) ;
	items->SetVariable(_T("Speed"), fabs(items->GetValue<double>(_T("StepSpeed")))) ;
	items->SetVariable(_T("SpindleDir"), 3.0 + (items->GetValue<double>(_T("StepSpeed"))>=0)) ;

	items->SetVariable(_T("ProgrammableLimitDistance"), 0) ;

	
	double dRetraction = items->GetValue<double>(_T("RetractDistance")) ;

	items->SetVariable(_T("MachiningType"), (long) (dRetraction<0)) ;
	items->SetVariable(_T("VariableRetractionValue"), 0.0) ;
	
	items->SetVariable(_T("ToolAxis"), 0) ; //??
  	
	// if tooling is wrong revise items list before calling this.
	SiemensTool tool;
	_toolnum= tool.DeriveToolParameters(_parent, items, pFeature,  pOpItem);

	SanityCheck() ;
	debugstream << _T("\n");
	debugstream << GetStepMap()->ToString();
	return S_OK;
}



	