#include <cstdio>
#include <sys/time.h>
#include <set>
#include <algorithm>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	const int MAX = 9 ;

	int permu[MAX] ;

	for(int ii = 0; ii < MAX; ii++)
		permu[ii] = ii + 1 ;

	int a, b, c ;
	int total = 0 ;

	set<int>		setSum ;
	set<int>::iterator      setSumIter ;

	while(1)
	{
		for(int multi = 1; multi < MAX; multi++)
		{
			for(int equal = multi + 1; equal < MAX; equal++)
			{
				a = 0 ;
				b = 0 ;
				c = 0 ;
				for(int ii = 0; ii < multi; ii++)
				{
					a *= 10 ;
					a += permu[ii] ;
				}

				for(int ii = multi; ii < equal; ii++)
				{
					b *= 10 ;
					b += permu[ii] ;
				}

				for(int ii = equal; ii < MAX; ii++)
				{
					c *= 10 ;
					c += permu[ii] ;
				}

				if( a * b == c)
				{
					setSum.insert(c) ;
					printf("%d * %d = %d\n", a, b, c) ;
				}
			}
		}

		if(!next_permutation(permu, &permu[MAX]))
			break ;
	}

	setSumIter = setSum.begin() ;
	for(; setSumIter != setSum.end(); setSumIter++)
		total += *setSumIter ;

	printf("Total : %d\n", total) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
