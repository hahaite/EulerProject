#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <list>

using namespace std ;

struct Fraction
{
	int nume ; 	// numerator
	int deno ; 	// denominator
};

struct Fraction64
{
	long long nume ; 	// numerator
	long long deno ; 	// denominator
};

class CFraction
{
public :
	CFraction() ;
	~CFraction() ;

	// Continued Fraction - Squared Root
	// When you want get sqrt(23), the value is as below.
	// nRoot = 23
	// listInt is 4, 1, 3, 1, 8, 1, 3, 1, 8....
	// first 4 is a0.
	// size is listInt's size.
	void contFraction_SquaredRoot(int nRoot, list<int>* listInt, int size, int flagReverse = 0) ;


	Fraction setFraction(int nume, int deno)
	{
		m_frac.nume = nume ;
		m_frac.deno = deno ;
		return m_frac ;
	};

	void setFraction(Fraction* frac, int nume, int deno)
	{
		frac->nume = nume ;
		frac->deno = deno ;
		return ;
	};

	Fraction64 setFraction(long long nume, long long deno)
	{
		m_frac.nume = nume ;
		m_frac.deno = deno ;
		return m_frac64 ;
	};

	void setFraction(Fraction64* frac, long long nume, long long deno)
	{
		frac->nume = nume ;
		frac->deno = deno ;
		return ;
	};


	Fraction add(Fraction* a, Fraction* b) ;
	Fraction add(int a, Fraction* b) ;

	Fraction64 add(Fraction64* a, Fraction64* b) ;
	Fraction64 add(int a, Fraction64* b) ;

	void reverse(Fraction* frac)
	{
		m_temp = frac->nume ;
		frac->nume = frac->deno ;
		frac->deno = m_temp ;	
		return ;
	};

	void reverse(Fraction64* frac)
	{
		m_temp64 = frac->nume ;
		frac->nume = frac->deno ;
		frac->deno = m_temp64 ;	
		return ;
	};


private :

public :

private :
	Fraction m_frac ;
	Fraction64 m_frac64 ;

	int m_temp ;
	long long m_temp64 ;

};


#endif
