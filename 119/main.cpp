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

	long long temp ;

	for(int ii = 2; ii < 99; ii++)
	{
		temp = ii ;
		for(int exp = 2; exp < 99; exp++)
		{
			temp = temp * ii ;

			if(temp > 999999999999999)
				break ;

			setInt.insert(temp) ;
		}
	}

	long long sum ;
	int count = 0 ;

	setIntIter = setInt.begin() ;
	for(; setIntIter != setInt.end(); setIntIter++)
	{
		temp = *setIntIter ;
		sum = 0 ;
		while(temp)
		{
			sum += (temp % 10) ;
			temp /= 10 ;
		}

		if(sum == 1)
			continue ;

		temp = sum ;

		while(temp < *setIntIter)
		{
			temp *= sum ;
			if(temp == *setIntIter)
			{
				count++ ;
				printf("Find(%d) ; %lld, sum : %d\n", count, *setIntIter, sum) ;
				break ;
			}
		}

		if(count == 30)
			break ;
	}

	printf("Result : %lld\n", *setIntIter) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
