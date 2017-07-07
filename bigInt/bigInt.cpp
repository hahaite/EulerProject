#include "bigInt.h"

#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <set>

#define _HO 	fprintf(stderr, "*** %s, Line : %d\n", __FUNCTION__, __LINE__) ;

CBigInt::CBigInt()
{
	m_value.clear() ;
	m_remainder.clear() ;
}


CBigInt::~CBigInt()
{

}


CBigInt::CBigInt(int a)
{
	char szText[32] ;
	sprintf(szText, "%d", a) ;

	m_value = szText ;
	m_remainder.clear() ;
}

CBigInt::CBigInt(const char* p)
{
	m_value = p ;
	m_remainder.clear() ;
}

CBigInt::CBigInt(const string& strA)
{
	m_value = strA ;
	m_remainder.clear() ;
}

CBigInt::CBigInt(const CBigInt& bigA)
{
	m_value = bigA.m_value ;
	m_remainder = bigA.m_remainder ;
}

void CBigInt::operator=(const CBigInt& bigA)
{
	m_value = bigA.m_value ;
	m_remainder = bigA.m_remainder ;
	return ;
}

void CBigInt::operator++()
{
	*this = *this + 1 ;
	return ;
}

void CBigInt::operator++(int dummy)
{
	*this = *this + 1 ;
	return ;
}


void CBigInt::operator--()
{
	*this = *this - 1 ;
	return ;
}

void CBigInt::operator--(int dummy)
{
	*this = *this - 1 ;
	return ;
}


void CBigInt::operator+=(const CBigInt& bigA)
{
	*this = *this + bigA ;
	return ;
}


void CBigInt::operator-=(const CBigInt& bigA)
{
	*this = *this - bigA ;
	return ;
}

void CBigInt::operator*=(const CBigInt& bigA)
{
	*this = *this * bigA ;
	return ;
}


void CBigInt::operator/=(const CBigInt& bigA)
{
	*this = *this / bigA ;
	return ;
}

int operator==(const CBigInt& bigA, const CBigInt& bigB)
{
	return (bigA.m_value == bigB.m_value) ;
}

////////////////////////////////////////////////////////////////////////

int operator > (const CBigInt& bigA, const CBigInt& bigB)
{
	CBigInt bigInt ;
	string::const_iterator 	strIter ;

	int flagA, flagB, ret ;

	strIter = bigA.m_value.begin() ;
	flagA = (*strIter == '-') ? 1 : 0 ;

	strIter = bigB.m_value.begin() ;
	flagB = (*strIter == '-') ? 1 : 0 ;

	switch((flagA * 10) + flagB)
	{
	case 0 : 	// PLUS_PLUS
		ret = bigInt.positiveCompare(&bigA.m_value, &bigB.m_value) ;
		ret = (ret > 0) ? 1 : 0 ;
		break ;
	case 1 : 	// PLUS_MINUS
		ret = 1 ;
		break ;
	case 10 : 	// MINUS_PLUS
		ret = 0 ;
		break ;
	case 11 : 	// MINUS_MINUS
		ret = bigInt.positiveCompare(&bigA.m_value, &bigB.m_value) ;
		ret = (ret < 0) ? 1 : 0 ;
		break ;
	}

	return ret ;
}

int operator >=(const CBigInt& bigA, const CBigInt& bigB)
{
	return (bigA > bigB) | (bigA == bigB) ;
}


int operator < (const CBigInt& bigA, const CBigInt& bigB)
{
	CBigInt bigInt ;
	string::const_iterator 	strIter ;

	int flagA, flagB, ret ;

	strIter = bigA.m_value.begin() ;
	flagA = (*strIter == '-') ? 1 : 0 ;

	strIter = bigB.m_value.begin() ;
	flagB = (*strIter == '-') ? 1 : 0 ;

	switch((flagA * 10) + flagB)
	{
	case 0 : 	// PLUS_PLUS
		ret = bigInt.positiveCompare(&bigB.m_value, &bigA.m_value) ;
		ret = (ret > 0) ? 1 : 0 ;
		break ;
	case 1 : 	// PLUS_MINUS
		ret = 0 ;
		break ;
	case 10 : 	// MINUS_PLUS
		ret = 1 ;
		break ;
	case 11 : 	// MINUS_MINUS
		ret = bigInt.positiveCompare(&bigB.m_value, &bigA.m_value) ;
		ret = (ret < 0) ? 1 : 0 ;
		break ;
	}

	return ret ;
}

