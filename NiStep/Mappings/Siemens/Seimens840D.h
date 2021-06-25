//
// Seimens840D.h
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.


#pragma once
#include "FeatureCycles.h"
#include "boost/tuple/tuple.hpp"
#include "StepNCTooling.h"

class Seimens840D;

class SiemensTool 
{
public:
	SiemensTool() {}
	virtual ~SiemensTool(){}
	FEATURECLASSDEF(SiemensTool);  // prevents copy constructors
	CCannedCycleItems *_parent;
	int DeriveToolParameters(IWorkCyclesPtr _parent, CCannedCycleItems * pItems, IStepNodePtr pFeature, IStepNodePtr pOpItem);
	void InitValues(CCannedCycleItems *pItems)  {}

	BEGIN_STEP_MAP(SiemensTool)

		ENTRY(_T("ToolNumber"),			_T("Compute"), _T("Long"), _T(""))
		ENTRY(_T("ToolTypeNumber"),		_T("Compute"), _T("Long"), _T(""))
		ENTRY(_T("ToolOffsetNumber"),	_T("Compute"), _T("Long"), _T(""))  // D number
		ENTRY(_T("Toolradius"),			_T("Compute"), _T("Double"), _T("Toolradius = Tooldiameter / 2.0;"))
		ENTRY(_T("ToolAngleTorus"),		_T("Compute"), _T("Double"), _T(""))
		ENTRY(_T("ToolCornerRadius"),	_T("Compute"), _T("Double"), _T(""))
		LINK(StepNCTooling)

	END_STEP_MAP(SiemensTool)

};


class Seimens840D : public IWorkCycles
{
public:
	Seimens840D(CWorldModel &wm);
	virtual ~Seimens840D(void);

	// input step nc tool class name, return matching tool number
	// FIXME: No handling of edge data yet.
	static long GetToolNumber(CString toolname);

	// Feature defining helpers
	virtual void NewWorkingStep(){}
	virtual IWorkCyclePtr CreateFeature(CANON_FEATURE eType);

	// Program helpers
	virtual CString GenerateNCProgram();
	virtual CString GenerateNCHeader();
	virtual CString SpindleCommand(double spindlespeed);
	virtual CString PostToolDefinition(int toolnum, int tooledge=1);
	CString PostToolChange(int toolnum);
	virtual HRESULT ParseStepNC(IStepNodePtr gProject, CStringVector &errors);

	virtual int  LookupTool(int type, double length, double radius, double cornerradius);

	typedef boost::tuple<int, double, double, double> ToolingTuple; 
	std::vector<ToolingTuple> _toollist;
	double _dLengthConversion;
	double _dSpeedConversion;
	int _nToolChangenum;

};
FEATURE_DECLARE_SMARTPOINTER(Seimens840D);

