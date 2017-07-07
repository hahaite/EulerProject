#include <cstdio>
#include <sys/time.h>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int max[12] = {31,28,31,30,31,30, 31,31,30,31,30,31} ;

	int year = 1900 ;
	int month = 1 ;
	int day = 1 ;

	int weekday = 1 ;

	int count = 0;

	while(1)
	{
		day++ ;
		weekday++ ;

		if(weekday == 7)
			weekday = 0 ;

		if(day > max[month-1])
		{
			day = 1 ;
			month++ ;
			printf("\n") ;
		}

		if(month > 12)
		{
			month = 1 ;
			year++ ;

			max[1] = 28 ;

			if(year % 4 == 0)
				max[1] = 29 ;

			if(year % 100 == 0)
				max[1] = 28 ;

			if(year % 400 == 0)
				max[1] = 29 ;
		}

		if(year > 1900 && day == 1 && weekday == 0)
			count++ ;

		printf("%d.%2d.%2d - %d\n", year, month, day, weekday) ;


		if(year == 2000 && month == 12 && day == 31)
			break ;
	}

	printf("count : %d\n", count) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
