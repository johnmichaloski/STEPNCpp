//
// StepNCTooling.h
//


// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#pragma once
#include "FeatureCycles.h"
#include "Addons.h"


/*
cutting_depth - The depth of the cut of this operation, which may differ from the depth of the hole as
such. The NC controller will not check if cutting_depth violates the boundaries of
the associated hole feature. If omitted, the total depth of the feature will be drilled.*/


class StepNCTooling 
{
public:
	StepNCTooling() ;
	virtual ~StepNCTooling(){}
	virtual HRESULT DeriveParameters(CCannedCycleItems * items, IStepNodePtr pExecutable);
	virtual void InitValues(CCannedCycleItems *pItems);
	BEGIN_STEP_MAP(StepNCTooling)

		// These build up the tree - these must be in the proper order
		ENTRY(_T("Tool"),				Cycle::Executable,	Cycle::Classname,	_T("its_operation/its_tool"))
		ENTRY(_T("Tooltype"),			Cycle::Executable,	Cycle::Classname,	_T("its_operation/its_tool/its_tool_body"))
		ENTRYSET(_T("CuttingEdge"),		Cycle::Executable,	Cycle::Classname,	_T("its_operation/its_tool/its_cutting_edge"), _T("[-1]"))

		ENTRY(_T("Toolname"),			Cycle::Feature,		Cycle::String,		_T("its_tool/its_id"))
		// WHICH ONE?
		ENTRY(_T("Toollength"),			Cycle::Operation,	Cycle::Length,		_T("its_tool/its_tool_body/dimension/cutting_edge_length"))
		//ENTRY(_T("Toollength"),			Cycle::Operation,	Cycle::Length,		_T("its_tool/its_cutting_edge[0]/tool_offset_length"))
		//ENTRY(_T("Toollength"),		Cycle::Operation,	Cycle::Length,		_T("its_tool/overall_assembly_length"))

		ENTRY(_T("Tooldiameter"),		Cycle::Operation,	Cycle::Length,		_T("its_tool/its_tool_body/dimension/diameter"))
		ENTRYSET(_T("HandOfCut"),		Cycle::Operation,	Cycle::String,		_T("its_tool/its_tool_body/hand_of_cut"), _T(".LEFT."))
		ENTRYSET(_T("CoolantThruTool"),	Cycle::Operation,	Cycle::String,		_T("its_tool/its_tool_body/coolant_through_tool"), _T(".F."))
		ENTRYSET(_T("TaperAngle"),		Cycle::Operation,	Cycle::Angle,		_T("its_tool/its_tool_body/taper_angle"), _T("0.0"))
		ENTRY(_T("NumberOfTeeth"),		Cycle::Operation,	Cycle::Long,		_T("its_tool/its_tool_body/number_of_teeth"))
		ENTRYSET(_T("ToolTopAngle"),	Cycle::Operation,	Cycle::Angle,		_T("its_tool/its_tool_body/dimension/tool_top_angle"), _T("0.0"))


		// Problem is if these aren't filled in properly its junk - make negative and if still negative delete.
		ENTRYSET(_T("CuttingEdgeLength"),	Cycle::Operation,	Cycle::Length,		_T("its_tool/its_tool_body/dimension/cutting_edge_length"), _T("-1"))
		ENTRYSET(_T("PilotLength"),			Cycle::Operation,	Cycle::Length,		_T("its_tool/its_tool_body/pilot_length"), _T("-1"))
		ENTRYSET(_T("ToolCircumferenceAngle"),	Cycle::Operation,	Cycle::Angle,	_T("its_tool/its_tool_body/dimension/tool_circumference_angle"), _T("-1"))
		ENTRYSET(_T("EdgeRadius"),			Cycle::Operation,	Cycle::Length,		_T("its_tool/its_tool_body/dimension/edge_radius"), _T("-1"))
		ENTRYSET(_T("EdgeCenterVertical"),	Cycle::Operation,	Cycle::Length,		_T("its_tool/its_tool_body/dimension/edge_center_vertical"), _T("-1"))
		ENTRYSET(_T("EdgeCenterHorizontal"),Cycle::Operation,	Cycle::Length,		_T("its_tool/its_tool_body/dimension/edge_center_horizontal"), _T("-1"))
		//ENTRY(_T("direction_for_spindle_orientation"),Cycle::Operation,	Cycle::Length,		_T("its_tool/direction_for_spindle_orientation"))
		//ENTRY(_T("tool_holder_diameter_for_spindle_orientation"),Cycle::Operation,	Cycle::Length,		_T("its_tool/tool_holder_diameter_for_spindle_orientation"))
#if 0

