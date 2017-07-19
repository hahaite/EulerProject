#include <cstdio>
#include <sys/time.h>

#include <map>
#include <set>
#include <list>
#include <cstring>

using namespace std ;

#define RET_OK  	0
#define RET_FAIL 	1

int checkRow(int (*pData)[9], int col)
{

	set<int>		setInt ;
	set<int>::iterator      setIntIter ;

	for(int ii = 0; ii < 9; ii++)
	{
		if(ii == col)
			continue ;

		setInt.insert( (*pData)[ii] ) ;
	}

	setIntIter = setInt.find((*pData)[col]) ;
	if(setIntIter != setInt.end())
		return RET_FAIL ;

	return RET_OK ;
}

int checkCol(int (*pData)[9][9], int row, int col)
{

	set<int>		setInt ;
	set<int>::iterator      setIntIter ;

	for(int ii = 0; ii < 9; ii++)
	{
		if(ii == row)
			continue ;

		setInt.insert( (*pData)[ii][col] ) ;
	}

	setIntIter = setInt.find((*pData)[row][col]) ;
	if(setIntIter != setInt.end())
		return RET_FAIL ;

	return RET_OK ;
}

int check3x3(int (*pData)[9][9], int row, int col)
{
	set<int>		setInt ;
	set<int>::iterator      setIntIter ;

	int startRow = row - (row % 3) ;
	int startCol = col - (col % 3) ;

	for(int ii = startRow; ii < (startRow+3); ii++)
	{
		for(int jj = startCol; jj < (startCol+3); jj++)
		{
			if(ii == row && jj == col)
				continue ;

			setInt.insert( (*pData)[ii][jj] ) ;
		}
	}

	setIntIter = setInt.find((*pData)[row][col]) ;
	if(setIntIter != setInt.end())
		return RET_FAIL ;

	return RET_OK ;
}

int output(int (*pData)[9][9])
{
	for(int ii = 0; ii < 9; ii++)
	{
		for(int jj = 0; jj < 9; jj++)
			printf("%d ", (*pData)[ii][jj]) ;
		printf("\n") ;
	}

	return 1 ;
}

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int sudoku[9][9] ;
	int data[9][9] ;
	char szBuf[1024] ;
	int ret ;
	int sum = 0 ;

	FILE* fp = fopen("sudoku.txt", "rt") ;

	for(int grid = 0; grid < 50; grid++)
	{
		fgets(szBuf, 1024, fp) ;

		for(int ii = 0; ii < 9; ii++)
		{
			fgets(szBuf, 1024, fp) ;
			for(int jj = 0; jj < 9; jj++)
				sudoku[ii][jj] = szBuf[jj] - '0' ;
		}

		int row = 0 ;
		int col = 0 ;

		memcpy(data, sudoku, sizeof(sudoku)) ;

		while(1)
		{
			// check static Sudoku.
			if(sudoku[row][col])
			{

				if(row == 8 && col == 8)
				{
					printf("FIND~!!! - %d\n", grid ) ;
					sum += (data[0][0] * 100) + (data[0][1] * 10) + data[0][2];
					output(&data) ;
					break ;
				}

				goto move_next ;

			}
			// setting cur Pos.
			data[row][col]++ ;

			if(data[row][col] == 10)
			{
				// move PREV.
				data[row][col] = 0 ;

				while(1)
				{
					col-- ;
					if(col < 0)
					{
						col = 9 ;
						row-- ;
					}

					if(!sudoku[row][col])
						break ;
				}
				continue ;
			}

			// CHECK~!!
			ret = checkRow(&data[row], col) ;
			if(ret != RET_OK)
				continue ;

			ret = checkCol(&data, row, col) ;
			if(ret != RET_OK)
				continue ;

			ret = check3x3(&data, row, col) ;
			if(ret != RET_OK)
				continue ;


			if(row == 8 && col == 8)
			{
				printf("FIND~!!!!! - %d\n", grid ) ;
				sum += (data[0][0] * 100) + (data[0][1] * 10) + data[0][2];

				output(&data) ;
				break ;
			}
move_next :
			// move NEXT~!!
			col++ ;
			if(col == 9)
			{
				col = 0 ;
				row++ ;
			}
		}
	}

	fclose(fp) ;

	printf("SUM : %d\n", sum) ;









	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
