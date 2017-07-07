#include <cstdio>
#include <sys/time.h>

#include "./../mymath/mymath.h"

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int ret ;
	int ii ;

	int count ;
	int countMax = 0 ;
	int maxA, maxB ;

	CPrime prime ;

	for(int a = -1000; a <= 1000; a++)
	{
		for(int b = -1000; b <= 1000; b++)
		{
			ii = 0 ;
			count = 0 ;

			while(1)
			{
				ret = (ii * ii) + (a * ii) + b ;

				if(prime.isPrime(ret))
				{
					count++ ;
					ii++ ;
				}
				else
				{
					if(count > countMax)
					{
						countMax = count ;
						maxA = a ;
						maxB = b ;
						printf("a = %d, b = %d, max = %d\n", a, b, count) ;
					}
					break ;
				}
			}
		}
	}

	printf("RET : a * b = %d\n", maxA * maxB ) ;





	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
