#include <cstdio>
#include <sys/time.h>

#include <algorithm>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int permu[10] ;

	for(int ii = 0; ii < 10; ii++)
		permu[ii] = ii ;

	int count = 1 ;

	while(1)
	{
		next_permutation(permu, &permu[10]) ;
		count++ ;

		if(count == 1000000)
			break ;
	}


	for(int ii = 0; ii < 10; ii++)
		printf("%d ", permu[ii]) ;
	printf("\n") ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
