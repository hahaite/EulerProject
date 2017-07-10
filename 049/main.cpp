#include <cstdio>
#include <sys/time.h>

#include <set>

#include "./../mymath/mymath.h"

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	CPrime primeObj ;

	list<int>	       listPrime ;
	list<int>::iterator     listPrimeIter ;

	set<int>		setInt ;
	set<int>::iterator      setIntIter ;

	int temp ;
	int prime ;

	primeObj.setPrime(1000) ;
	while(1)
	{
		prime = primeObj.getNextPrime() ;

		if(prime > 9999)
			break ;

		listPrime.push_back(prime) ;
	}

	printf("prime Size : %d\n", listPrime.size()) ;

	list<int>::iterator     listIter1 ;
	list<int>::iterator     listIter2 ;
	list<int>::iterator     listIter3 ;

	int a, b, c ;
	int flagFind = 1 ;

	listIter1 = listPrime.begin() ;
	for(; listIter1 != listPrime.end(); listIter1++)
	{
		listIter2 = listIter1 ;
		listIter2++ ;
		for(; listIter2 != listPrime.end(); listIter2++)
		{
			listIter3 = listIter2 ;
			listIter3++ ;

			for(; listIter3 != listPrime.end(); listIter3++)
			{

				a = *listIter1 ;
				b = *listIter2 ;
				c = *listIter3 ;

				if((b - a) == (c - b))
				{
					setInt.clear() ;

					temp = a ;
					while(temp)
					{
						setInt.insert(temp % 10) ;
						temp /= 10 ;
					}


					temp = b ;
					flagFind = 1 ;
					while(temp)
					{
						a = temp % 10 ;

						setIntIter = setInt.find(a) ;
						if(setIntIter == setInt.end())
						{
							flagFind = 0 ;
							break ;
						}
						temp /= 10 ;
					}

					if(!flagFind)
						continue ;

					temp = c ;
					while(temp)
					{
						a = temp % 10 ;

						setIntIter = setInt.find(a) ;
						if(setIntIter == setInt.end())
						{
							flagFind = 0 ;
							break ;
						}
						temp /= 10 ;
					}


					if(!flagFind)
						continue ;

					a = setInt.size() ;

					setInt.clear() ;
					temp = b ;
					while(temp)
					{
						setInt.insert(temp % 10) ;
						temp /= 10 ;
					}
					b = setInt.size() ;

					setInt.clear() ;
					temp = c ;
					while(temp)
					{
						setInt.insert(temp % 10) ;
						temp /= 10 ;
					}
					c = setInt.size() ;


					if(a != b || a != c)
						continue ;

					printf("%d %d %d\n", *listIter1, *listIter2, *listIter3) ;

				}
			}
		}
	}


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
