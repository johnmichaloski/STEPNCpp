//
// iges.h
//

// DISCLAIMER: 
//  This software was produced by the National Institute of Standards 
//  and Technology (NIST), an agency of the U.S. government, and by statute is 
//  not subject to copyright in the United States.  Recipients of this 
//  software assume all responsibility associated with its operation,
//  modification,maintenance, and subsequent redistribution. 
//
//  See NIST Administration Manual 4.09.07 b and Appendix I. 

#pragma once

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>

#include "atlstr.h"
#include "linalg3d.h"
#include "ClassUtils.h"
#include "boost/variant.hpp"
#include "boost/lexical_cast.hpp"
using namespace std;


namespace Iges 
{
	struct ABCD;
	struct ABCDEFGHIJKLMNOPQRS;
	struct XYZIJK;
	struct IGES_Globals;
	struct Entity;
	struct IGES_ENTITIES;
	class IgesModel;

	enum Units { inches=1, millimeters, see15, feet, miles=5, meters=6, kilometers=7, mils=8, microns=9, centimeters=10, microinches=11};
	enum DraftingCode { igesnone=0, iso=0, ANFOR=2, ANSI=3, BSI=4, CSA=5, DIN=6, JIS=7};
	enum LineFontPattern { solid=1, dashed=2, phantom=3, centerline=4, dotted=5};
	enum ColorCode { NoColor=0, Black=1, Red=2, Green=3, Blue=4, Yellow=5, Magenta=6, Cyan=7, White=8};

	struct ABCD{ 
		double A,B,C,D; 
		ABCD(double a=0, double b=0, double c=0, double d=0) : A(a), B(b), C(c), D(d) {}
	} ;
	struct XYZIJK{ 
		double x,y,z,i,j,k; 
		XYZIJK(double X=0, double Y=0, double Z=0, double I=0, double J=0, double K=0) : x(X), y(Y), z(Z), i(I), j(J), k(K) {}
	} ;

	struct ABCDEFGHIJKLMNOPQRS
	{
		union{
			struct{
				double a,b,c,d, e,f,g,h, k,l,m,n, p,q,r,s;
			};
			double data[19];
		};

	};

	struct ModelGlobals
	{

		ModelGlobals(); 
		//////////////////////
		CString ToString(); 
		//////////////////////

		VarDefs vars;

		static std::vector<ColorMap> igesColorIndex;
		CString sParameterDelimiter,sRecordDelimiter,sProductId,sFilename,sSystemId,sPreprocessVersion;	// 1
		int nIntegerBits,nMaxPowerTenFloat,nFloatingSignificantDigits,nMaxPowerTenDouble,nFloatingSignificantDigitsDbl;				// 7
		CString sProductIdReceiving;	// 12
		float dModelSpaceScale;		// 13
		int nUnits;	// 14  1=inches, 2=mm, 3=, 4=feet, 5=miles, 6=meters
		CString sUnits;	// 15
		int nMaxNumberLineWeight;	// 16
		float dMaxLineWeightInUnits;	// 17
		CString sDateTime;	// 18
		float dMinResolution;	// 19
		float dMaxCoordinateValue;	// 20
		CString sAuthor;	// 21
		CString sOrganization;	// 22
		int nIgesVersion;	// 22
		int nDraftingStandard;	// 23
	};


	struct Entity 
	{
		Entity();
		CString m_szEntityName;
		virtual int GetEntityType() { return ID; }
		//////////////////////
		int igesEntityGetType() { return type; }
		int igesEntityGetColor() { return color; }
		int igesEntityGetStatus() { return status; }
		int igesEntityGetLine(){ return line; }

		//////////////////////

		int ID;
		int type;                      /* 1-8 entity type */
		int datarec;                      /* 9-16 parameter data */
		int structure;                 /* 17-24 parameter data */
		int linefontpattern;            /* 25-32 parameter data */
		int level;						/* 33-40 entity status */
		int view;						/* 41-48 entity status */
		int pTransform; 				/* 49-56 entity status */
		int labeldisplay;				/* 57-64 entity status */
		int status;                    /* 65-72 entity status */
		int seqnum;                    /* 73-80 sequence num*/
		int line;                      /* sequence number */
		int nForm;

