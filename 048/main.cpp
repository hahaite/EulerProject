#include <cstdio>
#include <sys/time.h>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	long long sum = 0LL ;
	long long value = 0LL ;

	for(int ii = 1; ii <= 1000; ii++)
	{
//		printf("ii : %d\n", ii) ;

		value = ii ;
		for(int jj = 1; jj < ii; jj++)
		{
			value *= ii ;
			if(value >= 10000000000LL)
				value %= 10000000000LL ;

		}

		sum += value ;

		if(sum >= 10000000000LL)
			sum %= 10000000000LL ;
	}

	printf("Result : %lld\n", sum) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
