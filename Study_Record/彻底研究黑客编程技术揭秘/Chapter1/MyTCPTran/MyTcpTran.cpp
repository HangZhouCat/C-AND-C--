// MyTcpTran.cpp: implementation of the CMyTcpTran class.
//
//////////////////////////////////////////////////////////////////////

#include "MyTcpTran.h"

using namespace std;






//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

/************************************************************************/
/* ����: CMyTCPTran
   ����: ���TCP��ͨ��                                                    */
/************************************************************************/

//���캯��
CMyTcpTran::CMyTcpTran()
{

//�׽��ַ���INVALID_SOCKET,����Ϊ���׽�����Ч�������ڹ��캯����Ϊ��Ա����Ĭ�ϸ�ֵΪ��Ч���׽��֣��𵽳�ʼ��������
	m_Socket = INVALID_SOCKET;



}

//��������
CMyTcpTran::~CMyTcpTran()
{


//


}




/************************************************************************/
/* ��������InitSocketLibray
   ����: ��ʼ��Socket��ͨ�ſ�,Ҫ��Winsock2
   ����:	lowver���汾�ĵ�λ
			higver: �汾�ĸ�λ    
   ����ֵ:		TRUE��ʾ�ɹ���FALSE��ʾʧ�ܡ�                                                                 */
/************************************************************************/
BOOL CMyTcpTran::InitSocketLibray(int lowver,int higver)
{


	WORD wVersion = 0;
	int errret = -1;
	WSADATA wsaData;

	//MAKEWORD������byte�ͺϲ���һ��word��,������һ���ǰ汾�ĵ�8λ��һ���ǰ汾�ĸ�8λ

	//��λ�ֽ�ָ�����汾����λ�ֽ�ָ�����汾�����һ������ʹ��2.1�汾��Socket����������¡�
	//wVersion = MAKEWORD(2,1);
	
	wVersion = MAKEWORD(lowver,higver);

	//���غͳ�ʼ��Socket��Ӧ�Ķ�̬���ӿ�ws2_32.dll��һЩ��Ϣ��Ϊʹ��Socket��׼����

	errret = WSAStartup(wVersion,&wsaData);

	//�ж�Socket��Ӧ�Ķ�̬���ӿ�İ汾

	if (LOBYTE (wsaData,wVersion) != 2 ||
		HIBYTE(wsaData,wVersion) !=2
		)
	{

		MessageBox(NULL,"winsocket ��汾��","��ʾ",MB_OK);
		return FALSE;

	}

	return TRUE;


}


/************************************************************************/
/* ��������InitSocket
   ����: �������ͳ�ʼ��Socket��Դ
   ����:	SocketType��SOCK_BIND ��ʾ�󶨱��ض˿�
					SOCK_NOBIND ��ʾ����
			BindIp: Ҫ�󶨵�IP��ַ,""Ϊ���������ַ�����ʮ���Ʊ�ʾIP��ַ
			BindPort: Ҫ�󶨵ı��ض˿ڣ����Ϊ0��ʾϵͳ�Զ�������
			opt: �����Ƿ�֧�ֶ˿����á�
   ����ֵ:		����:INVALID_SOCKET
                ��ȷ�����ؿ��õ�SOCKET                                            */
