#include <iostream.h>


void luojiyu()
{

	int health = 0;
	int number = 0;
	int school = 0;
	cout << "������ѧ���ɼ�:";
	cin >> number;
	cout << "������ѧ������״̬��(����1)��������(0)��";
	cin >> health;
	cout<<"������ѧ���Ƿ���и���ѧ������(1)��û��(0)��";
	cin>>school;
	if (health && school && (number > 500))
	{

		cout<<"����¼ȡ"<<endl;

	}
	else
	{

		cout<<"������¼ȡ"<<endl;

	}


}
void luojihuo()
{
	int health = 0;
	int number = 0;
	int school = 0;
	int suit = 0,exce = 0;
	cout<<"�������Ƿ��س�������(1),��(0)��";
	cin>>suit;
	cout<<"�������Ƿ���������(1),��(0)��";
	cin>>exce;
	if (suit || exce)
	{


		cout<<"����¼ȡ"<<endl;

	}
	else
	{

			
			cout << "������ѧ���ɼ�:";
			cin >> number;
			cout << "������ѧ������״̬��(����1)��������(0)��";
			cin >> health;
			cout<<"������ѧ���Ƿ���и���ѧ������(1)��û��(0)��";
			cin>>school;
			if (health && school && (number > 500))
			{

				cout<<"����¼ȡ"<<endl;

			}
			else
			{

				cout<<"������¼ȡ"<<endl;

			}


	}


}

void sanyuanyunsuanfu()
{

	int i = 10,j = 15, n = 0;
	n = i>j?i++:++j;
	cout<<"i="<<i<<"\tj="<<j<<"\tn="<<n<<endl;
	n = i-j?i+j:i-10?j:i;
	cout<<"i="<<i<<"\tj="<<j<<"\tn="<<n<<endl;
	

}

void main()
{
	

	sanyuanyunsuanfu();

}