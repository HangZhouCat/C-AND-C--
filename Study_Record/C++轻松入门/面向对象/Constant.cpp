// Constant.cpp: implementation of the CConstant class.
//
//////////////////////////////////////////////////////////////////////

#include "Constant.h"
#include <iostream.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

//CConstant::CConstant(int x,int y)
//{
//	m_x = x;
//	m_y = y;
//
//}

CConstant::CConstant (int n):nNum(n),rNum(nNum)
{
//ͨ����ʼ���б�����ʼ�������ݳ�Ա
	cout<<nNum<<":"<<rNum<<endl;

}
CConstant::~CConstant()
{

}
void CConstant::disp()
{
	
	cout<<"x="<<m_x<<"***y="<<m_y<<endl;


}

void CConstant::disp() const
{
//����Ա����ʵ��
	cout<<"x="<<m_x<<"$$$y="<<m_y<<endl;

}
