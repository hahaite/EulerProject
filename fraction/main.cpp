#include <cstdio>
#include "fraction.h"

int main()
{
	CFraction frac ;

	list<int> 		listInt ;
	list<int>::iterator 	listIntIter ;

	frac.contFraction_SquaredRoot(61, &listInt, 30, 1) ;


	listIntIter = listInt.begin() ;
	for(; listIntIter != listInt.end(); listIntIter++)
		printf("%d ", *listIntIter) ;
	printf("\n") ;

	return 1 ;
}
