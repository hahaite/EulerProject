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

	long long min = sqrt(1020304050607080900L) ;
	long long max = sqrt(1929394959697989990L) ;
	long long check ;

	char szBuf[32] ;

	printf("min : %lld\n", min) ;
	printf("max : %lld\n", max) ;

	for(long long ii = min; ii <= max; ii += 10)
	{
		check = ii * ii ;	
		sprintf(szBuf, "%lld", check) ;
		

		if(szBuf[0] == '1' && szBuf[2] == '2' && szBuf[4] == '3'
			&& szBuf[6] == '4' && szBuf[8] == '5' && szBuf[10] == '6'
			&& szBuf[12] == '7' && szBuf[14] == '8' && szBuf[16] == '9'
			&& szBuf[18] == '0')
		{
			printf("Result : %lld\n", ii) ;
			break ;

		}
	}

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
