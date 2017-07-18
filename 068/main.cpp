#include <cstdio>
#include <sys/time.h>

#include <vector>
#include <algorithm>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	vector<int> 	vecInt ;

	int max = 10 ;

	for(int ii = 1; ii <= max; ii++)
		vecInt.push_back(ii) ;

	int a, b, c, d, e ;

	long long maxValue = 0 ;
	long long sum ;

	int digit[5][3] = {{0, 5, 6},
			   {1, 6, 7},
			   {2, 7, 8},
			   {3, 8, 9},
			   {4, 9, 5}} ;		
	int* pDigit ;
	int min ;
	int count = 0 ;

#if 1
	while(1)
	{
		a = vecInt[0] + vecInt[5] + vecInt[6] ;
		b = vecInt[1] + vecInt[6] + vecInt[7] ;
		c = vecInt[2] + vecInt[7] + vecInt[8] ;
		d = vecInt[3] + vecInt[8] + vecInt[9] ;
		e = vecInt[4] + vecInt[9] + vecInt[5] ;
	
		if((a == b) && (a == c) && (a == d) && (a == e))
		{
			// find minimum value.
			min = vecInt[0] < vecInt[1] ? vecInt[0] : vecInt[1] ;
			min = min < vecInt[2] ? min : vecInt[2] ;
			min = min < vecInt[3] ? min : vecInt[3] ;
			min = min < vecInt[4] ? min : vecInt[4] ;

			while(1)
			{
				if(vecInt[digit[0][0]] == min)
					break ;
				rotate(digit[0], digit[1], digit[5]) ;
			}

			sum = 0 ;
			pDigit = digit[0] ;
			count = 0 ;
			for(int ii = 0; ii < 15; ii++)
			{
				count = (vecInt[*pDigit] == 10) ? count + 1 : count ;
				sum *= (vecInt[*pDigit] == 10) ? 100 : 10 ;
				sum += vecInt[*pDigit] ;
				pDigit++ ;
			}

			if(count == 1 && sum > maxValue)
				maxValue = sum ;
		}

		if(!next_permutation(vecInt.begin(), vecInt.end()))
			break ;
	}
#endif

	printf("RET : %lld\n", maxValue) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
