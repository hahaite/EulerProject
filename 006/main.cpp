#include <cstdio>
#include <sys/time.h>

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int ret1 = 0 ;
	int ret2 = 0 ;

	for(int ii = 1; ii <= 100; ii++)
	{
		ret1 += (ii * ii) ;
		ret2 += ii ;
	}
	ret2 *= ret2 ;

	printf("ret1 : %d\n", ret1) ;
	printf("ret2 : %d\n", ret2) ;

	printf("result : %d\n", ret2 - ret1) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
