#include <cstdio>
#include <sys/time.h>

#include "../mymath/mymath.h"

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////


	CInteger integer ;

	double val ;

	long long prevN = 0LL ;
	long long prevD = 1LL ;

	int ret ;

	for(int d = 1; d < 1000000; d++)
	{
		for(int n = (d * 2) / 5; n < d; n++)
		{
			ret = (7*n) - (3*d) ;

			if(ret > 0)
				break ;

			if(((n*prevD) - (d*prevN)) > 0LL &&
					((3LL*d) - (7LL*n)) > 0LL)
			{
				if(integer.GCD(d, n) == 1)
				{
					prevN = n ;
					prevD = d ;
//					printf("%lld / %lld \n", prevN, prevD) ;
				}
			}
		}
	}

	printf("prev N/D = %lld / %lld\n", prevN, prevD) ;
	printf("Result = %lld\n", prevN) ;



	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
