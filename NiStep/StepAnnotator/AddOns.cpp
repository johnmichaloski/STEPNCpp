#include "StdAfx.h"
#include "AddOns.h"
#include "Misc.h"
#import <msxml6.dll>
#include "linalg3dII.h"

CAddons::CAddons(IStepNodePtr project) :  _project(project)
{

}
	
HRESULT CAddons::DefineGlobalTolerance(double dTolerance)
{
	if(dTolerance<=0.0)
		return E_INVALIDARG;
	if (_project==NULL)
		return E_FAIL;

	IStepNodePtr workpiece= _project->GetAttribute(bstrFormat(_T("/its_workpieces[%d]"), 0));
	if (workpiece==NULL)
		return E_FAIL;

	return workpiece->SetAttributeValue(bstr_t(L"global_tolerance"), bstrFormat(_T("%.3f"), dTolerance));
}

HRESULT CAddons::DefineBlockWorkpiece(IStepNodePtr _project,  LPCTSTR name, double x, double y, double z, 
								   LPCTSTR stdId, LPCTSTR materialID)
{

	IStepNodePtr workpiece;

	if (_project==NULL)
		return E_FAIL;

	INodeListPtr its_workpieces=_project->SelectNodeList(_T("its_workpieces"));

	if(its_workpieces->size() < 1)
	{
		workpiece= its_workpieces->push_back(_bstr_t(L"workpiece"), _bstr_t(L"Eworkpiece"));
	}
	else
		workpiece= _project->GetAttribute(bstrFormat(_T("/its_workpieces[%d]"), 0));

	try
	{
		// FIXME: should I replace...
		if(stdId!=NULL)
			workpiece->SetAttributeValue(_bstr_t(L"its_material/standard_identifier"), stdId);
		if(materialID!=NULL)
			workpiece->SetAttributeValue(_bstr_t(L"its_material/material_identifier"), materialID);
		if(name!=NULL)
			workpiece->SetAttributeValue(_bstr_t(L"its_bounding_geometry/_Eblock/name"), name);

		workpiece->SetAttributeValue(_bstr_t(L"its_bounding_geometry/_Eblock/x"), bstrFormat(_T("%.3f"), x));
		workpiece->SetAttributeValue(_bstr_t(L"its_bounding_geometry/_Eblock/y"), bstrFormat(_T("%.3f"), y));
		workpiece->SetAttributeValue(_bstr_t(L"its_bounding_geometry/_Eblock/z"), bstrFormat(_T("%.3f"), z));
		workpiece->SetAttributeValue(_bstr_t(L"its_bounding_geometry/_Eblock/position/name"), _T("bottom-left-origin"));
		workpiece->SetAttributeValue(_bstr_t(L"its_bounding_geometry/_Eblock/position/location/name"), _T("origin"));
		workpiece->SetAttributeValue(_bstr_t(L"its_bounding_geometry/_Eblock/position/location/coordinates"), _T("0,0,0"));
		workpiece->SetAttributeValue(_bstr_t(L"its_bounding_geometry/_Eblock/position/axis/name"), _T("direction"));
		workpiece->SetAttributeValue(_bstr_t(L"its_bounding_geometry/_Eblock/position/axis/direction_ratios"), _T("0,0,1"));
		workpiece->SetAttributeValue(_bstr_t(L"its_bounding_geometry/_Eblock/position/ref_direction/name"), _T("ref_direction"));
		workpiece->SetAttributeValue(_bstr_t(L"its_bounding_geometry/_Eblock/position/ref_direction/direction_ratios"), _T("1,0,0"));
	}
	catch(...)
	{
		return E_FAIL;
	}
	return S_OK;
}

