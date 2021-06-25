//
// iges.cpp
//

#include "stdafx.h"

#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <ctype.h>

#include "iges.h"
#include "linalg3dII.h"
#include "Misc.h"
#include "QueryPath.h"

using namespace Iges;
//enum { hollerith_, integer_, real_};
#define hollerith_ 1
//std::vector<ColorMap> IGES_Globals::igesColorIndex ;
//struct Bogus
//{
//	Bogus()
//	{
//		IGES_Globals::igesColorIndex.push_back(ColorMap(0,0,0));
//		IGES_Globals::igesColorIndex.push_back(ColorMap(0,0,0)); 
//		IGES_Globals::igesColorIndex.push_back(ColorMap(1,0,0)); 
//		IGES_Globals::igesColorIndex.push_back(ColorMap(0,1,0)); 
//		IGES_Globals::igesColorIndex.push_back(ColorMap(0,0,1)); 
//		IGES_Globals::igesColorIndex.push_back(ColorMap(1,1,0)); // yellow 
//		IGES_Globals::igesColorIndex.push_back(ColorMap(1,0,1)); //Magenta=6, 
//		IGES_Globals::igesColorIndex.push_back(ColorMap(0,1,1)); // Cyan=7, 
//		IGES_Globals::igesColorIndex.push_back(ColorMap(1,1,1)); // White=8};
//	}
//};
//static Bogus bogus;

static TCHAR * sIgesUnits[]= { _T("INCH"), _T("MM"), _T(""), _T("FEET"), _T("MILES"), _T("METERS"), _T("KILOMETERS"), _T("MILS"), _T("MICRONS"), _T("CENTIMETERS"), _T("MICROINCHES")};



const TCHAR *  Entity::sBlankStatus[2] = {_T("Visible"), _T("Blank")};
const TCHAR *  Entity::sSubordinateStatus[4] = {_T("Independent"), _T("Physically Dependent"), _T("Logically Dependent"), _T("Both Physically and Logically Dependent") };
const TCHAR *  Entity::sEntityUseStatus[6] = {_T("Geometry"), _T("Annotation"), _T("Definition"), _T("Other"), _T("Logical/Positional"), _T("2D Parametric")};
const TCHAR *  Entity::sHierarchyStatus[3] = {_T("Global Top down"), _T("Global Defer"), _T("use hierarchy property")};
const TCHAR *  Entity::sLineFontPattern[6] = { _T(""), _T("solid"), _T("dashed"), _T("phantom"), _T("centerline"), _T("dotted=")};


static CString Hollerith(CString str) { return StrFormat(_T("%dH%s"), str.GetLength(), str); }
static CString DeHollerith(CString str){ return str.Mid(str.Find(_T("H"))+1); }

Entity * IgesModel::AddEntity(Entity * pEntity) 
{ 
	//gEntities.push_back(pEntity); 
	//pEntity->m_pModel=this; 
	return pEntity; 
}


void *  IgesModel::Write(CString szFilename)
{

	return NULL;
}
void IgesModel::Clear()
{


}

void * IgesModel::Read(CString szFilename)
{


	return NULL;

}
double  IgesModel::GetMax() 
{
	//ComputeMinsMaxs() ;
	return 0; //max(max(flDummy.GetMax().x,  flDummy.GetMax().y) ,flDummy.GetMax().z );

}

CString IgesModel::ToString()
{
	CString tmp;

	return tmp;

}


static CString AddSpacers(CString str, CString token)
{
	CString tmp;
	for(int i=0;i<str.GetLength()-1; i++)
	{
		tmp+=str[i];
		if(token==str[i] && token==str[i+1])
			tmp+=_T(" ");

	}
	return tmp;
}
void IgesModel::SetFilename(CString sFilename){	gIgesGlobals.sFilename=sFilename; gIgesGlobals.sProductIdReceiving=sFilename;}
void IgesModel::SetAuthor(CString sAuthor ){gIgesGlobals.sAuthor=sAuthor;}
void IgesModel::SetOrganization(CString sOrganization ){gIgesGlobals.sOrganization=sOrganization;}
void IgesModel::SetUnits(Units nUnits){gIgesGlobals.nUnits=nUnits; gIgesGlobals.sUnits = sIgesUnits[(int) nUnits];}
void IgesModel::SetDateTime(FILETIME ftFiletime){ CTime t(ftFiletime);  gIgesGlobals.sDateTime=t.Format( _T("%y%m%d.%H%M%S") ); }

ModelGlobals::ModelGlobals()
{
	vars.push_back(VarDef(_T("Parameter Delimiter") , hollerith_, (DWORD) &(this->sParameterDelimiter), _T("hollerith")));
	vars.push_back(VarDef(_T("Record Delimiter") , hollerith_, (DWORD) &(this->sRecordDelimiter), _T("hollerith")));
	vars.push_back(VarDef(_T("Product Id") , hollerith_, (DWORD) &(this->sProductId), _T("hollerith")));
	vars.push_back(VarDef(_T("Filename") , hollerith_, (DWORD) &(this->sFilename), _T("hollerith")));
	vars.push_back(VarDef(_T("System Id") , hollerith_, (DWORD) &(this->sSystemId), _T("hollerith")));
	vars.push_back(VarDef(_T("Preprocess Version") , hollerith_, (DWORD) &(this->sPreprocessVersion), _T("hollerith")));
	vars.push_back(VarDef(_T("IntegerBits") , integer_, (DWORD) &(this->nIntegerBits), _T("int")));
	vars.push_back(VarDef(_T("MaxPowerTenFloat") , integer_, (DWORD) &(this->nMaxPowerTenFloat), _T("int")));
	vars.push_back(VarDef(_T("FloatingSignificantDigits") , integer_, (DWORD) &(this->nFloatingSignificantDigits), _T("int")));
	vars.push_back(VarDef(_T("MaxPowerTenDouble") , integer_, (DWORD) &(this->nMaxPowerTenDouble), _T("int")));
	vars.push_back(VarDef(_T("FloatingSignificantDigitsDb") , integer_, (DWORD) &(this->nFloatingSignificantDigitsDbl), _T("int")));
	vars.push_back(VarDef(_T("ProductId Receiving") , hollerith_, (DWORD) &(this->sProductIdReceiving), _T("hollerith")));
	vars.push_back(VarDef(_T("ModelSpaceScale") , real_, (DWORD) &(this->dModelSpaceScale), _T("real")));
	vars.push_back(VarDef(_T("Units") , integer_, (DWORD) &(this->nUnits), _T("int")));
	vars.push_back(VarDef(_T("Units") , hollerith_, (DWORD) &(this->sUnits), _T("hollerith")));
	vars.push_back(VarDef(_T("MaxNumberLineWeight") , integer_, (DWORD) &(this->nMaxNumberLineWeight), _T("int")));
	vars.push_back(VarDef(_T("MaxLineWeightInUnits") , real_, (DWORD) &(this->dMaxLineWeightInUnits), _T("real")));
	vars.push_back(VarDef(_T("DateTime") , hollerith_, (DWORD) &(this->sDateTime), _T("hollerith")));
	vars.push_back(VarDef(_T("MinResolution") , real_, (DWORD) &(this->dMinResolution), _T("real")));
	vars.push_back(VarDef(_T("MaxCoordinateValue") , real_, (DWORD) &(this->dMaxCoordinateValue), _T("real")));

	vars.push_back(VarDef(_T("Author") , hollerith_, (DWORD) &(this->sAuthor), _T("hollerith")));
	vars.push_back(VarDef(_T("Organization") , hollerith_, (DWORD) &(this->sOrganization), _T("hollerith")));

	vars.push_back(VarDef(_T("IgesVersion") , integer_, (DWORD) &(this->nIgesVersion), _T("int")));
	vars.push_back(VarDef(_T("DraftingStandard") , integer_, (DWORD) &(this->nDraftingStandard), _T("int")));

	//vars.push_back(VarDef(_T("Special1") , hollerith_, (DWORD) &(this->sSpecial1), _T("hollerith")));
	//vars.push_back(VarDef(_T("Special2") , hollerith_, (DWORD) &(this->sSpecial2), _T("hollerith")));
	sParameterDelimiter=_T(","); sRecordDelimiter=_T(";");
	sFilename=_T("");; sProductIdReceiving=_T("");
	sSystemId=_T(""); sPreprocessVersion=_T("");
	nIntegerBits=32; nMaxPowerTenFloat=38; nFloatingSignificantDigits=15; nMaxPowerTenDouble=15; nFloatingSignificantDigitsDbl=308;
	dModelSpaceScale=1.0;
	nUnits=1; sUnits=_T("INCH");
	nMaxNumberLineWeight=8; dMaxLineWeightInUnits=0.0160000; 
	dMinResolution=0.0001;  nIgesVersion=11; nDraftingStandard=0;

}