		int lineweight;					/* 9-15 line weight */
		int color;						/* 17-24 color number */
		int parameterlinecount;			/* 25-32 parameter line count */

		int nAssocPointers;
		std::vector<int> m_vAssocPtrs;

		int nPropertyPointers;
		std::vector<int> m_vPropertyPtrs;

		// Derived values;
		int nBlank;
		int nSubordinate;
		int nUseFlag;
		int nHierarchy;
		const static TCHAR * sBlankStatus[2];
		const static TCHAR * sSubordinateStatus[4];
		const static TCHAR * sEntityUseStatus[6];
		const static TCHAR * sHierarchyStatus[3];
		const static TCHAR *  sLineFontPattern[6];
		/*short translated;                flag if the entity has been processed */
		std::vector<void *> param;		/* GSList containing params */
		std::vector<int> m_nPointers; // pointes to directory entities for the constituent entities.
		std::vector<Entity *> m_SubEntities;
		CStringVector tokens ;
		VarDefs vars;
		CString sBlank;
		CString m_szErrmsg;

	};

	struct Entity1
	{
		CString m_szEntityName;
		int ID;
		enum { none_, point_, circarc_, arc3d_, line_, xform_ };
		int type; // iges type
		int _type;
		virtual CString ToXmlString(){ return ""; }
		virtual void FromXmlString(CString str){  }
		bool IsLine() { return _type == line_; }
		bool IsPoint() { return _type == point_; }
		bool IsArc() { return _type == arc3d_; }
		virtual Vector FirstPoint() { return Vector(); }
		virtual Vector LastPoint() { return Vector(); }

	};
	struct Transform : public Entity1
	{
		enum FormFactor { OrthogonalRH=0, OrthogonalLH=1};

		/////////////////////////////////////////////////////////////////////////////////////
		// TransformEntity
		Transform(double d11, double d12, double d13, double d14, 
			double d21, double d22, double d23, double d24, 
			double d31, double d32, double d33, double d34) ;
		Transform(Matrix m) : matrix(m) {	_type= xform_;}
		//////////////////////
		virtual CString ToString();
		//	virtual double DrawRaw(Pnts * pPts);
		//////////////////////
		Matrix matrix;
		int n; // 1 - number of entities

	};
	struct Point : public Entity1
	{
		Point(double x1=0, double y1=0, double z1=0);
		Point(Vector);
		//////////////////////
		virtual CString ToXmlString();
		virtual void FromXmlString(CString str);
		virtual Vector GetPoint(float u, float v=0.0) ;
		//////////////////////
		Point3d pt;
		float& X1;  // 1- X start point
		float& Y1;  // 2- Y  start point
		float& Z1;  // 3- Z start point 
		Vector FirstPoint() { return Vector(X1,Y1,Z1); }
		Vector LastPoint() { return Vector(X1,Y1,Z1); }
	};

	struct Line : public Entity1
	{
		Line(double x1=0, double y1=0, double z1=0, double x2=0, double y2=0, double z2=0)  ;
		Line(Vector v1, Vector v2)  ;
		//////////////////////
		virtual	Vector GetPoint(float u, float v=0.0) ;
		virtual	Vector GetStart(float u, float v=0.0) { return Vector(_pt1); }
		virtual	Vector GetEnd(float u, float v=0.0) { return Vector(_pt2); }
		virtual REAL Magnitude() { return Vector(_pt2-_pt1).Len(); }
		virtual Vector Direction() { return Vector(_pt2-_pt1).Normalize(); }
		CString ToXmlString();
		void FromXmlString(CString str);
		Vector FindNearestPt(Vector pt )
		{
			Vector v1(_pt1), v2(_pt2), _dir( Direction());
			return ( v1 + _dir  *	Dot(pt - v1, _dir) / _dir.Norm() );
		}
		REAL Distance(Point3d pt) { return  Vector(Vector(pt) - FindNearestPt(pt)).Len(); }
		Vector FirstPoint() { return _pt1; }
		Vector LastPoint() { return _pt2; }
		//////////////////////
		Vector _pt1;
		Vector _pt2;
	};

