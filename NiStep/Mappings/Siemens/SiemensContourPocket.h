
//
// SiemensContourPocket.h
//


// This software was developed by U.S. Government employees as part of
// their official duties and is not subject to copyright. No warranty implied 
// or intended.

#pragma once
#include "FeatureCycles.h"
#include "Siemens/Seimens840D.h"
#include "iges.h"
using namespace Iges;

//using namespace Cycle;

class SiemensContourPocket : public  IWorkCycle
{
public:
	SiemensContourPocket(IWorkCycles * owner);
	virtual ~SiemensContourPocket(){}
	FEATURECLASSDEF(SiemensContourPocket);  // prevents copy constructors

	virtual CString ToGCode(int nDialect, int eRoughFinish=0);
	virtual HRESULT DeriveParameters(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem) ;
	virtual CString ToString() ;

	BEGIN_STEP_MAP(SiemensContourPocket)

		ENTRYSET(_T("Type"),				Cycle::Compute,		Cycle::String,		_T(""), _T("ContourPocket"))
		ENTRY(_T("CornerRadius"),			Cycle::Feature,		Cycle::Length,		_T("orthogonal_radius/theoretical_size"))
		ENTRY(_T("StartAbscissa"),			Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[0]"))
		ENTRY(_T("StartOrdinate"),			Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[1]"))
		ENTRY(_T("MaxOneInfeedDepth"),		Cycle::Operation,	Cycle::Length,		_T("axial_cutting_depth"))
		ENTRY(_T("Stepdown"),				Cycle::Operation,	Cycle::Length,		_T("axial_cutting_depth"))
		ENTRY(_T("Stepover"),				Cycle::Operation,	Cycle::Length,		_T("radial_cutting_depth"))
		ENTRY(_T("MachiningType"),			Cycle::Compute,		Cycle::Long,		_T(""))

		ENTRY(_T("Location"),				Cycle::Feature,		Cycle::Vector,		_T("feature_placement/location/coordinates"))
		ENTRY(_T("Axis"),					Cycle::Feature,		Cycle::Vector,		_T("feature_placement/axis/direction_ratios"))
		ENTRY(_T("ReferenceDirection"),	Cycle::Feature,		Cycle::Vector,		_T("feature_placement/ref_direction/direction_ratios"))

		ENTRY(_T("FeatureName"),		Cycle::Feature,		Cycle::String,		_T("its_id"))
		ENTRY(_T("AbsDepth"),				Cycle::Feature,		Cycle::Position,	_T("depth/position/location/coordinates[2]"))
		ENTRY(_T("CornerRadius"),			Cycle::Feature,		Cycle::Length,		_T("orthogonal_radius/theoretical_size"))
		ENTRY(_T("CutterComp"),			Cycle::Operation,	Cycle::String,		_T("its_technology/feedrate_reference"))
		ENTRY(_T("Feature"),				Cycle::Feature,		Cycle::Classname,	_T(""))
		ENTRY(_T("FinishAllowanceDepth"),	Cycle::Operation,	Cycle::Length,		_T("allowance_bottom"))
		ENTRY(_T("FinishAllowanceSide"),	Cycle::Operation,	Cycle::Length,		_T("allowance_side"))
		ENTRY(_T("InfeedFeedrate"),		Cycle::Operation,	Cycle::Feed,		_T("its_technology/feedrate"))
		ENTRY(_T("Operation"),				Cycle::Operation,	Cycle::Classname,	_T(""))
		ENTRY(_T("MachiningStrategy"),		Cycle::Operation,	Cycle::Classname,	_T("its_machining_strategy"))
		ENTRY(_T("MaxOneInfeedDepth"),		Cycle::Operation,	Cycle::Length,		_T("axial_cutting_depth"))
		ENTRY(_T("PlacementRefDirection"), Cycle::Feature,		Cycle::Vector,		_T("feature_placement/ref_direction/direction_ratios"))
		ENTRY(_T("ReferencePlane"),		Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[2]"))
		ENTRY(_T("RetractPlane"),			Cycle::Operation,	Cycle::Position,	_T("retract_plane"))
		ENTRY(_T("StepSpeed"),			Cycle::Operation,	Cycle::Speed,		_T("its_technology/spindle"))
		ENTRY(_T("StartAbscissa"),			Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[0]"))
		ENTRY(_T("StartOrdinate"),			Cycle::Feature,		Cycle::Position,	_T("feature_placement/location/coordinates[1]"))
		ENTRY(_T("StepFeedrate"),			Cycle::Operation,	Cycle::Feed,		_T("its_technology/feedrate"))

		ENTRY(_T("Angle"),					Cycle::Compute,		Cycle::Angle,		_T("Angle = acos(Dot(Vector(1,0,0), PlacementRefDirection)) * 180.0 / M_PI;"))
		ENTRY(_T("CycleType"),				Cycle::Compute,		Cycle::Long,		_T("CycleType = 1.0 + Find(Operation, \"finish\")")) 
		ENTRY(_T("FeedrateSurface"),		Cycle::Compute,		Cycle::Feed,		_T("FeedrateSurface = StepFeedrate * 1000.0 * 60.0 ;"))
		ENTRY(_T("FeedrateInfeed"),		Cycle::Compute,		Cycle::Feed,		_T("FeedrateInfeed = StepFeedrate * 1000.0 * 60.0 ;"))
		ENTRY(_T("MillingDirection"),		Cycle::Compute,		Cycle::Long,		_T("MillingDirection = 1.0;")) 
		ENTRY(_T("RetractionTravel"),		Cycle::Compute,		Cycle::Length,		_T("RetractionTravel=0.0;")) 
		ENTRY(_T("SafetyPlane"),			Cycle::Compute,		Cycle::Length,		_T("SafetyPlane	= 2.0;"))
		ENTRY(_T("Speed"),					Cycle::Compute,		Cycle::Speed,		_T("Speed = fabs(SpindleSpeed);"))
		ENTRY(_T("SpindleDir"),			Cycle::Compute,		Cycle::Long,		_T("SpindleDir=( 3.0 + (SpindleSpeed>=0));")) 

		ENTRY(_T("CurveType"),				Cycle::Feature,		Cycle::Classname,	_T("feature_boundary/closed_profile_shape")) 

		ENTRY(_T("RoughingTolerance"),		Cycle::Compute,		Cycle::Length,		_T("")) 
		ENTRY(_T("FinishingTolerance"),	Cycle::Compute,		Cycle::Length,		_T("")) 

		ENTRY(_T("PocketRoutine"),			Cycle::Compute,		Cycle::String,		_T(""))

		ENTRY(_T("Contour"),				Cycle::Feature,		Cycle::Polyline,	_T("feature_boundary/closed_profile_shape/")) 
		


		LINK(StepNCTooling)
		LINK(SiemensTool)

	END_STEP_MAP(SiemensContourPocket)

	BEGIN_OUTPUT_PARAMETER_MAP(SiemensContourPocket)
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("G0  F2000 "), _T(""), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("X%.3f "), _T("StartAbscissa"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("Y%.3f "), _T("StartOrdinate"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("Z%.3f\n"), _T("RetractPlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("F%.3f"), _T("FeedrateInfeed"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("M0%d"), _T("SpindleDir"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("S%.3f\n"), _T("Speed"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Rough"),  _T("CYCLE832(%.3f,1003)\n"), _T("RoughingTolerance"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Finish"), _T("CYCLE832(%.3f,102001)\n"), _T("FinishingTolerance"), _T(""))

		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%s"), _T("PocketRoutine"), _T(""))

		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("CYCLE73("), _T(""), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%d, "), _T("MachiningType"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("\"%s\", "), _T("DrillProgram"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("\"%s\", "), _T("PocketMillProgram"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("\"%d\", "), _T("ToolNumber"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("RetractPlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("ReferencePlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("SafetyPlane"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("AbsDepth"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T(" , "), _T(""), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("MaxOneInfeedDepth"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("Stepover"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("FinishAllowanceSide"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("FinishAllowanceDepth"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("FeedrateSurface"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%.3f, "), _T("FeedrateInfeed"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("0, "), _T("MillingDirection"), _T(""))
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("0, "), _T(""), _T(""))  //Start point in first axis (only with manual selection of start point)
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("0, "), _T(""), _T(""))  //Start point in second axis (only with manual selection of start point)
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("0, "), _T(""), _T(""))  // Radius of center point path for insertion along helical path or max. insertion angle for oscillating insertion
//		STEPNC_OUTPUT_ENTRY(_T("Both"), _T(" , "), _T(""), _T(""))  // _DP1 real Insertion depth per 360° revolution on insertion along helical path
//		STEPNC_OUTPUT_ENTRY(_T("Both"), _T("%d "), _T("ToolOffsetNumber"), _T("")) //Tool offset number of stock removal tool (D number)
		STEPNC_OUTPUT_ENTRY(_T("Both"), _T(")\n"), _T(""), _T(""))
	END_OUTPUT_PARAMETER_MAP(SiemensContourPocket)

	BEGIN_VERIFY_PARAMETER_MAP(SiemensContourPocket)
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("CutterComp != \"TCP\"") , _T(""))
		STEPNC_VERIFY_ENTRY(_T("Warning"), _T("Both"), _T("RetractPlane == 0.0") ,_T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("RetractPlane <= ReferencePlane") , _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("ReferencePlane <= AbsDepth") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Toolradius >= CornerRadius") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Toolradius  > Width") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("FeedrateSurface <= 0.0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("FeedrateInfeed <= 0.0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Speed <= 0.0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("CornerRadius <= 0.0") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Toollength < (ReferencePlane - AbsDepth)") ,  _T(""))
		STEPNC_VERIFY_ENTRY(_T("Error"), _T("Both"), _T("Toollength < ((ReferencePlane - AbsDepth) - 10)") ,  _T(""))
	END_VERIFY_PARAMETER_MAP(SiemensContourPocket)
	CompositeCurve contour;

private:
	std::vector<Vector> vContourPoints;
	int _nMyContourNumber;

};
FEATURE_DECLARE_SMARTPOINTER(SiemensContourPocket);


//////////////////////////////////////////////////////////////////////////////////////////
SiemensContourPocket::SiemensContourPocket(IWorkCycles * owner):   IWorkCycle(owner)
{
	//SetName(_T("SiemensContourPocket"));
	_parent=owner;
	InitStepItems(&items);
	InitOutputs(this);
	InitTests(this);

}

CString SiemensContourPocket::ToString() 
{ 
	CString tmp = GetStepMap()->ToString(); 
	tmp += _T("Contour=");

	if(items.GetValue<tstring>(_T("CurveType")) ==_T("polyline"))
	{
		for(int i=0; i< vContourPoints.size(); i++) 
		{ 
			tmp += _T("<Point>");
			tmp += vContourPoints[i].ToString();
			tmp += _T("</Point>");
		}
	}
	tmp += _T("\n");
	return tmp;
}

CString SiemensContourPocket::ToGCode(int nDialect, int eRoughFinish)
{
	CString block;
	block+= StrFormat(_T("GOTOF ENDLABEL%d\n"), _nMyContourNumber);
	OutputDebugString(items.ToString());

	if(! items.IsDirty(_T("Axis")))
		items.SetVariable(_T("Axis"), Vector(0,0,1));
	if(! items.IsDirty(_T("ReferenceDirection")))
		items.SetVariable(_T("ReferenceDirection"), Vector(1,0,0));
	if(! items.IsDirty(_T("StartAbscissa")))
		items.SetVariable(_T("StartAbscissa"),(double) 0.0);
	if(! items.IsDirty(_T("StartOrdinate")))
		items.SetVariable(_T("StartOrdinate"), (double) 0.0);

	Matrix m = DirectionMatrix( items.GetValue<Vector>(_T("Axis")),	items.GetValue<Vector>(_T("ReferenceDirection")));

	//Vector axis = items.GetValue<Vector>(_T("Axis"));
	//Vector ref_dir = items.GetValue<Vector>(_T("ReferenceDirection"));
	//Vector cross_dir = Cross(axis, ref_dir);
	//Matrix m (ref_dir.x, ref_dir.y, ref_dir.z, 0,
	//	cross_dir.x, cross_dir.y, cross_dir.z, 0,
	//	axis.x, axis.y, axis.z, 0,
	//	0,0,0,1);
	double startx = items.GetValue<double>(_T("StartAbscissa"), 0.0);
	double starty = items.GetValue<double>(_T("StartOrdinate"), 0.0);
	
	block+= (LPCTSTR) StrFormat(_T("_CONTOUR%d: "),  _nMyContourNumber);
	if(items.GetValue<double>(_T("CornerRadius")) > 0)
		block+=  StrFormat(_T("G641 ADIS=%.3f\n"), items.GetValue<double>(_T("CornerRadius")));

	Vector lastpt(-1000,-10000,-1000);
	Matrix transform;
	for(int i=0; i< contour.size(); i++)
	{
		if(i== 0)
		{
		}
		if(i== contour.size()-1)
			block+= (LPCTSTR) StrFormat(_T("_ENDCONTOUR%d: "), _nMyContourNumber);

		Entity1 * entity = contour[i];
		Vector v=lastpt;
		if(entity->_type == Entity1::point_)
		{

			Point * entity = (Point * )  contour[i];
#if 0
			Vector v = m * Vector(entity->pt); //+ items.GetValue<Vector>(_T("Location"));
			v=v+Vector(startx, starty, 0.0);
#endif
			v = transform * Vector(entity->pt);
			block+=  StrFormat(_T("G1 X%.3f Y%.3f\n"), v.x,  v.y);

		}
		else  if(entity->IsLine())
		{
			Line * entity = (Line *)  contour[i];
			if(Vector(entity->_pt1)!=lastpt)
			{
				v= transform * Vector(entity->_pt1); //+ items.GetValue<Vector>(_T("Location"));
				block+=  StrFormat(_T("G1 X%.3f Y%.3f\n"), startx+ v.x, starty+ v.y);
				lastpt=v;
			}
			v = transform * Vector(entity->_pt2); //+ items.GetValue<Vector>(_T("Location"));
			block+=  StrFormat(_T("G1 X%.3f Y%.3f"), startx+ v.x, starty+ v.y);
			lastpt=v;
		}
		else  if(entity->IsArc())
		{
			Iges::Arc3D * entity = (Iges::Arc3D *)  contour[i];
			if(entity->Arc3D::sw>0)
				block+=  StrFormat(_T("G2 "));
			else
				block+=  StrFormat(_T("G3 "));
			
			v = transform * Vector(entity->Arc3D::ep2); //+ items.GetValue<Vector>(_T("Location"));
			block+=  StrFormat(_T("X%.3f Y%.3f CR=%.3f"), startx+ v.x, starty+ v.y,  entity->radius);
			lastpt=v;
		}
		else	if(entity->_type == Entity1::xform_)
		{
			transform = ((Iges::Transform *)  contour[i])->matrix;

		}	
		block+=  _T("\n");




	}
#if 0
	for(int i=0; i< vContourPoints.size(); i++)
	{
		if(i== 0)
		{
			if(items.GetValue<double>(_T("CornerRadius")) > 0)
				block+=  StrFormat(_T("G641 ADIS=%.3f\n"), items.GetValue<double>(_T("CornerRadius")));
			block+= (LPCTSTR) StrFormat(_T("_CONTOUR%d: G1 "),  _nMyContourNumber);
		}
		if(i== vContourPoints.size()-1)
			block+= (LPCTSTR) StrFormat(_T("_ENDCONTOUR%d: "), _nMyContourNumber);
		Vector v = m * vContourPoints[i]; //+ items.GetValue<Vector>(_T("Location"));

		block+=  StrFormat(_T("G1 X%.3f Y%.3f"), startx+ v.x, starty+ v.y);
		// Add CornerRadius
		//if(i!=0  && (items.GetValue<double>(_T("CornerRadius")) > 0))
		//	block+=  StrFormat(_T(" CR=%.3f"),  items.GetValue<double>(_T("CornerRadius")));
		block+=  _T(_T("\n"));
	}
#endif
	block+= StrFormat(_T("CONTOUR%d:\n"), _nMyContourNumber);
	block+= StrFormat(_T("CYCLE74(,\"_CONTOUR%d\",\"_ENDCONTOUR%d\")\n"), _nMyContourNumber, _nMyContourNumber);
	block+= StrFormat(_T("ENDLABEL%d:\n"), _nMyContourNumber);
	
	block+= IWorkCycle::ToGCode(nDialect, eRoughFinish) ;
	return block;
}

HRESULT SiemensContourPocket::DeriveParameters(IStepNodePtr pExecutable, IStepNodePtr pFeature, IStepNodePtr pOpItem) 
{
	IWorkCycle::DeriveParameters(pExecutable, pFeature, pOpItem);
	CCannedCycleItems * items = GetStepMap();  // initialize output for now...	

	items->SetVariable(_T("Angle"),  (double) acos(Dot(Vector(1,0,0),  items->GetValue<Vector>(_T("PlacementRefDirection")))) * 180.0 / M_PI);
	
	items->SetVariable(_T("FeedrateSurface"), items->GetValue<double>(_T("StepFeedrate")) * 1000.0 * 60.0) ;
	items->SetVariable(_T("FeedrateInfeed"), items->GetValue<double>(_T("StepFeedrate")) * 1000.0 * 60.0) ;

	items->SetVariable(_T("RetractPlane"), items->GetValue<double>(_T("ReferencePlane"))+ 10.0) ;
	items->SetVariable(_T("SafetyPlane"), 2.0) ;
	items->SetVariable(_T("Speed"), fabs(items->GetValue<double>(_T("StepSpeed")))) ;
	items->SetVariable(_T("SpindleDir"), 3.0 + (items->GetValue<double>(_T("StepSpeed"))>=0)) ;

	items->SetVariable(_T("Toolradius"), items->GetValue<double>(_T("Tooldiameter")) / 2.0) ;

	items->SetVariable(_T("ToolTypeNumber"), Seimens840D::GetToolNumber(items->GetValue<tstring>(_T("Tooltype")).c_str())) ;
	items->SetVariable(_T("ToolOffsetNumber"), 1) ;  //  Tool D Number


	_toolnum = _parent->LookupTool(items->GetValue<long>(_T("ToolTypeNumber")),
		items->GetValue<double>(_T("Toollength")),
		items->GetValue<double>(_T("Toolradius")),
		0);
	items->SetVariable(_T("ToolNumber"),(long) _toolnum) ;

	items->SetVariable(_T("RoughingTolerance"), (double) 0.01) ;
	items->SetVariable(_T("FinishingTolerance"), (double) 0.001) ;

	items->SetVariable(_T("SolidMachiningTool"), _T("2")) ;  // FIXME: Tool number string - this is fixed and is wrong.
	

	_nMyContourNumber=_parent->GetContourNumber();
	items->SetVariable(_T("PocketMillProgram"), (LPCTSTR)  StrFormat(_T("PocketMill%d"), _nMyContourNumber));
	items->SetVariable(_T("PocketRoutine"), (LPCTSTR) StrFormat(_T("REPEAT CONTOUR%d ENDLABEL%d\n"), _nMyContourNumber, _nMyContourNumber));

	/* Mill direction for machining the pocket: (enter without sign)
	Values: 
	0: Down-cut milling (corresponds to direction of spindle rotation)
	1: Down-cut milling
	2: with G2 (independent of spindle direction)
	3: with G3
	*/
	items->SetVariable(_T("MillingDirection"), (long) 2) ;

	/*
	Machining type: (enter without sign)
	_VARI integer
	Values:
	UNITS DIGIT: Machining process
		1: Roughing (solid machining) from solid material
		2: Roughing of residual material
		3: Finishing of edge
		4: Finishing of base
		5: Predrilling
	TENS DIGIT: Insertion strategy
		1: Perpendicular to G1
		2: On helical path
		3: Oscillation
	HUNDREDS DIGIT: Lift-off mode
		0: on retraction plane (_RTP)
		1: by amount of safety clearance (_SDIS) over reference plane(_RFP)
	THOUSANDS DIGIT: Start point
		1: automatic
		2: manual
	*/
	
	CString Operation =(LPCTSTR) items->GetValue<tstring>(_T("Operation")).c_str();
	items->SetVariable(_T("CycleType"),  1.0 + (Operation.Find(_T("finish"))>=0)) ;
	items->SetVariable(_T("MachiningType"), 1001) ;


	// general_closed_profile implies  closed_pocket
	IStepNodePtr pPocket =  pFeature;
	IStepNodePtr pProfile = pPocket->SelectNode(_T("feature_boundary")); 
	tstring szCurveType = items->GetValue<tstring>(_T("CurveType"));
	
	// Translate coordinate system in composite curve transform
	double startx = items->GetValue<double>(_T("StartAbscissa"));
	double starty = items->GetValue<double>(_T("StartOrdinate"));
	Matrix m = DirectionMatrix( items->GetValue<Vector>(_T("Axis")),	items->GetValue<Vector>(_T("ReferenceDirection")));
	Matrix t = Translate(Vector(startx, starty, 0));
	m=t * m;

	if(szCurveType == _T("polyline"))
	{
		IStepNodePtr  pCurve =  pProfile->SelectNode(_T("closed_profile_shape")); // closed_profile_shape.get();
		contour.AddEntity(Transform(m));

		// There will be points, as this is not a pointer, may be empty though
		//EListT<Ecartesian_pointPtr> points = pCurve->points;
		INodeListPtr points = pCurve->SelectNode(_T("points"))->GetNodeList();

		// Change vector of pointer to doubles to actual math vector
		for(int i=0; i< points->size(); i++) 
		{ 
			Vector v = FromComVector(points->Getitem(i)->ToVector(_bstr_t((LPCTSTR) _T("coordinates"))));
			//vContourPoints.push_back ( v); 
			contour.AddEntity(Point(v));

		}
		OutputDebugString(contour.ToXmlString());
#if 0
		if(vContourPoints[0]!= vContourPoints[vContourPoints.size()-1] )  // should  be since its a closed profile! 
		{


		}
#endif
	}
	else	if(szCurveType == _T("composite_curve"))
	{
			contour = items->GetValue<Iges::CompositeCurve>(_T("Contour"));
			contour.insert(contour.begin(), new Transform(m));
	}

	debugstream << GetStepMap()->ToString();
	return S_OK;

}