int operator <=(const CBigInt& bigA, const CBigInt& bigB)
{
	return (bigA < bigB) | (bigA == bigB) ;
}


const CBigInt operator+(const CBigInt& bigA, const CBigInt& bigB)
{
	CBigInt bigInt ;

	CBigInt leftA ;
	CBigInt leftB ;
	string::iterator 	strIter ;
	string::const_iterator 	strConstIter ;

	if(bigB.m_value == "0")
	{
		bigInt.m_value = bigA.m_value ;
		return bigInt ;
	}

	// check minus sign
	int flagA, flagB ;

	string* pa ;
	string* pb ;

	strConstIter = bigA.m_value.begin() ;
	flagA = (*strConstIter == '-') ? 1 : 0 ;
	
	strConstIter = bigB.m_value.begin() ;
	flagB = (*strConstIter == '-') ? 1 : 0 ;

	switch((flagA * 10) + flagB)
	{
	case 0 : 	// PLUS_PLUS
		bigInt = bigInt.positiveAdd(&bigA.m_value, &bigB.m_value) ;
		break ;
	case 1 : 	// PLUS_MINUS
		leftB = bigB.m_value ;
		strIter = leftB.m_value.begin() ;
		leftB.m_value.erase(strIter) ;
		bigInt = bigA - leftB ;
		break ;
	case 10 : 	// MINUS_PLUS
		leftA = bigA.m_value ;
		strIter = leftA.m_value.begin() ;
		leftA.m_value.erase(strIter) ;
		bigInt = bigB - leftA ;
		break ;
	case 11 : 	// MINUS_MINUS
		leftA = bigA.m_value ;
		leftB = bigB.m_value ;

		strIter = leftA.m_value.begin() ;
		leftA.m_value.erase(strIter) ;

		strIter = leftB.m_value.begin() ;
		leftB.m_value.erase(strIter) ;

		bigInt.m_value = bigInt.positiveAdd(&leftA.m_value, &leftB.m_value) ;
		bigInt.m_value = '-' + bigInt.m_value ;
		break ;
	}
	return bigInt ;
}



const CBigInt operator-(const CBigInt& bigA, const CBigInt& bigB)
{
	CBigInt bigInt ;

	string leftA ;
	string leftB ;
	string strTemp ;

	string::iterator 	strIter ;
	string::const_iterator 	strConstIter ;

	if(bigB.m_value == "0")
		return bigA ;

	// check minus sign
	int flagA, flagB ;

	strConstIter = bigA.m_value.begin() ;
	flagA = (*strConstIter == '-') ? 1 : 0 ;
	
	strConstIter = bigB.m_value.begin() ;
	flagB = (*strConstIter == '-') ? 1 : 0 ;

	switch((flagA * 10) + flagB)
	{
	case 0 : 	// PLUS_PLUS
		leftA = bigA.m_value ;
		leftB = bigB.m_value ;
		break ;
	case 1 : 	// PLUS_MINUS
		leftB = bigB.m_value ;
		strIter = leftB.begin() ;
		leftB.erase(strIter) ;

		bigInt.m_value = bigInt.positiveAdd(&bigA.m_value, &leftB) ;
		return bigInt ;
		break ;
	case 10 : 	// MINUS_PLUS
		leftA = bigA.m_value ;
		strIter = leftA.begin() ;
		leftA.erase(strIter) ;

		bigInt.m_value = bigInt.positiveAdd(&leftA, &bigB.m_value) ;
		bigInt.m_value = '-' + bigInt.m_value ;
		return bigInt ;
		break ;
	case 11 : 	// MINUS_MINUS
		leftA = bigA.m_value ;
		leftB = bigB.m_value ;

		strIter = leftA.begin() ;
		leftA.erase(strIter) ;

		strIter = leftB.begin() ;
		leftB.erase(strIter) ;
		break ;
	}

	int lenA = leftA.size() ;
	int lenB = leftB.size() ;
	int ret = bigInt.positiveCompare(&leftA, &leftB) ;

	int flagMinus = 0 ;
	
	if(ret > 0)
	{
		for(int ii = 0; ii < (lenA - lenB); ii++)
			leftB = "0" + leftB ;
	}
	else if(ret < 0)
	{
		strTemp = leftA ;
		leftA = leftB ;
		leftB = strTemp ;

		for(int ii = 0; ii < (lenB - lenA); ii++)
			leftB = "0" + leftB ;

		flagMinus = 1 ;
	}
	else
	{
		bigInt.m_value = "0" ;
		return bigInt ;
	}

	lenB = leftB.size() ;
	strIter = leftB.begin() ;
	for(; strIter != leftB.end(); strIter++)
	{
		if(*strIter == '0')
			*strIter = '9' ;
		else
			*strIter = '9' - *strIter + '0' ;
	}
	strIter-- ;
	*strIter += 1 ;

	bigInt.m_value = bigInt.positiveAdd(&leftA, &leftB) ;

	strIter = bigInt.m_value.begin() ;
	bigInt.m_value.erase(strIter) ;

	while(1)
	{
		strIter = bigInt.m_value.begin() ;

		if(*strIter == '0')
			bigInt.m_value.erase(strIter) ;
		else	
			break ;
	}

	if(flagMinus && (!flagA && !flagB))
		bigInt.m_value = '-' + bigInt.m_value ;

	if(!flagMinus && (flagA && flagB))
		bigInt.m_value = '-' + bigInt.m_value ;
	
	return bigInt ;
}

