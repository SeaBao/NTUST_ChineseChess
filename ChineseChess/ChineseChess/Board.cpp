#include "Board.h"
#include <Windows.h>
#include <iostream>

void SetCursorPosistion(int x, int y) {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = x;
	Position.Y = y;

	SetConsoleCursorPosition(hOut, Position);
}


Board::Board()
{
}

void Board::PrintMap()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = 24;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(hOut, FALSE, &cfi);

	CONSOLE_CURSOR_INFO	cursorInfo;
	GetConsoleCursorInfo(hOut, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(hOut, &cursorInfo);

	int boardWidth = 100;
	int boardHeight = 30;

	SetCursorPosistion(0, 0);
	cout << "ùÝ";
	for (int i = 0; i < boardWidth  -2; i++) {
		cout << "ùù";
	}
	cout << "ùß" << endl;

	for (int i = 0; i < boardHeight - 2; i++) {
		for (int j = 0; j < boardWidth; j++) {
			if (j == 0 || j == boardWidth - 1) {
				cout << "ùø";

				if (j == boardWidth - 1) {
					cout << endl;
				}
			}
			else {
				cout << " ";
			}
		}
	}

	cout << "ùã";
	for (int i = 0; i < boardWidth - 2; i++) {
		cout << "ùù";
	}
	cout << "ùå" << endl;
	SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | FOREGROUND_RED);
	SetCursorPosistion(35, 1);
	cout << "¢°  ¢±  ¢²  ¢³  ¢´  ¢µ  ¢¶  ¢·  ¢¸";

	for (int i = 0; i < 25; i++) {		
		for (int j = 0; j < 34; j++) {
			SetCursorPosistion(35 + j, 2 + i);
			cout << " ";
		}
	}

}


Board::~Board()
{
}
