#define _WIN32_WINNT 0x0500

#include <iostream>
#include <Windows.h>
#include "OperatingChess.h"
#include "LogPanel.h"
#include "ChessWalking.h"
#include "Board.h"
#include "Utility.h"
using namespace std;

int main() {
	int WindowHeight = 22, WindowWidth = 80;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HWND consoleWindow = GetConsoleWindow();

	setlocale(LC_ALL, "zh_TW.UTF-8");
	SetConsoleTitle("NTUST Chinese Chess VER. 0.0.1");
	SetWindow(WindowWidth + 2, WindowHeight + 1);
	/*SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
	ShowScrollBar(consoleWindow, SB_BOTH, FALSE);*/

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 28;
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
	LogPanel::CurrentPanel.PrintPanel();
	Board::CurrentBoard.ReadFile("Board.txt");
	SetCursorPosistion(Board::CurrentBoard.ConvertToConsolePoint(4, 9).X, Board::CurrentBoard.ConvertToConsolePoint(4, 9).Y);
	OperatingChess start;
	start.gameStart();
	return 0;
}