/************************************************************************/
SOCKET CMyTcpTran::InitSocket(int SocketType,string strBindIp, u_short BindPort,int opt)
{

	SOCKET socketid = INVALID_SOCKET;
	//����һ���ܹ���������ͨ�ŵ��׽���

	socketid = socket(PF_INET,SOCK_STREAM,0);

	SOCKADDR_IN sockStruct;

	//ʹ��TCP/IPЭ��
	sockStruct.sin_family = AF_INET;
	if (strBindIp.empty())
	{

		//����strBindIpΪ�գ�����INADDR_ANY ��ʾSocket���ý��������κ�IP����Ϣ
		sockStruct.sin_addr.S_un.S_addr = INADDR_ANY;

	}
	else
	{

		//����strBindIp��Ϊ�գ���strBindIpת��Ϊchar*��
		//��IP��ַ�ӵ�����ʽת�����޷��ų�����
		sockStruct.sin_addr.S_un.S_addr = inet_addr(strBindIp.c_str());

	}

	//������BindPortת��Ϊ�����ֽ���󱣴�
	sockStruct.sin_port = htons(BindPort);

	//���󶨶˿�
	if ( SocketType == SOCKETNOBIND )
	{

		//��sockStruct�ṹ��ָ���������ϵļ������������

		if (connect(socketid,(LPSOCKADDR)&sockStruct,sizeof(sockStruct))  == 
			SOCKET_ERROR
			)
		{


			//�������ϵļ��������ʧ��
			//OutputDebugString("���Ӵ���");
			closesocket(socketid);

			//�ر��Լ��򿪵�Socket�׽��֣���ֹռ���ڴ档
			shutdown(socketid,2);

			//�����׽�����Ч

			socketid = INVALID_SOCKET��

		}
		m_Socket = socketid;

	}

//����ǰ󶨱��ض˿�
else if ( SocketType == SOCKETBIND )
{

	//����sockStructָ��������������IP�Ͷ˿�

	if (bind(socketid,(sockaddr*)&sockStruct,sizeof(sockaddr_in)) == 
		SOCKET_ERROR
		)
	{

		//�󶨶˿�ʧ��
		closesocket(socketid);

		//�����׽�����Ч

		socketid = INVALID_SOCKET;

	}else
	{

		//��IP�Ͷ˿ڳɹ�����������������������������Ӷ���
		//SOMXCONNָ������������

		if ( listen(socketid,SOMAXCONN) == SOCKET_ERROR )
		{

			//������������ʧ�ܣ���ر��׽��֣��������׽�����Ч״̬
			closesocket(socketid);
			socketid = INVALID_SOCKET;

		}

	}

	m_Socket = socketid;

}

	return socketid;

}

/************************************************************************/
/* ��������myaccept
   ����: ����һ���µ��׽��������addrָ���Ŀͻ����׽��ֽ�������ͨ��
   ����:	s��		���ڼ���״̬�����׽���
					SOCK_NOBIND ��ʾ����
			BindIp: Ҫ�󶨵�IP��ַ,""Ϊ���������ַ�����ʮ���Ʊ�ʾIP��ַ
			BindPort: Ҫ�󶨵ı��ض˿ڣ����Ϊ0��ʾϵͳ�Զ�������
			opt: �����Ƿ�֧�ֶ˿����á�
   ����ֵ:		����:INVALID_SOCKET
                ��ȷ�����ؿ��õ�SOCKET                                            */
/************************************************************************/

SOCKET CMyTcpTran::myaccept(SOCKET sock, const char *buf, int len,int flag,int overtime)
{
	
	//�����µ��׽��ֲ���ʼ��ΪINVALID_SOCKET
	SOCKET acceptsocket = INVALID_SOCKET;
	//accept���óɹ����ؿ��õ��׽��֣�����ʧ��ͬ������INVALID_SOCKET
	acceptsocket = accept(sock,addr,addrlen);

	return acceptsocket��

}

/************************************************************************/
/* ��������myrecv
   ����: �������ͳ�ʼ��Socket��Դ
   ����:	sock��		���ն��׽��������� 
			buf:		������Ž��յ������ݵĻ�����
			len:		���յ����ݵĴ�С
			flag:		һ������Ϊ0
			overtime:	��ʱʱ��
			EndMark:	������ʶ
			Soonflag:	�Ƿ���������
   ����ֵ:	���յ������ݵ��ֽ�����                                       */
