#include <cstdio>
#include <sys/time.h>

#include <set>
#include <string>
#include <cstring>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	set<int>		setSum ;
	set<int>::iterator      setSumIter ;

	for(int ii = 1; ii < 50; ii++)
		setSum.insert(ii * (ii + 1) / 2) ;

	FILE* fp = fopen("words.txt", "rt") ;
	if(!fp)
		return 0 ;

	char szText[32000] ;

	fgets(szText, sizeof(szText), fp) ;

	char* pa ;
	string strA ;
	string::iterator strIter ;
	int sum = 0 ;
	int count = 0 ;

	pa = strtok(szText, ",") ;

	while(1)
	{
		strA = pa ;
		strIter = strA.begin() ;
		strA.erase(strIter) ;

		strIter = strA.end() ;
		strIter-- ;
		strA.erase(strIter) ;

		sum = 0 ;
		strIter = strA.begin() ;
		for(; strIter != strA.end(); strIter++)
			sum += *strIter - 'A' + 1 ;

		setSumIter = setSum.find(sum) ;

		if(strA == "SKY")
			printf("sum : %d\n", sum) ;

		if(setSumIter != setSum.end())
			count++ ;

		pa = strtok(NULL, ",") ;

		if(pa == NULL)
			break ;
	}
	fclose(fp) ;
	printf("Result : %d\n", count) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
