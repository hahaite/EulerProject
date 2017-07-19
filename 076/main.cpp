#include <cstdio>
#include <sys/time.h>

#include <cstring>

using namespace std ;

void setSum(int* pVal, int max)
{
	int sum = 0 ;
	for(int ii = 0; ii < max; ii++)
	{
		if(pVal[ii] == 0)
			break ;

		sum += pVal[ii] ;
	}

	pVal[0] += (max - sum) ;

	return  ;
}

int getSum(int* pVal, int max)
{
	int sum = 0 ;
	for(int ii = 0; ii < max; ii++)
	{
		if(pVal[ii] == 0)
			break ;

		sum += pVal[ii] ;
	}
	return sum ;
}

void increase(int* pVal, int max)
{
	int pos = 1 ;
	int sum ;

	while(1)
	{
		pVal[pos]++ ;
		for(int ii = pos-1; ii >= 0; ii--)
			pVal[ii] = pVal[pos] ;

		sum = getSum(pVal, max) ;

		if(sum <= max)
			return ;
		else
			pos++ ;
	}
	return ;
}

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int max = 100 ;
	int array[max] ;

	memset(array, 0x00, sizeof(array)) ;
	array[0] = 1 ;
	array[1] = 1 ;

	int n = 0 ;
	while(1)
	{
		n++;
		setSum(array, max) ;

		if(array[max-1] == 1)
			break ;

		increase(array,max) ;
	}

	printf("ret : %d\n", n) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
