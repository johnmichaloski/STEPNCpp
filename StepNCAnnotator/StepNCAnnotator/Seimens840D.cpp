#include "StdAfx.h"
#include "Seimens840D.h"
#include "ExpressUtils.h"
template<typename T>
static Vector ToVector(std::vector<T> &direction_ratios )
{
	Vector v;
	v.x= direction_ratios[0]->val;
	v.y= direction_ratios[1]->val;
	if(direction_ratios.size()> 2)
		v.z= direction_ratios[2]->val;
	return v;
};
Seimens840D::Seimens840D(CWorldModel &wm): CFeatureCycles(wm) 
{

}

Seimens840D::~Seimens840D(void)
{
}
//
// FIXME: add handle for multiline comments
//
CString Seimens840D::NewBlock(CString line)
{
	CString block;

	if(line.GetLength() < 1)
		return block;
	if(_wm._bUseBlockNums)
		block.Format("N%03d ", _wm._nBlockNum);
	block.AppendFormat("%s",  line);
	_wm._nBlockNum+=_wm._nBlockIncr;
	if(block.ReverseFind('\n')<0)
		block+="\n";
	return block;

}

/*
$TC_DP1[6,1]=120 $TC_DP3[6,1]=150 $TC_DP6[6,1]=6
100 Cutter acc. to CLDATA
110 Ballhead cutter
120 End mill (without corner rounding)
121 End mill (with corner rounding)
130 Angle head cutter (without corner rounding)
131 Angle head cutter (with corner rounding)
140 Facing tool
145 Thread cutter
150 Side mill
151 Saw
155 Bevel cutter
160 Drill and thread milling cutter
Group with type 2xy (drills):
200 Twist drill
205 Solid drill
210 Boring bar
220 Center drill
230 Countersink
231 Counterbore
240 Tap, regular
241 Tap, fine
242 Tap, Whitworth
250 Reamer
*/

int  Seimens840D::DefineTool(ToolEnums type, double length, double radius, double cornerradius)
{
	static int num=1;
	_toollist.push_back( ToolingTuple(type, length, radius, cornerradius));
	num++;
	return num-1;
}
CString Seimens840D::ToolChange(int toolnum)
{
	CString block;
	if(toolnum!=0)
	{
		ToolingTuple tooling(_toollist[toolnum-1]);

		block+=NewBlock(StrFormat("$TC_DP1[%d,1]=%d $TC_DP3[%d,1]=%d $TC_DP6[%d,1]=%d\n", 
			toolnum, boost::get<0>(tooling), toolnum, (int) boost::get<1>(tooling), toolnum,  (int) boost::get<2>(tooling)));

		block+=NewBlock(StrFormat("T%d\n",toolnum) );
		block+=NewBlock("M6\n");
	}
	return block;

}


CString Seimens840D::SpindleCommand(double spindlespeed)
{
	CString block;
	if(spindlespeed==0)
		return "M05";
	// negative angle is clockwise rotation, typical for machining tools
	if(spindlespeed<0)
		return StrFormat("M03S%d", (long) fabs(spindlespeed));
	if(spindlespeed>0)
		return StrFormat("M04S%d", (long) fabs(spindlespeed));

	return block;

}
IFeatureCyclePtr Seimens840D::CreateFeature(CANON_FEATURE eType)
{
	switch(eType)
	{
	case FACEMILL:
		return new SiemensFaceMill(this, _wm);
	case POCKETRECTANGULAR:
		return new SiemensPocketBasicRectangular(this,_wm);
	case DRILLCENTERING:
		return new SiemensDrillCentering(this, _wm);
	case REAMING:
		return new SiemensReaming(this, _wm);
	default: 
		{
			OUTPUT_DEBUG_STRING("Creating non-feature Siemens feature-based program\n");
			DebugBreak();
			return NULL;
		}

	}

	return NULL;
}


CString Seimens840D::GenerateNCProgram()
{
	_wm._nBlockNum=_wm._nBlockIncr;  
	CString tmp;
	CString line;
	std::vector<IFeatureCyclePtr> & _commands=*this;
	time_t rawtime;
	time ( &rawtime );

	tmp+="; STEP-NC ISO 14649 NIST Feature-Based  Siemens 840D NC Generator\n";
	tmp.Append(StrFormat("; Generated: %s\n",ctime(&rawtime) )); 

	tmp.AppendFormat(";Workpiece stock size: %.2f x %.2f x %.2f \n", _vStockExtents.x, _vStockExtents.y, _vStockExtents.z);
	tmp.AppendFormat(";Workpiece area(blank cuboid) \n");
	tmp.AppendFormat(";Place following code in file: DPWP.INI\n");
	tmp.AppendFormat(";SIM_WPAREA_XMIN=%d\n", (long) _vStockOrigin.x);
	tmp.AppendFormat(";SIM_WPAREA_XMAX=%d\n",(long) (_vStockOrigin.x + _vStockExtents.x) );
	tmp.AppendFormat(";SIM_WPAREA_YMIN=%d\n", (long) (_vStockOrigin.y));
	tmp.AppendFormat(";SIM_WPAREA_YMAX=%d\n", (long) (_vStockOrigin.y + _vStockExtents.y));
	tmp.AppendFormat(";SIM_WPAREA_ZMIN=%d\n", (long) ( _vStockOrigin.z));
	tmp.AppendFormat(";SIM_WPAREA_ZMAX=%d\n", (long) ( _vStockOrigin.z + _vStockExtents.z));

	line.AppendFormat("G17"); // G17=xyplane
	line.AppendFormat(" G90"); //  G90 absolute distance ,  
	line.AppendFormat(" G54"); // G54 use preset work coordinate system 1,
	line.AppendFormat(" G94\n"); // G94 units per minute feed rate mode 
	tmp+=NewBlock(line);


	for(int i=0; i< _commands.size(); i++)
	{
		if(FAILED(_commands[i]->Verify()))
		{
			OUTPUT_DEBUG_STRING(StrFormat("Error in command %s\n", _commands[i]->GetName()));

		}

		tmp+=_commands[i]->ToGCode(0);
	}

	tmp+=NewBlock("M30\n");
	return tmp;
}

