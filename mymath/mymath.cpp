#include "mymath.h"

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std ;


CPrime::CPrime()
{
	m_curPrime = 0 ;
}

CPrime::~CPrime()
{

}

// calcul a^n%mod
size_t CPrime::power(size_t a, size_t n, size_t mod)
{
	size_t power = a;
	size_t result = 1;
		 
	while (n)
	{
		if (n & 1)
		result = (result * power) % mod;
		power = (power * power) % mod;
		n >>= 1;
	}
	return result;
}

// n−1 = 2^s * d with d odd by factoring powers of 2 from n−1
bool CPrime::witness(size_t n, size_t s, size_t d, size_t a)
{
	size_t x = power(a, d, n);
	size_t y;
			 
	while (s) 
	{
		y = (x * x) % n;
		if (y == 1 && x != 1 && x != n-1)
			return false;
		x = y;
		--s;
	}

	if (y != 1)
		return false;

	return true;
}


bool CPrime::isPrime(size_t n)
{
	if (((!(n & 1)) && n != 2 ) || (n < 2) || (n % 3 == 0 && n != 3))
		return false;
	if (n <= 3)
		return true;

	size_t d = n / 2;
	size_t s = 1;
	while (!(d & 1))
	{
		d /= 2;
		++s;
	}

	if (n < 1373653)
		return witness(n, s, d, 2) && witness(n, s, d, 3);
	if (n < 9080191)
		return witness(n, s, d, 31) && witness(n, s, d, 73);
	if (n < 4759123141)
		return witness(n, s, d, 2) && witness(n, s, d, 7) && witness(n, s, d, 61);
	if (n < 1122004669633)
		return witness(n, s, d, 2) && witness(n, s, d, 13) && witness(n, s, d, 23) && witness(n, s, d, 1662803);
	if (n < 2152302898747)
		return witness(n, s, d, 2) && witness(n, s, d, 3) && witness(n, s, d, 5) && witness(n, s, d, 7) && witness(n, s, d, 11);
	if (n < 3474749660383)
		return witness(n, s, d, 2) && witness(n, s, d, 3) && witness(n, s, d, 5) && witness(n, s, d, 7) && witness(n, s, d, 11) && witness(n, s, d, 13);

	return witness(n, s, d, 2) && witness(n, s, d, 3) && witness(n, s, d, 5) && witness(n, s, d, 7) && witness(n, s, d, 11) && witness(n, s, d, 13) && witness(n, s, d, 17);

}

void CPrime::setPrime(long long prime)
{
	if((prime & 1L) == 0)
		prime-- ;
	
	m_curPrime = prime ;

	return ;
}

void CPrime::resetPrime()
{
	m_curPrime = 0 ;
	return ;
}

long long CPrime::getNextPrime()
{
	if(m_curPrime == 0)
	{
		m_curPrime = 2 ;
		return m_curPrime ;
	}
	
	if(m_curPrime == 2)
	{
		m_curPrime = 3 ;
		return m_curPrime ;
	}

	int ret ;
	while(1)
	{
		m_curPrime += 2 ;

		ret = isPrime(m_curPrime) ;

		if(ret)
			break ;
	}

	return m_curPrime ;
}

//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

void CDivisor::getIntegerFactorization(long long value, map<long long, int>* pMapIntFactor)
{
	static CPrime prime ;
	int ret ;
	
	long long myPrime ;
	map<long long, int>::iterator 		mapIntFactorIter ;

	prime.resetPrime() ;

	while(1)
	{
		ret = prime.isPrime(value) ;
		if(ret)
		{
			mapIntFactorIter = pMapIntFactor->find(value) ;
			if(mapIntFactorIter == pMapIntFactor->end())
				pMapIntFactor->insert(make_pair(value, 1)) ;
			else
				mapIntFactorIter->second++ ;

			break ;
		}
		
		myPrime = prime.getNextPrime() ;

		while(1)
		{
			if(value % myPrime == 0)
			{
				value /= myPrime ;
	
			
				mapIntFactorIter = pMapIntFactor->find(myPrime) ;
				if(mapIntFactorIter == pMapIntFactor->end())
					pMapIntFactor->insert(make_pair(myPrime, 1)) ;
				else
					mapIntFactorIter->second++ ;

				ret = prime.isPrime(value) ;
				if(ret)
					break ;
			}
			else
			{
				break ;
			}
		}
	}

	return  ;
}

