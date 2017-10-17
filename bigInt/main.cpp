#include <cstdio>
#include <string>
#include <cstdlib>

#if __linux__
#include <sys/time.h>
#endif

#include "./bigInt.h"

using namespace std ;

int main()
{
#if __linux__
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
#endif
	/////////////////////////////////////////////////////////////////////

	CBigInt bigA ;
	CBigInt bigB ;
	CBigInt bigC ;

	int a, b, ret ;

#if 0
	string 		szData ;
	string::iterator strIter ;
	bigA = "1234567" ;

	szData = bigA.getBinary() ;
	printf("binary : %s\n", szData.c_str()) ;
#endif

#if 0
	bigA = 17 ;
	bigB = 5 ;

	bigC = bigA.gcd(bigA, bigB) ;
	
	printf("gcd : %s\n", bigC.c_str()) ;

#endif


#if 0 	// increase ++, --
	bigA = 3 ;
	bigA++ ;
	printf("increase ++ = %s\n", bigA.c_str()) ;

	bigA = 3 ;
	++bigA ;
	printf("increase ++ = %s\n", bigA.c_str()) ;

	bigA = 3 ;
	bigA-- ;
	printf("increase -- = %s\n", bigA.c_str()) ;

	bigA = 3 ;
	--bigA ;
	printf("increase -- = %s\n", bigA.c_str()) ;
#endif

#if 0 	// Compare Test ==
	bigA = "-123" ;
	bigB = "1234" ;
	ret = (bigA == bigB) ;
	printf("compare == : %d\n", ret) ;

	bigA = "123" ;
	ret = (bigA == 123) ;
	printf("compare == : %d\n", ret) ;

	bigB = "123" ;
	ret = (123 == bigB) ;
	printf("compare == : %d\n", ret) ;

	bigA = "-123" ;
	ret = (bigA == -123) ;
	printf("compare == : %d\n", ret) ;

	bigA = -123 ;
	ret = (bigA == -123) ;
	printf("compare == : %d\n", ret) ;
#endif



#if 0 	// Compare Test >, >==
	bigA = "-3" ;
	bigB = "-5" ;
	ret = (bigA > bigB) ;
	printf("compare1 [ %s > %s ] : %d\n", bigA.c_str(), bigB.c_str(), ret) ;

	bigA = "-5" ;
	b = -3 ;
	ret = bigA > b ;
	printf("compare2 [ %s > %d ] : %d\n", bigA.c_str(), b, ret) ;

	a = 3 ;
	bigB = "5" ;
	ret = a > bigB ;
	printf("compare2 [ %d > %s ] : %d\n", a, bigB.c_str(), ret) ;

	bigA = "3" ;
	bigB = "3" ;
	ret = (bigA >= bigB) ;
	printf("compare1 [ %s >= %s ] : %d\n", bigA.c_str(), bigB.c_str(), ret) ;

	bigA = "-5" ;
	b = -3 ;
	ret = bigA >= b ;
	printf("compare2 [ %s >= %d ] : %d\n", bigA.c_str(), b, ret) ;

	a = 3 ;
	bigB = "5" ;
	ret = a >= bigB ;
	printf("compare2 [ %d >= %s ] : %d\n", a, bigB.c_str(), ret) ;


#endif


#if 0 	// Compare Test <, <=
	bigA = "3" ;
	bigB = "5" ;
	ret = (bigA < bigB) ;
	printf("compare1 [ %s < %s ] : %d\n", bigA.c_str(), bigB.c_str(), ret) ;

	bigA = "-3" ;
	b = -5 ;
	ret = (bigA < b) ;
	printf("compare1 [ %s < %d ] : %d\n", bigA.c_str(), b, ret) ;

	a = 5 ;
	bigB = "-3" ;
	ret = (a < bigB ) ;
	printf("compare1 [ %d < %s ] : %d\n", a, bigB.c_str(), ret) ;


	bigA = "-3" ;
	bigB = "-5" ;
	ret = (bigA <= bigB) ;
	printf("compare1 [ %s <= %s ] : %d\n", bigA.c_str(), bigB.c_str(), ret) ;

	bigA = "-3" ;
	b = -5 ;
	ret = (bigA <= b) ;
	printf("compare1 [ %s <= %d ] : %d\n", bigA.c_str(), b, ret) ;

	a = 5 ;
	bigB = "-3" ;
	ret = (a <= bigB ) ;
	printf("compare1 [ %d <= %s ] : %d\n", a, bigB.c_str(), ret) ;

#endif


#if 0   // add Test

	bigA = "3733985" ;
	bigB = "393848" ;
	bigC = bigA + bigB ;
	printf("result1 : %s\n", bigC.c_str()) ;

//	bigC = bigA + 393848 ;
//	printf("result2 : %s\n", bigC.c_str()) ;
#endif


#if 0   // substraction

	bigA = "-3733985" ;
	bigB = "393848" ;
	bigC = bigA - bigB ;
	printf("substraction [ %s - %s ] = %s\n", bigA.c_str(), bigB.c_str(), bigC.c_str()) ;

	bigA = "3733985" ;
	b = 393848 ;
	bigC = bigA - b ;
	printf("substraction [ %s - %d ] = %s\n", bigA.c_str(), b, bigC.c_str()) ;

	a = 3733985 ;
	bigB = "393848" ;
	bigC = a - bigB ;
	printf("substraction [ %d - %s ] = %s\n", a, bigB.c_str(), bigC.c_str()) ;

#endif



#if 0   // divide
	bigA = "44" ;
	bigB = "371" ;
	bigC = bigA / bigB ;

	string strTemp ;
	strTemp = bigC.getRemainder() ;
	printf("divide [ %s / %s ] = %s, remainder : %s\n", 
		bigA.c_str(), bigB.c_str(), bigC.c_str(), strTemp.c_str()) ;

#endif

#if 1 	// combinations test
	bigA = "23" ;
	bigB = "10" ;

//	bigC = bigC.combinations(bigA, bigB) ;
//	printf("combination1 %s C %s = %s\n", bigA.c_str(), bigB.c_str(), bigC.c_str()) ;

//	for(int ii = 2; ii <= 20; ii++)
	{
		bigC = bigC.combinations(28, 10) ;
		printf("combination, %d = %s\n", 1, bigC.c_str()) ;
	}

#endif

#if 0 	// reverse value - "1234" -> "4321"
	bigA = "3333" ;
	bigC = bigC.reverse(bigA) ;
	printf("result : %s\n", bigC.c_str()) ;
#endif

#if 0 	// check palindrome - "1234321"
	bigA = "7" ;
	ret = bigA.palindrome(bigA) ;
	printf("result : %d\n", ret) ;
#endif


#if 0 	// check sort
	bigA = "654321" ;
	bigC = bigA.sort(bigA) ;
	printf("result : %s\n", bigC.c_str()) ;
#endif

#if 0 	// factorial test
//	bigA = 0 ;

	bigC = bigC.factorial(63) ;
	printf("63! = %s\n", bigC.c_str()) ;
#endif

#if 0 	// pow test
	bigA = 3 ;
	bigB = 10 ;

	bigC = bigC.pow(3, bigB ) ;
	printf("result : %s\n", bigC.c_str()) ;
#endif

#if 0
	strA = "42" ;
	strB = "17" ;
	
	strResult = bigInt.divide(&strA, &strB) ;
	printf("strResult : %s\n", strResult.c_str()) ;	
	return 1 ;
#endif

#if 0
	strA = "21" ;
	strB = "3" ;
	
	strResult = bigInt.remainder(&strA, &strB) ;
	printf("strResult : %s\n", strResult.c_str()) ;	

	return 1 ;
#endif

#if 0
	char szText[128] ;

	for(int ii = -1000; ii <= 1000; ii++)
	{
		bigA = ii ;

		printf("%d\n", ii) ;
		for(int jj = -1000; jj <= 1000; jj++)
		{
			bigB = jj ;

//			bigC = ii + bigB ;
//			ret = ii + jj ;

//			bigC = bigA - bigB ;
//			ret = ii - jj ;

//			bigC = ii * bigB;
//			ret = ii * jj ;

			if(ii <= 0 || jj <= 0)
				continue ;

			bigC = bigA / bigB ;
			ret = ii / jj ;

//			strResult = bigInt.remainder(&strA, &strB) ;
//			ret = ii % jj ;


			if(ret != atoi(bigC.c_str()))
			{
				printf("error [%d.%d] \n", ii, jj) ;
				printf("str Sum Result  : %s\n", bigC.c_str()) ;
				printf("Correct value is %d\n", ret) ;
				return 1 ;
			}
		}
	}
#endif

	/////////////////////////////////////////////////////////////////////
#if __linux__
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%lu.%06lu]\n", tWorking.tv_sec, tWorking.tv_usec) ;
#endif
	return 1 ;
}
