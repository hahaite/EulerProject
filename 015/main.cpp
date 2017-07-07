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

	// 중심이항계수 (Central binomial coefficient)
	// n-th 값 : (2n!) / (n!)^2

	CBigInt bigA ;
	CBigInt bigB ;

	bigA = bigA.factorial(40) ;
	bigB = bigA.factorial(20) ;
	bigB = bigB * bigB ;

	bigA = bigA / bigB ;
	printf("strRet : %s\n", bigA.c_str()) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