const CBigInt operator*(const CBigInt& bigA, const CBigInt& bigB)
{
	CBigInt bigInt ;

	string::const_iterator 	strAIter ;
	string::const_iterator 	strBIter ;
	string::iterator 	strMuitlIter ;
	string::iterator 	strTempIter ;
	string::const_iterator 	strSignIter ;
	string::const_iterator 	strConstIter ;

	bigInt.m_value = "0" ;
	string strTemp = "0" ;

	int a, b, multi ;
	int upper = 0 ;

	int flagA, flagB ;

	strConstIter = bigA.m_value.begin() ;
	flagA = (*strConstIter == '-') ? 1 : 0 ;

	strConstIter = bigB.m_value.begin() ;
	flagB = (*strConstIter == '-') ? 1 : 0 ;

	strBIter = bigB.m_value.end() ;

	int count = 0 ;

	while(1)
	{
		strTemp = "0" ;
		upper = 0 ;
		b = *(--strBIter) - '0' ;


		strAIter = bigA.m_value.end() ;
		while(1)
		{
			a = *(--strAIter) - '0' ;

			if(strAIter != bigA.m_value.begin())
			{
				strSignIter = strAIter ;
				strSignIter-- ;
			}

			multi = (a * b)	+ upper ;

			strTempIter = strTemp.begin() ;
			*strTempIter = (char)(multi % 10) + '0' ;

			upper = multi / 10 ;
			strTemp = (char)('0') + strTemp ;

			if(strAIter == bigA.m_value.begin() || *strSignIter == '-')
			{
				strTempIter = strTemp.begin() ;
				if(upper > 0)
					*strTempIter = (char)('0') + upper ;	
				else
					strTemp.erase(strTempIter) ;
				break ;
			}
		}

		for(int ii = 0; ii < count; ii++)
			strTemp = strTemp + "0" ;

		bigInt.m_value = bigInt.positiveAdd(&bigInt.m_value, &strTemp) ;

		count++ ;

		if(strBIter != bigB.m_value.begin())
		{
			strSignIter = strBIter ;
			strSignIter-- ;
		}

		if(strBIter == bigB.m_value.begin() || *strSignIter == '-')
			break ;
	}

	if((flagA + flagB) % 2 == 1)
		bigInt.m_value = '-' + bigInt.m_value ;

	return bigInt ;
}


