#include <cstdio>
#include <sys/time.h>

#include <set>
#include <list>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	list<int>	       listDegree ;
	list<int>::iterator     listIter ;
	list<int>::iterator     listIter2 ;

	set<int>		setDegree ;
	set<int>::iterator      setIter ;

	int n ;
	for(int ii = 1; ii < 3000; ii++)
	{
		n = ii*((3*ii) - 1) / 2 ;

		listDegree.push_back(n) ;
		setDegree.insert(n) ;
	}
	printf("complete insertation.\n") ;

	listIter = listDegree.begin() ;

	int add, substract ;

	int count = 0 ;

	for(; listIter != listDegree.end(); listIter++)
	{
		count++ ;

		listIter2 = listIter ;
		for(; listIter2 != listDegree.end(); listIter2++)
		{
			if(listIter2 == listIter)
				continue ;

			add = *listIter2 + *listIter ;
			substract = *listIter2 - *listIter ;

			setIter = setDegree.find(add) ;
			if(setIter == setDegree.end())
				continue ;

			setIter = setDegree.find(substract) ;
			if(setIter == setDegree.end())
				continue ;

			printf("FIND : %d - %d = %d\n", *listIter, *listIter2, *listIter2 - *listIter) ;
		}
	}

	return 1 ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
