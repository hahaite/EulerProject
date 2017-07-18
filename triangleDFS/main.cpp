#include "triangleDFS.h"

#include <cstdio>

using namespace std ;

int main()
{
	CTriangleDFS tridfs ;

	const int MAX = 5 ;

	tridfs.init(MAX) ;
	int value[MAX] ;

	while(1)
	{
		if(!tridfs.getNext(value))
			break ;

		for(int ii = 0; ii < MAX; ii++)
			printf("%d ", value[ii]) ;
		printf("\n") ;

	}

	return 1 ;
}

