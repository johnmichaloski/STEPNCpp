//
// StepNCCenterDrilling.h
//


// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#pragma once
#include "FeatureCycles.h"
#include "Addons.h"
#include "StepNCTooling.h"

/*
cutting_depth - The depth of the cut of this operation, which may differ from the depth of the hole as
such. The NC controller will not check if cutting_depth violates the boundaries of
the associated hole feature. If omitted, the total depth of the feature will be drilled.*/


class StepNCCenterDrilling : public   IWorkCycle
{
public:
	StepNCCenterDrilling(IWorkCycles * owner=NULL) ;
	virtual ~StepNCCenterDrilling(){}
	virtual HRESULT DeriveParameters(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem);
	virtual HRESULT LoadIntoStep();
	virtual HRESULT Create(IStepNodePtr);
	virtual void InitValues(CCannedCycleItems *pItems){}
	BEGIN_STEP_MAP(StepNCCenterDrilling)

		// These build up the tree - these must be in the proper order
		ENTRY(_T("Feature"),		Cycle::Executable,	Cycle::Classname,		_T("its_feature"))   
		ENTRY(_T("Operation"),		Cycle::Executable,	Cycle::Classname,		_T("its_operation"))
		ENTRY(_T("SecurityPlane"),	Cycle::Executable,	Cycle::StepPosition,	_T("its_secplane/position"))
		ENTRY(_T("FeaturePlacement"),Cycle::Executable,	Cycle::StepPosition,	_T("its_feature/feature_placement"))
		ENTRY(_T("Depth"),			Cycle::Executable,	Cycle::StepPosition,	_T("its_feature/depth/position"))
		
		// diameter/implicit_tolerance/  :: PLUS_MINUS_VALUE(0.100,0.100,3)

