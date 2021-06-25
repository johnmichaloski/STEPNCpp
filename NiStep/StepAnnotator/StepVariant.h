//
// StepStepVariant.h
//


#pragma once

#include <string>
#include "linalg3d.h"
#include "boost/lexical_cast.hpp"
#include "iges.h"


using namespace std;
typedef void * NULL_t;
// I don't need an empty

/*
Works:
	StepVariant v1=22.0;
	StepVariant v2=34.0;
	double d =  v1.get<double>() +  v2.get<double>(); 
	OutputDebugString(StrFormat(_T("Answer = %f\n"), d));
Doesn't Work:
	StepVariant v1=22.0;
	StepVariant v2=34;
	double d =  v1.get<double>() +  v2.get<double>(); 
	OutputDebugString(StrFormat(_T("Answer = %f\n"), d));

*/
class StepVariant 
{
public:
//	bool _b;
	long _l;
	double _d;
	tstring _s;
	Vector _v;
	Matrix _m;
	Iges::CompositeCurve _curve;

	tstring _type;
	void Init() { _d=0.0; _l=0;  }

	StepVariant() { Init(); _type= _T("null"); } 
    StepVariant( bool b ) : _l( long(b)), _d(0)		{ USES_CONVERSION; _type= A2T(typeid( long ).name());} 
    StepVariant( int i ) : _l(i), _d(0) 			{ USES_CONVERSION; _type= A2T(typeid( long ).name());} 
    StepVariant( long l ) : _l(l), _d(0)			{ USES_CONVERSION; _type= A2T(typeid( long ).name());} 
    StepVariant( float f ) : _d(f), _l(0)			{ USES_CONVERSION; _type= A2T(typeid( double ).name());} 
    StepVariant( double d ) : _d(d), _l(0)			{ USES_CONVERSION; _type= A2T(typeid( double ).name());} 
    StepVariant( Vector v ) : _v(v), _d(0), _l(0)	{ USES_CONVERSION; _type= A2T(typeid( Vector ).name());} 
    StepVariant( Matrix m ) : _m(m), _d(0), _l(0)	{ USES_CONVERSION; _type= A2T(typeid( Matrix ).name());} 
    StepVariant( Iges::CompositeCurve c ) : _curve(c), _d(0), _l(0)	
	{USES_CONVERSION; _type= A2T(typeid( Iges::CompositeCurve ).name());} 
#ifdef UNICODE
    StepVariant( const wchar_t *s ) : _s(s), _d(0), _l(0){ USES_CONVERSION; _type= A2T(typeid( tstring ).name()) ;}
#else
    StepVariant( const char  *s )   : _s(s), _d(0), _l(0){ _type= typeid( tstring ).name() ;} 

#endif
    StepVariant( const tstring &s ) : _s( s ), _d(0), _l(0) {USES_CONVERSION;  _type= A2T(typeid( tstring ).name()) ;  } 

	const tstring & type() const 
	{ 
		return _type ; 
	} 
	template< typename T >
	bool IsType() const 
	{
		USES_CONVERSION;
		if(A2T(typeid( T ).name()) == _type)
		 return true;
		return false;
	}

	template< typename T >
	T get() const 
	{
		if(typeid( T ).name() == typeid(CString ).name())
			DebugBreak();
		if(IsType<tstring>())
			return *(T *) &_s;
		else if(IsType<long>())
			return *(T *)&_l;
		else if(IsType<double>())
			return *(T *)&_d;
		else  if(IsType<Vector>())
			return *(T *)&_v;
		else  if(IsType<Matrix>())
			return *(T *)&_m;
		else  if(IsType<Iges::CompositeCurve>())
			return *(T *)&_curve;
		throw std::exception("bad stepvariant get");

	}
	template<>
	double get<double>() const 
	{
		if(IsType<long>() )
			return  (double) _l;
		if(IsType<tstring>() )
			return  (double) _tstof (_s.c_str());
		return _d;
	}
	template< >
	long get<long>() const 
	{
		if(IsType<tstring>())	
			return _tcstol( get<tstring>().c_str(), NULL, 10 );
		if(IsType<double>() )
			return (long )_d;
		return _l;
	}
	template<>
	Vector get<Vector>() const 
	{
		if(IsType<tstring>() )
		{
			CString tmp = (LPCTSTR) get<tstring>( ).c_str();
			return Vector(DVal(tmp,0,","), DVal(tmp,1,","), DVal(tmp,2,","));
		}
		if(IsType<Vector>() )
			return _v;

		return Vector();
	}


