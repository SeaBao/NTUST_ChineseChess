#include <iostream>
#include <Windows.h>
#include "OperatingChess.h"
#include "ChessWalking.h"
#include "Board.h"
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
	SetConsoleTitle("NTUST Chinese Chess VER. 0.0.1");
	SetWindow(81, 26);

	Board board;
	board.PrintMap();

	cin.get();
	return 0;
}