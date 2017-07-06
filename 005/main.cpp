#include <cstdio>
#include <sys/time.h>

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int primeList[8] = {2, 3, 5, 7, 11, 13, 17, 19} ;
	int prime ;
	int data[20] ;

	for(int ii = 1; ii <= 20; ii++)
		data[ii-1] = ii ;

	int ret = 1 ;
	int flag = 0 ;
	
	for(int ii = 0; ii < 8; ii++)
	{
		prime = primeList[ii] ;

		while(1)
		{
			flag = 0 ;
			for(int jj = 0; jj < 20; jj++)
			{
				if(data[jj] % prime == 0)
				{
					data[jj] /= prime ;
					flag = 1 ;
				}
			}

			if(flag)
			{
				printf("prime : %d\n", prime) ;
				ret *= prime ;
			}
			else
			{
				break ;
			}
		}
	}

	printf("ret : %d\n", ret) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
