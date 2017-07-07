#include <cstdio>
#include <string>
#include <sys/time.h>

#include "./../bigInt/bigInt.h"

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	CBigInt bigInt ;
	bigInt = 1 ;

	for(int ii = 1; ii <= 1000; ii++)
		bigInt = bigInt + bigInt ;

	printf("%s\n", bigInt.c_str()) ;

	string strSum ;
	string::iterator strIter ;

	int sum = 0 ;
	strSum = bigInt.getString() ;
	strIter = strSum.begin() ;

	for(; strIter != strSum.end(); strIter++)
		sum += (*strIter - '0') ;

        printf("sum : %d\n", sum) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
