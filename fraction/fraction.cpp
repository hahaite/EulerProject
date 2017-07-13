#include "fraction.h"

#include <cmath>

CFraction::CFraction()
{

}

CFraction::~CFraction()
{

}

void CFraction::contFraction_SquaredRoot(int nRoot, list<int>* listInt, int size, int flagReverse)
{
	//         ra + c
	//    d + ---------
	//            b

	int a, b, c, d ;
	int square = 2 ;

	while(1)
	{
		if(nRoot == square * square)
			return ;

		square++ ;

		if(sqrt(nRoot) < square)
			break ;
	}

	listInt->clear() ;

	a = nRoot ;
	b = 1 ;

	d = sqrt(a) ;
	c = -d ;

	listInt->push_back(d) ;

	for(int jj = 0; jj < size; jj++)
	{
		d = b / ((sqrt(a) + c)) ;
		b = (a - (c*c)) / b ;
		c = -c - (b * d) ;

		if(flagReverse)
			listInt->push_front(d) ;
		else
			listInt->push_back(d) ;

	}	

#if 0
	printf("%d ==>> ", ii) ;
	for(int aa = 0; aa < 30; aa++)
	{
		printf("%2d ", repeat[aa]) ;	
	}
	printf("\n") ;
#endif

	return ;
}

Fraction CFraction::add(Fraction* a, Fraction* b)
{
	// numerator / denominator

	m_frac.deno = a->deno * b->deno ;
	m_frac.nume = (a->nume * b->deno) + (a->deno * b->nume) ;

#if 0
	int check = 2 ;
	int min = (m_frac.nume <= m_frac.deno) ? m_frac.nume : m_frac.deno ;
	min /= 2 ;
	while(1)
	{

		if((m_frac.nume % check == 0) && (m_frac.deno % check == 0))
		{
			m_frac.nume /= check ;
			m_frac.deno /= check ;
			continue ;
		}

		check++ ;
		if(check & 0x02 == 0)
			check++ ;

		if(check >=  min)
			break ;
	}
#endif

	return m_frac ;
}

Fraction CFraction::add(int a, Fraction* b)
{
	Fraction fracA = {a, 1} ;

	return add(&fracA, b) ;

}


Fraction64 CFraction::add(Fraction64* a, Fraction64* b)
{
	// numerator / denominator

	m_frac64.deno = a->deno * b->deno ;
	m_frac64.nume = (a->nume * b->deno) + (a->deno * b->nume) ;

#if 0
	long long check = 2LL ;
	long long min = (m_frac.nume <= m_frac.deno) ? m_frac.nume : m_frac.deno ;
	min /= 2LL ;

	while(1)
	{

		if((m_frac64.nume % check == 0LL) && (m_frac64.deno % check == 0LL))
		{
			m_frac64.nume /= check ;
			m_frac64.deno /= check ;
			continue ;
		}

		check++ ;
		if(check & 2LL == 0LL)
			check++ ;

		if(check >=  min)
			break ;
	}
#endif

	return m_frac64 ;

}


Fraction64 CFraction::add(int a, Fraction64* b)
{
	Fraction64 fracA = {a, 1LL} ;

	return add(&fracA, b) ;
}
