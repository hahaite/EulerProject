#include <cstdio>
#include <sys/time.h>

#include <map>

using namespace std ;


int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int next, cur;

	int flagInc, flagDec ;
	int temp ;
	int bouncy = 0 ;

	int ii = 99 ;

	double rate ;

	while(1)
	{
		ii++ ;

		flagInc = 0 ;
		flagDec = 0 ;

		temp = ii ;

		while(temp)
		{
			cur = temp % 10 ;
			temp /= 10 ;
			next = temp % 10 ;

			if(!flagDec && (next > cur))
				flagDec = 1 ;

			if(!flagInc && (cur > next))
				flagInc = 1 ;

			if(flagDec && flagInc)
				break ;

			if(temp < 10)
				break ;
		}

#if 0
		if(!flagDec && flagInc)
			printf("Inc ; %d\n", ii) ;

		if(flagDec && !flagInc)
			printf("Dec ; %d\n", ii) ;

		if(flagDec && flagInc)
			printf("Bouncy ; %d\n", ii) ;
#endif

		if(flagDec && flagInc)
			bouncy++ ;


		rate = (double)bouncy/ii ;
		rate *= 100 ;

		if(rate > 99)
		{
			ii-- ;
			printf("Find : %d\n", ii) ;
			break ;

		}
	}

	printf("bouncy Count : %d\n", bouncy) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
