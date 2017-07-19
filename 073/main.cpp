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

	// from Euler's PHI

	CInteger integer ;

	int count = 0 ;

	for(int d = 1; d <= 12000; d++)
	{
		for(int n = 1; n < d; n++)
		{
			if(((3 * n) - d) > 0 &&
					(d - (2*n)) > 0LL)
			{
				if(integer.GCD(d, n) == 1)
					count++ ;
			}
		}
	}

	printf("Result : %d\n", count) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
