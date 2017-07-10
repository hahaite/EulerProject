#include <cstdio>
#include <sys/time.h>

#include <list>
#include <set>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

        int temp = 0 ;
        int len ;
        int count ;

        list<int>               listPanDigit ;
        list<int>::iterator     listPanDigitIter ;

        set<int>                setPanDigit ;
        set<int>::iterator      setPanDigitIter ;

        for(int index = 2; index < 10000; index++)
        {
                if(index % 10 == 0)
                        continue ;

                count = 1 ;
                len = 0 ;
                setPanDigit.clear() ;
                listPanDigit.clear() ;
                while(1)
                {
                        temp = index * count ;
                        count++ ;

                        listPanDigit.push_back(temp) ;

                        while(temp)
                        {
                                setPanDigit.insert(temp % 10) ;
                                temp /= 10 ;
                                len++ ;
                        }

                        setPanDigitIter = setPanDigit.find(0) ;
                        if(setPanDigitIter != setPanDigit.end())
                                goto while_continue ;

                        if(len != setPanDigit.size())
                                goto while_continue ;

                        if(len > 9)
                                goto while_continue ;

                        if(len == 9 && setPanDigit.size() == 9)
                        {
                                printf("FIND : %d\n", index) ;

                                listPanDigitIter = listPanDigit.begin() ;

                                printf("\t\t Result : ") ;
                                for(; listPanDigitIter != listPanDigit.end(); listPanDigitIter++)
                                        printf("%d", *listPanDigitIter) ;
                                printf("\n") ;
                                break ;
                        }
                }

while_continue :
        continue ;
	}

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
