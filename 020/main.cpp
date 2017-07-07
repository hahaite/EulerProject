#include <cstdio>
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

	bigInt = bigInt.factorial(100) ;

	string::iterator strIter ;

	int sum = 0 ;
	string st = bigInt.getString() ;
	strIter = st.begin() ;

	for(; strIter != st.end(); strIter++)
		sum += (*strIter - '0') ;

	printf("sum : %d\n", sum) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
