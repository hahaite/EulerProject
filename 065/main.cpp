#include <cstdio>
#include <sys/time.h>

#include <list>
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

	CBigInt nume1 ;
	CBigInt deno1 ;

	CBigInt nume2 ;
	CBigInt deno2 ;

	CBigInt temp1 ;
	CBigInt temp2 ;
	CBigInt temp3 ;

	list<int > 		listInt ;
	list<int >::iterator    listIntIter ;

	int index = 1 ;
	for(int ii = 1; ii < 100; ii++)
	{
		if(ii % 3 == 1 || ii % 3 == 0)
			listInt.push_front(1) ;
		else
			listInt.push_front(index++ * 2) ;
	}

	listIntIter = listInt.begin() ;

	nume1 = 1 ;
	deno1 = *listIntIter ;

	listIntIter++ ;
	for(; listIntIter != listInt.end(); listIntIter++)
	{
		nume2 = *listIntIter ;
		deno2 = 1 ;

		temp1 = deno1 * deno2 ;
		temp2 = nume1 * deno2 ;
		temp3 = deno1 * nume2 ;

		//reverse
		nume1 = temp1 ;
		deno1 = temp2 + temp3 ;
	}

	nume2 = 2 ;
	deno2 = 1 ;

	temp1 = deno1 * deno2 ;
	temp2 = nume1 * deno2 ;
	temp3 = deno1 * nume2 ;

	deno1 = temp1 ;
	nume1 = temp2 + temp3 ;

	printf("sum : %s / %s\n", nume1.c_str(), deno1.c_str()) ;

	string strResult = nume1.getString() ;

	string::iterator strIter ;
	strIter = strResult.begin() ;

	int sum = 0 ;
	for(; strIter != strResult.end(); strIter++)
	{
		sum += (*strIter - '0') ;
	}

	printf("result : %d\n", sum) ;




	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
