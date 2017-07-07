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

	CBigInt bigA = 1 ;
	CBigInt bigB = 1 ;
	CBigInt bigRet ;

	list<string>	    listRet ;
	list<string>::iterator  listRetIter ;

	while(1)
	{
		bigA++ ;

		if(bigA == 101)
			break ;

		printf("strA : %s\n", bigA.c_str()) ;

		bigB = 1 ;
		while(1)
		{
			bigB++ ;

			if(bigB == "101")
				break ;

			bigRet = bigRet.pow(bigA, bigB) ;

			listRetIter = listRet.begin() ;
			for(; listRetIter != listRet.end(); listRetIter++)
			{
				if(bigRet.getString() == *listRetIter)
				{
					printf("find : %s\n", bigRet.c_str()) ;
					break ;
				}
			}

			if(listRetIter == listRet.end())
				listRet.push_back(bigRet.getString()) ;
		}
	}

	printf("ret : %d\n", listRet.size()) ;

	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
