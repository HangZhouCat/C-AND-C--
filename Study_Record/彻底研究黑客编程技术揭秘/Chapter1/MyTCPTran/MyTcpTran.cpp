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
   ����ֵ:		TRUE��ʾ�ɹ���FALSE��ʾʧ�ܡ�                                                                 */
/************************************************************************/
