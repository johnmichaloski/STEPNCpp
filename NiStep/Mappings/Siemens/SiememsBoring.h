//
// SiememsBoring.h
//

// Status: UNIMPLEMENTED/UNTESTED

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#pragma once
#include "FeatureCycles.h"
#include "Mappings/Seimens840D.h"

/* 
Enlarge a preexisting hole:

The tool drills at the programmed spindle speed and feedrate velocity up to the entered
drilling depth.

With Boring 2, oriented spindle stop is activated with the SPOS command once the drilling
depth has been reached. Then, the programmed retraction positions are approached in rapid
traverse and, from there, the retraction plane.


ENTITY boring_operation
	ABSTRACT SUPERTYPE OF (ONEOF(boring, reaming))
SUBTYPE OF (drilling_type_operation);
	spindle_stop_at_bottom: BOOLEAN;
	depth_of_testcut: OPTIONAL length_measure;
	waiting_position: OPTIONAL cartesian_point;
END_ENTITY;

spindle_stop_at_bottom: Possible spindle stop at the bottom of the hole. If the attribute oriented_spindle_stop
in the workingstep’s technology is set, this will cause an oriented spindle stop.

depth_of_testcut: Depth of a testcut after which the hole is measured.

waiting_position: A waiting position for the tool i.e. to allow measuring. The tool moves out of the
hole along the tool axis until it reaches the plane of the waiting_position. It then
moves to the waiting position itself.

*/


////////////////////////////////////////////////////////////////////////
class SiememsBoring :   public IWorkCycle
{
public:
	SiememsBoring(IWorkCycles * owner);

	virtual ~SiememsBoring(){}
	FEATURECLASSDEF(SiememsBoring);  // prevents copy constructors

	virtual HRESULT DeriveParameters(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem);

	BEGIN_STEP_MAP(SiememsBoring)
		ENTRYSET("Type",			Cycle::Compute,		Cycle::String,		"", "Boring")
		ENTRY("FeatureName",		Cycle::Feature,		Cycle::String,		"its_id")
		ENTRY("Feature",			Cycle::Feature,		Cycle::Classname,	"")
		ENTRY("Operation",			Cycle::Operation,	Cycle::Classname,	"")
		ENTRY("CenterX",			Cycle::Feature,		Cycle::Position,	"feature_placement/location/coordinates[0]")
		ENTRY("CenterY",			Cycle::Feature,		Cycle::Position,	"feature_placement/location/coordinates[1]")
		ENTRY("AbsDepth",			Cycle::Feature,		Cycle::Position,	"depth/position/location/coordinates[2]")

		// dwell type issues...
		ENTRY("DoDwell",			Cycle::Operation,	Cycle::Boolean,		"spindle_stop_at_bottom")  
		ENTRY("Dwell",				Cycle::Operation,	Cycle::Double,		"dwell_time_bottom")  

		ENTRY("ReferencePlane",		Cycle::Feature,		Cycle::Position,	"feature_placement/location/coordinates[2]")
		ENTRY("RetractPlane",		Cycle::Operation,	Cycle::Position,	"retract_plane")
		ENTRY("SafetyPlane",		Cycle::Compute,		Cycle::Position,	"SafetyPlane	= 2.0;")

		ENTRY("CycleType",			Cycle::Compute,		Cycle::Long,		"CycleType = 1.0 + Find(Operation, \"finish\")") 

		ENTRY("StepFeedrate",		Cycle::Operation,	Cycle::Feed,		"its_technology/feedrate")
		ENTRY("Feedrate",			Cycle::Compute,		Cycle::Feed,		"Feedrate = StepFeedrate * 1000.0 * 60.0 ;")
		ENTRY("RetractionFeedrate",Cycle::Compute,		Cycle::Feed,		"Feedrate = StepFeedrate * 1000.0  * 60.0 ;")
		
