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

	int n ;
	int rn ;
	int sum ;
	int temp ;

	int checkCount = 0 ;

	for(int ii = 1; ii < 1000000000; ii++)
	{
		n = ii ;
		temp = n ;
	
		if(n % 10 == 0)
			continue ;
		
		rn = 0 ;
		while(temp)
		{
			rn *= 10 ;
			rn += temp % 10 ;
			temp /= 10 ;	
		}

		sum = n + rn ;

		temp = sum ;
		while(temp)
		{
			if((temp % 10)%2 == 0)
				break ;

			temp /= 10 ;
		}
		
		if(temp)
			continue ;

		checkCount++ ;
	}

	printf("check count : %d\n", checkCount) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
