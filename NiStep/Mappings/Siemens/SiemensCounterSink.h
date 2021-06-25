//
// SiemensCounterSink.h
//


// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#pragma once
#include "FeatureCycles.h"



class SiemensCounterSink : public  IWorkCycle
{
public:
	SiemensCounterSink(IWorkCycles * owner, CWorldModel & wm) ;
	virtual ~SiemensCounterSink(){}
	virtual HRESULT DeriveParameters(IStepNodePtr pFeature, IStepNodePtr pOpItem);

	BEGIN_STEP_PARAMETER_MAP(SiemensCounterSink)
		STEPNC_PARAMETER_ENTRY("AAAFeatureName", "Feature", "String", "its_id")
		STEPNC_PARAMETER_ENTRY("Feature", "Feature", "Classname", "")
		STEPNC_PARAMETER_ENTRY("MachineOp", "Operation", "Classname", "")
		STEPNC_PARAMETER_ENTRY("CenterX", "Feature", "Double", "feature_placement/location/coordinates[0]")
		STEPNC_PARAMETER_ENTRY("CenterY", "Feature", "Double", "feature_placement/location/coordinates[1]")
		STEPNC_PARAMETER_ENTRY("AbsDepth", "Feature", "Double", "depth/position/location/coordinates[2]")

		STEPNC_PARAMETER_ENTRY("Diameter", "Operation", "Double", "diameter/theoretical_size")

		// dwell type issues...
		STEPNC_PARAMETER_ENTRY("DoDwell", "Operation", "Long", "spindle_stop_at_bottom")  
		STEPNC_PARAMETER_ENTRY("Dwell", "Operation", "Double", "dwell_time_bottom")  

		STEPNC_PARAMETER_ENTRY("ReferencePlane", "Feature", "Double", "feature_placement/location/coordinates[2]")
		STEPNC_PARAMETER_ENTRY("RetractPlane", "Operation", "Double", "retract_plane")
		STEPNC_PARAMETER_ENTRY("SafetyPlane", "Compute", "Double", "SafetyPlane	= 2.0;")

		STEPNC_PARAMETER_ENTRY("CycleType", "Compute", "Long", "CycleType = 1.0 + Find(MachineOp, \"finish\")") 

		STEPNC_PARAMETER_ENTRY("StepFeedrate", "Operation", "Double", "its_technology/feedrate")
		STEPNC_PARAMETER_ENTRY("Feedrate", "Compute", "Double", "Feedrate = StepFeedrate * 1000.0 * 60.0 ;")
		STEPNC_PARAMETER_ENTRY("RetractionFeedrate", "Compute", "Double", "Feedrate = StepFeedrate * 1000.0 * 60.0 ;")
		
		STEPNC_PARAMETER_ENTRY("SpindleSpeed", "Operation", "Double", "its_technology/spindle")
		STEPNC_PARAMETER_ENTRY("Speed", "Compute", "Double", "Speed = fabs(SpindleSpeed);")
		STEPNC_PARAMETER_ENTRY("SpindleDir", "Compute", "Long", "SpindleDir=( 3.0 + (SpindleSpeed>=0));") 

		STEPNC_PARAMETER_ENTRY("ToolTypeNumber", "Compute", "Long", "")
		STEPNC_PARAMETER_ENTRY("Toolradius", "Compute", "Double", "Toolradius = Tooldiameter / 2.0;")
		STEPNC_PARAMETER_ENTRY("Toolname", "Operation", "Classname", "its_tool/its_tool_body")
		STEPNC_PARAMETER_ENTRY("Tooldiameter", "Operation", "Double", "its_tool/its_tool_body/dimension/diameter")
		STEPNC_PARAMETER_ENTRY("Toollength", "Operation", "Double", "its_tool/its_tool_body/dimension/cutting_edge_length")

