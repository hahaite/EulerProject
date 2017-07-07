#include <cstdio>
#include <list>
#include <set>
#include <sys/time.h>

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

	list<int> 		listDivisor ;
	list<int>::iterator 	listDivisorIter ;

	list<int> 		listInt ;
	list<int>::iterator	listIter1 ;
	list<int>::iterator	listIter2 ;

	set<int> 		setInt ;
	set<int>::iterator 	setIntIter ;

	int sum = 0 ;
	int ret = 0 ;

	for(int ii = 2; ii <= 28122; ii++)
	{
		divisor.getDivisor(ii, &listDivisor) ;

		listDivisor.pop_back() ;
		listDivisorIter = listDivisor.begin() ;

		sum = 0 ;
		for(; listDivisorIter != listDivisor.end(); listDivisorIter++)
			sum += *listDivisorIter ;


		if(sum > ii && sum < 28123)
			listInt.push_back(ii) ;
	}

	listIter1 = listInt.begin() ;

	for(; listIter1 != listInt.end(); listIter1++)
	{
		listIter2 = listIter1 ;
		for(; listIter2 != listInt.end(); listIter2++)
		{
			if(*listIter1 + *listIter2 < 28123)
				setInt.insert(*listIter1 + *listIter2) ;
		}
	}

	ret = 0 ;
	for(int ii = 1; ii < 28123; ii++)
	{
		setIntIter = setInt.find(ii) ;
		if(setIntIter == setInt.end())
			ret += ii ;
	}

	printf("Result : %d\n", ret) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
