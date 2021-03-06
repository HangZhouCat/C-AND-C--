// UDPServer.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <WinSock2.h>
#pragma comment(lib,"ws2_32")

int main()
{
	WSADATA WSAData;
	WSAStartup(MAKEWORD(2, 2), &WSAData);

	//创建套接字
	SOCKET sServer = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

	//对sockaddr_in结构体填充地址、端口等信息
	struct sockaddr_in ServerAddr;
	ServerAddr.sin_family = AF_INET;
	ServerAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	ServerAddr.sin_port = htons(666);

	//绑定套接字与地址信息
	bind(sServer, (SOCKADDR*)&ServerAddr, sizeof(ServerAddr));

	//接收消息
	char szMsg[MAXBYTE] = { 0 };
	struct sockaddr_in ClientAddr;
	int nSize = sizeof(ClientAddr);
	recvfrom(sServer,szMsg,MAXBYTE,0,(SOCKADDR*)&ClientAddr,&nSize);
	printf("Client Msg: %s \r\n", szMsg);

	printf("Client IP=%s : %d",inet_ntoa(ClientAddr.sin_addr),htons(ClientAddr.sin_port));

	//发送消息
	lstrcpy((LPWSTR)szMsg, (LPCWSTR)"Hello Client From Server Msg!\r\n");
	nSize = sizeof(ClientAddr);
	sendto(sServer, szMsg, strlen(szMsg) + sizeof(char), 0, (SOCKADDR*)&ClientAddr, nSize);

	WSACleanup();

	getchar();
	getchar();

    return 0;
}

