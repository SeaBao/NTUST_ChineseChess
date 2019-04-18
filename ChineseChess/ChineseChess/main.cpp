#include <iostream>
#include <Windows.h>

int main() {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);

	system("pause");
	return 0;
}