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

	list<int>	       listDigitLeft ;
	list<int>	       listDigitRight ;
	list<int>::iterator     listDigitIter ;

	int temp ;
	int sum = 0 ;
	int retCount = 0 ;
	int prime ;

	CPrime primeObj ;

	while(1)
	{
		prime = primeObj.getNextPrime() ;

		if(prime < 10)
			continue ;

		temp = prime ;
		listDigitLeft.clear() ;
		listDigitRight.clear() ;

		while(temp)
		{
			listDigitLeft.push_front(temp % 10) ;
			listDigitRight.push_front(temp % 10) ;
			temp /= 10 ;
		}

		// remove left
		while(1)
		{
			listDigitLeft.pop_front() ;

			temp = 0 ;
			listDigitIter = listDigitLeft.begin() ;
			for(; listDigitIter != listDigitLeft.end(); listDigitIter++)
			{
				temp *= 10 ;
				temp += *listDigitIter ;
			}

			if(!primeObj.isPrime(temp))
				goto while_continue ;

			if(listDigitLeft.size() == 1)
				break ;
		}

		// remove Right
		while(1)
		{
			listDigitRight.pop_back() ;

			temp = 0 ;
			listDigitIter = listDigitRight.begin() ;
			for(; listDigitIter != listDigitRight.end(); listDigitIter++)
			{
				temp *= 10 ;
				temp += *listDigitIter ;
			}

			if(!primeObj.isPrime(temp))
				goto while_continue ;

			if(listDigitRight.size() == 1)
				break ;
		}

		sum += prime ;
		printf("FIND : %d\n", prime ) ;

		retCount++ ;

		if(retCount == 11)
			break ;

while_continue :
		continue ;
	}

	printf("SUM : %d\n", sum) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
