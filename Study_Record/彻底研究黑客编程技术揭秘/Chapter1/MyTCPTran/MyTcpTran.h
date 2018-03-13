// MyTcpTran.h: interface for the CMyTcpTran class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYTCPTRAN_H__32ADFBE7_7E86_4AE3_9972_101EDE0741AB__INCLUDED_)
#define AFX_MYTCPTRAN_H__32ADFBE7_7E86_4AE3_9972_101EDE0741AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#define SOCKETBIND 1		//�������˼������ض˿ڵȴ��ͻ�������ͨ�ŷ�ʽ
#define SOCKETNOBIND 2		//���������������ӿͻ���ͨ�ŷ�ʽ
#define SOCKET_TIMEOUT -100		//�׽��ֳ�ʱ

#include <WINSOCK2.H>		//Winsock API����Ҫ��ͷ�ļ�
#include <string.h>			//ʹ��string��������Ҫ��ͷ�ļ�
using namespace std;

#pragma comment (lib,"ws2_32.lib")	//Winsock API ���ӿ��ļ�

class CMyTcpTran  
{
public:
	CMyTcpTran();					//���캯��
	virtual ~CMyTcpTran();			//��������

public��
		static BOOL InitSocketLibray(int lowver, int higver);	//��ʼ��Windows API���ӿ��ļ�

public:
	//��ʼ��socket����
	SOCKET InitSocket(int SocketType,string strBindIp, u_short BindPort,int opt);

	//��Ա��ؼ����Ĵ�����
	SOCKET myaccept(SOCKET sock, const char *buf, int len,int flag,int overtime);

	//���������/�ͻ��˷�������/�����
	int mysend(SOCKET sock,const char *buf,int len,int flag,int overtime);

	//���մӿͻ���/�������˷���������/�����
	int myrecv(SOCKET sock,const *buf,int len,int flag,int overtime,char *EndMark, BOOL soonflag=FALSE);

private:
	SOCKET m_Socket;		//˽���׽��ֳ�Ա����

};

#endif // !defined(AFX_MYTCPTRAN_H__32ADFBE7_7E86_4AE3_9972_101EDE0741AB__INCLUDED_)
