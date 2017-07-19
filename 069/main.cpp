#include <cstdio>
#include <sys/time.h>

#include "../mymath/mymath.h"

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	CDivisor divisor ;

	int eulerPhi ;
	int max = 0 ;
	double nof ;
	double max_nof = 0 ;

	for(int ii = 2; ii <= 1000000; ii++)
	{
		if(ii % 10000 == 9999)
			printf("ing - %d\n", ii) ;

		eulerPhi = divisor.eulerPhi(ii) ;

		nof = (double)ii/eulerPhi ;

		if(nof > max_nof)
		{
			max_nof = nof ;
			max = ii ;
			printf("%d - %f\n", ii, nof ) ;
		}

	}

	printf("Result : %d\n", max) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
