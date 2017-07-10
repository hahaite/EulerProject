#include <cstdio>
#include <sys/time.h>

#include <list>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	list<int>	       listDigit ;
	list<int>::iterator     listDigitIter ;

	list<int>	       listBinary;
	list<int>::iterator     listBinaryIter ;

	list<int>::iterator     listLeftIter ;
	list<int>::iterator     listRightIter ;

	int temp ;
	int sum = 0 ;
	int flagPalindrome_digit ;
	int flagPalindrome_binary ;

	for(int index = 10; index <= 1000000; index++)
	{
		// Check Digit
		temp = index ;

		listDigit.clear() ;
		while(temp)
		{
			listDigit.push_front(temp % 10) ;
			temp /= 10 ;
		}

		listLeftIter = listDigit.begin() ;
		listRightIter = listDigit.end() ;
		listRightIter-- ;

		flagPalindrome_digit = 1 ;
		for(int ii = 0; ii < listDigit.size() / 2; ii++)
		{
			if(*listLeftIter != *listRightIter)
			{
				flagPalindrome_digit = 0 ;
				break ;
			}

			listLeftIter++ ;
			listRightIter-- ;
		}
		if(!flagPalindrome_digit)
			continue ;

		// Check Binary
		temp = index ;

		listBinary.clear() ;
		while(temp)
		{
			listBinary.push_front(temp & 0x01) ;
			temp /= 2 ;
		}

		listLeftIter = listBinary.begin() ;
		listRightIter = listBinary.end() ;
		listRightIter-- ;

		flagPalindrome_binary = 1 ;
		for(int ii = 0; ii < listBinary.size() / 2; ii++)
		{
			if(*listLeftIter != *listRightIter)
			{
				flagPalindrome_binary = 0 ;
				break ;
			}
			listLeftIter++ ;
			listRightIter-- ;
		}

		if(flagPalindrome_digit && flagPalindrome_binary)
		{
			sum += index ;
			printf("index : %d\n", index) ;
		}
	}

	sum += 25 ;  // add 1, 3, 5, 7, 9

	printf("Result : %d\n", sum) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
