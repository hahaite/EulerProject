#include <cstdio>
#include <sys/time.h>

#include <string>

#include "./../mymath/mymath.h"

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

// north-west : (2n-1)^2 -4(n-1)
// north-east : (2n-1)^2 -6(n-1)
// south-west : (2n-1)^2 -2(n-1)
// south-east : (2n-1)^2

	int r1, r2, r3, r4 ;
	int max ;
	int n = 1 ;
	int count = 0 ;

	CPrime primeObj ;

	while(1)
	{
		n++ ;
		r1 = 4*(n*n) - (10 * n) + 7 ;
		r2 = 4*(n*n) - (8 * n) + 5 ;
		r3 = 4*(n*n) - (6 * n) + 3 ;
// 		r4 = 4*(n*n) - (4 * n) + 1 ;

		max = (4*n) - 3 ;

		if(primeObj.isPrime(r1))
			count++ ;

		if(primeObj.isPrime(r2))
			count++ ;

		if(primeObj.isPrime(r3))
			count++ ;

		if(count * 100 / max < 10)
		{
			printf("%d : max : %d\n", n, max) ;
			break ;
		}
	}

	printf("ret : %d\n", (2 * n) - 1) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
