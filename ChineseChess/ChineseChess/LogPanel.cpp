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

void LogPanel::PrintLogs()
{
	auto hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	auto cursorPos = GetCursorPosition();
	WORD whiteText = FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED;

	int start;
	if (_LogIndex >= _PanelHeight) {
		start = _LogIndex - _PanelHeight + 1;
	}
	else {
		start = 0;
	}

	ClearPanel(false);
	ShowConsoleCursor(false);
	for (int i = start; i < _LogIndex; i++) {
		SetCursorPosistion(5, 2 + i - start);

		// Doing printing stuffs
		SetConsoleTextAttribute(hOut, whiteText);
		wcout << i + 1 << " ";
		if (_logArr[i].Team) {
			SetConsoleTextAttribute(hOut, FOREGROUND_INTENSITY);
			wcout << L"��";
		}
		else {

			SetConsoleTextAttribute(hOut, FOREGROUND_RED);
			wcout << L"��";
		}

		SetConsoleTextAttribute(hOut, whiteText);
		wcout << L"�G";
		wcout << _logArr[i].ChessName << " ";

		wchar_t digitArr[] = { L'��', L'��', L'��', L'��', L'��', L'��', L'��', L'��', L'��' };
		wchar_t chineseArr[] = { L'�E', L'�K', L'�C', L'��', L'��', L'�|', L'�T', L'�G', L'�@' };
		if (_logArr[i].toY == _logArr[i].fromY) {
			wcout << (_logArr[i].Team ? digitArr[_logArr[i].fromX] : chineseArr[_logArr[i].fromX]) << L" �� " << (_logArr[i].Team ? digitArr[_logArr[i].toX] : chineseArr[_logArr[i].toX]);
		}
		else {
			if (_logArr[i].toY - _logArr[i].fromY > 0) {
				if (_logArr[i].Team) {
					wcout << digitArr[_logArr[i].fromX] << L" �i " << digitArr[abs(_logArr[i].toY - _logArr[i].fromY) - 1];
				}
				else {
					wcout << chineseArr[_logArr[i].fromX] << L" �h " << chineseArr[8 - abs(_logArr[i].toY - _logArr[i].fromY) + 1];
				}

			}
			else {
				if (_logArr[i].Team) {
					wcout << digitArr[_logArr[i].fromX] << L" �h " << digitArr[abs(_logArr[i].toY - _logArr[i].fromY) - 1];
				}
				else {
					wcout << chineseArr[_logArr[i].fromX] << L" �i " << chineseArr[8 - abs(_logArr[i].toY - _logArr[i].fromY) + 1];
				}
			}
		}

	}

	ShowConsoleCursor(true);
	SetCursorPosistion(cursorPos.X, cursorPos.Y);
}

int& LogPanel::GetIndex() {
	return _LogIndex;
}

void LogPanel::ClearPanel(bool resetIndex = false)
{
	auto hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	auto cursorPos = GetCursorPosition();

	SetConsoleTextAttribute(hOut, 0);
	for (int y = 0; y < _PanelHeight - 1; y++) {
		SetCursorPosistion(5, 2 + y);
		wcout << "                  ";
	}

	SetCursorPosistion(cursorPos.X, cursorPos.Y);

	if (resetIndex) {
		_logArr.clear();
		_LogIndex = 0;
	}
}

void LogPanel::AddLog(wchar_t ChessName, int fromX, int fromY, int toX, int toY, bool Team)
{
	Log myLog;
	myLog.ChessName = ChessName;
	myLog.Team = Team;
	myLog.fromX = fromX;
	myLog.fromY = fromY;
	myLog.toX = toX;
	myLog.toY = toY;

	if (_LogIndex < _logArr.size()) {
		_logArr[_LogIndex] = myLog;
	}
	else {
		_logArr.push_back(myLog);
	}
	_LogIndex++;
	PrintLogs();
}