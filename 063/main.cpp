#include <cstdio>
#include <sys/time.h>

#include <set>

#include "./../bigInt/bigInt.h"

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	CBigInt bigA ;
	int flagFound = 0 ;
	int size ;
	int count = 0 ;

	int exp = 0 ;

	while(1)
	{
		exp++ ;
		flagFound = 0 ;
		for(int ii = 1; ii < 10; ii++)
		{	
			bigA = bigA.pow(ii, exp) ;

			size = bigA.size() ;
			if(size == exp)
			{
				count++ ;
				printf("%d - pow(%d, %d) = %s\n", count, ii, exp, bigA.c_str()) ;
				flagFound = 1 ;
			}
			
			if(size > exp)
				break ;
		}

		if(!flagFound)
			break ;
	}
	printf("Result : %d\n", count) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
