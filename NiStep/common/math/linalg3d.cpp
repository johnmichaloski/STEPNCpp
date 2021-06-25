//
//
//
#include "stdafx.h"
#include "linalg3d.h"

bool Solve3 (Mtx & A, Vec & B,  Vec & X)
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
    double fDet = A(0,0)*AInv(0,0) + A(0,1)*AInv(1,0) +
        A(0,2)*AInv(2,0);
    if (fabs(fDet) < ZeroTolerance)
    {
        return false;
    }

    double fInvDet = ((double)1.0)/fDet;
    for (int iRow = 0; iRow < 3; iRow++)
    {
        for (int iCol = 0; iCol < 3; iCol++)
        {
            AInv(iRow,iCol) *= fInvDet;
        }
    }

    X(0) = AInv(0,0)*B(0)+AInv(0,1)*B(1)+AInv(0,2)*B(2);
    X(1) = AInv(1,0)*B(0)+AInv(1,1)*B(1)+AInv(1,2)*B(2);
    X(2) = AInv(2,0)*B(0)+AInv(2,1)*B(1)+AInv(2,2)*B(2);
    return true;
}

#if 0
Mtx LU(Mtx& m, Vec& v)
{
	GULAPI bool LUDecomposition( Mtx& m, Vec& v,
                             int *perm_sign, Ptr<int>& index )
{
  double * vv;
  double big,sum,dummy,temp;
  int i,j,k,imax,n,d;

  n = nRowsCols - 1;
  vv=alloc(sizeof(double)*n); /* vv will contain pivot scale factor for each row */
  d = 1;
  
  for( i = 0; i <= n; i++ )
  {
    big = 0.0;
    for( j = 0; j <= n; j++ )
    {
      if( (temp = fabs(A[i][j])) > big )
        big = temp;
    }    
    if( big == 0.0 )  
      return false;

    vv[i] = (double)1 / big;
  }  
  for( j = 0; j <= n; j++ )    /* loop over columns */
  {
    for( i = 0; i < j; i++ )
    {
      sum = A[i][j];
      for( k = 0; k < i; k++ )
        sum -= A[i][k] * A[k][j];
      A[i][j] = sum;
    }
    big = 0.0;
    
    for( i = j; i <= n; i++ )
    {
      sum = A[i][j];
      for( k = 0; k < j; k++ )
        sum -= A[i][k] * A[k][j];
      A[i][j] = sum;
      
      if( (dummy = vv[i] * rtr<T>::fabs(sum)) >= big ) // search pivot element
      {
        big = dummy;
        imax = i;
      }
    }   
    if( j != imax ) /* pivot element not on diagonal */
    {
      for( k = 0; k <= n; k++ )
        Swap( A[imax][k], A[j][k] );  /* swap rows */
 
      d = -d;  
      vv[imax] = vv[j];  /* swap scale factors */
    }
    index[j] = imax;
 
    if( A[j][j] == 0.0 )
      A[j][j] = rtr<T>::tiny();
      
    if( j != n )          /* divide  by pivot element */
    {
      dummy = (T)1 / A[j][j];
      for( i = j+1; i <= n; i++ )
        A[i][j] *= dummy;
    }  
  }    /* next column */ 

  *perm_sign = d;
  return true;
}  
}
#endif
#if 0
{
	int i,j,k,n=4;
	float a[10][10],b[10],x[10],l[10][10],z[10],u[10][10],sum;
	Mtx I;

	for(i=0; i<4; i++) b[i]=v(i);
	b[4]=0;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j<n) a[i][j]=m(i,j);
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i>j) u[i][j]=0;
			else if(i==j) l[i][j]=1;
			else l[i][j]=0;
		}
	}
	//--------------------------------------------------------------------
	//AX=B
	//Decomposition of A into L and U	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			sum=0;
			if(i<=j)
			{
				for(k=0;k<n;k++) 
					if(k!=i)
						sum=sum+l[i][k]*u[k][j];
				u[i][j]=a[i][j]-sum;
			}
			else 
			{
				for(k=0;k<n;k++)
					if(k!=j)
						sum=sum+l[i][k]*u[k][j];
				l[i][j]=(a[i][j]-sum)/u[j][j];
			}
		}
	}

	OutputDebugString("L=\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			StrFormat(StringEx("%f " , l[i][j]));
		OutputDebugString("\n");
	}

	OutputDebugString("U=\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			OutputDebugString(StrFormat("%f " , u[i][j]));
		OutputDebugString("\n");
	}

	//--------------------------------------------------------------------
	//Now LUX=B
	//i.e LZ=B
	//Obtaining Z by forward subtitiution 
	z[0]=b[0]/l[0][0];
	for(i=1;i<n;i++)
	{
		sum=0;
		for(j=0;j<i;j++)
		{
			sum=sum+z[j]*l[i][j];
		}
		z[i]=b[i]-sum;
	}

	OutputDebugString("Z=\n");
	for(i=0;i<n;i++)
	{
		OutputDebugString(StrFormat("%f " , z[i]));
	}
	OutputDebugString("\n");
	//--------------------------------------------------------------------
	//Now UX=Z
	//Finding X by backward substitution
	x[n-1]=z[n-1]/u[n-1][n-1];
	for(i=n-2;i>=0;i--)
	{
		sum=0;
		for(j=n-1;j>i;j--)
			sum=sum+x[j]*u[i][j];
		x[i]=(z[i]-sum)/u[i][i];

	}
	OutputDebugString("Solution:\n");
	for(i=0;i<n;i++)
		OutputDebugString(StrFormat("%f " , z[i]));
	OutputDebugString("\n");
	return Mtx();
}
#endif

