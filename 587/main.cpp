#include <cstdio>
#include <sys/time.h>

#include <cmath>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int a, b, c ;  // a(X^2) + bX + c = 0 
	
	double b4ac ;
	double x, y ;
	double triSize ;
	double arcSize ;
	double totalSize ;

	double occupyPercent ;

	double targetSize = 1 - ((3.1415926545)/4) ;

	printf("Target Size : %.10f\n", targetSize) ;

	const double GAP = 0.000001 ;

	int ii = 0 ;
	while(1)
	{
		// circle function : (x-1)^2 + (y-1)^2 = 1 ;
		// line function : y = x, y = (1/2)x, y = (1/3)x .....
		// find cross points x, y between line and circle.
		ii++ ;
		a = (ii * ii) + 1 ;
		b = -((ii * 2) + 2) ;
		c = 1 ;

		b4ac = sqrt((b * b) - 4 * a * c) ;

		y = (double)(-b - b4ac) / (2 * a) ;
		x = ii * y ;

		// get Size under line.
		triSize = (x * y) / 2 ;

		// get size under arc 
		arcSize = 0 ;
		for(double jj = x ; jj <= 1; jj = jj + GAP)
		{
			y = 1 - sqrt(jj * (2 - jj)) ;

			arcSize += (GAP * y) ;	
		}

		totalSize = triSize + arcSize ;

		occupyPercent = (totalSize / targetSize) * 100 ;

		printf("%d : %.8f\n", ii, occupyPercent ) ;
	
		if(occupyPercent < 0.1)
		{
			break ;	
		}
	}

	printf("\n======= Result : %d\n\n", ii) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
