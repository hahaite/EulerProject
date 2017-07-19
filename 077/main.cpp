#include <cstdio>
#include <sys/time.h>

#include <cstring>
#include "../mymath/mymath.h"

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

	CPrime primeObj ;

        int max ;
        int flag = 0 ;
        int primeCount = 0 ;
        int index = 2 ;
        int* array ;

        while(1)
        {
                flag = 0 ;
                primeCount = 0 ;

                index++ ;
                array = new int[index] ;
                memset(array, 0x00, sizeof(int) * index) ;
                array[0] = 1 ;
                array[1] = 1 ;

                max = index ;

                while(1)
                {
                        flag = 0 ;
                        setSum(array, max) ;

                        for(int ii = 0; ii < max; ii++)
                        {
                                if(array[ii] == 0)
                                        break ;

                                if(!primeObj.isPrime(array[ii]))
                                {
                                        flag = 1 ;
                                        break ;
                                }
                        }

                        if(!flag)
                                primeCount++ ;

                        if(array[max-1] == 1)
                                break ;

                        increase(array,max) ;
                }

                delete[] array ;

                printf("%d - prime Count : %d\n", index, primeCount) ;

                if(primeCount > 5000)
                        break ;
        }

	printf("Result : %d\n", index) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
