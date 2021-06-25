//
// SiemensRectangularPocket.h
//


// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#pragma once
#include "FeatureCycles.h"
#include "StepNCRectangularPocket.h"

class SiemensRectangularPocket;


class SiemensRectangularPocket :public IWorkCycle
{
public:
	SiemensRectangularPocket::SiemensRectangularPocket(IWorkCycles * owner): // IWorkCycle(wm),
	  IWorkCycle(owner) 
	  {
		  _parent=owner;
		  InitStepItems(&items);
		  InitOutputs(this);
		  InitTests(this);
	  }	
	  virtual ~SiemensRectangularPocket(){}
	FEATURECLASSDEF(SiemensRectangularPocket);  // prevents copy constructors

	virtual HRESULT DeriveParameters(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem) ;

	BEGIN_STEP_MAP(SiemensRectangularPocket)
		LINK(StepNCRectangularPocket)

		//ENTRY("Angle",					Cycle::Compute,		Cycle::Angle,		"Angle = acos(Dot(Vector(1,0,0), PlacementRefDirection)) * 180.0 / M_PI;")
		//ENTRY("CycleType",				Cycle::Compute,		Cycle::Long,		"CycleType = 1.0 + Find(Operation, \"finish\")") 
		ENTRY(_T("Feedrate"),				Cycle::Compute,		Cycle::Feed,		_T("Feedrate = StepFeedrate * 1000.0 * 60.0 ;"))
		ENTRY(_T("InfeedFeedrate"),			Cycle::Compute,		Cycle::Feed,		_T("InfeedFeedrate = StepFeedrate * 1000.0 * 60.0 ;"))
		ENTRY(_T("MillingDirection"),		Cycle::Compute,		Cycle::Long,		_T("MillingDirection = 1.0;")) 
		ENTRY(_T("RetractionTravel"),		Cycle::Compute,		Cycle::Length,		_T("RetractionTravel=0.0;")) 
		ENTRY(_T("SafetyPlane"),			Cycle::Compute,		Cycle::Length,		_T("SafetyPlane	= 2.0;"))
		ENTRY(_T("Speed"),					Cycle::Compute,		Cycle::Speed,		_T("Speed = fabs(SpindleSpeed);"))
		ENTRY(_T("SpindleDir"),				Cycle::Compute,		Cycle::Long,		_T("SpindleDir=( 3.0 + (SpindleSpeed>=0));")) 


		ENTRY(_T("RoughingTolerance"),		Cycle::Compute,		Cycle::Length,		_T("")) 
		ENTRY(_T("FinishingTolerance"),		Cycle::Compute,		Cycle::Length,		_T("")) 
		LINK(SiemensTool)

		//  StepNCRectangularPocket links in tooling

	END_STEP_MAP(SiemensRectangularPocket)

	BEGIN_OUTPUT_PARAMETER_MAP(SiemensRectangularPocket)
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("G0  F2000 "), _T(""), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("X%.3f "), _T("CenterAbscissa"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("Y%.3f "), _T("CenterOrdinate"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("Z%.3f\n"), _T("RetractPlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("F%.3f"), _T("Feedrate"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("M0%d"), _T("SpindleDir"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("S%.3f\n"), _T("Speed"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Rough"),  _T("CYCLE832(%.3f,1003)\n"), _T("RoughingTolerance"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Finish"), _T("CYCLE832(%.3f,102001)\n"), _T("FinishingTolerance"), _T(""))

		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("POCKET1("), _T(""), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("RetractPlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("ReferencePlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("SafetyPlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("AbsDepth"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T(" , "), _T(""), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("Length"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("Width"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("CornerRadius"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("CenterAbscissa"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("CenterOrdinate"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("Angle"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("InfeedFeedrate"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("Feedrate"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("MaxOneInfeedDepth"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%d, "), _T("MillingDirection"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("FinishAllowanceSide"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%d "), _T("CycleType"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Finish"), _T(" , "), _T(""), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Finish"), _T("%.3f, "), _T("MaxOneInfeedDepth"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Finish"), _T("%.3f  "), _T("Feedrate"), _T(""))
	//	STEPNC_OUTPUT_ENTRY(_T("Finish"), _T("%.3f "), _T("Speed"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T(")\n"), _T(""), _T(""))
	END_OUTPUT_PARAMETER_MAP(SiemensRectangularPocket)

	BEGIN_VERIFY_PARAMETER_MAP(SiemensRectangularPocket)
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("CutterComp != \"TCP\"") , _T(""))
		STEPNC_VERIFY_ENTRY(_T("Warning"), _T("Both"), _T("RetractPlane == 0.0") ,_T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("RetractPlane <= ReferencePlane") , _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("ReferencePlane <= AbsDepth") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Feedrate <= 0.0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Speed <= 0.0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Length <= 0.0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Width <= 0.0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("CornerRadius <= 0.0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Toollength < (ReferencePlane - AbsDepth)") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Toolradius >= CornerRadius") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Toolradius  > Width") ,  _T(""))
	END_VERIFY_PARAMETER_MAP(SiemensRectangularPocket)

	/*
	The other parameters can be selected as options. They define the insertion strategy and overlapping
	for solid machining:
	_MIDA real Maximum infeed width as a value in solid machining in the plane
	_AP1 real Blank dimension of pocket length
	_AP2 real Blank dimension of pocket width
	_AD real Blank pocket depth dimension from reference plane
	_RAD1 real Radius of the helical path on insertion (relative to the tool center point
	path) or maximum insertion angle for reciprocating motion
	_DP1 real Insertion depth per 360° revolution on insertion along helical path
	*/
};
FEATURE_DECLARE_SMARTPOINTER(SiemensRectangularPocket);


//////////////////////////////////////////////////////////////////////////////////////////

HRESULT SiemensRectangularPocket::DeriveParameters(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem) 
{
	IWorkCycle::DeriveParameters(pExecutable, pFeature, pOpItem);
	CCannedCycleItems * items = GetStepMap();  // initialize output for now...	

	double d = Dot(Vector(1,0,0),  items->GetValue<Vector>(_T("PlacementRefDirection"))); 
	items->SetVariable(_T("Angle"), (double) acos( d ) * 180.0 / M_PI);

	CString Operation = items->GetValue<tstring>(_T("Operation")).c_str();
	items->SetVariable(_T("CycleType"), (long) 1.0 + (Operation.Find(_T("finish"))>=0)) ;
	
	items->SetVariable(_T("Feedrate"), items->GetValue<double>(_T("StepFeedrate")) * 1000.0 * 60.0) ;
	items->SetVariable(_T("InfeedFeedrate"), items->GetValue<double>(_T("StepFeedrate")) * 1000.0 * 60.0) ;
	items->SetVariable(_T("MillingDirection"), (long) 2) ;
	items->SetVariable(_T("RetractPlane"), items->GetValue<double>(_T("ReferencePlane"))+ 10.0) ;
	items->SetVariable(_T("SafetyPlane"), 2.0) ;
	items->SetVariable(_T("Speed"), fabs(items->GetValue<double>(_T("StepSpeed")))) ;
	items->SetVariable(_T("SpindleDir"), 3.0 + (items->GetValue<double>(_T("StepSpeed"))>=0)) ;
	items->SetVariable(_T("RoughingTolerance"), (double) 0.01) ;
	items->SetVariable(_T("FinishingTolerance"), (double) 0.001) ;



	// if tooling is wrong revise items list before calling this.
	SiemensTool tool;
	_toolnum= tool.DeriveToolParameters(_parent, items, pFeature,  pOpItem);

	debugstream << GetStepMap()->ToString();

	return S_OK;

}
