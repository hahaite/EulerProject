#include <cstdio>
#include <sys/time.h>

#include <set>
#include <list>

#include "./../mymath/mymath.h"

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

#if 1
        CPrime primeObj ;

        list<int>               listPrime ;
        list<int>::iterator     listPrimeIter ;
        list<int>::iterator     listPrimeIter2 ;

        set<int>                setPrime ;
        set<int>::iterator      setPrimeIter ;

        int count ;
        int width = 2;
        int maxWidth = 0 ;
        int sum ;
        int sizeMax ;
        int prime ;

        while(1)
        {
                prime = primeObj.getNextPrime() ;
                if(prime > 1000000)
                        break ;

                listPrime.push_back(prime) ;
        }

        listPrimeIter = listPrime.begin() ;
        for(;listPrimeIter != listPrime.end(); listPrimeIter++)
                setPrime.insert(*listPrimeIter) ;

        sizeMax = listPrime.size() ;

        while(1)
        {
                listPrimeIter = listPrime.begin() ;

                for(int ii = 0; ii < sizeMax - width; ii++)
                {
                        listPrimeIter2 = listPrimeIter ;

                        sum = 0 ;
                        for(int jj = 0; jj < width; jj++)
                        {
                                sum += *listPrimeIter2 ;
                                listPrimeIter2++ ;
                        }

                        if(ii == 0 && sum > 1000000)
                                goto while_break ;

                        setPrimeIter = setPrime.find(sum) ;
                        if(setPrimeIter != setPrime.end())
                        {
                                if(width > maxWidth)
                                {
                                        maxWidth = width ;
                                        printf("width : %d, sum : %d\n", width, sum) ;
                                        break ;
                                }
                        }
                        listPrimeIter++ ;
                }
                width++ ;

                continue ;
while_break :
                break ;
        }

#endif

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
