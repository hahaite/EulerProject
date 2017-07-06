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

	CPrime prime ;

	long long value = 600851475143 ;

	long long curPrime ;
	long long ret ;

	while(1)
	{
		curPrime = prime.getNextPrime() ;	

		if( value % curPrime == 0)
		{
			value /= curPrime ;
			prime.resetPrime() ;

			if(prime.isPrime(value))
				break ;
		}
	}

	printf("value : %lld\n", value) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
