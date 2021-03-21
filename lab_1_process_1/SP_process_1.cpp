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

	//Створення мьютекса

	HANDLE hMutex = CreateMutex(&sa, TRUE, "Mutex");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		cout << "Мьютекс існує!" << endl;
		WaitForSingleObject(hMutex, INFINITE);
		cout << "Мьютекс захоплено!" << endl;
	}

	else if (hMutex)
	{
		cout << "Мьютекс створено!" << endl;
	}
	else cout << "Помилка створення мьютекса " << GetLastError() << endl;

	//Створення семафора

	HANDLE hSemaphore = CreateSemaphore(&sa, 1, 1, "Semaphore");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		cout << "Семафор існує!" << endl;
		WaitForSingleObject(hSemaphore, INFINITE);
		cout << "Семафор захоплено!" << endl;
	}
	else if (hSemaphore)
	{
		cout << "Семафор створено!" << endl;
	}
	else cout << "Помилка створення семафора " << GetLastError() << endl;

	//Створення таймера

	HANDLE hTimer = CreateWaitableTimer(&sa, FALSE, "Timer");
	if (hTimer)
	{
		LARGE_INTEGER dueTime;
		DWORD Count = 0;
		dueTime.QuadPart = -50000000;//
		cout << "Таймер створено!" << endl;
		SetWaitableTimer(hTimer, &dueTime, 10000, NULL/*вказівник на асинхроного виклику*/, &Count, TRUE/*виводить з сплячого стану*/);
		WaitForSingleObject(hTimer, INFINITE);
		cout << "Таймер зупинився." << endl;
	}
	else cout << "Помилка створення таймера" << GetLastError() << endl;

	system("pause");
	return 0;
}