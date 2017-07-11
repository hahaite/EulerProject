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

	CBigInt bigA ;

	int count = 0 ;
	for(int n = 1; n <= 100; n++)
	{
		printf("n : %d\n", n) ;
		for(int r = 1; r <= n; r++)
		{
			bigA = bigA.combinations(n, r) ;

			if(bigA >= 1000000)
				count++ ;
		}
	}

	printf("count : %d\n", count) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
