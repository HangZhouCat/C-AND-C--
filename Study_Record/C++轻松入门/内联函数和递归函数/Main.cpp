#include <iostream.h>
inline int intPower(int x);			//����һ����������intPower
int gcdt(int x,int y);
int factorial(int x);

void neilianhanshu()
{


	for (int n =1;n<=10;n++)
	{

		int m = intPower(n);		//������������intPower
		cout<<n<<"��ƽ����:"<<m<<endl;

	}


}

inline int intPower(int x)			//������������intPower
{


	return x*x;

}

void zhijiediguihanshu()
{

		int n = gcdt(20,6);
		cout<<"���Լ��Ϊ:"<<n<<endl;

}
int gcdt(int x,int y)
{


	if (x%y==0)
	{

		return y;

	}

	return gcdt(y,x%y);		//�ٴε���gcdt��������		//ֱ�ӵݹ����

}

void jianjiediguidiaoyong()
{



	int n,m;
	cout<<"������һ����";
	cin>>n;
	if (n>=0 &&  0 <= 20)
	{

		m = factorial(n);			//������׳˺���
		cout<<n<<"!="<<m<<endl;

	}
	else
	{

		cout<<"�������ֵ�Ƿ�!"<<endl;


	}


}

int factorial(int x)
{


	int t;
	if (x==0)
	{

			 t = 1;

	}
	else
	{


		t = x * factorial(x-1);

	}
	return t;

}


void main()
{

		jianjiediguidiaoyong();

}