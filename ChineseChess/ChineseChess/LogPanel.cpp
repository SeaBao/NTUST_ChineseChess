#include "LogPanel.h"
#include "Utility.h"
#include <iostream>

LogPanel LogPanel::CurrentPanel = LogPanel();

LogPanel::LogPanel()
{
	_LogIndex = 0;
}

void LogPanel::PrintPanel()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);

	for (int y = 0; y <= _PanelHeight; y++) {
		for (int x = 0; x < _PanelWidth; x++) {
			SetCursorPosistion(x + 2, y + 1);
			if (y == 0) {
				if (x == 0) {
					wcout << L"�� ";
				}
				else if (x == _PanelWidth - 1) {
					wcout << L"�� ";
				}
				else {
					wcout << L"�� ";
				}
			}
			else if (y == _PanelHeight) {
				if (x == 0) {
					wcout << L"�� ";
				}
				else if (x == _PanelWidth - 1) {
					wcout << L"�� ";
				}
				else {
					wcout << L"�� ";
				}
			}
			else {
				if (x == 0 || x == _PanelWidth - 1) {
					wcout << L"�� ";
				}
			}
		}
	}

	SetCursorPosistion(7, 1);
	wcout << L" �� �p �� ��";
}

void LogPanel::AddLog(wchar_t ChessName, int fromX, int fromY, int toX, int toY, bool Team)
{
	auto hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	auto cursorPos = GetCursorPosition();
	WORD whiteText = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;
	
	SetCursorPosistion(5, 2 + _LogIndex++);

	// Doing printing stuffs
	SetConsoleTextAttribute(hOut, whiteText);
	wcout << _LogIndex << " ";
	if (Team) {
		SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY);
		wcout << L"��";
	}
	else {
		
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		wcout << L"��";
	}
	SetConsoleTextAttribute(hOut, whiteText);
	wcout << L"�G";

	wcout << ChessName << " " << fromX << " " << fromY << " " << toX << " " << toY;

	SetCursorPosistion(cursorPos.X, cursorPos.Y);
}