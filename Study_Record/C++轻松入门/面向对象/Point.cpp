// Point.cpp: implementation of the CPoint class.
//
//////////////////////////////////////////////////////////////////////

#include "Point.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPoint::CPoint(int x,int y)			//�������Ĺ��캯��
{


	m_x = x;
	m_y = y;

}

void CPoint::copy(CPoint *point)
{

	m_x = CPoint->m_x;			//ͨ������ָ����ʸö������ݳ�Ա����ֵ
	m_y = CPoint->m_y;			//�����ó�Ա�����Ķ�������ݳ�Ա

}


void CPoint::disp()
{
	
}

CPoint::~CPoint()
{

}
