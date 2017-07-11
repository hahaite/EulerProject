#include <cstdio>
#include <sys/time.h>

#include <list>
#include <cstring>
#include <cstdlib>

//#include "./../mymath/mymath.h"

using namespace std ;

int checkChar(char a)
{
        if(a == '`')
                return 0 ;

        if(a == '\r')
                return 1 ;
        if(a == '\n')
                return 1 ;

#if 1
        if( 25 <= a && a <= 126)
                return 1 ;
#endif

        return 0 ;
}

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

        list<char>              listCipher ;
        list<char>              listPlain ;

        list<char>::iterator    listCipherIter ;
        list<char>::iterator    listIter ;

        char szText[1024 * 10] ;
        char szTok[32] ;

        char* pTok ;
        char cipher ;

        FILE* fp = fopen("cipher1.txt", "rt") ;
        fgets(szText, sizeof(szText), fp) ;
        fclose(fp) ;

        pTok = strtok(szText, ",") ;
        listCipher.push_back(atoi(pTok)) ;

        int temp ;

        int max = 0 ;

        int c1, c2, c3 ;
        int p1, p2, p3 ;
        int ret ;

        int flag = 1 ;
        int count = 0 ;

        int sum = 0 ;

        while(1)
        {
                pTok = strtok(NULL, ",") ;
                if(pTok == NULL)
                        break ;

                temp = atoi(pTok) ;

                if(temp > max)
                {
                        max = temp ;
//                      printf("max : %d\n", max) ;
                }

                listCipher.push_back(temp) ;
        }


        listIter = listCipher.begin() ;
        for(; listIter != listCipher.end(); listIter++)
        {
                count++ ;

                if(count % 3 == 1)
                        listPlain.push_back(*listIter ^ 'g') ;
                if(count % 3 == 2)
                        listPlain.push_back(*listIter ^ 'o') ;
                if(count % 3 == 0)
                        listPlain.push_back(*listIter ^ 'd') ;
        }


        listIter = listPlain.begin() ;

        for(; listIter != listPlain.end(); listIter++)
        {
                printf("%c", *listIter) ;
                sum += *listIter ;
        }
        printf("\n") ;
        printf("SUM : %d\n", sum) ;

        printf("max : %d\n", max) ;
        printf("RESULT : %d\n", sum) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