const CBigInt operator/(const CBigInt& bigA, const CBigInt& bigB)
{
	
	// a / b = c ;
	// a : dividend
	// b : divisor
	// c : quotient
	// a % b : remainder

	CBigInt bigDividend ;
	CBigInt bigDivisor ;
	CBigInt bigQuotient ;
	CBigInt bigRemainder ;
	CBigInt bigPart ;

	bigQuotient = 0 ;

	string::iterator strIter ;

	int ret ;

	if(bigA == bigB)
	{
		CBigInt bigInt ;
		bigInt.m_remainder = "0" ;
		bigInt.m_value = "1" ;
		return bigInt ;
	}

	if(bigB == 1)
	{
		CBigInt bigInt ;
		bigInt.m_remainder = "0" ;
		bigInt.m_value = bigA.m_value ;
		return bigInt ;
	}

	if(bigA < bigB)
	{
		CBigInt bigInt ;
		bigInt.m_remainder = bigA.m_value ;
		bigInt.m_value = "0" ;
	}

	bigDividend = bigA ;
	bigDivisor = bigB ;

	strIter = bigDividend.m_value.begin() ;

	while(1)
	{
		while(1)
		{
			if(bigPart == 0)
				bigPart.m_value.clear() ;

			bigPart.m_value = bigPart.m_value + *strIter ;

			strIter++ ;

			if(bigQuotient > 0)
				bigQuotient.m_value = bigQuotient.m_value + '0' ;

			if(bigPart >= bigDivisor)
				break ;

			if(strIter == bigDividend.m_value.end())
				break ;
		}
		
		if(bigPart < bigDivisor)
			break ;

		while(1)
		{
			bigPart = bigPart - bigDivisor ;

			bigQuotient++ ;
			
			if(bigDivisor > bigPart)
				break ;
		}
		if(strIter == bigDividend.m_value.end())
			break ;
	}
	bigQuotient.m_remainder = bigPart.m_value ;

	return bigQuotient ;
}

const CBigInt operator%(const CBigInt& bigA, const CBigInt& bigB)
{
	CBigInt bigInt ;
	bigInt = bigA / bigB ;
	bigInt.m_value = bigInt.m_remainder ;

	return bigInt ;
}


const CBigInt CBigInt::gcd(const CBigInt& bigA, const CBigInt& bigB)
{
	CBigInt bigD = 1 ;
	CBigInt bigTemp ;

	CBigInt ba = bigA ;
	CBigInt bb = bigB ;

	while(1)
	{
		bigTemp = ba % bb ;

		if(bigTemp == 0)
			break ;

		ba = bb ;
		bb = bigTemp ;
		bigD = bigTemp ;
	}

	return bigD ;
}



const CBigInt CBigInt::factorial(const CBigInt& bigA)
{
	CBigInt bigInt ;
	bigInt = bigA ;
	
	int ii = 0 ;

	if(bigA == 0)
	{
		bigInt = 1 ;
		return bigInt ;
	}

	while(1)
	{
		ii++ ;
		if(bigA == ii)
			break ;

		bigInt = bigInt * ii ;

	}
	return bigInt ;
}

const CBigInt CBigInt::reverse(const CBigInt& bigA)
{
	CBigInt bigInt ;
	bigInt.m_value.clear() ;
	string::const_iterator strConstIter ;
	string::iterator strIter ;
	
	strConstIter = bigA.m_value.end() ;

	while(1)
	{
		strConstIter-- ;
		bigInt.m_value = bigInt.m_value + *strConstIter ;

		if(strConstIter == bigA.m_value.begin())
			break ;
	}

	while(1)
	{
		strIter = bigInt.m_value.begin() ;
		if(*strIter == '0')
			bigInt.m_value.erase(strIter) ;
		else
			break ;
	}

	return bigInt ;
}


int CBigInt::palindrome(const CBigInt& bigA)
{
	CBigInt bigInt ;
	bigInt = reverse(bigA) ;

	if(bigInt == bigA)
		return 1 ;
	
	return 0 ;
}