HRESULT SiemensFaceMill::DeriveParameters(IStepNodePtr pFeature, Emachining_operationPtr pOpItem)
{
	Vector direction_ratios;	// vector describing angle of rotation for facing
	Vector location;			// corner feature start location(not cutter starting location)
	Vector vDepth ;				// 3D description of depth plane...
	double dLength;				// positive length in travel direction (other use sign for direction)
	double dWidth;				
	double dRetract;			// retract in z plane from reference point (z0)
	double dFinishingDepth;		// only used for finishing operation

	// Calc feeds and speeds
	IFeatureCycle::DeriveParameters(pFeature, pOpItem);

	// Get planar_face info
	Eplanar_facePtr pFace = (Eplanar_face*) pFeature.get();
	Elinear_pathPtr course_of_travel =pFace->course_of_travel;   // machining direction

	vDepth = ToVector(pFace->depth->position->location->coordinates);				// 3D description of depth plane...
	dWidth   = course_of_travel->distance->theoretical_size->val;					// positive length in travel direction (other use sign for direction)
	direction_ratios = ToVector(course_of_travel->its_direction->direction_ratios);	// vector describing angle of rotation for facing
	location = ToVector(pFace->feature_placement->location->coordinates);			// starting position also?

	// QUESTION: need to multiply vector to length to determine actual machining direction?
	// QUESTION: 

	// optional wasn't defined
	if(pFace->course_of_travel->placement)
	{
		Vector vTravelLocation = ToVector(pFace->course_of_travel->placement->location->coordinates); // starting position.
		Vector vTravelDirection_ratios = ToVector(course_of_travel->placement->axis->direction_ratios); 
		Vector vTravelRef_direction=ToVector(course_of_travel->placement->ref_direction->direction_ratios);  // assume this means (0,0,1)
	}

	dLength=pFace->removal_boundary->profile_length->its_parameter_value->val; 
	dRetract =  (pOpItem->retract_plane!=NULL) ? pOpItem->retract_plane->val: location.z+10;
	dFinishingDepth=0.75;

	//if(pFacingOp->allowance_bottom)
	//	dFinishingDepth	= pFacingOp->allowance_bottom->val;	

	int nToolnum = _parent->DefineTool(Seimens840D::FacingTool, 100,  GetToolRadius(), 0);
	SetToolNum(nToolnum);

	SetRetractPlane(dRetract);
	SetReferencePlane(location.z);
	SetSafetyPlane(2); // _SDIS Safety clearance 2 mm 
	SetDepth(vDepth.z);
	SetFinishAllowance(0);
	SetFinishAllowanceDepth(dFinishingDepth);
	SetStartAbscissa(location.x);
	SetStartOrdinate(location.y);   // y0

	SetLength(dLength); // _LENG Rectangle dimensions X = +60 mm
	SetWidth(dWidth); // _WID Rectangle dimensions Y = +40 mm

	// FIXME: calculate rotation form direction_ratios
	SetAngle(0); // _STA Angle of rotation in the plane 10 degrees

	// FIXME: these should be caculated from "removal_boundary-face_boundary"
	SetMaxInfeedDepth(6); // _MID Maximum infeed depth 6 mm
	SetMaxInfeedWidth(10); // _MIDA Maximum infeed width 10 mm
	SetRetractionTravel(5); // _FDP Retraction at the end of the milling path 5 mm

	if(_szMachineopClass=="plane_rough_milling")
	{
		SetCycleType(IFeatureCycle::Roughing);
	}
	else
		SetCycleType(IFeatureCycle::Finishing);

	SetMillingDirection(3);
	SetOverrun(2); // _FDP1 Overrun on last cut as determined by the cutting edge geometry 2 mm

	// Verify and see if parameters are ok...
	return S_OK;
}

