#include <iostream.h>
void Fibonacci()
{
//��������Fibonacci����
	int i = 0;
	int f[20] = {1,1};
	for (i = 2;i < 20;i++)
	{

		f[i] = f[i-2] + f[i-1];		//����Ľṹ����ǰ����ֻ��
		

	}
	for (i = 0;i < 20; i++)
	{

		if (i%5 == 0)			//�ж��Ƿ����5
		{

				cout<<endl;			//ÿ����ַ����1������

		}
		cout<<f[i]<<" ";			//��������ÿ1Ԫ��

	}
}
void disp(int nArray[],int len)
{
//��������Ϊ������������
	for (int i = 0;i<len;i++)
	{

		nArray[i] = 0;			//��nArray��ÿ��Ԫ�ر��0

	}
}
void Array_arg_fun()
{
	
	int nArray[] = {10,20,30,40};
	int i = 0;
	disp(nArray,4);
	for (i = 0;i < 4;i++)
	{
		cout<<nArray[i]<<",";		//�������
	}
	cout<<endl;

}
void main()
{
	int nArray[10] ;
	int n = sizeof(nArray) / sizeof(nArray[0]);
	cout<<n;

}