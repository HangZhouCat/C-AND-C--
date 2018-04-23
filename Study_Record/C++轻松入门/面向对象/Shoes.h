// Shoes.h: interface for the CShoes class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOES_H__D95E3FEA_0CFB_4F1B_A784_47D7173DBF8C__INCLUDED_)
#define AFX_SHOES_H__D95E3FEA_0CFB_4F1B_A784_47D7173DBF8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CShoes  
{
public:
	CShoes();			//Ĭ�ϵĹ��캯��CShoes()
	CShoes (int s,char* strColor);		//�������Ĺ��캯��
	CShoes (const CShoes &s);			//�������캯��
	virtual ~CShoes();
	int getSize();
	char* getColor();
private:
	int size;
	char color[10];
};

#endif // !defined(AFX_SHOES_H__D95E3FEA_0CFB_4F1B_A784_47D7173DBF8C__INCLUDED_)
