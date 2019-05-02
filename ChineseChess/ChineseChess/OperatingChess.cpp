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
			
			Board temp2;
			auto temp1 =Board::CurrentBoard[Board::ConvertToBoardPoint().y][Board::ConvertToBoardPoint().x];
			ChessWalking now(temp1.GetID(), temp1.GetTeam(), Board::ConvertToBoardPoint().x, Board::ConvertToBoardPoint().y);
			if (temp1.GetID() != 0)
			{
					 if (isChoosed == 1 && previousCursonX == Board::ConvertToBoardPoint().x &&previousCursonY == Board::ConvertToBoardPoint().y)
					{
						HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
						wcout << Board::CurrentBoard[Board::ConvertToBoardPoint().y][Board::ConvertToBoardPoint().x].GetText();
						
						SetConsoleCursorPosition(hin, pos);
						isChoosed = 0;
					}
					else if (isChoosed && (previousCursonX != Board::ConvertToBoardPoint().x || previousCursonY != Board::ConvertToBoardPoint().y))//旗子碰撞 林志浩
					{
						 cout << "?";
						 pos = temp2.ConvertToConsolePoint(previousCursonX, previousCursonY);
						 HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
						 SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
						 SetConsoleCursorPosition(hin, pos);
						 //wcout << "";
						
						 isChoosed = 0;
					}
					else if (!isChoosed)
					{
						HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x90);
						wcout << Board::CurrentBoard[Board::ConvertToBoardPoint().y][Board::ConvertToBoardPoint().x].GetText();

						previousCursonX = Board::ConvertToBoardPoint().x;
						previousCursonY = Board::ConvertToBoardPoint().y;
						isChoosed = 1;
						
						//now.printWhereCanGO();
						SetConsoleCursorPosition(hin, pos);
					}

			}
			//走路
			else if (isChoosed && (previousCursonX != Board::ConvertToBoardPoint().x || previousCursonY != Board::ConvertToBoardPoint().y))
			{
				int tempX =pos.X;
				int tempY = pos.Y;
				auto temp1 = Board::CurrentBoard[previousCursonY][previousCursonX];
				if(now.walk(temp1.GetID(), Board::ConvertToBoardPoint().x, Board::ConvertToBoardPoint().y, Board::CurrentBoard[previousCursonY][previousCursonX].GetText(),temp1))
				{
					pos = temp2.ConvertToConsolePoint(previousCursonX, previousCursonY);
					HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
					SetConsoleCursorPosition(hin, pos);
					wcout << "  ";
					Board::CurrentBoard[previousCursonY][previousCursonX] = Chess(0, L'\0', false);
					pos.X = tempX;
					pos.Y = tempY;
					SetConsoleCursorPosition(hin, pos);
					isChoosed = 0;
				}
				
				
				
			}
			
			
		}
		else if (command == 27)//esc
		{
			Menu temp;
			temp.printMenu();
		}
		
		command = _getch();
	}
}


OperatingChess::~OperatingChess()
{
}