		its_operation/its_tool/its_cutting_edge/its_cutting_edge[0]/tool_offset_length/
		its_operation/its_tool/its_cutting_edge/its_cutting_edge[0]/its_material/standard_identifier/
		its_operation/its_tool/its_cutting_edge/its_cutting_edge[0]/its_material/material_identifier/
		its_operation/its_tool/its_cutting_edge/its_cutting_edge[0]/technological_data/
		its_operation/its_tool/its_cutting_edge/its_cutting_edge[0]/expected_tool_life/
		/*  The technology defines the technological parameters to be used for
		machining (e.g. the spindle speed and the feed of the tool which guarantee expected_tool_life).
		*/
		its_operation/its_tool/its_cutting_edge/its_cutting_edge[0]/its_technology/feedrate/
		its_operation/its_tool/its_cutting_edge/its_cutting_edge[0]/its_technology/feedrate_reference/
		its_operation/its_tool/its_cutting_edge/its_cutting_edge[0]/its_technology/cutspeed/
		its_operation/its_tool/its_cutting_edge/its_cutting_edge[0]/its_technology/spindle/
		its_operation/its_tool/its_cutting_edge/its_cutting_edge[0]/its_technology/feedrate_per_tooth/
		its_operation/its_tool/its_cutting_edge/its_cutting_edge[0]/its_technology/synchronize_spindle_with_feed/
		its_operation/its_tool/its_cutting_edge/its_cutting_edge[0]/its_technology/inhibit_feedrate_override/
		its_operation/its_tool/its_cutting_edge/its_cutting_edge[0]/its_technology/inhibit_spindle_override/
#endif

		END_STEP_MAP(StepNCTooling)

		BEGIN_VERIFY_PARAMETER_MAP(StepNCTooling)

		END_VERIFY_PARAMETER_MAP(StepNCTooling)
};
FEATURE_DECLARE_SMARTPOINTER(StepNCTooling);

inline StepNCTooling::StepNCTooling() 
{ 
}

inline void StepNCTooling::InitValues(CCannedCycleItems *pItems) 
{
	// this should go into the table
	pItems->SetVariable(_T("HandOfCut"), _T(".LEFT.")) ;
	pItems->SetVariable(_T("CoolantThruTool"), _T(".F")) ;
	pItems->SetVariable(_T("TaperAngle"), _T("0.0")) ;
	pItems->SetVariable(_T("Toolradius"), _T("0.0")) ;
	pItems->SetVariable(_T("CuttingEdge"), _T("[-1]")) ;

}

inline HRESULT StepNCTooling::DeriveParameters(CCannedCycleItems * pItems, IStepNodePtr pExecutable)
{

	if(pItems->GetValue<double>(_T("Toolradius"), -1)> 0.0)
	{
		pItems->SetVariable(_T("Tooldiameter"), pItems->GetValue<double>(_T("Toolradius")) * 2.0) ;
	}

	if(pItems->GetValue<double>(_T("CuttingEdgeLength"),-1) < 0.0) 
		pItems->Remove(_T("CuttingEdgeLength")) ;
	if(pItems->GetValue<double>(_T("PilotLength"),-1) < 0.0)
		pItems->Remove(_T("PilotLength")) ;
	if(pItems->GetValue<double>(_T("ToolCircumferenceAngle"),-1) < 0.0)
		pItems->Remove(_T("ToolCircumferenceAngle")) ;
	if(pItems->GetValue<double>(_T("EdgeRadius"),-1) < 0.0) 
		pItems->Remove(_T("EdgeRadius")) ;
	if(pItems->GetValue<double>(_T("EdgeCenterVertical"),-1) < 0.0)
		pItems->Remove(_T("EdgeCenterVertical")) ;
	if(pItems->GetValue<double>(_T("EdgeCenterHorizontal"),-1) < 0.0)
		pItems->Remove(_T("EdgeCenterHorizontal")) ;


	//Hack for now
	pItems->SetVariable(_T("CuttingEdge"),_T("[-1]")) ;
	

	return S_OK;

}

