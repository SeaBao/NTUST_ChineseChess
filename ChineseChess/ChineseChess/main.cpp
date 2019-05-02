#include <iostream>
#include <Windows.h>
#include "OperatingChess.h"
#include "ChessWalking.h"
#include "Board.h"
#include "Menu.h"
using namespace std;

void SetWindow(int Width, int Height)
{
	_COORD coord;
	coord.X = Width;
	coord.Y = Height;

	_SMALL_RECT Rect;
	Rect.Top = 0;
	Rect.Left = 0;
	Rect.Bottom = Height - 1;
	Rect.Right = Width - 1;

	HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(Handle, coord);
	SetConsoleWindowInfo(Handle, TRUE, &Rect);
}

int main() {
	setlocale(LC_ALL, "zh_TW.UTF-8");
	SetConsoleTitle("NTUST Chinese Chess VER. 0.0.1");
	SetWindow(81, 26);

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO	cursorInfo;
	GetConsoleCursorInfo(hOut, &cursorInfo);
	cursorInfo.bVisible = true;
	SetConsoleCursorInfo(hOut, &cursorInfo);

	Board::CurrentBoard.ReadFile("Board.txt");
	OperatingChess start;
	start.gameStart();
	
	return 0;
}