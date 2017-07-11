#include <cstdio>
#include <sys/time.h>

#include <cstring>
#include <list>

#include "./../mymath/mymath.h"

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	CPrime primeObj ;

	list<int> 		listInt ;
	list<int>::iterator 	listIntIter ;

	int temp ;
	char szOrg[128] ;
	char szText[128] ;

	int maxPrimeCount = 0 ;
	int primeCount ;

	// variable of finding zero.
	int flagOne ;
	int count ;

	int index = 10 ;
	while(index < 1000000)
	{
		index++ ;

		temp = index ;
		listInt.clear() ;
		count = 0 ;
		while(temp)
		{
			flagOne = temp % 10 ;
			listInt.push_front(flagOne) ;
			temp /= 10 ;

			if(flagOne == 0 )
				count++ ;
		}

		listIntIter = listInt.begin() ;

		if(count == 0 && *listIntIter != 1)
			continue ;

		count = 0 ;
		listIntIter = listInt.begin() ;
		for(; listIntIter != listInt.end(); listIntIter++)
		{
			szOrg[count] = *listIntIter + '0';
			count++ ;
		}
		szOrg[count] = '\0' ;

		primeCount = 0 ;

		flagOne = (szOrg[0] == '1') ? 1 : 0 ;

		for(int ii = 0; ii <= 9; ii++)
		{
			if(ii == 0 && flagOne == 1)
				continue ;

			memcpy(szText, szOrg, strlen(szOrg)+1) ;

			for(int jj = 0; jj < strlen(szText); jj++)
			{
				if((flagOne == 1) && (szText[jj] == '1'))
					szText[jj] = ii + '0' ;

				else if((flagOne == 0) && (szText[jj] == '0'))
					szText[jj] = ii + '0' ;
			}

			temp = atoi(szText) ;

			if(primeObj.isPrime(temp))
				primeCount++ ;
		}

		if(primeCount > maxPrimeCount)
		{
			printf("index : %d, Prime count : %d\n", index, primeCount) ;
			maxPrimeCount = primeCount ;
		}

		if(primeCount == 8)
			break ;

	}

	printf("Result : %d\n", index) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
