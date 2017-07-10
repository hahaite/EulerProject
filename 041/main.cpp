#include <cstdio>
#include <sys/time.h>

#include <vector>
#include <algorithm>

#include "./../mymath/mymath.h"

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	vector<int> 		vecPrime ;
	vector<int>::iterator 	vecPrimeIter ;

	int prime ;
	CPrime primeObj ;

	for(int nn = 2; nn <= 9; nn++)
	{
		vecPrime.clear() ;
		for(int ii = 1; ii <= nn; ii++)
			vecPrime.push_back(ii) ;

		while(1)
		{
			prime = 0 ;
			for(int ii = 0; ii < nn; ii++)
			{
				prime += vecPrime[ii] ;
				
				if(ii != nn - 1)
					prime *= 10 ;
			}

			if(primeObj.isPrime(prime))
				printf("%d\n", prime) ;

			reverse(vecPrime.begin() + nn, vecPrime.end()) ;

			if(!next_permutation(vecPrime.begin(), vecPrime.end()))
				break ;
		}
	}

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
