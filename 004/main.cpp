#include <cstdio>
#include <sys/time.h>

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int ret ;
	int temp ;
	int reverse ;

	int max = 0 ;

	for(int ii = 100; ii < 1000; ii++)
	{
		for(int jj = 100; jj < 1000; jj++)
		{
			ret = ii * jj ;

			reverse = 0 ;
			
			temp = ret ;
			while(temp)
			{
				reverse *= 10 ;
				reverse += (temp % 10) ;
				temp /= 10 ;
			}

			if((ret == reverse) && (ret > max))
					max = ret ;
		}
	}

	printf("max : %d\n", max) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
