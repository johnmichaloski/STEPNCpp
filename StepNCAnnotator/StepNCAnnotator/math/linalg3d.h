//
// linalg3d.h
//
#pragma once

#include "Misc.h"  // Include for debugging purposes

#include <cmath>
#pragma warning( disable : 4244)
#pragma warning( disable : 4305)

#define EPSILON 0.00001f
#define PI 3.1415926
#define TwoPI 6.28318531
#define Deg2Rad(Ang) ((REAL)( Ang * PI / 180.0 ))
#define Rad2Deg(Ang) ((REAL)( Ang * 180.0 / PI ))
#define Sq(X) (X*X)
#define Eq(X,Y,Z) fabs((X-Y)<Z)
#define sign(x) ((x>=0)?  1 : -1 );
#define ZeroTolerance (0.00000001)

#define REAL float


// REAL sqrt(REAL f) { if(f<0) throw; else return ::sqrt(f); }

// =========================================
// 3-vector
// =========================================
class Vec
{
public:
	
	REAL x, y, z, w; // Position & weight
	Vec(): x( 0 ), y( 0 ), z( 0 ), w(1) {} // Default constructor
	Vec( REAL x, REAL y, REAL z ) : x( x ), y( y ), z( z ), w(1) 	{} // Element constructor
	Vec( REAL x, REAL y, REAL z, REAL w ) : x( x ), y( y ), z( z ), w(w) 	{} // Element constructor
	Vec( const Vec& a )	: x( a.x ), y( a.y ), z( a.z ) , w(a.w)	{}// Copy constructor
	REAL & operator ()(int n) { return ( (n==0)?  x : (n==1) ? y: z ); }
	Vec &operator += ( const Vec &src ) { x += src.x; y += src.y; z += src.z; w += src.w; return *this; }
	Vec operator + ( const Vec &src ) const { Vec tmp( *this ); return ( tmp += src ); }
	Vec &operator -= ( const Vec &src ) { x -= src.x; y -= src.y; z -= src.z; w -= src.w; return *this; }
	Vec operator - ( const Vec &src ) const { Vec tmp( *this ); return ( tmp -= src ); }
	Vec operator - () const { return Vec(-x,-y,-z); }
	Vec &operator *= ( const REAL src ) { x *= src; y *= src; z *= src;  w *= src; return *this; }
	Vec operator * ( const REAL src ) const { Vec tmp( *this ); return ( tmp *= src ); }
	Vec &operator /= ( const REAL src ) { x /= src; y /= src; z /= src; w /= src; return *this; }
	Vec operator / ( const REAL src ) const { Vec tmp( *this ); return ( tmp /= src ); }
	bool operator == ( const Vec& b) const { return ((*this)-b).Norm() < EPSILON; }
	//	REAL & operator () (int i) { REAL & ptrD(x); return ptrD+=(sizeof(REAL)*i); }
	//bool operator == ( const Vec& b) const { return x==b.x && y==b.y && z==b.z; }
	inline REAL Norm() const { return x*x + y*y + z*z; } // Norm (len^2)
	inline REAL Len() const { return sqrt(Norm()); } // Length of the vector
	Vec Normalize(){ Vec tmp( *this ); return ( tmp /= Len() ); }
	Vec Inverse(){ Vec tmp( *this ); return ( tmp /= Norm() ); }

	enum {XY=3, XZ=5, YZ=6, ZX=7}; // change with vector array of ordering, 0 if none.
	Vec Slice(int nBits) { 
		Vec tmp(*this);   
		if (nBits==XZ) tmp.y=tmp.z; 
		else if (nBits==YZ) { tmp.x=tmp.y; tmp.y=tmp.z; }
		else if(nBits==ZX) { tmp.y=tmp.x; tmp.x=tmp.z; }
		tmp.z=0;
		return tmp;
	}
	Vec Unslice(int nBits) { 
		Vec tmp(*this);   
		if (nBits==XZ) tmp.z=tmp.y; 
		else if (nBits==YZ) { tmp.y=tmp.x; tmp.z=tmp.y; }
		return tmp;
	} 
	CString ToString(){ CString buf; buf.Format( "%f %f %f", x,y,z); return  buf ; /*Not reentrant*/}
};

