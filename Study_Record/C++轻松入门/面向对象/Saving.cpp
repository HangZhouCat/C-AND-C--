#include "Saving.h"
void CSaving::init(int n){			//��ʼ��

		accoundId = 10000;
		balance = 0;
}
void CSaving::saving(float money){		//��Ա����  ��Ǯ

		balance += money;

}
void CSaving::saving(float money1,float money2)
{
	//���صĳ�Ա������ʵ��
	balance = balance + money1 + money2;
}
void CSaving::assume(float money){		//��Ա����	ȡǮ

		balance -= money;

}
void CSaving::disp(){					//��Ա����	��ӡ

		cout<<"�˺ţ�"<<accoundId<<endl;
		cout<<"���:"<<balance<<endl;

}