void SiemensFaceMill::SetMillingDirection(Vector v)
{

	v.Normalize();
	if(_wm.GetPlane() == CWorldModel::CANON_PLANE_YZ)
	{
		if(v.y>0)
			SetMillingDirection(3);
		else
			SetMillingDirection(4);
	}
	else 
	{
		if(v.x>0)
			SetMillingDirection(3);
		else
			SetMillingDirection(4);
	}
}
CString SiemensFaceMill::ToGCode(int nDialect, int eRoughFinish)
{

	CString line, block;


	block.AppendFormat(";%s\n", GetComment()); // feature-based operation  comment
	block+=_parent->ToolChange(GetToolNum());
	block+=_parent->NewBlock(StrFormat("G0  X%-.*f Y%-.*f Z%-.*f\n", 
		_wm.nFPrecision, GetStartAbscissa(), _wm.nFPrecision, GetStartOrdinate(), _wm.nFPrecision, GetRetractPlane())); // Approach start position
	block+=_parent->NewBlock(StrFormat("F%d%s\n", (long) GetFeedrate(), _parent->SpindleCommand ( GetSpindleSpeed())));

	line="CYCLE71(";
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetRetractPlane() );  // Retraction plane (absolute)
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetReferencePlane()  );  // Reference plane (absolute)
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetSafetyPlane() );  // Safety clearance (to be added to the reference plane, enter without sign)
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetDepth());  //Depth (absolute)
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetStartAbscissa());  // Starting point, abscissa (absolute)
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetStartOrdinate());  // Starting point, ordinate (absolute)
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetLength());  // Length of the rectangle in the 1st axis, incrementally.The corner from which dimensioning is carried out results from the sign.
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetWidth());  //_WID real Length of the rectangle in the 2nd axis, incrementally.The corner from which dimensioning is carried out results from the sign.
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetAngle());  // _STA real Angle between the longitudinal axis of the rectangle and the first axis ofthe plane (abscissa, enter without sign);
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetMaxInfeedDepth() ); // MID real Maximum infeed depth (enter without sign)
	line.AppendFormat("%.*f,", _wm.nFPrecision, fabs(GetMaxInfeedWidth()) ); //_MIDA real Maximum infeed width value for machining in the plane (enter without sign)
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetRetractionTravel()); //FDP real Retraction travel in cutting direction (incremental, enter without sign)
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetFinishAllowanceDepth()); //_FALD real Final machining allowance in depth (incremental, enter without sign). In finishing mode, ); //_FALD refers to the remaining material on the surface.
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetFeedrate()); //_FFP1 real Feedrate for surface machining
	line.AppendFormat("%-d,", GetCycleType() + 10 *GetMillingDirection() ); //	 Machining type: (enter without sign)
	line.AppendFormat("%.*f", _wm.nFPrecision, fabs(GetOverrun()) ); // _FDP1 real Overrun travel in direction of plane infeed (incremental, enter without sign)

	line+=")\n";
	block+=_parent->NewBlock(line);

	return block;
}



CString SiemensFaceMill::TestCode()
{
	SetRetractPlane(10); // Retraction plane 10 mm
	SetReferencePlane(0); // Reference plane 0 z0=0
	SetSafetyPlane(2); // _SDIS Safety clearance 2 mm
	SetDepth(-11.0); // _DP Depth -11 mm
	SetFinishAllowance(0); //_FAL Finishing allowance in plane No finishing allowance
	SetFinishAllowanceDepth(0); // _FALD Finishing allowance in depth No finishing allowance
	SetStartAbscissa(100); // _PA Starting point of the rectangle X = 100 mm
	SetStartOrdinate(100); // _PO Starting point of the rectangle Y = 100 mm
	SetLength(60); // _LENG Rectangle dimensions X = +60 mm
	SetWidth(40); // _WID Rectangle dimensions Y = +40 mm
	SetAngle(10); // _STA Angle of rotation in the plane 10 degrees
	SetMaxInfeedDepth(6); // _MID Maximum infeed depth 6 mm
	SetMaxInfeedWidth(10); // _MIDA Maximum infeed width 10 mm
	SetRetractionTravel(5); // _FDP Retraction at the end of the milling path 5 mm
	SetFeedrate(4000); // _FFP1 Feedrate in the plane 4000 mm/min
	SetCycleType(IFeatureCycle::Roughing); // _VARI Machining type Roughing parallel to the X axis with alternating direction
	SetMillingDirection(3);
	SetOverrun(2); // _FDP1 Overrun on last cut as determined by the cutting edge geometry 2 mm

	return ToGCode(0);

}
/////////////////////////////////////////////////////////////////////////
SiemensDrillCentering::SiemensDrillCentering(Seimens840D * owner, CWorldModel & wm) : _parent(owner), DrillCentering(wm)
{ 
}
HRESULT SiemensDrillCentering::DeriveParameters(IStepNodePtr pFeature, Emachining_operationPtr pOpItem)
{
	return DeriveBasicParameters( pFeature,  pOpItem);
}

