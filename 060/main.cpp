#include <cstdio>
#include <sys/time.h>

#include <list>
#include <set>

#include "./../mymath/mymath.h"

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////


	const int KK = 5 ;

	list<int> 		listPrime ;
	list<int>::iterator 	listPrimeIter ;
	list<int>::iterator 	listPrimeIter2 ;
	list<int>::iterator 	listPrimeIter3 ;
	list<int>::iterator 	listPrimeIter4 ;
	list<int>::iterator 	listPrimeIter5 ;

	set<int>		setCheck ;
	set<int>::iterator      setCheckIter ;

	CPrime prime ;

//	prime.readQuantity(1200, &listPrime) ;

	for(int ii = 0; ii < 1200; ii++)
	{
		listPrime.push_back(prime.getNextPrime()) ;

	}


	listPrimeIter = listPrime.end() ;
	listPrimeIter-- ;
	printf("primeMax : %d\n", *listPrimeIter) ;

	string str1 ;
	string str2 ;
	string str3 ;
	string str4 ;
	string str5 ;

	string strRet[20] ;

	char szText[32] ;
	int nInt ;

	int ret ;
	int flagBreak ;

	CPrime primeObj ;


	listPrimeIter = listPrime.begin() ;
	listPrimeIter++ ;
	for(; listPrimeIter != listPrime.end(); listPrimeIter++)
	{
		sprintf(szText, "%d", *listPrimeIter) ;
		str1 = szText ;

		listPrimeIter2 = listPrimeIter ;
		listPrimeIter2++ ;
		for(; listPrimeIter2 != listPrime.end(); listPrimeIter2++)
		{
			sprintf(szText, "%d", *listPrimeIter2) ;
			str2 = szText ;

			strRet[0] = str1 + str2 ;
			strRet[1] = str2 + str1 ;

			flagBreak = 0;
			for(int ii = 0; ii < 2; ii++)
			{
				nInt = atoi(strRet[ii].c_str()) ;

				if(!primeObj.isPrime(nInt))
				{
					flagBreak = 1 ;
					break ;
				}
			}

			if(flagBreak)
				continue ;;

			// find 3
			listPrimeIter3 = listPrimeIter2 ;
			listPrimeIter3++ ;
			for(; listPrimeIter3 != listPrime.end(); listPrimeIter3++)
			{
				sprintf(szText, "%d", *listPrimeIter3) ;
				str3 = szText ;

				strRet[0] = str1 + str2 ;
				strRet[1] = str1 + str3 ;
				strRet[2] = str2 + str1 ;
				strRet[3] = str2 + str3 ;
				strRet[4] = str3 + str1 ;
				strRet[5] = str3 + str2 ;



				flagBreak = 0;
				for(int ii = 0; ii < 6; ii++)
				{
					nInt = atoi(strRet[ii].c_str()) ;

					if(!primeObj.isPrime(nInt))
					{
						flagBreak = 1 ;
						break ;
					}
				}

				if(flagBreak)
					continue ;;

//				printf("%s %s %s\n", str1.c_str(), str2.c_str(), str3.c_str()) ;

				// find 4
				listPrimeIter4 = listPrimeIter3 ;
				listPrimeIter4++ ;
				for(; listPrimeIter4 != listPrime.end(); listPrimeIter4++)
				{
					sprintf(szText, "%d", *listPrimeIter4) ;
					str4 = szText ;

					strRet[0] = str1 + str2 ;
					strRet[1] = str1 + str3 ;
					strRet[2] = str1 + str4 ;
					strRet[3] = str2 + str1 ;
					strRet[4] = str2 + str3 ;
					strRet[5] = str2 + str4 ;
					strRet[6] = str3 + str1 ;
					strRet[7] = str3 + str2 ;
					strRet[8] = str3 + str4 ;
					strRet[9] = str4 + str1 ;
					strRet[10] = str4 + str2 ;
					strRet[11] = str4 + str3 ;

					flagBreak = 0;
					for(int ii = 0; ii < 12; ii++)
					{
						nInt = atoi(strRet[ii].c_str()) ;

						if(!primeObj.isPrime(nInt))
						{
							flagBreak = 1 ;
							break ;
						}
					}

					if(flagBreak)
						continue ;;
//					printf("%s %s %s %s\n", str1.c_str(), str2.c_str(), str3.c_str(), str4.c_str()) ;

					// find 5
					listPrimeIter5 = listPrimeIter4 ;
					listPrimeIter5++ ;
					for(; listPrimeIter5 != listPrime.end(); listPrimeIter5++)
					{
						sprintf(szText, "%d", *listPrimeIter5) ;
						str5 = szText ;

						strRet[0] = str1 + str2 ;
						strRet[1] = str1 + str3 ;
						strRet[2] = str1 + str4 ;
						strRet[3] = str1 + str5 ;

						strRet[4] = str2 + str1 ;
						strRet[5] = str2 + str3 ;
						strRet[6] = str2 + str4 ;
						strRet[7] = str2 + str5 ;

						strRet[8] = str3 + str1 ;
						strRet[9] = str3 + str2 ;
						strRet[10] = str3 + str4 ;
						strRet[11] = str3 + str5 ;

						strRet[12] = str4 + str1 ;
						strRet[13] = str4 + str2 ;
						strRet[14] = str4 + str3 ;
						strRet[15] = str4 + str5 ;

						strRet[16] = str5 + str1 ;
						strRet[17] = str5 + str2 ;
						strRet[18] = str5 + str3 ;
						strRet[19] = str5 + str4 ;

						flagBreak = 0;
						for(int ii = 0; ii < 20; ii++)
						{
							nInt = atoi(strRet[ii].c_str()) ;
							if(!primeObj.isPrime(nInt))
							{
								flagBreak = 1 ;
								break ;
							}
						}

						if(flagBreak)
							continue ;;

						printf("%s %s %s %s %s\n", str1.c_str(), str2.c_str(), str3.c_str(), str4.c_str(), str5.c_str()) ;
						printf("Sum : %d\n", atoi(str1.c_str()) +
									atoi(str2.c_str()) +
									atoi(str3.c_str()) +
									atoi(str4.c_str()) +
									atoi(str5.c_str())) ;
					}
				}
			}
		}
	}


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
