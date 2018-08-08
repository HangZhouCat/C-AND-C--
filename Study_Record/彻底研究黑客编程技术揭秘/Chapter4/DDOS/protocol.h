#ifndef  _PROTOCAL_H
#define  _PROTOCAL_H



#define  ETHER_HEADER_LENGTH   0x0e                     //��̫��ͷ���� 
#define  IP_HEADER_LENGTH      0x14                     //IPͷ���ĳ���
#define  TCP_HEADER_LENGTH     0x14                     //TCPͷ������
#define  TCP_DATA_LENGTH       0x00   //0x10                     //TCP���ݲ��ֳ���  
#define  PSD_LENGTH            0x0c                     //PSDα�ײ�����


//32λ��IP��ַ
typedef  struct tagIP_ADDRESS
{
	unsigned   char   byte1;
	unsigned   char   byte2;
	unsigned   char   byte3;
	unsigned   char   byte4;
}IP_ADDRESS,* LPIP_ADDRESS;


//48λ��MAC��ַ
typedef struct tagHARD_MAC
{
	unsigned   char   byte1;
	unsigned   char   byte2;
	unsigned   char   byte3;
	unsigned   char   byte4;
	unsigned   char   byte5;
	unsigned   char   byte6;
}HARD_MAC,* LPHARD_MAC;


//��̫��ͷ��14���ֽ�
typedef  struct  tagETHERNET_HEADER
{
	HARD_MAC	 dmac;                   //��̫��Ŀ�ĵ�ַ
	HARD_MAC     smac;                   //��̫��Դ��ַ
	WORD         type;                   //֡����  IP���ݰ���0x0800   ARP����0x0806   RARP����0x8035       
}ETHERNET_HEADER,* LPETHERNET_HEADER;


//ARP֡��60���ֽڣ�������4��CRCУ��λ  
typedef   struct tagARP_FRAME
{
	ETHERNET_HEADER	    frameheader;      //��̫��ͷ��14���ֽ�
	WORD                hardtype;         //Ӳ������2���ֽ�
	WORD                protype;          //Э������2���ֽ�
	unsigned  char      hardlength;       //Ӳ����ַ����1���ֽ�
	unsigned  char      prolength;        //Э���ַ����1���ֽ�
	WORD                oper;             //����ѡ��     1:����   2��Ӧ��
	HARD_MAC	        smac;             //������Ӳ����ַ  6���ֽ� 
	IP_ADDRESS		    saddr;            //������ip��ַ   4���ֽ�
	HARD_MAC	        dmac;             //Ŀ��Ӳ����ַ  6���ֽ� 
	IP_ADDRESS		    daddr;            //������ip��ַ  4���ֽ�
	BYTE                padding[18];      //���0
}ARP_FRAME,* LPARP_FRAME;


//IP���ݰ���ͷ��   
typedef  struct  tagIP_HEADER
{
	unsigned   char	  ver_ihl;          //version  (4 bits) +Internet header  length(4 bits)  �汾(4) + �ײ�����(1����λ4���ֽ�)
	unsigned   char   tos;              //Type  of  service   ���ַ���
	unsigned   short  tlen;             //Total length    �ܳ��ȣ�IPͷ��+���ݲ��ֵĳ��ȣ� �ܳ����ֶ�Ϊ16λ��������ݱ�����󳤶�Ϊ2^16-1=65535�ֽ�  
	unsigned   short  identification;   //Identification   ��ʶ
	unsigned   short  flags_of;         //Flags (3 bits) + Fragment offsets (13 bits)  ��־ Ƭƫ��
	unsigned   char   ttl;              //Time to live  ����ʱ��
	unsigned   char   proto;            //Protocol   Э��
	unsigned   short  crc;              //Header  checksum  �ײ�У���
	IP_ADDRESS        saddr;            //Դ��ַ  
	IP_ADDRESS        daddr;            //Ŀ�ĵ�ַ
	//unsigned   int    op_pad;           //Options + Padding   ��ѡ�ֶ� + ���
}IP_HEADER,* LPIP_HEADER;


