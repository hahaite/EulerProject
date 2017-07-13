#include <cstdio>
#include <sys/time.h>

#include <list>
#include <algorithm>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	list<pair<int, int> >	   listVal ;
	list<pair<int, int> >::iterator listValIter ;
	list<pair<int, int> >::iterator listValIter2 ;

	int n = 0 ;
	int val ;

	for(int ii = 3; ii <= 8; ii++)
	{

		n = 0 ;
		while(1)
		{
			n++ ;

			val = (ii == 3) ? n*(n+1)/2     : val ;
			val = (ii == 4) ? n*n	   : val ;
			val = (ii == 5) ? n*(3*n-1)/2   : val ;
			val = (ii == 6) ? n*(2*n-1)     : val ;
			val = (ii == 7) ? n*(5*n-3)/2   : val ;
			val = (ii == 8) ? n*(3*n-2)     : val ;

			if(val < 1000)
				continue ;

			if(val > 9999 )
				break ;

			if(val % 100 < 10)
				continue ;

			listVal.push_back(make_pair(ii, val)) ;
		}
	}
	printf("size : %d\n", listVal.size()) ;



	int suffix ;
	int prefix ;
	int flagFind ;

	listValIter = listVal.begin() ;
	while(1)
	{
		flagFind = 0 ;
		suffix = listValIter->second % 100 ;

		listValIter2 = listVal.begin() ;
		for(; listValIter2 != listVal.end(); listValIter2++)
		{
			if(listValIter2->first == listValIter->first)
				continue ;

			if(suffix == (listValIter2->second / 100))
			{
				flagFind = 1 ;
				break ;
			}
		}

		if(!flagFind)
			listValIter = listVal.erase(listValIter) ;
		else
			listValIter++ ;

		if(listValIter == listVal.end())
			break ;

	}
	printf("size : %d\n", listVal.size()) ;


	listValIter = listVal.begin() ;
	while(1)
	{
		flagFind = 0 ;
		prefix = listValIter->second / 100 ;

		listValIter2 = listVal.begin() ;
		for(; listValIter2 != listVal.end(); listValIter2++)
		{
			if(listValIter2->first == listValIter->first)
				continue ;

			if(prefix == (listValIter2->second % 100))
			{
				flagFind = 1 ;
				break ;
			}
		}

		if(!flagFind)
			listValIter = listVal.erase(listValIter) ;
		else
			listValIter++ ;

		if(listValIter == listVal.end())
			break ;

	}
	printf("size : %d\n", listVal.size()) ;

	list<int>	       list3 ;
	list<int>	       list4 ;
	list<int>	       list5 ;
	list<int>	       list6 ;
	list<int>	       list7 ;
	list<int>	       list8 ;
	list<int>*	      pList ;

	list<int>::iterator     listIter3 ;
	list<int>::iterator     listIter4 ;
	list<int>::iterator     listIter5 ;
	list<int>::iterator     listIter6 ;
	list<int>::iterator     listIter7 ;
	list<int>::iterator     listIter8 ;

	listValIter = listVal.begin() ;
	for(; listValIter != listVal.end(); listValIter++)
	{
		pList = (listValIter->first == 3) ? &list3 : pList ;
		pList = (listValIter->first == 4) ? &list4 : pList ;
		pList = (listValIter->first == 5) ? &list5 : pList ;
		pList = (listValIter->first == 6) ? &list6 : pList ;
		pList = (listValIter->first == 7) ? &list7 : pList ;
		pList = (listValIter->first == 8) ? &list8 : pList ;

		pList->push_back(listValIter->second) ;
	}


	int permu[5] = {4, 5, 6, 7, 8} ;

	list<int>*	      pList4 ;
	list<int>*	      pList5 ;
	list<int>*	      pList6 ;
	list<int>*	      pList7 ;
	list<int>*	      pList8 ;

	int sum = 0 ;


	while(1)
	{
		listIter3 = list3.begin() ;
		for(; listIter3 != list3.end(); listIter3++)
		{
			pList4 = (permu[0] == 4) ? &list4 : pList4 ;
			pList4 = (permu[0] == 5) ? &list5 : pList4 ;
			pList4 = (permu[0] == 6) ? &list6 : pList4 ;
			pList4 = (permu[0] == 7) ? &list7 : pList4 ;
			pList4 = (permu[0] == 8) ? &list8 : pList4 ;

			listIter4 = pList4->begin() ;
			for(; listIter4 != pList4->end(); listIter4++)
			{
				if(*listIter3 % 100 != *listIter4 / 100)
					continue ;

				pList5 = (permu[1] == 4) ? &list4 : pList5 ;
				pList5 = (permu[1] == 5) ? &list5 : pList5 ;
				pList5 = (permu[1] == 6) ? &list6 : pList5 ;
				pList5 = (permu[1] == 7) ? &list7 : pList5 ;
				pList5 = (permu[1] == 8) ? &list8 : pList5 ;

				listIter5 = pList5->begin() ;
				for(; listIter5 != pList5->end(); listIter5++)
				{
					if(*listIter4 % 100 != *listIter5 / 100)
						continue ;

					pList6 = (permu[2] == 4) ? &list4 : pList6 ;
					pList6 = (permu[2] == 5) ? &list5 : pList6 ;
					pList6 = (permu[2] == 6) ? &list6 : pList6 ;
					pList6 = (permu[2] == 7) ? &list7 : pList6 ;
					pList6 = (permu[2] == 8) ? &list8 : pList6 ;

					listIter6 = pList6->begin() ;
					for(; listIter6 != pList6->end(); listIter6++)
					{
						if(*listIter5 % 100 != *listIter6 / 100)
							continue ;

						pList7 = (permu[3] == 4) ? &list4 : pList7 ;
						pList7 = (permu[3] == 5) ? &list5 : pList7 ;
						pList7 = (permu[3] == 6) ? &list6 : pList7 ;
						pList7 = (permu[3] == 7) ? &list7 : pList7 ;
						pList7 = (permu[3] == 8) ? &list8 : pList7 ;

						listIter7 = pList7->begin() ;
						for(; listIter7 != pList7->end(); listIter7++)
						{
							if(*listIter6 % 100 != *listIter7 / 100)
								continue ;

							pList8 = (permu[4] == 4) ? &list4 : pList8 ;
							pList8 = (permu[4] == 5) ? &list5 : pList8 ;
							pList8 = (permu[4] == 6) ? &list6 : pList8 ;
							pList8 = (permu[4] == 7) ? &list7 : pList8 ;
							pList8 = (permu[4] == 8) ? &list8 : pList8 ;

							listIter8 = pList8->begin() ;
							for(; listIter8 != pList8->end(); listIter8++)
							{
								if(*listIter7 % 100 != *listIter8 / 100)
									continue ;

								if(*listIter8 % 100 != *listIter3 / 100)
									continue ;

								printf("FIND~!!!!! - %d %d %d %d %d %d\n",
									*listIter3,
									*listIter4,
									*listIter5,
									*listIter6,
									*listIter7,
									*listIter8) ;

								sum += *listIter3 ;
								sum += *listIter4 ;
								sum += *listIter5 ;
								sum += *listIter6 ;
								sum += *listIter7 ;
								sum += *listIter8 ;

								printf("Result : %d\n", sum) ;
							}
						}
					}
				}
			}
		}

		if(!next_permutation(&permu[0], &permu[5]))
			break ;
	}

	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
