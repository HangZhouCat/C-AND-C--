// SimInPut.cpp : implementation file
//

#include "stdafx.h"
#include "MouseKeyBoard.h"
#include "SimInPut.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSimInPut dialog


CSimInPut::CSimInPut(CWnd* pParent /*=NULL*/)
	: CDialog(CSimInPut::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSimInPut)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CSimInPut::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSimInPut)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSimInPut, CDialog)
	//{{AFX_MSG_MAP(CSimInPut)
	ON_BN_CLICKED(IDC_BTN_KeyBoard, OnBTNKeyBoard)
	ON_BN_CLICKED(IDC_BTN_Mouse, OnBTNMouse)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSimInPut message handlers

void CSimInPut::FindAndFocus()
{
	GetDlgItemText(IDC_EDIT_CAPTION,m_StrCaption);
	//�ж������Ƿ�Ϊ��
	if (m_StrCaption == "")
	{
		AfxMessageBox("����Ϊ�գ�����������");
		return;
	}
	m_hWnd = ::FindWindow(NULL,m_StrCaption.GetBuffer(0));
	//�ú���������ָ�����ڵ��߳����õ�ǰ̨,���Ҽ���ô���
	::SetForegroundWindow(m_hWnd);
	
}

void CSimInPut::OnBTNKeyBoard() 
{
	// TODO: Add your control notification handler code here
	//ģ����̲���
	//�ҵ�����
	//�������õ�ǰ̨������

	FindAndFocus();
	Sleep(1000);
	//ģ��F5����
	keybd_event(VK_F5,0,0,0);
	Sleep(1000);
	keybd_event(VK_F5,0,0,0);
	Sleep(1000);
	keybd_event(VK_F5,0,0,0);
	Sleep(1000);
}

void CSimInPut::OnBTNMouse() 
{
	// TODO: Add your control notification handler code here
	//ģ��������
	
	FindAndFocus();
	//�õ���������Ļ������(x,y)
	POINT pt = {0};
	::ClientToScreen(m_hWnd,&pt);
	//�������λ��
	SetCursorPos(pt.x + 36,pt.y + 395);
	//ģ������Ҽ�
	mouse_event(MOUSEEVENTF_RIGHTDOWN,0,0,0,0);
	Sleep(100);
	mouse_event(MOUSEEVENTF_RIGHTUP,0,0,0,0);
	Sleep(3000);
	//0x52 = R
	//�ڵ����Ҽ��˵�����R��
	//��ˢ��ҳ��
	keybd_event(0x52,0,0,0);

}
