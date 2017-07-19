#include <cstdio>
#include <sys/time.h>

#include <set>
#include <cstdlib>
#include "../bigInt/bigInt.h"

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

        set<int>                setInt ;
        set<int>::iterator      setIntIter ;

        CBigInt         bigA ;
        bigA = 1 ;

        FILE* fp = fopen("keylog.txt", "rt") ;

        char szBuf[32] ;

        while(1)
        {
                fgets(szBuf, 128, fp) ;

                if(feof(fp))
                        break ;

                setInt.insert(atoi(szBuf)) ;
        }

        printf("size : %d\n", setInt.size()) ;

        string* pStr ;
        string::iterator strIter ;
        int offset = 0 ;
        int flagFind ;

        while(1)
        {
                bigA++ ;
                pStr = bigA.getStrPtr() ;

                flagFind = 1;

                setIntIter = setInt.begin() ;
                for(; setIntIter != setInt.end(); setIntIter++)
                {
                        offset = 0 ;
                        sprintf(szBuf, "%d", *setIntIter) ;

                        strIter = pStr->begin() ;
                        for(; strIter != pStr->end(); strIter++)
                        {
                                if(*strIter == szBuf[offset])
                                        offset++ ;

                                if(offset == 3)
                                        break ;
                        }

                        if(strIter == pStr->end())
                        {
                                flagFind = 0 ;
                                break ;
                        }
                }

                if(flagFind)
                        break ;
        }

        printf("%s\n", bigA.c_str()) ;

        fclose(fp) ;



	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
