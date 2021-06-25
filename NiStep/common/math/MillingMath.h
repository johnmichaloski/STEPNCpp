// 
// MillingMath.h
//


#pragma once
#include <boost/tuple/tuple.hpp>

typedef boost::tuple<int, double, double, double> ToolingTuple; 

typedef float Real;       
typedef Real Point2d [2];        /* 2d point */
typedef Real Point3d [3];        /* 3d point */
typedef Real Point4d [4];
typedef unsigned short ushort;
/* 2d line */
struct Line2D
{
	Point2d e1;                  /* The first endpoint */
	Point2d e2;                  /* The second endpoint */
} ;                   

/* 3d line */
struct  Line3D
{
	Point3d e1;                  /* The first endpoint */
	Point3d e2;                  /* The second endpoint */
} ; 

/* 2d arc */
struct Arc2D
{
	Point2d c;                   /* Arc center */
	Real r;                   /* Arc radius */
	Real sa;                  /* Start angle in radians */
	Real sw;                  /* Sweep angle in radians */
} ;                   

/* 3d arc */
struct Arc3D
{
	Point3d ep1, ep2;    /* Arc endpoints */
	Point3d c;           /* Arc center, relative to view */
	Real r;           /* Arc radius */
	Real sa;          /* Start angle in radians */
	Real sw;          /* Sweep angle in radians */
} ;           


/* 
Parametric spline 	   
spline sp;
alloc_spline_data_ptr (&sp);
if (sp.c_ptr != NULL && 
(sp.data_ptr_index == 0 || sp.data_ptr_index == 1))
mprintf ("PASS\n");
*/
struct  ParametricSpline
{
	Point3d e1, e2;    /* The endpoints */
	Real t1;        /* The t parameter corresponding to e1 */
	Real t2;        /* The t parameter corresponding to e2 */
	Real max_curv;  /* Maximum curvature */
	short n_segs;   /* Number of segments */
	byte ord;       /* The order of the polynomial */
	byte dim;       /* The dimension: 2 for 2d, 3 for 3d */
	//byte dummy;     /* A filler */
	boolean closed; /* True if spline is closed (endpoints are equal) */
	//byte pad[2];    /* pad entity to 8 bytes */
	//eptr_type ent_ptr; /* The entity pointer */
	//long pad1;      /* Filler */
	//byte pad2;      /* Filler */
	//boolean ram;    /* True if entity stored in RAM */

	short data_ptr_index; /* The data pointer index  */ 
	Real *c_ptr;    /* The coefficient pointer */
} ;           

/* NURBS curve */
struct NURBS        
{
	Point3d e1, e2;        /* endpoints */
	Real t1, t2, maxc;  /* beg, end parameters, max curvature */
	Real normal[3];     /* if planar, normal to plane of curve */
	short nk;           /* number of knots */
	short np;           /* number of control points */
	byte deg;           /* degree */
	byte dim;           /* dimension, includes weight in rational case */
	struct
	{
		ushort planar   :1;    /* Set to 1 if planar */
		ushort closed   :1;    /* Set to 1 if closed */
		ushort non_rat  :1;    /* Set to 1 if non-rational */
		ushort periodic :1;    /* Set to 1 if periodic */
		ushort uniform  :1;    /* Set to 1 if uniform */
		ushort filler   :11;   /* Filler */
	} flags;

	Real *k_ptr;        /* points to knots array */
	Real *cp_ptr;       /* points to control points array */
	//eptr_type ent_ptr;  /* Used if entity overflows to disk */
	//short data_ptr_index; /* Used if entity overflows to disk */
	//boolean ram;        /* Used if entity overflows to disk */
	//byte pad;           /* Filler */
} ;


class MillingProcess
{
public:

	double LookupSfm(CString szToolMaterial, CString szPartMaterial) { return 0; }
	double ComputeSpindleSpeed(double sfm, double diameter)
	{
		_rpm = (12.0 * sfm)/( 3.1415926535 * diameter);
		return _rpm;
	}
	double ComputeFeedrate(double spindlespeed /* rpm */, double feedpertooth /*length/tooth*/, int nTeeth)
	{
		_feed = spindlespeed /*rpm*/ * feedpertooth * (double) nTeeth;
		return _feed; // length/min  e.g., mm/min or in/min
	}
	double CuttingSpeed(double inchDiameter)  
	{

	}
	//double CuttingSpeed(double mmDiameter)
	//{

	//}
	// Qd - Volume of metal remove - input mm units or inch units work  in^3/min
	double RateOfMetalRemoval(double dWidthCut, double dDepthCut,  double feed) 
	{
		double Qm = dWidthCut * dDepthCut * feed; 
		return Qm;
	}

	// return hp given: k metal constant, E is efficiency (around .7-.85) 
	double Horsepower(double k, double Qd, double E) { return (k *Qd )/ E; }

	// return hps - hp = 33,000 ftlb/min = 550 ft lb /sec
	double SpindleTorque(double hp, double rpm /* part rpm*/) { double hps = 550 * hp / 33000; return (63030 * hps )/ rpm; }


	// drilling, milling, turning
	typedef boost::tuple<double, double, double> KHorsepowerTuple; 
	std::map<CString, KHorsepowerTuple> _kHorsepowerlist;

	void InitKHorsepower()
	{
		//_toollist.push_back("Mild Steel 25RC", ToolingTuple(1.0, 1.0, .9));
		//_toollist.push_back("Mild Steel 30RC", ToolingTuple(1.6, 1.8, 1.3));
		//_toollist.push_back("Mild Steel 50RC", ToolingTuple(1.9, 2.1, 1.5));
		//_toollist.push_back("Soft Cast Iron", ToolingTuple(.8, .7, .5));
		//_toollist.push_back("Hard Cast Iron", ToolingTuple(.9, 1.1, 1.0));
		//_toollist.push_back("Aluminum", ToolingTuple(.35, .4, .3));
		//_toollist.push_back("Brass", ToolingTuple(.5, .6, .4));
		//_toollist.push_back("Bronze", ToolingTuple(.6, .8, .7));
		//_toollist.push_back("Stainless 400", ToolingTuple(1.3, 1.3, 1.1));
		//_toollist.push_back("Stainless 300", ToolingTuple(1.6, 1.8, 1.7));
		//_toollist.push_back("Titanium", ToolingTuple(1.0, 1.0, 1.1));
		//_toollist.push_back("Nickel Alloys", ToolingTuple(1.6, 1.6, 1.5));
	}
	double _rpm;
	double _feed;
};

class DrillingProcess
{
public:


};