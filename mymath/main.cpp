#include <cstdio>

#include <sys/time.h>
#include <map>

#include "mymath.h"

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	CPrime prime ;
#if 0
	long long curPrime ;

	curPrime = prime.getNextPrime() ;	
	printf("cur Prime : %lld\n", curPrime) ;
#endif

#if 0
	long long curPrime ;

	prime.setPrime(1008) ;	
	curPrime = prime.getNextPrime() ;	
	printf("cur Prime : %lld\n", curPrime) ;
#endif

	CDivisor divisor ;

// test - get integer factorization.
#if 0
	map<long long, int> 		mapIntFactor ;
	map<long long, int>::iterator 	mapIntFactorIter ;

	divisor.getIntegerFactorization(8, &mapIntFactor) ;

	mapIntFactorIter = mapIntFactor.begin() ;
	for(; mapIntFactorIter != mapIntFactor.end(); mapIntFactorIter++)
	{
		printf("Integer Factorialization : [%d, %d]\n", mapIntFactorIter->first, mapIntFactorIter->second) ;
	}
#endif


// test - get divisor
#if 0
	list<int> 		listDivisor ;
	list<int>::iterator 	listDivisorIter ;

	int value = 9 ;
	divisor.getDivisor(value, &listDivisor) ;

	listDivisorIter = listDivisor.begin() ;
	for(; listDivisorIter != listDivisor.end(); listDivisorIter++)
		printf("%d ", *listDivisorIter) ;

	printf("\n") ;
#endif

// test - get divisor number
#if 0
	int num = divisor.getDivisorNum(72) ;
	printf("divisor number ; %d\n", num) ;
#endif

	CInteger integer ;

	int rev = integer.reverse(12345001) ;
	printf("rev : %d\n", rev) ;




	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