inline REAL Dot(const  Vec& a,const  Vec& b ) { return a.x*b.x + a.y*b.y + a.z*b.z; }
inline Vec Cross( const Vec &a, const Vec &b ) { return Vec( a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x ); }
inline REAL Displacement(Vec & u ,Vec &v) { return Vec(u-v).Len(); } 
inline Vec  Projection( Vec & v1,  Vec  &v2) { Vec tmp1(v2.Normalize()); return tmp1*=Dot(  v1, tmp1);}
inline Vec  CartPlaneProj( Vec &v,  Vec &normal) { return v-Projection(v, normal);}
inline Vec  Lerp( Vec &v1,  Vec &v2, REAL scale) { Vec tmp1( v1 ); Vec tmp2(v2-v1); tmp2*=scale; return tmp1+=tmp2; }
inline bool Perpendicular(const Vec &v1, const Vec &v2) { return (Dot(v1,v2)==0); }
inline bool Parallel( Vec &v1,  Vec &v2) { return ( Vec (v1.Normalize() - v2.Normalize()).Len()<EPSILON); }
inline REAL atan360(REAL y1, REAL x1){ REAL a (atan2(y1,x1));	return (a<0)?	a+ TwoPI : a; }
inline Vec VMin(Vec & v1, Vec & v2){ return Vec((v1.x<v2.x)? v1.x : v2.x, (v1.y<v2.y)? v1.y : v2.y, (v1.z<v2.z)? v1.z : v2.z); }
inline Vec VMax(Vec & v1, Vec & v2){ return Vec((v1.x>v2.x)? v1.x : v2.x, (v1.y>v2.y)? v1.y : v2.y, (v1.z>v2.z)? v1.z : v2.z); }
inline bool VGt(Vec & v1, Vec & v2){ return (v1.x>v2.x) || (v1.y>v2.y) || (v1.z>v2.z); }
inline bool VLt(Vec & v1, Vec & v2){ return (v1.x<v2.x) || (v1.y<v2.y) || (v1.z<v2.z); }

// make this a template type?
inline Vec operator * ( const REAL src, const Vec& v ) { Vec tmp( v ); return ( tmp *= src ); }


typedef Vec Vector;

// =========================================
// 4 x 4 matrix
// =========================================
class Mtx
{
public:

	const static int order=4;
	// 4x4, [[0 1 2 3] [4 5 6 7] [8 9 10 11] [12 13 14 15]]
	REAL data[ 16 ];

	// Creates an identity matrix
	Mtx()
	{
		static REAL IdentityMatrix[16] = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };
		memcpy(this,&IdentityMatrix,sizeof(REAL)*16);
		//for ( int i = 0; i < 16; ++i )
		//	data[ i ] = 0;
		//data[ 0 + 0 ] = data[ 4 + 1 ] = data[ 8 + 2 ] = data[ 12 + 3 ] = 1;
	}
	Mtx( const Mtx& a )	{ memcpy(this,&a,sizeof(Mtx));}
	Mtx( REAL d11, REAL d12, REAL d13,REAL d14,
		REAL d21, REAL d22, REAL d23, REAL d24,
		REAL d31, REAL d32, REAL d33, REAL d34,
		REAL d41, REAL d42, REAL d43, REAL d44)
	{ 
		Load (d11,  d12,  d13, d14,d21,  d22,  d23,  d24, d31,  d32,  d33,  d34, d41,  d42,  d43,  d44); 
	}
	// Operators
	Mtx & operator /=(REAL d) { for ( int i = 0; i < order*order; ++i ) data[i] /= d;  return *this; }
	Mtx & operator *=(REAL d) { for ( int i = 0; i < order*order; ++i ) data[i] *= d;  return *this; }
	//!!
	REAL operator () ( unsigned column, unsigned row )	{ return data[ column + ( row * 4 ) ]; }
	REAL & operator ()(int row, int col) { return data[row * 4 + col]; }

	void Load( REAL d11, REAL d12, REAL d13,REAL d14,
		REAL d21, REAL d22, REAL d23, REAL d24,
		REAL d31, REAL d32, REAL d33, REAL d34,
		REAL d41, REAL d42, REAL d43, REAL d44)
	{ 
		va_list ap;
		va_start(ap, d11);
		memcpy(&this->data,ap-sizeof(REAL),sizeof(REAL)*16);
		va_end(ap);
	}

	// Returns the transpose of this matrix
	Mtx Transpose() const;

	REAL Determinant();

	CString ToString(){ return StrFormat("%f %f %f %f \n%f %f %f %f \n%f %f %f %f \n%f %f %f %f \n",
		data[0],data[1],data[2],data[3],data[4],data[5],data[6],data[7],data[8],data[9],data[10],data[11],data[12],data[13],data[14],data[15]);
	}
	Mtx Rotation() { Mtx tmp(*this);  tmp.data[3]=tmp.data[7]=tmp.data[11]=0; tmp.data[15]=1;  return tmp; }
	Vector Translation() { Vector tmp( data[3],data[7],data[11],data[15]);  return tmp; }
	bool IsIdentity() { 
		static REAL IdentityMatrix[16] = { 1,0,0,0, 0,1,0,0, 0,0,1,0, 0,0,0,1 };
		return memcmp(this,&IdentityMatrix,sizeof(REAL)*16)==0; 
	} 

};

