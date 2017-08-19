#include <cstdio>
#include <sys/time.h>

#include <cstdlib>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int max = 1 ;
	for(int ii = 0; ii < 9; ii++)
		max *= 4 ;

	printf("max4 ; %d\n", max) ;
	// 262144
	
	int sum4[262144] ;

	int temp ;
	int sum ;
	for(int nn = 0; nn < 262144; nn++)
	{
		temp = nn ;
		sum = 0 ;
		for(int ii = 0; ii < 9; ii++)
		{
//			printf("%d ", (temp % 4) + 1) ;
			sum += (temp % 4) + 1 ;
			temp /= 4 ;
		}
//		printf("--- %d\n", sum) ;
		sum4[nn] = sum ;
	}

	max = 1 ;
	for(int ii = 0; ii < 6; ii++)
		max *= 6 ;

	printf("max6 ; %d\n", max) ;
	// 46656
	int sum6[46656] ;

	for(int nn = 0; nn < max; nn++)
	{
		temp = nn ;
		sum = 0 ;
		for(int ii = 0; ii < 6; ii++)
		{
//			printf("%d ", (temp % 6) + 1) ;
			sum += (temp % 6) + 1 ;
			temp /= 6 ;
		}
//		printf("--- %d\n", sum) ;
		sum6[nn] = sum ;
	}

	long long win = 0 ;
	long long total = 262144L * 46656L ;

	for(int ii = 0; ii < 262144; ii++)
	{
		for(int jj = 0; jj < 46656; jj++)
		{
			if(sum4[ii] > sum6[jj])
				win++ ;
		}
	}

	printf("win : %lld\n", win) ;
	printf("total : %lld\n", total) ;

	printf("Result : %.7llf\n", (long double)win / total) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
