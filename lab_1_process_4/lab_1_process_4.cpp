//Процес 4 – побудований таким чином, що на одному комп’ютері запускається лише один раз
#include <iostream>
#include <conio.h>
#include <tchar.h>
#include <Windows.h>
using namespace std;

int main()

{

	HANDLE hMutex = OpenMutex(MUTEX_ALL_ACCESS, FALSE, L"Mutex4");
	if (hMutex != NULL)
	{
		cout << "Program is already opened." << endl;
	}
	else
	{
		HANDLE hMutex2 = CreateMutex(NULL, FALSE, L"Mutex4");
		cout << "Creating a new mutex.";
		system("pause");
	}

	return 0;
}