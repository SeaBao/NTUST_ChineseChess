#include "OperatingChess.h"
#include <windows.h>
#include <iostream>
#include "Board.h"

OperatingChess::OperatingChess()
{
	command = _getch();
	pos.X = 42, pos.Y = 2; // 將位置設在 (5,5) 之地方。
	hin = GetStdHandle(STD_OUTPUT_HANDLE);
}


void OperatingChess::gameStart()
{
	
	while (command != EOF)
	{
		//Board::CurrentBoard.PrintMap();
		hin = GetStdHandle(STD_OUTPUT_HANDLE);
		if (command == 75)//left
		{
			if (Board::ConvertToBoardPoint().x != 0) {
				pos.X -= 4;
				SetConsoleCursorPosition(hin, pos);
			}
		}
		else if (command == 72)//up
		{
			if (Board::ConvertToBoardPoint().y != 0) {
				pos.Y -= 2;
				SetConsoleCursorPosition(hin, pos);
			}
		}
		else if (command == 77)//right
		{
			if (Board::ConvertToBoardPoint().x != 8) {
				pos.X += 4;
				SetConsoleCursorPosition(hin, pos);
			}
		}
		else if (command == 80)//down
		{
			if (Board::ConvertToBoardPoint().y != 10) {
				pos.Y += 2;
				SetConsoleCursorPosition(hin, pos);
			}
		}
		else if (command == 13)
		{
			HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x90);
			cout << "test";
		}
		
		command = _getch();
	}
}


OperatingChess::~OperatingChess()
{
}
