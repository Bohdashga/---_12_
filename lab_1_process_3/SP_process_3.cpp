//Процес 3. Продемонструвати роботу семафора, створеного в процесі 1 звикористанням функції  WaitForMultipleObject
#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	HANDLE hSemaphore = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, "Semaphore");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
	{
		cout << "Семафор з процесу 1 був відкритим" << endl;
	}
	else
	{
		cout << "Семафор відкрито"<<endl;
	}
	HANDLE hMutex = OpenMutex(MUTEX_ALL_ACCESS, FALSE, "Mutex4");
	if (GetLastError() != ERROR_ALREADY_EXISTS)
	{
		cout << "Мьютекс з процесу 4" << endl;
	}
	else
	{
		cout << "Мьютекс відкрито" << endl;
	}
	HANDLE array_Semaphores[2] = { hSemaphore , hMutex };
	WaitForMultipleObjects(1, array_Semaphores, TRUE, INFINITE);
	cout << "Кінець процесу 3" << endl;
	ReleaseSemaphore(hSemaphore, 1, NULL);
	CloseHandle(hSemaphore);

	system("pause");
	return 0;
}
