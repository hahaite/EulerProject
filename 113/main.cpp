#include <cstdio>
#include <sys/time.h>

#include <map>

using namespace std ;


int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	// 아래 코드를 이용해 증가하는 경우와 감소하는 경우의 맨 앞자리(큰자리)의 갯수를
	// 비교하였다.
	//
	// 증가하는 경우 아래 갯수만큼 얻을 수 있었다.
	//
	//	 1  2  3  4   5   6   7   8   9
	// ~ 10^2  2  3  4  5   6   7   8   9  10
	// ~ 10^3  3  6 10 15  21  28  36  45  55
	// ~ 10^4  4 10 20 35  56  84 120 165 220
	// ~ 10^5  5 15 35 70 126 210 330 495 715
	//
	// 감소하는 경우 아래 규칙을 얻을 수 있었다.
	//
	//	8  7  6  5   4   3   2   1
	// ~10^2  1  2  3  4   5   6   7   8
	// ~10^3  2  5  9 14  20  27  35  44
	// ~10^4  3  9 19 34  55  83 119 164
	// ~10^5  4 14 34 69 125 209 329 494
	//
	// 아래 주석처리 된 코드는 증가 또는 감소를 정해진 숫자까지 구하는 코드이며
	// 아래 #if 1<->0 으로 증가와 감소를 선택할 수 있다.

#if 0
	long long next;
	long long cur;

	int flagInc, flagDec ;
	int temp ;
	int notBouncy = 0 ;

	int first ;

//      while(1)
	for(int ii = 10; ii < 10000; ii++)
	{
		flagInc = 0 ;
		flagDec = 0 ;

		temp = ii ;

		while(temp)
		{
			cur = temp % 10 ;
			temp /= 10 ;
			next = temp % 10 ;

			if(!flagDec && (next > cur))
				flagInc = 1 ;

			if(!flagInc && (cur > next))
				flagDec = 1 ;

			if(flagDec && flagInc)
				break ;

			if(temp < 10)
				break ;
		}

		if(!flagDec && !flagInc)
			flagInc = 1 ;

		if(flagDec && flagInc)
			continue ;

#if 1
		if(flagDec && !flagInc)
			continue ;
#else
		if(!flagDec && flagInc)
			continue ;
#endif

		notBouncy++ ;
		printf("%d - %d\n", ii, notBouncy) ;
	}

	printf("bouncy Count : %d\n", notBouncy) ;
#endif

	long long array[100][9] ;
	long long notBouncy = 0 ;

	for(int ii = 0; ii < 9; ii++)
		array[0][ii] = ii + 2 ;


	for(int row = 1; row < 100; row++)
	{
		for(int col= 0; col < 9; col++)
		{
			if(col == 0)
			{
				array[row][col] = row + 2 ;
				continue ;
			}

			array[row][col] = array[row][col-1] + array[row-1][col] ;
		}
	}

	int const MY_ROW = 100 ;


	for(int row = 0; row < MY_ROW-1; row++)
	{
		for(int col= 0; col < 9; col++)
			notBouncy += array[row][col] ;
	}

	for(int row = 0; row < MY_ROW-1; row++)
	{
		for(int col= 0; col < 8; col++)
			notBouncy += (array[row][col]-1) ;
	}

	notBouncy += 9 ;

	printf("not Bouncy : %lld\n", notBouncy) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
