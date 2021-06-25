//
// linalg3dImpl.h
  
inline Mtx inverse(Mtx &A) 
{
    Mtx AInv; // [3][3];
    AInv(0,0) = A(1,1)*A(2,2)-A(1,2)*A(2,1);
    AInv(0,1) = A(0,2)*A(2,1)-A(0,1)*A(2,2);
    AInv(0,2) = A(0,1)*A(1,2)-A(0,2)*A(1,1);
    AInv(1,0) = A(1,2)*A(2,0)-A(1,0)*A(2,2);
    AInv(1,1) = A(0,0)*A(2,2)-A(0,2)*A(2,0);
    AInv(1,2) = A(0,2)*A(1,0)-A(0,0)*A(1,2);
    AInv(2,0) = A(1,0)*A(2,1)-A(1,1)*A(2,0);
    AInv(2,1) = A(0,1)*A(2,0)-A(0,0)*A(2,1);
    AInv(2,2) = A(0,0)*A(1,1)-A(0,1)*A(1,0);
    REAL fDet = A(0,0)*AInv(0,0) + A(0,1)*AInv(1,0) +
        A(0,2)*AInv(2,0);
    if (fabs(fDet) < ZeroTolerance)
    {
       throw;
    }

    REAL fInvDet = ((REAL)1.0)/fDet;
    for (int iRow = 0; iRow < 3; iRow++)
    {
        for (int iCol = 0; iCol < 3; iCol++)
        {
            AInv(iRow,iCol) *= fInvDet;
        }
    }
	return AInv;
}

inline REAL Mtx::Determinant() 
{
	Mtx &m=*this;
	return
		m(0,3) * m(1,2) * m(2,1) * m(3,0)-m(0,2) * m(1,3) * m(2,1) * m(3,0)-m(0,3) * m(1,1) * m(2,2) * m(3,0)+m(0,1) * m(1,3)    * m(2,2) * m(3,0)+
		m(0,2) * m(1,1) * m(2,3) * m(3,0)-m(0,1) * m(1,2) * m(2,3) * m(3,0)-m(0,3) * m(1,2) * m(2,0) * m(3,1)+m(0,2) * m(1,3)    * m(2,0) * m(3,1)+
		m(0,3) * m(1,0) * m(2,2) * m(3,1)-m(0,0) * m(1,3) * m(2,2) * m(3,1)-m(0,2) * m(1,0) * m(2,3) * m(3,1)+m(0,0) * m(1,2)    * m(2,3) * m(3,1)+
		m(0,3) * m(1,1) * m(2,0) * m(3,2)-m(0,1) * m(1,3) * m(2,0) * m(3,2)-m(0,3) * m(1,0) * m(2,1) * m(3,2)+m(0,0) * m(1,3)    * m(2,1) * m(3,2)+
		m(0,1) * m(1,0) * m(2,3) * m(3,2)-m(0,0) * m(1,1) * m(2,3) * m(3,2)-m(0,2) * m(1,1) * m(2,0) * m(3,3)+m(0,1) * m(1,2)    * m(2,0) * m(3,3)+
		m(0,2) * m(1,0) * m(2,1) * m(3,3)-m(0,0) * m(1,2) * m(2,1) * m(3,3)-m(0,1) * m(1,0) * m(2,2) * m(3,3)+m(0,0) * m(1,1)    * m(2,2) * m(3,3);
} 

inline void dswap(REAL &X, REAL &Y) { REAL tmp(X); X=Y; Y=tmp; }
inline Mtx Mtx::Transpose() const
{
	Mtx m(*this);
	//int idx = 0;
	//for ( int row = 0; row < order; ++row )
	//	for ( int col = 0; col < order; ++col, ++idx )
	//		m.data[ idx ] = data[ row + ( col * 4 ) ];

	 for ( int i = 0; i < order; ++i) {
       for ( int j = i +1; j < order; ++j)
         dswap( m( i, j), m( j, i)); // need a swap function not provided here
     }
	return m;

}
// Creates a scale matrix
inline Mtx Scale( const Vec &scale )
{
	Mtx m;
	m.data[ 0 + 0 ] = scale.x;
	m.data[ 4 + 1 ] = scale.y;
	m.data[ 8 + 2 ] = scale.z;
	return m;
}

// Creates a translation matrix
inline Mtx Translate( const Vec &moveAmt )
{
	Mtx m;
	m.data[ 0 + 3 ] = moveAmt.x;
	m.data[ 4 + 3 ] = moveAmt.y;
	m.data[ 8 + 3 ] = moveAmt.z;
	return m;
}

inline Mtx RotateX( REAL ang )
{
	REAL s = ( REAL ) sin(  ang  );
	REAL c = ( REAL ) cos(  ang  );

	Mtx m;
	m.data[ 4 + 1 ] = c; m.data[ 4 + 2 ] = -s;
	m.data[ 8 + 1 ] = s; m.data[ 8 + 2 ] = c;
	return m;
}

inline Mtx RotateY( REAL ang )
{
	REAL s = ( REAL ) sin(  ang  );
	REAL c = ( REAL ) cos(  ang  );

	Mtx m;
	m.data[ 0 + 0 ] = c; m.data[ 0 + 2 ] = s;     
	m.data[ 8 + 0 ] = -s; m.data[ 8 + 2 ] = c;   
	return m;
}

// Creates an euler rotation matrix (by Z-axis)

inline Mtx RotateZ( REAL ang )
{
	REAL s = ( REAL ) sin( ang  );
	REAL c = ( REAL ) cos(  ang  );

	Mtx m;
	m.data[ 0 + 0 ] = c; m.data[ 0 + 1 ] = -s;
	m.data[ 4 + 0 ] = s; m.data[ 4 + 1 ] = c;
	return m;
}

