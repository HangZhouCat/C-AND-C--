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
	const int *p = &i;		//����ָ��ָ�����i
	i = 28;					//�ı䳣��i��ֵ
	cout<<*p<<endl;
	p = &n;					//�ѳ���ָ��pָ��n
	cout<<*p<<endl;
	


}
void Point_Const2()
{
//ָ�볣������ȷʹ�÷���
	int i = 8;
	int n = 8;
	int *const p = &i;		//����ָ�볣��p������ʼ��ָ�����i
	*p = 12;				//ͨ��ָ�볣�����ı���ָ��ı���i��ֵ
	cout<<*p<<endl;
	i = i + n;
	cout<<*p<<endl;

}
void Point_Fun_Swap(int *px,int *py)
{
//���彻������
	int temp = *px;
	*px = *py;
	*py = temp;
	
}
void Point_Fun()
{
//ָ����Ϊ����������������ֵ���н���
	
	int a = 88,b = 208;
	cout<<"a="<<a<<"\tb="<<b<<endl;
	Point_Fun_Swap(&a,&b);
	cout<<"a="<<a<<"\tb="<<b<<endl;

}
void Point_Array_Copy(int *pDst, const int *pSrc,int slen)
{

	for (int i = 0;i < slen;i++)
	{

		*pDst++ = *pSrc++;

	}

}
void Point_Array_Copy_disp(int *p,int len)
{

	
	for (int i=0;i<len;i++)
	{

		cout<<*(p+i)<<"";


	}

	cout<<endl;

}
void Point_Array_Copy_Main()
{

	int array1[20] = {0};



}
void main()
{


	Point_Fun();


}