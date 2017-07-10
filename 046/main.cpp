#include <cstdio>
#include <sys/time.h>

#include <list>

#include "./../mymath/mymath.h"

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	CDivisor divisor ;
	CPrime   primeObj ;

	list<int>	       listDivisor ;
	list<int>::iterator     listDivisorIter ;

	list<int>	       listPrime ;
	list<int>::iterator     listPrimeIter ;

	int checkVal = 0 ;
	int powCnt ;

	int ii = 1 ;
	int prime ;

	while(1)
	{
		ii += 2 ;

		listDivisor.clear() ;
		divisor.getDivisor(ii, &listDivisor) ;

		if(listDivisor.size() < 3)
			continue ;

		primeObj.resetPrime() ;

		while(1)
		{
			prime = primeObj.getNextPrime() ;

			if(prime > ii)
				break ;

			powCnt = 1 ;
			while(1)
			{
				checkVal = prime + (2 * powCnt * powCnt) ;

				if(checkVal >= ii)
					break ;

				powCnt++ ;
			}

			if(checkVal == ii)
			{
//			      printf("%d = %d + ( 2 * ( %d ^2))\n", ii, *listPrimeIter, powCnt) ;
				break ;
			}
		}

		if(prime > ii)
		{
			printf("Result : %d\n", ii) ;
			break ;
		}
	}

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
