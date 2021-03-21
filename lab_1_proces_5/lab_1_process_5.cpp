//Процес 5. Наслідує всі об’єкти ядра процесу 1.
#include<iostream>
#include<windows.h>
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	STARTUPINFOA si;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;
	//C:\Users\m\source\repos\SP_1\lab_1_proces_5\lab_1_proces_5
	LPCSTR path = "..\\..\\lab_1_process_1\\Debug\\lab_1_process_1.exe";
	if (CreateProcessA(path, NULL, NULL, NULL, TRUE, NULL, NULL, NULL, &si, &pi))
	{
		cout << "Наслідування" << endl;
		Sleep(1000);				// чекаємо
	}
	else
		cout << "error";
	system("pause");
	return 0;
}
