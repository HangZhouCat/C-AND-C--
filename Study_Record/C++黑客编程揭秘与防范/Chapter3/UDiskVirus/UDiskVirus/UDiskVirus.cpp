// UDiskVirus.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>

char szAutoRun[] = "[AutoRun] \
\r\nopen = notepad.exe \
\r\nshell\\open=打开(&O) \
";

//感染函数
void infect(char* pszFile,UINT uDriveType)	
{
	char szDriveString[MAXBYTE] = { 0 };
	DWORD dwRet = 0;
	

}
int main()
{
    return 0;
}