	/* 3d arc */
	struct Arc3D : public Entity1
	{
		Vector ep1, ep2;    /* Arc endpoints */
		Vector c;           /* Arc center, relative to view */
		REAL radius;           /* Arc radius */
		REAL sa;          /* Start angle in radians */
		REAL sw;          /* Sweep angle in radians */
		Arc3D() {  	_type= arc3d_; }
		Arc3D(Vector ep1, Vector ep2, Vector center, REAL radius, REAL startangle, REAL sweepangle);
		CString ToXmlString();
		void FromXmlString(CString str);	       
		Vector FirstPoint() { return ep1; }
		Vector LastPoint() { return ep2; }
		void Init() { ep1=Vector(); ep2=Vector(); c=Vector(); radius=0.0; sa=0.0; sw=0.0; }
	};

	// X(u) = AX(i) + BX(i) * s + CX(i) * pow(s,2) + DX(i) * pow(s,3)
	// Y(u) = AY(i) + BY(i) * s + CY(i) * pow(s,2) + DY(i) * pow(s,3)
	// Z(u) = AZ(i) + BZ(i) * s + CZ(i) * pow(s,2) + DZ(i) * pow(s,3)
	//


	struct CircularArc : public Entity1
	{
		CircularArc();
		Vector GetPoint(float u, float v) ;

		Vector ep1, ep2;    /* Arc endpoints */
		Vector c;           /* Arc center, relative to view */
		REAL radius;           /* Arc radius */
		REAL sa;          /* Start angle in radians */
		REAL sw;          /* Sweep angle in radians */

		//////////////////////
		float ZT;  // 1 - parallel ZT displacement of arc form XT, YT plane
		float X1;  // 2- arc center abscissa
		float Y1;	// 3- arc center ordinate
		float X2;	// 4 - start point abscissa
		float Y2;	// 5 start point ordinate
		float X3;	// 6 - termiante point absicssa
		float Y3;	// 7 - terminate point ordinate

	};
#if 0
	/* 	CompositeEntity entity;
	Point & pt = entity.get<Point>();
	pt.X1 = 1;
	pt.Y1 = 1;
	pt.Z1 = 1;
	*/

	class CompositeEntity :
		public Point,
		public CircularArc,
		public Arc3D,
		public Line
	{
	public:
		template<typename T> 
		T & get() const { return (*((T*) this)); }
		CompositeEntity() { _type = none_; }
		CompositeEntity(Point p) : Point(p) { _type = point_; }
		CompositeEntity(CircularArc a) : CircularArc(a) { _type = circarc_; }
		CompositeEntity(Arc3D a) : Arc3D(a) { _type = arc3d_; }
		CompositeEntity(Line a) : Line(a) { _type = line_; }
		// FIXME: add closed boolean

		CompositeEntity& operator=(const CompositeEntity& rhs)
		{
			if (this !=&rhs)
			{
				this->~CompositeEntity();//destroy self
				new (this) CompositeEntity(rhs);//reconstruct self using placement new and copy ctor
			}
			return *this;
		}
		CString ToString();
		void FromString(CString);

	};
#endif
	// Composite  is defined as an ordered list of entites of the following tuypes: point, line, circular arc,
	// conic ar, parametric spline, rational B-spline, and connect point.
	struct CompositeCurve : public Entity, public std::vector<Entity1 *>
	{
		CompositeCurve();
		//////////////////////
		CString ToXmlString();
		void AddXmlEntity(CString);
	
		int AddEntity(Point p) { push_back( new Point(p)); return size();}
		int AddEntity(Arc3D a) { push_back( new  Arc3D(a)); return size();}
		int AddEntity(Line a) { push_back( new Line(a)); return size();}
		int AddEntity(Transform t) { push_back( new Transform(t)); return size();}

		//////////////////////
		int n; // 1 - number of entities

	};
	// A * XT*T + B * XT * YT + C * YT * YT + D * XT + E * YT + F = 0
	struct ConicArc : public Entity
	{
		enum FormFactor { General=0, Ellipse=1, Hyperbola=2, Parabola=3};
		ConicArc();

