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
	wcout << L"ùÝ ";
	for (int i = 0; i < MenuWidth - 2; i++)
	{
		wcout << L"ùù";
	}
	wcout << L"ùß \n";
	pos.Y = 7;
	SetConsoleCursorPosition(hOut, pos);
	//wcout << L"ùø    Ä~Äò¹CÀ¸   ùø \n";
	wcout << L"ùø    ";
	SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x90);
	wcout << L"Ä~Äò¹CÀ¸";
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	wcout << L"   ùø \n";
	pos.Y = 8;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"ùøùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùø \n";
	pos.Y = 9;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"ùø    ";
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	wcout << L"­«·s¶}©l";
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	wcout << L"   ùø \n";
	pos.Y = 10;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"ùøùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùø \n";
	pos.Y = 11;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"ùø    ";
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	wcout << L"¦^¥D¿ï³æ";
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	wcout << L"   ùø \n";
	pos.Y = 12;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"ùøùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùùø \n";
	pos.Y = 13;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"ùø    ";
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	wcout << L"Â÷¶}¹CÀ¸";
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	wcout << L"   ùø \n";
	pos.Y = 14;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"ùã ";
	for (int i = 0; i < MenuWidth - 2; i++)
	{
		wcout << L"ùù";
	}
	wcout << L"ùå ";
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
		wcout << L"Ä~Äò¹CÀ¸";
		pos.Y = 9, pos.X = 43;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		wcout << L"­«·s¶}©l";
		pos.X = 42, pos.Y = 7;
		SetConsoleCursorPosition(hin, pos);
	}
	else if (pos.Y == 9)
	{
		SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x90);
		wcout << L"­«·s¶}©l";
		pos.Y = 7, pos.X = 43;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		wcout << L"Ä~Äò¹CÀ¸";
		pos.Y = 11, pos.X = 43;
		SetConsoleCursorPosition(hOut, pos);
		wcout << L"¦^¥D¿ï³æ";
		pos.Y = 9, pos.X = 42;
		SetConsoleCursorPosition(hOut, pos);
	}
	else if (pos.Y == 11)
	{
		SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x90);
		wcout << L"¦^¥D¿ï³æ";
		pos.Y = 9, pos.X = 43;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		wcout << L"­«·s¶}©l";
		pos.Y = 13, pos.X = 43;
		SetConsoleCursorPosition(hOut, pos);
		wcout << L"Â÷¶}¹CÀ¸";
		pos.Y = 11, pos.X = 42;
		SetConsoleCursorPosition(hOut, pos);
	}
	else if (pos.Y == 13)
	{
		SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x90);
		wcout << L"Â÷¶}¹CÀ¸";
		pos.Y = 11, pos.X = 43;
		SetConsoleCursorPosition(hOut, pos);
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		wcout << L"¦^¥D¿ï³æ";
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
	wcout << L"ùÝ ";
	for (int i = 0; i < 10; i++)
	{
		wcout << L"ùù";
	}
	wcout << L"ùß \n";
	pos.Y = 8;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"ùø  ¶Â¤è³Ó§Q ùø \n";
	pos.Y = 9;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"ùã ";
	for (int i = 0; i < 10; i++)
	{
		wcout << L"ùù";
	}
	wcout << L"ùå ";
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
	wcout << L"ùÝ ";
	for (int i = 0; i < 10; i++)
	{
		wcout << L"ùù";
	}
	wcout << L"ùß \n";
	pos.Y = 8;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"ùø  ¬õ¤è³Ó§Q ùø \n";
	pos.Y = 9;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"ùã ";
	for (int i = 0; i < 10; i++)
	{
		wcout << L"ùù";
	}
	wcout << L"ùå ";
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
	wcout << L"ùÝ ";
	for (int i = 0; i < 12; i++)
	{
		wcout << L"ùù";
	}
	wcout << L"ùß \n";
	pos.Y = 12;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"ùø   ¶}±Ò·s§½? ùø ";
	pos.Y = 13;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"ùø             ùø ";
	pos.Y = 14;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"ùø   ";
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	wcout << L"¬O    §_";
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	wcout << L"  ùø ";
	pos.Y = 15;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"ùã ";
	for (int i = 0; i < 12; i++)
	{
		wcout << L"ùù";
	}
	wcout << L"ùå ";
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
			wcout << L"¬O";
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			pos.X = 46;
			pos.Y = 14;
			SetConsoleCursorPosition(hin, pos);
			wcout << L"§_";
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
			wcout << L"§_";
			SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			pos.X = 40;
			pos.Y = 14;
			SetConsoleCursorPosition(hin, pos);
			wcout << L"¬O";
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