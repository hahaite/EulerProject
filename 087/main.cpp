#include <cstdio>
#include <sys/time.h>

#include <list>
#include <set>
#include "./../mymath/mymath.h"

using namespace std ;

int find2(int val)
{
	static int n = 1 ;

	while(1)
	{
		n++ ;
		if(n*n > val)
			break ;
	}
	n-- ;
	return n ;
}

int find3(int val)
{
	static int n = 1 ;
	while(1)
	{
		n++ ;
		if(n*n*n > val)
			break ;
	}
	n-- ;

	return n ;
}

int find4(int val)
{
	static int n = 1 ;

	while(1)
	{
		n++ ;
		if(n*n*n*n > val)
			break ;
	}
	n-- ;

	return n ;
}

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	CPrime primeObj ;

	list<int>	       listPrime2 ;
	list<int>	       listPrime3 ;
	list<int>	       listPrime4 ;

	list<int>::iterator     listIter2 ;
	list<int>::iterator     listIter3 ;
	list<int>::iterator     listIter4 ;

	set<int>		setInt ;

	int prime ;

	primeObj.resetPrime() ;
	while(1)
	{
		prime = primeObj.getNextPrime() ;

		if(prime > 7071)
			break ;

		listPrime2.push_back(prime) ;
	}

	primeObj.resetPrime() ;
	while(1)
	{
		prime = primeObj.getNextPrime() ;

		if(prime > 368)
			break ;

		listPrime3.push_back(prime) ;
	}

	primeObj.resetPrime() ;
	while(1)
	{
		prime = primeObj.getNextPrime() ;

		if(prime > 85)
			break ;

		listPrime4.push_back(prime) ;
	}

	int a, b, c ;
	int aa, bb, cc ;

	listIter2 = listPrime2.begin() ;
	for(; listIter2 != listPrime2.end(); listIter2++)
	{
		a = *listIter2 ;
		aa = a * a ;

		listIter3 = listPrime3.begin() ;
		for(; listIter3 != listPrime3.end(); listIter3++)
		{

			b = *listIter3 ;
			bb = b*b*b ;

			listIter4 = listPrime4.begin() ;
			for(; listIter4 != listPrime4.end(); listIter4++)
			{
				c = *listIter4 ;
				cc = c*c*c*c ;

				if(aa + bb + cc < 50000000)
					setInt.insert(aa+bb+cc) ;
			}
		}
	}

	printf("size : %d\n", setInt.size()) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
