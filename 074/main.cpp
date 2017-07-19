#include <cstdio>
#include <sys/time.h>

#include <set>

using namespace std ;

int factorial(int n)
{
	int ret = 1 ;
	for(int ii = 2; ii <= n; ii++)
		ret *= ii ;

	return ret ;
}


int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int temp ;
	int facSum = 0 ;
	int count = 0 ;
	int ret = 0 ;

	set<int>		setInt ;
	set<int>::iterator      setIntIter ;

	for(int ii = 1; ii <= 1000000; ii++)
	{

		if(ii % 10000 == 0)
			printf("ii : %d\n", ii) ;

		temp = ii ;

		count = 0 ;
		facSum = 0 ;
		setInt.clear() ;
		while(1)
		{
			setInt.insert(temp) ;

			while(temp)
			{
				facSum += factorial(temp % 10) ;
				temp /= 10 ;
			}

			setIntIter = setInt.find(facSum) ;
			count++ ;

			if(setIntIter != setInt.end())
			{
				if(count == 60)
					ret++ ;
				break ;
			}


			temp = facSum ;
			facSum = 0 ;
		}
	}

	printf("ret : %d\n", ret) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