		//////////////////////
		virtual	Vector GetPoint(float u, float v=0.0) ;
		CString ToString();
		//////////////////////

		float A,B,C,D,E,F, ZT, X1, Y1, X2, Y2; 

	};

	struct CopiusData : public Entity
	{
		CopiusData()
		{ 
			type=ID=106;  
			m_szEntityName=_T("CopiusData");
		}
		//////////////////////
		CString ToString();
		//////////////////////
		int IP; // 1- interpretation flag: 1=x,y pairs, 2=x,y,z coordinates, 3=x,y,z, coordinates i,j,j vectors
		int nNum; // 2 - number of n-tuples 
		std::vector<XYZIJK> xyzijks;
		double ZT;

	};

	struct ParametricSpline : public Entity
	{
		ParametricSpline(int ctype=0, int h=0, int ndim=0, int n=0);
		//////////////////////
		CString ToString();

		//////////////////////
		enum Type { Linear=1, Quadratic=2, Cubic=3, Wilson_Fowler=4, Modified_Wilson_Fowler=5, B_Spline=6};
		int CTYPE; // 1 - type
		int H;		// 2 - degree of continuitywith respect to arc length 0=continuous, 1=continuous&slope continuous, 2=continuous&slope& Curvature continuous
		int NDIM;	// 3 - number of dimensions, 2=planar, 3=non-planar
		int N;		// 4- number of segments;
		FloatList  Ts;
		std::vector<ABCD>  XCoordinatePolynomial;  // 0..n
		std::vector<ABCD>  YCoordinatePolynomial;  // 0..n
		std::vector<ABCD>  ZCoordinatePolynomial;  // 0..n 
	};

	// A* XT + B *YT + C * ZT = D
	struct PlaneEntity  : public Entity
	{
		PlaneEntity();
		//////////////////////
		CString ToString();
		//////////////////////
		float A; // 1 -  coefficient
		float B; // 2 -  coefficient
		float C; // 3 -  coefficient
		float D; // 4 -  coefficient
		int PTR ;
		double X, Y, Z, SIZE;
	};

	struct ParametricSplineSurface  : public Entity
	{

		ParametricSplineSurface(){ ID=114;  m_szEntityName=_T("ParametricSplineSurfaceEntity");}
		~ParametricSplineSurface() {  }

		//////////////////////
		Vector CalcPoint(double s, double t, int i, int j);
		CString ToString();

		//////////////////////
		int CTYPE, PTYPE, M, N;
		std::vector<double>  TUs;
		std::vector<double>  TVs;
		const static int m_nP=19;
		vector<vector<ABCDEFGHIJKLMNOPQRS> > Xs;
		vector<vector<ABCDEFGHIJKLMNOPQRS> > Ys;
		vector<vector<ABCDEFGHIJKLMNOPQRS> > Zs;

	};

	struct RuledSurface : public Entity
	{
		RuledSurface();
		//////////////////////
		virtual CString ToString();
		//////////////////////
		int DE1, DE2;       // DE1-Dictionary Entry 1, DE2-Dictionary Entry 2
		int DIRFLG;			// Direction flag 0=join first to first, last to last, 1=join first to last, last to first
		int DEVFLG;			// Devlopable sruface flag 1=developable, 0= possibly not
	};




	struct BSpline  : public Entity
	{
		BSpline(){ type=ID=126;  m_szEntityName=_T("BSplineEntity");}

		enum FormFactor { TBD=0, Line=1, CircularArc=2, EllipticalArc=3, ParabolicArc=4, HyperbolicArc=5};
		const static TCHAR * sFormFactors[6];
		//////////////////////
		virtual CString ToString();
		double BasisFcn(const int i, const int k, const double u, FloatList& t);
		//////////////////////
		int K,M, nPLANAR, nOpenClosed, nRational, nPeriodic;
		int N, A;
		FloatList  Ts;
		FloatList  Ws;
		VectorList  P;
		float V[2];
		float XNORM, YNORM, ZNORM;
	};


