typedef struct tagLinkInfo {

		SOCKET s;			//����ͨ��Socket
		string strBindIp;		//�����е�����iP
		u_short BindPort;		//���������������ķ������˿�

}LINKINFO,*LPLINKINFO;

typedef struct tagProcessInfo {
	DWORD PID;			//����ID
	char ProcName[64];		//������
	char ProcPath[128];		//����·��
}PROCESSINFO,*LPPROCESSINFO;
