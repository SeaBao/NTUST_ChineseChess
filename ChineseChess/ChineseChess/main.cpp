#include <iostream>
#include <Windows.h>
#include "OperatingChess.h"
#include "ChessWalking.h"
#include "Board.h"
#include "Utility.h"
using namespace std;

int main() {
	int WindowHeight = 24, WindowWidth = 80;
	setlocale(LC_ALL, "zh_TW.UTF-8");
	SetConsoleTitle("NTUST Chinese Chess VER. 0.0.1");
	SetWindow(WindowWidth + 1, WindowHeight + 1);

	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 30;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(hOut, FALSE, &cfi);

	for (int y = 0; y <= WindowHeight; y++) {
		for (int x = 0; x < WindowWidth; x++) {
			SetCursorPosistion(x, y);
			if (y == 0) {
				if (x == 0) {
					wcout << L"שÝ ";
				}
				else if (x == WindowWidth - 1) {
					wcout << L"שß ";
				}
				else {
					wcout << L"שש ";
				}
			}
			else if (y == WindowHeight) {
				if (x == 0) {
					wcout << L"שד ";
				}
				else if (x == WindowWidth - 1) {
					wcout << L"שו ";
				}
				else {
					wcout << L"שש ";
				}
			}
			else {
				if (x == 0 || x == WindowWidth - 1) {
					wcout << L"שר ";
				}
			}
		}
	}

	system("del /Q History\\*.txt > nul 2> nul");
	Board::CurrentBoard.ReadFile("Board.txt");
	SetCursorPosistion(Board::CurrentBoard.ConvertToConsolePoint(4, 10).X, Board::CurrentBoard.ConvertToConsolePoint(4, 10).Y);
	OperatingChess start;
	start.gameStart();
	return 0;
}