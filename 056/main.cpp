#include <cstdio>
#include <sys/time.h>

#include <string>

#include "./../bigInt/bigInt.h"

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	CBigInt bigInt ;
	CBigInt bigRet ;

	string*	 pStr ;
	string::iterator strIter ;

	int sum ;
	int maxSum = 0 ;

	for(int ii = 1; ii <= 100; ii++)
	{
		printf("ii : %d\n", ii) ;
		for(int jj = 1; jj <= 100; jj++)
		{
			bigRet = bigInt.pow(ii, jj) ;
			pStr = bigRet.getStrPtr() ;
			strIter = pStr->begin() ;

			sum = 0 ;
			for(; strIter != pStr->end(); strIter++)
			{
				sum += *strIter - '0' ;
			}

			if(sum > maxSum)
				maxSum = sum ;
		}
	}

	printf("maxSum : %d\n", maxSum) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
