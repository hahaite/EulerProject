#include <cstdio>
#include <string>
#include <sys/time.h>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	// one two three four five six seven eight nine ten
	// eleven twelve thirteen fourteen fifteen sixteen seventeen eighteen nineteen
	// twenty
	// thrity
	// forty
	// fifty
	// sixty
	// seventy
	// eighty
	// ninety

	int digit10 ;
	int digit100 ;

	string strNum ;
	string szLess20[100] ;

	int less20[21] = {0, 3, 3, 5, 4, 4,
			3, 5, 5, 4, 3,
			6, 6, 8, 8, 7,
			7, 9, 8, 8 } ;

	int more20[10] = {0, 0, 6, 6, 5,
			5, 5, 7, 6, 6} ;

	int total = 0 ;
	for(int ii = 1; ii <= 999; ii++)
	{
		digit10 = ii % 100 ;
		digit100 = ii / 100 ;

		if(digit10 < 20)
		{
			total += less20[digit10] ;
		}
		else if(digit10 >= 20)
		{
			total += more20[digit10 / 10] ;
			total += less20[digit10 % 10] ;

			if(digit10 % 10 != 0)
				strNum =  strNum + " " + szLess20[digit10 % 10];
		}

		if(digit100 > 0)
		{
			total += less20[digit100] ;

			if(digit10 == 0)
				total += 7 ; // hundred
			else
				total += 10 ; // hundred and
		}
	}

	// 1000 : one thousand - 11
	total += 11 ;
	printf("total : %d\n", total) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