CString ModelGlobals::ToString()
{
	CString tmp;
	for(UINT i=0; i<vars.size(); i++)
	{
		VarDef vardef = vars[i];
		//	CString str = vardef.Write ();
		//	tmp.AppendFormat(_T("%-20s = %s\n"), vardef.m_sName, vardef.Write());
	}
	return tmp;
}

/* creates a new entity according to lines1/2, and adds it at the end of the list */
/* TODO: checks on the lines1/2 to prevent crashes if malformed (too short) */

//Entity *IGES_ENTITIES::igesEntityAdd(CString line1, CString line2)
//{
//	Entity *newEntity=NULL;
//	int type;
//	try {
//
//		if(line1.GetLength()<80 || line2.GetLength() < 80)
//			return NULL;
//		//int type = atoi((LPCSTR) line1.Mid(0,8));
//		if( 1!= sscanf(line1.Mid(0,8).GetBuffer(), _T("%8d"), &type )) throw;
//
//		switch(type)
//		{
//		case 100:  newEntity= (Entity *) new CircularArcEntity;  break;
//		case 102:  newEntity= (Entity *) new CompositeCurveEntity;  break;
//		case 104:  newEntity= (Entity *) new ConicArcEntity;  break;  /* Tested*/
//		case 106:  newEntity= (Entity *) new CopiusDataEntity;  break;
//		case 108:  newEntity= (Entity *) new PlaneEntity;  break;
//		case 110:  newEntity= (Entity *) new LineEntity;  break;   /* Tested*/
//		case 112:  newEntity= (Entity *) new ParametricSplineEntity;  break;
//		case 114:  newEntity= (Entity *) new ParametricSplineSurfaceEntity;  break;	
//		case 116:  newEntity= (Entity *) new PointEntity;  break; /* Tested*/
//		case 124:  newEntity= (Entity *) new TransformEntity;  break; /* Tested*/
//		case 126:  newEntity= (Entity *) new BSplineEntity;  break; /* Tested*/
//
//		case 118:	newEntity= (Entity *) new RuledSurface;  break;  
//		case 120:	newEntity= (Entity *) new SurfaceRevolutionEntity;  break;
//		case 122:	newEntity= (Entity *) new TabulatedCylinderEntity;  break;
//		case 125:	newEntity= (Entity *) new FlashEntity;  break;
//		case 128:	newEntity= (Entity *) new NurbSurfaceEntity;  break;
//		case 130:	newEntity= (Entity *) new OffsetCurveEntity;  break;
//		case 142:	newEntity= (Entity *) new CurveParametricSurfaceEntity;  break;
//		case 144:	newEntity= (Entity *) new TrimmedSurfaceEntity;  break;
//
//		case 212:  newEntity= (Entity *) new GeneralNoteEntity;  break; /* Tested*/
//		case 214:  newEntity= (Entity *) new LeaderEntity;  break; /* Tested*/
//		case 216:  newEntity= (Entity *) new LinearDimensionEntity;  break; /* Tested*/
//		case 314:  newEntity= (Entity *) new ColorEntity;  break; /* Tested*/
//		case 406:  newEntity= (Entity *) new CPropertyTypeEntity;  break; /* Tested*/
//
//		default:
//			throw;
//
//		}
//		if(newEntity==NULL)
//			throw;
//
//		if( 1!= sscanf(line1.Mid(8,8).GetBuffer(), _T("%8d"), &newEntity->datarec )) throw;
//		if( 1!= sscanf(line1.Mid(16,8).GetBuffer(), _T("%8d"), &newEntity->structure )) throw;
//		if( 1!= sscanf(line1.Mid(24,8).GetBuffer(), _T("%8d"), &newEntity->linefontpattern )) throw;
//		if( 1!= sscanf(line1.Mid(32,8).GetBuffer(), _T("%8d"), &newEntity->level )) throw;
//		// FIXME: this is a problem - I think it is left blank? throw doesn't work?
//		//if( 1!= sscanf(line1.Mid(40,8).GetBuffer(), _T("%8d"), &newEntity->view )) throw;
//		if( 1!= sscanf(line1.Mid(48,8).GetBuffer(), _T("%8d"), &newEntity->pTransform )) throw;
//		if( 1!= sscanf(line1.Mid(64,8).GetBuffer(), _T("%8d"), &newEntity->status )) throw;
//		if( 1!= sscanf(line1.Mid(73,7).GetBuffer(), _T("%8d"), &newEntity->line )) throw;
//
//		if( 1!= sscanf(line2.Mid(8,8).GetBuffer(), _T("%8d"), &newEntity->lineweight )) throw;
//		if( 1!= sscanf(line2.Mid(16,8).GetBuffer(), _T("%8d"), &newEntity->color )) throw;
//		if( 1!= sscanf(line2.Mid(24,8).GetBuffer(), _T("%8d"), &newEntity->parameterlinecount )) throw;
//		if( 1!= sscanf(line2.Mid(32,8).GetBuffer(), _T("%8d"), &newEntity->nForm )) throw;
//
//		newEntity-> nBlank = 0;
//		newEntity-> nSubordinate= 0;
//		newEntity-> nUseFlag= 0;
//		newEntity-> nHierarchy= 0;
//
//		sscanf(line1.Mid(64,2).GetBuffer(), _T("%2d"), &newEntity->nBlank );
//		sscanf(line1.Mid(66,2).GetBuffer(), _T("%2d"), &newEntity->nSubordinate );
//		sscanf(line1.Mid(68,2).GetBuffer(), _T("%2d"), &newEntity->nUseFlag );
//		sscanf(line1.Mid(70,2).GetBuffer(), _T("%2d"), &newEntity->nHierarchy );
//		// Error check
//		// blank = 0,1   subordiante = 0,1,2,3 use=1,2,3,4,5,6 hierarch = 0,1,2
//
//		push_back(newEntity);
//	}
//	catch(...)
//	{
//		return NULL;
//	}
//	return newEntity;
//}

////////////////////////////////////////////////////////////////
// Entity


Entity::Entity()
{
	//	m_pModel =NULL;
	//	next=NULL;
	type=datarec=structure=linefontpattern=0;                      
	level=view=pTransform=labeldisplay=status=0;						
	seqnum=line=nForm=0;                   
	lineweight=color=parameterlinecount=0;
	nBlank=nSubordinate=nHierarchy=0;	
	nAssocPointers=0;
	m_vAssocPtrs.clear();
	nPropertyPointers=0;
	m_vPropertyPtrs.clear();
	//devars.push_back(VarDef(_T("Type") , integer_, (DWORD) &(this->type), _T("integer")));
	//devars.push_back(VarDef(_T("Datarec") , integer_, (DWORD) &(this->datarec), _T("integer")));
	//devars.push_back(VarDef(_T("Structure") , integer_, (DWORD) &(this->structure), _T("integer")));
	//devars.push_back(VarDef(_T("Linefontpattern") , integer_, (DWORD) &(this->linefontpattern), _T("integer")));
	//devars.push_back(VarDef(_T("Level") , integer_, (DWORD) &(this->level), _T("integer")));
	//devars.push_back(VarDef(_T("View") , integer_, (DWORD) &(this->view), _T("integer")));
	//devars.push_back(VarDef(_T("pTransform") , integer_, (DWORD) &(this->pTransform), _T("integer")));
	//devars.push_back(VarDef(_T("Labeldisplay") , integer_, (DWORD) &(this->labeldisplay), _T("integer")));
	//devars.push_back(VarDef(_T("Status") , integer_, (DWORD) &(this->status), _T("integer")));
	//devars.push_back(VarDef(_T("Seqnum") , integer_, (DWORD) &(this->seqnum), _T("integer")));

	//devars.push_back(VarDef(_T("Type") , integer_, (DWORD) &(this->type), _T("integer")));
	//devars.push_back(VarDef(_T("Lineweight") , integer_, (DWORD) &(this->lineweight), _T("integer")));
	//devars.push_back(VarDef(_T("Color") , integer_, (DWORD) &(this->color), _T("integer")));
	//devars.push_back(VarDef(_T("Parameterlinecount") , integer_, (DWORD) &(this->parameterlinecount), _T("integer")));
	//devars.push_back(VarDef(_T("nForm") , integer_, (DWORD) &(this->nForm), _T("integer")));
	//devars.push_back(VarDef(_T("Blank") , string_, (DWORD) &(this->sBlank), _T("CString")));
	//devars.push_back(VarDef(_T("Blank") , string_, (DWORD) &(this->sBlank), _T("CString")));
	//devars.push_back(VarDef(_T("Label") , string_, (DWORD) &(this->sBlank), _T("CString")));
	//devars.push_back(VarDef(_T("LabelNum") , string_, (DWORD) &(this->sBlank), _T("CString")));
	//devars.push_back(VarDef(_T("Seqnum") , integer_, (DWORD) &(this->seqnum), _T("integer")));

}

