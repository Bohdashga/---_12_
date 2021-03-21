//Процес 2. Відкрити всі три створені у процесі 1 об’єкти ядра та довести, що вони є спільними для процесів 1 та 2.
//використати функцію GetLastError
//використати функцію WaitForSingleObject
#include<iostream>
#include<windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//Відкриття мьютекса

	HANDLE hMutex = OpenMutex(MUTEX_ALL_ACCESS, FALSE, "Mutex");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		cout << "Мьютекс існує!" << endl;
		WaitForSingleObject(hMutex, INFINITE);
		cout << "Мьютекс захоплено!" << endl;
	}
	if (hMutex == NULL)
	{

		cout << "Помилка відкрття мьютекса: " << GetLastError() << endl;
	}
	else cout << "Мьютекс відкрито" << endl;

	//Відкриття семафора

	HANDLE hSemaphore = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "Semaphore");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		cout << "Семафор існує!" << endl;
		WaitForSingleObject(hSemaphore, INFINITE);
		cout << "Семафор захоплено!" << endl;
	}
	else if (hSemaphore == NULL)
	{
		cout << "Помилка відкрття семафора " << GetLastError() << endl;
	}
	else
		cout << "Семафор відкрито" << endl;

    //Відкриття семафора

	HANDLE hTimer = OpenWaitableTimer(TIMER_ALL_ACCESS, FALSE, "Timer");
	if (hTimer == NULL)
	{
		cout << "Помилка відкриття таймера" << GetLastError() << endl;
	}
	else
		cout << "Таймер відкрито" << endl;
}