#include <cstdio>
#include <cstring>
#include <string>
#include <map>

#include <sys/time.h>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int sum = 0 ;

	for(int ii = 1; ii < 1000; ii++)
	{
		if(ii % 3 == 0 || ii % 5 == 0)
			sum += ii ;

	}

	printf("sum : %d\n", sum) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
