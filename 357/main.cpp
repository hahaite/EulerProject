#include <cstdio>
#include <sys/time.h>
#include <cmath>

#include <set>

#include "./../mymath/mymath.h"

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	list<int> 		listDiv ;
	list<int>::iterator 	listDivIter ;

	list<int> 		listSum ;
	list<int>::iterator 	listSumIter ;

	CDivisor divisor ;
	CPrime primeObj ;

	int check ;
	int prime ;

	while(1)
	{
		prime = primeObj.getNextPrime() ;

		if(prime > 100000000)
			break ;

		listDiv.clear() ;
		divisor.getDivisor(prime - 1, &listDiv) ;

		listDivIter = listDiv.begin() ;
		for(; listDivIter != listDiv.end(); listDivIter++)
		{
			check = ((prime-1) / *listDivIter) + *listDivIter ;

			if(!primeObj.isPrime(check))
				break ;
		}

		if(listDivIter == listDiv.end())
		{
			printf("OK : %d\n", prime-1) ;
			listSum.push_back(prime-1) ;
		}
	}

	long long sum = 0 ;

	listSumIter = listSum.begin() ;
	for(; listSumIter != listSum.end(); listSumIter++)
	{
		sum += *listSumIter ;
	}

	printf("Result : %lld\n", sum) ;
	printf("\n") ;

#if 0
	setSizeIter = setSize.begin() ;
	for(; setSizeIter != setSize.end(); setSizeIter++)
	{
		printf("size : %d\n", *setSizeIter) ;
	}
#endif

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
