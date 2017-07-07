#include <cstdio>
#include <sys/time.h>

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

	CBigInt bigA = 1 ;
	CBigInt bigB = 1 ;
	CBigInt bigSum ;

	int count = 2 ;

	while(1)
	{
		bigSum = bigA + bigB ;
		count++ ;

		bigA = bigB ;
		bigB = bigSum ;

		if(bigSum.size() >= 1000)
			break ;
	}

	printf("count : %d\n", count) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