	struct SurfaceRevolution  : public Entity
	{
		SurfaceRevolution();
		//////////////////////
		virtual CString ToString();
		//////////////////////
		int L, C;       // L - line, C- pointer to geometry generatrix 
		float SA, TA;  // start angle and terminate angle in radians

	};
	struct TabulatedCylinder  : public Entity
	{
		TabulatedCylinder();
		//////////////////////
		virtual CString ToString();
		//////////////////////
		int DE;				// DE-Dictionary Entry to directrix curve
		float LX, LY, LZ;	// Coordinates of terminate point of the generatrix. 
		//Start point is identical to start point of generatrix.

	};

	struct Flash  : public Entity
	{
		const static TCHAR * sForms[6] ;

		Flash();
		//////////////////////
		virtual CString ToString();
		//////////////////////
		float X,Y;				// X, Y reference of flash
		float DIM1, DIM2;		// First and second flash sizing parameter
		float ROT;				// rotation of flas about reference point
		int DE;				// DE of reference entity or zero.

	};


	struct NurbSurface  : public Entity
	{
		const static TCHAR * sForms[11] ;
		enum FormFactor { TBD=0, Plane=1, RightCircularCylinder=2, Cone=3, Sphere=4, Torus=5,
			SurfaceOfRevolution=6, TabulatedCylinder=7, RuledSurface=8, GeneralQuadricSurface=9};

		NurbSurface(){ type=ID=128;  m_szEntityName=_T("NurbSurfaceEntity");}
		~NurbSurface() {  }

		//////////////////////
		virtual CString ToString();
		Vector CalcPoint(float s, float t, int i, int j);

		//////////////////////
		int K1, K2, M1, M2;						// N=upper index, M=degree
		int PROP1, PROP2, PROP3, PROP4, PROP5; //  prop1=1st closed, prop2=2nd closed, prop3(0=rational, 1=polynomial), prop4/5- 1-2 periodic
		int N1, N2, A,B,C; // derived

		FloatList  Ss;
		FloatList  Ts;
		Array2D<float> Ws;
		Array2D<Vector>  Pts;
		float  U[2];
		float  V[2];

	};


	struct OffsetCurve  : public Entity
	{
		OffsetCurve();
		//////////////////////

		//virtual double DrawRaw(IPnts * pPts);
		//virtual double DrawOGL(CFeatureList * pPts);
		//////////////////////
		long DE1;				// DE of reference entity to be offset.
		long FLAG;				// offset distance flag, 1= single value offset, 2=varying linearly, 3=distance as function
		long DE2;				// DE of reference to curve which describes offset or zero.
		long NDIM;				// pointer of particualr coordinate of DE2 which describes offset as a function (only if FLAG=3)
		long PTYPE;				// tapered offset type flat, 1=function of arc length, 2-function of parameter
		float D1;				// first offset disance (only if FLAG=1 or=2)
		float TD1;				// arc length or parameter value depending on PTYPE, of first offset distance (FLAG=2)
		float D2;				// first offset disance (only if FLAG=1 or=2)
		float TD2;				// arc length or parameter value depending on PTYPE, of second offset distance (FLAG=2)
		double VX,VY,VZ;		// unit vector normal to plane containing curve to be offset
		double TT1, TT2;		// Offset curve starting and ending parameter value

	};

	// Connect Point Entity - 132
	// Node Entity - 134
	// Finite Element Entity - 136 
	// Nodal Displacement and Rotation Entity - 138

	struct OffsetSurface  : public Entity
	{
		OffsetSurface(){ type=ID=140;  m_szEntityName=_T("OffsetSurfaceEntity");}
		//////////////////////

		//////////////////////
		float NX,NY,NZ;  // x,y,z coordinate of offset indicate N(U,mV,m)
		float D; //  distance by which the surface is normally offset on the sidef ot he offset indicator if d>0 opposite if d<0
		long PE; // pointer to surface entity to be offset
	};

	struct CurveParametricSurface : public Entity
	{
		CurveParametricSurface();
		enum CRTNEnum { Unspecified=0, ProjectionCurveOntoSurface=1, IntersectionTwoSurfaces=2, Isometric=3};
		enum PrefEnum { Unspec=0, SoB=1, CPreferred=2, CorBEqual=3};
		//////////////////////
		virtual CString ToString();
		//////////////////////
		long CTRN; // indicates the way the curve on the suface has been created
		long SPTR;	// pointer to the surface on which the curve lies
		long BPTR;	// pointer to the entity that contains the definition of curve B in the parametric space(u,v,) of surface S
		long CPTR;	// pionter to the curve C
		long PREF;  // indicates the prerred representation in the sending system
	};

