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

	int r1, r2, r3, r4 ;

	int sum = 0;

	for(int n = 1; n <= (1001 / 2 + 1); n++)
	{
		r1 = 4 * n * (n -1) + 1 ;
		r2 = 2*n*(2*n-5)+7 ;
		r3 = 4*n*(n-2)+5 ;
		r4 = 2*n*(2*n-3)+3 ;

		sum += r1 + r2 + r3 + r4 ;
	}

	printf("sum : %d\n", sum - 3) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
