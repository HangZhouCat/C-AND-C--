#include <ntddk.h>	//������iostream.h
void MyDriverUnload(PDRIVER_OBJECT driver);
NTSTATUS DriverEntry(PDRIVER_OBJECT driver, PUNICODE_STRING reg_path)	//������main������WinMain(),DLL_Entry()
{

	DbgPrint("Hello Word! \r\n");		//���Դ�ӡ ����ʱ��ӡ��仰

	driver->DriverUnload = MyDriverUnload;		//ָ��ж�غ���

	return STATUS_SUCCESS;		//����
}
void MyDriverUnload(PDRIVER_OBJECT driver)
{


	DbgPrint("Sys Unloading....\r\n");	//ж��ʱ��ӡһ�仰

}