//TCP���ݰ�ͷ��
typedef  struct tagTCP_HEADER
{
	unsigned  short sport;				// Դ�˿ں�16bit
    unsigned  short dport;				// Ŀ�Ķ˿ں�16bit
    unsigned  int   seq;				// ���к�32bit ����ʶ��TCPԴ����TCPĿ��˷��͵������ֽ���������ʾ��������Ķ��еĵ�һ�������ֽڡ�
    unsigned  int   ack;				// ȷ�Ϻ�32bit ֻ��ACK��־Ϊ1ʱ��ȷ�Ϻ��ֶβ���Ч��������Ŀ����������յ�Դ�˵���һ�������ֽڡ�
	unsigned  char  offset;             // ǰ4λ��TCPͷ���� ����ͷ��ռ32���ص���Ŀ��û���κ�ѡ���ֶε�TCPͷ������Ϊ20�ֽڣ���������60�ֽڵ�TCPͷ����
	unsigned  char  flag;               // ��6λ������
										// ��6λ����־λ
										// ��־λ�ֶΣ�U��A��P��R��S��F����ռ6���ء������صĺ������£�
										// URG: ����ָ�루urgent pointer����Ч
										// ACK��ȷ�������Ч
										// PSH�����շ�Ӧ�þ��콫������Ķν���Ӧ�ò㡣
										// RST���ؽ����ӡ�
										// SYN������һ�����ӡ�
										// FIN���ͷ�һ�����ӡ�
	//����TCP��ͷ��־λ
	#define   TCP_URG              0x01<<5
	#define   TCP_ACK              0x01<<4
	#define   TCP_PSH              0x01<<3 
	#define   TCP_RST              0x01<<2
	#define   TCP_SYN              0x01<<1
	#define   TCP_FIN              0x01<<0
    unsigned  short window;             // ���ڴ�С16bit ���ֶ����������������ơ���λΪ�ֽ��������ֵ�Ǳ�������һ�ν��յ��ֽ�����
    unsigned  short checkcum;           // �����16bit ռ16���ء�������TCP���ĶΣ���TCPͷ����TCP���ݽ���У��ͼ��㣬����Ŀ��˽�����֤��
    unsigned  short surgentpointer;     // ��������ƫ����16bit	����һ��ƫ������������ֶ��е�ֵ��ӱ�ʾ�����������һ���ֽڵ���š�
}TCP_HEADER,*LPTCP_HEADER;


//����TCP�ײ��в�����Դ��ַ��Ŀ���ַ����Ϣ��Ϊ�˱�֤TCPУ�����Ч�ԣ��ڽ���TCPУ��͵ļ���ʱ����Ҫ����һ��TCPα�ײ���У��ͣ��������£�
typedef  struct  tagPSD_HEADER
{
	unsigned    long   saddr;   //Դ��ַ 4
	unsigned    long   daddr;   //Ŀ�ĵ�ַ 4
	unsigned	char   mbz;     //�ÿ�	 1
	unsigned	char   ptoto;   //Э������ 1
	unsigned	short  tcpl;    //TCP�ܳ���  2
	TCP_HEADER  th;             //TCPͷ��  
	unsigned    char   data[TCP_DATA_LENGTH];  //����
}PSD_HEADER,*LPSD_HEADER;

//IP֡��TCP��
typedef   struct tagIP_TCP_FRAME
{
	ETHERNET_HEADER    frameheader;				 //��̫��ͷ��14���ֽ�
	IP_HEADER          ih;						 //IPͷ��
	union{
		struct{
			TCP_HEADER		   th;						 //TCPͷ��
			unsigned    char   data[TCP_DATA_LENGTH];	 //����
		}tcp_fk;
		unsigned  char tcpall[TCP_HEADER_LENGTH+TCP_DATA_LENGTH];    
	}TCP;
}IP_TCP_FRAME,*LPIP_TCP_FRAME;


//UDP���ݰ�ͷ��
typedef  struct tagUDP_HEADER
{
	unsigned   short   sport;           //Դ�˿�
	unsigned   short   dport;           //Ŀ�Ķ˿�
	unsigned   short   len;             //Datagram length  ����UDPͷ����UDP���ݵ��ܳ����ֽڡ�
	unsigned   short   crc;             //Checksum    У��� ������UDPͷ����UDP���ݽ���У�顣��TCP��ͬ���ǣ���UDP��˵�����ֶ��ǿ�ѡ���TCP���ݶ��е�У����ֶ��Ǳ����еġ�
}UDP_HEADER,*LPUDP_HEADER;

#endif