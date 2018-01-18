#include <cstdio>
#include <sys/time.h>

#include <set>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	set<int> 		setInt ;
	set<int>::iterator 	setIntIter ;

	set<int> 		setTail ;
	set<int>::iterator 	setTailIter ;

	int ii = 2 ;
	int flagContinue ;

	long long a, b, c ;
	int temp, temp2 ;
	int findCount = 0 ;

	a = 1 ;
	b = 1 ;

	// generate Tailed PanDigital
	while(1)
	{
		ii++ ;

		c = a + b ;
		
		c %= 1000000000 ;

		a = b ;
		b = c ;


		setInt.clear() ;

		temp = c ;

		flagContinue = 0 ;
		while(temp)
		{
			temp2 = temp % 10 ;
			if(temp2 == 0)
			{
				flagContinue = 1 ;
				break ;
			}

			setInt.insert(temp2) ;

			temp /= 10 ;
		}

		if(flagContinue)
			continue ;

		if(setInt.size() == 9)
		{
			findCount++ ;
			setTail.insert(ii) ;
			printf("ii : %d - %d\n", ii, findCount) ;
		}

		if(findCount == 200)
			break ;
	}

	// Check Tail PanDigital
	long long upper_border = 1e15 ;
	a = 1 ;
	b = 1 ;
	ii = 2 ;

	while(1)
	{
		ii++ ;

		c = a + b ;
		a = b ;
		b = c ;

		if(c >= upper_border )
		{
			a /= 10 ;
			b /= 10 ;
			c /= 10 ;
		}

		setInt.clear() ;

		temp = c / 1000000 ;

		flagContinue = 0 ;
		while(temp)
		{
			temp2 = temp % 10 ;
			if(temp2 == 0)
			{
				flagContinue = 1 ;
				break ;
			}

			setInt.insert(temp2) ;

			temp /= 10 ;
		}

		if(flagContinue)
			continue ;

		if(setInt.size() == 9)
		{
			setTailIter = setTail.find(ii) ;
			if(setTailIter != setTail.end())
				break ;
		}
	}

	printf("Result : %d\n", ii) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
