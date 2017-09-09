#include <cstdio>
#include <sys/time.h>

#include <set>
#include <cstring>
#include <cstdlib>

#include "./../triangleDFS/triangleDFS.h"

using namespace std ;

#define INDEX_MAX 	100


int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int ii, jj ;
	int data[100][100] ;

	for(int ii = 0; ii < 100; ii++)
	{
		for(int jj = 0; jj < 100; jj++)
			data[ii][jj] = 0 ;
	}

	// get data from the file.
	char* pTok ;
	char szBuf[1024] ;

	FILE* fp = fopen("./triangle.txt", "rt") ;

	if(!fp)
	{
		printf("file open error\n") ;
		return -1 ;
	}	

	ii = 0;
	jj = 0 ;
	while(1)
	{
		fgets(szBuf, 1024, fp) ;
		if(feof(fp))
			break ;

		jj = 0 ;
		pTok = strtok(szBuf, " ") ;
		data[ii][jj] = atoi(pTok) ;


		while(1)
		{
			jj++ ;
			pTok = strtok(NULL, " ") ;
			if(pTok == NULL)
				break ;

			data[ii][jj] = atoi(pTok) ;
		}
		ii++ ;
	}
	fclose(fp) ;
	
	CTriangleDFS tridfs ;

	const int DEPTH = 25 ;

	int row = 0;
	int totalSum = 0 ;
	int prevMaxCol = 0 ;
	int listCol[DEPTH] ;

	for(ii = 0; ii < 4; ii++)
	{
		printf("========================================= ii : %d\n", ii) ;
		tridfs.init(DEPTH) ;

		int maxCol = 0 ;
		int maxSum = 0 ;

		int sum ;

		if(ii > 0)
		{
			if(data[row][prevMaxCol] < data[row][prevMaxCol + 1])
			{
				prevMaxCol++ ;
			}
		}

		while(1)
		{
			if(!tridfs.getNext(listCol))
				break ;

			sum = 0 ;
			for(int dd = 0; dd < DEPTH; dd++)
			{
				sum += data[row + dd][listCol[dd] + prevMaxCol] ;
			}

			if(sum > maxSum)
			{
				maxSum = sum ;
				maxCol = listCol[DEPTH-1] + prevMaxCol ;
				printf("Refresh maxCol : %d, maxSum : %d\n", maxCol, maxSum) ;
			}
		}
	
		totalSum += maxSum ;

		row += DEPTH ;
		prevMaxCol = maxCol ;

		tridfs.destroy() ;
	}

	printf("\nResult : %d\n", totalSum) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
