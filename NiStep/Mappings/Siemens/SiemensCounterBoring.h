//
// SiemensCounterBoring.h
//


// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#pragma once
#include "FeatureCycles.h"
#include "Siemens/Seimens840D.h"



class SiemensCounterBoring : public   IWorkCycle
{
public:
	SiemensCounterBoring(IWorkCycles * owner) ;
	virtual ~SiemensCounterBoring(){}
	virtual HRESULT DeriveParameters(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem);

	BEGIN_STEP_MAP(SiemensCounterBoring)
		ENTRYSET(_T("Type"),			Cycle::Compute,		Cycle::String,		_T(""), _T("CounterBoring"))
		ENTRY(_T("FeatureName"),	Cycle::Feature,		Cycle::String,		_T("its_id"))
		ENTRY(_T("Feature"),			Cycle::Feature,		Cycle::Classname,	_T(""))
		ENTRY(_T("Operation"),			Cycle::Operation,	Cycle::Classname,	_T(""))

		ENTRY(_T("CenterX"),			Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[0]"))
		ENTRY(_T("CenterY"),			Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[1]"))
		ENTRY(_T("AbsDepth"),			Cycle::Feature,		Cycle::Position,	_T("depth/position/location/coordinates[2]"))

		ENTRY(_T("Diameter"),			Cycle::Operation,	Cycle::Length,		_T("diameter/theoretical_size"))

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

	//	ENTRY(_T("Toollength"), _T("Operation"), _T("Double"), _T("its_tool/its_cutting_edge[1]/tool_offset_length"))
	//	ENTRY(_T("Toollength"), _T("Operation"), _T("Double"), _T("its_tool/overall_assembly_length"))
	END_STEP_MAP(SiemensCounterBoring)

	BEGIN_OUTPUT_PARAMETER_MAP(SiemensCounterBoring)
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("G0  F2000 "), _T(""), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("X%.3f "), _T("CenterX"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("Y%.3f "), _T("CenterY"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("Z%.3f\n"), _T("RetractPlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("F%.3f"), _T("Feedrate"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("M0%d"), _T("SpindleDir"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("S%.3f\n"), _T("Speed"), _T(""))

		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("CYCLE82("), _T(""), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("RetractPlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("ReferencePlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("SafetyPlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("AbsDepth"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T(" , "), _T(""), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("Dwell"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T(")\n "), _T(""), _T(""))
	END_OUTPUT_PARAMETER_MAP(SiemensCounterBoring)

	BEGIN_VERIFY_PARAMETER_MAP(SiemensCounterBoring)
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("CutterComp != \"TCP\"") , _T(""))
		STEPNC_VERIFY_ENTRY(_T("Warning"), _T("Both"), _T("RetractPlane == 0.0") ,_T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("RetractPlane <= ReferencePlane") , _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("ReferencePlane <= AbsDepth") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Feedrate <= 0.0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Speed <= 0.0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Toollength < (ReferencePlane - AbsDepth)") ,  _T(""))
  	END_VERIFY_PARAMETER_MAP(SiemensCounterBoring)

};


SiemensCounterBoring::SiemensCounterBoring(IWorkCycles * owner):  IWorkCycle(owner)
{
	_sName=_T("Counterboring"); 
	_parent=owner;
	InitStepItems(&items);
	InitOutputs(this);
	InitTests(this);

}

HRESULT SiemensCounterBoring::DeriveParameters(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem)
{
	IWorkCycle::DeriveParameters(pExecutable, pFeature, pOpItem);
	CCannedCycleItems * items = GetStepMap();  // initialize output for now...	

	CString Operation =(LPCTSTR) items->GetValue<tstring>(_T("Operation")).c_str();
	items->SetVariable(_T("CycleType"),  1.0 + (Operation.Find(_T("finish"))>=0)) ;
	
	items->SetVariable(_T("Feedrate"), items->GetValue<double>(_T("StepFeedrate")) * 1000.0 * 60.0) ;
	items->SetVariable(_T("RetractionFeedrate"), items->GetValue<double>(_T("StepFeedrate")) * 1000.0 * 60.0) ;
	items->SetVariable(_T("SafetyPlane"), 2.0) ;
	items->SetVariable(_T("Speed"), fabs(items->GetValue<double>(_T("StepSpeed")))) ;
	items->SetVariable(_T("SpindleDir"), 3.0 + (items->GetValue<double>(_T("StepSpeed"))>=0)) ;

	// if tooling is wrong revise items list before calling this.
	SiemensTool tool;
	_toolnum= tool.DeriveToolParameters(_parent, items, pFeature,  pOpItem);

	SanityCheck() ;
	debugstream << GetStepMap()->ToString();
	return S_OK;
}

