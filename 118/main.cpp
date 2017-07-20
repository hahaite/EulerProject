#include <cstdio>
#include <sys/time.h>

#include <set>
#include <algorithm>
#include <cstring>

using namespace std ;

#include "../mymath/mymath.h"

struct PrimeData
{
	static int col ;
	int array[8] ;
};

int PrimeData::col = 8 ;

struct DataCompare
{
	bool operator()(const PrimeData& lhs, const PrimeData& rhs) const
	{
		for(int ii = 0; ii < lhs.col; ii++)
		{
			if(lhs.array[ii] < rhs.array[ii])
				return 1 ;
			else if(lhs.array[ii] > rhs.array[ii])
				return 0 ;
		}
		return 0 ;
	}
};

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int prime[8] ;

	set<PrimeData, DataCompare> 		setData ;	
	set<PrimeData, DataCompare>::iterator 	setDataIter ;	

	PrimeData primeData ;

	vector<int> 	vecInt ;
	vector<int>	vecCombi ;

	vector<int>::iterator	vecIter ;

	int flagBreak ;

	int left ;
	int right ;

	int primeCount = 0 ;

	CPrime primeObj ;
	int flagPrimeSet = 0 ;
	
	for(int nn = 0; nn < 8; nn++)
	{
		printf("NN ; %d\n", nn) ;
		int data[9] = {1, 2, 3, 4, 5, 6, 7,8, 9};

		while(1)
		{
			int n = 8 ;
			int r = nn + 1 ;

			vecInt.clear() ;
			for(int ii = 1; ii <= n; ii++)
				vecInt.push_back(ii) ;

			CCombination combination(&vecInt, r) ;

			while(1)
			{
				flagBreak = combination.getNext(&vecCombi) ;

				memset(prime, 0x00, sizeof(prime)) ;
				
				left = 0 ;
				for(int ii = 0; ii < r; ii++)
				{
					right = vecCombi[ii] ;
					
					for(int jj = left; jj < right; jj++)
					{
						prime[ii] *= 10 ;
						prime[ii] += data[jj] ;
					}
						
					left = right ;
				}

				for(int jj = left; jj < 9; jj++)
				{
					prime[r] *= 10 ;
					prime[r] += data[jj] ;
				}
				
				flagPrimeSet = 1 ;
				for(int ii = 0; ii <=r; ii++)
				{
					flagPrimeSet = primeObj.isPrime(prime[ii]) ;

					if(!flagPrimeSet)
						break ;
				}
				
				if(flagPrimeSet)
				{
					std::sort(&prime[0], &prime[8]) ;
					memcpy(&primeData.array, prime, sizeof(prime)) ;
					setData.insert(primeData) ;
				}

				if(!flagBreak)
					break ;
			}

			if(!next_permutation(&data[0], &data[9]))
				break ;
		}
	}

	printf("primeCount : %d\n", setData.size()) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
