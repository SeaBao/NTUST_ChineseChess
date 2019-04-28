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
			pos.X = pos.X - 4;
			SetConsoleCursorPosition(hin, pos);
			if (Board::ConvertToBoardPoint().x <= -1)
			{
				pos.X = pos.X + 4;
			}

		
			SetConsoleCursorPosition(hin, pos);
		}
		else if (command == 72)//up
		{
			pos.Y = pos.Y - 2;
	
			SetConsoleCursorPosition(hin, pos);
			if (Board::ConvertToBoardPoint().y <= -1)
			{
				pos.Y = pos.Y + 2;
			}
			SetConsoleCursorPosition(hin, pos);
		}
		else if (command == 77)//right
		{
			pos.X = pos.X + 4;
			SetConsoleCursorPosition(hin, pos);
			if (Board::ConvertToBoardPoint().x <= -1)
			{
				pos.X = pos.X - 4;
			}
			SetConsoleCursorPosition(hin, pos);
		}
		else if (command == 80)//down
		{
			pos.Y = pos.Y + 2;

			SetConsoleCursorPosition(hin, pos);
			if (Board::ConvertToBoardPoint().y <= -1)
			{
				pos.Y = pos.Y - 2;
			}
			SetConsoleCursorPosition(hin, pos);
		}
		else if (command == 13)
		{
			auto temp1 =Board::CurrentBoard[Board::ConvertToBoardPoint().y][Board::ConvertToBoardPoint().x];
			
			if (temp1.GetID() != 0)
			{
					 if (isChoosed == 1 && temp1.GetID() == previousChessID)
					{
						HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
						wcout << Board::CurrentBoard[Board::ConvertToBoardPoint().y][Board::ConvertToBoardPoint().x].GetText();
						SetConsoleCursorPosition(hin, pos);
						isChoosed = 0;
					}
					else if (isChoosed && temp1.GetID() != previousChessID)
					{

					}
					else if (!isChoosed)
					{
						HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x90);
						wcout << Board::CurrentBoard[Board::ConvertToBoardPoint().y][Board::ConvertToBoardPoint().x].GetText();
						previousChessID = temp1.GetID();
						isChoosed = 1;
						SetConsoleCursorPosition(hin, pos);
					}

			}
			
			
		}
		
		command = _getch();
	}
}


OperatingChess::~OperatingChess()
{
}
