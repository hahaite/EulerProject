#include <cstdio>
#include <sys/time.h>

#include <list>
#include "./../bigInt/bigInt.h"
#include "./../fraction/fraction.h"

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	CBigInt bigInt ;
	CFraction frac ;

	CBigInt bigX ;
	CBigInt bigY ;
	CBigInt bigD ;

	CBigInt bigA ;
	CBigInt bigB ;

	CBigInt bigTemp ;
	CBigInt bigMax = 0 ;

	list<int>	       listInt ;
	list<int>::iterator     listIntIter ;

	int ret ;
	int maxii ;

	for(int ii = 2; ii <= 1000; ii++)
	{
		int listSize = 0 ;
		while(1)
		{
			listInt.clear() ;
			frac.contFraction_SquaredRoot(ii, &listInt, listSize++) ;
			if(listInt.empty())
				break ;

			listIntIter = listInt.end() ;

			bigX = 0 ;
			bigY = 1 ;

			while(1)
			{
				listIntIter-- ;

				if(listIntIter == listInt.begin())
					break ;

				bigA = *listIntIter ;
				bigB = 1 ;

				bigInt.fraction_add(bigA, bigB, bigX, bigY, bigX, bigY) ;
				bigInt.swap(bigX, bigY) ;
			}

			bigA = *listIntIter ;
			bigB = 1 ;

			bigInt.fraction_add(bigA, bigB, bigX, bigY, bigX, bigY) ;

			// check
			bigD = ii ;

			bigA = bigInt.pow(bigX, 2) ;
			bigB = bigInt.pow(bigY, 2) ;
			bigB = bigD * bigB ;

			bigTemp = bigA - bigB ;

			if(bigTemp == 1)
				break ;
		}
		printf("%d -->> %s / %s\n", ii, bigX.c_str(), bigY.c_str()) ;

		if(bigX > bigMax)
		{
			bigMax = bigX ;
			maxii = ii ;
		}
	}

	printf("max : %d\n", maxii) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
