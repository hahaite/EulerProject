#include <cstdio>
#include <sys/time.h>

#include <map>
#include <cstring>
#include <cstdlib>

using namespace std ;


int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	FILE* fp = fopen("triangles.txt", "rt") ;

	char szBuf[1024] ;

	int x1, y1 ;
	int x2, y2 ;
	int x3, y3 ;

	double d1, d2, d3 ;
	double b1, b2, b3 ;

	char* pTok ;
	int count = 0 ;
	int ret ;
	int temp = 0 ;

	multimap<int, int>	      mapPos ;
	multimap<int, int>::iterator    mapPosIter ;

	while(1)
//      for(int ii = 0; ii < 1000; ii++)
	{
		fgets(szBuf, 1024, fp) ;

		if(feof(fp))
			break ;

		// first pos.
		pTok = strtok(szBuf, ",") ;
		x1 = atoi(pTok) ;
		pTok = strtok(NULL, ",") ;
		y1 = atoi(pTok) ;

		// second pos.
		pTok = strtok(NULL, ",") ;
		x2 = atoi(pTok) ;
		pTok = strtok(NULL, ",") ;
		y2 = atoi(pTok) ;

		// third pos.
		pTok = strtok(NULL, ",") ;
		x3 = atoi(pTok) ;
		pTok = strtok(NULL, ",") ;
		y3 = atoi(pTok) ;


		mapPos.clear() ;
		mapPos.insert(make_pair(x1, y1)) ;
		mapPos.insert(make_pair(x2, y2)) ;
		mapPos.insert(make_pair(x3, y3)) ;

		mapPosIter = mapPos.begin() ;
		x3 = mapPosIter->first ;
		y3 = mapPosIter->second ;

		mapPosIter++ ;
		x2 = mapPosIter->first ;
		y2 = mapPosIter->second ;

		mapPosIter++ ;
		x1 = mapPosIter->first ;
		y1 = mapPosIter->second ;


		if(x1 == x2 || x1 == x3 || x2 == x3)
		{
//		      printf("Xa == Xb : [%4d,%4d] [%4d,%4d] [%4d,%4d]\n", x1, y1, x2, y2, x3, y3) ;
			continue ;
		}

		if(y1 == y2 || y1 == y3 || y2 == y3)
		{
//		      printf("Ya == Yb : [%4d,%4d] [%4d,%4d] [%4d,%4d]\n", x1, y1, x2, y2, x3, y3) ;
			continue ;
		}

		d1 = (double)(y1-y2)/(x1-x2) ;
		d2 = (double)(y1-y3)/(x1-x3) ;
		d3 = (double)(y2-y3)/(x2-x3) ;


		b1 = y1-(d1*x1) ;
		b2 = y1-(d2*x1) ;
		b3 = y3-(d3*x3) ;

//	      printf("[%4d,%4d] [%4d,%4d] [%4d,%4d]\n", x1, y1, x2, y2, x3, y3) ;
//	      printf("%f, %f, %f\n", d1, d2, d3) ;


		if( y1 > y2 && y2 > y3)
		{
			if(b1 < 0 && b2 > 0 && b3 < 0)
				count++ ;

			if(b1 > 0 && b2 < 0 && b3 > 0)
				count++ ;


		}
		else if( y1 > y3 && y3 > y2)
		{
			if(b1 < 0 && b2 > 0 && b3 < 0)
				count++ ;
		}
		else if( y2 > y1 && y1 > y3)
		{
			if(b1 > 0 && b2 < 0 && b3 > 0)
				count++ ;
		}
		else if( y3 > y2 && y2 > y1)
		{
			if(b1 < 0 && b2 > 0 && b3 < 0)
				count++ ;

			if(b1 > 0 && b2 < 0 && b3 > 0)
				count++ ;
		}
		else if( y2 > y3 && y3 > y1)
		{
			if(b1 > 0 && b2 < 0 && b3 > 0)
				count++ ;
		}
		else if( y3 > y1 && y1 > y2)
		{
			if(b1 < 0 && b2 > 0 && b3 < 0)
				count++ ;
		}
		else
		{
			printf("CHECK~!! - [%d,%d] [%d,%d] [%d,%d]\n", x1, y1, x2, y2, x3, y3) ;
		}

	}
	fclose(fp) ;

	printf("Count : %d\n", count) ;



	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