		ENTRY("StepSpeed",		Cycle::Operation,	Cycle::Speed,		"its_technology/spindle")
		ENTRY("Speed",				Cycle::Compute,		Cycle::Speed,		"Speed = fabs(SpindleSpeed);")
		ENTRY("SpindleDir",		Cycle::Compute,		Cycle::Long,		"SpindleDir=( 3.0 + (SpindleSpeed>=0));") 
		
		LINK(SiemensTool)

	//	ENTRY("Toollength",	Cycle::Operation, Cycle::Double, "its_tool/its_tool_body/dimension/cutting_edge_length")
	//	ENTRY("Toollength", Cycle::Operation, Cycle::Double, "its_tool/overall_assembly_length")
	END_STEP_MAP(SiememsBoring)

	BEGIN_OUTPUT_PARAMETER_MAP(SiememsBoring)

		STEPNC_OUTPUT_ENTRY("Both", "G0  F2000 ", "", "")
		STEPNC_OUTPUT_ENTRY("Both", "X%.3f ", "CenterX", "")
		STEPNC_OUTPUT_ENTRY("Both", "Y%.3f ", "CenterY", "")
		STEPNC_OUTPUT_ENTRY("Both", "Z%.3f\n", "RetractPlane", "")
		STEPNC_OUTPUT_ENTRY("Both", "F%.3f", "Feedrate", "")
		STEPNC_OUTPUT_ENTRY("Both", "M0%d", "SpindleDir", "")
		STEPNC_OUTPUT_ENTRY("Both", "S%.3f\n", "Speed", "")

		STEPNC_OUTPUT_ENTRY("Both", "CYCLE86(", "", "")
		STEPNC_OUTPUT_ENTRY("Both", "%.3f, ", "RetractPlane", "")
		STEPNC_OUTPUT_ENTRY("Both", "%.3f, ", "ReferencePlane", "")
		STEPNC_OUTPUT_ENTRY("Both", "%.3f, ", "SafetyPlane", "")
		STEPNC_OUTPUT_ENTRY("Both", "%.3f, ", "AbsDepth", "")
		STEPNC_OUTPUT_ENTRY("Both", " , ", "", "")
		STEPNC_OUTPUT_ENTRY("Both", "%.3f, ", "Dwell", "")
		STEPNC_OUTPUT_ENTRY("Both", "%.3f, ", "Feedrate", "")
		STEPNC_OUTPUT_ENTRY("Both", "%.3f ", "RetractionFeedrate", "")
		STEPNC_OUTPUT_ENTRY("Both", ")\n", "", "")
	END_OUTPUT_PARAMETER_MAP(SiememsBoring)

	BEGIN_VERIFY_PARAMETER_MAP(SiememsBoring)
	END_VERIFY_PARAMETER_MAP(SiememsBoring)

};
FEATURE_DECLARE_SMARTPOINTER(SiememsBoring);


SiememsBoring::SiememsBoring(IWorkCycles * owner)
{
	_sName="Reaming"; 
	_parent=owner;
	InitItems(this);
	InitOutputs(this);
	InitTests(this);
}

HRESULT SiememsBoring::DeriveParameters(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem)
{
	IWorkCycle::DeriveParameters(pExecutable, pFeature, pOpItem);

	CCannedCycleItems * items = GetStepMap();  // initialize output for now...	

	items->SetVariable("CycleType",  2) ;
	
	items->SetVariable("Feedrate", items->GetValue<double>("StepFeedrate") * 1000.0 * 60.0) ;
	items->SetVariable("RetractionFeedrate", items->GetValue<double>("StepFeedrate") * 1000.0 * 60.0) ;
	items->SetVariable("SafetyPlane", 2.0) ;
	items->SetVariable("Speed", fabs(items->GetValue<double>("StepSpeed"))) ;
	items->SetVariable("SpindleDir", 3.0 + (items->GetValue<double>("StepSpeed")>=0)) ;
	SiemensTool tool;
	_toolnum= tool.DeriveToolParameters(_parent, items, pFeature,  pOpItem);


	SanityCheck() ;

	debugstream << GetStepMap()->ToString();
	return S_OK;
}
