#include <cstdio>
#include <sys/time.h>

#include <set>
#include <cstdlib>
#include "../bigInt/bigInt.h"

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

        CBigInt bigN ;
        CBigInt bigA ;
        CBigInt bigR ;

        bigN = 2 ;
        bigR = 1 ;

        bigA = 1 ;

        string* pStr ;
        string::iterator        strIter ;

        int sum = 0 ;
        int totalSum = 0 ;
        int index = 2 ;
        int power = 4 ;

        for(int n = 2; n < 100; n++)
        {
                if(n == power)
                {
                        index++ ;
                        power = index * index ;
                        continue ;
                }

                bigN = n ;
                bigA = 1 ;
                sum = 0 ;

                for(int ii = 0; ii < 110; ii++)
                {

                        for(int jj = 0; jj < 10; jj++)
                        {
                                bigA++ ;
                                bigR = bigR.pow(bigA, 2) ;

                                if(bigR > bigN)
                                {
                                        bigA-- ;
                                        break ;
                                }
                        }

                        bigA  = bigA * 10 ;
                        bigN = bigN * 100 ;
                }
                pStr = bigA.getStrPtr() ;


                strIter = pStr->begin() ;

                for(int ii = 0; ii < 100; ii++)
                {
                        sum += (*strIter - '0') ;
                        strIter++ ;
                }

                printf("[%d] sum : %d\n", n, sum) ;
                totalSum += sum ;
        }

        printf("total : %d\n", totalSum) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
