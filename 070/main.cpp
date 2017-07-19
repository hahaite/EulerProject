#include <cstdio>
#include <sys/time.h>

#include "../mymath/mymath.h"

#include <set>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int eulerPhi ;
	int max = 0 ;
	double nof ;
	double min_nof = 99999999 ;
	int minIndex ;

	int temp1 ;
	int temp2 ;
	int digit1 ;
	int digit2 ;

	map<int, int> 		mapIndex ;
	map<int, int> 		mapEuler ;

	map<int, int>::iterator mapIter ;
	map<int, int>::iterator mapIter2 ;
	
	CDivisor divisor ;

	int flagCheck = 0 ;

	for(int ii = 3; ii <= 10000000; ii = ii + 2)
	{
		eulerPhi = divisor.eulerPhi(ii) ;

		mapIndex.clear() ;
		mapEuler.clear() ;

		temp1 = ii ;
		while(temp1)
		{
			temp2 = temp1 % 10 ;

			mapIter = mapIndex.find(temp2) ;
			if(mapIter == mapIndex.end())
				mapIndex.insert(make_pair(temp2, 1)) ;
			else
				mapIter->second++ ;
			temp1 /= 10 ;
		}

		temp1 = eulerPhi ;
		while(temp1)
		{
			temp2 = temp1 % 10 ;

			mapIter = mapEuler.find(temp2) ;
			if(mapIter == mapEuler.end())
				mapEuler.insert(make_pair(temp2, 1)) ;
			else
				mapIter->second++ ;
			temp1 /= 10 ;
		}

		if(mapIndex.size() != mapEuler.size())
			continue ;

		mapIter = mapIndex.begin() ;
		mapIter2 = mapEuler.begin() ;
		flagCheck = 0 ;

		for(; mapIter != mapIndex.end(); mapIter++)
		{
			if((mapIter->first != mapIter2->first) ||
				(mapIter->second != mapIter2->second))
			{
				flagCheck = 1 ;
				break ;
			}
			mapIter2++ ;
		}

		if(flagCheck)
			continue ;

		nof = (double)ii/eulerPhi ;

		if(nof < min_nof)
		{
			min_nof = nof ;
			minIndex = ii ;
			printf("[%d, %d] - %f\n", ii, eulerPhi, nof) ;
		}
	}

	printf("Result : %d\n", minIndex) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
