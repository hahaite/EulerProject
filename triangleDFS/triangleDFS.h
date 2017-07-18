#ifndef _TRIANGLEDFS_H_
#define _TRIANGLEDFS_H_

#include <vector>

class CTriangleDFS
{
public :
	int init(int width) ;
	int getNext(int* pList) ;
	int destroy() ;

private :
	int loop() ;

public :

private :
	int m_width ;
	int m_max ;

	std::vector<std::vector<int> > 	m_data ;
	std::vector<int> 	m_direct ;
	std::vector<int> 	m_value ;

	
	int m_status ;
	int m_row ;
	int m_col ;

};

#endif

