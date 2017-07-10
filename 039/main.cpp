#include <cstdio>
#include <sys/time.h>

#include <map>

using namespace std ;


int check_c(int c)
{

	int count = 1 ;

	while(1)
	{
		if(c == (count * count))
			return count ;

		if(c < (count * count))
			break ;

		count++ ;
	}

	return 0 ;
}

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int c ;
	int sum ;

	map<int, int>		   mapSum ;
	map<int, int>::iterator	 mapSumIter ;

	for(int a = 1; a <= 1000; a++)
	{
		for(int b = 1; b <= 1000; b++)
		{
			if(a + b > 1000)
				continue ;

			c = (a * a) + (b * b) ;
			c = check_c(c) ;

			if(c == 0)
				continue ;

			sum = a + b + c ;
			if(sum <= 1000)
			{
				mapSumIter = mapSum.find(sum) ;
				if(mapSumIter == mapSum.end())
					mapSum.insert(make_pair(sum, 1)) ;
				else
					mapSumIter->second++ ;
			}
		}
	}

	int max = 0 ;
	int ret ;
	mapSumIter = mapSum.begin() ;
	for(; mapSumIter != mapSum.end(); mapSumIter++)
	{
		if(mapSumIter->second > max)
		{
			ret = mapSumIter->first ;
			max = mapSumIter->second ;
			printf("%d - %d\n", mapSumIter->first, mapSumIter->second) ;
		}
	}

	printf("Result : %d\n", ret ) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
