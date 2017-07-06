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

	int a = 1 ;
	int b = 2 ;
	int c = 3 ;

	int sum =  2;

	while(1)
	{
		c = a + b ;	

		if( c > 4000000)
			break ;

		if(c % 2 == 0)
			sum += c ;

		a = b ;
		b = c ;
	}

	printf("sum : %d\n", sum) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
