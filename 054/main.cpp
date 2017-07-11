#include <cstdio>
#include <sys/time.h>

#include <set>
#include <cstring>

using namespace std ;

#define HIGH_CARD 	100
#define ONE_PAIR 	200
#define TWO_PAIRS 	300
#define THREE_KIND 	400
#define STRAIGHT 	500
#define FLUSH 		600
#define FULL_HOUSE 	700
#define FOUR_KIND 	800
#define STRAIGHT_FLUSH 	900
#define ROYAL_FLUSH 	1000

int aa, bb, cc, dd, ee ;

set<int> 		setCard ;
set<int>::iterator 	setCardIter ;

int card[5][2] ;

int getCard(char* szBuf)
{
	int cardNum ;

	if( '1' <= szBuf[0] && szBuf[0] <= '9')
		cardNum = (szBuf[0] - '0') * 10 ;
	else if( szBuf[0] == 'T')
		cardNum = 100 ;
	else if( szBuf[0] == 'J')
		cardNum = 110 ;
	else if( szBuf[0] == 'Q')
		cardNum = 120 ;
	else if( szBuf[0] == 'K')
		cardNum = 130 ;
	else if( szBuf[0] == 'A')
		cardNum = 140 ;

	if(szBuf[1] == 'C')
		cardNum += 1 ;
	else if(szBuf[1] == 'D')
		cardNum += 2 ;
	else if(szBuf[1] == 'H')
		cardNum += 3 ;
	else if(szBuf[1] == 'S')
		cardNum += 4 ;

	return cardNum ;
}


int RoyalFlush(char* szBuf)
{
	aa = getCard(&szBuf[0]) ;
	bb = getCard(&szBuf[3]) ;
	cc = getCard(&szBuf[6]) ;
	dd = getCard(&szBuf[9]) ;
	ee = getCard(&szBuf[12]) ;
	
	setCard.clear() ;
	setCard.insert(aa) ;
	setCard.insert(bb) ;
	setCard.insert(cc) ;
	setCard.insert(dd) ;
	setCard.insert(ee) ;

	setCardIter = setCard.begin() ;
	for(int ii = 0; ii < 5; ii++)
	{
		card[ii][0] = *setCardIter / 10 ;	
		card[ii][1] = *setCardIter % 10 ;
		setCardIter++ ;
	}

	if(card[0][0] != 10 || card[1][0] != 11 || card[2][0] != 12 || card[3][0] != 13 || card[4][0] != 14)
		return 0 ;	


	int mark = card[0][1] ;

	
	if(card[1][1] != mark || card[2][1] != mark || card[3][1] != mark || card[4][1] != mark)
		return 0 ;	

	return ROYAL_FLUSH ;
}


int StraightFlush(char* szBuf)
{
	aa = getCard(&szBuf[0]) ;
	bb = getCard(&szBuf[3]) ;
	cc = getCard(&szBuf[6]) ;
	dd = getCard(&szBuf[9]) ;
	ee = getCard(&szBuf[12]) ;

	setCard.clear() ;
	setCard.insert(aa) ;
	setCard.insert(bb) ;
	setCard.insert(cc) ;
	setCard.insert(dd) ;
	setCard.insert(ee) ;

	setCardIter = setCard.begin() ;
	for(int ii = 0; ii < 5; ii++)
	{
		card[ii][0] = *setCardIter / 10 ;	
		card[ii][1] = *setCardIter % 10 ;
		setCardIter++ ;
	}

	if(card[1][0] - card[0][0] != 1)
		return 0 ;
	if(card[2][0] - card[1][0] != 1)
		return 0 ;
	if(card[3][0] - card[2][0] != 1)
		return 0 ;
	if(card[4][0] - card[3][0] != 1)
		return 0 ;


	int mark = card[0][1] ;

	if(card[1][1] != mark || card[2][1] != mark || card[3][1] != mark || card[4][1] != mark)
		return 0 ;	

	return STRAIGHT_FLUSH ;
}



