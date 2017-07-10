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

	int a, b, c, d, aa, bb;
	int total = 0 ;

	int retA = 1;
	int retB = 1;

	int chkA ;
	int chkB ;

	for(int ii = 2; ii < 9999; ii++)
	{
		a = ii / 1000 ;
		b = (ii / 100) % 10 ;
		c = (ii / 10) % 10 ;
		d = ii % 10 ;

		aa = a * 10 + b ;
		bb = c * 10 + d ;

		if(bb >= aa)
			continue ;

		if(bb < 10)
			continue ;

		if(a != d && b != c)
			continue ;

		chkA = ((double)bb / aa) * 1000 ;

		if(a == d)
			chkB = ((double)c / b) * 1000 ;
		else
			chkB = ((double)d / a) * 1000 ;

		if(chkA != chkB)
			continue ;

		total++ ;
		retA *= aa ;
		retB *= bb ;
		printf("%2d / %2d\n", bb, aa) ;
	}
	printf("A / B : %d / %d\n", retB, retA) ;
	printf("Result : %d\n", retA/ retB) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
