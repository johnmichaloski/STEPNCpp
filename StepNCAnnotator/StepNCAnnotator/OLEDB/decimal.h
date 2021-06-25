/*!
 * $RCSfile: decimal.h,v $
 * \file com/decimal.h
 *
 * \brief Defines a decimal helper class, based on code from a previous major version of CashIT (a.k.a CDecimal).
 *
 * \author J&ouml;rgen Sigvardsson &lt;jorgen@profitab.com&gt;
 * \version $Revision: 1.10 $
 */
#pragma once

namespace com {
	/*!
	 * C++ wrapper class for the OLE Automation type DECIMAL. Provides all the VarDecXXX() functions through
	 * a C++ class and function interface. Objects of type Decimal look and behave like "ordinary ints".
	 *
	 * \author J&ouml;rgen Sigvardsson
	 */
	class Decimal : public DECIMAL {
	public:
		// Constructors
		Decimal(const DECIMAL& decValue) throw();
		// Default to 0
		Decimal() throw();
		Decimal(char nValue) throw();
		Decimal(short nValue) throw();
		Decimal(long nValue) throw ();
		Decimal(unsigned char nValue) throw();
		Decimal(unsigned short nValue) throw();
		Decimal(unsigned long nValue) throw ();
		Decimal(float fValue) throw();
		Decimal(double dValue) throw();
		Decimal(const DB_NUMERIC& dbValue) throw();
		
		static Decimal max_value(long nDigits, long nDecimals) throw();

		// Mutators
		bool FromString(LPCOLESTR lpszNum, LCID lcid = 0) throw();
		
		// Operators (mutating)
		Decimal& operator = (char nValue) throw();
		Decimal& operator = (short nValue) throw();
		Decimal& operator = (long nValue) throw();
		Decimal& operator = (unsigned char nValue) throw();
		Decimal& operator = (unsigned short nValue) throw();
		Decimal& operator = (unsigned long nValue) throw();
		Decimal& operator = (float nValue) throw();
		Decimal& operator = (double nValue) throw();
		Decimal& operator = (const DB_NUMERIC& dbValue) throw();
		Decimal& operator += (const DECIMAL& decRHS) throw();
		Decimal& operator -= (const DECIMAL& decRHS) throw();
		Decimal& operator *= (const DECIMAL& decRHS) throw();
		Decimal& operator /= (const DECIMAL& decRHS) throw();
		Decimal operator++(int /* prefix operator: not used */) throw();
		Decimal operator--(int /* prefix operator: not used */) throw();
		Decimal& operator++() throw();
		Decimal& operator--() throw();
		
		// Mutating functions
		Decimal& MakeAbsolute() throw();
		Decimal& MakeNegative() throw();
		Decimal& MakeInteger() throw();
		Decimal& MakeFixed() throw();
		// nDecimals >= 0
		Decimal& MakeRound(int nDecimals) throw();
		
		// Non-mutating functions
		Decimal Absolute() const throw();
		Decimal Negative() const throw();
		Decimal Integer() const throw();
		Decimal Fixed() const throw();
		// nDecimals >= 0
		Decimal Round(int nDecimals) const throw();
		
		// Inspectors (non-mutating)
		bool IsNegative() const throw();
		bool IsZero() const throw ();
		BSTR ToString(LCID lcid = 0) const throw();
		bool ConvertTo(char* b) const throw();
		bool ConvertTo(short* s) const throw();
		bool ConvertTo(int* i) const throw();
		bool ConvertTo(long* l) const throw();
		bool ConvertTo(unsigned char* b) const throw();
		bool ConvertTo(unsigned short* s) const throw();
		bool ConvertTo(unsigned int* i) const throw();
		bool ConvertTo(unsigned long* l) const throw();
		bool ConvertTo(float* f) const throw();
		bool ConvertTo(double* d) const throw();
	};

	// Operators
	Decimal operator + (const DECIMAL& decLHS, const DECIMAL& decRHS) throw();
	Decimal operator - (const DECIMAL& decLHS, const DECIMAL& decRHS) throw();
	Decimal operator * (const DECIMAL& decLHS, const DECIMAL& decRHS) throw();
	Decimal operator / (const DECIMAL& decLHS, const DECIMAL& decRHS) throw();
	bool operator < (const DECIMAL& decLHS, const DECIMAL& decRHS) throw();
	bool operator > (const DECIMAL& decLHS, const DECIMAL& decRHS) throw();
	bool operator <= (const DECIMAL& decLHS, const DECIMAL& decRHS) throw();
	bool operator >= (const DECIMAL& decLHS, const DECIMAL& decRHS) throw();
	bool operator == (const DECIMAL& decLHS, const DECIMAL& decRHS) throw();
	bool operator != (const DECIMAL& decLHS, const DECIMAL& decRHS) throw();


	// Param: decThis          represents the number you want to round
	// Param: nSmallestCoin    an integer in cents (cent = hundreth of a currency), specifying the smallest coin.
	Decimal RoundToSmallestCoin(const Decimal& decThis, unsigned long nSmallestCoin) throw();
}
