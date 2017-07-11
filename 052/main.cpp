#include <cstdio>
#include <sys/time.h>

#include <cstring>
#include <set>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	multiset<int> 			msetFirst ;
	multiset<int>::iterator 	msetFirstIter ;

	multiset<int> 			msetSecond ;
	multiset<int>::iterator 	msetSecondIter ;

	int index = 1 ;
	int temp ;

	while(1)
	{
		msetFirst.clear() ;

		index++ ;

		temp = index ;
		
		while(temp)
		{
			msetFirst.insert(temp % 10) ;
			temp /= 10 ;
		}

		for(int multi = 2; multi <= 6; multi++)
		{
			msetSecond.clear() ;

			temp = index * multi ;
			while(temp)
			{
				msetSecond.insert(temp % 10) ;
				temp /= 10 ;
			}

			if(msetFirst.size() != msetSecond.size())
				goto while_continue ;

			msetFirstIter = msetFirst.begin() ;
			msetSecondIter = msetSecond.begin() ;

			for(; msetFirstIter != msetFirst.end(); msetFirstIter++)
			{
				if(*msetFirstIter != *msetSecondIter)
					goto while_continue ;

				msetSecondIter++ ;
			}
		}

		break ;

while_continue :
	continue ;

	}

	printf("Result : %d\n", index) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