#if 0
Matrix Matrix::Inverse() const {
     assert(m_r == m_c);
 
     Matrix res = *this;
 
     int i,j,k;
                     /* Locations of pivot elements */
     int *pvt_i, *pvt_j;
     double pvt_val;                     /* Value of current pivot element */
     double hold;                        /* Temporary storage */
 
     pvt_i = new int[m_r];
     pvt_j = new int[m_r];
 
     for (k = 0; k < m_r; k++)
     {
         /* Locate k'th pivot element */
         pvt_val = res(k,k);            /* Initialize for search */
         pvt_i[k] = k;
         pvt_j[k] = k;
         for(i = k; i < m_r; i++)
             for(j = k; j < m_r; j++)
                 if(fabs(res(i,j)) > fabs(pvt_val)) {
                     pvt_i[k] = i;
                     pvt_j[k] = j;
                     pvt_val = res(i,j);
                 }
 
         if(pvt_val==0) {
             /* Matrix is singular (zero determinant). */
             delete [] pvt_i;
             delete [] pvt_j;
             assert(!"Matrix is singular.");
         }
 
         /* "Interchange" rows (with sign change stuff) */
         i = pvt_i[k];
         if (i != k)                     /* If rows are different */
             for (j = 0; j < m_r; j++)
             {
                 hold = -res(k,j);
                 res(k,j) = res(i,j);
                 res(i,j) = hold;
             }
 
         /* "Interchange" columns */
         j = pvt_j[k];
         if (j != k)                     /* If columns are different */
             for (i = 0; i < m_r; i++)
             {
                 hold = -res(i,k);
                 res(i,k) = res(i,j);
                 res(i,j) = hold;
             }
 
         /* Divide column by minus pivot value */
         for (i = 0; i < m_r; i++)
             if (i != k)                   /* Don't touch the pivot entry */
                 res(i,k) /= ( -pvt_val) ;  /* (Tricky C syntax for division) */
 
         /* Reduce the matrix */
         for (i = 0; i < m_r; i++)
         {
             hold = res(i,k);
             for (j = 0; j < m_r; j++)
                 if ( i != k && j != k )   /* Don't touch pivot. */
                     res(i,j) += hold * res(k,j);
         }
 
         /* Divide row by pivot */
         for (j = 0; j < m_r; j++)
             if (j != k)                   /* Don't touch the pivot! */
                 res(k,j) /= pvt_val;
 
         /* Replace pivot by reciprocal (at last we can touch it). */
         res(k,k) = 1.0/pvt_val;
     }
 
     /* That was most of the work, one final pass of row/column interchange */
     /* to finish */
     for (k = m_r-2; k >= 0; k--)  /* Don't need to work with 1 by 1 corner */
     {
         i = pvt_j[k];        /* Rows to swap correspond to pivot COLUMN */
         if (i != k)                     /* If rows are different */
             for(j = 0; j < m_r; j++)
             {
                 hold = res(k,j);
                 res(k,j) = -res(i,j);
                 res(i,j) = hold;
             }
 
         j = pvt_i[k];           /* Columns to swap correspond to pivot ROW */
         if (j != k)                     /* If columns are different */
             for (i = 0; i < m_r; i++)
             {
                 hold = res(i,k);
                 res(i,k) = -res(i,j);
                 res(i,j) = hold;
             }
     }
 
     delete [] pvt_i;
     delete [] pvt_j;
 
     return res;
 }


