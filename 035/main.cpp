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

	list<int> 		listDigit ;
	list<int>::iterator 	listDigitIter ;

	int temp ;
	int circularPrime = 0 ;

	CPrime cprm ;

	int index = 0 ;
	int prime ;

	while(1)
	{
		prime = cprm.getNextPrime() ;

		listDigit.clear() ;

		if(prime > 1000000)
			break ;

		temp = prime ;

		while(temp)
		{
			listDigit.push_front(temp % 10) ;
			temp /= 10 ;
		}

		if(listDigit.size() == 1)
		{
			circularPrime++ ;
			continue ;
		}

		for(int ii = 0; ii < listDigit.size() ; ii++)
		{
			temp = 0 ;
			listDigitIter = listDigit.begin() ;
			for(; listDigitIter != listDigit.end(); listDigitIter++)
			{
				temp *= 10 ;
				temp += *listDigitIter ;
			}

			if(!cprm.isPrime(temp))
				break ;

			if(ii == listDigit.size() - 1)
			{
				printf("OK~~!! Circular prime : %d\n", temp) ;
				circularPrime++ ;
				break ;
			}

			listDigitIter = listDigit.begin() ;
			temp = *listDigitIter ;

			listDigit.push_back(temp) ;
			listDigit.pop_front() ;
		}
	}

	printf("Result : %d\n", circularPrime) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