		ENTRY(_T("FeatureName"),	Cycle::Feature,		Cycle::String,		_T("its_id"))
		ENTRY(_T("ReferencePlane"),	Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[2]"))
		ENTRY(_T("RetractPlane"),	Cycle::Operation,	Cycle::Position,	_T("retract_plane"))
		ENTRY(_T("SafetyPlane"),	Cycle::Executable,	Cycle::Position,	_T("its_secplane/position/location/coordinates[2]"))

		ENTRY(_T("CenterX"),		Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[0]"))
		ENTRY(_T("CenterY"),		Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[1]"))
		ENTRY(_T("AbsDepth"),		Cycle::Feature,		Cycle::Position,	_T("depth/position/location/coordinates[2]"))
		ENTRY(_T("Diameter"),		Cycle::Feature,		Cycle::Double,		_T("diameter/theoretical_size"))

		// dwell type issues...
		ENTRY(_T("DoDwell"),		Cycle::Operation,	Cycle::Boolean,		_T("spindle_stop_at_bottom"))  
		ENTRY(_T("Dwell"),			Cycle::Operation,	Cycle::Double,		_T("dwell_time_bottom"))  


		ENTRY(_T("CycleType"),		Cycle::Compute,		Cycle::Long,		_T("CycleType = 1.0 + Find(Operation, \"finish\")"))

		ENTRY(_T("StepFeedrate"),	Cycle::Operation,	Cycle::Feed,		_T("its_technology/feedrate"))
		ENTRY(_T("Feedrate"),		Cycle::Compute,		Cycle::Feed,		_T("Feedrate = StepFeedrate * 1000.0 * 60.0 ;"))
		ENTRY(_T("RetractionFeedrate"),Cycle::Compute,	Cycle::Feed,		_T("Feedrate = StepFeedrate * 1000.0  * 60.0 ;"))
		
		ENTRY(_T("StepSpeed"),		Cycle::Operation,	Cycle::Speed,			_T("its_technology/spindle"))
		ENTRY(_T("Speed"),			Cycle::Compute,		Cycle::Speed,		_T("Speed = fabs(SpindleSpeed);"))
		ENTRY(_T("SpindleDir"),		Cycle::Compute,		Cycle::Long,		_T("SpindleDir=( 3.0 + (SpindleSpeed>=0));")) 

		ENTRY(_T("Overcut"),		Cycle::Operation,	Cycle::Length,		_T("overcut_length"))
		ENTRY(_T("CuttingDepth"),	Cycle::Operation,	Cycle::Length,		_T("cutting_depth"))

		LINK(StepNCTooling)

	END_STEP_MAP(StepNCCenterDrilling)

	BEGIN_VERIFY_PARAMETER_MAP(StepNCCenterDrilling)
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("CutterComp != \"TCP\"") , _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Dwell < 0.0") , _T("DWELL_TIME_MUST_NOT_BE_NEGATIVE"))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("RetractPlane <= ReferencePlane") , _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("ReferencePlane <= AbsDepth") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Feedrate <= 0.0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Speed <= 0.0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Toollength < (ReferencePlane - AbsDepth)") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Overcut != 0.0") ,  _T("CENTER_DRILLING_MUST_NOT_HAVE_OVERCUT_LENGTH"))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("CuttingDepth < 0.0") ,  _T("CUTTING_DEPTH_MUST_BE_POSITIVE"))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("CuttingDepth > ( fabs(AbsDepth - ReferencePlane)") ,  _T("CUTTING_DEPTH_MUST_NOT_BE_GREATER_THAN_DEPTH"))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("RetractionFeedrate<=0.0") ,  _T("FEED_ON_RETRACE_MUST_NOT_BE_NEGATIVE_OR_TINY"))
		
	END_VERIFY_PARAMETER_MAP(StepNCCenterDrilling)
	IStepNodePtr _project;
};
FEATURE_DECLARE_SMARTPOINTER(StepNCCenterDrilling);

inline StepNCCenterDrilling::StepNCCenterDrilling(IWorkCycles * owner) :   IWorkCycle(owner)
{ 
	_parent=owner;
	InitStepItems(&items);
	InitTests(this);

}
inline HRESULT StepNCCenterDrilling::DeriveParameters(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem)
{
	IWorkCycle::DeriveParameters(pExecutable, pFeature, pOpItem);
	CCannedCycleItems * items = GetStepMap();  // initialize output for now...	

	items->SetVariable(_T("CycleType"),  1) ;

	items->SetVariable(_T("Feedrate"), items->GetValue<double>(_T("StepFeedrate")) * 1000.0 * 60.0) ;
	items->SetVariable(_T("RetractionFeedrate"), items->GetValue<double>(_T("StepFeedrate")) * 1000.0 * 60.0) ;
	items->SetVariable(_T("SafetyPlane"), 2.0) ;
	items->SetVariable(_T("Speed"), fabs(items->GetValue<double>(_T("StepSpeed")))) ;
	items->SetVariable(_T("SpindleDir"), 3.0 + (items->GetValue<double>(_T("StepSpeed"))>=0)) ;

	// if tooling is wrong revise items list before calling this.
	//_toolnum= DeriveToolParameters( pFeature,  pOpItem);


	SanityCheck() ;
	debugstream << GetStepMap()->ToString();
	return S_OK;
}

inline HRESULT StepNCCenterDrilling::Create(IStepNodePtr project)
{
	if(project==NULL)
		return E_INVALIDARG;
	CAddons addon(project);

	//if(project->main_workplan==NULL)
	//	project->AddAttribute(StrFormat(_T("/main_workplan")));
	//_pExecutable = (Eexecutable *) new Emachining_workingstep(); 
	project->AddAttribute(bstrFormat(bstr_t(L"/main_workplan/its_elements[-1]{machining_workingstep}")));
	INodeListPtr list = project->SelectNodeList(_T("/main_workplan/its_elements"));
	_pExecutable= project->SelectNode(bstrFormat(_T("/main_workplan/its_elements[%d]"), list->size()-1));

	items.ClearDirtyFlags(); 

	return S_OK;
}

inline HRESULT StepNCCenterDrilling::LoadIntoStep() 
{ 
	CAddons addons(gProject);
	StepNCTooling tooling;
	tooling.DeriveParameters(&items, _pExecutable); 
	IWorkCycle::LoadWSIntoStep(gProject);
	addons.DefineStepNcImplicitTolerance(_pFeature, _T("diameter/implicit_tolerance"), _T("0.3"), _T("0.3"), _T("3"));
	return S_OK; 
}




class StepNCReaming : public   StepNCCenterDrilling
{
public:
	StepNCReaming(IWorkCycles * owner=NULL)  :  StepNCCenterDrilling(owner)
	{
		_parent=owner;
		InitStepItems(&items);
		CCannedCycleItems * items = GetStepMap();  // initialize output for now...	
		items->SetVariable(_T("Type"), _T("Reaming")) ;

	}
	virtual ~StepNCReaming(){}
};