CString SiemensDrillCentering::ToGCode(int nDialect, int eRoughFinish)
{ 
	CString line, block;

	//if(this->GetPlane() != NC)
	//	line.AppendFormat("G17 "); // G17=xyplane
	//line.AppendFormat("G94"); // G94 units per minute feed rate mode 
	//block+=_parent->NewBlock(line);
	block.AppendFormat(";%s\n", GetComment()); // feature-based operation  comment
	block+=_parent->ToolChange(this->GetToolNum());
	block+=_parent->NewBlock(StrFormat("G0 F2000 X%-.*f Y%-.*f Z%-.*f\n", 
		_wm.nFPrecision, GetCenterAbscissa(), _wm.nFPrecision, GetCenterOrdinate(), _wm.nFPrecision, GetRetractPlane())); // Approach start position
	block+=_parent->NewBlock(StrFormat("F%d%s\n", (long) GetFeedrate(), _parent->SpindleCommand ( GetSpindleSpeed())));

	line="CYCLE81(";
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetRetractPlane() );  // Retraction plane (absolute)
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetReferencePlane()  );  // Reference plane (absolute)
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetSafetyPlane() );  // Safety clearance (to be added to the reference plane, enter without sign)
	if(GetAbsFinalDepth()!=NaN)
		line.AppendFormat("%.*f",_wm.nFPrecision,  GetAbsFinalDepth());  //Depth (absolute)  
	else if(GetRelFinalDepth()!=NaN)
		line.AppendFormat("%.*f", _wm.nFPrecision, GetRelFinalDepth());  //Depth (rel)  
	line+=")\n";
	block+=_parent->NewBlock(line);

	return block;
}
HRESULT SiemensDrillCentering::Verify(std::vector<EnumErrors>& errors) 
{ 
	if(GetAbsFinalDepth()==NaN && GetRelFinalDepth()==NaN)
		errors.push_back(E_UNINIITALIZED_PARAMETER);
	if(GetReferencePlane()==NaN || GetCenterAbscissa()==NaN || GetCenterOrdinate()==NaN)
		errors.push_back(E_UNINIITALIZED_PARAMETER);
	if(GetHoleRadius() < GetToolRadius())
		errors.push_back(E_TOOL_LARGER_THAN_HOLE);

	if(errors.size()>0)
		return E_FAIL;
	return S_OK;

}
///////////////////////////////////////////////////////////////////////////////////
HRESULT SiemensReaming::DeriveParameters(IStepNodePtr pFeature, Emachining_operationPtr pOpItem)
{
	if(FAILED(DeriveBasicParameters( pFeature,  pOpItem)))
		return E_FAIL;

	// EBooleanPtr spindle_stop_at_bottom; 
	// Elength_measurePtr depth_of_testcut; 
	// Ecartesian_pointPtr waiting_position; 

	EreamingPtr reamop = (Ereaming *) 	pOpItem.get(); 
	double dDwell;
	double dFeedrate=0.0;  
	double dRetractionFeedrate=0.0;
	long nCuttercomp;

	int nToolnum = _parent->DefineTool(Seimens840D::Reamer, 100,  GetToolRadius(), 0);
	SetToolNum(nToolnum);

	// FIXME: This is not DWELL
	dDwell = (reamop->spindle_stop_at_bottom->_nSelection) ? 1.0 : 0.0;
	if(reamop->its_technology && reamop->its_technology->feedrate )
	{
		dFeedrate=reamop->its_technology->feedrate->val;
		nCuttercomp=reamop->its_technology->feedrate_reference->_nSelection;
	}
	dRetractionFeedrate= reamop->feed_on_retract? reamop->feed_on_retract->val : dFeedrate;

	// Dwell at bottom, feedrate cutting, feedrate retraction
	SetDwell(dDwell);
	SetFeedrate(dFeedrate);
	SetRetractionFeedrate(dRetractionFeedrate);
	return S_OK;
}

HRESULT SiemensReaming::Verify(std::vector<EnumErrors>& errors) 
{ 
	return Reaming::Verify(errors);
}

CString SiemensReaming::ToGCode(int nDialect, int eRoughFinish)
{ 
	CString line, block;


	block.AppendFormat(";%s\n", GetComment()); // feature-based operation  comment
	block+=_parent->ToolChange(this->GetToolNum());
	block+=_parent->NewBlock(StrFormat("G0  F2000 X%-.*f Y%-.*f Z%-.*f\n", 
		_wm.nFPrecision, GetCenterAbscissa(), _wm.nFPrecision, GetCenterOrdinate(), _wm.nFPrecision, GetRetractPlane())); // Approach start position
	block+=_parent->NewBlock(StrFormat("F%d%s\n", (long) GetFeedrate(), _parent->SpindleCommand ( GetSpindleSpeed())));

	line="CYCLE85(";
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetRetractPlane() );  // Retraction plane (absolute)
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetReferencePlane()  );  // Reference plane (absolute)
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetSafetyPlane() );  // Safety clearance (to be added to the reference plane, enter without sign)
	if(GetAbsFinalDepth()!=NaN)
		line.AppendFormat("%.*f,",_wm.nFPrecision,  GetAbsFinalDepth());  //Depth (absolute)  
	else if(GetRelFinalDepth()!=NaN)
		line.AppendFormat("%.*f,", _wm.nFPrecision, GetRelFinalDepth());  //Depth (rel)  

	line.AppendFormat("%.*f,", _wm.nFPrecision, GetDwell() );  
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetFeedrate() );  
	line.AppendFormat("%.*f", _wm.nFPrecision, GetRetractionFeedrate() ); 
	line+=")\n";
	block+=_parent->NewBlock(line);


	return block;
}

SiemensReaming::SiemensReaming(Seimens840D * owner, CWorldModel & wm): _parent(owner), Reaming(wm)
{
	_sName="Reaming"; 
	SetDwell(NaN);				// Dwell time at final drilling depth
	SetFeedrate(NaN);			// Feedrate
	SetRetractionFeedrate(NaN);  //Retraction feedrate
}
//////////////////////////////////////////////////////////////////////////////////////////