int FourKind(char* szBuf)
{
	aa = getCard(&szBuf[0]) ;
	bb = getCard(&szBuf[3]) ;
	cc = getCard(&szBuf[6]) ;
	dd = getCard(&szBuf[9]) ;
	ee = getCard(&szBuf[12]) ;

	setCard.clear() ;
	setCard.insert(aa) ;
	setCard.insert(bb) ;
	setCard.insert(cc) ;
	setCard.insert(dd) ;
	setCard.insert(ee) ;

	setCardIter = setCard.begin() ;
	for(int ii = 0; ii < 5; ii++)
	{
		card[ii][0] = *setCardIter / 10 ;	
		card[ii][1] = *setCardIter % 10 ;
		setCardIter++ ;
	}

	int num = card[0][0] ;
	if(card[1][0] == num && card[2][0] == num && card[3][0] == num)
		return FOUR_KIND ; 

	num = card[1][0] ;
	if(card[2][0] == num && card[3][0] == num && card[4][0] == num)
		return FOUR_KIND ; 

	return 0 ;
}


int FullHouse(char* szBuf)
{
	aa = getCard(&szBuf[0]) ;
	bb = getCard(&szBuf[3]) ;
	cc = getCard(&szBuf[6]) ;
	dd = getCard(&szBuf[9]) ;
	ee = getCard(&szBuf[12]) ;

	setCard.clear() ;
	setCard.insert(aa) ;
	setCard.insert(bb) ;
	setCard.insert(cc) ;
	setCard.insert(dd) ;
	setCard.insert(ee) ;

	setCardIter = setCard.begin() ;
	for(int ii = 0; ii < 5; ii++)
	{
		card[ii][0] = *setCardIter / 10 ;	
		card[ii][1] = *setCardIter % 10 ;
		setCardIter++ ;
	}

	int check1 ;
	int check2 ;
	int num = card[0][0] ;
	check1 = card[1][0] == num && card[2][0] == num ;
	check2 = card[3][0] == card[4][0] ;

	if(check1 && check2)
		return FULL_HOUSE ;

	num = card[2][0] ;
	check1 = card[3][0] == num && card[4][0] == num ;
	check2 = card[0][0] == card[1][0] ;

	if(check1 && check2)
		return FULL_HOUSE ;

	return 0 ;
}

int Flush(char* szBuf)
{
	aa = getCard(&szBuf[0]) ;
	bb = getCard(&szBuf[3]) ;
	cc = getCard(&szBuf[6]) ;
	dd = getCard(&szBuf[9]) ;
	ee = getCard(&szBuf[12]) ;

	setCard.clear() ;
	setCard.insert(aa) ;
	setCard.insert(bb) ;
	setCard.insert(cc) ;
	setCard.insert(dd) ;
	setCard.insert(ee) ;

	setCardIter = setCard.begin() ;
	for(int ii = 0; ii < 5; ii++)
	{
		card[ii][0] = *setCardIter / 10 ;	
		card[ii][1] = *setCardIter % 10 ;
		setCardIter++ ;
	}

	int check ;
	int num = card[0][1] ;
	check = card[1][1] == num && card[2][1] == num && card[3][1] == num && card[4][1] == num ;

	if(check)
		return FLUSH ;

	return 0 ;
}

int Straight(char* szBuf)
{
	aa = getCard(&szBuf[0]) ;
	bb = getCard(&szBuf[3]) ;
	cc = getCard(&szBuf[6]) ;
	dd = getCard(&szBuf[9]) ;
	ee = getCard(&szBuf[12]) ;

	setCard.clear() ;
	setCard.insert(aa) ;
	setCard.insert(bb) ;
	setCard.insert(cc) ;
	setCard.insert(dd) ;
	setCard.insert(ee) ;

	setCardIter = setCard.begin() ;
	for(int ii = 0; ii < 5; ii++)
	{
		card[ii][0] = *setCardIter / 10 ;	
		card[ii][1] = *setCardIter % 10 ;
		setCardIter++ ;
	}

	int num1 = card[1][0] - card[0][0] ;
	int num2 = card[2][0] - card[1][0] ;
	int num3 = card[3][0] - card[2][0] ;
	int num4 = card[4][0] - card[3][0] ;

	if(num1 == 1 && num2 == 1 && num3 == 1 && num4 == 1)
		return STRAIGHT ;

	return 0 ;
}

int ThreeKind(char* szBuf)
{
	aa = getCard(&szBuf[0]) ;
	bb = getCard(&szBuf[3]) ;
	cc = getCard(&szBuf[6]) ;
	dd = getCard(&szBuf[9]) ;
	ee = getCard(&szBuf[12]) ;

	setCard.clear() ;
	setCard.insert(aa) ;
	setCard.insert(bb) ;
	setCard.insert(cc) ;
	setCard.insert(dd) ;
	setCard.insert(ee) ;

	setCardIter = setCard.begin() ;
	for(int ii = 0; ii < 5; ii++)
	{
		card[ii][0] = *setCardIter / 10 ;	
		card[ii][1] = *setCardIter % 10 ;
		setCardIter++ ;
	}

	int check ;
	int num = card[0][0] ;
	check = card[1][0] == num && card[2][0] == num ;
	if(check)
		return THREE_KIND ;

	num = card[1][0] ;
	check = card[2][0] == num && card[3][0] == num ;
	if(check)
		return THREE_KIND ;

	num = card[2][0] ;
	check = card[3][0] == num && card[4][0] == num ;
	if(check)
		return THREE_KIND ;

	return 0 ;
}

