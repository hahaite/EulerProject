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

	long long a ;
	long long b ;
	long long ret ;

	double root2 = 1.414213562373095048801688724209698078569671 ;
	double rOdd = root2 + 2 ;
	double rEven = rOdd / 2 ;

	a = 3LL ;
	b = (double)a * rEven ;

	int flag = 0 ;

	for(int ii = 0; ii < 14; ii++)
	{

		a = b ;
		if(!flag)
			b = (double)a * rOdd ;
		else
			b = (double)a * rEven ;
		ret = a * b ;
		printf("%lld = %lld * %lld\n", ret, a, b ) ;

		flag ^= 1 ;

	}
	printf("Result : %lld\n", ret) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
