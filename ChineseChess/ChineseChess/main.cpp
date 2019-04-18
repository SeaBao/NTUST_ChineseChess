#include <iostream>
#include <Windows.h>
#include"OperatingChess.h"
#include"ChessWalking.h"
using namespace std;
int main() {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << "test";
	system("pause");
	return 0;
}