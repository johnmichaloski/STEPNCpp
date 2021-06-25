//
// StepNCRectangularPocket.h
//


// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#pragma once
#include "FeatureCycles.h"
//#include _T("Seimens840D.h")
//#include _T("Addons.h")
#include "StepNCTooling.h"



class StepNCRectangularPocket : public   IWorkCycle
{
public:
	StepNCRectangularPocket(IWorkCycles * owner=NULL) ;
	virtual ~StepNCRectangularPocket(){}
	virtual HRESULT DeriveParameters(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem);
	virtual HRESULT LoadIntoStep();
	virtual HRESULT Create(IStepNodePtr /*type==project*/, CString opname);
	virtual void InitValues(CCannedCycleItems *pItems){}
	BEGIN_STEP_MAP(StepNCRectangularPocket)

		ENTRYSET(_T("Type"),				Cycle::Compute,		Cycle::String,		_T(""), _T("RectangularPocket"))

		// These build up the tree - these must be in the proper order
		ENTRY(_T("Feature"),				Cycle::Executable,	Cycle::Classname,		_T("its_feature"))   
		ENTRY(_T("Operation"),				Cycle::Executable,	Cycle::Classname,		_T("its_operation"))
		ENTRY(_T("SecurityPlane"),			Cycle::Executable,	Cycle::StepPosition,	_T("its_secplane/position"))
		ENTRY(_T("FeaturePlacement"),		Cycle::Executable,	Cycle::StepPosition,	_T("its_feature/feature_placement"))
		ENTRY(_T("Depth"),					Cycle::Executable,	Cycle::StepPosition,	_T("its_feature/depth/position"))
		ENTRY(_T("MachiningStrategy"),		Cycle::Executable,	Cycle::Classname,		_T("its_operation/its_machining_strategy"))
		ENTRY(_T("FeatureBoundary"),		Cycle::Executable,	Cycle::Classname,		_T("its_feature/feature_boundary"))
		ENTRY(_T("BottomCondition"),		Cycle::Executable,	Cycle::Classname,		_T("its_feature/bottom_condition"))
		// diameter/implicit_tolerance/  :: PLUS_MINUS_VALUE(0.100,0.100,3)