const CBigInt CBigInt::sort(const CBigInt& bigA)
{
	CBigInt bigInt ;

	multiset<char> 			msetChar ;
	multiset<char>::iterator 	msetCharIter ;

	string::const_iterator 		strConstIter ;

	strConstIter = bigA.m_value.begin() ;

	for(; strConstIter != bigA.m_value.end(); strConstIter++)
		msetChar.insert(*strConstIter) ;

	bigInt.m_value.clear() ;

	msetCharIter = msetChar.begin() ;
	for(; msetCharIter != msetChar.end(); msetCharIter++)
	{
//		if(*msetCharIter != '0')
		bigInt.m_value += (char)*msetCharIter ;
	}
	
	return bigInt ;
}


const CBigInt CBigInt::combinations(const CBigInt& bigN, const CBigInt& bigR)
{
	return factorial(bigN) / (factorial(bigR) * factorial(bigN - bigR)) ;
}

void CBigInt::swap(CBigInt& bigA, CBigInt& bigB)
{
	CBigInt bigTemp ;

	bigTemp = bigA ;
	bigA = bigB ;
	bigB = bigTemp ;
}


const CBigInt CBigInt::isSquareNumber()
{
	CBigInt bigL = 1 ;
	CBigInt bigR = 10 ;

	CBigInt bigMid ;
	CBigInt bigTemp ;

	// check Max
	while(1)
	{
		bigTemp = bigR * bigR ;

		if( bigTemp > *this)
			break ;

		bigR *= 10 ;
	}

	while(1)
	{
		bigMid = (bigL + bigR) / 2 ;
		bigTemp = bigMid * bigMid ;

		if(bigTemp == *this)
			return bigMid ;
		else if(bigTemp > *this)
			bigR = bigMid ;
		else
			bigL = bigMid ;

		if(bigR - bigL == 1)
			break ;
	}

	return 0 ;
}


// Fraction
// a/b + c/d = r1/r2 ;
// fraction_add( &a, &b, &c, &d, &r1, &r2) ;
void CBigInt::fraction_add(const CBigInt& nume1, const CBigInt& deno1, 
			const CBigInt& nume2, const CBigInt& deno2, 
			CBigInt& numeRet, CBigInt& denoRet)
{
	numeRet = (nume1 * deno2) + (deno1 * nume2) ;
	denoRet = deno1 * deno2 ;

	return ;
}


const CBigInt CBigInt::pow(const CBigInt& bigA, const CBigInt& bigB)
{
	CBigInt bigInt ;
	int ii = 0 ;

	bigInt = 1 ;
	if(bigB == 0)
		return bigInt ;

	bigInt = bigA ;

	while(1)
	{
		ii++ ;
		if(bigB == ii)
			break ;

		bigInt = bigInt * bigA ;
	}

	return bigInt ;
}


string CBigInt::positiveAdd(const string *pStrA, const string* pStrB)
{
	string::const_iterator 	strAIter ;
	string::const_iterator 	strBIter ;
	string::iterator 	strSumIter ;
	string strSum = "0" ;

	int a, b, sum ;
	int upper = 0 ;

	strAIter = pStrA->end() ;
	a = *(--strAIter) - '0' ;

	strBIter = pStrB->end() ;
	b = *(--strBIter) - '0' ;

	while(1)
	{
		sum = a + b + upper ;
		
		strSumIter = strSum.begin() ;
		*strSumIter = (char)(sum % 10) + '0' ;
	
		upper = sum / 10 ;
		strSum = (char)('0') + strSum ;

		if(strAIter == pStrA->begin() && strBIter == pStrB->begin())
		{
			strSumIter = strSum.begin() ;
			if(upper > 0)
				*strSumIter = '1' ;	
			else
				strSum.erase(strSumIter) ;
			break ;
		}

		a = (strAIter != pStrA->begin()) ? *(--strAIter) - '0' : 0 ;
		b = (strBIter != pStrB->begin()) ? *(--strBIter) - '0' : 0 ;
	}

	return strSum ;
}


int CBigInt::positiveCompare(const string* pStrA, const string* pStrB)
{
	int lenA ;
	int lenB ;

	lenA = pStrA->size() ;
	lenB = pStrB->size() ;

	if(lenA > lenB)
		return 1 ;
	else if(lenA < lenB)
		return -1 ;

	return pStrA->compare(*pStrB) ;
}
