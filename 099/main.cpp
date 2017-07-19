#include <cstdio>
#include <sys/time.h>

#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std ;


int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	FILE* fp = fopen("base_exp.txt", "rt") ;

	char szBuf[1024] ;

	int a, b ;
	char* pBuf ;

	double logA ;
	double logMax = 0 ;

	int line = 0 ;

	while(1)
	{
		line++ ;
		fgets(szBuf, 1024, fp) ;

		if(feof(fp))
			break ;

		pBuf = strtok(szBuf, ",") ;
		a = atoi(pBuf) ;

		pBuf = strtok(NULL, ",") ;
		b = atoi(pBuf) ;

		logA = b * log10(a) ;

		if(logA > logMax)
		{
			logMax = logA ;
			printf("line : %d\n", line) ;
		}
	}



	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
