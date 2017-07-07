#include <cstdio>
#include <sys/time.h>

#include <set>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int data[15][15] =
	{{75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{95, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{17, 47, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{18, 35, 87, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{20, 4, 82, 47, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{19, 1, 23, 75, 3, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{88, 2, 77, 73, 7, 63, 67, 0, 0, 0, 0, 0, 0, 0, 0},
	{99, 65, 4, 28, 6, 16, 70, 92, 0, 0, 0, 0, 0, 0, 0},
	{41, 41, 26, 56, 83, 40, 80, 70, 33, 0, 0, 0, 0, 0, 0},
	{41, 48, 72, 33, 47, 32, 37, 16, 94, 29, 0, 0, 0, 0, 0},
	{53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, 0, 0, 0, 0},
	{70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, 0, 0, 0},
	{91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, 0, 0},
	{63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, 0},
	{4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23}} ;

#define INDEX_MAX 15

	int sum[INDEX_MAX] = {0, } ;
	int temp [INDEX_MAX] = {0, } ;

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

			sum[col] = (temp[col-1] >= temp[col]) ? temp[col-1] : temp[col] ;
			sum[col] += data[row][col] ;
		}
	}

	set<int>		setInt ;
	set<int>::iterator      setIntIter ;

	for(int ii = 0; ii < INDEX_MAX; ii++)
		setInt.insert(sum[ii]) ;

	setIntIter = setInt.end() ;
	setIntIter-- ;
	printf("MAx : %d\n", *setIntIter) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
