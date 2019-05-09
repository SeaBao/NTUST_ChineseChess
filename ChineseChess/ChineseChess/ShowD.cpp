#include "ShowD.h"

int ShowD::roundCount = 1;

void ShowD::showTurn()
{
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
		wcout << L"¨ı§Ë §U¥—";
	}
	else
	{
		Position.X = 65;
		Position.Y = 5;
		SetConsoleCursorPosition(hOut, Position);
		wcout << L"∂¬§Ë §U¥—";
	}
}

void ShowD::printRight()
{
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = 61;
	Position.Y = 1;
	SetConsoleCursorPosition(hOut, Position);
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
	wcout << L"˘› ";
	for (int i = 0; i < 14; i++)
	{
		wcout << L"˘˘";
	}
	wcout << L"˘ﬂ \n";
	Position.X = 61;
	Position.Y = 2;
	SetConsoleCursorPosition(hOut, Position);
	for (int i = 0; i < 19; i++)
	{
		wcout << L"˘¯               ˘¯ \n";
		Position.Y = 3 + i;
		SetConsoleCursorPosition(hOut, Position);
	}
	Position.X = 61;
	Position.Y = 21;
	SetConsoleCursorPosition(hOut, Position);
	wcout << L"˘„ ";
	for (int i = 0; i < 14; i++)
	{
		wcout << L"˘˘";
	}
	wcout << L"˘Â ";
	Position.X = 64;
	Position.Y = 18;
	SetConsoleCursorPosition(hOut, Position);
	wcout << L" °Ù";
	Position.X = 63;
	Position.Y = 19;
	SetConsoleCursorPosition(hOut, Position);
	wcout << L"°ˆ  °˜  ±±®Ó";
	Position.X = 64;
	Position.Y = 20;
	SetConsoleCursorPosition(hOut, Position);
	wcout << L" °ı";
	Position.X = 63;
	Position.Y = 16;
	SetConsoleCursorPosition(hOut, Position);
	wcout << L" Enter øÔ®˙";
	Position.X = 63;
	Position.Y = 14;
	SetConsoleCursorPosition(hOut, Position);
	wcout << L" > ¡Ÿ≠Ï";
	Position.X = 63;
	Position.Y = 12;
	SetConsoleCursorPosition(hOut, Position);
	wcout << L" < Æ¨¥—";
	Position.X = 63;
	Position.Y = 10;
	SetConsoleCursorPosition(hOut, Position);
	wcout << L" ESC øÔ≥Ê";
	Position.X = 62;
	Position.Y = 9;
	SetConsoleCursorPosition(hOut, Position);
	wcout << L"˘˘˘˘˘˘˘˘˘˘˘˘˘˘˘˘˘˘˘˘˘˘˘˘˘˘˘˘˘˘";
	showTurn();
}