// Creates an euler rotation matrix (pitch/head/roll (x/y/z))
inline Mtx Rotate( REAL pitch, REAL head, REAL roll )
{
	REAL sp(  pitch  ), cp (cos(  pitch  ));  // REAL sp(  pitch  ) is this an error?
	REAL sh(  sin(  head  )), ch ( cos(  head  ));
	REAL sr (  sin(  roll  )),  cr (cos(  roll  ));

	Mtx m;
	m.data[ 0 + 0 ] = cr * ch - sr * sp * sh;
	m.data[ 0 + 1 ] = -sr * cp;
	m.data[ 0 + 2 ] = cr * sh + sr * sp * ch;

	m.data[ 4 + 0 ] = sr * ch + cr * sp * sh;
	m.data[ 4 + 1 ] = cr * cp;
	m.data[ 4 + 2 ] = sr * sh - cr * sp * ch;

	m.data[ 8 + 0 ] = -cp * sh;
	m.data[ 8 + 1 ] = sp;
	m.data[ 8 + 2 ] = cp * ch;
	return m;
}


// Creates an arbitraty rotation matrix
inline Mtx MakeRotationMatrix( const Vec &dir, const Vec &up )
{
	Vec x = Cross( up, dir ), y = Cross( dir, x ), z = dir;
	Mtx m;
	m.data[ 0 ] = x.x; m.data[ 1 ] = x.y; m.data[ 2 ] = x.z;
	m.data[ 4 ] = y.x; m.data[ 5 ] = y.y; m.data[ 6 ] = y.z;
	m.data[ 8 ] = z.x; m.data[ 9 ] = z.y; m.data[ 10 ] = z.z;
	return m;
}

/**
	\relates Mtx
Given angle r in radians and unit vector u = ai + bj + ck or [a,b,c]', define:
\code
q0 = cos(r/2),  q1 = sin(r/2) a,  q2 = sin(r/2) b,  q3 = sin(r/2) c

we do need [a,b,c]' to have unit length, and by our construction the
"quaternion" q0,q,q2,q3 must then also have unit length

and construct from these values the rotation matrix:

     (q0² + q1² - q2² - q3²)      2(q1q2 - q0q3)          2(q1q3 + q0q2)

Q  =      2(q2q1 + q0q3)     (q0² - q1² + q2² - q3²)      2(q2q3 - q0q1)

          2(q3q1 - q0q2)          2(q3q2 + q0q1)     (q0² - q1² - q2² + q3²)

Multiplication by Q then effects the desired rotation, and in particular:

Q u = u
\endcode
*/
inline Matrix MakeQRotationAroundAxis(Vector v, double dRadian)
{
	Matrix m;
	double a=v.x, b=v.y, c=v.z;
	double q0=cos(dRadian/2.0);
	double q1=sin(dRadian/2.0)*a;
	double q2=sin(dRadian/2.0)*b;
	double q3=sin(dRadian/2.0)*c;
	m.data[0]=q0*q0+q1*q1-q2*q2-q3*q3;
	m.data[1]=2 * (q1*q2-q0*q3);
	m.data[2]=2*(q1*q3+q0*q2);

	m.data[4]=2* (q2*q1+q0*q3);
	m.data[5]=q0*q0-q1*q1+q2*q2-q3*q3;
	m.data[6]=2*(q2*q3-q0*q1);

	m.data[8]=2*(q3*q1-q0*q2);
	m.data[9]=2*(q3*q2+q0*q1);
	m.data[10]=q0*q0-q1*q1-q2*q2+q3*q3;
	return m;
}
// Transforms a vector by a matrix
inline Vec operator * ( const Vec& v, const Mtx& m )
{
	return Vec(
		m.data[ 0 ] * v.x + m.data[ 1 ] * v.y + m.data[ 2 ] * v.z + m.data[ 3 ],
		m.data[ 4 ] * v.x + m.data[ 5 ] * v.y + m.data[ 6 ] * v.z + m.data[ 7 ],
		m.data[ 8 ] * v.x + m.data[ 9 ] * v.y + m.data[ 10 ] * v.z + m.data[ 11 ] );
}

// Transforms a vector by a matrix
inline Vec operator * ( const Mtx& m, const Vec& v )
{
	return Vec(
		m.data[ 0 ] * v.x + m.data[ 1 ] * v.y + m.data[ 2 ] * v.z + m.data[ 3 ],
		m.data[ 4 ] * v.x + m.data[ 5 ] * v.y + m.data[ 6 ] * v.z + m.data[ 7 ],
		m.data[ 8 ] * v.x + m.data[ 9 ] * v.y + m.data[ 10 ] * v.z + m.data[ 11 ] );
}

// Multiplies a matrix by another matrix

inline Mtx operator * ( const Mtx& a, const Mtx& b )
{
	Mtx ans;
	for ( int aRow = 0; aRow < 4; ++aRow )
		for ( int bCol = 0; bCol < 4; ++bCol )
		{
			int aIdx = aRow * 4;
			int bIdx = bCol;

			REAL val = 0;
			for ( int idx = 0; idx < 4; ++idx, ++aIdx, bIdx += 4 )
				val += a.data[ aIdx ] * b.data[ bIdx ];
			ans.data[ bCol + aRow * 4 ] = val;
		}
		return ans;
}

extern bool Solve3 (Mtx & A, Vec & B,  Vec & X);

// Perspective is along the z-axis with the eye at +z.
  
inline Mtx	Perspective	(Mtx &m, REAL d)
{
	Mtx tmp(m);
	double	f = 1. / d;
	for (int i = 0 ; i < 4 ; i++) {
		tmp.data[i*4+3] += tmp.data[i*4+2]*f;
		tmp.data[i*4+2]  = 0;
	}
	return (tmp);
}



