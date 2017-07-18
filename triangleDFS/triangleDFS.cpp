#include "triangleDFS.h"

#include <cstdio>

#define LEFT 	0x01
#define RIGHT 	0x02

#define MOVE_FIRST_CHILD 	0X04
#define MOVE_SECOND_CHILD 	0X05
#define MOVE_PARENT 		0X06

using namespace std ;

int CTriangleDFS::init(int width)
{
	m_max = width ;

	m_status = MOVE_FIRST_CHILD ;
	m_row = 0 ;
	m_col = 0 ;

	m_data.clear() ;
	m_direct.clear() ;
	m_value.clear() ;

	m_direct.assign(width, LEFT) ;

	m_data.assign(width, vector<int>(width, 0)) ;

	for(int ii = 0; ii < m_max; ii++)
	{
		for(int jj = 0; jj <= ii; jj++)
			m_data[ii][jj] = jj ;
	}

	m_value.assign(width, 0) ;

	return 1 ;
}

int CTriangleDFS::getNext(int* pList)
{
	if(m_row  == m_max-1 && m_col == m_max-1)
		return 0 ;

	int ii ;
	int flagBreak = 0 ;

	while(1)
	{
		if(flagBreak)
			break ;

		switch(m_status)
		{
		case MOVE_FIRST_CHILD :
			m_row++ ;
			m_value[m_row] = m_data[m_row][m_col] ;
			m_direct[m_row - 1] = LEFT ;

			m_status = (m_row < m_max-1) ? MOVE_FIRST_CHILD : MOVE_SECOND_CHILD ;

			if(m_row == m_max-1)
			{
				for(ii = 0; ii <= m_row ; ii++)
					pList[ii] = m_value[ii] ;	
				return 1 ;
			}
			break ;

		case MOVE_SECOND_CHILD :
			m_col++ ;
			m_value[m_row] = m_data[m_row][m_col] ;

			m_direct[m_row - 1] = RIGHT ;
			m_status = (m_row < m_max-1) ?  MOVE_FIRST_CHILD : MOVE_PARENT ;

			if(m_row == m_max-1)
			{
				for(ii = 0; ii <= m_row ; ii++)
					pList[ii] = m_value[ii] ;	
				return 1 ;
			}
			break ;

		case MOVE_PARENT :
			if(m_direct[m_row-1] == RIGHT)
				m_col-- ;
			m_row-- ;

			if(m_row == 0)
			{
				m_status = MOVE_SECOND_CHILD ;
				m_row++ ;
				break ;
			}

			m_status = (m_direct[m_row-1] == LEFT) ?  MOVE_SECOND_CHILD : MOVE_PARENT ;
			break ;
		}
	}

	return 0 ;
}


int CTriangleDFS::destroy()
{
	m_data.clear() ;
	m_direct.clear() ;
	m_value.clear() ;

	return 1 ;
}


