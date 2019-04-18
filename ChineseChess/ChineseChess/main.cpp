#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = 0;
	Position.Y = 0;

	
	cout << "Hello World";
	SetConsoleCursorPosition(hOut, Position);
	cout << "test";

	return 0;
}