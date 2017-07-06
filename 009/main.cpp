#include <cstdio>
#include <cstring>
#include <sys/time.h>

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

        int a, b, c ;
        int flagFind = 0 ;

        for(int a = 1; a < 1000; a++)
        {

                for(int b = 1; b < 1000; b++)
                {
                        for(int c = 1; c < 1000; c++)
                        {
                                if(((a*a) + (b*b) == (c*c)) && (a + b + c) == 1000)
                                {
                                        printf("%d %d %d = %d\n", a, b, c, a*b*c) ;
                                        flagFind = 1 ;
                                        break ;
                                }
                        }

                        if(flagFind)
                                break ;
                }

                if(flagFind)
                        break ;
        }

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
