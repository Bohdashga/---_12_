//������ 2. ³������ �� ��� ������� � ������ 1 �ᒺ��� ���� �� �������, �� ���� � �������� ��� ������� 1 �� 2.
//����������� ������� GetLastError
//����������� ������� WaitForSingleObject
#include<iostream>
#include<windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//³������� ��������

	HANDLE hMutex = OpenMutex(MUTEX_ALL_ACCESS, FALSE, "Mutex");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		cout << "������� ����!" << endl;
		WaitForSingleObject(hMutex, INFINITE);
		cout << "������� ���������!" << endl;
	}
	if (hMutex == NULL)
	{

		cout << "������� ������� ��������: " << GetLastError() << endl;
	}
	else cout << "������� �������" << endl;

	//³������� ��������

	HANDLE hSemaphore = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "Semaphore");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		cout << "������� ����!" << endl;
		WaitForSingleObject(hSemaphore, INFINITE);
		cout << "������� ���������!" << endl;
	}
	else if (hSemaphore == NULL)
	{
		cout << "������� ������� �������� " << GetLastError() << endl;
	}
	else
		cout << "������� �������" << endl;

    //³������� ��������

	HANDLE hTimer = OpenWaitableTimer(TIMER_ALL_ACCESS, FALSE, "Timer");
	if (hTimer == NULL)
	{
		cout << "������� �������� �������" << GetLastError() << endl;
	}
	else
		cout << "������ �������" << endl;
}