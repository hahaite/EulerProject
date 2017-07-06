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

	map<long long, int> 		mapIntFactor ;
	map<long long, int>::iterator 	mapIntFactorIter ;

	CDivisor divisor ;

//	void getIntegerFactorization(int value, std::map<long long, int>* pMapIntFactor) ;

	divisor.getIntegerFactorization(252, &mapIntFactor) ;

	mapIntFactorIter = mapIntFactor.begin() ;
	for(; mapIntFactorIter != mapIntFactor.end(); mapIntFactorIter++)
	{
		printf("Integer Factorialization : [%d, %d]\n", mapIntFactorIter->first, mapIntFactorIter->second) ;
	}


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
