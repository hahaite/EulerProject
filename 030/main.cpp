#include <cstdio>
#include <sys/time.h>
#include <cmath>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////


	int digitNum = 0 ;
	int digit[32] ;
	int temp ;
	int index = 0 ;
	int sum ;
	int ret = 0 ;

	for(int ii = 2; ii < 999999; ii++)
	{
		temp = ii ;
		index = 0 ;
		while(temp)
		{
			digit[index++] = temp % 10 ;
			temp /= 10 ;
		}

		sum = 0 ;
		for(int jj = 0; jj < index; jj++)
			sum += pow(digit[jj], 5) ;

		if(ii == sum)
			ret += ii ;
	}

	printf("ret : %d\n", ret) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
