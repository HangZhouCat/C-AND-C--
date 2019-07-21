// UDPClient.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <WinSock2.h>
#pragma comment (lib,"ws2_32")

int main()
{


	WSADATA wsaData;
	WSAStartup(MAKEWORD(2, 2), &wsaData);
	
	//创建套接字
	SOCKET sClient = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);


	//对sockaddr_in结构体填充地址、端口等信息。
	struct sockaddr_in ServerAddr;
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	ServerAddr.sin_port = htons(666);

	//发送消息
	char szMsg[MAXBYTE] = { 0 };
	lstrcpy((LPWSTR)szMsg, (LPCWSTR)"Hello Server!\r\n");
	int nSize = sizeof(ServerAddr);
	sendto(sClient, szMsg, strlen(szMsg) + sizeof(char), 0, (SOCKADDR*)&ServerAddr, nSize);

	//接收消息
	nSize = sizeof(ServerAddr);
	recvfrom(sClient, szMsg, MAXBYTE, 0, (SOCKADDR*)&ServerAddr,&nSize);
	printf("Server Msg: %s \r\n",szMsg);

	WSACleanup();

	getchar();
	getchar();

    return 0;
}

