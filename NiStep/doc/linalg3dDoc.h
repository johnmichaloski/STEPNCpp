//
// linalg3dDoc.h Documentation
//
// http://www.digilife.be/quickreferences/QRC/Doxygen%20Quick%20Reference.pdf
// latex notes: http://ctan.tug.org/tex-archive/info/lshort/english/lshort.pdf 
// http://www.artofproblemsolving.com/LaTeX/AoPS_L_GuideCommands.php
// http://en.wikipedia.org/wiki/Help:Formula
// http://my.supa.ac.uk/mod/glossary/view.php?id=1138&mode=cat&hook=17
/** \class Vec
A vector describes an ordered 3-tuple \f$(x, y, z)\f$ where x, y and z are real numbers.
*/

/** \fn inline REAL Vec::Norm() const
Returns \f$ \parallel v \parallel =x^2 + y^2 + z^2\f$.
*/

/** \fn inline REAL Vec::Len() const
Returns a vectors euclidean length, defined as 
\f$ \parallel v \parallel  = \sqrt{x^2+y^2+z^2} \f$
*/

/** \fn Vec Vec::Normalize()
Normalizes the vector to a unit vector:
\f$ \hat{u} = \frac{u}{\parallel u \parallel} \f$
A unit vector is often denoted by a lowercase letter with a superscribed caret or "hat", 
but is frequently represented by the vector symbool \f$\vec{u}\f$ also.
*/

/** \fn Vec Vec::Slice(int nBits)
Returns parts of the vector depending on the input bitmask. 
Bit 1 set return x.
Bit 2 set return y.
Bit 3 set return z.
\par Example
\code
Vec v1(1,2,3);
Vec v2= v1.Slice(3);
\endcode
v2 now contains (1,2,0).
@param nBits the bitmask to return values.
*/

/** \fn Vec Vec::CString ToString(CString sep=_T(""))
Returns a string of the xyz values.
@param sep defines the separator between  x y and z.
*/

/** \fn inline REAL Dot(const  Vec& a,const  Vec& b )
\relates Vec
Returns the dot product of two vectors.
The dot product between two vectors \f$(Ax,Ay,Az)\f$ and \f$(Bx,By,Bz)\f$ is calculated:
\f$ A \cdot  B = AxBx +  AyBy + AzBz \f$
@param a defines vector A
@param b defines vector B
*/
/** \fn Vec Cross( const Vec &a, const Vec &b ) 
\relates Vec
Returns the cross product of two vectors.

If you have 2 vectors then the cross product will return a vector which is perpendicular (ie at a right angle) to both of them.
The cross product between two vectors (Ax,Ay,Az) and (Bx,By,Bz) is:
 
\f$ A \times  B = ( AyBz -  AzBy, AzBy -  AxBz, AxBy -  AyBx ) \f$

@param a defines vector A
@param b defines vector B
*/


