#include <stdio.h>
#include <winsock.h>

//���ر����ͷ�ļ��Ϳ��ļ�
#pragma comment(lib,"ws2_32")

//�Զ����������
void usage(char *prog)
{

	printf("Usage:GSGBannerScan.exe 127.0.0.1 65535\n");
	printf("GSGBannerScan.exe IP Startport Endport\n");

}

int main(int argc,char *argv[])
{

	
		if (argc != 4)
		{

			usage(argv[0]);
			return -1;

		}//�����������4������ʾ����


WSADATA wsa;

//��ʼ��Socket�汾
if ( WSAStartup(MAKEWORD(2,2), &wsa)  != 0 )
{


		printf("Winsock Dll init Failed!\n");
		return -1;

}
//���嵱ǰ�˿ںͼ�����
int nowport,count;

//���ÿ�ʼ�˿ںͽ����˿�
struct sockaddr_in sa;
int startport = atoi(argv[2]);
int endport = atoi(argv[3]);

//�ж϶˿���Ч��
if ( endport < startport )
{
	

		printf("don't doing, endport < startport\n");
		return -1;

}

//���õ�ǰ�˿�=��ʼ�˿�
nowport = startport;
printf("Start Scan.....\n");
for (nowport;nowport < endport;nowport++)
{

		//����Ŀ��������Ϣ
		sa.sin_family = AF_INET;
		sa.sin_addr.S_un.S_addr = inet_addr(argv[1]);
		sa.sin_port = htons(nowport);

		//����Socket�׽���
		SOCKET sockFD = socket(AF_INET,SOCK_STREAM,0);
		if (sockFD == INVALID_SOCKET)
		{

			printf("Socket create Error!\n");
			return -1;

		}

		int iTimeOut = 5000;		//���ó�ʱ
		setsockopt(sockFD,SOL_SOCKET,SO_RCVTIMEO,(char*)&iTimeOut,sizeof(iTimeOut));
		if (connect())
		{
		}

}


}
