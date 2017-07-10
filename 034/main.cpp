#include <cstdio>
#include <sys/time.h>

#include <cstring>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int index = 2 ;

	int fac[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880} ;

	int digit[10] ;

	int sum ;
	int temp ;
	int ret ;

	while(1)
	{
		index++ ;
		temp = index ;

		memset(digit, 0x00, sizeof(digit)) ;

		for(int ii = 9; ii >= 0; ii--)
		{
			if(temp == 0)
				break ;

			digit[ii] = temp % 10 ;
			temp /= 10 ;
		}

		temp = 0 ;
		sum = 0 ;
		for(int ii = 0; ii < 10; ii++)
		{
			if(!temp && digit[ii] == 0)
				continue ;

			temp = 1 ;
			sum += fac[digit[ii]] ;
		}


		if(index == sum)
		{
			printf("sum : %d\n", index) ;
			ret += sum ;
		}

		if(index == 99999999)
			break ;
	}

	printf("Result : %d\n", ret) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