/////////////////////////////////////////////////////////////////////////////////////
// TransformEntity

Transform::Transform(double d11, double d12, double d13, double d14, 
								 double d21, double d22, double d23, double d24, 
								 double d31, double d32, double d33, double d34) 
{
	ID=124; m_szEntityName=_T("TransformEntity");
	matrix.Load (d11,  d12,  d13, d14, d21,  d22,  d23,  d24, d31,  d32,  d33,  d34, 0,  0,  0,  1);
	_type= xform_;
}

CString Transform::ToString() 
{
	CString str(_T("*********************** Parameter Data Record ***********************\n"));
	str.AppendFormat(_T("%20s\n"), _T("Transform"));
	str+=(LPCTSTR) matrix.ToString();
	return str;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// Point
Point::Point(double x1, double y1, double z1) : X1(pt[0]), Y1(pt[1]),Z1(pt[2])
{ 
	_type= point_;
	X1=x1; Y1=y1; Z1=z1;
	ID=116;  m_szEntityName=_T("Point");

}
Point::Point(Vector v) : X1(pt[0]), Y1(pt[1]),Z1(pt[2])
{
	_type= point_;
	X1=v.x; Y1=v.y; Z1=v.z;
	ID=116;  m_szEntityName=_T("Point");

}

Vector Point::GetPoint(float u, float v) 
{
	return  Vector(X1, Y1, Z1);
}

CString Point::ToXmlString()
{
	CString str = StrFormat(_T("<POINT> %9.5f  %9.5f %9.5f </POINT>\n"),  this->pt[0], this->pt[1], this->pt[2]);
	return str;
}
void Point::FromXmlString(CString str)
{

	CQueryPath query;
	if(FAILED(query.Read(str)))
		return;

	MSXML2::IXMLDOMNodePtr pNode = query.QueryNode(_T("Point"));
	if(pNode!=NULL)
	{
		long atom;
		pt[0]= DVal((LPCTSTR) pNode->text,0,_T(" "));
		pt[1]= DVal((LPCTSTR) pNode->text,1,_T(" "));
		pt[2]= DVal((LPCTSTR) pNode->text,2,_T(" "));

	}

	query.Close();

}

//double TransformEntity::DrawRaw(IPnts * pPts)
//{
//	pPts->MultTransform((Matrix &) *this);
//	return 0;
//}

/////////////////////////////////////////////////////////////////////////////////////
// CompositeCurveEntity - 102
CompositeCurve::CompositeCurve()
{ 
	type=ID=102;  m_szEntityName=_T("CompositeCurveEntity");
	//vars.push_back(VarDef(_T("type") , integer_, (DWORD) &(this->type), _T("integer")));
	//vars.push_back(VarDef(_T("n") , integer_, (DWORD) &(this->n), _T("integer")));
	////	vars.push_back(VarDef(_T("DictEntryPointers") ,  (DWORD) &(this->m_nPointers), _T("indices"), arrayint1D_, &(this->n)));
}

CString CompositeCurve::ToXmlString()
{
	CString str;
	str.AppendFormat(_T("%20s\n"), _T("CompositeCurveEntity"));

	for(UINT i=0; i<= (UINT) n && i<size(); i++) 
	{
		Entity1 *entity=at(i);
		str.AppendFormat(_T("%s"), entity->ToXmlString());
	}
	return str;

}
void CompositeCurve::AddXmlEntity(CString str)
{
	CQueryPath query;
	if(FAILED(query.Read(str)))
		return;

	MSXML2::IXMLDOMNodePtr pNode = query.QueryNode(_T("//Point"));
	for(int i=0; i<1; i++)
	{
		if(pNode !=NULL)
		{
			Point p;
			p.FromXmlString((LPCTSTR) pNode->Gettext());
			push_back( new Point(p)); 
			continue;
		}
		pNode = query.QueryNode(_T("//Line"));
		if(pNode!=NULL)
		{
			Line l;
			l.FromXmlString((LPCTSTR) pNode->xml);
			push_back( new Line(l)); 
			continue;
		}
		pNode = query.QueryNode(_T("//Arc"));
		if(pNode!=NULL)
		{
			Arc3D a;
			a.FromXmlString((LPCTSTR) pNode->xml);
			push_back( new Arc3D(a)); 
			continue;
		}
	}
	query.Close();

}


/////////////////////////////////////////////////////////////////////////////////////
// LineEntity - 110

Line::Line(double x1, double y1, double z1, double x2, double y2, double z2) 
{
	_type= line_;
	_pt1=Vector(x1,y1,z1); 
	_pt2=Vector(x2,y2,z2); 
	type=ID=110; m_szEntityName=_T("LineEntity");
}

Line::Line(Vector v1, Vector v2)  
{
	_type= line_;

	_pt1=v1;
	_pt2=v2;

}

Vector Line::GetPoint(float u, float v) 
{
	//Vector start(X1,Y1,Z1), end( X2,Y2,Z2);
	double dDist= Vector((_pt2-_pt1)).Len();
	return Lerp(_pt1,_pt2, u * dDist);
}


CString Line::ToXmlString()
{
	CString str;
	str.AppendFormat(_T("<LINE><START> %9.5f  %9.5f  %9.5f </START>\n"),  this->_pt1.x, this->_pt1.y, this->_pt1.z);
	str.AppendFormat(_T("<END>%9.5f  %9.5f  %9.5f</END></LINE>\n"),  this->_pt2.x, this->_pt2.y, this->_pt2.z);
	return str;
}
void Line::FromXmlString(CString str)
{	
	CQueryPath query;
	if(FAILED(query.Read(str)))
		return;

	MSXML2::IXMLDOMNodePtr pNode = query.QueryNode(_T("//Line/Start"));
	if(pNode!=NULL)
	{
		_pt1.x= DVal((LPCTSTR) pNode->text,0,_T(" "));
		_pt1.y= DVal((LPCTSTR) pNode->text,1,_T(" "));
		_pt1.z= DVal((LPCTSTR) pNode->text,2,_T(" "));

	}
	pNode = query.QueryNode(_T("//Line/End"));
	if(pNode!=NULL)
	{
		_pt2.x= DVal((LPCTSTR) pNode->text,0,_T(" "));
		_pt2.y= DVal((LPCTSTR) pNode->text,1,_T(" "));
		_pt2.z= DVal((LPCTSTR) pNode->text,2,_T(" "));

	}
	query.Close();
}
/////////////////////////////////////////////////////////////////////////////////////
// CircularArcEntity
CircularArc::CircularArc() 
{
	type=ID=100;  m_szEntityName=_T("CircularArcEntity");
	//vars.push_back(VarDef(_T("type") , integer_, (DWORD) &(this->type), _T("integer")));
	//vars.push_back(VarDef(_T("ZT") , real_, (DWORD) &(this->ZT), _T("real")));
	//vars.push_back(VarDef(_T("X1") , real_, (DWORD) &(this->X1), _T("real")));
	//vars.push_back(VarDef(_T("Y1") , real_, (DWORD) &(this->Y1), _T("real")));
	//vars.push_back(VarDef(_T("X2") , real_, (DWORD) &(this->X2), _T("real")));
	//vars.push_back(VarDef(_T("Y2") , real_, (DWORD) &(this->Y2), _T("real")));
	//vars.push_back(VarDef(_T("X3") , real_, (DWORD) &(this->X3), _T("real")));
	//vars.push_back(VarDef(_T("Y3") , real_, (DWORD) &(this->Y3), _T("real")));
}


Vector CircularArc::GetPoint(float u, float v) 
{
	Helix arc;
	arc.Init(Vector(X2,Y2,0), Vector(X3,Y3,0), Vector(X1,Y1,0), Vec(0,0,1), 0);
	double a=u*arc.angle;
	return arc.ArcPoint(a);
}


Arc3D::Arc3D(Vector ep1, Vector ep2, Vector center, REAL radius, REAL startangle, REAL sweepangle)
{
	_type= arc3d_;
	this->ep1=ep1;
	this->ep2=ep2;
	this->c=center;
	this->radius=radius;
	this->sa=startangle;
	this->sw=sweepangle;

}

CString Arc3D::ToXmlString()
{
	CString str;
	str.AppendFormat(_T("<ARC>"));
	str.AppendFormat(_T("<CENTER> %9.5f  %9.5f  %9.5f </CENTER>\n"),  this->c.x, this->c.y, this->c.z);
	str.AppendFormat(_T("<START>%9.5f  %9.5f  %9.5f</START>\n"),  this->ep1.x, this->ep1.y, this->ep1.z);
	str.AppendFormat(_T("<END>%9.5f  %9.5f  %9.5f</END>\n"),  this->ep2.x, this->ep2.y, this->ep2.z);
	str.AppendFormat(_T("<RADIUS>%9.5f  </RADIUS>\n"),  this->radius);
	str.AppendFormat(_T("<STARTANGLE>%9.5f  </STARTANGLE>\n"),  this->sa);
	str.AppendFormat(_T("<SWEEP>%9.5f  </SWEEP>\n"),  this->sw);
	str.AppendFormat(_T("</ARC>"));
	return str;
}
void Arc3D::FromXmlString(CString str)
{
	CQueryPath query;
	 Init();

	if(FAILED(query.Read(str)))
		return;

	// FIXME: could need to fill in missing parameters
	MSXML2::IXMLDOMNodePtr pNode = query.QueryNode(_T("//Arc/Start"));
	if(pNode!=NULL)
	{
		ep1.x= DVal((LPCTSTR) pNode->text,0,_T(" "));
		ep1.y= DVal((LPCTSTR) pNode->text,1,_T(" "));
		ep1.z= DVal((LPCTSTR) pNode->text,2,_T(" "));

	}
	pNode = query.QueryNode(_T("//Arc/End"));
	if(pNode!=NULL)
	{
		ep2.x= DVal((LPCTSTR) pNode->text,0,_T(" "));
		ep2.y= DVal((LPCTSTR) pNode->text,1,_T(" "));
		ep2.z= DVal((LPCTSTR) pNode->text,2,_T(" "));

	}
	pNode = query.QueryNode(_T("//Arc/Center"));
	if(pNode!=NULL)
	{
		c.x= DVal((LPCTSTR) pNode->text,0,_T(" "));
		c.y= DVal((LPCTSTR) pNode->text,1,_T(" "));
		c.z= DVal((LPCTSTR) pNode->text,2,_T(" "));

	}
	
	pNode = query.QueryNode(_T("//Arc/Radius"));
	if(pNode!=NULL)
		radius= DVal((LPCTSTR) pNode->text,0,_T(" "));

	pNode = query.QueryNode(_T("//Arc/StartAngle"));
	if(pNode!=NULL)
		sa= DVal((LPCTSTR) pNode->text,0,_T(" "));

	pNode = query.QueryNode(_T("//Arc/SweepAngle"));
	if(pNode!=NULL)
		sw= DVal((LPCTSTR) pNode->text,0,_T(" "));

	query.Close();
}


/////////////////////////////////////////////////////////////////////////////////////
// ConicArc
/*

A * XT*XT + B * XT * YT +  C * YT * YT + D * XT + E * YT + F = 0

A general conic curve C is the locus of all points (x,y) satisfying the equation: 
	 r x2 + s y2 + t x y + u x + v y + w = 0, 
	 
where: 

If 4 r s - t2 > 0, C is an ellipse. A special case occurs when r = s and t = 0, when C becomes a circle. 
If 4 r s - t2 < 0, C is a hyperbola. 
If 4 r s - t2 = 0, C is a parabola. A degenerate case occurs when r = s = t = 0, when C is a line. 

A bounded conic arc is defined as either of the following: 

A full ellipse (or a circle) C. 
The tuple  C, ps, pt, o  , where C is the supporting conic curve, with the arc endpoints 
being ps and pt (the source and target points, respectively). 
The orientation o indicates whether we proceed from ps to pt in a clockwise or 
in a counterclockwise direction. Note that C may also correspond to a line or to 
pair of lines - in this case o may specify a COLLINEAR orientation. 
*/
ConicArc::ConicArc()
{ 
	type=ID=104;  m_szEntityName=_T("ConicArcEntity");
	vars.push_back(VarDef(_T("type") , integer_, (DWORD) &(this->type), _T("integer")));
	vars.push_back(VarDef(_T("A") , real_, (DWORD) &(this->A), _T("real")));
	vars.push_back(VarDef(_T("B") , real_, (DWORD) &(this->B), _T("real")));
	vars.push_back(VarDef(_T("C") , real_, (DWORD) &(this->C), _T("real")));
	vars.push_back(VarDef(_T("D") , real_, (DWORD) &(this->D), _T("real")));
	vars.push_back(VarDef(_T("E") , real_, (DWORD) &(this->E), _T("real")));
	vars.push_back(VarDef(_T("F") , real_, (DWORD) &(this->F), _T("real")));
	vars.push_back(VarDef(_T("ZT") , real_, (DWORD) &(this->ZT), _T("real")));
	vars.push_back(VarDef(_T("X1") , real_, (DWORD) &(this->X1), _T("real")));
	vars.push_back(VarDef(_T("Y1") , real_, (DWORD) &(this->Y1), _T("real")));
	vars.push_back(VarDef(_T("X2") , real_, (DWORD) &(this->X2), _T("real")));
	vars.push_back(VarDef(_T("Y2") , real_, (DWORD) &(this->Y2), _T("real")));
}

Vector ConicArc::GetPoint(float u, float v) 
{

	// 	plotter.ConicArc(ConicArc(1, 0.0625,0.,0.25,0.,0.,-0.015625,0.,0.5,0.,0.5,0 ),0,0,0);
	if(nForm  == ConicArc::Ellipse)
	{
		double a=sqrt(-F/A), b=sqrt(-F/C);
		double angle1 = acos( X1/a), angle2 = acos( X2/a);
		if(angle1==angle2)
			angle2=angle2+ TwoPI;
		double d=angle1+ u*fabs(angle2-angle1);
		return Vector(D + a * cos(d), E + b * sin(d), ZT );
	}

	// plotter.ConicArc(ConicArc(3,0.,0.,1.,-1.,0.,0.,0.,0.25,-0.5,0.25,0.52),0,0,0);
	else if(nForm == ConicArc::Parabola)
	{
		if(A!=0 && E!=0)
		{
			double t1 = (X1<X2) ? X1 : X2;
			double t2 = (X1<X2) ? X2 : X1;
			double t=t1+ u*fabs(t2-t1);
			return Vector((X1<X2) ? t : -t, -(A/E) * t * t, ZT );
		}
		else if(C!=0 && D!=0)
		{
			double t1 = (Y1<Y2) ? Y1 : Y2;
			double t2 = (Y1<Y2) ? Y2 : Y1;
			double t=t1+ u*fabs(t2-t1);
			return Vector(-(C/D) * t * t, (Y1<Y2) ? t : -t, ZT );
		}

	}
	// plotter.ConicArc(ConicArc(2,16.,0.,-64.,0.,0.,-1.,0.,0.5,-0.22,0.5,0.22),0,0,0);
	else 	if(nForm == ConicArc::Hyperbola)
	{
		if((F* A) < 0 && (F*C) > 0)
		{
			double a=sqrt(-F/A), b=sqrt(F/C);
			double t1=atan(Y1/b), t2=atan(Y2/b); 
			// ranges from -pi/2 <t1,t2< pi/2
			double t=((t1<t2)? t1 : -t1) + u * (((t1<t2)? t2 : -t2) - ((t1<t2)? t1 : -t1));
			return Vector(D + a * 1.0/cos(((t1<t2) ? t : -t)), E + b * tan((t1<t2) ? t : -t), ZT );

		}
		else if((F* A) > 0 && (F*C) < 0)
		{
			double a=sqrt(F/A), b=sqrt(-F/C);
			double t1=atan(X1/b), t2=atan(X2/b); 
			// ranges from -pi/2 <t1,t2< pi/2
			double t=((t1<t2)? t1 : -t1) + u *  (((t1<t2)? t2 : -t2) - ((t1<t2)? t1 : -t1));
			return Vector(D + a * tan((t1<t2) ? t : -t) , E + b * 1.0/cos(((t1<t2) ? t : -t)), ZT );
		}
	}	
	return Vector();
}

/////////////////////////////////////////////////////////////////////////////////////
// ParametricSplineEntity
ParametricSpline::ParametricSpline(int ctype, int h, int ndim, int n) : CTYPE(ctype), H(h), NDIM(ndim), N(n) 
{
	type=ID=112; m_szEntityName=_T("ParametricSplineEntity");
}

CString ParametricSpline::ToString()
{
	CString str;
	str.AppendFormat(_T("%s\n"), _T("*********************** Parameter Data Record ***********************"));
	str.AppendFormat(_T("%-20s  Form=%d\n"), _T("ParametricSpline"), nForm);
	str.AppendFormat(_T("Type=%d  H=%d  NDIM=%d  N=%d\nT[%d]="), CTYPE, H, NDIM, N,N);
	for(int i=0; i<= N; i++) 
		str.AppendFormat(_T("%9.5f,"), Ts[i]);
	str+=_T("\n");
	for(int i=0; i<= N; i++) 
	{
		str.AppendFormat(_T("A[%d] %9.5f %9.5f %9.5f\n"), i+1, XCoordinatePolynomial[i].A, YCoordinatePolynomial[i].A, ZCoordinatePolynomial[i].A );
		str.AppendFormat(_T("B[%d] %9.5f %9.5f %9.5f\n"), i+1, XCoordinatePolynomial[i].B, YCoordinatePolynomial[i].B, ZCoordinatePolynomial[i].B );
		str.AppendFormat(_T("C[%d] %9.5f %9.5f %9.5f\n"), i+1, XCoordinatePolynomial[i].C, YCoordinatePolynomial[i].C, ZCoordinatePolynomial[i].C );
		str.AppendFormat(_T("D[%d] %9.5f %9.5f %9.5f\n"), i+1, XCoordinatePolynomial[i].D, YCoordinatePolynomial[i].D, ZCoordinatePolynomial[i].D );
	}
	return str;
}

/////////////////////////////////////////////////////////////////////////////////////
//Copius Data - Form Number              = 63 - Simple Closed Planar Curve\

CString CopiusData::ToString()
{
	CString str;
	str.AppendFormat(_T("%s\n"), _T("*********************** Copius Data Record ***********************"));
	str.AppendFormat(_T("%-20s IP=%d Form=%d\n"), _T("CopiusData"), IP, nForm);
	for(int i=0; i<nNum; i++)
	{
		str.AppendFormat(_T("I = %d X = %9.5f  Y= %9.5f Z = %9.5f"), i+1, xyzijks[i].x, xyzijks[i].y, xyzijks[i].z);
		if(IP==3 || IP == 13) str.AppendFormat(_T(" I= %9.5f J = %9.5f K= %9.5f"), xyzijks[i].i, xyzijks[i].j, xyzijks[i].k);
		str+=_T("\n");
	}

	return str;
}

/////////////////////////////////////////////////////////////////////////////////////
//GeneralNoteEntity Data -

CString GeneralNote::ToString()
{
	CString str;
	str.AppendFormat(_T("%s\n"), _T("*********************** General Note Data Record ***********************"));
	for(int i=0; i<m_nStrings; i++)
	{
		CNoteData note=m_notes[i];
		str.AppendFormat(_T("I = %d\n"), i+1);
		str.AppendFormat(_T("\tCount = %8d Width = %9.5f Height = %9.5f\n"), note.m_nCount, note.m_dWidth, note.m_dHeight);
		str.AppendFormat(_T("\tFontCharacteristic = %8d  SlantAngle = %9.5f Rotation = %9.5f  Mirror = %8d\n"), 
			note.m_nFontCharacteristic, note.m_nSlantAngle, note.m_dRotation, note.m_nMirror);
		str.AppendFormat(_T("\tX = %9.5f  Y = %9.5f  Z = %9.5f\n"), note.X1, note.Y1, note.Z1);
		str.AppendFormat(_T("\tNote = %s\n"), note.m_sGeneralNote);
	}
	return str;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// PlaneEntity
PlaneEntity::PlaneEntity()
{ 
	type=ID=108;  m_szEntityName=_T("PlaneEntity");
	vars.push_back(VarDef(_T("type") , integer_, (DWORD) &(this->type), _T("integer")));
	vars.push_back(VarDef(_T("A") , real_, (DWORD) &(this->A), _T("real")));
	vars.push_back(VarDef(_T("B") , real_, (DWORD) &(this->B), _T("real")));
	vars.push_back(VarDef(_T("C") , real_, (DWORD) &(this->C), _T("real")));
	vars.push_back(VarDef(_T("D") , real_, (DWORD) &(this->D), _T("real")));
	vars.push_back(VarDef(_T("PTR") , integer_, (DWORD) &(this->PTR), _T("integer")));
	vars.push_back(VarDef(_T("X") , real_, (DWORD) &(this->X), _T("real")));
	vars.push_back(VarDef(_T("Y") , real_, (DWORD) &(this->Y), _T("real")));
	vars.push_back(VarDef(_T("Z") , real_, (DWORD) &(this->Z), _T("real")));
	vars.push_back(VarDef(_T("SIZE") , real_, (DWORD) &(this->SIZE), _T("real")));
}
CString PlaneEntity::ToString()
{
	CString str;
	str.AppendFormat(_T("%s\n"), _T("*********************** Parameter Data Record ***********************"));
	str.AppendFormat(_T("%-20s %s\n"), _T("PlaneEntity"), nForm==1 ? _T("Bounded") : _T("Unbounded"));
	str.AppendFormat(_T("A=%9.5f B=%9.5f C=%9.5f D=%9.5f\n"),  A, B, C, D );
	str.AppendFormat(_T("PTR =%d\n"), PTR );
	str.AppendFormat(_T("XYZ = %9.5f %9.5f %9.5f\n"),X,Y,Z );
	str.AppendFormat(_T("SIZE = %9.5f\n"), SIZE );
	return str;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// ParametricSplineSurfaceEntity
CString ParametricSplineSurface::ToString()
{
	static TCHAR Ps[] = { _T('A'), _T('B'), _T('C'), _T('D'), _T('E'), _T('F'), _T('G'), _T('H'),  _T('K'), _T('L'), _T('M'), _T('N'), _T('P'), _T('Q'), _T('R'), _T('S') };
	CString str;
	int i;
	str.AppendFormat(_T("%s\n"), _T("*********************** Parameter Data Record ***********************"));
	str.AppendFormat(_T("%-20s\n"), _T("ParametricSplineSurfaceEntity"));
	str+=_T("TUs ");
	for(int i=0; i<= M; i++) 
		str.AppendFormat(_T("%9.5f "), TUs[i]);
	str+=_T("\nTVs ");
	for(i=0; i<= N; i++) 
		str.AppendFormat(_T("%9.5f "), TVs[i]);
	str+=_T("\n");
	for(int m=0; m<= M; m++) 
	{
		for(int n=0; n<= N; n++) 
		{
			for(int k=0; k<16;  k++) 
				str.AppendFormat(_T("%C[%d][%d] %9.5f %9.5f %9.5f\n"), Ps[k], m,n, Xs[m][n].data[k],  Ys[m][n].data[k],  Zs[m][n].data[k] );
			str+=_T("\n");
		}
	}
	return str;
}

Vector ParametricSplineSurface::CalcPoint(double s, double t, int i, int j)
{
	double x,y,z;
	double s2=s*s, s3=s*s*s, t2=t*t, t3=t*t*t;
	x=Xs[i][j].a + Xs[i][j].b*s + Xs[i][j].c*s2 + Xs[i][j].c*s3 +
		Xs[i][j].e*t + Xs[i][j].f*t*s + Xs[i][j].g*t*s2 + Xs[i][j].h*t*s3 + 
		Xs[i][j].k*t2 + Xs[i][j].l*t2*s + Xs[i][j].m*t2*s2 + Xs[i][j].n*t2*s3 + 
		Xs[i][j].p*t3 + Xs[i][j].q*t3*s + Xs[i][j].r*t3*s2 + Xs[i][j].s*t3*s3;
	y=Ys[i][j].a + Ys[i][j].b*s + Ys[i][j].c*s2 + Ys[i][j].c*s3 +
		Ys[i][j].e*t + Ys[i][j].f*t*s + Ys[i][j].g*t*s2 + Ys[i][j].h*t*s3 + 
		Ys[i][j].k*t2 + Ys[i][j].l*t2*s + Ys[i][j].m*t2*s2 + Ys[i][j].n*t2*s3 + 
		Ys[i][j].p*t3 + Ys[i][j].q*t3*s + Ys[i][j].r*t3*s2 + Ys[i][j].s*t3*s3;
	z=Zs[i][j].a + Zs[i][j].b*s + Zs[i][j].c*s2 + Zs[i][j].c*s3 +
		Zs[i][j].e*t + Zs[i][j].f*t*s + Zs[i][j].g*t*s2 + Zs[i][j].h*t*s3 + 
		Zs[i][j].k*t2 + Zs[i][j].l*t2*s + Zs[i][j].m*t2*s2 + Zs[i][j].n*t2*s3 + 
		Zs[i][j].p*t3 + Zs[i][j].q*t3*s + Zs[i][j].r*t3*s2 + Zs[i][j].s*t3*s3;
	return Vector(x,y,z);

}
//double ParametricSplineSurface::DrawRaw(IPnts * pPts)
//{
//	int i,j;
//	double s,t;
//	for(i=0; i<M; i++)
//		for(s=0; s<=1; s+=1)
//			for(j=0; j<N; j++)
//				for(t=0; t<=1; t+=GetResolution())
//					pPts->Add(CalcPoint(s,t,i,j));
//	for(j=0; j<N; j++)
//		for(t=0; t<=1; t+=1)
//			for(i=0; i<M; i++)
//				for(s=0; s<=1; s+=GetResolution())
//					pPts->Add(CalcPoint(s,t,i,j));
//	return 0;
//}


//////////////////////////////////////////////////////////////////////////////////////////////////
// BSplineSurfaceEntity
const TCHAR *  BSpline::sFormFactors[6] = {_T("TBD"), _T("Line"), _T("CircularArc"), _T("EllipticalArc"), _T("ParabolicArc"), _T("HyperbolicArc") };

CString BSpline::ToString()
{
	static TCHAR Ps[] = { _T('A'), _T('B'), _T('C'), _T('D'), _T('E'), _T('F'), _T('G'), _T('H'),  _T('K'), _T('L'), _T('M'), _T('N'), _T('P'), _T('Q'), _T('R'), _T('S') };
	static TCHAR * sForms[] = { _T("B-Spline Parameterization"), _T("Line"), _T("Circular Arc"), _T("Elliptical"), _T("Parabolic"), _T("Hyperbolic") };
	int i,k;
	CString str;
	str.AppendFormat(_T("%s\n"), _T("*********************** Parameter Data Record ***********************"));
	str.AppendFormat(_T("%-20s Form=%s\n"), _T("BSplineEntity"), (nForm<6) && (nForm>=0)? sForms[nForm] : _T(""));
	str.AppendFormat(_T("K=%d M=%d Planar=%d OpenClosed=%d Rational=%d Periodic=%d\n"), K,M, nPLANAR, nOpenClosed, nRational, nPeriodic);
	str+=_T("Ts ");
	for( k=-M, i=0; k<=N+M; k++, i++) 
		str.AppendFormat(_T("%9.5f "), Ts[i]);
	str+=_T("\nWs ");
	for(i=0; i<= K; i++) 
		str.AppendFormat(_T("%9.5f "), Ws[i]);
	str+=_T("\n");
	for(i=0; i<= K; i++) 
	{
		str.AppendFormat(_T("[%d] %9.5f %9.5f %9.5f\n"), i,P[i].x, P[i].y, P[i].z); // Xs[i], Ys[i], Zs[i]);  

	}
	str.AppendFormat(_T("V[0]=%9.5f V[1]=%9.5f \n"), V[0], V[1]);  
	str.AppendFormat(_T("XNORM=%9.5f YNORM=%9.5f ZNORM=%9.5f\n"), XNORM, YNORM, ZNORM);  
	return str;
}


//double BSpline::BasisFcn(const int i, const int k, const double u, const std::vector<double>& t)
//{
//	if (k==1)
//	{
//		return ( (t[i] <= u) && (u < t[i+1]) ) ? 1.0 : 0.0;
//	}
//	else
//	{
//		const bool aa = (t[i+k] == t[i+1]);
//		const bool bb = (t[i+k-1] == t[i]);
//
//		return
//			(!aa && !bb) ? 0.0 :
//		(!bb) ? ((t[i+k]-u) / (t[i+k]-t[i+1])) * BasisFcn(i+1, k-1, u, t) :
//		(!aa) ? ((u-t[i])/(t[i+k-1]-t[i])) * BasisFcn(i, k-1, u, t) :
//		((u-t[i])/(t[i+k-1]-t[i])) * BasisFcn(i, k-1, u, t) + ((t[i+k]-u) / 
//			(t[i+k]-t[i+1])) *BasisFcn(i+1, k-1, u, t);
//	}
//}

double BSpline::BasisFcn(const int i, const int k, const double u, FloatList& t)
{
	if(k==0) 
		return ( (t[i] <= u) && (u <= t[i+1]) ) ? 1.0 : 0.0;
	double b;
	if((t[i+k]==t[i]) || (t[i+k+1]==t[i+1]))
		return 0;
	if(t[i+k]==t[i])
		return ((t[i+k+1]-u) * BasisFcn(i+1,k-1,u,t) )/(t[i+k+1]-t[i+1]);
	if(t[i+k+1]==t[i+1])
		return ((u-t[i]) * BasisFcn(i, k-1, u, t) ) / (t[i+k]-t[i]);

	b= ((u-t[i]) * BasisFcn(i, k-1, u, t) ) / (t[i+k]-t[i])  + ((t[i+k+1]-u) * BasisFcn(i+1,k-1,u,t) )/(t[i+k+1]-t[i+1]) ;
	return b;

}


/////////////////////////////////////////////////////////////////////////////////////
// LeaderEntity

CString Leader::ToString()
{
	static TCHAR * sForms[] = {_T(""), _T("Wedge"), _T("Triangle"), _T("Filled Triangle"), _T("No arrowhead"), _T("Circle"), 
		_T("Filled Circle"),  _T("Rectangle"), _T("Filled Rectangle"), _T("Slash"), _T("Integral Sign"), _T("Open Triangle"), _T("Dimension origin")};
	CString str(_T("*********************** Parameter Data Record ***********************\n"));
	str.AppendFormat(_T("%-20s\n Form=%s"), _T("LeaderEntity"), (nForm < 13)? sForms[nForm]: _T("Unknown"));
	str.AppendFormat(_T("Segments=%d\nHeight=%9.5f\nWidth=%9.5f\nZdepth=%9.5f\n"), N, dHeight, dWidth, dZdepth);
	str.AppendFormat(_T("Arrowhead = %9.5f %9.5f\n"),  P[0].x, P[0].y);
	for(UINT i=1; i<=N; i++)
		str.AppendFormat(_T("XY= %9.5f  %9.5f\n"),P[i].x, P[i].y );
	return str;
}

/////////////////////////////////////////////////////////////////////////////////////
// SurfaceRevolutionEntity
SurfaceRevolution::SurfaceRevolution()
{ 
	type=ID=120;  m_szEntityName=_T("SurfaceRevolutionEntity");
	vars.push_back(VarDef(_T("type") , integer_, (DWORD) &(this->type), _T("integer")));
	vars.push_back(VarDef(_T("L") , integer_, (DWORD) &(this->L), _T("integer")));
	vars.push_back(VarDef(_T("C") , integer_, (DWORD) &(this->C), _T("integer")));
	vars.push_back(VarDef(_T("SA") , real_, (DWORD) &(this->SA), _T("real")));
	vars.push_back(VarDef(_T("TA") , real_, (DWORD) &(this->TA), _T("real")));
}

CString SurfaceRevolution::ToString()
{
	CString str(_T("*********************** Parameter Data Record ***********************\n"));
	str.AppendFormat(_T("%-20s\n"), _T("SurfaceRevolutionEntity"));
	str.AppendFormat(_T("Line           	=%d\nGeneratrix     	=%d\n"), L, C);
	str.AppendFormat(_T("Start angle    =%9.5f\nStart angle    =%9.5f\n"), SA, TA);
	return str;
}

/////////////////////////////////////////////////////////////////////////////////////
// RuledSurface
RuledSurface::RuledSurface()
{ 
	type=ID=118;  m_szEntityName=_T("RuledSurface");

	vars.push_back(VarDef(_T("type") , integer_, (DWORD) &(this->type), _T("integer")));
	vars.push_back(VarDef(_T("DE1") , integer_, (DWORD) &(this->DE1), _T("integer")));
	vars.push_back(VarDef(_T("DE2") , integer_, (DWORD) &(this->DE2), _T("integer")));
	vars.push_back(VarDef(_T("DIRFLG") , integer_, (DWORD) &(this->DIRFLG), _T("integer")));
	vars.push_back(VarDef(_T("DEVFLG") , integer_, (DWORD) &(this->DEVFLG), _T("integer")));

}

CString RuledSurface::ToString()
{
	CString str(_T("*********************** Parameter Data Record ***********************\n"));
	str.AppendFormat(_T("%-20s Form=%d\n"), _T("RuledSurface"), nForm);
	str.AppendFormat(_T("Pointer to first Curve=%d\nPointer to second Curve=%d\n"), DE1, DE2);
	str.AppendFormat(_T("Direction Flag=%d\nDevelopable Surface Flag=%d\n"), DIRFLG, DEVFLG);
	return str;
}

/////////////////////////////////////////////////////////////////////////////////////
// TabulatedCylinderEntity
TabulatedCylinder::TabulatedCylinder()
{ 
	type=ID=122;  m_szEntityName=_T("TabulatedCylinderEntity");
	vars.push_back(VarDef(_T("type") , integer_, (DWORD) &(this->type), _T("integer")));
	vars.push_back(VarDef(_T("DE") , integer_, (DWORD) &(this->DE), _T("integer")));
	vars.push_back(VarDef(_T("LX") , real_, (DWORD) &(this->LX), _T("real")));
	vars.push_back(VarDef(_T("LY") , real_, (DWORD) &(this->LY), _T("real")));
	vars.push_back(VarDef(_T("LZ") , real_, (DWORD) &(this->LZ), _T("real")));
}


CString TabulatedCylinder::ToString()
{
	CString str(_T("*********************** Parameter Data Record ***********************\n"));
	str.AppendFormat(_T("%-20s Form=%d\n"), _T("TabulatedCylinderEntity"), nForm);
	str.AppendFormat(_T("DE           	=%d\n"), DE);
	str.AppendFormat(_T("Terminate Point = %9.5f %9.5f %9.5f\n"),  LX, LY, LZ);
	return str;
}

/////////////////////////////////////////////////////////////////////////////////////
// FlashEntity
const TCHAR * Flash::sForms[6] = {_T(""), _T("Defined by Reference Entity"), _T("Circular"), _T("Rectangular"), _T("Donut"), _T("Canoe") };
Flash::Flash()
{ 
	type=ID=125;  m_szEntityName=_T("FlashEntity");
	vars.push_back(VarDef(_T("type") , integer_, (DWORD) &(this->type), _T("integer")));
	vars.push_back(VarDef(_T("X") , real_, (DWORD) &(this->X), _T("real")));
	vars.push_back(VarDef(_T("Y") , real_, (DWORD) &(this->Y), _T("real")));
	vars.push_back(VarDef(_T("DIM1") , real_, (DWORD) &(this->DIM1), _T("real")));
	vars.push_back(VarDef(_T("DIM2") , real_, (DWORD) &(this->DIM2), _T("real")));
	vars.push_back(VarDef(_T("ROT") , real_, (DWORD) &(this->ROT), _T("real")));
	vars.push_back(VarDef(_T("DE") , integer_, (DWORD) &(this->DE), _T("integer")));
}
CString Flash::ToString()
{
	CString str(_T("*********************** Parameter Data Record ***********************\n"));
	str.AppendFormat(_T("%-20s Form=%s\n"), _T("FlashEntity"),(nForm>=0 && nForm<6) ? sForms[nForm] : _T(""));
	str.AppendFormat(_T("Reference Point = %9.5f %9.5f \n"),  X, Y);
	str.AppendFormat(_T("Dimensions = %9.5f %9.5f \n"),  DIM1, DIM1);
	str.AppendFormat(_T("Rotation = %9.5f \n"),  ROT);
	str.AppendFormat(_T("Referneced Entity = %d \n"),  DE);
	return str;
}


/////////////////////////////////////////////////////////////////////////////////////
// NurbSurfaceEntity
const TCHAR * NurbSurface::sForms[11] = {_T(""), _T("TBD"), _T("Plane"), _T("Right circular cylinder"), _T("Cone"), _T("Sphere"), _T("Torus"), 
_T("Surface of Revolution"), _T("Tablulated cylinder"), _T("Ruled surface"), _T("General quadric surface") };

CString NurbSurface::ToString()
{
	int i,k, k1,k2;
	CString str(_T("*********************** Parameter Data Record ***********************\n"));
	str.AppendFormat(_T("%-20s Form=%s\n"), _T("NurbSurfaceEntity"),(nForm>=0 && nForm<11) ? sForms[nForm] : _T(""));
	str.AppendFormat(_T("K1=%d K2=%d \n"),  K1,K2);
	str.AppendFormat(_T("M1=%d M2=%d \n"),  M1,M2);
	str.AppendFormat(_T("PROP1=%d PROP2=%d PROP3=%d PROP4=%d PROP5=%d\n"), PROP1,PROP2,PROP3,PROP4,PROP5);

	str+=_T("Ss ");
	for( k=-M1, i=0; k<N1+M1; k++, i++) 
		str.AppendFormat(_T("%9.5f "), Ss[i]);
	str+=_T("\nTs ");
	for( k=-M2, i=0; k<N2+M2; k++, i++) 
		str.AppendFormat(_T("%9.5f "), Ts[i]);
	str+=_T("\nWs\n");
	for(k2=0; k2<=K2 ; k2++)
	{
		for(k1=0; k1<=K1; k1++)
		{
			str.AppendFormat(_T("W[%d][%d] = %9.5f "), k1,k2, Ws[k1][k2]);
		}
		str+=_T("\n");
	}
	str+=_T("\nPts");
	for(k2=0; k2<=K2 ; k2++)
	{
		for(k1=0; k1<=K1; k1++)
		{
			str.AppendFormat(_T("Pt[%d][%d]=(%s) "),  k1,k2, Pts[k1][k2].ToString());
		}
		str+=_T("\n");
	}
	return str;
}

/////////////////////////////////////////////////////////////////////////////////////
// OffsetCurveEntity
OffsetCurve::OffsetCurve()
{ 
	type=ID=130;  m_szEntityName=_T("OffsetCurveEntity");
	vars.push_back(VarDef(_T("type") , integer_, (DWORD) &(this->type), _T("integer")));
	vars.push_back(VarDef(_T("DE1") , integer_, (DWORD) &(this->DE1), _T("integer")));
	vars.push_back(VarDef(_T("FLAG") , integer_, (DWORD) &(this->FLAG), _T("integer")));
	vars.push_back(VarDef(_T("DE2") , integer_, (DWORD) &(this->DE2), _T("integer")));
	vars.push_back(VarDef(_T("NDIM") , integer_, (DWORD) &(this->NDIM), _T("integer")));
	vars.push_back(VarDef(_T("PTYPE") , integer_, (DWORD) &(this->PTYPE), _T("integer")));
	vars.push_back(VarDef(_T("D1") , real_, (DWORD) &(this->D1), _T("real")));
	vars.push_back(VarDef(_T("TD1") , real_, (DWORD) &(this->TD1), _T("real")));
	vars.push_back(VarDef(_T("D2") , real_, (DWORD) &(this->D2), _T("real")));
	vars.push_back(VarDef(_T("TD2") , real_, (DWORD) &(this->TD2), _T("real")));
	vars.push_back(VarDef(_T("VX") , real_, (DWORD) &(this->VX), _T("real")));
	vars.push_back(VarDef(_T("VY") , real_, (DWORD) &(this->VY), _T("real")));
	vars.push_back(VarDef(_T("VZ") , real_, (DWORD) &(this->VZ), _T("real")));
	vars.push_back(VarDef(_T("TT1") , real_, (DWORD) &(this->TT1), _T("real")));
	vars.push_back(VarDef(_T("TT2") , real_, (DWORD) &(this->TT2), _T("real")));
}


/////////////////////////////////////////////////////////////////////////////////////
// LinearDimensionEntity
LinearDimension::LinearDimension()
{ 
	type=ID=216;  
	m_szEntityName=_T("LinearDimensionEntity");
	vars.push_back(VarDef(_T("type") , integer_, (DWORD) &(this->type), _T("integer")));
	vars.push_back(VarDef(_T("DENOTE") , integer_, (DWORD) &(this->DENOTE), _T("integer")));
	vars.push_back(VarDef(_T("DEARRW1") , integer_, (DWORD) &(this->DEARRW1), _T("integer")));
	vars.push_back(VarDef(_T("DEARRW2") , integer_, (DWORD) &(this->DEARRW2), _T("integer")));
	vars.push_back(VarDef(_T("DEWIT1") , integer_, (DWORD) &(this->DEWIT1), _T("integer")));
	vars.push_back(VarDef(_T("DEWIT2") , integer_, (DWORD) &(this->DEWIT2), _T("integer")));
}


CString LinearDimension::ToString()
{
	CString str(_T("*********************** Parameter Data Record ***********************\n"));
	str.AppendFormat(_T("%-20s \n"), _T("LinearDimensionEntity"));
	str.AppendFormat(_T("DENOTE=%d  \n"),  DENOTE);
	str.AppendFormat(_T("DEARRW1=%d DEARRW2=%d \n"),  DEARRW1, DEARRW2);
	str.AppendFormat(_T("DEWIT1=%d DEWIT2=%d \n"),  DEWIT1, DEWIT2);
	return str;
}

/////////////////////////////////////////////////////////////////////////////////////
// AngularDimensionEntity
AngularDimension::AngularDimension()
{ 
	ID=202;  m_szEntityName=_T("AngularDimensionEntity");
	vars.push_back(VarDef(_T("type") , integer_, (DWORD) &(this->type), _T("integer")));
	vars.push_back(VarDef(_T("DENOTE") , integer_, (DWORD) &(this->DENOTE), _T("integer")));
	vars.push_back(VarDef(_T("DEWIT1") , integer_, (DWORD) &(this->DEWIT1), _T("integer")));
	vars.push_back(VarDef(_T("DEWIT2") , integer_, (DWORD) &(this->DEWIT2), _T("integer")));
	vars.push_back(VarDef(_T("XT") , real_, (DWORD) &(this->XT), _T("real")));
	vars.push_back(VarDef(_T("YT") , real_, (DWORD) &(this->YT), _T("real")));
	vars.push_back(VarDef(_T("R") , real_, (DWORD) &(this->R), _T("real")));
	vars.push_back(VarDef(_T("DEARRW1") , integer_, (DWORD) &(this->DEARRW1), _T("integer")));
	vars.push_back(VarDef(_T("DEARRW2") , integer_, (DWORD) &(this->DEARRW2), _T("integer")));
}

CString AngularDimension::ToString()
{
	CString str(_T("*********************** Parameter Data Record ***********************\n"));
	str.AppendFormat(_T("%-20s \n"), _T("AngularDimensionEntity"));
	str.AppendFormat(_T("DENOTE=%d  \n"),  DENOTE);
	str.AppendFormat(_T("DEWIT1=%d DEWIT2=%d \n"),  DEWIT1, DEWIT2);
	str.AppendFormat(_T("XT = %9.5f  YT = %9.5f R = %9.5f \n"),  XT, YT, R);
	str.AppendFormat(_T("DEARRW1=%d DEARRW2=%d \n"),  DEARRW1, DEARRW2);
	return str;
}
/////////////////////////////////////////////////////////////////////////////////////
// AngularDimensionEntity
DiameterDimension::DiameterDimension()
{ 
	type=ID=206;  m_szEntityName=_T("DiameterDimensionEntity");
	vars.push_back(VarDef(_T("type") , integer_, (DWORD) &(this->type), _T("integer")));
	vars.push_back(VarDef(_T("DENOTE") , integer_, (DWORD) &(this->DENOTE), _T("integer")));
	vars.push_back(VarDef(_T("DEARRW1") , integer_, (DWORD) &(this->DEARRW1), _T("integer")));
	vars.push_back(VarDef(_T("DEARRW2") , integer_, (DWORD) &(this->DEARRW2), _T("integer")));
	vars.push_back(VarDef(_T("XT") , real_, (DWORD) &(this->XT), _T("real")));
	vars.push_back(VarDef(_T("YT") , real_, (DWORD) &(this->YT), _T("real")));
}
CString DiameterDimension::ToString()
{
	CString str(_T("*********************** Parameter Data Record ***********************\n"));
	str.AppendFormat(_T("%-20s \n"), _T("DiameterDimensionEntity"));
	str.AppendFormat(_T("DENOTE=%d  \n"),  DENOTE);
	str.AppendFormat(_T("DEARRW1=%d DEARRW2=%d \n"),  DEARRW1, DEARRW2);
	str.AppendFormat(_T("XT = %9.5f  YT = %9.5f \n"),  XT, YT);
	return str;
}
/////////////////////////////////////////////////////////////////////////////////////
// FlagNoteEntity

CString FlagNote::ToString()
{
	CString str(_T("*********************** Parameter Data Record ***********************\n"));
	str.AppendFormat(_T("%-20s \n"), _T("FlagNoteEntity"));
	str.AppendFormat(_T("XT = %9.5f  YT = %9.5f  ZT = %9.5f\n"),  XT, YT, ZT);
	str.AppendFormat(_T("A = %9.5f \n"),  A);
	str.AppendFormat(_T("DENOTE=%d  N=%d \nDEARRWs="),  DENOTE, N);
	for(int i=0; i< N; i++)
		str.AppendFormat(_T("%d \n"),  DEARRWs[i]);
	str+=_T("\n");
	return str;
}
/////////////////////////////////////////////////////////////////////////////////////
// ColorEntity
Color::Color()
{ 
	type=ID=314;  
	m_szEntityName=_T("ColorEntity"); 
	vars.push_back(VarDef(_T("type") , integer_, (DWORD) &(this->type), _T("integer")));
	vars.push_back(VarDef(_T("CC1") , real_, (DWORD) &(this->CC1), _T("real")));
	vars.push_back(VarDef(_T("CC2") , real_, (DWORD) &(this->CC2), _T("real")));
	vars.push_back(VarDef(_T("CC3") , real_, (DWORD) &(this->CC3), _T("real")));
//	vars.push_back(VarDef(_T("name") , string_, (DWORD) &(this->name), _T("string"), true));
}

CString Color::ToString()
{
	CString str(_T("*********************** Parameter Data Record ***********************\n"));
	str.AppendFormat(_T("%-20s \n"), _T("ColorEntity"));
	str.AppendFormat(_T("Name = %s R = %9.5f  G = %9.5f  B = %9.5f\n"),  name, CC1, CC2, CC3);
	return str;
}
/////////////////////////////////////////////////////////////////////////////////////
// CurveParametricSurfaceEntity
CurveParametricSurface::CurveParametricSurface()
{ 
	type=ID=142;  m_szEntityName=_T("CurveParametricSurfaceEntity");
	vars.push_back(VarDef(_T("type") , integer_, (DWORD) &(this->type), _T("integer")));
	vars.push_back(VarDef(_T("CTRN") , integer_, (DWORD) &(this->CTRN), _T("integer")));
	vars.push_back(VarDef(_T("SPTR") , integer_, (DWORD) &(this->SPTR), _T("integer")));
	vars.push_back(VarDef(_T("BPTR") , integer_, (DWORD) &(this->BPTR), _T("integer")));
	vars.push_back(VarDef(_T("CPTR") , integer_, (DWORD) &(this->CPTR), _T("integer")));
	vars.push_back(VarDef(_T("PREF") , integer_, (DWORD) &(this->PREF), _T("integer")));
}

CString CurveParametricSurface::ToString()
{
	CString str(_T("*********************** Parameter Data Record ***********************\n"));
	str.AppendFormat(_T("%-20s \n"), _T("CurveParametricSurfaceEntity"));
	str.AppendFormat(_T("CTRN = %d SPTR = %d  BPTR = %d  CPTR = %d PREF=%d\n"),  CTRN, SPTR, BPTR, CPTR, PREF);
	return str;
}

/////////////////////////////////////////////////////////////////////////////////////
// TrimmedSurfaceEntity

CString TrimmedSurface::ToString()
{
	CString str(_T("*********************** Parameter Data Record ***********************\n"));
	str.AppendFormat(_T("%-20s \n"), _T("CurveParametricSurfaceEntity"));
	str.AppendFormat(_T("PTS = %d N1 = %d  N2 = %d  PT0 = %d \nPts= \n"),  PTS, N1, N2, PT0);
	for(int i=0; i< N2; i++)
		str.AppendFormat(_T("%d "), PTs[i]);
	str+=_T("\n");
	return str;
}
/////////////////////////////////////////////////////////////////////////////////////
// TrimmedSurfaceEntity
CString CPropertyType::ToString()
{
	CString str(_T("*********************** Parameter Data Record ***********************\n"));
	str.AppendFormat(_T("%-20s \n"), _T("CPropertyTypeEntity"));
	return str;
}

