#include <stdio.h>

void main(void)
{


		int a = 10;
		char b = 'x';
		short c = 3;
		float d = 3.14;
		double e = 6.12345;
		long f = 1234;
		__int64 g = 1234;		//��long long ����һ��Ч��  ֻ����VC6.0�в�֧��long long ��������

		
		
		int num;
		


		num = sizeof(a);
		printf("int a %d\n",num);


		num = sizeof(b);
		printf("char b %d\n",num);

		num = sizeof(c);
		printf("short c %d\n",num);

		num = sizeof(d);
		printf("float d %d\n",num);

		num = sizeof(e);
		printf("double e %d\n",num);

		num = sizeof(f);
		printf("long f %d\n",num);

		num = sizeof(g);
		printf("__int64 g %d\n",num);

		getchar();


}