#include <cstdio>
#include <sys/time.h>

#include <list>
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

	set<int> 		setSum ;
	set<int>::iterator 	setSumIter ;

	setSum.insert(4) ; // K = 2 ;

	int data[12000] ;

	int kk, pos, ii ;
	int sum, product, minSum ;

	for(int nn = 3; nn <= 12000; nn++)
	{
		if(nn % 100 == 0)
			printf("Index : %d\n", nn) ;
		
		kk = nn ;
		pos = 0 ;

		for(ii = 0; ii < kk; ii++)
			data[ii] = 1 ;

		data[0] = 2 ;
		data[1] = 2 ;
		minSum = 0 ;

		while(1)
		{
			// obtain product
			product = 1;
			for(ii = 0; ii < kk; ii++)
			{
				if(data[ii] == 1)
					break ;
				product *= data[ii] ;
			}
			
			// obtain sum
			sum = 0 ;
			for(ii = 0; ii < kk; ii++)
			{
				if(data[ii] == 1)
				{
					sum += (kk - ii) ;
					break ;
				}
				sum += data[ii] ;
			}

			if(product >= sum)
			{
				if(product == sum)
				{
#if 0
					printf("Find(%d) : ", kk) ;
					for(int ii = 0; ii < kk; ii++)
					{
						printf("%d ", data[ii]) ;
						if(data[ii] == 1)
						{
							printf("[%d]", kk - ii) ; 
							break ;
						}
					}
					printf("\n") ;
#endif
					if(minSum == 0)
						minSum = sum ;

					if(minSum > sum)
						minSum = sum ;
				}

				pos++ ;
				if(data[pos] == 1)
				{
					product = 1 ;
					product = product << (pos + 1) ;

					sum = kk + pos + 1 ;
					
					if(product > sum)
					{
						setSum.insert(minSum) ;
						break ;
					}
				}

				data[pos]++ ;

				for(ii = 0; ii < pos ; ii++)
					data[ii] = data[pos] ;
				
				continue ;
			}

			pos = 0 ;
			data[0]++ ;
		}
	}

	sum = 0 ;
	setSumIter = setSum.begin() ;
	for(; setSumIter != setSum.end(); setSumIter++)
		sum += *setSumIter ;
	
	printf("Sum : %d\n", sum) ;



	
	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