	struct TrimmedSurface  : public Entity
	{
		TrimmedSurface(){ type=ID=144;  m_szEntityName=_T("TrimmedSurfaceEntity");}
		//////////////////////
		virtual HRESULT ReadParameters(CString str, CString szFieldDelim=_T(","), CString szEndDelim=_T(";"));
		virtual CString ToString();
		//////////////////////
		long PTS; // pointer to surface entity to be trimmed
		long N1;	// =0 if the outer boundary is the boundary of D, =1 otherwise
		long N2;	// indicates the number of simple closed curves which constitute the inner boundary of the trimmed surface.
		long PT0;	// pointer to the simple closed curve (Curve on a Parametric Surface Entity) constitutes outer boundary or 0
		CIntArray PTs;	// pointer to 1..n2 simple closed inner boundary curve (Curve on a Parametric Surface Entity)

	};
	// CSG Block Entity - 150
	// CSG Right Angle Wedge Entity - 152
	// CSG Right Circular Cylinder Entity - 154
	// CSG Right Circular Cone Frustrum Entity - 156
	// CSG Sphere Entity - 158
	// CSG Torus Entity - 160
	// CSG Solid of Revolution Entity - 162
	// CSG Solid of Linear Extrusion Entity - 164
	// CSG Ellipsoid Entity - 164
	// CSG Boolean Tree Entity - 180
	// CSG Solid Instance Entity - 430
	// CSG Solid Assembly Entity - 184

	////////////////////////////////////////////////////////////////////////////////////
	// Annotations
	struct AngularDimension : public Entity
	{
		AngularDimension();
		//////////////////////
		virtual CString ToString();
		//////////////////////
		int DENOTE;			// pointer to general note directory entry
		int DEWIT1;			// pointer to witness line ; 0 if not defined
		int DEWIT2;			// pointer to witness line ; 0 if not defined
		float XT;			// coordinates of vertex point
		float YT;			// coordinates of vertex point
		float R;			// radius of leader arcs
		int DEARRW1;		// pointer to first leader directory entry
		int DEARRW2;		// pointer to second leader directory entry
	};

	struct DiameterDimension : public Entity
	{
		DiameterDimension();
		//////////////////////
		virtual CString ToString();
		//////////////////////
		int DENOTE;			// pointer to general note directory entry
		int DEARRW1;		// pointer to first leader directory entry
		int DEARRW2;		// pointer to second leader directory entry
		float XT;			// arc center coordinates 
		float YT;			// arc center coordinates 
	};

	struct FlagNote : public Entity
	{
		FlagNote(){ type=ID=208;  m_szEntityName=_T("FlagNoteEntity");}

		//////////////////////
		virtual HRESULT ReadParameters(CString str, CString szFieldDelim=_T(","), CString szEndDelim=_T(";"));
		virtual CString ToString();
		//////////////////////
		float XT,YT, ZT;	// lower left corner  coordinates 
		float A;			// rotation angle in radians
		int DENOTE;			// pointer to general note directory entry
		int N;				// number of associated leaders
		CIntArray DEARRWs;		// pointer to accoiated leaders directory entry
	};
	struct GeneralNote : public Entity
	{
		struct  CNoteData {
			int m_nCount;
			double m_dWidth;
			double m_dHeight;
			int m_nFontCharacteristic;
			double m_nSlantAngle; //radians
			double m_dRotation;
			int m_nMirror; // 0 - no mirroring, 1 - mirror axis is perpendicular, 2= mirror axis is text base line
			long m_nVH;
			float X1;  // 1- X start point
			float Y1;  // 2- Y  start point
			float Z1;  // depth from XY, XY plane
			CString m_sGeneralNote;
		} ;

		GeneralNote(){ type=ID=212;  m_szEntityName=_T("GeneralNoteEntity"); m_nStrings=0;}

