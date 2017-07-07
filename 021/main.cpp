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

	CDivisor divisor ;

	list<int>	       listDivisor ;
	list<int>::iterator     listDivisorIter ;

	int sum = 0 ;
	int sum2 = 0 ;

	int ret = 0 ;

	for(int ii = 2; ii <= 10000; ii++)
	{
		divisor.getDivisor(ii, &listDivisor) ;

		listDivisor.pop_back() ;
		listDivisorIter = listDivisor.begin() ;

		sum = 0 ;
		sum2 = 0 ;
		for(; listDivisorIter != listDivisor.end(); listDivisorIter++)
			sum += *listDivisorIter ;

		if(ii != sum && 2 <= sum && sum <= 10000)
		{
			divisor.getDivisor(sum, &listDivisor) ;

			listDivisor.pop_back() ;

			listDivisorIter = listDivisor.begin() ;
			for(; listDivisorIter != listDivisor.end(); listDivisorIter++)
				sum2 += *listDivisorIter ;

		}

		if(ii != sum && ii == sum2)
		{
			printf("ii : %d, sum : %d\n", ii, sum) ;
			ret += ii ;
		}
	}

	printf("Result : %d\n", ret) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
