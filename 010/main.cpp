#include <cstdio>
#include <sys/time.h>

#include "./../mymath/mymath.h"

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	CPrime prime ;

	long long ret = 0 ;
	long long value = 0 ;

	while(1)
	{
		value = prime.getNextPrime() ;

		if(value > 2000000)
			break ;
		
		ret += value ;
	}

	printf("ret ; %lld\n", ret) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
