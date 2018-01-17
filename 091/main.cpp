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

	CInteger integer ;

	int x1, y1, x2, y2 ;
	int a, b, c ;

	multiset<int> 			setInt ;
	multiset<int>::iterator 	setIntIter ;

	int gcd ;
	int count = 0 ;

	const int WIDTH = 50 ;

	for(int r1 = 0; r1 <= WIDTH; r1++)
	{
		for(int c1 = 0; c1 <= WIDTH; c1++)
		{
			if(r1 == 0 && c1 == 0)
				continue ;

			gcd = integer.GCD(r1, c1) ;

			x1 = c1 / gcd ;
			y1 = r1 / gcd ;

			for(int r2 = 0; r2 <= WIDTH; r2++)
			{
				for(int c2 = 0; c2 <= WIDTH; c2++)
				{
					if(r2 == 0 && c2 == 0)
						continue ;

					gcd = integer.GCD(r2, c2) ;

					x2 = c2 / gcd ;
					y2 = r2 / gcd ;

					if(x1 == x2 && y1 == y2)
						continue ;

					if((double)r1/c1 <= (double)r2/c2)
						continue ;
					
					setInt.clear() ;
					setInt.insert((c1*c1) + (r1*r1)) ;	
					setInt.insert((c2*c2) + (r2*r2)) ;	
					setInt.insert((c1-c2)*(c1-c2) + (r1-r2)*(r1-r2)) ;	

					setIntIter = setInt.begin() ;
					a = *setIntIter ;
					setIntIter++ ;
					b = *setIntIter ;
					setIntIter++ ;
					c = *setIntIter ;
					
					if( a + b == c)
						count++ ;			
				}
			}
		}
	}

	printf("Result : %d\n", count) ;
	
	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