void CAddons::DefineAxis2_placement_3d(IStepNodePtr pStep, 
										  CString steppath, 
										  CString name,
										  LPCTSTR position,
										  LPCTSTR axis,
										  LPCTSTR ref_direction )
{

	pStep->SetAttributeValue(bstrFormat(_T("%s/name"), (LPCTSTR) steppath), _bstr_t(name));

	pStep->SetAttributeValue(bstrFormat(_T("%s/location/name"), (LPCTSTR) steppath), _T("LOCATION"));
	pStep->SetAttributeValue(bstrFormat(_T("%s/location/coordinates[-1]"), (LPCTSTR) steppath), _T("0.0"));
	pStep->SetAttributeValue(bstrFormat(_T("%s/location/coordinates[-1]"), (LPCTSTR) steppath), _T("0.0"));
	pStep->SetAttributeValue(bstrFormat(_T("%s/location/coordinates[-1]"), (LPCTSTR) steppath), _T("0.0"));
	pStep->SetAttributeValue(bstrFormat(_T("%s/location/coordinates"), (LPCTSTR) steppath),_bstr_t((LPCTSTR) position) );

	pStep->SetAttributeValue(bstrFormat(_T("%s/axis/name"), (LPCTSTR) steppath), _T("AXIS"));
	pStep->SetAttributeValue(bstrFormat(_T("%s/axis/direction_ratios[-1]"), (LPCTSTR) steppath), _T("0.0"));
	pStep->SetAttributeValue(bstrFormat(_T("%s/axis/direction_ratios[-1]"), (LPCTSTR) steppath), _T("0.0"));
	pStep->SetAttributeValue(bstrFormat(_T("%s/axis/direction_ratios[-1]"), (LPCTSTR) steppath), _T("1.0"));
	pStep->SetAttributeValue(bstrFormat(_T("%s/axis/direction_ratios"), (LPCTSTR) steppath), _bstr_t((LPCTSTR) axis) );

	pStep->SetAttributeValue(bstrFormat(_T("%s/ref_direction/name"), (LPCTSTR) steppath), _T("REF_DIRECTION"));
	pStep->SetAttributeValue(bstrFormat(_T("%s/ref_direction/direction_ratios[-1]"), (LPCTSTR) steppath), _T("1.0"));
	pStep->SetAttributeValue(bstrFormat(_T("%s/ref_direction/direction_ratios[-1]"), (LPCTSTR) steppath), _T("0.0"));
	pStep->SetAttributeValue(bstrFormat(_T("%s/ref_direction/direction_ratios[-1]"), (LPCTSTR) steppath), _T("0.0"));
	pStep->SetAttributeValue(bstrFormat(_T("%s/ref_direction/direction_ratios"), (LPCTSTR) steppath), _bstr_t((LPCTSTR) ref_direction) );

}
void CAddons::DefineStepNcImplicitTolerance(IStepNodePtr pStep, 
											CString steppath, 
											LPCTSTR upper_limit,
											LPCTSTR lower_limit,
											LPCTSTR significant_digits )
{
#if 0
	// selection is tricky - this is wrong but it "works"...
	CVarDefPtr vardef = pStep->SelectAttribute(steppath);
	//Store(vardef,  (IStepNode *) new Eplus_minus_value()); // remove old node
	//pStep->AddAttribute(StrFormat("%s{%s}", steppath, "plus_minus_value"));
	pStep->SetAttributeValue(bstrFormat(_T("%s/upper_limit"), steppath), upper_limit);
	pStep->SetAttributeValue(bstrFormat(_T("%s/lower_limit"), steppath), lower_limit);
	pStep->SetAttributeValue(bstrFormat(_T("%s/significant_digits"), steppath), significant_digits);
#endif
}

