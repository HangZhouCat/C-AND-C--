//�оٽ���ģ��
#include "stdafx.h"
#include "windows.h"
#include <vector>
#include <TLHELP32.H>
#include "PSAPI.H"			//Ҫ��SDK֧�ֵ��ԣ��оٽ���·����
#pragma comment(lib,"PSAPI.LIB")

BOOL EnablePrivilege(HANDLE hToken,LPCSTR szPrivName)
{

	TOKEN_PRIVILEGES tkp;	//TOKEN_PRIVILEGES�ṹ����һ����Ȩ��Ϣ�ķ������ơ�
	//�޸Ľ���Ȩ��
	LookupPrivilegeValue(NULL,szPrivName,&tkp.Privileges[0].Luid);		//LookupPrivilegeValue������������Ψһ��ʶ��(LUID)����ָ��ϵͳ���ش���ָ������Ȩ�����֡�
	tkp.PrivilegeCount = 1;
	tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	//֪ͨϵͳ�޸Ľ���Ȩ��
	AdjustTokenPrivileges(hToken,FALSE,&tkp,sizeof tkp,NULL,NULL);
	return ((GetLastError() == ERROR_SUCCESS));
}
BOOL GetProcessList(std::vector(PROCESSINFO*) *pProcInfo)
{

	DWORD processid[1024],needed;
	HANDLE hProcess;
	HMODULE hModule;
	

}