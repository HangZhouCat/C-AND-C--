#include <iostream.h>
#include <math.h>
#include <string.h>

void GetStrLen()
{
//��ȡ�ַ������Ⱥ��� 
	
	char str1[] = "good morning!";			//��ʼһ���ַ�����
	char *pStr = "hello word!";				//����һ���ַ���ָ��
	char str2[80];							//����һ���ַ�����
	cout<<"�������ַ���:";
	cin>>str2;								//��������ַ�������str2������
	cout<<strlen("aabbccddee")<<endl;		//���ָ���ַ����ĳ���
	cout<<"str1 �ĳ�����:"<<strlen(str1)<<endl;
	cout<<"pStr �ĳ�����:"<<strlen(pStr)<<endl;
	cout<<"str2 �ĳ�����:"<<strlen(str2)<<endl;


}
void StrCopy()
{
//�ַ������ƺ���

	char str1[10],str2[10];
	char str3[] = "hello";
	


}
void StrConcat()
{
//�ַ������Ӻ���

}
void StrCompare()
{
//�ַ����ȽϺ���


}

void main()
{

	GetStrLen();

}