void CDivisor::getDivisor(int value, std::list<int>* pListDivisor)
{
	int divisor ;

	map<int, pair<int, int> >	       mapUpper ;
	map<int, pair<int, int> >::iterator mapUpperIter ;

	map<long long, int>	   mapIntFactor ;
	map<long long, int>::iterator mapIntFactorIter ;

	pListDivisor->clear() ;
	mapIntFactor.clear() ;

	if(value == 1)
	{
		pListDivisor->push_back(1) ;
		return ;
	}

	getIntegerFactorization(value, &mapIntFactor) ;

//	mapIntFactorIter = mapIntFactor.begin() ;
//	for(; mapIntFactorIter != mapIntFactor.end(); mapIntFactorIter++)
//		printf("[%d.%d]\n", mapIntFactorIter->first, mapIntFactorIter->second) ;

	mapIntFactorIter = mapIntFactor.begin() ;
	for(; mapIntFactorIter != mapIntFactor.end(); mapIntFactorIter++)
		mapUpper.insert(make_pair(mapIntFactorIter->first, make_pair(mapIntFactorIter->second, 0))) ;

	while(1)
	{
		divisor = 1 ;

		mapUpperIter = mapUpper.begin() ;
		for(; mapUpperIter != mapUpper.end(); mapUpperIter++)
		{
			divisor *= pow(mapUpperIter->first, mapUpperIter->second.second) ;
		}
		pListDivisor->push_back(divisor) ;

		mapUpperIter = mapUpper.begin() ;

		while(1)
		{
			mapUpperIter->second.second++ ;

			if(mapUpperIter->second.second > mapUpperIter->second.first)
			{
				mapUpperIter->second.second = 0 ;
				mapUpperIter++ ;

				if(mapUpperIter == mapUpper.end())
					goto getDivisor_while_break ;
				else
					continue ;
			}

			break ;
		}

		continue ;

getDivisor_while_break :
		break ;
	}

	pListDivisor->sort() ;

#if 0
	list<int>::iterator     listDivisorIter = pListDivisor->begin() ;
	for(; listDivisorIter != listDivisor.end(); listDivisorIter++)
		printf("divisor : %d\n", *listDivisorIter) ;
#endif

	return ;
}


int CDivisor::getDivisorNum(int value)
{
	map<long long, int>	   mapIntFactor ;
	map<long long, int>::iterator mapIntFactorIter ;

	mapIntFactor.clear() ;

	getIntegerFactorization(value, &mapIntFactor) ;

	mapIntFactorIter = mapIntFactor.begin() ;

	int ret = 1 ;
	for(; mapIntFactorIter != mapIntFactor.end(); mapIntFactorIter++)
	{
		ret *= (mapIntFactorIter->second + 1) ;
	}

	return ret ;
}

int CDivisor::eulerPhi(long long val)
{
	map<long long, int> 		mapInt ;
	map<long long, int>::iterator 	mapIntIter ;

	int eulerPhi = 1 ;

	getIntegerFactorization(val, &mapInt) ;

	mapIntIter = mapInt.begin() ;

	for(; mapIntIter != mapInt.end(); mapIntIter++)
	{
		for(int jj = 1; jj <= mapIntIter->second; jj++)
			eulerPhi = (jj == 1) ? eulerPhi * (mapIntIter->first - 1) : eulerPhi * mapIntIter->first ;
	}

	return eulerPhi ;
}



///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

long long CInteger::reverse(long long value)
{
	long long temp = 0 ;
	while(1)
	{
		temp += value % 10 ;

		value /= 10 ;

		if(value == 0 )
			break ;

		temp *= 10 ;
	}

	return temp ;
}

int CInteger::palindrome(long long value)
{
	
	long long temp = this->reverse(value) ;

	if(temp == value)
		return 1 ;

	return 0 ;
}


int CInteger::GCD(int a, int b)
{
	while(b != 0)
	{
		m_temp = a % b ;
		a = b ;
		b = m_temp ;
	}
	
	return a ;
}


///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

CCombination::CCombination(vector<int>* vecInt, int r)
{
	m_vecInt = vecInt ;

	m_bitmask.clear() ;
	m_bitmask.resize(r, 1) ;
	m_bitmask.resize(vecInt->size(), 0) ;
}


int CCombination::getNext(vector<int>* vecCombi)
{
	vecCombi->clear() ;

	int size = m_bitmask.size() ;

	for(int ii = 0; ii < size; ii++)
	{
		if(m_bitmask[ii])
			vecCombi->push_back((*m_vecInt)[ii]) ;
	}

	if(!prev_permutation(m_bitmask.begin(), m_bitmask.end()))
		return 0 ;

	return 1 ;
}


