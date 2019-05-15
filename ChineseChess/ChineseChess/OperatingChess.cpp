#include "OperatingChess.h"
#include "ChessWalking.h"
#include "clear.cpp"
#include "Board.h"
#include "Menu.h"
#include "LogPanel.h"
#include"ShowD.h"
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
	Menu start;
	start.startTurnFix();

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
				int powBarrierX=0;
				int powBarrierY=0;
				auto temp1 = Board::CurrentBoard[previousCursonY][previousCursonX];
				int x = Board::ConvertToBoardPoint().x, y = Board::ConvertToBoardPoint().y, currentx = Board::ConvertToBoardPoint().x, currenty = Board::ConvertToBoardPoint().y;
					int flag = 0,count=0;
					
				
				if (now.walk(temp1.GetID(), Board::ConvertToBoardPoint().x, Board::ConvertToBoardPoint().y, previousCursonX, previousCursonY, Board::CurrentBoard[previousCursonY][previousCursonX].GetText(), temp1,x,y,flag))
				{
					int redWillLose = 0, blackWillLose = 0;
					
					Board::CurrentBoard[previousCursonY][previousCursonX] = Chess::GetChessByID(0);
					int blackCaptainX = 0, blackCaptainY = 0, redCaptainX = 0, redCaptainY = 0, hasChess = 0;
					for (int i = 3; i <= 5; i++)
					{
						for (int k = 0; k <= 2; k++)
						{
							if (Board::CurrentBoard[k][i].GetID() == 1)
							{
								blackCaptainX = i;
								blackCaptainY = k;
							}
						}
						for (int k = 7; k <= 9; k++)
						{
							if (Board::CurrentBoard[k][i].GetID() == 8)
							{
								redCaptainX = i;
								redCaptainY = k;
							}
						}
					}
					if (blackCaptainX == redCaptainX)
					{
						for (int i = blackCaptainY + 1; i <= redCaptainY - 1; i++)
						{
							if (Board::CurrentBoard[i][blackCaptainX].GetID() != 0)
							{
								hasChess++;
							}
						}
					}
					else if (blackCaptainX != redCaptainX)hasChess++;
					if (hasChess == 0)
					{
						if (turn % 2 == 0)
						{
							Menu temp;
							temp.blackWins();
						}
						else
						{
							Menu temp;
							temp.redWins();
						}
					}
					for (int xx = 0; xx <= 8; xx++)
					{
						for (int yy = 0; yy <= 9; yy++)
						{
							if (Board::CurrentBoard[yy][xx].GetID() == 4)
							{
								int flag = 1;
								if (xx == redCaptainX)
								{
									if (yy > redCaptainY)
									{
										for (int i = redCaptainY + 1; i < yy; i++)
										{
											if (Board::CurrentBoard[i][xx].GetID() != 0)
											{
												flag = 0;
												break;
											}
										}
									}
									else if (yy < redCaptainY)
									{
										for (int i = yy + 1; i < redCaptainY; i++)
										{
											if (Board::CurrentBoard[i][xx].GetID() != 0)
											{
												flag = 0;
												break;
											}
										}

									}
								}
								else if (yy == redCaptainY)
								{
									if (xx > redCaptainX)
									{
										for (int i = redCaptainX + 1; i < xx; i++)
										{
											if (Board::CurrentBoard[yy][i].GetID() != 0)
											{
												flag = 0;
												break;
											}
										}
									}
									else if (xx < redCaptainX)
									{
										for (int i = xx + 1; i < redCaptainX; i++)
										{
											if (Board::CurrentBoard[yy][i].GetID() != 0)
											{
												flag = 0;
												break;
											}
										}

									}
								}
								else flag = 0;
								if (flag)
								{
									redWillLose = 1;
								}

							}
							else if (Board::CurrentBoard[yy][xx].GetID() == 5)
							{
								int flag = 0;
								if ((abs(xx - redCaptainX) + abs(yy - redCaptainY) == 3) && abs(xx - redCaptainX) != 0 && abs(yy - redCaptainY) != 0)
								{
									if (xx - redCaptainX == 2)
									{
										if (Board::CurrentBoard[yy][xx - 1].GetID() == 0)
										{
											flag = 1;
										}
									}
									else if (xx - redCaptainX == -2)
									{
										if (Board::CurrentBoard[yy][xx + 1].GetID() == 0)
										{
											 flag = 1;
										}
									
									}
									if (yy - redCaptainY == 2)
									{
										if (Board::CurrentBoard[yy - 1][xx].GetID() == 0)
										{
											flag = 1;
										}
										
									}
									else if (yy - redCaptainY == -2)
									{
										if (Board::CurrentBoard[yy+ 1][xx].GetID() == 0)
										{
											 flag = 1;
										}
										
									}

								}

								if (flag )
								{
									redWillLose = 1;
								}
							}
							else if (Board::CurrentBoard[yy][xx].GetID() == 6)
							{
							int rightx = 0, righty = 0, upx = 0, upy = 0, leftx = 0, lefty = 0, downx = 0, downy = 0, countRight = 0, countUp = 0, countLeft = 0, countDown = 0;
							for (int i = xx + 1; i < 9; i++)
							{
								if (Board::CurrentBoard[yy][i].GetID() != 0)
								{
									countRight++;
								}
								if (countRight == 2)
								{
									rightx = i;
									righty = yy;
									break;
								}
							}
							for (int i = xx - 1; i >= 0; i--)
							{
								if (Board::CurrentBoard[yy][i].GetID() != 0)
								{
									countLeft++;
								}
								if (countLeft == 2)
								{
									leftx = i;
									lefty = yy;
									break;
								}
							}
							for (int i = yy + 1; i < 10; i++)
							{
								if (Board::CurrentBoard[i][xx].GetID() != 0)
								{
									countDown++;
								}
								if (countDown == 2)
								{
									downx = xx;
									downy = i;
									break;
								}
							}
							for (int i = yy - 1; i >= 0; i--)
							{
								if (Board::CurrentBoard[i][xx].GetID() != 0)
								{
									countUp++;
								}
								if (countUp == 2)
								{
									upx = xx;
									upy = i;
									break;
								}
							}
							if ((redCaptainX == rightx && redCaptainY == righty && countRight == 2) || (redCaptainX == leftx && redCaptainY == lefty && countLeft == 2) || (redCaptainX == upx && redCaptainY == upy && countUp == 2) || (redCaptainX == downx && redCaptainY == downy && countDown == 2))
							{

								if (countLeft == 2)
								{
									redWillLose = 1;

								}
								if (countRight == 2)
								{
									redWillLose = 1;
								}
								if (countDown == 2)
								{


									redWillLose = 1;

								}
								if (countUp == 2)
								{
									redWillLose = 1;
								}

							}
							}
							else if (Board::CurrentBoard[yy][xx].GetID() == 7)
							{
							if ((abs(redCaptainX - xx) + abs(redCaptainY - yy) > 1))
							{

								}
							else if (yy < redCaptainY)
							{

							}
								else
								{
								redWillLose = 1;	
								}
							}

							if (Board::CurrentBoard[yy][xx].GetID() == 11)
							{
								int flag = 1;
								if (xx == blackCaptainX)
								{
									if (yy > blackCaptainY)
									{
										for (int i = blackCaptainY + 1; i < yy; i++)
										{
											if (Board::CurrentBoard[i][xx].GetID() != 0)
											{
												flag = 0;
												break;
											}
										}
									}
									else if (yy < blackCaptainY)
									{
										for (int i = yy + 1; i < blackCaptainY; i++)
										{
											if (Board::CurrentBoard[i][xx].GetID() != 0)
											{
												flag = 0;
												break;
											}
										}

									}
								}
								else if (yy == blackCaptainY)
								{
									if (xx > blackCaptainX)
									{
										for (int i = blackCaptainX + 1; i < xx; i++)
										{
											if (Board::CurrentBoard[yy][i].GetID() != 0)
											{
												flag = 0;
												break;
											}
										}
									}
									else if (xx < blackCaptainX)
									{
										for (int i = xx + 1; i < blackCaptainX; i++)
										{
											if (Board::CurrentBoard[yy][i].GetID() != 0)
											{
												flag = 0;
												break;
											}
										}

									}
								}
								else flag = 0;
								if (flag)
								{
									ShowD temp;
									temp.blackShowCheckmate();
									blackWillLose = 1;
								}
							}
							else if (Board::CurrentBoard[yy][xx].GetID() == 12)
							{
								
								int flag = 0;
								if ((abs(xx - blackCaptainX) + abs(yy - blackCaptainY) == 3) && abs(xx - blackCaptainX) != 0 && abs(yy - blackCaptainY) != 0)
								{
									if (xx - blackCaptainX == 2)
									{
										if (Board::CurrentBoard[yy][xx - 1].GetID() == 0)
										{
											flag = 1;
											
										}
									}
									else if (xx - blackCaptainX == -2)
									{
										if (Board::CurrentBoard[yy][xx + 1].GetID() == 0)
										{
											flag = 1;
										}

									}
									if (yy - blackCaptainY == 2)
									{
										if (Board::CurrentBoard[yy - 1][xx].GetID() == 0)
										{
											flag = 1;
										}

									}
									else if (yy - blackCaptainY == -2)
									{
										if (Board::CurrentBoard[yy + 1][xx].GetID() == 0)
										{
											flag = 1;
										}

									}

								}

								if (flag )
								{
									blackWillLose = 1;
								}
							}
							else if (Board::CurrentBoard[yy][xx].GetID() == 13)
							{
							int rightx = 0, righty = 0, upx = 0, upy = 0, leftx = 0, lefty = 0, downx = 0, downy = 0, countRight = 0, countUp = 0, countLeft = 0, countDown = 0;
							for (int i = xx + 1; i < 9; i++)
							{
								if (Board::CurrentBoard[yy][i].GetID() != 0)
								{
									countRight++;
								}
								if (countRight == 2)
								{
									rightx = i;
									righty = yy;
									break;
								}
							}
							for (int i = xx - 1; i >= 0; i--)
							{
								if (Board::CurrentBoard[yy][i].GetID() != 0)
								{
									countLeft++;
								}
								if (countLeft == 2)
								{
									leftx = i;
									lefty = yy;
									break;
								}
							}
							for (int i = yy + 1; i < 10; i++)
							{
								if (Board::CurrentBoard[i][xx].GetID() != 0)
								{
									countDown++;
								}
								if (countDown == 2)
								{
									downx = xx;
									downy = i;
									break;
								}
							}
							for (int i = yy - 1; i >= 0; i--)
							{
								if (Board::CurrentBoard[i][xx].GetID() != 0)
								{
									countUp++;
								}
								if (countUp == 2)
								{
									upx = xx;
									upy = i;
									break;
								}
							}
							if ((blackCaptainX == rightx && blackCaptainY == righty && countRight == 2) || (blackCaptainX == leftx && blackCaptainY == lefty && countLeft == 2) || (blackCaptainX == upx && blackCaptainY == upy && countUp == 2) || (blackCaptainX == downx && blackCaptainY == downy && countDown == 2))
							{

								if (countLeft == 2)
								{
									blackWillLose = 1;

								}
								if (countRight == 2)
								{
									blackWillLose = 1;
								}
								if (countDown == 2)
								{


									blackWillLose = 1;

								}
								if (countUp == 2)
								{
									blackWillLose = 1;
								}

							}
							}
							else if (Board::CurrentBoard[yy][xx].GetID() == 14)
							{
								if (abs(blackCaptainX - xx) + abs(blackCaptainY - yy) > 1)
								{

								}
								else if (blackCaptainY > yy)
								{

								}
								else
								{
									blackWillLose = 1;
								}
							}
							
						}
					}
					if (blackWillLose)
					{
						ShowD temp;
						temp.blackShowCheckmate();
					}
					else
					{
						ShowD temp;
						temp.blackCancelCheckmate();
					}
					if (redWillLose)
					{
						ShowD temp;
						temp.redShowCheckmate();
					}
					else
					{
						ShowD temp;
						temp.redCancelCheckmate();

					}
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
