#include <cstdio>
#include <sys/time.h>

#include <cstdlib>
#include <map>

using namespace std ;


#define POS_START 	0
#define POS_JAIL 	10
#define POS_GOTO_JAIL 	30

#define CHEST_1 	2
#define CHEST_2 	17
#define CHEST_3 	33

#define CHANCE_1 	7
#define CHANCE_2 	22
#define CHANCE_3 	36

#define CHANCE_GOTO_START 	0x11
#define CHANCE_GOTO_JAIL 	0x12
#define CHANCE_GOTO_C1 		0x13
#define CHANCE_GOTO_E3 		0x14
#define CHANCE_GOTO_H2 		0x15
#define CHANCE_GOTO_R1 		0x16
#define CHANCE_GOTO_NEXT_R 	0x17
#define CHANCE_GOTO_NEXT_U 	0x18
#define CHANCE_GOTO_BACK_3 	0x29

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	map<int, int> 			mapPos ;
	map<int, int>::iterator 	mapPosIter ;

	for(int ii = 0; ii < 40; ii++)
		mapPos.insert(make_pair(ii, 0)) ;

	int flagChest = 0 ;
	int flagChance = 0 ;

	int chance[16] = {0, } ;
	chance[0] = CHANCE_GOTO_START ;
	chance[1] = CHANCE_GOTO_JAIL ;
	chance[2] = CHANCE_GOTO_C1 ;
	chance[3] = CHANCE_GOTO_E3 ;
	chance[4] = CHANCE_GOTO_H2 ;
	chance[5] = CHANCE_GOTO_R1 ;
	chance[6] = CHANCE_GOTO_NEXT_R ;
	chance[7] = CHANCE_GOTO_NEXT_R ;
	chance[8] = CHANCE_GOTO_NEXT_U ;
	chance[9] = CHANCE_GOTO_BACK_3 ;

	int pos = 0 ;
	int dice ;
	int dice2 ;
	int moveCount ;
	int temp = 0 ;
	
	int max = 1000000 ;

	for(int ii = 0; ii < max; ii++)
	{
		temp = rand() ;
		dice = (temp % 1000) % 4 ;
		temp /= 1000 ;
		dice2 = (temp % 1000) % 4 ;

		moveCount = dice + dice2 + 2 ;
		
		pos += moveCount ;

		if(pos >= 40)
			pos -= 40 ;	

		switch(pos)
		{
		case POS_GOTO_JAIL :
			pos = POS_JAIL ;
			break ;
		case CHEST_1 :
		case CHEST_2 :
		case CHEST_3 :

			if(flagChest == 0)
				pos = POS_START ;
			else if(flagChest == 1)
				pos = POS_JAIL ;

			flagChest++ ;

			if(flagChest == 16)
				flagChest = 0 ;
			break ;
		case CHANCE_1 :
		case CHANCE_2 :
		case CHANCE_3 :

			flagChance = (flagChance == 16) ? 0 : flagChance + 1 ;
	
			temp = pos ;		
			switch(chance[flagChance])
			{

			case CHANCE_GOTO_START :
				pos = POS_START ;
				break ;
			case CHANCE_GOTO_JAIL :
				pos = POS_JAIL ;
				break ;
			case CHANCE_GOTO_C1 :
				pos = 11 ;
				break ;
			case CHANCE_GOTO_E3 :
				pos = 24 ;
				break ;
			case CHANCE_GOTO_H2 :
				pos = 39 ;
				break ;
			case CHANCE_GOTO_R1 :
				pos = 5 ;
				break ;
			case CHANCE_GOTO_NEXT_R :
				pos = (temp == CHANCE_1) ? 15 : pos ;
				pos = (temp == CHANCE_2) ? 25 : pos ;
				pos = (temp == CHANCE_3) ? 5 : pos ;
				break ;
			case CHANCE_GOTO_NEXT_U :
				pos = (temp == CHANCE_1) ? 12 : pos ;
				pos = (temp == CHANCE_2) ? 28 : pos ;
				pos = (temp == CHANCE_3) ? 12 : pos ;
				break ;
			case CHANCE_GOTO_BACK_3 :
				if(pos == CHANCE_3)
				{
					if(flagChest == 0)
						pos = POS_START ;
					else if(flagChest == 1)
						pos = POS_JAIL ;

					flagChest++ ;

					if(flagChest == 16)
						flagChest = 0 ;

				}
				else
				{
					pos -= 3 ;
				}
				break ;
			}
			break ;
		}

		mapPosIter = mapPos.find(pos) ;
		if(mapPosIter != mapPos.end())
			mapPosIter->second++ ;
	}

	int ret = 0;

	multimap<int, int> 			mapCheck ;
	multimap<int, int>::iterator 		mapCheckIter ;

	mapPosIter = mapPos.begin() ;
	for(; mapPosIter != mapPos.end(); mapPosIter++)
		mapCheck.insert(make_pair(mapPosIter->second, mapPosIter->first)) ;

	mapCheckIter = mapCheck.end() ;
	for(int ii = 0; ii < 3; ii++)
	{
		ret *= 100 ;
		mapCheckIter-- ;
		printf("[%d : %d] - %f\n", mapCheckIter->first, mapCheckIter->second, (double)mapCheckIter->first/max*100 ) ;
		ret += mapCheckIter->second ;
	}
	
	printf("Result : %d\n", ret) ;
	
	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