/** \fn inline REAL Displacement(Vec & u ,Vec &v)
\relates Vec
Defined here as a magnitude given as the length between vectors u and v,
returns
Vec(u-v).Len(); 
\f$  \| u-v \| \f$

*/
/** \fn inline Vec  Projection( Vec & v1,  Vec  &v2)
\relates Vec
The vector projection of v2 onto v1 is the vector with this length that begins 
at the point v1 points in the same direction (or opposite direction if the scalar projection is negative) as v1.

\f$  \hat{v_2} ( v_1 \cdot  \hat{v_2} ) \f$

\par Example
For an arc, the center vector and start vector are assumed to be in the plane defined by the normal vector. 
If this is not true, then it will be made true by moving the center vector onto the plane, where normal = (0,0,1).
\code
		center=Projection(start-center, normal)+ center; 
\endcode
*/
/** \fn inline Vec  CartPlaneProj( Vec &v,  Vec &normal) 
\relates Vec
return v-Projection(v, normal)
*/
/** \fn inline Vec  Lerp( Vec &v1,  Vec &v2, REAL scale) 
\relates Vec
Linear Interpolation, the formula is  p(u) = x + u * (b-a)   0<=u<=1
where a and b are the two points to interpolate between and u indicates the 
ratio along the line from a to b of the desired point.
Calling parameters correspond to: a=v1, b=v2, u = scale.
*/
/** \fn inline bool Perpendicular(const Vec &v1, const Vec &v2)
\relates Vec
Determine if two vectors are perpendical by calculating dot product 
of the vectors and determining if it is less than \f$\epsilon\f$: 

\f$ \| v_1 \cdot v_2 \| < \epsilon \f$
*/
/** \fn inline bool Parallel( Vec &v1,  Vec &v2)
\relates Vec
Determine if two vectors are parallel by seeing if the two calculated unit vectors are identical. 

 \f$ \| \hat{v_1} - \hat{v_2} \| < \epsilon \f$
*/
/** \fn inline REAL atan360(REAL y1, REAL x1)
\relates Vec
Atan2 produces arctangent results in the range \f$ (-\pi, \pi] \f$  which atan360 maps 
to \f$[0,2\pi)\f$  by adding \f$2\pi\f$  to negative values.
*/
/** \fn inline Vec VMin(Vec & v1, Vec & v2)
\relates Vec
Returns the minimum of each component of the two vectors. Useful for statistics.
return  return Vec((v1.x<v2.x)? v1.x : v2.x, (v1.y<v2.y)? v1.y : v2.y, (v1.z<v2.z)? v1.z : v2.z); 
*/
/** \fn inline Vec VMax(Vec & v1, Vec & v2)
\relates Vec
Returns the maximum of each component of the two vectors. Useful for statistics.
return Vec((v1.x>v2.x)? v1.x : v2.x, (v1.y>v2.y)? v1.y : v2.y, (v1.z>v2.z)? v1.z : v2.z); }
*/
/** \fn inline bool VGt(Vec & v1, Vec & v2)
\relates Vec
return (v1.x>v2.x) || (v1.y>v2.y) || (v1.z>v2.z); }
*/
/** \fn inline bool VLt(Vec & v1, Vec & v2)
\relates Vec
return (v1.x<v2.x) || (v1.y<v2.y) || (v1.z<v2.z); }
*/
/** \fn inline Vec Direction(Vec   v1, Vec   v2) 
\relates Vec
return \f$ v_2 - v_1\f$
*/

/** \class Mtx
4 x 4 matrix


*/

/** \fn void Mtx::Load( REAL d11, REAL d12, REAL d13,REAL d14,REAL d21, REAL d22, REAL d23, REAL d24,REAL d31, REAL d32, REAL d33, REAL d34,	REAL d41, REAL d42, REAL d43, REAL d44)
Loads 16 values into 4x4 homogeneous matrice and creates the following matrix:

\f[ 
\left ( \begin{array}{cccc}
d_{11} & d_{12} & d_{13} & d_{14} \\
d_{21} & d_{22} & d_{23} & d_{24}\\
d_{31} & d_{32} & d_{33} & d_{34}\\
d_{41} & d_{42} & d_{43} & d_{44}
\end{array} \right )
\f]

*/


/** \fn Mtx Mtx::Transpose() const
Returns the transpose of this matrix
For matrix \f$M\f$ returns  \f$M^T\f$.
*/

/** \fn REAL Mtx::Determinant()
\relates Mtx
Returns the determinant \f$det\left|M\right|\f$ of this matrix.
From Wikipedia: The fundamental geometric meaning of a determinant is a scale factor for measure when the matrix is 
regarded as a linear transformation. 
Thus a 2 x 2 matrix with determinant 2 when applied to a set of points with finite area will transform those points into a set with twice the area.
A matrix is invertible if and only if its determinant is non-zero.

*/

/** \fn CString Mtx::ToString()
\relates Mtx
*/
/** \fn Mtx Mtx::Rotation() 
\relates Mtx
Returns the rotational part \f$a,b,c,d,e,f,g,h,i\f$  of the matrix:

\f[ 
\left ( \begin{array}{cccc}
a & b & c & x \\
d & e & f & y \\
g & h & i & z \\
0 & 0 & 0 & w  
\end{array} \right )
\f]

as a new matrix.
*/

