#include <cstdio>
#include <sys/time.h>

#include <set>

#include "./../bigInt/bigInt.h"

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	CBigInt bigInt ;

	string strA  ;
//      strA = bigInt.pow(2, 63) ;
//      printf("%s\n", strA.c_str()) ;
//      strA = bigInt.pow(5027, 3) ;
//      printf("%s\n", strA.c_str()) ;

	multiset<pair<pair<long long , int>, int> >		     msetInt ;
	multiset<pair<pair<long long, int>, int> >::iterator	    msetIntIter ;

	multiset<int>		   msetDigit ;
	multiset<int>::iterator	 msetDigitIter ;

	int zero ;
	long long temp ;

//      temp = 2954LL * 2954LL * 2954LL ;
//      printf("temp : %lld\n", temp) ;
//      return 1 ;

	for(long long ii = 100LL; ii < 10000LL; ii++)
	{
		temp = ii * ii * ii ;


		msetDigit.clear() ;
		while(temp)
		{
			msetDigit.insert(temp % 10LL) ;
			temp /= 10LL ;
		}

		zero = 0 ;
		temp = 0LL ;
		msetDigitIter = msetDigit.begin() ;
		for(; msetDigitIter != msetDigit.end(); msetDigitIter++)
		{
			if(*msetDigitIter == 0)
				zero++ ;

			temp *= 10LL ;
			temp += *msetDigitIter ;
		}

		msetInt.insert(make_pair(make_pair(temp, zero), ii)) ;
	}


	long long prev1 = 0LL;
	int prev2 = 0;
	int count = 0 ;
	msetIntIter = msetInt.begin() ;
	for(; msetIntIter != msetInt.end(); msetIntIter++)
	{

		if((prev1 == msetIntIter->first.first) && (prev2 == msetIntIter->first.second))
		{
//		      printf("\n") ;
			count++;
		}
		else
		{
			count = 1 ;
		}

		prev1 = msetIntIter->first.first ;
		prev2 = msetIntIter->first.second ;

		if(count == 5)
		{
			multiset<pair<pair<long long, int>, int> >::iterator	    msetIntIter1 ;
			multiset<pair<pair<long long, int>, int> >::iterator	    msetIntIter2 ;
			multiset<pair<pair<long long, int>, int> >::iterator	    msetIntIter3 ;
			multiset<pair<pair<long long, int>, int> >::iterator	    msetIntIter4 ;

			msetIntIter4 = (--msetIntIter)++ ;
			msetIntIter3 = (--msetIntIter4)++ ;
			msetIntIter2 = (--msetIntIter3)++ ;
			msetIntIter1 = (--msetIntIter2)++ ;

			printf("%lld - %d - %d\n", msetIntIter1->first.first, msetIntIter1->first.second, msetIntIter1->second) ;
			printf("%lld - %d - %d\n", msetIntIter2->first.first, msetIntIter2->first.second, msetIntIter2->second) ;
			printf("%lld - %d - %d\n", msetIntIter3->first.first, msetIntIter3->first.second, msetIntIter3->second) ;
			printf("%lld - %d - %d\n", msetIntIter4->first.first, msetIntIter4->first.second, msetIntIter4->second) ;
			printf("%lld - %d - %d\n", msetIntIter->first.first, msetIntIter->first.second, msetIntIter->second) ;
			printf("\n") ;
		}
		if(msetIntIter->first.first == 12334566789LL)
			printf("check : %lld - %d - %d\n", msetIntIter->first.first, msetIntIter->first.second, msetIntIter->second) ;

	}

	printf("5027^3 : %lld\n", 5027LL * 5027LL * 5027LL) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
