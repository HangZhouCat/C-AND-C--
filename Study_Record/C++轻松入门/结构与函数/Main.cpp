#include <iostream.h>
#include <string.h>
struct user 
{

	char name[10];
	int age;

};
struct man {

	char name[10];
	int age;
	char sex;

};

typedef struct user USER;			//�����½ṹ������
typedef struct man MAN;
MAN GetMan();			//���������䷵������ΪMAN
void disp(MAN *p);
void func(USER us);
void func1(USER *pUser);
void func2(USER &us);

void func(USER us)
{

  us.age += 2;
  strcpy(us.name, "HAHA");

}
void func1(USER *pUser)
{

	pUser->age += 2;
	strcpy(pUser->name,"HAHAHA");

}
void func2(USER &us)
{

	us.age += 2;
	strcpy(us.name,"HAHAHA");

}

void JieGouTransAddress()
{

	USER user1 = {"LILY",20	};
	func1(&user1);
	cout<<"����:"<<user1.name<<"����:"<<user1.age<<endl;


}

void JieGouTransValue()
{
//�ṹ�Ĵ���ֵ����

	USER user1 = {"LILY",20	};
	func(user1);
	cout<<"����:"<<user1.name<<"����:"<<user1.age<<endl;
}
void JieGouQuote()
{
//�ṹ�����õ���

	USER user1 = {"LILY",20	};
	func2(user1);
	cout<<"����:"<<user1.name<<"����:"<<user1.age<<endl;


}
void disp(MAN *p)
{

	cout<<" ����: "<<p->name<<" ����: "<<p->age<<" �Ա�: "<<p->sex<<endl;

}
MAN GetMan()
{

	MAN t;
	cout<<"��������˵����������䣬���Ա��м��ÿո�ָ�:";
	cin>>t.name>>t.age>>t.sex;		//�����û��������Ϣ
	return t;

}

void JieGouReturn()
{
//�ṹ��Ϊ����ֵ
	MAN manArray[3];			//����MAN�ṹ����
	for (int i=0;i<3;i++)
	{

		manArray[i] = GetMan();		//����GetMan��������
		disp(&manArray[i]);			//��ʾ

	}
	
}

void main()
{

	JieGouReturn();


}