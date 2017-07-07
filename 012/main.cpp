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

	int index = 2 ;
	int sum = 3 ;

	int size ;

	while(1)
	{
		size = divisor.getDivisorNum(sum) ;

		if(size >= 500)
			break ;

		index++ ;
		sum += index ;
	}

	printf("ret : %d\n", sum) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