		//////////////////////
		virtual CString ToString();
		//////////////////////
		int m_nStrings;
		std::vector<CNoteData> m_notes;
	};

	struct Leader  : public Entity
	{
		Leader() { ID=214;  m_szEntityName=_T("LeaderEntity");  }
		//////////////////////
		virtual CString ToString();
		//////////////////////
		int N;
		double dHeight, dWidth, dZdepth;
		VectorList  P;
	};

	struct LinearDimension  : public Entity
	{
		LinearDimension();
		//////////////////////
		virtual CString ToString();
		//////////////////////
		int DENOTE;			// pointer to general note directory entry
		int DEARRW1;		// pointer to first leader directory entry
		int DEARRW2;		// pointer to second leader directory entry
		int DEWIT1;			// pointer to witness line ; 0 if not defined
		int DEWIT2;			// pointer to witness line ; 0 if not defined

	};

	struct Color : public Entity
	{
		Color();
		//////////////////////
		virtual CString ToString();
		COLORREF GetColor() { return RGB((short)((CC1*256)/100), (short)((CC2*256)/100),(short)((CC3*256)/100)); }
		//////////////////////
		float CC1;			// red
		float CC2;			// green
		float CC3;			// blue
		CString name;		// name

	};

	struct CPropertyType  : public Entity
	{
		enum FormFactor { TBD=0, Levels=1, RegionRestriction=2, LevelFunction=3, LineWidening=5, DrilledHole=6, 
			ReferenceDesignator=7, PinNumber=8, PortNumber=9, Hierarchy=10, TableData=11};
		CPropertyType(){ type=ID=406;  m_szEntityName=_T("CPropertyTypeEntity"); }
		//////////////////////
		virtual CString ToString();
		//////////////////////
		float NP;			// number properties
		// Form1 - Levels
		std::vector<int> Ls;		// pointer to associated level numbers
		// Form2 - RegionRestriction not handled
		int EVR, ECPR, ECCRR;		// pointer to associated level numbers
		// Form3 - not handled
		int FC, FD;
		// Form15 - Name
		CString Name;
	};



	class IgesModel
	{
	public:

		IgesModel() {  }
		~IgesModel(){ Clear(); }
		//////////////////////
		void Clear();
		void *  Read(CString szFilename);
		void *  Write(CString szFilename);
		Entity * AddEntity(Entity * pEntity);
		void SetFilename(CString);
		void SetAuthor(CString);
		void SetOrganization(CString );
		void SetUnits(Units );
		void SetDateTime(FILETIME );


		Entity * CreateIgesModelFromFile(CString str);
		HRESULT  ExtractParams(Entity *, CString);
		CString ToString(); 
		double GetResolution(){ return m_dResolution; }
		void SetResolution(double dResolution){ m_dResolution=dResolution; }
		//	Entity * FindEntity(int n) { return gEntities.igesGetEntity(n); }
		//		void  ComputeMinsMaxs();
		double GetMax();

		ModelGlobals gIgesGlobals;

		static std::vector<ColorMap> igesColorIndex;
		CString sParameterDelimiter,sRecordDelimiter,sProductId,sFilename,sSystemId,sPreprocessVersion;	// 1
		int nIntegerBits,nMaxPowerTenFloat,nFloatingSignificantDigits,nMaxPowerTenDouble,nFloatingSignificantDigitsDbl;				// 7
		CString sProductIdReceiving;	// 12
		float dModelSpaceScale;		// 13
		int nUnits;	// 14  1=inches, 2=mm, 3=, 4=feet, 5=miles, 6=meters
		CString sUnits;	// 15
		int nMaxNumberLineWeight;	// 16
		float dMaxLineWeightInUnits;	// 17
		CString sDateTime;	// 18
		float dMinResolution;	// 19
		float dMaxCoordinateValue;	// 20
		CString sAuthor;	// 21
		CString sOrganization;	// 22
		int nIgesVersion;	// 22
		int nDraftingStandard;	// 23
		CString sSpecial1;	// 24
		CString sSpecial2;	// 25

		CString errmsg;
		long m_nCurrentLine;
		double m_dResolution;


	};

};