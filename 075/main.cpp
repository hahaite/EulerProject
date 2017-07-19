#include <cstdio>
#include <sys/time.h>

#include <set>
#include <algorithm>
#include "./../mymath/mymath.h"

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int a, b, c ;
	int temp ;

	CDivisor divisor ;

	set<pair<int, pair<int, int> > >		setTemp ;
	set<pair<int, pair<int, int> > >::iterator      setTempIter ;

	set<pair<int, pair<int, int> > >		setInt ;
	set<pair<int, pair<int, int> > >::iterator      setIntIter ;

	for(int ii = 1; ii < 1000; ii++)
	{
		printf("ii : %d\n", ii) ;
		for(int jj = 1; jj < ii; jj++)
		{
			if(!divisor.is_pairwise_disjoint_set(ii, jj))
				continue ;

			a = (ii*ii) - (jj*jj) ;
			b = 2*ii*jj ;
			c = (ii*ii) + (jj*jj) ;

			if(a + b + c > 1500000)
				break ;

			if(a > b)
				std::swap(a, b) ;

			setTemp.insert(make_pair(a, make_pair(b, c))) ;
		}
	}

	while(1)
	{
		setTempIter = setTemp.begin() ;

		a = setTempIter->first ;
		b = setTempIter->second.first ;
		c = setTempIter->second.second ;

		while(1)
		{
			setInt.insert(make_pair(a, make_pair(b, c))) ;

			a += setTempIter->first ;
			b += setTempIter->second.first ;
			c += setTempIter->second.second ;

			if(a + b + c > 1500000)
				break ;
		}

		setTemp.erase(setTempIter) ;

		if(setTemp.empty())
			break ;
	}

	map<int, int> 		mapInt ;
	map<int, int>::iterator mapIntIter ;
	int sum ;
	int count = 0 ;

	setIntIter = setInt.begin() ;
	for(; setIntIter != setInt.end(); setIntIter++)
	{
		sum = setIntIter->first + setIntIter->second.first + setIntIter->second.second ;

		mapIntIter = mapInt.find(sum) ;
		if(mapIntIter == mapInt.end())
			mapInt.insert(make_pair(sum, 1)) ;
		else
			mapIntIter->second++ ;
	}

	mapIntIter = mapInt.begin() ;
	for(; mapIntIter != mapInt.end(); mapIntIter++)
	{
		if(mapIntIter->second == 1)
			count++ ;
	}

	printf("Result : %d\n", count) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
