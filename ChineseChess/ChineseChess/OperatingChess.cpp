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
		if (command == 75)
		{
			pos.X = pos.X - 4;
			SetConsoleCursorPosition(hin, pos);
		}
		else if (command == 72)
		{
			pos.Y = pos.Y - 2;
			SetConsoleCursorPosition(hin, pos);
		}
		else if (command == 77)
		{
			pos.X = pos.X + 4;
			SetConsoleCursorPosition(hin, pos);
		}
		else if (command == 80)
		{
			pos.Y = pos.Y + 2;
			SetConsoleCursorPosition(hin, pos);
		}
		else if (command == 13)
		{

		}
		command = _getch();
		
		wcout << Board::ConvertToBoardPoint().x << " " << Board::ConvertToBoardPoint().y << endl;
	}
}


OperatingChess::~OperatingChess()
{
}
