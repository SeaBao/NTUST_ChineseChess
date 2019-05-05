#include "LogPanel.h"
#include "Utility.h"
#include <iostream>

LogPanel::LogPanel()
{
	int PanelHeight = 22, PanelWidth = 22;
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

	for (int y = 0; y <= PanelHeight; y++) {
		for (int x = 0; x < PanelWidth; x++) {
			SetCursorPosistion(x + 2, y + 1);
			if (y == 0) {
				if (x == 0) {
					wcout << L"ùÝ ";
				}
				else if (x == PanelWidth - 1) {
					wcout << L"ùß ";
				}
				else {
					wcout << L"ùù ";
				}
			}
			else if (y == PanelHeight) {
				if (x == 0) {
					wcout << L"ùã ";
				}
				else if (x == PanelWidth - 1) {
					wcout << L"ùå ";
				}
				else {
					wcout << L"ùù ";
				}
			}
			else {
				if (x == 0 || x == PanelWidth - 1) {
					wcout << L"ùø ";
				}
			}
		}
	}

	SetCursorPosistion(7, 1);
	wcout << L" ¾Ô ªp Åã ¥Ü";

	_LogIndex = 0;
}

void LogPanel::AddLog(wchar_t ChessName, int fromX, int fromY, int toX, int toY, bool Team)
{
}
