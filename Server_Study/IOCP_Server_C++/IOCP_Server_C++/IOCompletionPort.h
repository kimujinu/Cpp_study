#pragma once

#pragma comment(lib, "ws2_32.lib") // winsock2 ����� ���� �ڸ�Ʈ �߰�
#include <WinSock2.h>

#define MAX_BUFFER 1024
#define SERVER_PORT 30002

struct stSOCKETINFO
{
	WSAOVERLAPPED overlapped;
	WSABUF dataBuf;
	SOCKET socket;
	char messageBuffer[MAX_BUFFER];
	int recvBytes;
	int sendBytes;
};

class IOCompletionPort
{
public:
	IOCompletionPort();
	~IOCompletionPort();

	// ���� ��� �� ���� ���� ����
	bool Initialize();
	// ���� ����
	void StartServer();
	// �۾� ������ ����
	bool CreateWorkThread();
	// �۾� ������ 
	void WorkerThread();

private:
	stSOCKETINFO* m_pSocketInfo; // ���� ����
	SOCKET m_listenSocket; // ���� ���� ����
	HANDLE m_hIOCP; // IOCP ��ü �ڵ�
	bool m_bAccept; // ��û ���� �÷���
	bool m_bWorkerThread; // �۾� ������ ���� �÷���
	HANDLE* m_pWorkerHandle; // �۾� ������ �ڵ�
};