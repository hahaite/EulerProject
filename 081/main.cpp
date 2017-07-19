#include <cstdio>
#include <sys/time.h>

using namespace std ;

#include <cstring>
#include <cstdlib>
#include <set>

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int ii, jj ;

#define INDEX_MAX 159

	int dataTemp[INDEX_MAX][INDEX_MAX] ;

	for(ii = 0; ii < INDEX_MAX; ii++)
	{
		for(jj = 0; jj < INDEX_MAX; jj++)
			dataTemp[ii][jj] = 0xfffff ;
	}

	// get data from the file.
	char* pTok ;
	char szBuf[1024] ;

	FILE* fp = fopen("matrix.txt", "rt") ;

	ii = 0;
	jj = 0 ;
	while(1)
	{
		fgets(szBuf, 1024, fp) ;
		if(feof(fp))
			break ;

		jj = 0 ;
		pTok = strtok(szBuf, ",") ;
		dataTemp[ii][jj] = atoi(pTok) ;

		while(1)
		{
			jj++ ;
			pTok = strtok(NULL, ",") ;
			if(pTok == NULL)
				break ;

			dataTemp[ii][jj] = atoi(pTok) ;
		}
		ii++ ;
	}
	fclose(fp) ;

	int data[INDEX_MAX][INDEX_MAX] ;


	for(ii = 0; ii < INDEX_MAX; ii++)
	{
		for(jj = 0; jj < INDEX_MAX; jj++)
			data[ii][jj] = 0xfffff ;
	}


	for(int index= 0; index < INDEX_MAX; index++)
	{
		int col = 0 ;
		int row = index ;

		int ii = 0 ;

		while(1)
		{
			data[index][ii] = dataTemp[row][col] ;

			row-- ;
			col++ ;
			ii++ ;

			if(row < 0)
				break ;
		}
	}

#if 0
	for(ii = 0; ii < 9; ii++)
	{
		for(jj = 0; jj < 9; jj++)
			printf("%5d ", data[ii][jj]) ;
		printf("\n") ;
	}
#endif

	int sum[INDEX_MAX] = {0, } ;
	int temp[INDEX_MAX] = {0, } ;

	for(int row = 0; row < INDEX_MAX; row++)
	{
		for(int jj = 0; jj < INDEX_MAX; jj++)
			temp[jj] = sum[jj] ;


		for(int col = 0; col < INDEX_MAX; col++)
		{
			if(col == 0)
			{
				sum[0] = temp[0] + data[row][col] ;
				continue ;
			}

			sum[col] = (temp[col-1] < temp[col]) ? temp[col-1] : temp[col] ;
			sum[col] += data[row][col] ;
		}
	}

	set<int>		setInt ;
	set<int>::iterator      setIntIter ;

	for(int ii = 0; ii < INDEX_MAX; ii++)
		setInt.insert(sum[ii]) ;

	setIntIter = setInt.begin() ;
	printf("Min Value : %d\n", *setIntIter) ;

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
