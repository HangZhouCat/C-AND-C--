#include <iostream.h>
void Point_Level1()
{
//ָ�������ʹ��
	int n = 10;
	int *pn = &n;
	cout<<"n="<<n<<endl;
	cout<<"pnָ���ֵΪ:"<<*pn<<endl;
	n += 25;		
	cout<<"n="<<n<<endl;
	cout<<"pnָ���ֵΪ:"<<*pn<<endl;
	*pn = *pn * 10;
	cout<<"n="<<n<<endl;
	cout<<"pnָ���ֵΪ:"<<*pn<<endl;
}
void Point_Level2()
{
//ָ��ָ�������ָ��
	int n = 10,i= 18;
	int *pn = &n;
	int **pp = &pn;
	cout<<"n="<<n<<endl;
	cout<<"pn="<<pn<<endl;
	cout<<"*pn="<<*pn<<endl;
	cout<<"pp="<<pp<<endl;
	**pp = 5;			//�൱�ڶ�n�Ĳ���
	cout<<"n="<<n<<endl;
	*pp = &i;		//�ı�pp�е�ֵ������ָ�����i
	cout<<"pn="<<pn<<endl;		//pn����i�ĵ�ֵַ
	cout<<"*pn="<<*pn<<endl;
}
void Point_Add_Sub()
{
//ָ������ļӼ�����
	int array[5] = {1,2,3,4,5},n = 1;
	int *p	= &array[0];
	for (int i = 0;i < 5;i++)
	{

		cout<<"p�еĵ�ַΪ��"<<p<<"\t����ֵΪ:"<<*p<<endl;
		p = p + n;

	}


}
void Point_Array_1()
{
//��������������׵�ַ
	int array[5] = {1,2,3,4,5};
	int *p = &array[0];
	cout<<"p="<<p<<endl;
	cout<<"array="<<&array<<endl;


}
void Point_Array_2()
{
//��ָ��ı�������Ԫ�ص�ֵ
	int array[5] = {1,3,5,7,9};
	int *p = array;		//��ָ��ָ��array
	for (int i = 0;i < 5;i++)
	{

		*(p+i) = i * 2;		//��ָ��ָ���Ԫ�ر��ż��
		cout<<array[i]<<" ";

	}
	cout<<endl;


}

void Point_Array_3()
{
//һά������Ԫ�ص�ָ���ʾ��
	
	int array[5] = {1,2,3,4,5};
	for (int i = 0;i < 5;i++)
	{


			cout<<"array["<<i<<"]="<<array[i]<<endl;
			cout<<"*(array+"<<i<<")="<<*(array+i)<<endl;		

	}


}
void Point_Array_4()
{
//�ַ�������ַ�ָ��
	char *pStr = NULL;		//��ʼ��Ϊ��
	char str[] = "this is C++ programe";		//��ʼ���ַ�����
	pStr = "this is C++ program";		//��ֵ���ַ�ָ��
	cout<<"pstr="<<pStr<<endl;
	cout<<"str="<<str<<endl;


}
void Point_Const()
{
//����ı䳣��ָ��ָ������ݵ�ֵ
	int i = 8;
	int n = 18;
	const int *p = &i;		//����ָ��ָ�����i
//	*p = 28;			//�޸ĳ���ָ��ָ������ݵ�ֵ�������������
	cout<<*p<<endl;


}
void Point_Const1()
{
//��ȷ�ı䳣��ָ��ָ�������ֵ��ָ���ַ
	int i = 8;
	int n = 18;
	const int *p = &i;
	i = 28;
	


}

void main()
{


	Point_Array_4();


}