// BoardRefresh.cpp : implementation file
//

#include "stdafx.h"
#include "MouseKeyBoard.h"
#include "BoardRefresh.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// BoardRefresh dialog


BoardRefresh::BoardRefresh(CWnd* pParent /*=NULL*/)
	: CDialog(BoardRefresh::IDD, pParent)
{
	//{{AFX_DATA_INIT(BoardRefresh)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void BoardRefresh::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(BoardRefresh)
	DDX_Control(pDX, IDOK, m_Start);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(BoardRefresh, CDialog)
	//{{AFX_MSG_MAP(BoardRefresh)
	ON_BN_CLICKED(IDOK, OnBtnStart)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// BoardRefresh message handlers

void BoardRefresh::OnBtnStart() 
{
	// TODO: Add your control notification handler code here
	CString strBtn;
	int nInterval = 0;		//ʱ����
	//��ȡ��������������
	GetDlgItemText(IDC_EDIT_CAPTION,m_strCaption);
	//��ȡ�����ˢ��Ƶ��
	nInterval = GetDlgItemInt(IDC_EDIT_INTERVAL,FALSE,TRUE);
	//�ж������ֵ�Ƿ�Ϸ�
	if (m_strCaption == "" || nInterval ==0)
	{
		return;
	}
	//��ȡ��ť�ı���
	m_Start.GetWindowText(strBtn);
	if (strBtn == "��ʼ")
	{

		//���ö�ʱ��
		SetTimer(1,nInterval * 1000,NULL);
		m_Start.SetWindowText("ֹͣ");
		GetDlgItem(IDC_EDIT_CAPTION)->EnableWindow(FALSE);
		GetDlgItem(IDC_EDIT_INTERVAL)->EnableWindow(FALSE);
	}
	else
	{
		//������ʱ��
		KillTimer(1);
		m_Start.SetWindowText("��ʼ");
		GetDlgItem(IDC_EDIT_CAPTION)->EnableWindow(TRUE);
		GetDlgItem(IDC_EDIT_INTERVAL)->EnableWindow(TRUE);
	}
}

void BoardRefresh::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
		//��Ӧ��ʱ���ĺ���

	AfxMessageBox("Timer");

	HWND hWnd = ::FindWindow(NULL,m_strCaption.GetBuffer(0));

	if (hWnd == 0)
	{

		AfxMessageBox("δ�ҵ����ھ�����Ժ�����!");

	}
	else{
		AfxMessageBox("�Ѿ��ҵ����ھ��������ˢ�£�");
	}

	//���ͼ��̰���
	::PostMessage(hWnd,WM_KEYDOWN,VK_F5,1);
	Sleep(50);		
	//���ͼ���̧��
	::PostMessage(hWnd,WM_KEYUP,VK_F5,1);
	
	CDialog::OnTimer(nIDEvent);
}
