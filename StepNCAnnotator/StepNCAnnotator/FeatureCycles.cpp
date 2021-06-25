//
// FeatureCycles.cpp
//


#include "StdAfx.h"
#include "FeatureCycles.h"
#include <math.h>
CWorldModel  gWm;


IFeatureCycle::IFeatureCycle(CWorldModel & wm) : _wm(wm) 
{
	_nToolNum=0;
	_nPlane=IFeatureCycle::NOPLANE;
	_nUnits=IFeatureCycle::NOUNITS;
	SetApproachPlane(NaN);	
	SetRetractPlane(NaN);	
	SetSafetyPlane(NaN);	
	SetReferencePlane(NaN);	

	SetSpindleSpeed(NaN);	
	SetFeedrate(NaN);	 // Feedrate for machining
	SetInfeedFeedrate(NaN);	 // Infeed Feedrate for machining

};
HRESULT IFeatureCycle::DeriveParameters(IStepNodePtr pFeature, Emachining_operationPtr pOpItem)	
{
	CVarDefPtr vardef;
	_variant_t var;
	double dToolRadius;
	double dFeedrate=0.0;  
	long nCuttercomp;
	double dSpindleSpeed=0.0;  
	Ecutting_toolPtr its_tool;		 // tool


	// Operation type...
	_szMachineopClass = ExpDemangle(pOpItem->Classname()).MakeLower() ; 

	// machining operation tooling information
	its_tool=(Ecutting_tool *) pOpItem->its_tool.get();


	// tooling classname,  drill, endmill, etc.
	_szToolClassname=(its_tool->its_tool_body) ? ExpDemangle(its_tool->its_tool_body->Classname()): "None specified";
	vardef = GetVarDef(its_tool , "its_tool_body/dimension/diameter");
	if(vardef==NULL)
		OUTPUT_ERROR_STRING("Tool selected without diameter. Feature guessing enabled :)\n");
	var = pOpItem->GetVarDefVal( vardef);
	try { dToolRadius= (double) var;} catch(...){ dToolRadius=0.0;}  
	dToolRadius/=2.0;

	// Feedrate is in base technology
	if(pOpItem->its_technology && pOpItem->its_technology->feedrate )
	{
		dFeedrate=pOpItem->its_technology->feedrate->val;
		dFeedrate=dFeedrate * 25.4 * 1000.0/60.0 ;  // speed_measure is in meters per second [m/sec] RS274 units per minute feed rate mode 
		nCuttercomp=pOpItem->its_technology->feedrate_reference->_nSelection;
	}
	// Spindle speed is int millingtechnology
	Emilling_technologyPtr pMillingTechnology = (Emilling_technology *) pOpItem->its_technology.get();
	if(pMillingTechnology)
	{
		dSpindleSpeed=(pMillingTechnology->spindle)? pMillingTechnology->spindle->val : 0; // sign determines cw, ccw

	}

	SetFeedrate(dFeedrate); // _FFP1 Feedrate in the plane 4000 mm/min
	SetSpindleSpeed(dSpindleSpeed); // _FFP1 Feedrate in the plane 4000 mm/min
	SetToolRadius(dToolRadius);

	return S_OK;
}
IFeatureCyclePtr CFeatureCycles::CreateFeature(CANON_FEATURE eType)
{
	switch(eType)
	{
	case FACEMILL:
		return new FaceMill(_wm);
	case POCKETRECTANGULAR:
		return new PocketRectangular(_wm);
	case DRILLCENTERING:
		return new DrillCentering(_wm);
	default: 
		return NULL;

	}

	return NULL;

}

HRESULT CFeatureCycles::StockDefinition(CANON_STOCK type, CString szMaterial, Vector origin, Vector extents)
{

	_eStockType=type;
	_szStockMaterial=szMaterial;
	_vStockOrigin=origin;
	_vStockExtents=extents;

	return S_OK;
}


//////////////////////////////////////////////////////////////////////
CString CFeatureCycles::GenerateNCProgram()
{
	CString tmp;
	std::vector<IFeatureCyclePtr> & _commands=*this;

	for(int i=0; i< _commands.size(); i++)
	{
		if(FAILED(_commands[i]->Verify()))
		{
			OUTPUT_DEBUG_STRING(StrFormat("Error in command %s\n", _commands[i]->GetName()));

		}

		tmp+=_commands[i]->ToGCode(0);
	}

	return tmp;
}

///////////////////////////////////////
FaceMill::FaceMill(CWorldModel & wm) : IFeatureCycle(wm)
{
	SetName("FaceMill");
}



/*
$TC_DP1[1,1] = 120 ;Tool type
$TC_DP6[1.1] =10 ;Tool radius
N100 T1
N102 M06
N110 G17 G0 G90 G54 G94 F2000 X0 Y0 Z20 ;Approach start position
;
CYCLE71( 10, 0, 2,-11, 100, 100, ->
-> 60, 40, 10, 6, 10, 5, 0, 4000, 31, 2)
;Cycle call
N125 G0 G90 X0 Y0
N130 M30 ;Program end
*/



PocketRectangular::PocketRectangular(CWorldModel & wm): IFeatureCycle(wm)
{
	SetName("PocketRectangular");
}


DrillCentering::DrillCentering(CWorldModel & wm) : IFeatureCycle(wm)
{ 
	_sName="DrillCentering"; 
}

Reaming::Reaming(CWorldModel & wm): IFeatureCycle(wm)
{ 
	_sName="Reaming"; 

}
