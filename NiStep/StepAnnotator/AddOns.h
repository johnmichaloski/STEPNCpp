//
//
//

// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#pragma once
#include "QueryPath.h"
#include "FeatureCycles.h"
#include "MillingMath.h"


class CAddons
{
public:

	CAddons(IStepNodePtr project) ;
	//CAddons(EprojectPtr project, IWorkCyclesPtr program) ;

	HRESULT DefineGlobalTolerance(double dTol);
	double StepFeedrate(double feedrate, long ccw) { return (ccw)? -feedrate : feedrate; }
	

	HRESULT DefineBlockWorkpiece(IStepNodePtr project, LPCTSTR name, 
		double x, 
		double y, 
		double z, 
		LPCTSTR stdId, 
		LPCTSTR materialID);
	void DefineAxis2_placement_3d(IStepNodePtr pStep, 
		CString steppath, 
		CString name,
		LPCTSTR position=_T("0,0,0"),
		LPCTSTR axis=_T("0,0,1"),
		LPCTSTR ref_direction = _T("1,0,0"));

	void DefineStepNcImplicitTolerance(IStepNodePtr pStep, 
		CString steppath, 
		LPCTSTR upper_limit,
		LPCTSTR lower_limit,
		LPCTSTR significant_digits );
	Line3D DeriveLine(IStepNodePtr pLine);
	Arc3D DeriveArc(IStepNodePtr arc);
	double AngleBetween(Vector v1,Vector v2, Vector normal= Vector(0,0,1)) ;

private:
	IStepNodePtr _project;
	CQueryPath querypath;
	//IWorkCyclesPtr _program;



};