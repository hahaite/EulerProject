#ifndef _PRIME_H_
#define _PRIME_H_

// src about prime : Rosetta Code - Miller Robin Algorithm
// https://rosettacode.org/wiki/Miller%E2%80%93Rabin_primality_test#C

#include <cstdlib>
#include <map>
#include <list>

class CPrime
{
public :
	CPrime() ;
	~CPrime() ;

	bool isPrime(size_t n) ;

	void resetPrime() ;
	long long getNextPrime() ;
private :
	// calcul a^n%mod
	size_t power(size_t a, size_t n, size_t mod) ;

	// n−1 = 2^s * d with d odd by factoring powers of 2 from n−1
	bool witness(size_t n, size_t s, size_t d, size_t a) ;


public :

private :
	long long m_curPrime ;
};


/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

class CDivisor
{
public :
	void getIntegerFactorization(long long value, std::map<long long, int>* pMapIntFactor) ;

	void getDivisor(int value, std::list<int>* pListDivisor) ;
	int getDivisorNum(int value) ;
private :

public :

private :


};







#endif