#include <cstdio>
#include <sys/time.h>

using namespace std ;


int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	long long a ;

	a = 1LL ;

	for(int ii = 0; ii < 7830457; ii++)
	{
		a = a * 2 ;
		a %= 10000000000LL ;
	}

	a *= 28433 ;
	a++ ;
	a %= 10000000000LL ;

	printf("Result : %lld\n", a) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
