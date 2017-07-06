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
	prime.resetPrime() ;
	int ret ;

	for(int ii = 0; ii < 10001; ii++)
		ret = prime.getNextPrime() ;

	printf("ret ; %d\n", ret) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
