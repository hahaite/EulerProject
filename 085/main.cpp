#include <cstdio>
#include <sys/time.h>

#include <cstdlib>
#include <map>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int w = 2 ;
	int h = 2 ;

	int sum = 0 ;
	int temp ;

	int minValue = 1000000 ;

	int newW ;
	int newH ;
	
	while(1)
	{
		sum = 0 ;
		for(int ii = 1; ii <= w; ii++)
		{
			for(int jj = 1; jj <= h; jj++)
				sum += (w - ii + 1) * (h - jj + 1) ;

		}
		if(sum < 2000000)
		{
			temp = 2000000 - sum ;

			if(temp < minValue)
			{
				minValue = temp ;
				newW = w ;
				newH = h ;

				printf("%d, %d = %d\n", w, h, minValue) ;
			}
		}
		else if(sum > 2000000)
		{
			temp = sum - 2000000 ;

			if(temp < minValue)
			{
				minValue = temp ;
				newW = w ;
				newH = h ;
				printf("%d, %d = %d\n", w, h, minValue) ;
			}

			if(w == 2)
				break ;

			w = 1 ;
			h++ ;
		}
		w++ ;
	}
	
	printf("Result : %d * %d = %d\n", newW, newH, newW * newH) ;

	
	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
