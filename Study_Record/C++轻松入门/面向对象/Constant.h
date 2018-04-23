// Constant.h: interface for the CConstant class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONSTANT_H__45502B78_116F_458F_B9CC_FCD8B60B5787__INCLUDED_)
#define AFX_CONSTANT_H__45502B78_116F_458F_B9CC_FCD8B60B5787__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CConstant  
{
public:
 	CConstant (int n);
//	CConstant(int x,int y);
	void disp();
	void disp() const;			//����Ա���������Ƕ�disp������
	
	virtual ~CConstant();
private:
	int m_x;
	int m_y;
	const int& rNum;			//�����ݳ�Ա
	const int nNum;				//�����ݳ�Ա
};

#endif // !defined(AFX_CONSTANT_H__45502B78_116F_458F_B9CC_FCD8B60B5787__INCLUDED_)
