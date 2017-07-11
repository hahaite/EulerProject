#include <cstdio>
#include <sys/time.h>

#include "./../bigInt/bigInt.h"

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

#if 1
	CBigInt bigInt ;
//      string strIndex = "0" ;

	CBigInt bigRev ;
	CBigInt bigPal ;

	int flagPal = 0 ;
	int count = 0 ;
	int index = 0 ;

	while(1)
	{
		index++ ;
		if(index == 10001)
			break ;

		bigPal = index ;

		flagPal = 0 ;
		for(int ii = 0; ii < 50; ii++)
		{
			bigRev = bigInt.reverse(bigPal) ;
			bigPal = bigPal + bigRev ;

			printf("big Pal : %s\n", bigPal.c_str()) ;

			flagPal = bigInt.palindrome(bigPal) ;

			if(flagPal)
				break ;
		}

		if(!flagPal)
			count++ ;
	}
#endif

	printf("Result ; %d\n", count) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
