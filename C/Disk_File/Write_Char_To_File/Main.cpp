#include "stdio.h"
#include "process.h"

void main()
{

	FILE *fp;		//�����ļ�ָ��
	char c;			


	printf("test\n");

	if ((fp=fopen("test.txt","w"))==NULL)		//���ļ�
	{

		printf("�ļ���ʧ�� \n");

		exit(1);

	}
	else
	{

		c = 'H';
		fputc(c,fp);
		c = 'E';
		fputc(c,fp);
		c = 'L';
		fputc(c,fp);
		c = 'L';
		fputc(c,fp);
		c = 'O';
		fputc(c,fp);
		fclose(fp);
	}
}
