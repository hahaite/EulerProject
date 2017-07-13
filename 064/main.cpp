#include <cstdio>
#include <sys/time.h>

#include <cmath>
#include <cstring>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	//	 ra + c
	//    d + ---------
	//	    b

	int a, b, c, d ;
	int square = 2 ;

	int repeat[10000] ;

	int retTop ;
	int ret[30] ;
	int odd = 0 ;

	for(int ii = 2; ii <= 10000; ii++)
	{
		if(ii == square * square)
		{
			square++ ;
//		      printf("%d -> PASS~!!\n", ii) ;
			continue ;
		}


		a = ii ;
		b = 1 ;

		d = sqrt(a) ;
		c = -d ;

		for(int jj = 0; jj < 10000; jj++)
		{
			d = b / ((sqrt(a) + c)) ;
			b = (a - (c*c)) / b ;
			c = -c - (b * d) ;

			repeat[jj] = d ;

// 			printf("%d + (r%d + %d) / %d\n", d, a, c, b) ;
		}

#if 0
		printf("%d ==>> ", ii) ;
		for(int aa = 0; aa < 30; aa++)
		{
			printf("%2d ", repeat[aa]) ;
		}
		printf("\n") ;
#endif


		int flagContinue = 0 ;
		for(int kk = 1; kk < 1500; kk++)
		{
			retTop = memcmp(repeat, &repeat[kk], kk * 4) ;

			if(!retTop)
			{
				flagContinue = 0 ;
				for(int tt = 0; tt < 30; tt++)
				{
					ret[tt] = memcmp(repeat, &repeat[kk * (tt + 2)], kk * 4) ;

					if(ret[tt])
					{
						flagContinue = 1 ;
						break ;
					}
				}

				if(flagContinue)
					continue ;

//				printf("length : %d\n", kk) ;
				if(kk % 2 == 1)
				{
//					printf("ODD : %d, length : %d\n", ii, kk) ;
					odd++ ;
				}

#if 0
				if(kk == 2)
				{
					printf("%d ==>> ", ii) ;
					for(int aa = 0; aa < 40; aa++)
					{
						printf("%2d ", repeat[aa]) ;
					}
					printf("\n") ;
				}
#endif
				break ;
			}
		}
	}

	printf("odd Count ; %d\n", odd) ;













	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