/************************************************************************/
int CMyTcpTran::myrecv(SOCKET sock,const *buf,int len,int flag,int overtime,char *EndMark, BOOL soonflag)
{

	//�������
	int ret;
	int nLeft = len;
	int idx = 0;
	int nCount = 0;
	fd_set readfds;			//fd_set���ļ��������ļ��ϡ�
	struct timeval timeout;
	timeout.tv_sec = 0;		//���ó�ʱֵ
	timeout.tv_usec = 500;
	DWORD s_time = GetTickCount();		//���شӲ���ϵͳ���������ھ����ĺ�����

	while ( nLeft >0 )
	{

		//������Ϣ
		MSG msg;
		PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);
		//���յ�����Ϣ���˳���Ϣ
		if (msg.message == WM_QUIT)
		{

			return 0;

		}

		FD_ZERO(&readfds);			//��set����
		FD_SET(sock, &readfds);		//��fd����set

		//select���������������׽���I/O�ģ���������޹�����

		if ( select(0, &readfds, NULL, NULL, &timeout) == SOCKET_ERROR )
		{

			return SOCKET_ERROR;

		}
		
		DWORD e_time = GetTickCount();
		if ( !FD_ISSET(sock, &readfds) )
		{

			if ( e_time - s_time > overtime * 1000 )		//��ʱ
			{

				return SOCKET_ERROR;

			}
			else
			{

				continue;

			}

		}

		ret = recv( sock, &buf[idx], nLeft, flag );			//��������

		if ( soonflag == TRUE )
		{

			//�������ؽ��յ����ֽ���
			return ret;

		}

		
		s_time = e_time;		//ֻҪ�����ݾ����ó�ʼʱ��ֵ

		if ( ret <= 0 )
		{

			//������
			int LastError = GetLastError();
			if ( ( -1 ==ret ) && (WSAETIMEDOUT == LastError) )
			{

				 if ( nCount < 2000 )
				 {

					Sleep( 10 );
					nCount++;
					continue;

				 }

			}
			return ret;

		}
		nCount = 0;

		nLeft -= ret;
		idx += ret;

		if ( EndMark != NULL && idx >5 )
		{


			if ( strstr(buf + (idx-5),EndMark) != NULL)
			{

				break;

			}

		}

	}

	return idx;


}

/************************************************************************/
/* ��������mysend
   ����: ��ָ����Socket��������
   ����:	sock��	���Ͷ��׽���������
			buf:		������ŷ������ݵĻ�����
			flag:		һ������Ϊ0
			overtime:	��ʱʱ��
   ����ֵ:	ʵ�ʷ������ݵ��ֽ�����                                       */
/************************************************************************/
int CMyTcpTran::mysend(SOCKET sock,const char *buf,int len,int flag,int overtime)
{

//�������
int ret;
int nLeft = len;
int idx = 0;


fd_set readfds;
struct timeval timeout;
timeout.tv_sec = 0;
timeout.tv_usec = 500;
DWORD s_time = GetTickCount();


while ( nLeft > 0 )
{

	//��Ի����͹ر���Ϣ
	MSG msg;
	PeekMessage(&msg, NULL, 0,0,PM_REMOVE);
	if ( msg.message == WM_QUIT )
	{

		return 0;

	}

	FD_ZERO(&readfds);
	FD_SET(sock, &readfds);

	int errorret = select(0,NULL,&readfds, NULL, &timeout);

	if (errorret == SOCKET_ERROR)
	{

		OutputDebugString("mysendEx SOCKET ����");
		return SOCKET_ERROR;

	}
	//���㵱ǰʱ��
	DWORD e_time = GetTickCount();
	if (!FD_ISSET(sock,&readfds))
	{

		//�����ʱ������
		if (e_time - s_time > overtime * 1000)
		{


			OutputDebugString("mysendEx�������ݳ�ʱ");
			return 0;

		}
		else
		{

			continue;
			
		}
		
	}
	ret = send(sock,&buf[idx], nLeft,flag);

	if ( ret <= 0 )
	{

		return ret;
		
	}

	nLeft -= ret;
	idx += ret;
	

}

	
return len;


}