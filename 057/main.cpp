#include <cstdio>
#include <sys/time.h>

#include <string>

#include "./../bigInt/bigInt.h"

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

        CBigInt a ;
        CBigInt b ;
        CBigInt ret ;

        CBigInt ra ;
        CBigInt rb ;

        int count = 0 ;

        for(int ii = 2; ii < 1000; ii++)
        {
		printf("ii : %d\n", ii) ;	
                ra = 2 ;
                rb = 1 ;
                for(int jj = 0; jj < ii; jj++)
                {
                        a = ra ;
                        b = rb ;

                        ra = (a + a) + b ;
                        rb = a ;

                }

                a = ra ;
                b = rb ;

                ra = a + b ;
                rb = a ;

//              printf("RESULT[%d] : ra, rb ; %s / %s\n", ii, ra.c_str(), rb.c_str() ) ;

                if(ra.size() > rb.size())
                        count++ ;

        }

        printf("result : %d\n", count) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
