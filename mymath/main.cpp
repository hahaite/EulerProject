#include <cstdio>

#include <sys/time.h>
#include <map>
#include <vector>

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
	CDivisor divisor ;

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


// test - get integer factorization.
#if 0
	map<long long, int> 		mapIntFactor ;
	map<long long, int>::iterator 	mapIntFactorIter ;

	divisor.getIntegerFactorization(17, &mapIntFactor) ;

	int divisorNumber = 1 ;

	mapIntFactorIter = mapIntFactor.begin() ;
	for(; mapIntFactorIter != mapIntFactor.end(); mapIntFactorIter++)
	{
		printf("Integer Factorialization : [%d, %d]\n", mapIntFactorIter->first, mapIntFactorIter->second) ;
		divisorNumber *= (mapIntFactorIter->second + 1) ;
	}
	printf("number of divisor : %d\n", divisorNumber) ;

#endif


// test - get divisor
#if 0
	list<int> 		listDivisor ;
	list<int>::iterator 	listDivisorIter ;

	int value = 120 ;
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

#if 0
	int rev = integer.reverse(12345001) ;
	printf("rev : %d\n", rev) ;
#endif


// test - combination
#if 0
        vector<int> vecInt ;
        vector<int> vecCombi ;

        int n = 7 ;
        int r = 4 ;

        for(int ii = 1; ii <= n; ii++)
                vecInt.push_back(ii) ;

        CCombination combination(&vecInt, r) ;

        int flagBreak ;

	int test = 0 ;

        while(1)
        {
		test++ ;

		if(test == 12)
			combination.skipThis(vecCombi[1]) ;

                flagBreak = combination.getNext(&vecCombi) ;

                for(int ii = 0; ii < r; ii++)
                        printf("%d ", vecCombi[ii]) ;
                printf("\n") ;

                if(!flagBreak)
                        break ;
        }
#endif

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
