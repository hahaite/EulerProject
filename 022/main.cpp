#include <cstdio>
#include <list>
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

	list<string>	    listName ;
	list<string>::iterator  listNameIter ;

	FILE* fp = fopen("names.txt", "rt") ;
	char szBuf[32] ;
	string strName ;
	int flagGetChar = 0 ;

	while(1)
	{
		fread(szBuf, 1, 1, fp) ;

		if(feof(fp))
			break ;

		if('A' <= szBuf[0] && szBuf[0] <= 'Z')
		{
			flagGetChar = 1 ;
			strName += szBuf[0] ;
		}

		if(szBuf[0] == '\"' && flagGetChar == 1)
		{
			flagGetChar = 0 ;
			listName.push_back(strName) ;
			strName.clear() ;
		}
	}
	fclose(fp) ;

	listName.sort() ;

	int sum = 0 ;
	int count = 0 ;
	int strSum ;
	string::iterator	strIter ;

	listNameIter = listName.begin() ;
	for(; listNameIter != listName.end(); listNameIter++)
	{
		count++ ;
		strSum = 0 ;
		strIter = listNameIter->begin() ;
		for(; strIter !=  listNameIter->end(); strIter++)
			strSum += (*strIter - 'A' + 1) ;

		sum += (strSum * count) ;

//		printf("%d (%d) = %d - %s\n", count, strSum, count * strSum, listNameIter->c_str()) ;
	}

	printf("sum : %d\n", sum) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
