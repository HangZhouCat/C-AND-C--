#include <iostream.h>
#include <vector>
using namespace std;	//ʹ�����ֿռ�std

void vector_add_element()
{
//����Ԫ�ص�����
	vector <int> vec;
	vec.push_back(10);
	vec.push_back(20);


}
void vector_del_element()
{
//����Ԫ�ص�ɾ��
	vector <int> vec;
	int i = 0;
	for (i = 0; i < 10; i++)
	{

		vec.push_back(i);			//��������

	}
	cout<<"���Ӻ��Ԫ�ظ���:"<<vec.size()<<endl;
	for (i = 0;i < 5;i++)
	{

		vec.pop_back();				//ɾ��Ԫ��

	}
	cout<<"ɾ�����Ԫ�ظ���:"<<vec.size()<<endl;
	for (i = 0;i < vec.size();i++)
	{

		cout<<vec[i]<<",";		//������������е�Ԫ��

	}
	cout<<endl;

}
void vector_vist_element()
{
//����Ԫ�صķ���
	vector <int> vec;
	int i = 0;
	for (i = 0;i < 10;i++)
	{


		vec.push_back(i);		//������Ԫ��

	}
	for (i = 0; i < vec.size(); i++)
	{

	
		 cout<<vec[i]<<",";		//������Ԫ��

	}
	cout<<endl;
	
}
void vector_demo()
{
//����������Ӧ��
	int i = 0 ;
	vector <long> vec_f;			//����vector����
	int max = 0;
	cout<<"������������:"<<endl;
	cin>>max;
	vec_f.push_back(1);				//�Ȱ�ǰ�������
	vec_f.push_back(1);
	for (i = 2;i < max;i++)
	{


		vec_f.push_back(vec_f[i-2] + vec_f[i-2]);
		

	}
	for (i = 0;i < vec_f.size(); i++)
	{


		cout<<vec_f[i]<<",";			//��������е�ÿһԪ��

	}
	cout<<"\nɾ��������У�"<<endl;
	for (i = 0;i < 5;i++)
	{

		vec_f.pop_back();			//ɾ�������е�Ԫ��

	}
	for (i = 0; i < vec_f.size(); i ++)
	{


		cout<<vec_f[i]<<",";			//��������е�ÿһԪ��

	}
	cout<<endl;

}
void main()
{

		vector_demo();

}
