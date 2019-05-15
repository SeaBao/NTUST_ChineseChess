#include "ShowD.h"
#include "Utility.h"

int ShowD::roundCount = 1;

void ShowD::showTurn()
{
	auto currentPos = GetCursorPosition();
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	int round = roundCount;
	if (round % 2 == 1)
	{
		Position.X = 65;
		Position.Y = 5;
		SetConsoleCursorPosition(hOut, Position);
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		wcout << L"紅方 下棋";
	}
	else
	{
		Position.X = 65;
		Position.Y = 5;
		SetConsoleCursorPosition(hOut, Position);
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
		wcout << L"黑方 下棋";
	}

	SetCursorPosistion(currentPos.X, currentPos.Y);
}

void ShowD::printRight()
{
	auto currentPos = GetCursorPosition();
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = 61;
	Position.Y = 1;
	SetConsoleCursorPosition(hOut, Position);
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	wcout << L"╔ ";
	for (int i = 0; i < 14; i++)
	{
		wcout << L"═";
	}
	wcout << L"╗ \n";
	Position.X = 61;
	Position.Y = 2;
	SetConsoleCursorPosition(hOut, Position);
	for (int i = 0; i < 19; i++)
	{
		wcout << L"║               ║ \n";
		Position.Y = 3 + i;
		SetConsoleCursorPosition(hOut, Position);
	}
	Position.X = 61;
	Position.Y = 21;
	SetConsoleCursorPosition(hOut, Position);
	wcout << L"╚ ";
	for (int i = 0; i < 14; i++)
	{
		wcout << L"═";
	}
	wcout << L"╝ ";
	Position.X = 64;
	Position.Y = 18;
	SetConsoleCursorPosition(hOut, Position);
	wcout << L" ↑";
	Position.X = 63;
	Position.Y = 19;
	SetConsoleCursorPosition(hOut, Position);
	wcout << L"←  →  控制";
	Position.X = 64;
	Position.Y = 20;
	SetConsoleCursorPosition(hOut, Position);
	wcout << L" ↓";
	Position.X = 63;
	Position.Y = 16;
	SetConsoleCursorPosition(hOut, Position);
	wcout << L" Enter 選取";
	Position.X = 63;
	Position.Y = 14;
	SetConsoleCursorPosition(hOut, Position);
	wcout << L" > 還原";
	Position.X = 63;
	Position.Y = 12;
	SetConsoleCursorPosition(hOut, Position);
	wcout << L" < 悔棋";
	Position.X = 63;
	Position.Y = 10;
	SetConsoleCursorPosition(hOut, Position);
	wcout << L" ESC 選單";
	Position.X = 62;
	Position.Y = 9;
	SetConsoleCursorPosition(hOut, Position);
	wcout << L"═══════════════";
	showTurn();

	SetCursorPosistion(currentPos.X, currentPos.Y);
}

void ShowD::blackShowCheckmate()
{
	auto currentPos = GetCursorPosition();
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = 64;
	Position.Y = 7;
	SetConsoleCursorPosition(hOut, Position);
	SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	wcout << L"黑方被將軍了!";
	SetCursorPosistion(currentPos.X, currentPos.Y);
}

void ShowD::blackCancelCheckmate()
{
	auto currentPos = GetCursorPosition();
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = 64;
	Position.Y = 7;
	SetConsoleCursorPosition(hOut, Position);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	wcout << L"             ";

	SetCursorPosistion(currentPos.X, currentPos.Y);
}

void ShowD::redShowCheckmate()
{
	auto currentPos = GetCursorPosition();
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = 64;
	Position.Y = 3;
	SetConsoleCursorPosition(hOut, Position);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	wcout << L"紅方被將軍了!";
	SetCursorPosistion(currentPos.X, currentPos.Y);
}

void ShowD::redCancelCheckmate()
{
	auto currentPos = GetCursorPosition();
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = 64;
	Position.Y = 3;
	SetConsoleCursorPosition(hOut, Position);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	wcout << L"             ";

	SetCursorPosistion(currentPos.X, currentPos.Y);
}