IFeatureCyclePtr SiemensBasicPocketing::DerivePocketingCycle(CFeatureCyclesPtr _program, IStepNodePtr pFeature, Emachining_operationPtr pOpItem)
{

	CString szFeatureClassname=ExpDemangle(pFeature->Classname());
	CString szMachineopClass = ExpDemangle(pOpItem->Classname()).MakeLower() ; 
	Seimens840DPtr program = (Seimens840D *) (CFeatureCycles *) _program.get();

	if(szFeatureClassname=="closed_pocket")
	{ 
		Eclosed_pocketPtr pPocket= (Eclosed_pocket*) pFeature.get();
		// Mind boggling inheritance chain: {,,StepNCAnnotator.exe}(*(Express::Epolyline*)(((*(Express::Egeneral_closed_profile*)(((*(Express::Eclosed_pocket*){*}((pPocket).p_)).feature_boundary).p_)).closed_profile_shape).p_)).points
		// location
		// (*((((*(Express::Eplacement*)(&*((((*(Express::Etwo5d_manufacturing_feature*)(&(*(Express::Emachining_feature*)(&(*(Express::Epocket*)(&*((pPocket).p_)))))))).feature_placement).p_)))).location).p_)).coordinates

		// test some classname for  Erectangular_closed_profile
		CString szProfileType = ExpDemangle(pPocket->feature_boundary->Classname()).MakeLower();
		// Got a rectangle
		SiemensPocketBasicRectangularPtr pocket;
		double dRetract;
		Vector vDepth ;				// 3D description of depth plane...
		Vector location;			// pocket location(not cutter starting location)
		Vector direction;			// reference direction of pocket

		double dLength, dWidth ; // rectangular information
		double dCornerRadius; // rectangular information

		pocket =(SiemensPocketBasicRectangular *)  program->CreateFeature(CFeatureCycles::POCKETRECTANGULAR).get();// FaceMill(gWm);
		pocket->SetFeatureClassname(szFeatureClassname);
		pocket->SetMachineopClass(szMachineopClass);
		pocket->IFeatureCycle::DeriveParameters( pFeature,  pOpItem);


		if(szProfileType=="general_closed_profile")
		{
			Egeneral_closed_profilePtr pProfile =(Egeneral_closed_profile *) pPocket->feature_boundary.get();
			CString szCurveType = ExpDemangle(pProfile->closed_profile_shape->Classname()).MakeLower();
			if(szCurveType=="polyline")
			{
				EpolylinePtr pCurve = (Epolyline *) pProfile->closed_profile_shape.get();

				// There will be points, as this is not a pointer, may be empty though
				EListT<Ecartesian_pointPtr> points = pCurve->points;
				std::vector<Vector> vPoints;
				// Change vector of pointer to doubles to actual math vector
				for(int i=0; i< points.size(); i++) 
				{ 
					vPoints.push_back (  ToVector(points[i]->coordinates)); 
					OUTPUT_DEBUG_STRING(vPoints.back().ToString());

				}
				if(vPoints.size()==5 && vPoints[0]==vPoints[4])  // should  be since its a closed profile! 
				{

					// test for rectangle - 
					Vector midpoint1 = (vPoints[2]+vPoints[0])*.5;
					Vector midpoint2 = (vPoints[3]+vPoints[1])* .5;
					if( Vector(midpoint1 - midpoint2).Len()< 0.01 )
					{


						dLength = Vector(vPoints[1]-vPoints[0]).Len();
						dWidth = Vector(vPoints[2]-vPoints[1]).Len();
						pocket->IFeatureCycle::DeriveParameters( pFeature,  pOpItem);
					}
				}
			}
		}
		else if(szProfileType=="rectangular_closed_profile")
		{
			Erectangular_closed_profilePtr pRect =(Erectangular_closed_profile *) pPocket->feature_boundary.get();

			dLength = (pRect->profile_length->theoretical_size) ? pRect->profile_length->theoretical_size->val : 0;  
			dWidth =   (pRect->profile_width->theoretical_size) ? pRect->profile_width->theoretical_size->val :0;

		}

		// Quick check to see that minimum location data we need is available.
		if(!	pPocket 
			|| !pPocket->depth 
			|| !pPocket->depth->position
			|| !pPocket->depth->position->location
			|| !pPocket->feature_placement 
			|| !pPocket->feature_placement->location 
			|| (pPocket->feature_placement->location->coordinates.size() < 3) 
			)
		{
			OUTPUT_DEBUG_STRING("Error: Insufficient information for pocketing\n");
			DebugBreak();
			return NULL;
		}

		// Corner radius - orthogonal radius of a fillet, if existing. 
		// FIXME: check against radius of tool.
		dCornerRadius = (pPocket->orthogonal_radius) ?pPocket->orthogonal_radius->theoretical_size->val : 0.0;

		// FIXME: can't do bottom planar radius yet.

		location = ToVector(pPocket->feature_placement->location->coordinates); // starting position also?
		vDepth = ToVector(pPocket->depth->position->location->coordinates);

		dRetract =  (pOpItem->retract_plane!=NULL) ? pOpItem->retract_plane->val: location.z+10;

		if(pPocket->feature_placement->ref_direction)
		{
			Vector vDirection = ToVector(pPocket->feature_placement->ref_direction->direction_ratios); 
			double dAngle = acos(Dot(Vector(1,0,0), vDirection)) * 180.0 / PI;
			pocket->SetAngle(dAngle);
		}

		pocket->SetRetractPlane(dRetract);
		pocket->SetReferencePlane(location.z);
		pocket->SetSafetyPlane(2); // _SDIS Safety clearance 2 mm 
		pocket->SetAbsDepth(vDepth.z);
		pocket->SetLength(dLength);
		pocket->SetWidth(dWidth);
		pocket->SetCenterAbscissa(location.x);
		pocket->SetCenterOrdinate(location.y);   // y0
		pocket->SetCornerRadius(dCornerRadius);

		if(szMachineopClass.Find("rough")>=0)
			pocket->SetCycleType(IFeatureCycle::Roughing);
		else
			pocket->SetCycleType(IFeatureCycle::Finishing);


		pocket->SetInfeedFeedrate(pocket->GetFeedrate());  // FIXME:
		pocket->SetMillingDirection(SiemensPocketBasicRectangular::G2); // FIXME: total guess climb vs conventional
		pocket->SetFinishFeed(pocket->GetFeedrate());			// FIXME: Feedrate for finishing
		pocket->SetFinishSpeed(pocket->GetSpindleSpeed());			//FIXME: Speed for finishing
		pocket->SetRelDepth(location.z-vDepth.z);


		Ebottom_and_side_millingPtr  pMillingOp = (Ebottom_and_side_milling *) pOpItem.get();
		if(pMillingOp )
		{

			// axial_cutting_depth: The cutting depth in the direction of the tool axis.
			pocket->SetMaxOneInfeedDepth(pMillingOp->axial_cutting_depth->val);

			//radial_cutting_depth: The cutting depth perpendicular to the tool axis.
			//pocket->SetStepOver(pMillingOp->its_machining_strategy->radial_cutting_depth->val);
			
			// Finishing allowance at the pocket edge (enter without sign)
			pocket->SetFinishAllowanceSide(pMillingOp->allowance_side->val);

			// Finishing allowance at the pocket bottom (enter without sign)
			pocket->SetFinishAllowanceBottom(pMillingOp->allowance_bottom->val);


		}
		else
		{

			pocket->SetFinishAllowanceSide(2.0); //FIXME:
			if(pocket->GetRelDepth()<pocket->GetToolRadius())
			{
				pocket->SetMaxOneInfeedDepth(pocket->GetRelDepth());
			}
			else 
			{
				pocket->SetMaxOneInfeedDepth(.8* pocket->GetToolRadius());
			}
		}


		int nToolnum = program->DefineTool(Seimens840D::Endmill, 100,  pocket->GetToolRadius(), 0);
		pocket->SetToolNum(nToolnum);

		std::vector<IFeatureCycle::EnumErrors> errors;
		pocket->Verify(errors);
		// Would help to have tool length to make sure depth is achievable
		return pocket;
	}

	return NULL;
}
SiemensPocketBasicRectangular::SiemensPocketBasicRectangular(Seimens840D * owner, CWorldModel & wm):_parent(owner), PocketRectangular(wm)
{
	//SetName("SiemensPocketBasicRectangular");
	SetAbsDepth(NaN);						// absolute signed depth of pocket
	SetRelDepth(NaN);						// relative depth of pocket
	SetCenterAbscissa(NaN);					// x centerpoint (absolute)
	SetCenterOrdinate(NaN);					// y centerpoint (absolute)
	SetLength(NaN);							//Pocket length (enter without sign)
	SetWidth(NaN);							// Pocket width (enter without sign)
	SetCornerRadius(NaN);					// Corner radius (enter without sign)

	/*Rotational Angle between the longitudinal axis of the rectangle and the first axis of
	the plane (abscissa, enter without sign);*/
	SetAngle(0);							// range 0<=angle<180
	SetMaxOneInfeedDepth(NaN);				// Maximum infeed depth for one infeed (enter without sign)

	SetFinishAllowanceSide(NaN);				 // Finishing allowance at the pocket edge
	SetFinishAllowanceBottom(NaN);				 // Finishing allowance at the pocket bottom
	SetFinishFeed(NaN);						// Feedrate for finishing
	SetFinishSpeed(NaN);					// Speed for finishing
}

