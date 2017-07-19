#include <cstdio>
#include <sys/time.h>

using namespace std ;

long long isSquare(long long n)
{
	// checkMax
	long long sqr = 10 ;
	while(1)
	{
		if(n < (sqr * sqr))
			break ;

		sqr = (sqr * 3) ;
	}

	// check Square
	long long left = 1 ;
	long long right = sqr ;
	long long mid = (left + right) / 2 ;

	while(1)
	{
		sqr = mid * mid ;
		if(n == sqr)
		{
//			printf("OK~!! %lld = %lld^2\n", n, mid) ;
			return mid ;
		}

		if(n > sqr)
			left = mid ;
		else
			right = mid ;

		mid = (left + right) / 2 ;


		if(mid == left || mid == right)
			break ;
	}

//      printf("not SQR - %d\n", n) ;
	return 0 ;
}

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	long long a, b ;
	int ret ;

	long long chk1 ;


	long long lenSum = 0 ;

	for(int ii = 2; ii < 340000000; ii++)
	{
		a = ii ;
		b = ii - 1 ;

		chk1 = (2*a + b)* (2*a - b) ;

		ret = isSquare(chk1) ;

		if(!ret)
			continue ;

		// It's the square.
		int len = a + a + b ;
		lenSum += len ;
// 		int size = (b * (isSquare((a*a) - (b*b/4)))/2) ;
		printf("CHK1 -> %d, %d, length : %d\n", a, b, len) ;

		if(len > 1000000000)
			printf("WARNING~! over max len\n") ;
	}


	for(int ii = 2; ii < 340000000; ii++)
	{
		a = ii ;
		b = ii + 1 ;

		chk1 = (2*a + b)* (2*a - b) ;

		ret = isSquare(chk1) ;

		if(!ret)
			continue ;

		// It's the square.
		int len = a + a + b ;
		lenSum += len ;

// 		int size = (b * (isSquare((a*a) - (b*b/4)))/2) ;
		printf("CHK1 -> %d, %d, length : %d\n", a, b, len) ;

		if(len > 1000000000)
			printf("WARNING~! over max len\n") ;

	}

	printf("length Sum : %lld\n", lenSum) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
