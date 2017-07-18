#include <cstdio>
#include <sys/time.h>

#include <set>
#include "./../triangleDFS/triangleDFS.h"

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

	CTriangleDFS tridfs ;

	const int DEPTH = 15 ;

	tridfs.init(DEPTH) ;
	int listCol[DEPTH] ;

	int maxSum = 0 ;

	int sum ;

	while(1)
	{
		if(!tridfs.getNext(listCol))
			break ;

		sum = 0 ;
		for(int dd = 0; dd < DEPTH; dd++)
			sum += data[dd][listCol[dd]] ;

		if(sum > maxSum)
			maxSum = sum ;
	}

	printf("Result : %d\n", maxSum) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;
	return 1 ;
}
