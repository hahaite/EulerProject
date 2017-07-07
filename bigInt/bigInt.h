/****************************************************
 *
 * Author : LEE Ho Sang (hahaite@hanmail.net)
 * Homepage : http://www.cyworld.com/hardycluster
 *
 * LICENSE : This code is FREE and NO Warranty.
 *
 * Release :
 * 2014-Oct-17 : The first release.
 *
*******************************************************/

// the examples are in main.cpp. Please see it.


#ifndef _BIGINT_H_
#define _BIGINT_H_

#include <string>

using namespace std ;

class CBigInt
{
public :
	CBigInt() ;
	~CBigInt() ;

	CBigInt(int a) ;
	CBigInt(const char* p) ;
	CBigInt(const string& strA) ;
	CBigInt(const CBigInt& bigA) ;

	const char* c_str(){ return m_value.c_str(); } ;
	const string getString(){ return m_value; } ;
	string* getStrPtr(){ return &m_value; } ;
	string getRemainder(){ return m_remainder; } ;

	int size(){ return m_value.size(); } ;

	void operator=(const CBigInt& bigA) ;	

	void operator++() ;
	void operator++(int dummy) ;

	void operator--() ;
	void operator--(int dummy) ;

	void operator+=(const CBigInt& bigA) ;
	void operator-=(const CBigInt& bigA) ;
	void operator*=(const CBigInt& bigA) ;
	void operator/=(const CBigInt& bigA) ;


	friend int operator==(const CBigInt& bigA, const CBigInt& bigB) ;

		
	friend int operator > (const CBigInt& bigA, const CBigInt& bigB) ;
	friend int operator >=(const CBigInt& bigA, const CBigInt& bigB) ;


	friend int operator < (const CBigInt& bigA, const CBigInt& bigB) ;
	friend int operator <=(const CBigInt& bigA, const CBigInt& bigB) ;


	friend const CBigInt operator+(const CBigInt& bigA, const CBigInt& bigB) ;	
	friend const CBigInt operator-(const CBigInt& bigA, const CBigInt& bigB) ;	
	friend const CBigInt operator*(const CBigInt& bigA, const CBigInt& bigB) ;	

	// I didn't consider to devide a negative to negative.
	friend const CBigInt operator/(const CBigInt& bigA, const CBigInt& bigB) ;	

	friend const CBigInt operator%(const CBigInt& bigA, const CBigInt& bigB) ;	


	// greatest common divisor

	const CBigInt gcd(const CBigInt& bigA, const CBigInt& bigB) ;

	// n!
	const CBigInt factorial(const CBigInt& bigA) ;

	// reverse value "1497" -> "7941"
	const CBigInt reverse(const CBigInt& bigA) ;

	// check palindrome. "1234321", 38799783"
	int palindrome(const CBigInt& bigA) ;

	// sort strings. "381273" -> "123378"
	const CBigInt sort(const CBigInt& bigA) ;


	// nCr = n! / r!(n-r)!	
	const CBigInt combinations(const CBigInt& bigN, const CBigInt& bigR) ;

	// swap bigA <-> bigB
	void swap(CBigInt& bigA, CBigInt& bigB) ;

	// If squareNumber, return value is sqrt(bigA).
	// If not, return zero.
	const CBigInt isSquareNumber() ;


	// Fraction
	// a/b + c/d = r1/r2 ;
	// fraction_add( &a, &b, &c, &d, &r1, &r2) ;
	void fraction_add(const CBigInt& nume1, const CBigInt& deno1, 
			const CBigInt& nume2, const CBigInt& deno2, 
			CBigInt& numeRet, CBigInt& denoRet) ;


	const CBigInt pow(const CBigInt& bigA, const CBigInt& bigB) ;

private :
	string positiveAdd(const string* pStrA, const string* pStrB) ;
	int positiveCompare(const string* pStrA, const string* pStrB) ;

public :

private :
	string m_value ;
	string m_remainder ;
};

#endif