int TwoPairs(char* szBuf)
{
	aa = getCard(&szBuf[0]) ;
	bb = getCard(&szBuf[3]) ;
	cc = getCard(&szBuf[6]) ;
	dd = getCard(&szBuf[9]) ;
	ee = getCard(&szBuf[12]) ;

	setCard.clear() ;
	setCard.insert(aa) ;
	setCard.insert(bb) ;
	setCard.insert(cc) ;
	setCard.insert(dd) ;
	setCard.insert(ee) ;

	setCardIter = setCard.begin() ;
	for(int ii = 0; ii < 5; ii++)
	{
		card[ii][0] = *setCardIter / 10 ;	
		card[ii][1] = *setCardIter % 10 ;
		setCardIter++ ;
	}

	int check ;
	check = (card[0][0] == card[1][0]) && (card[2][0] == card[3][0]) ;
	if(check)
		return TWO_PAIRS ;

	check = (card[0][0] == card[1][0]) && (card[3][0] == card[4][0]) ;
	if(check)
		return TWO_PAIRS ;

	check = (card[1][0] == card[2][0]) && (card[3][0] == card[4][0]) ;
	if(check)
		return TWO_PAIRS ;

	return 0 ;
}

int OnePair(char* szBuf)
{
	aa = getCard(&szBuf[0]) ;
	bb = getCard(&szBuf[3]) ;
	cc = getCard(&szBuf[6]) ;
	dd = getCard(&szBuf[9]) ;
	ee = getCard(&szBuf[12]) ;

	setCard.clear() ;
	setCard.insert(aa) ;
	setCard.insert(bb) ;
	setCard.insert(cc) ;
	setCard.insert(dd) ;
	setCard.insert(ee) ;

	setCardIter = setCard.begin() ;
	for(int ii = 0; ii < 5; ii++)
	{
		card[ii][0] = *setCardIter / 10 ;	
		card[ii][1] = *setCardIter % 10 ;
		setCardIter++ ;
	}

	
	if(card[0][0] == card[1][0])
		return (ONE_PAIR + card[1][0]) ;
	if(card[1][0] == card[2][0])
		return (ONE_PAIR + card[2][0]) ;
	if(card[2][0] == card[3][0])
		return (ONE_PAIR + card[3][0]) ;
	if(card[3][0] == card[4][0])
		return (ONE_PAIR + card[4][0]) ;

	return 0 ;
}	

int HighCard(char* szBuf)
{
	aa = getCard(&szBuf[0]) ;
	bb = getCard(&szBuf[3]) ;
	cc = getCard(&szBuf[6]) ;
	dd = getCard(&szBuf[9]) ;
	ee = getCard(&szBuf[12]) ;

	setCard.clear() ;
	setCard.insert(aa) ;
	setCard.insert(bb) ;
	setCard.insert(cc) ;
	setCard.insert(dd) ;
	setCard.insert(ee) ;

	setCardIter = setCard.begin() ;
	for(int ii = 0; ii < 5; ii++)
	{
		card[ii][0] = *setCardIter / 10 ;	
		card[ii][1] = *setCardIter % 10 ;
		setCardIter++ ;
	}

	return (HIGH_CARD + card[4][0]) ;		
}	

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	FILE* fp = fopen("poker.txt", "rt") ;
	
	char szBuf[128] ;
	char szBuf1[128] ;
	char szBuf2[128] ;

	int point1 = 0 ;
	int point2 = 0 ;

	int ii = 0 ;

	int win = 0 ;
	int draw = 0 ;
	int lose = 0 ;

#if 1
	strcpy(szBuf1, "6H 6S 6C ") ;
	point1 = StraightFlush(szBuf1) ;
	if(point1)
		printf("Straight Flush : %s\n", szBuf1) ;
