// Shoes.cpp: implementation of the CShoes class.
//
//////////////////////////////////////////////////////////////////////
#include <iostream.h>
#include <string.h>
#include "Shoes.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CShoes::CShoes()
{
//Ĭ�Ϲ��캯����ʵ��
	strcpy(color,"��ɫ");
	size = 40;			//��ʼ�����ݳ�Աsize

}

CShoes::CShoes (int s,char* strColor)
{
//�������Ĺ��캯����ʵ��
	strcpy(color,strColor);			//��ʼ�����ݳ�ԱstrColor
	size = s;						//��ʼ�����ݳ�Աsize
}

CShoes::CShoes (const CShoes &s)			
{
//�������캯����ʵ��
	strcpy(color,s.color);
	size = s.size;

}

CShoes::~CShoes()
{
	size = 0;
	cout<<"���ٶ���"<<endl;


}

int CShoes::getSize()
{
	return size;
}
char* CShoes::getColor()
{
	return color;
}