	//	STEPNC_PARAMETER_ENTRY("Toollength", "Operation", "Double", "its_tool/its_cutting_edge[1]/tool_offset_length")
	//	STEPNC_PARAMETER_ENTRY("Toollength", "Operation", "Double", "its_tool/overall_assembly_length")
	END_STEP_PARAMETER_MAP(SiemensCounterSink)

	BEGIN_OUTPUT_PARAMETER_MAP(SiemensCounterSink)
		STEPNC_OUTPUT_ENTRY("Both", "G0  F2000 ", "", "")
		STEPNC_OUTPUT_ENTRY("Both", "X%.3f ", "CenterX", "")
		STEPNC_OUTPUT_ENTRY("Both", "Y%.3f ", "CenterY", "")
		STEPNC_OUTPUT_ENTRY("Both", "Z%.3f\n", "RetractPlane", "")
		STEPNC_OUTPUT_ENTRY("Both", "F%.3f", "Feedrate", "")
		STEPNC_OUTPUT_ENTRY("Both", "M0%d", "SpindleDir", "")
		STEPNC_OUTPUT_ENTRY("Both", "S%.3f\n", "Speed", "")

		STEPNC_OUTPUT_ENTRY("Both", "CYCLE82(", "", "")
		STEPNC_OUTPUT_ENTRY("Both", "%.3f, ", "RetractPlane", "")
		STEPNC_OUTPUT_ENTRY("Both", "%.3f, ", "ReferencePlane", "")
		STEPNC_OUTPUT_ENTRY("Both", "%.3f, ", "SafetyPlane", "")
		STEPNC_OUTPUT_ENTRY("Both", "%.3f, ", "AbsDepth", "")
		STEPNC_OUTPUT_ENTRY("Both", " , ", "", "")
		STEPNC_OUTPUT_ENTRY("Both", "%.3f, ", "Dwell", "")
		STEPNC_OUTPUT_ENTRY("Both", ")\n ", "", "")
	END_OUTPUT_PARAMETER_MAP(SiemensCounterSink)

	BEGIN_VERIFY_PARAMETER_MAP(SiemensCounterSink)
	END_VERIFY_PARAMETER_MAP(SiemensCounterSink)

};


SiemensCounterSink::SiemensCounterSink(IWorkCycles * owner, CWorldModel & wm): IWorkCycle(wm)
{
	_sName="Counterboring"; 
	_parent=owner;
	InitItems(this);
	InitOutputs(this);
	InitTests(this);

}

HRESULT SiemensCounterSink::DeriveParameters(IStepNodePtr pFeature, IStepNodePtr pOpItem)
{
	IWorkCycle::DeriveParameters(pFeature, pOpItem);
	CCannedCycleItems * items = GetMap();  // initialize output for now...	

	CString machineop =(LPCTSTR) items->GetValue<tstring>("MachineOp").c_str();
	items->SetVariable("CycleType",  1.0 + (machineop.Find("finish")>=0)) ;
	
	items->SetVariable("Feedrate", items->GetValue<double>("StepFeedrate") * 1000.0 * 60.0) ;
	items->SetVariable("RetractionFeedrate", items->GetValue<double>("StepFeedrate") * 1000.0 * 60.0) ;
	items->SetVariable("SafetyPlane", 2.0) ;
	items->SetVariable("Speed", fabs(items->GetValue<double>("SpindleSpeed"))) ;
	items->SetVariable("SpindleDir", 3.0 + (items->GetValue<double>("SpindleSpeed")>=0)) ;
	items->SetVariable("Toolradius", items->GetValue<double>("Tooldiameter") / 2.0) ;

	items->SetVariable("ToolTypeNumber", Seimens840D::GetToolNumber(items->GetValue<tstring>("Toolname").c_str())) ;
	_toolnum = _parent->LookupTool(items->GetValue<long>("ToolTypeNumber"),
		items->GetValue<double>("Toollength"),
		items->GetValue<double>("Toolradius"),
		0);

	debugstream << GetMap()->ToString();
	return S_OK;
}