		ENTRY(_T("FeatureName"),			Cycle::Feature,		Cycle::String,		_T("its_id"))
		ENTRY(_T("ReferencePlane"),			Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[2]"))
		ENTRY(_T("RetractPlane"),			Cycle::Operation,	Cycle::Position,	_T("retract_plane"))
		ENTRY(_T("SafetyPlane"),			Cycle::Executable,	Cycle::Position,	_T("its_secplane/position/location/coordinates[2]"))
		ENTRY(_T("AbsDepth"),				Cycle::Feature,		Cycle::Position,	_T("depth/position/location/coordinates[2]"))

		ENTRY(_T("CenterAbscissa"),			Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[0]"))
		ENTRY(_T("CenterOrdinate"),			Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[1]"))
		ENTRY(_T("StartAbscissa"),			Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[0]"))
		ENTRY(_T("StartOrdinate"),			Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[1]"))
		ENTRY(_T("PlacementRefDirection"),  Cycle::Feature,		Cycle::Vector,		_T("feature_placement/ref_direction/direction_ratios"))
		ENTRY(_T("Location"),				Cycle::Feature,		Cycle::Vector,		_T("feature_placement/location/coordinates"))
		ENTRY(_T("Axis"),					Cycle::Feature,		Cycle::Vector,		_T("feature_placement/axis/direction_ratios"))
		ENTRY(_T("ReferenceDirection"),		Cycle::Feature,		Cycle::Vector,		_T("feature_placement/ref_direction/direction_ratios"))

		ENTRY(_T("Length"),					Cycle::Feature,		Cycle::Length,		_T("feature_boundary/profile_length/theoretical_size"))
		ENTRY(_T("Width"),					Cycle::Feature,		Cycle::Length,		_T("feature_boundary/profile_width/theoretical_size"))
		ENTRY(_T("CornerRadius"),			Cycle::Feature,		Cycle::Length,		_T("orthogonal_radius/theoretical_size"))
		ENTRY(_T("PlanarRadius"),			Cycle::Feature,		Cycle::Length,		_T("planar_radius/theoretical_size"))
		ENTRY(_T("Slope"),					Cycle::Feature,		Cycle::Length,		_T("slope"))

		ENTRY(_T("FinishAllowanceDepth"),	Cycle::Operation,	Cycle::Length,		_T("allowance_bottom"))
		ENTRY(_T("FinishAllowanceSide"),	Cycle::Operation,	Cycle::Length,		_T("allowance_side"))
		ENTRY(_T("MaxOneInfeedDepth"),		Cycle::Operation,	Cycle::Length,		_T("axial_cutting_depth"))
		ENTRY(_T("Stepdown"),				Cycle::Operation,	Cycle::Length,		_T("axial_cutting_depth"))
		ENTRY(_T("Stepover"),				Cycle::Operation,	Cycle::Length,		_T("radial_cutting_depth"))

		ENTRY(_T("CutterComp"),				Cycle::Operation,	Cycle::String,		_T("its_technology/feedrate_reference"))
		ENTRY(_T("InfeedFeedrate"),			Cycle::Operation,	Cycle::Feed,		_T("its_technology/feedrate"))
		ENTRY(_T("StepSpeed"),				Cycle::Operation,	Cycle::Speed,		_T("its_technology/spindle"))
		ENTRY(_T("StepFeedrate"),			Cycle::Operation,	Cycle::Feed,		_T("its_technology/feedrate"))

		//project/main_workplan/its_elements/its_elements[1]/its_operation/its_machine_functions/coolant/
		//project/main_workplan/its_elements/its_elements[1]/its_operation/its_machine_functions/mist/
		//project/main_workplan/its_elements/its_elements[1]/its_operation/its_machine_functions/chip_removal/
		ENTRY(_T("Angle"),					Cycle::Compute,		Cycle::Angle,		_T("Angle = acos(Dot(Vector(1,0,0), PlacementRefDirection)) * 180.0 / M_PI;"))
		ENTRY(_T("CycleType"),				Cycle::Compute,		Cycle::Long,		_T("CycleType = 1.0 + Find(Operation, \")finish\"")) 
		LINK(StepNCTooling)

	END_STEP_MAP(StepNCRectangularPocket)

	BEGIN_VERIFY_PARAMETER_MAP(StepNCRectangularPocket)
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
		
	END_VERIFY_PARAMETER_MAP(StepNCRectangularPocket)
	IStepNodePtr _project;  /*type==project*/
};
FEATURE_DECLARE_SMARTPOINTER(StepNCRectangularPocket);

inline StepNCRectangularPocket::StepNCRectangularPocket(IWorkCycles * owner) :   IWorkCycle(owner)
{ 
	_parent=owner;
	InitStepItems(&items);
	InitTests(this);

}
inline HRESULT StepNCRectangularPocket::DeriveParameters(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem)
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

inline HRESULT StepNCRectangularPocket::Create(IStepNodePtr project, CString opname)
{
	if(project==NULL)
		return E_INVALIDARG;

	if(project->GetClassname() !=_bstr_t( L"project"))
		return E_INVALIDARG; // throw std::exception(_T("Bad project node"));

	INodeListPtr its_elements = project->GetAttributeNodeList(_bstr_t(L"/main_workplan/its_elements"));
	_pExecutable= its_elements->push_back(_bstr_t(L"machining_workingstep"), _bstr_t(L""));

	items.ClearDirtyFlags(); 

	return S_OK;
}

inline HRESULT StepNCRectangularPocket::LoadIntoStep() 
{ 
//	CAddons addons((Eproject *) gProject.get());
	CCannedCycleItems * items = GetStepMap();  
	StepNCTooling tooling;
	tooling.DeriveParameters(items, _pExecutable); 

	IWorkCycle::LoadWSIntoStep(gProject);
	// FILL IN MISSING PARTS

	// Angle will have to be added as a  simplifying concept
	// Angle = acos(Dot(Vector(1,0,0), PlacementRefDirection)) * 180.0 / M_PI;
	if(items->IsDirty(_T("Angle")))
	{
		double a = items->GetValue<double>(_T("Angle")) * M_PI/180.0 ;
		// translate into step 
		Vector v   = Vector(1,0,0) * RotateZ(a) ;
		items->SetVariable(_T("ReferenceDirection"), (Vector) v) ;

	}
	if(items->IsDirty(_T("CCW")))
	{
		double ccw = (items->GetValue<long>(_T("CCW")) > 0) ? -1 : 1;
		items->SetVariable(_T("StepSpeed"), ccw * items->GetValue<double>(_T("Speed"))) ;  

	}
	if(!items->IsDirty(_T("Cutmode")))
	{
		items->SetVariable(_T("Cutmode"), (LPCTSTR) _T(".climb."));
		// project/main_workplan/its_elements/its_elements[3]/its_operation/its_machining_strategy/*/cutmode
	}
	if(items->IsDirty(_T("CycleType")))
	{
		CString str = (LPCTSTR) items->GetValue<tstring>(_T("Climb")).c_str();
		if(str==_T("rough"))
		{
			items->SetVariable(_T("Operation"), _T("bottom_and_side_rough_milling")) ;  
		}
		else
		{
			items->SetVariable(_T("Operation"), _T("bottom_and_side_finish_milling")) ;  

		}

	}	
	return S_OK; 
}


	