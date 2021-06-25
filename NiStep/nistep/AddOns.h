//
// AddONs.h
//

#pragma once
#include "ExpressUtils.h"
#include "stepnc_schemaClassDefinitions.h"
using namespace Express;

extern IStepNodePtr CreateExpressAddons(CString classname, CString name) ;


class EHelix : public IStepNode
{
public: 
	CLASSDEF(EHelix);
	Ecurve _curve;
	Eaxis2_placement_3dPtr position; 
	Epositive_length_measurePtr radius; 
	Elength_measurePtr pitch; 

};
EXP_DECLARE_SMARTPOINTER(EHelix);

struct Earc : public IStepNode
{
public: 
	Ecurve _curve;
	CLASSDEF(Earc);
	Ecartesian_pointPtr start_point;    /* Arc endpoints */
	Ecartesian_pointPtr end_point;
	Ecartesian_pointPtr center;           /* Arc center, relative to view */
	Eplane_angle_measurePtr radius;           /* Arc radius */
	Eplane_angle_measurePtr start_angle;          /* Start angle in radians */
	Eplane_angle_measurePtr sweep_angle;          /* Sweep angle in radians */
} ;      
EXP_DECLARE_SMARTPOINTER(Earc);


