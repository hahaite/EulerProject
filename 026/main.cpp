#include <cstdio>
#include <sys/time.h>

#include "./../bigInt/bigInt.h"
#include "./../mymath/mymath.h"

//    http://blog.naver.com/weizmann_why/60165865541

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	CDivisor divisor ;
	CPrime 	prime ;

	map<long long, int> 		mapInt ;
	map<long long, int>::iterator	mapIntIter ;

	int len = 0 ;
	int maxLen = 0 ;

	CBigInt bigRet ;

	CBigInt big999 ;
	CBigInt bigRemainder ;

	long long ret ;
	long long r999 ;
	long long remainder ;

	long long temp ;

//	for(int ii = 900; ii < 1000; ii++)
	{
		int ii = 977 ;
		
//		if(!prime.isPrime(ii))
//			continue ;


		mapInt.clear() ;
		divisor.getIntegerFactorization(ii, &mapInt) ;

		printf("size : %d\n", mapInt.size()) ;
		
		mapInt.erase(2) ;
		mapInt.erase(5) ;

		mapIntIter = mapInt.begin() ;

//		if(mapIntIter == mapInt.end())
//			continue ;

		bigRet = 1 ;
		for(; mapIntIter != mapInt.end(); mapIntIter++)
			bigRet = bigRet * mapIntIter->first ;

		printf("bigRet : %s\n", bigRet.c_str()) ;

		big999 = 9 ;

		while(1)
		{
#if 1
			bigRemainder = big999 % bigRet ;

			if(bigRemainder == 0)
			{
				len = big999.size() ;
				break ;
			}

			big999 = (big999 * 10) + 9 ;
#endif
		}
		printf("big999 : %s\n", big999.c_str()) ;


		if(len > maxLen)
		{
			maxLen = len ;
			printf("%d - len : %d\n", ii, len) ;
		}
	}



	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
