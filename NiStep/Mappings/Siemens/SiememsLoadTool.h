//
// SiememsLoadTool.h
//


// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#pragma once
#include "FeatureCycles.h"
#include "Siemens/Seimens840D.h"



////////////////////////////////////////////////////////////////////////
class SiememsLoadTool : public   IWorkCycle
{
public:
	SiememsLoadTool(IWorkCycles * owner);

	virtual ~SiememsLoadTool(){}
	FEATURECLASSDEF(SiememsLoadTool);  // prevents copy constructors

	virtual HRESULT DeriveParameters(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem);
	virtual CString ToGCode(int nDialect, int eRoughFinish);

	BEGIN_STEP_MAP(SiememsLoadTool)
		ENTRYSET(_T("Type"),			Cycle::Compute,		Cycle::String,		_T(""), _T("LoadTool"))
		ENTRY(_T("FeatureName"),		Cycle::Feature,		Cycle::String,		_T("its_id"))
		ENTRY(_T("Feature"),			Cycle::Feature,		Cycle::Classname,	_T(""))
		ENTRY(_T("Operation"),			Cycle::Operation,	Cycle::Classname,	_T(""))
		
		// Not the same tool definition as feature. Tool not in operation!
		STEPNC_PARAMETER_ENTRY(_T("ToolNumber"), _T("Compute"), _T("Long"), _T(""))
		STEPNC_PARAMETER_ENTRY(_T("ToolTypeNumber"), _T("Compute"), _T("Long"), _T(""))
		STEPNC_PARAMETER_ENTRY(_T("ToolOffsetNumber"), _T("Compute"), _T("Long"), _T(""))  // D number
		STEPNC_PARAMETER_ENTRY(_T("Toolradius"), _T("Compute"), _T("Double"), _T("Toolradius = Tooldiameter / 2.0;"))
		STEPNC_PARAMETER_ENTRY(_T("Toolname"), _T("Executable"), _T("Classname"), _T("its_tool/its_tool_body"))
		STEPNC_PARAMETER_ENTRY(_T("Tooldiameter"), _T("Executable"), _T("Double"), _T("its_tool/its_tool_body/dimension/diameter"))
		STEPNC_PARAMETER_ENTRY(_T("Toollength"), _T("Executable"), _T("Double"), _T("its_tool/its_cutting_edge[0]/tool_offset_length"))
		STEPNC_PARAMETER_ENTRY(_T("ToolAngleTorus"), _T("Compute"), _T("Double"), _T(""))
		STEPNC_PARAMETER_ENTRY(_T("ToolCornerRadius"), _T("Compute"), _T("Double"), _T(""))

	END_STEP_MAP(SiememsLoadTool)
	BEGIN_OUTPUT_PARAMETER_MAP(SiememsLoadTool)
	END_OUTPUT_PARAMETER_MAP(SiememsLoadTool)

	BEGIN_VERIFY_PARAMETER_MAP(SiememsLoadTool)
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("ToolTypeNumber < 0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Toollength <= 0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Toolradius <= 0") ,  _T(""))
	END_VERIFY_PARAMETER_MAP(SiememsLoadTool)

};
FEATURE_DECLARE_SMARTPOINTER(SiememsLoadTool);


SiememsLoadTool::SiememsLoadTool(IWorkCycles * owner):  IWorkCycle(owner)
{
	_sName=_T("LoadTool"); 
	_parent=owner;
	InitStepItems(&items);
	InitOutputs(this);
	InitTests(this);
}
CString SiememsLoadTool::ToGCode(int nDialect, int eRoughFinish)
{
	CString  block;
	block+=StrFormat(_T(";\n;OP%d - "), _parent->_opnum++) + this->GetComment()+ _T("\n;\n");
	block+= _parent->PostToolChange(_toolnum);
	return _parent->PostBlock(block);
}
HRESULT SiememsLoadTool::DeriveParameters(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem)
{
	IWorkCycle::DeriveParameters(pExecutable, pFeature, pOpItem);
	SiemensTool tool;
	_toolnum= tool.DeriveToolParameters(_parent, &items, pFeature,  pOpItem);

	debugstream << GetStepMap()->ToString();

	Verify(errors);

	if(errors.size()>0)
		return E_FAIL;
	return S_OK;
}
