#include <cstdio>
#include <sys/time.h>

#include <map>

#include "./../mymath/mymath.h"

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	CDivisor divisor ;

	map<long long, int> 		mapInt ;
	map<long long, int>::iterator	mapIter ;

	int a, b, c, d ;
	int ii = 1 ;
	int mapSize ;
	while(1)
	{
//		if(ii % 10000 == 9999)
//			printf("ii : %d\n", ii) ;

		ii++ ;

		mapInt.clear() ;
		divisor.getIntegerFactorization(ii, &mapInt) ;

		mapSize = mapInt.size() ;

		if(ii % 4 == 2)
			a = mapSize ;
		else if(ii % 4 == 3)
			b = mapSize ;
		else if(ii % 4 == 0)
			c = mapSize ;
		else
			d = mapSize ;

		if(a == 4 && b == 4 && c == 4 && d == 4)
		{
			printf("Result : %d\n", ii - 3) ;
			break ;
		}
	}


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
