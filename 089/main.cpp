#include <cstdio>
#include <sys/time.h>

#include <cstring>
#include <string>

using namespace std ;

int checkRoman(char* szData)
{
	if(*szData == 'I' || *szData == 'V' || *szData == 'X' || *szData == 'L' ||
		*szData == 'C' || *szData == 'D' || *szData == 'M')
	{
		return 1 ;
	}

	return 0 ;
}


int getRomanValue(char* szData, int* flagSubstraction)
{
	if(!checkRoman(szData))
		return 0 ;

	*flagSubstraction = 1 ;

	if(!strncmp(szData, "IV", 2)) 	return 4 ;
	else if(!strncmp(szData, "IX", 2)) return 9 ;
	else if(!strncmp(szData, "XL", 2)) return 40 ;
	else if(!strncmp(szData, "XC", 2)) return 90 ;
	else if(!strncmp(szData, "CD", 2)) return 400 ;
	else if(!strncmp(szData, "cM", 2)) return 900 ;

	*flagSubstraction = 0 ;

	if(szData[0] == 'I') return 1 ;
	else if(szData[0] == 'V') return 5 ;
	else if(szData[0] == 'X') return 10 ;
	else if(szData[0] == 'L') return 50 ;
	else if(szData[0] == 'C') return 100 ;
	else if(szData[0] == 'D') return 500 ;
	else if(szData[0] == 'M') return 1000 ;

	return 0 ;
}

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	char szRoman[128] ;
	string sText ;

	FILE* fp = fopen("./roman.txt", "rt") ;

	int flagSub ;
	int flagPos ;

	int value, temp, len ;

	string strRoman[1000] ;
	int roman[1000] ;
	int ii = 0 ;

	int totalNumber = 0 ;

	if(!fp)
	{
		printf("fopen error\n") ;
		return 1 ;
	}

	while(1)
	{

		memset(szRoman, 0x00, sizeof(szRoman)) ;
		fgets(szRoman, sizeof(szRoman)-1, fp) ;

		len = strlen(szRoman) ;

		for(int jj = len - 1; jj >= 0; jj--)
		{
			if(checkRoman(&szRoman[jj]))
				break ;

			szRoman[jj] = '\0' ;
		}
		len = strlen(szRoman) ;

		totalNumber += len ;

		flagPos = 0 ;
		value = 0 ;

		while(1)
		{
			temp = getRomanValue(&szRoman[flagPos], &flagSub) ;

			if(temp == 0)
			{
//				printf("%s\t\t - %d - %d\n", szRoman, value, len) ;
				strRoman[ii] = szRoman ;
				roman[ii] = value ;
				ii++ ;
				break ;
			}

			value += temp ;
			flagPos = flagSub ? flagPos + 2 : flagPos + 1 ;
		}

		if(feof(fp))
			break ;
	}
	fclose(fp) ;

	int digitNumber[10] = {0, 1, 2, 3, 2, 1, 2, 3, 4, 2} ;
	int secondNumber = 0 ;

	for(ii = 0; ii < 1000; ii++)
	{
//		printf("%s\t\t - %d\n", strRoman[ii].c_str(), roman[ii]) ;

		temp = roman[ii] ;
		temp %= 1000 ;

		while(temp)
		{
			secondNumber += digitNumber[temp % 10] ;
			temp /= 10 ;
		}

		secondNumber += (int)(roman[ii] / 1000) ;
	}

	printf("Result : %d - %d = %d\n", totalNumber, secondNumber, totalNumber - secondNumber) ;
	
	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
