#include <iostream.h>
struct student {			//����struct student�ṹ

	long id;
	char name[10];
	char sex;
	int age;
	float score;

};

typedef struct student STUDENT;		//������������

STUDENT sdArray[5] =  {{800123,"LiMin",'M',16,89.5},{800124,"ZengLu",'F',16,96.5},
{800125,"WuMeiMei",'F',16,80.5},{800126,"WangLei",'M',17,88.5},{800127,"SunDong",'M',15,66}
					};

bool findStudent(long id,int &index);		//���Һ�������
void disp(int index);					//��ʾ��������

void JieGouType()
{

	STUDENT sd;		//����ṹ����
	cout<<"������ѧ����ѧ��:";
	cin>>sd.id;
	cout<<"������ѧ��������:";
	cin>>sd.name;
	cout<<"������ѧ�����Ա�:";
	cin>>sd.sex;
	cout<<"������ѧ��������:";
	cin>>sd.age;
	cout<<"������ѧ���ĳɼ�:";
	cin>>sd.score;
	cout<<"ѧ��\t����\t�Ա�\t����\t�ɼ�"<<endl;
						//���ʽṹ��Ա��������
	cout<<sd.id<<"\t"<<sd.name<<"\t"<<sd.sex<<"\t"<<sd.age<<"\t"<<sd.score<<endl;

}
bool findStudent(long id,int &index)
{

	for (int i = 0;i<5;i++)
	{

		if (sdArray[i].id == id)
		{

			index = i;			//��ͬ�͸�ֵ��index
			return true;
		}

	}
	return false;

}
void disp(int index)
{

	cout<<"ѧ��\t����\t�Ա�\t����\t�ɼ�"<<endl;
	cout<<sdArray[index].id<<"\t"<<sdArray[index].name<<"\t"<<sdArray[index].sex<<"\t"<<sdArray[index].age<<"\t"<<sdArray[index].score<<endl;

}
void JieGouArray()
{
//�ṹ���͵������ָ��

	long id = 0;
	int index = 0;
	cout<<"������ѧ��";
	cin>>id;
	if (findStudent(id,index))			//����ѧ����ͬ��
	{
	
			disp(index);	

	}
	else
	{

			cout<<"û�и�ѧ����ؼ�¼"<<endl;

	}


}
void JieGouPoint()
{
//�ṹָ��
	
	STUDENT *p = NULL;		//�����ṹָ��
	STUDENT sd = {800123,"LiMin",'M',16,89.5};	//���ṹ������ֵ
	p = &sd;
	p->age = 18;
	p->score = 86.5;
	
	cout<<"ѧ��\t����\t�Ա�\t����\t�ɼ�"<<endl;
	cout<<p->id<<"\t"<<p->name<<"\t"<<p->sex<<"\t"<<p->age<<"\t"<<p->score<<endl;

}



void main()
{

	JieGouArray();

}