#endif

	while(1)
	{
		fgets(szBuf, 128, fp) ;

		if(feof(fp))
			break ;

		memcpy(szBuf1, szBuf, 14) ;
		memcpy(szBuf2, &szBuf[15], 14) ;
		szBuf1[14] = '\0' ;
		szBuf2[14] = '\0' ;

		point1 = 0 ;
		point2 = 0 ;

		point1 = RoyalFlush(szBuf1) ;
		point2 = RoyalFlush(szBuf2) ;

		if(point1 || point2)
			printf("Royal Flush\n") ;

		// Straight Flush
		if(!point1)
			point1 = StraightFlush(szBuf1) ;
		if(!point2)
			point2 = StraightFlush(szBuf2) ;
		
		if(point1 == STRAIGHT_FLUSH)
			printf("Straight Flush : %s\n", szBuf1) ;
		if(point2 == STRAIGHT_FLUSH)
			printf("Straight Flush : %s\n", szBuf2) ;

		// Four of a Kind
		if(!point1)
			point1 = FourKind(szBuf1) ;
		if(!point2)
			point2 = FourKind(szBuf2) ;
		
		if(point1 == FOUR_KIND)
			printf("four of a kind : %s\n", szBuf1) ;
		if(point2 == FOUR_KIND)
			printf("four of a kind : %s\n", szBuf2) ;

		// Full House
		if(!point1)
			point1 = FullHouse(szBuf1) ;
		if(!point2)
			point2 = FullHouse(szBuf2) ;
		
#if 0
		if(point1 == FULL_HOUSE )
			printf("Full House : %s\n", szBuf1) ;
		if(point2 == FULL_HOUSE )
			printf("Full House : %s\n", szBuf2) ;
#endif

		// Flush
		if(!point1)
			point1 = Flush(szBuf1) ;
		if(!point2)
			point2 = Flush(szBuf2) ;

#if 0		
		if(point1 == FLUSH )
			printf("Flush : %s\n", szBuf1) ;
		if(point2 == FLUSH )
			printf("Flush : %s\n", szBuf2) ;
#endif

		// Straight
		if(!point1)
			point1 = Straight(szBuf1) ;
		if(!point2)
			point2 = Straight(szBuf2) ;
#if 0	
		if(point1 == STRAIGHT)
			printf("Straight : %s\n", szBuf1) ;
		if(point2 == STRAIGHT)
			printf("Straight : %s\n", szBuf2) ;
#endif

		// Three of a kind
		if(!point1)
			point1 = ThreeKind(szBuf1) ;
		if(!point2)
			point2 = ThreeKind(szBuf2) ;

#if 0
		if(point1 == THREE_KIND)
			printf("Three of a kind : %s\n", szBuf1) ;
		if(point2 == THREE_KIND)
			printf("Three of a kind : %s\n", szBuf2) ;
#endif

		// Two Pairs
		if(!point1)
			point1 = TwoPairs(szBuf1) ;
		if(!point2)
			point2 = TwoPairs(szBuf2) ;

#if 0		
		if(point1 == TWO_PAIRS)
			printf("Two Pairs : %s\n", szBuf1) ;
		if(point2 == TWO_PAIRS)
			printf("Two Pairs : %s\n", szBuf2) ;
#endif


		// One pair
		if(!point1)
			point1 = OnePair(szBuf1) ;
		if(!point2)
			point2 = OnePair(szBuf2) ;

#if 0		
		if(point1 == ONE_PAIR)
			printf("One Pair: %s\n", szBuf1) ;
		if(point2 == ONE_PAIR)
			printf("One Pair : %s\n", szBuf2) ;
#endif

		// High Card
		if(!point1)
			point1 = HighCard(szBuf1) ;
		if(!point2)
			point2 = HighCard(szBuf2) ;

#if 0		
		if(point1 == ONE_PAIR)
			printf("One Pair: %s\n", szBuf1) ;
		if(point2 == ONE_PAIR)
			printf("One Pair : %s\n", szBuf2) ;
#endif

		printf("%s - %s ", szBuf1, szBuf2) ;
		printf("\t[%d, %d]", point1, point2) ;


		if(point1 > point2)
		{
			printf("\tWIN~!!\n") ;
			win++ ;
		}
		else if(point1 == point2)
		{
			printf("\t\tDraw\n") ;
			draw++ ;
		}
		else if(point1 < point2)
		{
			printf("\t\t\tYou Lose.\n") ;
			lose++ ;
		}
		else
			printf("--------------------------------\n") ;
	}

	printf("====================================\n") ;
	printf("win : %d\n", win) ;
	printf("draw : %d\n", draw ) ;
	printf("lose : %d\n", lose ) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
