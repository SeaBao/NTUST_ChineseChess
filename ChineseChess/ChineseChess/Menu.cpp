#include "Menu.h"
#include "Utility.h"
#include "Board.h"
#include "LogPanel.h"
#include "regret.h"
#include "ShowD.h"
#include <fstream>
#include <Windows.h>
#include <iostream>
#include <algorithm>
#include <sstream>


bool Menu::redFirst = false;
bool Menu::isFirstOne = true;

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
	Board::CurrentBoard.ReadFile("History/store.txt");
	SetCursorPosistion(Board::ConvertToConsolePoint(4, 9).X, Board::ConvertToConsolePoint(4, 9).Y);
	ShowConsoleCursor(true);
	Board::CurrentBoard.StartGame();
}

void Menu::EnterTwo()
{
	startTurnFix();
	if (Menu::isFirstOne)
	{
		Board::CurrentBoard.ReadFile("Board.txt");
	}
	else
	{
		Board::CurrentBoard.ReadFile("EndGame_1.txt");
	}
	LogPanel::CurrentPanel.ClearPanel(true);
	system("del /Q History\\*.txt > nul 2> nul");
	Board::ChessSteps = 0;
	Regret::roundCount = 0;
	SetCursorPosistion(Board::CurrentBoard.ConvertToConsolePoint(4, 9).X, Board::CurrentBoard.ConvertToConsolePoint(4, 9).Y);
	ShowConsoleCursor(true);
	Board temp;
	ShowD::roundCount = redFirst;
	ShowD showturn;
	showturn.showTurn();
	Board::CurrentBoard.StartGame();
}

void Menu::EnterThree()
{
	Board::CurrentBoard.mainScreen();
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

void Menu::blackWins()
{
	COORD pos;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = 37, pos.Y = 7;
	ShowConsoleCursor(false);
	SetConsoleCursorPosition(hOut, pos);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	wcout << L"�� ";
	for (int i = 0; i < 10; i++)
	{
		wcout << L"��";
	}
	wcout << L"�� \n";
	pos.Y = 8;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"��  �¤�ӧQ �� \n";
	pos.Y = 9;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"�� ";
	for (int i = 0; i < 10; i++)
	{
		wcout << L"��";
	}
	wcout << L"�� ";
	wantNext();
}

void Menu::redWins()
{
	COORD pos;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = 37, pos.Y = 7;
	ShowConsoleCursor(false);
	SetConsoleCursorPosition(hOut, pos);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	wcout << L"�� ";
	for (int i = 0; i < 10; i++)
	{
		wcout << L"��";
	}
	wcout << L"�� \n";
	pos.Y = 8;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"��  ����ӧQ �� \n";
	pos.Y = 9;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"�� ";
	for (int i = 0; i < 10; i++)
	{
		wcout << L"��";
	}
	wcout << L"�� ";
	wantNext();
}

void Menu::wantNext()
{
	COORD pos;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = 36, pos.Y = 11;
	ShowConsoleCursor(false);
	SetConsoleCursorPosition(hOut, pos);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	wcout << L"�� ";
	for (int i = 0; i < 12; i++)
	{
		wcout << L"��";
	}
	wcout << L"�� \n";
	pos.Y = 12;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"��   �}�ҷs��? �� ";
	pos.Y = 13;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"��             �� ";
	pos.Y = 14;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"��   ";
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	wcout << L"�O    �_";
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	wcout << L"  �� ";
	pos.Y = 15;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"�� ";
	for (int i = 0; i < 12; i++)
	{
		wcout << L"��";
	}
	wcout << L"�� ";
	command = _getch();
	while (command != EOF)
	{
		hin = GetStdHandle(STD_OUTPUT_HANDLE);
		if (command == 75) //left
		{
			pos.X = 40;
			pos.Y = 14;
			SetConsoleCursorPosition(hin, pos);
			SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x90);
			wcout << L"�O";
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			pos.X = 46;
			pos.Y = 14;
			SetConsoleCursorPosition(hin, pos);
			wcout << L"�_";
			pos.X = 40;
			pos.Y = 14;
			SetConsoleCursorPosition(hin, pos);
		}
		if (command == 77) //right
		{
			pos.X = 46;
			pos.Y = 14;
			SetConsoleCursorPosition(hin, pos);
			SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x90);
			wcout << L"�_";
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			pos.X = 40;
			pos.Y = 14;
			SetConsoleCursorPosition(hin, pos);
			wcout << L"�O";
			pos.X = 46;
			pos.Y = 14;
			SetConsoleCursorPosition(hin, pos);
		}
		if (command == 13) //enter
		{
			if (pos.X == 46)
			{
				EnterThree();
				break;
			}
			else if (pos.X == 40)
			{
				EnterTwo();
				break;
			}
		}
		command = _getch();
	}
}

void Menu::startTurnFix()
{
	ifstream file;
	file.open("Board.txt");
	string line;
	int row = 0;
	while (getline(file, line)) {
		if (row == 10) {
			if (line == "1") {
				Menu::redFirst = true;
			}
			break;
		}
		row++;
	}
	ShowD temp;
	temp.showTurn();
}