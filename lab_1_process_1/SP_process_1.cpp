#include<iostream>
#include<windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	SECURITY_ATTRIBUTES sa;
	sa.nLength = sizeof(sa);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	//��������� ��������

	HANDLE hMutex = CreateMutex(&sa, TRUE, "Mutex");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		cout << "������� ����!" << endl;
		WaitForSingleObject(hMutex, INFINITE);
		cout << "������� ���������!" << endl;
	}

	else if (hMutex)
	{
		cout << "������� ��������!" << endl;
	}
	else cout << "������� ��������� �������� " << GetLastError() << endl;

	//��������� ��������

	HANDLE hSemaphore = CreateSemaphore(&sa, 1, 1, "Semaphore");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		cout << "������� ����!" << endl;
		WaitForSingleObject(hSemaphore, INFINITE);
		cout << "������� ���������!" << endl;
	}
	else if (hSemaphore)
	{
		cout << "������� ��������!" << endl;
	}
	else cout << "������� ��������� �������� " << GetLastError() << endl;

	//��������� �������

	HANDLE hTimer = CreateWaitableTimer(&sa, FALSE, "Timer");
	if (hTimer)
	{
		LARGE_INTEGER dueTime;
		DWORD Count = 0;
		dueTime.QuadPart = -50000000;//
		cout << "������ ��������!" << endl;
		SetWaitableTimer(hTimer, &dueTime, 10000, NULL/*�������� �� ����������� �������*/, &Count, TRUE/*�������� � �������� �����*/);
		WaitForSingleObject(hTimer, INFINITE);
		cout << "������ ���������." << endl;
	}
	else cout << "������� ��������� �������" << GetLastError() << endl;

	system("pause");
	return 0;
}