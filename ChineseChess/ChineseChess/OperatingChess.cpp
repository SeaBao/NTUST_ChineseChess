#include "OperatingChess.h"
#include "ChessWalking.h"
#include "Board.h"
#include "Menu.h"
#include <windows.h>
#include <iostream>

OperatingChess::OperatingChess()
{
	command = _getch();
	pos.X = Board::CurrentBoard.ConvertToConsolePoint(4,10).X;
	pos.Y = Board::CurrentBoard.ConvertToConsolePoint(4,10).Y;
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
			auto temp1 = Board::CurrentBoard[Board::ConvertToBoardPoint().y][Board::ConvertToBoardPoint().x];
			auto temp3 = Board::CurrentBoard[Board::ConvertToBoardPoint().y][Board::ConvertToBoardPoint().x];
			ChessWalking now(temp1.GetID(), temp1.GetTeam(), Board::ConvertToBoardPoint().x, Board::ConvertToBoardPoint().y);

			if (isChoosed == 1 && previousCursonX == Board::ConvertToBoardPoint().x && previousCursonY == Board::ConvertToBoardPoint().y && temp1.GetID() != 0)
			{
				HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
				wcout << Board::CurrentBoard[Board::ConvertToBoardPoint().y][Board::ConvertToBoardPoint().x].GetText();

				SetConsoleCursorPosition(hin, pos);
				isChoosed = 0;
			}

			else if (!isChoosed && temp1.GetID() != 0)
			{
				int tempX = pos.X;
				int tempY = pos.Y;
				previousChess = temp1;
				HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x90);
				wcout << Board::CurrentBoard[Board::ConvertToBoardPoint().y][Board::ConvertToBoardPoint().x].GetText();
				previousCursonX = Board::ConvertToBoardPoint().x;
				previousCursonY = Board::ConvertToBoardPoint().y;
				isChoosed = 1;

				now.printWhereCanGO(Board::CurrentBoard[previousCursonY][previousCursonX].GetID(), previousCursonX, previousCursonY);
				pos.X = tempX;
				pos.Y = tempY;

				SetConsoleCursorPosition(hin, pos);
			}


			//走路
			else if (isChoosed && (previousCursonX != Board::ConvertToBoardPoint().x || previousCursonY != Board::ConvertToBoardPoint().y))
			{
				int tempX = pos.X;
				int tempY = pos.Y;
				auto temp1 = Board::CurrentBoard[previousCursonY][previousCursonX];
				int x = Board::ConvertToBoardPoint().x, y = Board::ConvertToBoardPoint().y, currentx = Board::ConvertToBoardPoint().x, currenty = Board::ConvertToBoardPoint().y;
				
					int flag = 0;
					if (Board::CurrentBoard[previousCursonY][previousCursonX].GetID() == 6 || Board::CurrentBoard[previousCursonY][previousCursonX].GetID() == 13)
					{
						int obstacleFirst = 0;
						if (currenty == previousCursonY)
						{
							if (currentx - previousCursonX > 0)
							{
								for (int i = previousCursonX + 1; i <= 10; i++)
								{
									if (Board::CurrentBoard[currenty][i].GetID() != 0)
									{

										if (obstacleFirst == 1)
										{
											x = i;
											y = currenty;
											break;
										}
										if (obstacleFirst == 0)obstacleFirst = 1;
									}
								}
							}
							else if (currentx - previousCursonX < 0)
							{
								for (int i = previousCursonX - 1; i >= 0; i--)
								{
									if (Board::CurrentBoard[currenty][i].GetID() != 0)
									{

										if (obstacleFirst == 1)
										{
											x = i;
											y = currenty;
											break;
										}
										if (obstacleFirst == 0)obstacleFirst = 1;
									}
								}
							}
						}
						else if (currentx == previousCursonX)
						{
							if (currenty - previousCursonY > 0)
							{
								for (int i = previousCursonY + 1; i <= 10; i++)
								{
									if (Board::CurrentBoard[i][currentx].GetID() != 0)
									{

										if (obstacleFirst == 1)
										{
											x = currentx;
											y = i;
											break;
										}
										if (obstacleFirst == 0)obstacleFirst = 1;
									}
								}
							}
							else if (currenty - previousCursonY < 0)
							{

								for (int i = previousCursonY - 1; i >= 0; i--)
								{
									if (Board::CurrentBoard[i][currentx].GetID() != 0)
									{


										if (obstacleFirst == 1)
										{
											x = currentx;
											y = i;
											break;
										}
										if (obstacleFirst == 0)obstacleFirst = 1;
									}
								}
							}
						}
						else
						{
							x = -1;
							y = -1;
						}
					}
				
				if (now.walk(temp1.GetID(), Board::ConvertToBoardPoint().x, Board::ConvertToBoardPoint().y, previousCursonX, previousCursonY, Board::CurrentBoard[previousCursonY][previousCursonX].GetText(), temp1,x,y))
				{
				
					if (temp3.GetID() != 0)//當前游標有棋子的話
					{

						if (temp3.GetTeam() != temp1.GetTeam())//如果棋種不相同
						{
							ChessWalking temp;
							

								
								


									Board::CurrentBoard[Board::ConvertToBoardPoint().y][Board::ConvertToBoardPoint().x] = previousChess;
									int tempX = pos.X;
									int tempY = pos.Y;
									temp.printText(Board::ConvertToBoardPoint().y, Board::ConvertToBoardPoint().x, Board::CurrentBoard[previousCursonY][previousCursonX].GetText(), pos, previousChess);
									pos = temp2.ConvertToConsolePoint(previousCursonX, previousCursonY);
									Board::CurrentBoard[previousCursonY][previousCursonX] = Chess(0, L'\0', false);
									HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
									SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | 0x00);
									SetConsoleCursorPosition(hin, pos);

									wcout << Board::CurrentBoard.GetGraphicStr(previousCursonX, previousCursonY);
									pos.X = tempX;
									pos.Y = tempY;
									SetConsoleCursorPosition(hin, pos);
									isChoosed = 0;
								


							}
						}






					


					else//當前游標沒棋子的話
					{

						pos = temp2.ConvertToConsolePoint(previousCursonX, previousCursonY);
						HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | 0x00);
						SetConsoleCursorPosition(hin, pos);

						wcout << Board::CurrentBoard.GetGraphicStr(previousCursonX, previousCursonY);
						Board::CurrentBoard[previousCursonY][previousCursonX] = Chess(0, L'\0', false);
						pos.X = tempX;
						pos.Y = tempY;
						SetConsoleCursorPosition(hin, pos);
						isChoosed = 0;
					}

				}







			}
		}
		else if (command == 27)//esc
		{
		Menu temp;

		}

				command = _getch();
	}

}
OperatingChess::~OperatingChess()
{

}