#define LogError(X,Y) { errors.push_back(X); OUTPUT_DEBUG_STRING(StrFormat("%s %s\n", #X, #Y)); }
HRESULT  SiemensPocketBasicRectangular::Verify(std::vector<EnumErrors> &errors)
{
	if(NaN==GetAbsDepth()) 
		LogError(E_UNINIITALIZED_PARAMETER,AbsDepth);
	if(NaN== GetRelDepth())
		LogError(E_UNINIITALIZED_PARAMETER,RelDepth);
	if(GetReferencePlane()==NaN )
		LogError(E_UNINIITALIZED_PARAMETER,GetReferencePlane);
	if(GetCenterAbscissa()==NaN )
		LogError(E_UNINIITALIZED_PARAMETER,GetCenterAbscissa);
	if(GetCenterOrdinate()==NaN)
		LogError(E_UNINIITALIZED_PARAMETER,GetCenterOrdinate);
	if(GetLength()==NaN )
		LogError(E_UNINIITALIZED_PARAMETER,GetLength);
	if(GetWidth()==NaN) 
		LogError(E_UNINIITALIZED_PARAMETER,GetWidth);
	if( GetMaxOneInfeedDepth()==NaN)
		LogError(E_UNINIITALIZED_PARAMETER,GetMaxOneInfeedDepth);

	if(GetLength()< 0) 
		LogError(E_LENGTH_NOT_POSITIVE,GetLength);
	if(GetWidth()< 0) 
		LogError(E_WIDTH_NOT_POSITIVE,GetWidth);
	if(GetCornerRadius()< 0) 
		LogError((IFeatureCycle::EnumErrors) E_FAIL, GetCornerRadius);
	if(GetToolRadius() < GetCornerRadius()) 
		LogError((IFeatureCycle::EnumErrors) E_FAIL, GetCornerRadius);
	if(GetMaxOneInfeedDepth() > (2.0 * GetToolRadius())) //warning
		LogError(E_Z_STEP_LARGER_THAN_TOOL_DIAMETER, GetMaxOneInfeedDepth);

	if(GetToolRadius() < GetCornerRadius()) 
		LogError((IFeatureCycle::EnumErrors) E_FAIL, GetCornerRadius);
	if(GetMaxOneInfeedDepth() <=0) 
		LogError(E_LENGTH_NOT_POSITIVE, GetMaxOneInfeedDepth);

#if 0
	if(GetFinishAllowance()<0)
		LogError(E_FINISHING_ALLOWANCE_NOT_POSITIVE,GetFinishAllowance);
#endif
	if(errors.size()>0)
		return E_FAIL;
	return S_OK;
}

