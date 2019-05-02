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
		else if (command == 13)//ENTER
		{
			auto temp1 =Board::CurrentBoard[Board::ConvertToBoardPoint().y][Board::ConvertToBoardPoint().x];
			
			if (temp1.GetID() != 0)
			{
					 if (isChoosed == 1 && previousCursonX == Board::ConvertToBoardPoint().x &&previousCursonY == Board::ConvertToBoardPoint().y)
					{
						HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
						wcout << Board::CurrentBoard[Board::ConvertToBoardPoint().y][Board::ConvertToBoardPoint().x].GetText();
						ChessWalking now(temp1.GetID(),);
						SetConsoleCursorPosition(hin, pos);
						isChoosed = 0;
					}
					else if (isChoosed && (previousCursonX != Board::ConvertToBoardPoint().x || previousCursonY != Board::ConvertToBoardPoint().y))
					{

					}
					else if (!isChoosed)
					{
						HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x90);
						wcout << Board::CurrentBoard[Board::ConvertToBoardPoint().y][Board::ConvertToBoardPoint().x].GetText();

						previousCursonX = Board::ConvertToBoardPoint().x;
						previousCursonY = Board::ConvertToBoardPoint().y;
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
