#include <cstdio>
#include <sys/time.h>
#include <cmath>

using namespace std ;

int main()
{
	timeval tFirst ;
	timeval tSecond ;
	timeval tWorking ;
	gettimeofday(&tFirst, NULL) ;
	/////////////////////////////////////////////////////////////////////

	int ret = 0 ;
	int total = 0 ;

	for(int aa = 0; aa <= 1; aa++)
	{
		for(int bb = 0; bb <= 2; bb++)
		{
			for(int cc = 0; cc <= 4; cc++)
			{
				for(int dd = 0; dd <= 10; dd++)
				{
					for(int ee = 0; ee <= 20; ee++)
					{
						for(int ff = 0; ff <= 40; ff++)
						{
							for(int gg = 0; gg <= 100; gg++)
							{
								for(int hh = 0; hh <= 200; hh++)
								{
									ret = (aa * 200) +
										(bb * 100) +
										(cc * 50) +
										(dd * 20) +
										(ee * 10) +
										(ff * 5) +
										(gg * 2) +
										(hh * 1) ;

									if(ret == 200)
									{
//									      printf("(%d *200) + (%d *100) + (%d *50) + (%d *20) + (%d *10) + (%d *5) + (%d *2) + (%d *1)\n",
//										      aa, bb, cc, dd, ee, ff, gg, hh) ;
										total++ ;
									}
								}
							}
						}
					}
				}
			}
		}
	}

	printf("total : %d\n", total) ;


	/////////////////////////////////////////////////////////////////////
	gettimeofday(&tSecond, NULL) ;
	timersub(&tSecond, &tFirst, &tWorking) ;
	printf("Working Time : [%d.%06d]\n", tWorking.tv_sec, tWorking.tv_usec) ;

	return 1 ;
}