#if 0
HRESULT STDMETHODCALLTYPE  CAddons::ParseXMLString(CString xmlstring, CString toptag)
{
	LONG atom;
	querypath.Open(xmlfilename);
	try{

		MSXML2::IXMLDOMNodeListPtr pnl = pXMLDom->selectNodes((LPCTSTR) toptag);
		// Should be 1 item...
		for(int i=0; i< pnl->length; i++)
		{
			MSXML2::IXMLDOMNodePtr pNode;
			pNode = querypath.DomPtr()->selectSingleNode((LPCTSTR) StrFormat(_T("/PROJECT/Entities/Entity[%d]"), i+1))->firstChild;
			CString sEntityType = (LPCTSTR) pNode->baseName;

			if(sEntityType==_T("Point"))
			{
//				Point(DVal(pNode->text,0,_T(" ")), DVal(pNode->text,1,_T(" ")),DVal(pNode->text,2,_T(" ")), &atom);
			}
			else if(sEntityType==_T("Line"))
			{
				MSXML2::IXMLDOMNodePtr pStart = pNode->selectSingleNode(_T("Start"));
				MSXML2::IXMLDOMNodePtr pEnd = pNode->selectSingleNode(_T("End"));
				//Line(DVal(pStart->text,0,_T(" ")), DVal(pStart->text,1,_T(" ")),DVal(pStart->text,2,_T(" ")),
				//	DVal(pEnd->text,0,_T(" ")), DVal(pEnd->text,1,_T(" ")),DVal(pEnd->text,2,_T(" ")), &atom);

			}
			else if(sEntityType==_T("Arc"))
			{
				MSXML2::IXMLDOMNodePtr pStart = pNode->selectSingleNode(_T("Start"));
				MSXML2::IXMLDOMNodePtr pEnd = pNode->selectSingleNode(_T("End"));
				MSXML2::IXMLDOMNodePtr pCenter = pNode->selectSingleNode(_T("Center"));
				MSXML2::IXMLDOMNodePtr pRadius = pNode->selectSingleNode(_T("Center"));
				double dRadius = atof( pNode->selectSingleNode(_T("Radius"))->text);
				double dStartAngle = atof( pNode->selectSingleNode(_T("StartAngle"))->text);
				double dSweepAngle = atof( pNode->selectSingleNode(_T("SweepAngle"))->text);
				//Arc(DVal(pCenter->text,0,_T(" ")), DVal(pCenter->text,1,_T(" ")),DVal(pCenter->text,2,_T(" ")),
				//	dRadius, dStartAngle, dSweepAngle, &atom);
#if 0
				Helix(
					DVal(pStart->text,0,_T(" ")), DVal(pStart->text,1,_T(" ")), DVal(pStart->text,2,_T(" ")),
					DVal(pEnd->text,0,_T(" ")), DVal(pEnd->text,1,_T(" ")), DVal(pEnd->text,2,_T(" ")),
					DVal(pCenter->text,0,_T(" ")), DVal(pCenter->text,1,_T(" ")), DVal(pCenter->text,2,_T(" ")),
					dRadius, dStartAngle, dSweepAngle, &atom);
#endif
			}
		}
	}
	catch(...)
	{
		DebugBreak();
		continue;
	}

	return S_OK;
}
#endif


Line3D CAddons::DeriveLine(IStepNodePtr pLine)
{
	//line.pnt.coordinates[0..2]						length_measure
	//line.dir.orientation.direction_ratios[0..2]		length_measure
	//line.dir.magnitude								length_measureif

	Line3D line;

	if(pLine->GetClassname() != _bstr_t(L"line"))
		throw std::exception("Bad Step Line values");

	try 
	{

		line.e1[0] = (double) pLine->GetAttributeValue(_bstr_t(L"/pnt/coordinates[0]"), (double) 0.0);
		line.e1[1] = (double) pLine->GetAttributeValue(_bstr_t(L"/pnt/coordinates[1]"), (double) 0.0);
		line.e1[2] = (double) pLine->GetAttributeValue(_bstr_t(L"/pnt/coordinates[2]"), (double) 0.0);

		line.e2[0] = line.e1[0] + ((double) pLine->GetAttributeValue(_bstr_t(L"/dir/magnitude"), (double) 0.0))
			* ((double) pLine->GetAttributeValue(_bstr_t(L"/dir/orientation/direction_ratios[0]"), (double) 0.0));

		line.e2[1] = line.e1[1] + ((double) pLine->GetAttributeValue(_bstr_t(L"/dir/magnitude"), (double) 0.0))
			* ((double) pLine->GetAttributeValue(_bstr_t(L"/dir/orientation/direction_ratios[1]"), (double) 0.0));

		line.e2[2] = line.e1[2] + ((double) pLine->GetAttributeValue(_bstr_t(L"/dir/magnitude"), (double) 0.0))
			* ((double) pLine->GetAttributeValue(_bstr_t(L"/dir/orientation/direction_ratios[2]"), (double) 0.0));

	}
	catch(...)
	{
		throw std::exception("Bad Step Line values");

	}

	return line;
}


