#include "OperatingChess.h"
#include "ChessWalking.h"
#include "clear.cpp"
#include "Board.h"
#include "Menu.h"
#include "LogPanel.h"
#include "regret.h"
#include "Utility.h"
#include <conio.h>
#include <iostream>

OperatingChess::OperatingChess()
{
	previousCursonX = -1;
	previousCursonY = -1;
	CurrentCursonX = -1;
	CurrentCursonY = -1;
	isChoosed = false;
	pos.X = Board::CurrentBoard.ConvertToConsolePoint(4,9).X;
	pos.Y = Board::CurrentBoard.ConvertToConsolePoint(4,9).Y;
	hin = GetStdHandle(STD_OUTPUT_HANDLE);
}


void OperatingChess::gameStart()
{
	ChessWalking record;
	while (command != EOF)
	{
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
			if (Board::ConvertToBoardPoint().y != 9) {
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

				if (temp1.GetTeam()) {
					SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY);
				}
				else {
					 
					SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY | FOREGROUND_RED);
				}
				
				wcout << Board::CurrentBoard[Board::ConvertToBoardPoint().y][Board::ConvertToBoardPoint().x].GetText();
				
				record.clearWhereCanGO();
				SetConsoleCursorPosition(hin, pos);
				isChoosed = 0;
				turn++;
			}

			else if (!isChoosed && temp1.GetID() != 0)
			{
			
				
				if (turn % 2 == 1 && temp1.GetTeam() == false)
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

					now.printWhereCanGO(Board::CurrentBoard[previousCursonY][previousCursonX].GetID(), previousCursonX, previousCursonY, record);
					pos.X = tempX;
					pos.Y = tempY;

					SetConsoleCursorPosition(hin, pos);
					turn++;
				}
				else if (turn % 2 == 0 && temp1.GetTeam() == true)
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
				
					now.printWhereCanGO(Board::CurrentBoard[previousCursonY][previousCursonX].GetID(), previousCursonX, previousCursonY, record);
					
					pos.X = tempX;
					pos.Y = tempY;

					SetConsoleCursorPosition(hin, pos);
					turn++;
				
				}
				
			}
			//走路
			else if (isChoosed && (previousCursonX != Board::ConvertToBoardPoint().x || previousCursonY != Board::ConvertToBoardPoint().y))
			{
				int tempX = pos.X;
				int tempY = pos.Y;
				int powBarrierX;
				int powBarrierY;
				auto temp1 = Board::CurrentBoard[previousCursonY][previousCursonX];
				int x = Board::ConvertToBoardPoint().x, y = Board::ConvertToBoardPoint().y, currentx = Board::ConvertToBoardPoint().x, currenty = Board::ConvertToBoardPoint().y;
					int flag = 0,count=0;
					if (Board::CurrentBoard[previousCursonY][previousCursonX].GetID() == 6 || Board::CurrentBoard[previousCursonY][previousCursonX].GetID() == 13)
					{
						int obstacleFirst = 0;
						if (currenty == previousCursonY)
						{
							if (currentx - previousCursonX > 0)
							{
								for (int i = previousCursonX+1; i <= 8; i++)
								{
									if (Board::CurrentBoard[currenty][i].GetID() != 0)
									{

										if (obstacleFirst == 1)
										{
											x = i;
											y = currenty;
											break;
										}
										if (obstacleFirst == 0)
										{
											powBarrierX = i;
											powBarrierY = currenty;
											obstacleFirst = 1;
										}
									}
								}
								for (int i = previousCursonX + 1; i <= 8; i++)
								{
									if (Board::CurrentBoard[currenty][i].GetID() != 0)
									{
										count++;
									}
								}
								if (x >= currentx&&count>1)flag = 1;
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
										if (obstacleFirst == 0)
										{
											powBarrierX = i;
											powBarrierY = currenty;
											obstacleFirst = 1;
										}
									}
								}
								for (int i = previousCursonX - 1; i >= 0; i--)
								{
									if (Board::CurrentBoard[currenty][i].GetID() != 0)
									{
										count++;
									}
								}
								if (x <= currentx && count > 1)flag = 1;
							}
						}
						else if (currentx == previousCursonX)
						{
							if (currenty - previousCursonY > 0)
							{
								for (int i = previousCursonY + 1; i <= 9; i++)
								{
									if (Board::CurrentBoard[i][currentx].GetID() != 0)
									{

										if (obstacleFirst == 1)
										{
											x = currentx;
											y = i;
											break;
										}
										if (obstacleFirst == 0)
										{
											powBarrierX = currentx;
											powBarrierY =i;
											obstacleFirst = 1;
										}

									}
								}
								for (int i = previousCursonY + 1; i <= 9; i++)
								{
									if (Board::CurrentBoard[i][currentx].GetID() != 0)
									{										
											count++;
									}
								}
								
								if (y >= currentx && count > 1)flag = 1;
								
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
										if (obstacleFirst == 0) {
											powBarrierX = currentx;
											powBarrierY = i;
											obstacleFirst = 1;
										}
									}
								}
								for (int i = previousCursonY - 1; i >=0; i--)
								{
									if (Board::CurrentBoard[i][currentx].GetID() != 0)
									{
										count++;
									}
								}
								if (y >= currentx && count > 1)flag = 1;
							}
						}
						else
						{
							
							flag = 1;
						}
						
					}
				
				if (now.walk(temp1.GetID(), Board::ConvertToBoardPoint().x, Board::ConvertToBoardPoint().y, previousCursonX, previousCursonY, Board::CurrentBoard[previousCursonY][previousCursonX].GetText(), temp1,x,y,flag))
				{
					CurrentCursonX = Board::ConvertToBoardPoint().x;
					CurrentCursonY = Board::ConvertToBoardPoint().y;
					
					if (temp3.GetID() != 0)//當前游標有棋子的話
					{

						if (temp3.GetTeam() != temp1.GetTeam())//如果棋種不相同
						{
							ChessWalking temp;
									Board::CurrentBoard[Board::ConvertToBoardPoint().y][Board::ConvertToBoardPoint().x] = previousChess;
									if ((previousChess.GetID() == 6 || previousChess.GetID() == 13) && Board::ConvertToBoardPoint().x == powBarrierX && Board::ConvertToBoardPoint().y == powBarrierY)
									{

									}
									else
									{
										int tempX = pos.X;
										int tempY = pos.Y;
										temp.printText(Board::ConvertToBoardPoint().y, Board::ConvertToBoardPoint().x, Board::CurrentBoard[previousCursonY][previousCursonX].GetText(), pos, previousChess);
										pos = temp2.ConvertToConsolePoint(previousCursonX, previousCursonY);
										Board::CurrentBoard[previousCursonY][previousCursonX] = Chess(0, L'\0', false);
										HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
										SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | 0x00);
										SetConsoleCursorPosition(hin, pos);
										
										wcout << Board::CurrentBoard.GetGraphicStr(previousCursonX, previousCursonY);
										record.clearWhereCanGO();
										pos.X = tempX;
										pos.Y = tempY;
										
										SetConsoleCursorPosition(hin, pos);

										isChoosed = 0;

									}								
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
						record.clearWhereCanGO();
						pos.X = tempX;
						pos.Y = tempY;
						SetConsoleCursorPosition(hin, pos);
						isChoosed = 0;
						
						
					}
					Board::CurrentBoard.WriteFile(to_string(++Board::ChessSteps) + ".txt", "History");
					Board::CurrentBoard.WriteFile("debug.txt", "History");
					LogPanel::CurrentPanel.AddLog(temp1.GetText(), GetPreviousCursonX(), GetPreviousCursonY(), GetCurrentCursonX(), GetCurrentCursonY(), temp1.GetTeam());
					Regret::roundCount++;
					ShowD::roundCount++;
					ShowD temp;
					temp.showTurn();
				}
				
			}
		}
		else if (command == 27)//esc
		{
			Menu temp;
			Board::CurrentBoard.WriteFile("store.txt", "History");
			temp.printMenu();

		}

		else if (command == ',')//<
		{
			Regret temp;
			if (Regret::roundCount >= 1)
			{
				temp.readLastStore();
			}
		}
		else if (command == '.')//>
		{
			Regret temp;
			temp.readNextStore();
		}

		command = _getch();
	}

}
