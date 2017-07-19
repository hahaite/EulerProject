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

        int temp ;
        int n ;
        int sum ;
        int count = 0 ;

        for(int ii = 2; ii < 10000000; ii++)
        {
                sum = 0 ;
                temp = ii ;

                while(1)
                {
                        while(temp)
                        {
                                n = temp % 10 ;
                                n = n*n ;
                                sum += n ;

                                temp /= 10 ;
                        }

                        if(sum == 89)
                                count++ ;

                        if(sum == 1 || sum == 89)
                                break ;

                        temp = sum ;
                        sum = 0 ;
                }

        }

	printf("Result : %d\n", count) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