/** \fn Vector Mtx::Translation()
\relates Mtx
Returns the translation part (\f$x,y,z,w\f$ ) of the matrix:

\f[ 
\left ( \begin{array}{cccc}
a & b & c & x \\
d & e & f & y \\
g & h & i & z \\
0 & 0 & 0 & w  
\end{array} \right )
\f]
*/
/** \fn bool Mtx::IsIdentity() 
\relates Mtx
Returns true if the current matrix is the identity matrix.
*/

/** \fn inline Mtx Scale( const Vec &scale )
\relates Mtx
Given a vector \f$v = (x,y,z) \f$ creates the scale matrix:

\f[ 
\left ( \begin{array}{cccc}
x & 0 & 0 & 0 \\
0 & y & 0 & 0 \\
0 & 0 & z & 0 \\
0 & 0 & 0 & 1  
\end{array} \right )
\f]
*/

/** \fn inline Mtx Translate( const Vec &moveAmt )
\relates Mtx
Given a vector \f$v = (x,y,z) \f$ creates a translation matrix from it:

\f[ 
\left ( \begin{array}{cccc}
1 & 0 & 0 & x \\
0 & 1 & 0 & y \\
0 & 0 & 1 & z \\
0 & 0 & 0 & 1  
\end{array} \right )
\f]*/

*/

/** \fn inline Mtx RotateX( REAL ang )
\relates Mtx
Creates an euler rotation matrix (by X-axis)

\f[ 
\left ( \begin{array}{cccc}
1 & 0 & 0 & 0 \\
0 &  \cos(\theta) & -\sin(\theta) & 0 \\
0 & \sin(\theta) & \cos(\theta) & 0 \\
0 & 0 & 0& 1  
\end{array} \right )
\f]
\f$ where\ \theta=ang \f$

*/  

/** \fn inline Mtx RotateY( REAL ang )
\relates Mtx
Creates an euler rotation matrix (by Y-axis)

\f[ 
\left ( \begin{array}{cccc}
\cos(\theta)& 0 & -\sin(\theta) & 0 \\
0 & 1 & 0 & 0 \\
-\sin(\theta) & 0 & \cos(\theta) & 0 \\
0 & 0 & 0& 1  
\end{array} \right )
\f]
\f$ where\ \theta=ang \f$

*/  

/** \fn inline Mtx RotateZ( REAL ang )
\relates Mtx
// Creates an euler rotation matrix (by Z-axis)

\f[ 
\left ( \begin{array}{cccc}
\cos(\theta)& -\sin(\theta) & 0 & 0 \\
\sin(\theta) &  \cos(\theta) & 0& 0 \\
0 & 0 & 1 & 0 \\
0 & 0 & 0& 1  
\end{array} \right )
\f]
\f$ where\ \theta=ang \f$

*/  

/** \fn inline Mtx Rotate( REAL pitch, REAL head, REAL roll )
// Creates an euler rotation matrix (pitch/head/roll (x/y/z))
\relates Mtx
\code
\endcode
*/  

/** \fn inline Mtx MakeRotationMatrix( const Vec &dir, const Vec &up )
\relates Mtx
// Creates an arbitraty rotation matrix
\code
\endcode
*/  

/** \fn inline Vec operator * ( const Vec& v, const Mtx& m )
\relates Mtx
// Transforms a vector by a matrix
\code
\endcode
*/  

/** \fn inline Vec operator * ( const Mtx& m, const Vec& v )
\relates Mtx
// Transforms a vector by a matrix
\code
\endcode
*/  

/** \fn inline Mtx operator * ( const Mtx& a, const Mtx& b )
\relates Mtx
// Multiplies a matrix by another matrix
\code
\endcode
*/  

/** \fn bool Solve3 (Mtx & A, Vec & b,  Vec & X)
\relates Mtx
Solves the equation 
\f{eqnarray*} Ax&=&b \\
x&=&A^{-1}b
\f}
to find x.
This equation will have a nontrivial solution iff the determinant \f$det\left|A\right|\neq0\f$. 
Returns false if the determinant is zero.

*/  

/** \fn inline Mtx Inverse(Mtx &A) 
\relates Mtx
\code
\endcode
*/  


/** \fn inline Mtx	Perspective	(Mtx &m, REAL d);
Perspective is along the z-axis with the eye at +z. d =Perspective distance		
\relates Mtx
*/  