inline Mtx inverse4x4(Mtx &m1) {

	Mtx m;
	m(0,0) = m(1,2)*m(2,3)*m(3,1) - m(1,3)*m(2,2)*m(3,1) + m(1,3)*m(2,1)*m(3,2) - m(1,1)*m(2,3)*m(3,2) - m(1,2)*m(2,1)*m(3,3) + m(1,1)*m(2,2)*m(3,3);
	m(0,1) = m(0,3)*m(2,2)*m(3,1) - m(0,2)*m(2,3)*m(3,1) - m(0,3)*m(2,1)*m(3,2) + m(0,1)*m(2,3)*m(3,2) + m(0,2)*m(2,1)*m(3,3) - m(0,1)*m(2,2)*m(3,3);
	m(0,2) = m(0,2)*m(1,3)*m(3,1) - m(0,3)*m(1,2)*m(3,1) + m(0,3)*m(1,1)*m(3,2) - m(0,1)*m(1,3)*m(3,2) - m(0,2)*m(1,1)*m(3,3) + m(0,1)*m(1,2)*m(3,3);
	m(0,3) = m(0,3)*m(1,2)*m(2,1) - m(0,2)*m(1,3)*m(2,1) - m(0,3)*m(1,1)*m(2,2) + m(0,1)*m(1,3)*m(2,2) + m(0,2)*m(1,1)*m(2,3) - m(0,1)*m(1,2)*m(2,3);
	m(1,0) = m(1,3)*m(2,2)*m(3,0) - m(1,2)*m(2,3)*m(3,0) - m(1,3)*m(2,0)*m(3,2) + m(1,0)*m(2,3)*m(3,2) + m(1,2)*m(2,0)*m(3,3) - m(1,0)*m(2,2)*m(3,3);
	m(1,1) = m(0,2)*m(2,3)*m(3,0) - m(0,3)*m(2,2)*m(3,0) + m(0,3)*m(2,0)*m(3,2) - m(0,0)*m(2,3)*m(3,2) - m(0,2)*m(2,0)*m(3,3) + m(0,0)*m(2,2)*m(3,3);
	m(1,2) = m(0,3)*m(1,2)*m(3,0) - m(0,2)*m(1,3)*m(3,0) - m(0,3)*m(1,0)*m(3,2) + m(0,0)*m(1,3)*m(3,2) + m(0,2)*m(1,0)*m(3,3) - m(0,0)*m(1,2)*m(3,3);
	m(1,3) = m(0,2)*m(1,3)*m(2,0) - m(0,3)*m(1,2)*m(2,0) + m(0,3)*m(1,0)*m(2,2) - m(0,0)*m(1,3)*m(2,2) - m(0,2)*m(1,0)*m(2,3) + m(0,0)*m(1,2)*m(2,3);
	m(2,0) = m(1,1)*m(2,3)*m(3,0) - m(1,3)*m(2,1)*m(3,0) + m(1,3)*m(2,0)*m(3,1) - m(1,0)*m(2,3)*m(3,1) - m(1,1)*m(2,0)*m(3,3) + m(1,0)*m(2,1)*m(3,3);
	m(2,1) = m(0,3)*m(2,1)*m(3,0) - m(0,1)*m(2,3)*m(3,0) - m(0,3)*m(2,0)*m(3,1) + m(0,0)*m(2,3)*m(3,1) + m(0,1)*m(2,0)*m(3,3) - m(0,0)*m(2,1)*m(3,3);
	m(2,2) = m(0,1)*m(1,3)*m(3,0) - m(0,3)*m(1,1)*m(3,0) + m(0,3)*m(1,0)*m(3,1) - m(0,0)*m(1,3)*m(3,1) - m(0,1)*m(1,0)*m(3,3) + m(0,0)*m(1,1)*m(3,3);
	m(2,3) = m(0,3)*m(1,1)*m(2,0) - m(0,1)*m(1,3)*m(2,0) - m(0,3)*m(1,0)*m(2,1) + m(0,0)*m(1,3)*m(2,1) + m(0,1)*m(1,0)*m(2,3) - m(0,0)*m(1,1)*m(2,3);
	m(3,0) = m(1,2)*m(2,1)*m(3,0) - m(1,1)*m(2,2)*m(3,0) - m(1,2)*m(2,0)*m(3,1) + m(1,0)*m(2,2)*m(3,1) + m(1,1)*m(2,0)*m(3,2) - m(1,0)*m(2,1)*m(3,2);
	m(3,1) = m(0,1)*m(2,2)*m(3,0) - m(0,2)*m(2,1)*m(3,0) + m(0,2)*m(2,0)*m(3,1) - m(0,0)*m(2,2)*m(3,1) - m(0,1)*m(2,0)*m(3,2) + m(0,0)*m(2,1)*m(3,2);
	m(3,2) = m(0,2)*m(1,1)*m(3,0) - m(0,1)*m(1,2)*m(3,0) - m(0,2)*m(1,0)*m(3,1) + m(0,0)*m(1,2)*m(3,1) + m(0,1)*m(1,0)*m(3,2) - m(0,0)*m(1,1)*m(3,2);
	m(3,3) = m(0,1)*m(1,2)*m(2,0) - m(0,2)*m(1,1)*m(2,0) + m(0,2)*m(1,0)*m(2,1) - m(0,0)*m(1,2)*m(2,1) - m(0,1)*m(1,0)*m(2,2) + m(0,0)*m(1,1)*m(2,2);
	double d= 1/m1.determinant();
	for(int i=0; i<16; i++) m.data[i]*=d;
	return m;
}
extern Mtx LU(Mtx & m, Vec &v);


