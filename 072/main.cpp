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

        // from Euler's PHI

        CDivisor divisor ;
        long long count = 0LL ;

        for(int ii = 2; ii <= 1000000; ii++)
        {
                if(ii % 10000 == 0)
                        printf("d : %d\n", ii) ;

                count += divisor.eulerPhi(ii) ;
        }

	printf("Result : %lld\n", count) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