typedef Mtx Matrix;

// Creates a scale matrix
inline Mtx Scale( const Vec &scale );

// Creates a translation matrix
inline Mtx Translate( const Vec &moveAmt );

// Creates an euler rotation matrix (by X-axis)
inline Mtx RotateX( REAL ang );

// Creates an euler rotation matrix (by Y-axis)
inline Mtx RotateY( REAL ang );

// Creates an euler rotation matrix (by Z-axis)
inline Mtx RotateZ( REAL ang );

// Creates an euler rotation matrix (pitch/head/roll (x/y/z))
inline Mtx Rotate( REAL pitch, REAL head, REAL roll );

// Creates an arbitraty rotation matrix
inline Mtx MakeRotationMatrix( const Vec &dir, const Vec &up );
// Transforms a vector by a matrix
inline Vec operator * ( const Vec& v, const Mtx& m );

// Transforms a vector by a matrix
inline Vec operator * ( const Mtx& m, const Vec& v );

// Multiplies a matrix by another matrix
inline Mtx operator * ( const Mtx& a, const Mtx& b );

extern bool Solve3 (Mtx & A, Vec & B,  Vec & X);

inline Mtx Inverse(Mtx &A) ;
inline Matrix MakeQRotationAroundAxis(Vector v, double dRadianAngle);

/* Perspective is along the z-axis with the eye at +z. d =Perspective distance		*/  
inline Mtx	Perspective	(Mtx &m, REAL d);

// =========================================
// Plane
// =========================================
class Plane
{
public:
	enum PLANE_EVAL
	{
		EVAL_COINCIDENT,
		EVAL_IN_BACK_OF,
		EVAL_IN_FRONT_OF,
		EVAL_SPANNING
	};

	Vec normal;
	REAL d;

	// Default constructor
	Plane(): normal( 0,1,0 ), d( 0 ) {}

	// Vector form constructor
	//   normal = normalized normal of the plane
	//   pt = any point on the plane
	Plane( const Vec& normal, const Vec& pt )
		: normal( normal ), d( Dot( -normal, pt )) 
	{}

	// Copy constructor
	Plane( const Plane& a )
		: normal( a.normal ), d( a.d ) 
	{}

	// Classifies a point (<0 == back, 0 == on plane, >0 == front)
	REAL classify( const Vec& pt ) const
	{
		REAL f = Dot( normal, pt ) + d;
		return ( f > -EPSILON && f < EPSILON ) ? 0 : f;
	}
};

//----------------------------------------------------------------------------
/** Compute the factorial.
 * give - an object who's type has operator++, operator=, operator<=, and operator*= defined.
 *        it should be a single valued scalar type such as an int, float, REAL etc....
 * NOTE: This could be faster with a lookup table, but then wouldn't work templated : kevin
 */
template<class T>
inline T factorial(T rhs)
{
   T lhs = (T)1;

   for( T x = (T)1; x <= rhs; ++x )
   {
      lhs *= x;
   }

   return lhs;
}
/** @} */

/**
 * clamp "number" to a range between lo and hi
 */
template <class T>
inline T clamp( T number, T lo, T hi )
{
   if (number > hi) number = hi;
   else if (number < lo) number = lo;
   return number;
}

/** @ingroup Interp
 * @name Scalar type interpolation (for doubles, floats, etc...)
 * @{
 */

/** Linear Interpolation between number [a] and [b].
 *  lerp=0.0 returns a, lerp=1.0 returns b
 *  @pre use REAL or float only...
 */
template <class T, typename U>
inline void lerp( T& result, const U& lerp, const T& a, const T& b )
{
    T size = b - a;
    result = ((U)a) + (((U)size) * lerp);
}
/** @} */

/**
 * Uses the quadratic formula to compute the 2 roots of the given 2nd degree
 * polynomial in the form of Ax^2 + Bx + C.
 *
 * @param r1   set to the first root
 * @param r2   set to the second root
 * @param a    the coefficient to x^2
 * @param b    the coefficient to x^1
 * @param c    the coefficient to x^0
 *
 * @return  true if both r1 and r2 are real; false otherwise
 */
template <class T>
inline bool quadraticFormula(T& r1, T& r2, const T& a, const T& b, const T& c)
{
   const T q = b*b - T(4)*a*c;

   // the result has real roots
   if (q >= 0)
   {
      const T sq = gmtl::Math::sqrt(q);
      const T d = T(1) / (T(2) * a);
      r1 = (-b + sq) * d;
      r2 = (-b - sq) * d;
      return true;
   }
   // the result has complex roots
   else
   {
      return false;
   }
}

#include "linalg3dImpl.h"