inline Mtx inverse(Mtx &m, int M=3) 
{

	int i,j,k;
	Mtx I ; // implement the static method...
	Mtx S(m); // make a working copy to destroy.

	for(i=0; i<M-1; i++)
	{
		for(k=i+1; k < M; k++)
		{
			for(j=M-1; j>=0; j--)
			{
				I.data[k*M+j] -= I.data[i*M+j] * 
					(S.data[k*M+i]/S.data[i*M+i]);
			}

			for(j=M-1; j>=i; j--)
			{
				S.data[k*M+j] -= S.data[i*M+j] * 
					(S.data[k*M+i]/S.data[i*M+i]);
			}
		}
	}     

	//-------------------------------------

	for(i=M-1; i>0; i--)
	{
		for(k=i-1; k >=0; k--)
		{
			for(j=M-1; j>=0; j--)
			{
				I.data[k*M+j] -= I.data[i*M+j] * 
					(S.data[k*M+i]/S.data[i*M+i]);          
			}

			for(j=M-1; j>=i; j--)
			{

				S.data[k*M+j] -= S.data[i*M+j] * 
					(S.data[k*M+i]/S.data[i*M+i]);

			}
		}
	}     

	for(i=0; i<M; i++)
	{
		for(j=M-1; j >=0; j--)
		{
			I.data[i*M+j] =I.data[i*M+j]/S.data[i*M+i]; 
		}

		for(j=M-1; j >=i; j--)
		{
			S.data[i*M+j] =S.data[i*M+j]/S.data[i*M+i];       
		}
	}     

	return I;

}
#endif
