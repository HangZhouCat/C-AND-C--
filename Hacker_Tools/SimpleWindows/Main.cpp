
#include <windows.h>



ATOM MyRegisterClass(HINSTANCE hInstance)
{


	WNDCLASSEX WndCls;

	//���ṹ��Ϊ0

	ZeroMemory(&WndCls, sizeof(WNDCLASSEX));

	//cbSize�ǽṹ���С

	WndCls.cbSize = sizeof(WNDCLASSEX);

	//lpfnWndProc�Ǵ��ڹ��̵�ַ

	WndCls.lpfnWndProc = WindowProc;

	//hInstance��ʵ�����

	WndCls.hInstance = hInstance;

	//lpszClassName�Ǵ���������

	WndCls.lpszClassName = CLASSNAME;

	//style�Ǵ�������

	WndCls.style = CS_HREDRAW | CS_VREDRAW;

	//hbrBackground�Ǵ����౳��ɫ

	WndCls.hbrBackground = (HBRUSH) COLOR_WINDOW + 1;

	//hCursor�������

	WndCls.hCursor = LoadCursor(NULL,IDC_ARROW);

	//hIcon��ͼ����

	WndCls.hIcon = LoadIcon(NULL, IDI_QUESTION);

	//����

	WndCls.cbClsExtra = 0;
	WndCls.cbWndExtra = 0;

	return RegisterClassEx(&WndCls);

}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{


	HWND hWnd = NULL;

	

	
	//��������



	
	hWnd = CreateWindowEx(WS_EX_CLIENTEDGE,
					CLASSNAME,
					"My First Window",
					
		
		)


}

int WINAPI WinMain ( HINSTANCE hInstance,		//Ӧ�ó����ʵ�����
					HINSTANCE hPrevInstance,	//ͬһ���ļ���������һ��ʵ����ʵ�����
					LPSTR lpCmdLine,			//���������Ĳ����������ڳ�������ʱ�����̴��ݲ�����
					int nShowCmd				//�ǽ�����ʾ��ʽ����������󻯡���С����ʾ�����������ص���ʾ��ʽ��
					)
{

	MSG Msg;
	BOOL bRet;

	//ע�ᴰ����

	MyRegisterClass(hInstance);

	//�������ڲ���ʾ����

	if ( ! InitInstance(hInstance, SW))
	{
	}





}