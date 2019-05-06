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
					wcout << L"╔ ";
				}
				else if (x == _PanelWidth - 1) {
					wcout << L"╗ ";
				}
				else {
					wcout << L"═ ";
				}
			}
			else if (y == _PanelHeight) {
				if (x == 0) {
					wcout << L"╚ ";
				}
				else if (x == _PanelWidth - 1) {
					wcout << L"╝ ";
				}
				else {
					wcout << L"═ ";
				}
			}
			else {
				if (x == 0 || x == _PanelWidth - 1) {
					wcout << L"║ ";
				}
			}
		}
	}

	SetCursorPosistion(7, 1);
	wcout << L" 戰 況 顯 示";
}

void LogPanel::ClearPanel()
{
	auto hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	auto cursorPos = GetCursorPosition();

	SetConsoleTextAttribute(hOut, 0);
	for (int y = 0; y < _PanelHeight - 1; y++) {
		SetCursorPosistion(5, 2 + y);
		wcout << "                  ";
	}

	SetCursorPosistion(cursorPos.X, cursorPos.Y);
}

void LogPanel::AddLog(wchar_t ChessName, int fromX, int fromY, int toX, int toY, bool Team)
{
	auto hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	auto cursorPos = GetCursorPosition();
	WORD whiteText = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;

	SetCursorPosistion(5, 2 + _LogIndex % (_PanelHeight - 1));

	if (_LogIndex % (_PanelHeight - 1) == 0) {
		ClearPanel();
	}

	_LogIndex++;

	// Doing printing stuffs
	SetConsoleTextAttribute(hOut, whiteText);
	wcout << _LogIndex << " ";
	if (Team) {
		SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY);
		wcout << L"黑";
	}
	else {
		
		SetConsoleTextAttribute(hOut, FOREGROUND_RED);
		wcout << L"紅";
	}
	SetConsoleTextAttribute(hOut, whiteText);
	wcout << L"：";
	wcout << ChessName << " ";

	wchar_t digitArr[] = { L'１', L'２', L'３', L'４', L'５', L'６', L'７', L'８', L'９' };
	wchar_t chineseArr[] = { L'九', L'八', L'七', L'六', L'五', L'四', L'三', L'二', L'一' };
	if (toY == fromY) {
		wcout << (Team ? digitArr[fromX] : chineseArr[fromX]) << L" 平 " << (Team ? digitArr[toX] : chineseArr[toX]);
	}
	else {
		if (toY - fromY > 0) {
			if (Team) {
				wcout << digitArr[fromX] << L" 進 " << digitArr[abs(toY - fromY) - 1];
			}
			else {
				wcout << chineseArr[fromX] << L" 退 " << chineseArr[8 - abs(toY - fromY) + 1];
			}

		}
		else {
			if (Team) {
				wcout << digitArr[fromX] << L" 退 " << digitArr[abs(toY - fromY) - 1];
			}
			else {
				wcout << chineseArr[fromX] << L" 進 " << chineseArr[8 - abs(toY - fromY) + 1];
			}
		}
	}

	SetCursorPosistion(cursorPos.X, cursorPos.Y);
}