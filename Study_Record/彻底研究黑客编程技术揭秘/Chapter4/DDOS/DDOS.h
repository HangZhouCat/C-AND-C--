// DDOS.h: interface for the CDDOS class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DDOS_H__F319FDAC_C9D0_488E_90CB_628CF9B403A8__INCLUDED_)
#define AFX_DDOS_H__F319FDAC_C9D0_488E_90CB_628CF9B403A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <WINSOCK2.H>
#pragma comment (lib,"ws2_32.lib")


#define BufferSize 1024			//Ԥ���建������С
static char pSendBuffer[BufferSize+60];		//���ͻ�����
static int iTotalSize = 0;

class CDDOS  
{
public:
	CDDOS();		//���캯��
	virtual ~CDDOS();		//��������
	void udp_flood();		//UDP��ˮ����
private:
	void fill_udp_buffer();

};

#endif // !defined(AFX_DDOS_H__F319FDAC_C9D0_488E_90CB_628CF9B403A8__INCLUDED_)