CString SiemensPocketBasicRectangular::ToGCode(int nDialect, int eRoughFinish)
{
	CString line, block;
	
	block.AppendFormat("\n\n;%s\n", GetComment()); // feature-based operation  comment

	block+=_parent->ToolChange(this->GetToolNum());

	block+=_parent->NewBlock(StrFormat("G0  F2000 X%-.*f Y%-.*f Z%-.*f\n", 
		_wm.nFPrecision, GetCenterAbscissa(), _wm.nFPrecision, GetCenterOrdinate(), _wm.nFPrecision, GetRetractPlane())); // Approach start position
	block+=_parent->NewBlock(StrFormat("F%d%s\n", (long) GetFeedrate(), _parent->SpindleCommand ( GetSpindleSpeed())));

	double dTolerance = gWm.GetGlobalTolerance();
	if(dTolerance<0)
		dTolerance=0.001;

	int nCmd = 102001;
	if(GetCycleType() == Roughing)
		nCmd = 102003;

	block.AppendFormat("; Tolerance definition\n"); 
	block+=_parent->NewBlock(StrFormat("CYCLE832(%f,%d)\n",  dTolerance, nCmd));



	line+="POCKET1(";
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetRetractPlane() );  // Retraction plane (absolute)
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetReferencePlane()  );  // Reference plane (absolute)
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetSafetyPlane() );  // Safety clearance (to be added to the reference plane, enter without sign)
	if(GetAbsDepth()!=NaN)
		line.AppendFormat("%.*f, ,", _wm.nFPrecision, GetAbsDepth());  //Depth (absolute)
	else if(GetRelDepth()!=NaN)
		line.AppendFormat(" , %.*f,", _wm.nFPrecision, GetRelDepth());  //Depth (relative)
	else
		line.AppendFormat("GetAbsDepth ERROR! ,GetRelDepth ERROR!,", _wm.nFPrecision, GetRelDepth());  //Depth (relative)

	line.AppendFormat("%.*f,", _wm.nFPrecision, GetLength());  
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetWidth());  
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetCornerRadius());			//
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetCenterAbscissa());		// Center point, abscissa (absolute)
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetCenterOrdinate());		// Center point, ordinate (absolute)

	line.AppendFormat("%.*f,", _wm.nFPrecision, GetAngle());				//  Angle between the longitudinal axis of the rectangle and the first axis ofthe plane (abscissa, enter without sign);
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetInfeedFeedrate());		// Feedrate for depth infeed
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetFeedrate());				// _Feedrate for surface machining


	line.AppendFormat("%.*f,", _wm.nFPrecision, GetMaxOneInfeedDepth() );	// FIXME FIXME Maximum infeed depth (enter without sign)
	line.AppendFormat("%d", GetMillingDirection() );						// Mill direction for machining the pocket 2=G2, 3=G3
	line.AppendFormat("%.*f,", _wm.nFPrecision, GetFinishAllowanceSide());	// Finishing allowance at the pocket edge (enter without sign)
	line.AppendFormat("%d", GetCycleType() );								// Machining type: (enter without sign)
	if(GetCycleType() == Finishing)
	{
		line.AppendFormat(",");

		line.AppendFormat("%.*f,", _wm.nFPrecision, GetFinishAllowanceBottom()); // FIXME: looks wrong Maximum infeed depth for finishing
		line.AppendFormat("%.*f,", _wm.nFPrecision, GetFinishFeed());		//Feedrate for finishing
		line.AppendFormat("%8.3f", fabs(GetFinishSpeed()));						//Speed for finishing
	}
	line+=")\n";
	block+=line;
	return block;
}

