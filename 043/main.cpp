#include <cstdio>
#include <sys/time.h>

#include <algorithm>
#include <cstring>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int pan[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0} ;
	int sum[16] ;

	int d2, d3, d4, d5, d6, d7, d8, prevD2 ;
	memset(sum, 0x00, sizeof(sum)) ;

	while(1)
	{
		d2 = (pan[1] * 100) + (pan[2] * 10) + pan[3] ;
		d3 = (pan[2] * 100) + (pan[3] * 10) + pan[4] ;
		d4 = (pan[3] * 100) + (pan[4] * 10) + pan[5] ;
		d5 = (pan[4] * 100) + (pan[5] * 10) + pan[6] ;
		d6 = (pan[5] * 100) + (pan[6] * 10) + pan[7] ;
		d7 = (pan[6] * 100) + (pan[7] * 10) + pan[8] ;
		d8 = (pan[7] * 100) + (pan[8] * 10) + pan[9] ;

		if(d2 % 2 != 0)
			goto while_continue ;
		if(d3 % 3 != 0)
			goto while_continue ;
		if(d4 % 5 != 0)
			goto while_continue ;
		if(d5 % 7 != 0)
			goto while_continue ;
		if(d6 % 11 != 0)
			goto while_continue ;
		if(d7 % 13 != 0)
			goto while_continue ;
		if(d8 % 17 != 0)
			goto while_continue ;

		for(int ii = 0; ii < 10; ii++)
			printf("%d", pan[ii]) ;
		printf("\n") ;

		for(int ii = 0; ii < 10; ii++)
			sum[6 + ii] += pan[ii] ;
while_continue :
		if(!next_permutation(pan, &pan[10]))
			break ;
	}

	int upper ;
	for(int ii = 15; ii >= 0; ii--)
	{
		upper = sum[ii] / 10 ;
		sum[ii] %= 10 ;

		sum[ii-1] += upper ;
	}

	int ii, jj ;

	for(ii = 0; ii < 16; ii++)
	{
		if(sum[ii] != 0)
			break ;
	}

	printf("SUM : ") ;
	for(jj = ii; jj < 16; jj++)
		printf("%d", sum[jj]) ;
	printf("\n") ;

	return 1 ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
