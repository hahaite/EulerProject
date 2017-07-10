#include <cstdio>
#include <sys/time.h>


using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	unsigned int temp ;

	unsigned int index3 = 1 ;
	unsigned int index5 = 1 ;
	unsigned int index6 = 1 ;

	unsigned int ret3 = 1 ;
	unsigned int ret5 = 1 ;
	unsigned int ret6 = 1 ;

	int status = 0 ;

	while(1)
	{
		status = 0 ;

		if(ret3 > ret5)
			status = (ret5 <= ret6) ? 5 : 6 ;
		else
			status = (ret3 <= ret6) ? 3 : 6 ;

		switch(status)
		{
		case 3 :
			index3++ ;
			ret3 = index3 * (index3 + 1) / 2 ;
			break ;
		case 5 :
			index5++ ;
			ret5 = index5 * ((3 * index5) - 1) / 2 ;
			break ;
		case 6 :
			index6++ ;
			ret6 = index6 * ((2 * index6) - 1) ;
			break ;
		}

		if(ret3 == ret5 && ret5 == ret6)
		{
			printf("%d\n", ret3) ;

			if(ret3 != 40755)
				break ;
		}
	}

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
