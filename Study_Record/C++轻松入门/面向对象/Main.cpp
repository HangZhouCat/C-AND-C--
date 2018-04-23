#include "Saving.h"
#include "Test.h"
#include "Shoes.h"
#include "Constant.h"
void saving()
{
//�ö�����ʵ�������˻��Ĳ���
	CSaving s;		//����CSaving����s
	float money = 0;
	s.init();		//��ʼ������s
	cout<<"����������:";
	cin>>money;
	s.saving(money);		//���ö���ĳ�Ա����saving
	cout<<"������ȡ����:";
	cin>>money;
	s.assume(money);		//���ö���ĳ�Ա����assume
	s.disp();				//���ö���ĳ�Ա����disp



}
void saving_point()
{
//ʹ��ָ�������ʵ�ֲ��������˺�
	CSaving s;		//����CSaving����s
	CSaving *p = &s;		//��pָ�����s
	float money = 0;
	p->init();
	cout<<"����������:";
	cin>>money;

	p->saving(money);		//���ö���ĳ�Ա����saving
	cout<<"������ȡ����:";
	cin>>money;
	p->assume(money);		//���ö���ĳ�Ա����assume
	p->disp();				//���ö���ĳ�Ա����disp
}
void saving_2()
{
//������������ݳ�Աֵ�ǲ�ͬ��
	CSaving s1,s2;
	s1.init(10000);
	s2.init(20000);
	s1.saving(100);
	s2.saving(250);
	s1.assume(50);
	s2.assume(50);
	s1.disp();
	s2.disp();
}
void member_fun()
{
//����Ա�����Ĳ�������Ĭ��ֵ
	CTest t1,t2;
	t1.init();				//û�и�������ֵ��ʹ��Ĭ�ϲ���ֵ
	t2.init(5);
	cout<<t1.getSum()<<" "<<t2.getSum()<<endl;
}
void access_control()
{
//�����Ա���Ϸ��ʿ��Ʒ�
	CTest t;				//����CTest��Ķ���
	t.num = 10;				//�޸ĳ�Աnum��ֵ
	t.add(10);
	cout<<"t.num="<<t.num<<endl;

	t.setSum(521);			//ͨ�����еĺ������޸�����private����sum��ֵ

	cout<<"t.sum="<<t.dispSum()<<endl;		//ͨ�����еĺ���������private����sum��ֵ
	

}
void Constructor()
{
//���캯��Demo
	CShoes shoes;			//����Ĭ�Ϲ��캯��
	CShoes shoes1(38,"��ɫ");			//���ô������Ĺ��캯��
	CShoes shoes2(shoes1);				//�������캯��-----��shoes1��������ʼ��shoes2
	cout<<"Ь����ĳ�ʼ����Ϊ��"<<shoes.getSize()<<"��ɫΪ:"<<shoes.getColor()<<endl;
	cout<<"Ь����ĳ�ʼ����Ϊ��"<<shoes1.getSize()<<"��ɫΪ:"<<shoes1.getColor()<<endl;
	cout<<"Ь����ĳ�ʼ����Ϊ��"<<shoes2.getSize()<<"��ɫΪ:"<<shoes2.getColor()<<endl;
}
void Constant_Class()
{
//���еĳ�����
	CConstant t1(5);			//һ�����		
	const CConstant t2(8);		//������
	t1.disp();
	t2.disp();			//ͨ�������������ó���Ա����
}
void main()
{

	Constant_Class();

}