#include "Menu.h"
#include "Utility.h"
#include "Board.h"
#include "regret.h"


void Menu::printMenu()
{
	COORD pos;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = 38, pos.Y = 6;
	ShowConsoleCursor(false);
	SetConsoleCursorPosition(hOut, pos);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	wcout << L"�� ";
	for (int i = 0; i < MenuWidth - 2; i++)
	{
		wcout << L"��";
	}
	wcout << L"�� \n";
	pos.Y = 7;
	SetConsoleCursorPosition(hOut, pos);
	//wcout << L"��    �~��C��   �� \n";
	wcout << L"��    ";
	SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x90);
	wcout << L"�~��C��";
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	wcout << L"   �� \n";
	pos.Y = 8;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"���������������������������������� \n";
	pos.Y = 9;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"��    ";
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	wcout << L"���s�}�l";
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	wcout << L"   �� \n";
	pos.Y = 10;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"���������������������������������� \n";
	pos.Y = 11;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"��    ";
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	wcout << L"�^�D���";
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	wcout << L"   �� \n";
	pos.Y = 12;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"���������������������������������� \n";
	pos.Y = 13;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"��    ";
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	wcout << L"���}�C��";
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	wcout << L"   �� \n";
	pos.Y = 14;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"�� ";
	for (int i = 0; i < MenuWidth - 2; i++)
	{
		wcout << L"��";
	}
	wcout << L"�� ";
	pos.X = 43, pos.Y = 7;
	SetConsoleCursorPosition(hOut, pos);
	command = _getch();
	while (command != EOF)
	{
		hin = GetStdHandle(STD_OUTPUT_HANDLE);
		if (command == 80)//down
		{
			if (pos.Y <= 11) {
				pos.Y += 2;
				SetConsoleCursorPosition(hin, pos);
				printWord(pos.Y);
			}
		}
		else if (command == 72)//up
		{
			if (pos.Y >= 9) {
				pos.Y -= 2;
				SetConsoleCursorPosition(hin, pos);
				printWord(pos.Y);
			}
		}
		if (command == 13)
		{
			if (pos.Y == 7)
			{
				EnterOne();
				break;
			}
			else if (pos.Y == 9)
			{
				EnterTwo();
				break;
			}
			else if (pos.Y == 11)
			{
				EnterThree();
			}
			else if (pos.Y == 13)
			{
				EnterFour();
			}
		}
		command = _getch();
	}
}

void Menu::EnterOne()
{
	Board temp;
	Board::CurrentBoard.ReadFile("History\store.txt");
	SetCursorPosistion(Board::ConvertToConsolePoint(4, 9).X, Board::ConvertToConsolePoint(4, 9).Y);
	ShowConsoleCursor(true);
}

void Menu::EnterTwo()
{
	Board::CurrentBoard.ReadFile("Board.txt");
	system("del /Q History\\*.txt > nul 2> nul");
	Board::ChessSteps = 0;
	Regret::roundCount = 0;
}

void Menu::EnterThree()
{

}

void Menu::EnterFour()
{
	exit(1);
}

void Menu::printWord(int y)
{
	COORD pos;
	HANDLE hOut;
	pos.Y = y;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (pos.Y == 7)
	{
		SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x90);
		wcout << L"�~��C��";
		pos.Y = 9, pos.X = 43;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		wcout << L"���s�}�l";
		pos.X = 42, pos.Y = 7;
		SetConsoleCursorPosition(hin, pos);
	}
	else if (pos.Y == 9)
	{
		SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x90);
		wcout << L"���s�}�l";
		pos.Y = 7, pos.X = 43;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		wcout << L"�~��C��";
		pos.Y = 11, pos.X = 43;
		SetConsoleCursorPosition(hOut, pos);
		wcout << L"�^�D���";
		pos.Y = 9, pos.X = 42;
		SetConsoleCursorPosition(hOut, pos);
	}
	else if (pos.Y == 11)
	{
		SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x90);
		wcout << L"�^�D���";
		pos.Y = 9, pos.X = 43;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		wcout << L"���s�}�l";
		pos.Y = 13, pos.X = 43;
		SetConsoleCursorPosition(hOut, pos);
		wcout << L"���}�C��";
		pos.Y = 11, pos.X = 42;
		SetConsoleCursorPosition(hOut, pos);
	}
	else if (pos.Y == 13)
	{
		SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x90);
		wcout << L"���}�C��";
		pos.Y = 11, pos.X = 43;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		wcout << L"�^�D���";
		pos.X = 42, pos.Y = 13;
		SetConsoleCursorPosition(hin, pos);
	}
}