	tstring ToString()
	{
		if(IsType<double>())	return boost::lexical_cast<tstring>( get<double>() );
		if(IsType<long>()) 		return boost::lexical_cast<tstring>( get<long>() );
		if(IsType<Vector>()) 		return (LPCTSTR) get<Vector>().ToString(); 
		if(IsType<Matrix>()) 		return (LPCTSTR) get<Matrix>().ToString(); 
		if(IsType<Iges::CompositeCurve>()) 		return _T(""); 
		return this->get<tstring>();

	}

	// or should bool make a double on constructor...
    bool operator !=( const StepVariant &v ) const { return !( *this == v ); }
	bool operator ==( const StepVariant &v ) const
	{ 
		if(this->IsType<tstring>() && v.IsType<tstring>())
			return this->get<tstring>()==v.get<tstring>();
		if(this->IsType<Vector>() && v.IsType<Vector>())
			return this->get<Vector>() == v.get<Vector>();
		// turn into double and test
		return this->get<double>()==v.get<double>();
	}
	bool operator <( const StepVariant &v2 ) const 
	{ 
		if(this->IsType<tstring>() && v2.IsType<tstring>())
			return this->get<tstring>()<v2.get<tstring>();
		return this->get<double>()<v2.get<double>();
	}
	bool operator <=( const StepVariant &v2 ) const 
	{ 
		if(this->IsType<tstring>() && v2.IsType<tstring>())
			return this->get<tstring>()<=v2.get<tstring>();
		return this->get<double>()<=v2.get<double>();
	}
	bool operator &&( const StepVariant &v2 ) const 
	{ 
		return this->get<double>() && v2.get<double>();

	}
	bool operator ||( const StepVariant &v2 ) const 
	{ 
		return this->get<double>() || v2.get<double>();

	}
	bool operator >( const StepVariant &v2 ) const {	
		return !( *this <=v2 ); 	}
	bool operator >=( const StepVariant &v2 ) const {	return !( *this < v2 ); 	}

	StepVariant operator +(  const StepVariant &v2 ) const 
	{ 
		if(this->IsType<tstring>() && v2.IsType<tstring>())
			return this->get<tstring>()+v2.get<tstring>();
		if(this->IsType<Vector>() && v2.IsType<Vector>())
			return  this->get<Vector>() +  v2.get<Vector>();

		double d1= get<double>();
		double d2 =v2.get<double>(); 	
		return  d1+d2;
	}
	StepVariant operator -(  const StepVariant &v2 ) const 
	{ 
		if(this->IsType<Vector>() && v2.IsType<Vector>())
			return  this->get<Vector>() -  v2.get<Vector>();

		// fixme: need better conversion 
		double d1= get<double>();
		double d2 =v2.get<double>(); 	
		return  d1-d2;
	}
	StepVariant operator *(  const StepVariant &v2 ) const 
	{ 
		if(this->IsType<Vector>() && v2.IsType<double>())
			return  this->get<Vector>()*  v2.get<double>();
		double d1 = get<double>();
		double d2 = v2.get<double>(); 	
		return  d1*d2;
	}
	StepVariant operator /(  const StepVariant &v2 ) const 
	{ 
		if(this->IsType<Vector>() && v2.IsType<double>())
			return this->get<Vector>() /  v2.get<double>();
		double d1 = get<double>();
		double d2 = v2.get<double>(); 	
		return  d1/d2;
	}
//	void StepVariant::Tests();

};
typedef StepVariant Variant;