class StepNCWorkpiece : public 	CStepNCItems
{
public:
	StepNCWorkpiece() { InitStepItems(&items); }
	virtual ~StepNCWorkpiece(){}	
	IStepNodePtr _project;
	IStepNodePtr _workpiece;


	void InitValues(CCannedCycleItems *pItems) {}

	inline HRESULT Create(IStepNodePtr project)
	{
		if (project==NULL)
			return E_INVALIDARG;

		_project=project;
		INodeListPtr its_elements = _project->GetAttributeNodeList(_bstr_t(L"its_workpieces"));
		int n = its_elements->size();
		if(n < 1)
		{
			_workpiece= its_elements->push_back(_bstr_t(L"workpiece"), _bstr_t(L""));
		}
		else
			_workpiece=its_elements->back();
	
		return S_OK;
	}
	virtual HRESULT LoadIntoStep() 
	{ 
		CAddons addons(_project);

		for(int i=0; i< this->items.size(); i++)
		{
			if(items.at(i)->Type() == Cycle::Classname)
			{
				_project->AddAttribute(bstrFormat(_T("%s%s"), items.at(i)->StepPath(), items.at(i)->_str));
			}
			else  if(items.at(i)->Type() == Cycle::StepPosition)
			{

				addons.DefineAxis2_placement_3d(_project,items.at(i)->StepPath(), items.at(i)->Name());
			}
		}

		items.Inject( NULL, NULL, NULL);
		return S_OK;
	}

	BEGIN_STEP_MAP(StepNCWorkpiece)

		// These build up the tree - these must be in the proper order
		ENTRY(_T("Form"),			Cycle::Project,		Cycle::Classname,		_T("/its_workpieces[0]/its_bounding_geometry"))
		
		ENTRY(_T("Name"),			Cycle::Project,		Cycle::Length,			_T("/its_workpieces[0]/its_id"))
		ENTRY(_T("X"),				Cycle::Project,		Cycle::Length,			_T("/its_workpieces[0]/its_bounding_geometry/x"))
		ENTRY(_T("Y"),				Cycle::Project,		Cycle::Length,			_T("/its_workpieces[0]/its_bounding_geometry/y"))
		ENTRY(_T("Z"),				Cycle::Project,		Cycle::Length,			_T("/its_workpieces[0]/its_bounding_geometry/z"))
		ENTRY(_T("Position"),		Cycle::Project,		Cycle::StepPosition,	_T("/its_workpieces[0]/its_bounding_geometry/position"))
		ENTRY(_T("Location"),		Cycle::Project,		Cycle::Vector,			_T("/its_workpieces[0]/its_bounding_geometry/position/location/coordinates"))
	//workpiece->SetAttributeValue(_T("its_material/standard_identifier"), stdId);
	//		workpiece->SetAttributeValue(_T("its_material/material_identifier"), materialID);

		END_STEP_MAP(StepNCWorkpiece)

};


class StepNCHeader : public 	CStepNCItems
{
public:
	StepNCHeader() { InitStepItems(&items); }
	virtual ~StepNCHeader(){}	
	IStepNodePtr _project;
	IStepNodePtr _workpiece;


	void InitValues(CCannedCycleItems *pItems) {}

	inline HRESULT Create(IStepNodePtr project)
	{
	
	
		return S_OK;
	}

	BEGIN_STEP_MAP(StepNCHeader)

		// These build up the tree - these must be in the proper order
		ENTRYSET(_T("Type"),			Cycle::Compute,		Cycle::String,			_T(""), _T("Header"))
		ENTRYSET(_T("Units"),			Cycle::Compute,		Cycle::String,			_T(""), _T("MM"))
		ENTRY(_T("Description"),		Cycle::Header,		Cycle::String,			_T(""))
		ENTRY(_T("Name"),				Cycle::Header,		Cycle::String,			_T(""))
		ENTRY(_T("Author"),				Cycle::Header,		Cycle::String,			_T(""))
		ENTRY(_T("Organization"),		Cycle::Header,		Cycle::String,			_T(""))
	END_STEP_MAP(StepNCHeader)

};

