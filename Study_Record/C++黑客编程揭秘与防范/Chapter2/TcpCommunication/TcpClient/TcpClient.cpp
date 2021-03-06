// TcpClient.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <WinSock2.h>
#pragma comment(lib,"ws2_32")

int main()
{

	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);

	//创建套接字
	SOCKET sClient = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);

	//对sockaddr_in结构体填充地址、端口等信息
	struct sockaddr_in ServerAddr;
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	ServerAddr.sin_port = htons(666);

	//连接服务器
	connect(sClient, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));

	char szMsg[MAXBYTE] = { 0 };

	//接收消息
	recv(sClient, szMsg, MAXBYTE, 0);
	printf("Server Msg:%s \r\n", szMsg);

	//发送消息
	lstrcpy((LPWSTR)szMsg, L"hello Server!\r\n");
	send(sClient,szMsg ,strlen(szMsg) + sizeof(char), 0);


	WSACleanup();


	getchar();
    return 0;
}

