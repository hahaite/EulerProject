#ifndef _PRIME_H_
#define _PRIME_H_

// src about prime : Rosetta Code - Miller Robin Algorithm
// https://rosettacode.org/wiki/Miller%E2%80%93Rabin_primality_test#C

#include <cstdlib>
#include <map>
#include <list>
#include <vector>
#include <string>

class CPrime
{
public :
	CPrime() ;
	~CPrime() ;

	bool isPrime(long long n) ;

	void setPrime(long long prime) ;

	void resetPrime() ;
	long long getNextPrime() ;
private :
	// calcul a^n%mod
	long long power(long long a, long long n, long long mod) ;

	// n−1 = 2^s * d with d odd by factoring powers of 2 from n−1
	bool witness(long long n, long long s, long long d, long long a) ;

	int getDigitNumber(long long n) ;

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

	int eulerPhi(long long val) ;

	int is_pairwise_disjoint_set(int a, int b) ;

private :

public :

private :

};

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

class CInteger
{
public :
	long long reverse(long long value) ;
	int palindrome(long long value) ;

	int GCD(int a, int b) ;
private :

public :

private :
	int m_temp ;

};

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

class CCombination
{
public :
	CCombination(std::vector<int>* vecInt, int r) ;

	int getNext(std::vector<int>* vecCombi) ;

private :
	std::string m_bitmask ;
	std::vector<int>* m_vecInt ;
};



#endif
