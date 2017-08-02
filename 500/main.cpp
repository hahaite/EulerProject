#include <cstdio>
#include <sys/time.h>
#include <cmath>

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

	CPrime primeObj ;

	list<int> 			listInt ;
	list<int>::iterator 		listIntIter ;

	long long prime ;
	long long temp ;


	for(int ii = 1; ii <= 500500; ii++)
	{
		prime = primeObj.getNextPrime() ;

		// 500500th prime is about 7,300,000
		// 2750 * 2750 = about 7,500,00
		if(ii > 2750)
		{
			listInt.push_back(prime) ;
			continue ;
		}

		temp = prime ;
		for(int exp = 1; exp <= 128; exp = exp * 2)
		{
			temp = pow(prime, exp) ;	
			if(temp > 7400000)
				break ;

			listInt.push_back(temp) ;
		}
	}

	listInt.sort() ;

	while(1)
	{
		listInt.pop_back() ;
		if(listInt.size() == 500500)
			break ;
	}
	printf("size : %d\n", listInt.size()) ;
	
	temp = 1 ;
	listIntIter = listInt.begin() ;

	while(1)
	{
		temp *= *listIntIter ;

		if(temp > 500500507)
		{
			listInt.push_back(temp % 500500507) ;
			temp = 1 ;
		}

		listIntIter++ ;
		listInt.pop_front() ;

		if(listIntIter == listInt.end())
			break ;
	}
	printf("Result : %d\n", temp) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
