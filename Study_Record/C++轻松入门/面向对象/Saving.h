#ifndef __SAVING_H__
#define __SAVING_H__
#include <iostream.h>
class CSaving
{

	int accoundId;			//���ݳ�Ա �˺�
	int balance;			//���ݳ�Ա ���
	

public:
	void init(int n=10000);		//��ʼ��
	void saving(float money);		//��Ա����  ��Ǯ
	void saving(float money1,float money2);		//saving��������
	void assume(float money);		//��Ա����	ȡǮ

	
	void disp();					//��Ա����	��ӡ




protected:
private:
};
#endif