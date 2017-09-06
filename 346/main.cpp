#include <cstdio>
#include <sys/time.h>

#include <set>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	set<long long> 			setInt ;
	set<long long>::iterator 	setIntIter ;

	long long sum = 1 ;
	long long exp = 1 ;
	while(1)
	{
		exp *= 2 ;
		if(exp - 1 > 1000000000000)
			break ;

		setInt.insert(exp - 1) ;
	}
	setInt.erase(3) ;
	
	for(int ii = 3; ii < 1000000; ii++)
	{
//		if(ii % 100000 == 0)
//			printf("=============== %d\n", ii) ;
		sum = 1 ;
		exp = 1 ;
		while(1)
		{
			exp *= ii ;
			if(sum + exp > 1000000000000)
				break ;
			sum += exp ;

			if(exp > ii)
			{
				setInt.insert(sum) ;
//				printf("%d\n", sum) ;
			}
		}
	}

	sum = 0 ;
	setIntIter = setInt.begin() ;
	for(; setIntIter != setInt.end(); setIntIter++)
	{
		sum += *setIntIter ;
	}

	printf("Sum : %lld\n", sum) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
