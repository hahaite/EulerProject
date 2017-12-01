#include <cstdio>
#include <sys/time.h>

#include <cmath>

#include <vector>
#include <list>
#include <set>

#include <algorithm>
#include "./../mymath/mymath.h"

using namespace std ;

struct Operator
{
	int a ;
	int b ;
	int c ;
};

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	Operator stOp ;

	int permu[4] = {1, 2,3 ,4} ;
	int digit[4] ;
	int temp ;
	int temp2 ;

	int flagBreak ;

	list<Operator> 			listOp ;
	list<Operator>::iterator 	listOpIter ;

	set<int> 			setResult ;
	set<int>::iterator 		setResultIter ;

	int max = 0 ;
	int  a, b, c, d ;


	for(int ii = 111; ii <= 999; ii++)
	{
		flagBreak = 0 ;

		temp = ii ;
		
		while(temp)
		{
			temp2 = temp % 10 ;

			if(temp2 == 0 || temp2 > 4)
				flagBreak = 1 ;
			temp /= 10 ;
		}

		if(flagBreak)
			continue ;

		temp = ii ;	
		stOp.a = temp % 10 ;
		temp /= 10 ;
		stOp.b = temp % 10 ;
		temp /= 10 ;
		stOp.c = temp % 10 ;

		listOp.push_back(stOp) ;
	}

	vector<int> 		vecInt ;
	vector<int> 		vecCombi ;

	for(int ii = 1; ii < 10; ii++)
		vecInt.push_back(ii) ;

	CCombination combi(&vecInt, 4) ;

	int op[3] ;

	int result ;
	double dResult ;
	double dTemp ;

	double da ;
	double db ;

	int flagDisplay ;

	while(1)
	{
		flagBreak = combi.getNext(&vecCombi) ;

		for(int ii = 0; ii < 4; ii++)
			digit[ii] = vecCombi[ii] ;

		setResult.clear() ;


		flagDisplay = 0 ;
//		if(digit[0] == 1 && digit[1] == 2 && digit[2] == 5 && digit[3] == 6)
//			flagDisplay = 1 ;

		while(1)
		{
			listOpIter = listOp.begin() ;
			for(; listOpIter != listOp.end(); listOpIter++)
			{
				op[0] = listOpIter->a ;
				op[1] = listOpIter->b ;
				op[2] = listOpIter->c ;
				
				dResult = digit[0] ;
				for(int ii = 0; ii < 3; ii++)
				{
					switch(op[ii])
					{
					case 1 : dResult = dResult + digit[ii+1] ; break ;
					case 2 : dResult = dResult - digit[ii+1] ; break ;
					case 3 : dResult = dResult * digit[ii+1] ; break ;
					case 4 : dResult = dResult / digit[ii+1] ; break ;
					}
				}

				switch(op[0])
				{
				case 1 : da = digit[0] + digit[1] ; break ;
				case 2 : da = digit[0] - digit[1] ; break ;
				case 3 : da = digit[0] * digit[1] ; break ;
				case 4 : da = digit[0] / digit[1] ; break ;
				}

				if(dResult <= 0)
					continue ;

				dResult += 0.000001 ;
				dTemp = dResult ;
				
				dTemp *= 100000 ;
				temp = dTemp ;
				temp %= 100000 ;

				if(temp == 0)
				{
					result = (int)dResult ;
					setResult.insert(result) ;
				}

				dTemp = digit[0] ;
				switch(op[0])
				{
				case 1 : da = dTemp + digit[1] ; break ;
				case 2 : da = dTemp - digit[1] ; break ;
				case 3 : da = dTemp * digit[1] ; break ;
				case 4 : da = (double)dTemp / digit[1] ; break ;
				}

				dTemp = digit[2] ;
				switch(op[2])
				{
				case 1 : db = dTemp + digit[3] ; break ;
				case 2 : db = dTemp - digit[3] ; break ;
				case 3 : db = dTemp * digit[3] ; break ;
				case 4 : db = (double)dTemp / digit[3] ; break ;
				}

				switch(op[1])
				{
				case 1 : dResult = da + db ; break ;
				case 2 : dResult = da - db ; break ;
				case 3 : dResult = da * db ; break ;
				case 4 : dResult = da / db ; break ;
				}

				if(dResult <= 0)
					continue ;

				dResult += 0.000001 ;
				dTemp = dResult ;
				
				dTemp *= 100000 ;
				temp = dTemp ;
				temp %= 100000 ;

				if(temp == 0)
				{
					result = (int)dResult ;
					setResult.insert(result) ;
				}

				if(flagDisplay)
				{
					printf("%d ", digit[0]) ;
					if(op[0] == 1) printf("+ ") ;
					if(op[0] == 2) printf("- ") ;
					if(op[0] == 3) printf("* ") ;
					if(op[0] == 4) printf("/ ") ;
					
					printf("%d ", digit[1]) ;
					if(op[1] == 1) printf("+ ") ;
					if(op[1] == 2) printf("- ") ;
					if(op[1] == 3) printf("* ") ;
					if(op[1] == 4) printf("/ ") ;

					printf("%d ", digit[2]) ;
					if(op[2] == 1) printf("+ ") ;
					if(op[2] == 2) printf("- ") ;
					if(op[2] == 3) printf("* ") ;
					if(op[2] == 4) printf("/ ") ;

					printf("%d = %f", digit[3], dResult) ;
					printf("\n") ;
				}
			}

			if(!next_permutation(&digit[0], &digit[4]))
				break ;
		}



		// check Order
		int maxTemp = 0 ;
		for(int ii = 1; ii < 10000; ii++)
		{
			setResultIter = setResult.find(ii) ;

			if(setResultIter != setResult.end())
				maxTemp = ii ;
			else
				break ;
		}

//		printf("%d %d %d %d - %3d, %2d\n", digit[0], digit[1], digit[2], digit[3], setResult.size(), maxTemp) ;

		if(maxTemp > max)
		{
			max = maxTemp ;
			a = digit[0] ;
			b = digit[1] ;
			c = digit[2] ;
			d = digit[3] ;			
		}


		if(!flagBreak)
			break ;
	}

	printf("Result : %d%d%d%d\n", a, b, c, d) ;
	
	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