/** note v1 and v2 dont have to be nomalised, thanks to minorlogic for telling me about this:
* http://www.euclideanspace.com/maths/algebra/vectors/angleBetween/minorlogic.htm
The quaternion in terms of axis-angle is:

q = cos(a/2) + i ( x * sin(a/2)) + j (y * sin(a/2)) + k ( z * sin(a/2))

where:

a=angle of rotation. 
x,y,z = vector representing axis of rotation. 

http://www.vb-helper.com/howto_find_angles.html

*/
double CAddons::AngleBetween(Vector v1,Vector v2, Vector normal) 
{ 
	v1=v1.Normalize();
	v2=v2.Normalize();
	REAL dDot = Dot(v1,v2);
	Vector c = Cross(v1,v2);
	REAL angle = acos(dDot);
	REAL axis = c.Norm(); 
	if(v1==v2)
		return 0;


	if(dDot>=1.0)
	{
		angle=0;
	}
	else if(dDot<-1.0)
	{
		angle=PI;
	}
	else
	{
		angle=acos(dDot);
	}

	/* now angle is in range 0..PI . Check if cross is antiparallel to
	normal. If so, true angle is between PI..2PI. Need to subtract
	from 2PI. */
	Vector v= Cross(v1, v2); 
	dDot=Dot(v, normal); 
	if (dDot < 0.0)
		angle = 2*PI - angle;
	if (angle > -(EPSILON) && angle < (EPSILON) )
	{
		angle = TwoPI; 
	}
	return angle;
} 




Arc3D CAddons::DeriveArc(IStepNodePtr pArc) 
{
	//radius.theoretical_size : toleranced_length_measure;
	//sweep_angle : plane_angle_measure;
	//placement.axis.direction_ratios  
	//placement.ref_direction.direction_ratios   
	if(pArc->GetClassname() != _bstr_t(L"partial_circular_profile"))
		throw std::exception("Bad partial_circular_profile node");

	Arc3D arc;
	arc.r = pArc->GetAttributeValue(_bstr_t(L"radius/theoretical_size"), _variant_t((double) 0.0));
	arc.ep1[0] = pArc->GetAttributeValue(_bstr_t(L"axis/direction_ratios[0]"), _variant_t((double) 0.0));
	arc.ep1[1] = pArc->GetAttributeValue(_bstr_t(L"axis/direction_ratios[1]"), _variant_t((double) 0.0));
	arc.ep1[2] = pArc->GetAttributeValue(_bstr_t(L"axis/direction_ratios[2]"), _variant_t((double) 0.0));

	arc.c[0] = arc.ep1[0] + arc.r * (double) pArc->GetAttributeValue(_bstr_t(L"ref_direction/direction_ratios[0]"), _variant_t((double) 0.0)); 
	arc.c[1] = arc.ep1[0] + arc.r * (double) pArc->GetAttributeValue(_bstr_t(L"ref_direction/direction_ratios[1]"), _variant_t((double) 0.0)); 
	arc.c[2] = arc.ep1[0] + arc.r * (double) pArc->GetAttributeValue(_bstr_t(L"ref_direction/direction_ratios[2]"), _variant_t((double) 0.0)); 
	arc.sw = pArc->GetAttributeValue(_bstr_t(L"sweep_angle"), _variant_t((double) 0.0));

	// FIXME: error checking on ARC values.

	Matrix m1 = RotateZ(arc.sw);
	Vector ep2 = m1 * Vector(arc.ep1[0], arc.ep1[1], arc.ep1[2]).Normalize();

	arc.ep2[0]= arc.c[0] + arc.r * ep2.x;
	arc.ep2[1]= arc.c[1] + arc.r * ep2.y;
	arc.ep2[2]= arc.c[2] + arc.r * ep2.z;

	// compute starting angle http://www.euclideanspace.com/maths/algebra/vectors/angleBetween/index.htm
	arc.sa = acos(Dot(Vector(arc.ep1[0], arc.ep1[1], arc.ep1[2]).Normalize(), Vector(arc.ep2[0], arc.ep2[1], arc.ep2[2]).Normalize()));

	return arc;


}