//////////////////////////////////////////////////////////////////////////////////////////
SiemensPocketRectangular::SiemensPocketRectangular(Seimens840D * owner, CWorldModel & wm): _parent(owner), PocketRectangular(wm)
{
	//SetName("SiemensPocketRectangular");
}

HRESULT  SiemensPocketRectangular::Verify(std::vector<EnumErrors> &errors)
{
	if(GetLength()< 0) 
		errors.push_back(E_LENGTH_NOT_POSITIVE);
	if(GetWidth()< 0) 
		errors.push_back(E_WIDTH_NOT_POSITIVE);
	if(GetCornerRadius()< 0) 
		errors.push_back(E_CORNER_RADIUS_NOT_POSITIVE);
	if(GetFinishAllowance()<0)
		errors.push_back(E_FINISHING_ALLOWANCE_NOT_POSITIVE);
	if(errors.size()>0)
		return E_FAIL;
	return S_OK;
}

CString SiemensPocketRectangular::ToGCode(int nDialect, int eRoughFinish)
{


	CString tmp;
#if 0
	CString szFPrecision="%8.3f,";
	tmp.AppendFormat("G17"); // G17=xyplane
	tmp.AppendFormat(" G90"); //  G90 absolute distance ,  
	tmp.AppendFormat(" G54"); // G54 use preset work coordinate system 1,
	tmp.AppendFormat(" G94\n"); // G94 units per minute feed rate mode 

	tmp.AppendFormat("G0  F2000 X%-8.3f Y%-8.3f Z%-8.3f\n", GetCenterAbscissa(), GetCenterOrdinate(), GetRetractPlane()); // Approach start position

	tmp+="CYCLE71(";
	tmp.AppendFormat("%.*f,", _wm.nFPrecision, GetRetractPlane() );  // Retraction plane (absolute)
	tmp.AppendFormat("%.*f,", _wm.nFPrecision, GetReferencePlane()  );  // Reference plane (absolute)
	tmp.AppendFormat("%.*f,", _wm.nFPrecision, GetSafetyPlane() );  // Safety clearance (to be added to the reference plane, enter without sign)
	if(GetAbsDepth()!=0)
		tmp.AppendFormat("%.*f,", _wm.nFPrecision, GetAbsDepth());  //Depth (absolute)
	else
		tmp.AppendFormat(" ,");  //Depth (absolute)

	if(GetRelDepth()!=0)
		tmp.AppendFormat("%.*f,", _wm.nFPrecision, GetRelDepth());  //Depth (relative)
	else
		tmp.AppendFormat(" ,");  //Depth (absolute)

	tmp.AppendFormat("%.*f,", _wm.nFPrecision, GetLength());  
	tmp.AppendFormat("%.*f,", _wm.nFPrecision, GetWidth());  
	tmp.AppendFormat("%.*f,", _wm.nFPrecision, GetCornerRadius());			//
	tmp.AppendFormat("%.*f,", _wm.nFPrecision, GetCenterAbscissa());		// Center point, abscissa (absolute)
	tmp.AppendFormat("%.*f,", _wm.nFPrecision, GetCenterOrdinate());		// Center point, ordinate (absolute)

	tmp.AppendFormat("%.*f,", _wm.nFPrecision, GetAngle());					//  Angle between the longitudinal axis of the rectangle and the first axis ofthe plane (abscissa, enter without sign);
	tmp.AppendFormat("%.*f,", _wm.nFPrecision, GetMaxInfeedDepth() );		// Cutting Depth: Maximum infeed depth (enter without sign)
	tmp.AppendFormat("%.*f,", _wm.nFPrecision, GetFinishAllowance());		// Finishing allowance at the pocket edge (enter without sign)
	tmp.AppendFormat("%.*f,", _wm.nFPrecision, GetFinishAllowanceBase());	// Finishing allowance at the pocket edge (enter without sign)
	tmp.AppendFormat("%.*f,", _wm.nFPrecision, GetFeedrate());				// _Feedrate for surface machining
	tmp.AppendFormat("%.*f,", _wm.nFPrecision, GetInfeedFeedrate());		// Feedrate for depth infeed


	tmp.AppendFormat("%d", GetMillingDirection() );				// Mill direction for machining the pocket 2=G2, 3=G3
	tmp.AppendFormat("%d", GetCycleType() );					// Machining type: (enter without sign)
	if(GetCycleType() == Roughing)
	{
		tmp+=")\n";
		return tmp;

	}
	tmp.AppendFormat("%.*f,", _wm.nFPrecision, GetMaxInfeedDepth());		// Maximum infeed depth for finishing
	tmp.AppendFormat("%.*f,", _wm.nFPrecision, GetFinishFeed());			//Feedrate for finishing
	tmp.AppendFormat("%.*f", _wm.nFPrecision, GetFinishSpeed());			//Speed for finishing

	tmp+=")\n";
#endif
	return tmp;
}

CString SiemensPocketRectangular::TestCode()
{

	return ToGCode(0);


}

//////////////////////////////////////////////////////////////////////////////////////////
