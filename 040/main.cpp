#include <cstdio>
#include <sys/time.h>

#include <list>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	list<int>	       listTotal ;
	list<int>	       listDigit ;
	list<int>::iterator     listIter ;

	int count = 0 ;
	int index = 0 ;
	int temp = 0 ;

	while(1)
	{
		index++ ;

		temp = index ;
		listDigit.clear() ;

		while(temp)
		{
			listDigit.push_front(temp % 10) ;
			temp /= 10 ;
			count++ ;
		}

		listIter = listTotal.end() ;
		listTotal.splice(listIter, listDigit) ;

		if(count > 1000000)
			break ;
	}

	count = 0 ;
	int ret = 1 ;
	listIter = listTotal.begin() ;
	for(; listIter != listTotal.end(); listIter++)
	{
		count++ ;

		if(count == 1)
			ret *= *listIter ;
		else if (count == 10)
			ret *= *listIter ;
		else if (count == 100)
			ret *= *listIter ;
		else if (count == 1000)
			ret *= *listIter ;
		else if (count == 10000)
			ret *= *listIter ;
		else if (count == 100000)
			ret *= *listIter ;
		else if (count == 1000000)
			ret *= *listIter ;
	}

	printf("ret : %d\n", ret) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
