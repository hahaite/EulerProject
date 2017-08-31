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

	set<long long> 			setSqure ;
	set<long long>::iterator 	setSqureIter ;

	long long ii = 2 ;
	long long temp ;

	while(1)
	{
		temp = ii * ii ;
		ii++ ;
		if(temp > 1000000000)
			break ;
		setSqure.insert(temp) ;
	}
	printf("squre size : %d, ii :%d\n", setSqure.size(), ii) ;

	long long a, b, c ;

	long long len ;

	int count = 0 ;
	int max = 1 ;

	while(1)
	{
		max++ ;
		for(a = 1; a <= max; a++)
		{
			for(b = a; b <= max; b++)
			{
				c = max ;
				len = ((a + b) * (a + b)) + (c * c) ;

				setSqureIter = setSqure.find(len) ;

				if(setSqureIter != setSqure.end())
					count++ ;
			}
		}

		printf("%d - %d\n", max, count) ;

		if(count > 1000000)
			break ;
	}

	printf("Result : %d\n", max) ;

	
	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
