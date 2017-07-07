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

#if 0
	CPrime prime ;

	long long curPrime ;

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
#if 1
	list<int> 		listDivisor ;
	list<int>::iterator 	listDivisorIter ;

	int value = 9 ;
	divisor.getDivisor(value, &listDivisor) ;

	listDivisorIter = listDivisor.begin() ;
	for(; listDivisorIter != listDivisor.end(); listDivisorIter++)
		printf("%d ", *listDivisorIter) ;

	printf("\n") ;
#endif

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
