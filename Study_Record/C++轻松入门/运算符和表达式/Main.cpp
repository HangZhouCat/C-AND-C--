#include <iostream.h>
#include <conio.h>
void suanshuyunsuanfu()
{


	int num1,num2,num3,num4,num5;

	num1 = 3+8;
	num2 = 10-7;
	num3 = num2 * num1;	//�˷�����
	num4 = num3/5;		//��������
	num5 = num3%2;		//ȡ������

	cout<<"num1="<<num1<<"\n";
	cout<<"num2="<<num2<<"\n";
	cout<<"num3="<<num3<<"\n";
	cout<<"num4="<<num4<<"\n";
	cout<<"num5="<<num5<<"\n";


}
void zizengAndzijian()
{

	int a,b;
	a = 20,b=20;

	cout<<"a++ ="<< a++ <<endl;
	cout<<"++b ="<< ++b <<endl;
	



}
void weiyunsuanfu()
{

	int n = 7;
	int left_n = 0;
	left_n = n << 4;	//��n��ֵ7����4λ����112�ٸ�ֵ��left_n
	cout << "left_n=" <<left_n <<endl;
	


}
void guanxiyunsuanfu()
{

		char m = 'm';		//�ַ�m��109
		char n = 'n';		//�ַ�n��110
		int i = 0;
		i = m < n;			//110����109������i��ֵΪ1
		cout<<"i="<<i<<endl;
		i = (m==n-1);		//109����110-1������i��ֵΪ1
		cout<<"i="<<i<<endl;


}

void yinyongbianliang()
{
//���ñ���

	int num = 10;
	int &rNum = num;			//������rNum�ĳ�ʼ��
	rNum = 20;					//ʵ���Ǹı�num��ֵ
	int temp = rNum;			//��num��ֵ����temp
	cout<<"num="<<num<<"temp="<<temp<<endl;

}

void main()
{

	
	yinyongbianliang();

	
}


