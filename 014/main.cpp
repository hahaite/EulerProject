#include <cstdio>
#include <string>
#include <sys/time.h>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	long long next ;

	int maxIndex = 0 ;
	int maxCount = 0 ;

	int count ;

	for(int ii = 2; ii < 1000000; ii++)
	{
//		if(ii % 1000 == 0)
//			printf("ii : %d\n", ii) ;

		count = 0 ;
		next = ii ;

		int tmp = 0 ;

		while(1)
		{
			count++ ;

			next = (next % 2 == 0) ? next / 2 : (next * 3) + 1 ;

			if(next == 1)
			{
				if(count > maxCount)
				{
					maxCount = count ;
					maxIndex = ii ;
				}
				break ;
			}
		}
	}

	printf("max Index  = %d\n", maxIndex) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
