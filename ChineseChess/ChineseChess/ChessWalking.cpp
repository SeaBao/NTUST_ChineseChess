#include "ChessWalking.h"
#include"Chess.h"
#include <windows.h>
#include"Board.h"
#include<iostream>
#include "Menu.h"
#include"Utility.h"
#include<math.h>
using namespace std;

void ChessWalking::printWhereToGoRed(int y, int x, COORD pos)
{
	HANDLE hin;
	hin = GetStdHandle(STD_OUTPUT_HANDLE);
	
	if (Board::CurrentBoard[y][x].GetID() == 0)
	{
		Board temp;
		pos = temp.ConvertToConsolePoint(x, y);
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_BLUE | 0x90);
		SetConsoleCursorPosition(hin, pos);
		wcout << Board::CurrentBoard.GetGraphicStr(x, y);

	}
	else if (Board::CurrentBoard[y][x].GetID() != 0 && Board::CurrentBoard[y][x].GetTeam() != false)
	{
		Board temp;
		pos = temp.ConvertToConsolePoint(x, y);
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOut,  BACKGROUND_BLUE | BACKGROUND_GREEN|0x90);
		SetConsoleCursorPosition(hin, pos);
		wcout << Board::CurrentBoard[y][x].GetText();
	}

}
void ChessWalking ::printWhereToGo(int y,int x,COORD pos)
{
	ChessWalking temp;
	HANDLE hin;
	
	hin = GetStdHandle(STD_OUTPUT_HANDLE);
	if (Board::CurrentBoard[y][x].GetID() == 0)
	{
		Board temp;
		pos = temp.ConvertToConsolePoint(x, y);
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_BLUE | 0x90);
		SetConsoleCursorPosition(hin, pos);
		wcout << Board::CurrentBoard.GetGraphicStr(x, y);

	}
	else if (Board::CurrentBoard[y][x].GetID() != 0 && Board::CurrentBoard[y][x].GetTeam() != true)
	{
		Board temp;
		pos = temp.ConvertToConsolePoint(x, y);
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | 0x90);
		SetConsoleCursorPosition(hin, pos);
		wcout << Board::CurrentBoard[y][x].GetText();
	}
	
}

ChessWalking::ChessWalking()
{
}
ChessWalking::ChessWalking(int id, bool blackorred, int x, int y)
{

	hin = GetStdHandle(STD_OUTPUT_HANDLE);
	ID = id;
	blackOrRed = blackorred;
	currentX = x;
	currentY = y;
}
//Chess(0, L'\0', false),
//Chess(1, L'將', true), Chess(2, L'士', true), Chess(3, L'象', true), Chess(4, L'車', true), Chess(5, L'馬', true), Chess(6, L'包', true), Chess(7, L'卒', true),
//Chess(8, L'帥', false), Chess(9, L'仕', false), Chess(10, L'相', false), Chess(11, L'車', false), Chess(12, L'傌', false), Chess(13, L'炮', false), Chess(14, L'兵', false)
int ChessWalking::walk(int id, int x, int y, int& previousCursonX, int &previousCursonY, wchar_t text, Chess temp, int powx,int powy,int powflag)
{
	Board temp1;
	hin = GetStdHandle(STD_OUTPUT_HANDLE);
	pos = temp1.ConvertToConsolePoint(x, y);
	if ((temp.GetTeam() == Board::CurrentBoard[y][x].GetTeam())&& Board::CurrentBoard[y][x].GetID()!=0)return 0;
	if (id == 1)
	{
		if ( (x >= 3 && x <= 5) && (y != -1) && y <= 2 && (abs(x - previousCursonX) + abs(y - previousCursonY) <= 1))
		{
			int count=0, sameY=0;
			for (int i = y + 1; i <= 9; i++)
			{
				if (Board::CurrentBoard[i][x].GetID() != 0)
				{
					if (Board::CurrentBoard[i][x].GetID() == 8)
					{
						sameY = 1;
						break;
					}
					count++;
				}
			}
			if (sameY == 1 && count == 0)return 0;
			printText(y, x, text, pos, temp);
			return 1;
		}
		else return 0;
	}
	else if (id == 2)
	{
		if (  (x >= 3 && x <= 5) && (y >= 0) && (y <= 2) && (abs(x - previousCursonX) == 1 && abs(y - previousCursonY) == 1))
		{
			printText(y, x, text, pos, temp);
			return 1;
		}
		else return 0;
	}
	else if (id == 3)
	{
		if ( Board::CurrentBoard[abs(y + previousCursonY) / 2][abs(x + previousCursonX) / 2].GetID() == 0 && x != -1 && y != -1 && (abs(x - previousCursonX) == 2 && abs(y - previousCursonY) == 2) && y < 5)
		{
			printText(y, x, text, pos, temp);
			return 1;
		}
		else return 0;
	}
	else if (id == 4)
	{

		if (  (x != -1) && (y != -1))
		{
			int hasAObstacleX = x;
			int hasAObstacleY = y;
			if (x == previousCursonX)
			{
				if (y - previousCursonY < 0)
				{
					for (int i = previousCursonY - 1; i > y; i--)
					{
						if (Board::CurrentBoard[i][x].GetID() != 0)
						{
							hasAObstacleY = i;
							break;
						}
					}
				}
				else if (y - previousCursonY > 0)
				{
					for (int i = previousCursonY + 1; i < y; i++)
					{
						if (Board::CurrentBoard[i][x].GetID() != 0)
						{
							hasAObstacleY = i;
							break;
						}
					}
				}
				if (hasAObstacleY == y)
				{
					printText(y, x, text, pos, temp);
					return 1;
				}
				else if ((abs(y - previousCursonY) < abs(previousCursonY - hasAObstacleY) && x == previousCursonX))
				{
					printText(y, x, text, pos, temp);
					return 1;

				}
				else return 0;
			}
			else if (y == previousCursonY)
			{
				if (x - previousCursonX < 0)
				{
					for (int i = previousCursonX - 1; i > x; i--)
					{
						if (Board::CurrentBoard[y][i].GetID() != 0)
						{
							hasAObstacleX = i;
							break;
						}
					}
				}
				else if (x - previousCursonX > 0)
				{
					for (int i = previousCursonX + 1; i < x; i++)
					{
						if (Board::CurrentBoard[y][i].GetID() != 0)
						{
							hasAObstacleX = i;
							break;
						}
					}
				}
				if (hasAObstacleX == x)
				{
					printText(y, x, text, pos, temp);
					return 1;
				}
				else if (abs(x - previousCursonX) < abs(previousCursonX - hasAObstacleX) && y == previousCursonY)
				{

					printText(y, x, text, pos, temp);
					return 1;
				}
			}
			else return 0;
		}
	}
	else if (id == 5)
	{
		if ( x != -1 && y != -1 && (abs(x - previousCursonX) + abs(y - previousCursonY) == 3) && abs(x - previousCursonX) != 0 && abs(y - previousCursonY) != 0)                                          
		{
			if (x - previousCursonX == 2)
			{
				if (Board::CurrentBoard[previousCursonY][previousCursonX + 1].GetID() == 0)
				{

				
					
					printText(y, x, text, pos, temp);
						return 1;
					

				}
				else return 0;
			}
			else if (x - previousCursonX == -2)
			{
				if (Board::CurrentBoard[previousCursonY][previousCursonX - 1].GetID() == 0)
				{

					
						printText(y, x, text, pos, temp);
						return 1;
					

				}
				else return 0;
			}
			if (y - previousCursonY == 2)
			{
				if (Board::CurrentBoard[previousCursonY+1][previousCursonX].GetID() == 0)
				{

						printText(y, x, text, pos, temp);
						return 1;
					

				}
				else return 0;
			}
			else if (y - previousCursonY == -2)
			{
				if (Board::CurrentBoard[previousCursonY-1][previousCursonX ].GetID() == 0)
				{

					
						printText(y, x, text, pos, temp);
						return 1;
					

				}
				else return 0;
			}

		}
		
		else return 0;
	}
	else if (id == 6)

	{
	
	if (powx == x && powy == y && ((powx == previousCursonX) || (powy == previousCursonY)) && (Board::CurrentBoard[y][x].GetID() != 0))
	{
		printText(y, x, text, pos, temp);
		return 1;
	}
	else if (Board::CurrentBoard[Board::ConvertToBoardPoint().y][Board::ConvertToBoardPoint().x].GetID() != 0 && (powx != x || powy != y))
	{
		return 0;
	}
	else
	{
		if ((x != -1) && (y != -1))
		{
			int hasAObstacleX = x;
			int hasAObstacleY = y;
			if (x == previousCursonX)
			{
				if (y - previousCursonY < 0)
				{
					for (int i = previousCursonY - 1; i > y; i--)
					{
						if (Board::CurrentBoard[i][x].GetID() != 0)
						{
							hasAObstacleY = i;
							break;
						}
					}
				}
				else if (y - previousCursonY > 0)
				{
					for (int i = previousCursonY + 1; i < y; i++)
					{
						if (Board::CurrentBoard[i][x].GetID() != 0)
						{
							hasAObstacleY = i;
							break;
						}
					}
				}
				if (hasAObstacleY == y)
				{
					printText(y, x, text, pos, temp);
					return 1;
				}
				else if ((abs(y - previousCursonY) < abs(previousCursonY - hasAObstacleY) && x == previousCursonX))
				{
					printText(y, x, text, pos, temp);
					return 1;

				}
				else return 0;
			}
			else if (y == previousCursonY)
			{
				if (x - previousCursonX < 0)
				{
					for (int i = previousCursonX - 1; i > x; i--)
					{
						if (Board::CurrentBoard[y][i].GetID() != 0)
						{
							hasAObstacleX = i;
							break;
						}
					}
				}
				else if (x - previousCursonX > 0)
				{
					for (int i = previousCursonX + 1; i < x; i++)
					{
						if (Board::CurrentBoard[y][i].GetID() != 0)
						{
							hasAObstacleX = i;
							break;
						}
					}
				}
				if (hasAObstacleX == x)
				{
					printText(y, x, text, pos, temp);
					return 1;
				}
				else if (abs(x - previousCursonX) < abs(previousCursonX - hasAObstacleX) && y == previousCursonY)
				{

					printText(y, x, text, pos, temp);
					return 1;
				}
			}

		}
	}
	}
	else if (id == 7)
	{
		if ( y >= 3 && y <= 4)
		{
			if (abs(x - previousCursonX) != 0)return 0;
			else if (y < previousCursonY)return 0;
			else if (abs(y - previousCursonY) == 1)
			{
				printText(y, x, text, pos, temp);
				return 1;
			}
			else return 0;
		}
		else if (  y >= 5 && x != -1 && y != -1)
		{
			
			if ((abs(x - previousCursonX) + abs(y - previousCursonY) > 1))return 0;
			else if (y < previousCursonY)return 0;
			else
			{
				printText(y, x, text, pos, temp);
				return 1;
			}
		}
		else return 0;
	}
	else if (id == 8)
	{
		if ( (x >= 3 && x <= 5) && (y != -1) && y <= 9 && y >= 7 && (abs(x - previousCursonX) + abs(y - previousCursonY) <= 1))
		{
			printText(y, x, text, pos, temp);
			return 1;
		}
		else return 0;
	}
	else if (id == 9)
	{
		if ( (x >= 3 && x <= 5) && (y >= 7) && (y <= 9) && (abs(x - previousCursonX) == 1 && abs(y - previousCursonY) == 1))
		{
			printText(y, x, text, pos, temp);
			return 1;
		}
		else return 0;
	}
	else if (id == 10)
	{
		if ( Board::CurrentBoard[abs(y + previousCursonY) / 2][abs(x + previousCursonX) / 2].GetID() == 0 && x != -1 && y != -1 && (abs(x - previousCursonX) == 2 && abs(y - previousCursonY) == 2) && y >= 5)
		{
			printText(y, x, text, pos, temp);
			return 1;
		}
		else return 0;
	}
	else if (id == 11)
	{
		if ( (x != -1) && (y != -1))
		{
			int hasAObstacleX = x;
			int hasAObstacleY = y;
			if (x == previousCursonX)
			{
				if (y - previousCursonY < 0)
				{
					for (int i = previousCursonY - 1; i > y; i--)
					{
						if (Board::CurrentBoard[i][x].GetID() != 0)
						{
							hasAObstacleY = i;
							break;
						}
					}
				}
				else if (y - previousCursonY > 0)
				{
					for (int i = previousCursonY + 1; i < y; i++)
					{
						if (Board::CurrentBoard[i][x].GetID() != 0)
						{
							hasAObstacleY = i;
							break;
						}
					}
				}
				if (hasAObstacleY == y)
				{
					printText(y, x, text, pos, temp);
					return 1;
				}
				else if ((abs(y - previousCursonY) < abs(previousCursonY - hasAObstacleY) && x == previousCursonX) && y != 5)
				{
					printText(y, x, text, pos, temp);
					return 1;

				}
				else return 0;
			}
			else if (y == previousCursonY)
			{
				if (x - previousCursonX < 0)
				{
					for (int i = previousCursonX - 1; i > x; i--)
					{
						if (Board::CurrentBoard[y][i].GetID() != 0)
						{
							hasAObstacleX = i;
							break;
						}
					}
				}
				else if (x - previousCursonX > 0)
				{
					for (int i = previousCursonX + 1; i < x; i++)
					{
						if (Board::CurrentBoard[y][i].GetID() != 0)
						{
							hasAObstacleX = i;
							break;
						}
					}
				}
				if (hasAObstacleX == x)
				{
					printText(y, x, text, pos, temp);
					return 1;
				}
				else if (abs(x - previousCursonX) < abs(previousCursonX - hasAObstacleX) && y == previousCursonY && y != 5)
				{

					printText(y, x, text, pos, temp);
					return 1;
				}
			}
			else return 0;
		}
	}
	else if (id == 12)
	{
	if (x != -1 && y != -1 && (abs(x - previousCursonX) + abs(y - previousCursonY) == 3) && abs(x - previousCursonX) != 0 && abs(y - previousCursonY) != 0)
	{
		if (x - previousCursonX == 2)
		{
			if (Board::CurrentBoard[previousCursonY][previousCursonX + 1].GetID() == 0)
			{
				printText(y, x, text, pos, temp);
				return 1;
			}
			else return 0;
		}
		else if (x - previousCursonX == -2)
		{
			if (Board::CurrentBoard[previousCursonY][previousCursonX - 1].GetID() == 0)
			{
				printText(y, x, text, pos, temp);
				return 1;
			}
			else return 0;
		}
		if (y - previousCursonY == 2)
		{
			if (Board::CurrentBoard[previousCursonY + 1][previousCursonX].GetID() == 0)
			{
				printText(y, x, text, pos, temp);
				return 1;
			}
			else return 0;
		}
		else if (y - previousCursonY == -2)
		{
			if (Board::CurrentBoard[previousCursonY - 1][previousCursonX].GetID() == 0)
			{


				printText(y, x, text, pos, temp);
				return 1;


			}
			else return 0;
		}

	}

	else return 0;

	}
	else if (id == 13)
	{
		if (powx == x && powy == y && ((powx == previousCursonX) || (powy == previousCursonY)) && (Board::CurrentBoard[y][x].GetID() != 0))
		{
			printText(y, x, text, pos, temp);
			return 1;
		}
		else if (Board::CurrentBoard[Board::ConvertToBoardPoint().y][Board::ConvertToBoardPoint().x].GetID() != 0 && (powx != x || powy != y))
		{
			return 0;
		}
		else
		{
			if ((x != -1) && (y != -1))
			{
				int hasAObstacleX = x;
				int hasAObstacleY = y;
				if (x == previousCursonX)
				{
					if (y - previousCursonY < 0)
					{
						for (int i = previousCursonY - 1; i > y; i--)
						{
							if (Board::CurrentBoard[i][x].GetID() != 0)
							{
								hasAObstacleY = i;
								break;
							}
						}
					}
					else if (y - previousCursonY > 0)
					{
						for (int i = previousCursonY + 1; i < y; i++)
						{
							if (Board::CurrentBoard[i][x].GetID() != 0)
							{
								hasAObstacleY = i;
								break;
							}
						}
					}
					if (hasAObstacleY == y)
					{
						printText(y, x, text, pos, temp);
						return 1;
					}
					else if ((abs(y - previousCursonY) < abs(previousCursonY - hasAObstacleY) && x == previousCursonX) )
					{
						printText(y, x, text, pos, temp);
						return 1;

					}
					else return 0;
				}
				else if (y == previousCursonY)
				{
					if (x - previousCursonX < 0)
					{
						for (int i = previousCursonX - 1; i > x; i--)
						{
							if (Board::CurrentBoard[y][i].GetID() != 0)
							{
								hasAObstacleX = i;
								break;
							}
						}
					}
					else if (x - previousCursonX > 0)
					{
						for (int i = previousCursonX + 1; i < x; i++)
						{
							if (Board::CurrentBoard[y][i].GetID() != 0)
							{
								hasAObstacleX = i;
								break;
							}
						}
					}
					if (hasAObstacleX == x)
					{
						printText(y, x, text, pos, temp);
						return 1;
					}
					else if (abs(x - previousCursonX) < abs(previousCursonX - hasAObstacleX) && y == previousCursonY)
					{

						printText(y, x, text, pos, temp);
						return 1;
					}
				}

			}
		}
	}
	else if (id == 14)
	{
		if (y >= 5 && y <= 6)
		{
			if (abs(x - previousCursonX) != 0)return 0;
			else if (y > previousCursonY)return 0;
			else if (abs(y - previousCursonY) == 1)
			{
				printText(y, x, text, pos, temp);
				return 1;
			}
			else return 0;
		}
		else if (y <= 4 && x != -1 && y != -1)
		{

			if ((abs(x - previousCursonX) + abs(y - previousCursonY) > 1))return 0;
			else if (y > previousCursonY)return 0;
			else
			{
				printText(y, x, text, pos, temp);
				return 1;
		}
	}
	else return 0;
	}
	return 0;
}
void ChessWalking::printWhereCanGO(int ID,int previousCursonX, int previousCursonY ,ChessWalking& temp)
{
	//printWhereToGo(y, x, pos);
	if (blackOrRed == true)
	{
		if (ID == 1)
		{
			for (int x = 0; x <= 8; x++)
			{
				for (int y = 0; y <= 9; y++)
				{
					if ((x >= 3 && x <= 5) && (y != -1) && y <= 2 && (abs(x - previousCursonX) + abs(y - previousCursonY) <= 1))
					{
						int count = 0, sameY = 0;
						for (int i = y + 1; i <= 9; i++)
						{
							if (Board::CurrentBoard[i][x].GetID() != 0)
							{
								if (Board::CurrentBoard[i][x].GetID() == 8)
								{
									sameY = 1;
									break;
								}
								count++;
							}
						}
						if (sameY == 1 && count == 0)
						{

						}
						else printWhereToGo(y, x, pos);
						temp.beShown[x][y] = 1;
					}
					
				}
			}
		}
		else if (ID == 2)
		{
			for (int x = 0; x <= 8; x++)
			{
				for (int y = 0; y <= 9; y++)
				{
					if ((x >= 3 && x <= 5) && (y >= 0) && (y <= 2) && (abs(x - previousCursonX) == 1 && abs(y - previousCursonY) == 1))
					{
						printWhereToGo(y, x, pos);
						temp.beShown[x][y] = 1;
					}

				}
			}
		}
		else if (ID == 3)
		{
			for (int x = 0; x <= 8; x++)
			{
				for (int y = 0; y <= 9; y++)
				{
					if (Board::CurrentBoard[abs(y + previousCursonY) / 2][abs(x + previousCursonX) / 2].GetID() == 0 && x != -1 && y != -1 && (abs(x - previousCursonX) == 2 && abs(y - previousCursonY) == 2) && y < 5)
					{

						printWhereToGo(y, x, pos);
						temp.beShown[x][y] = 1;

					}

				}
			}
			
		}
		else if (ID == 4)
		{
		for (int x = 0; x <= 8; x++)
		{
			for (int y = 0; y <= 9; y++)
			{
				if ((x != -1) && (y != -1))
				{
					int hasAObstacleX = x;
					int hasAObstacleY = y;
					if (x == previousCursonX)
					{
						if (y - previousCursonY < 0)
						{
							for (int i = previousCursonY - 1; i > y; i--)
							{
								if (Board::CurrentBoard[i][x].GetID() != 0)
								{
									hasAObstacleY = i;
									break;
								}
							}
						}
						else if (y - previousCursonY > 0)
						{
							for (int i = previousCursonY + 1; i < y; i++)
							{
								if (Board::CurrentBoard[i][x].GetID() != 0)
								{
									hasAObstacleY = i;
									break;
								}
							}
						}
						if (hasAObstacleY == y )
						{
							printWhereToGo(y, x, pos);
							temp.beShown[x][y] = 1;
							
						}
						else if ((abs(y - previousCursonY) < abs(previousCursonY - hasAObstacleY) && x == previousCursonX) )
						{
							printWhereToGo(y, x, pos);
							temp.beShown[x][y] = 1;
							

						}
					
					}
					else if (y == previousCursonY)
					{
						if (x - previousCursonX < 0)
						{
							for (int i = previousCursonX - 1; i > x; i--)
							{
								if (Board::CurrentBoard[y][i].GetID() != 0)
								{
									hasAObstacleX = i;

									break;
								}
							}
						}
						else if (x - previousCursonX > 0)
						{
							for (int i = previousCursonX + 1; i < x; i++)
							{
								if (Board::CurrentBoard[y][i].GetID() != 0)
								{
									hasAObstacleX = i;
									break;
								}
							}
						}
						if (hasAObstacleX == x )
						{
							printWhereToGo(y, x, pos);
							temp.beShown[x][y] = 1;
						
						}
						else if (abs(x - previousCursonX) < abs(previousCursonX - hasAObstacleX) && y == previousCursonY)
						{
							printWhereToGo(y, x, pos);
							temp.beShown[x][y] = 1;

						}
					}
				}


				


				}

			}
		}	
		else if (ID == 5)
		{
			for (int x = 0; x <= 8; x++)
			{
				for (int y = 0; y <= 9; y++)
				{
					
					 if (x != -1 && y != -1 && (abs(x - previousCursonX) + abs(y - previousCursonY) == 3) && abs(x - previousCursonX) != 0 && abs(y - previousCursonY) != 0  )
					{
						if (x - previousCursonX == 2)
						{
							if (Board::CurrentBoard[previousCursonY][previousCursonX + 1].GetID() == 0)
							{
								printWhereToGo(y, x, pos);
								temp.beShown[x][y] = 1;
							}

						}
						else if (x - previousCursonX == -2)
						{
							if (Board::CurrentBoard[previousCursonY][previousCursonX - 1].GetID() == 0)
							{
								printWhereToGo(y, x, pos);
								temp.beShown[x][y] = 1;
							}

						}
						if (y - previousCursonY == 2)
						{
							if (Board::CurrentBoard[previousCursonY + 1][previousCursonX].GetID() == 0)
							{
								printWhereToGo(y, x, pos);
								temp.beShown[x][y] = 1;
							}
						}
						else if (y - previousCursonY == -2)
						{
							if (Board::CurrentBoard[previousCursonY - 1][previousCursonX].GetID() == 0)
							{
								printWhereToGo(y, x, pos);
								temp.beShown[x][y] = 1;
							}

						}

					}
				}
			}

		}
		else if (ID == 6)
		{
			for (int x = 0; x <= 8; x++)
			{
				for (int y = 0; y <= 9; y++)
				{
					if (x == previousCursonX && y == previousCursonY)continue;
				
						if ((x != -1) && (y != -1))
						{

							int hasAObstacleX = x;
							int hasAObstacleY = y;
							//走直的
							if (x == previousCursonX)
							{
								if (y - previousCursonY < 0)
								{
									for (int i = previousCursonY - 1; i > y; i--)
									{
										if (Board::CurrentBoard[i][x].GetID() != 0)
										{
											hasAObstacleY = i;
											break;
										}
									}
								}
								else if (y - previousCursonY > 0)
								{
									for (int i = previousCursonY + 1; i < y; i++)
									{
										if (Board::CurrentBoard[i][x].GetID() != 0)
										{
											hasAObstacleY = i;
											break;
										}
									}
								}
								if (hasAObstacleY == y)
								{
									if (Board::CurrentBoard[y][x].GetID() != 0)
									{
											Board temp;
											pos = temp.ConvertToConsolePoint(x, y);
											HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
											if (Board::CurrentBoard[y][x].GetTeam() == true)
											{
												SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY);
											}
											else
											{
												SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY | FOREGROUND_RED);
											}

											
											SetConsoleCursorPosition(hin, pos);
											wcout << Board::CurrentBoard[y][x].GetText();
									}
									else
									{
										printWhereToGo(y, x, pos);
										temp.beShown[x][y] = 1;
									}
									
								}
								else if ((abs(y - previousCursonY) < abs(previousCursonY - hasAObstacleY) && x == previousCursonX))
								{
									printWhereToGo(y, x, pos);
									temp.beShown[x][y] = 1;
								}
								
							}
							else if (y == previousCursonY) //走橫的
							{
								if (x - previousCursonX < 0)
								{
									for (int i = previousCursonX - 1; i > x; i--)
									{
										if (Board::CurrentBoard[y][i].GetID() != 0)
										{
											hasAObstacleX = i;
											break;
										}
									}
								}
								else if (x - previousCursonX > 0)
								{
									for (int i = previousCursonX + 1; i < x; i++)
									{
										if (Board::CurrentBoard[y][i].GetID() != 0)
										{
											hasAObstacleX = i;
											break;
										}
									}
								}
								if (hasAObstacleX == x )
								{
									if (Board::CurrentBoard[y][x].GetID() != 0)
									{
										Board temp;
										pos = temp.ConvertToConsolePoint(x, y);
										HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
										if (Board::CurrentBoard[y][x].GetTeam() == true)
										{
											SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY);
										}
										else
										{
											SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY | FOREGROUND_RED);
										}


										SetConsoleCursorPosition(hin, pos);
										wcout << Board::CurrentBoard[y][x].GetText();
									}
									else
									{
										printWhereToGo(y, x, pos);
										temp.beShown[x][y] = 1;
									}
								}
								else if (abs(x - previousCursonX) < abs(previousCursonX - hasAObstacleX) && y == previousCursonY )
								{

									printWhereToGo(y, x, pos);
									temp.beShown[x][y] = 1;
								}
							}

						



					}
				}
			}
			}
		else if (ID == 7)
		{
			for (int x = 0; x <= 8; x++)
			{
				for (int y = 0; y <= 9; y++)
				{
					if (y >= 3 && y <= 4)
					{
						if (abs(x - previousCursonX) != 0)
						{

						}
						else if (y < previousCursonY)
						{

						}
						else if (abs(y - previousCursonY) == 1)
						{
							
							temp.beShown[x][y] = 1;
							printWhereToGo(y, x, pos);
							
						}
						
					}
					else if (y >= 5 && x != -1 && y != -1)
					{

						if ((abs(x - previousCursonX) + abs(y - previousCursonY) > 1))
						{

						}
						else if (y < previousCursonY)
						{

						}
						else
						{
							printWhereToGo(y, x, pos);
							temp.beShown[x][y] = 1;
						}
					}
					
				}
			}
		}
	}
	else//printWhereToGoRed(y, x, pos);
	{
		if (ID == 8)
		{
			for (int x = 0; x <= 8; x++)
			{
				for (int y = 0; y <= 9; y++)
				{
					if ((x >= 3 && x <= 5) && (y != -1) && y <= 9 && y >= 7 && (abs(x - previousCursonX) + abs(y - previousCursonY) <= 1))
					{
						int count = 0, sameY = 0;
						for (int i = y - 1; i >= 0; i--)
						{
							if (Board::CurrentBoard[i][x].GetID() != 0)
							{
								if (Board::CurrentBoard[i][x].GetID() == 1)
								{
									sameY = 1;
									break;
								}
								count++;
							}
						}
						if (sameY == 1 && count == 0)
						{

						}
						else printWhereToGoRed(y, x, pos);
						temp.beShown[x][y] = 1;
					}
					
				}
			}
		}
		else if (ID == 9)
		{
			for (int x = 0; x <= 8; x++)
			{
				for (int y = 0; y <= 9; y++)
				{
					if ((x >= 3 && x <= 5) && (y >= 7) && (y <= 9) && (abs(x - previousCursonX) == 1 && abs(y - previousCursonY) == 1))
					{
						printWhereToGoRed(y, x, pos);
						temp.beShown[x][y] = 1;
					}
					
				}
			}
		}
		else if (ID == 10)
		{
			for (int x = 0; x <= 8; x++)
			{
				for (int y = 0; y <= 9; y++)
				{
					if (Board::CurrentBoard[abs(y + previousCursonY) / 2][abs(x + previousCursonX) / 2].GetID() == 0 && x != -1 && y != -1 && (abs(x - previousCursonX) == 2 && abs(y - previousCursonY) == 2) && y >= 5)
					{
						printWhereToGoRed(y, x, pos);
						temp.beShown[x][y] = 1;
					}
					
				}
			}
		}
		else if (ID == 11)
		{
			for (int x = 0; x <= 8; x++)
			{
				for (int y = 0; y <= 9; y++)
				{
					if ((x != -1) && (y != -1))
					{
						int hasAObstacleX = x;
						int hasAObstacleY = y;
						if (x == previousCursonX)
						{
							if (y - previousCursonY < 0)
							{
								for (int i = previousCursonY - 1; i > y; i--)
								{
									if (Board::CurrentBoard[i][x].GetID() != 0)
									{
										hasAObstacleY = i;
										break;
									}
								}
							}
							else if (y - previousCursonY > 0)
							{
								for (int i = previousCursonY + 1; i < y; i++)
								{
									if (Board::CurrentBoard[i][x].GetID() != 0)
									{
										hasAObstacleY = i;
										break;
									}
								}
							}
							if (hasAObstacleY == y)
							{
								printWhereToGoRed(y, x, pos);
								temp.beShown[x][y] = 1;
							}
							else if ((abs(y - previousCursonY) < abs(previousCursonY - hasAObstacleY) && x == previousCursonX) && y != 5)
							{
								printWhereToGoRed(y, x, pos);
								temp.beShown[x][y] = 1;
							}
							
						}
						else if (y == previousCursonY)
						{
							if (x - previousCursonX < 0)
							{
								for (int i = previousCursonX - 1; i > x; i--)
								{
									if (Board::CurrentBoard[y][i].GetID() != 0)
									{
										hasAObstacleX = i;
										break;
									}
								}
							}
							else if (x - previousCursonX > 0)
							{
								for (int i = previousCursonX + 1; i < x; i++)
								{
									if (Board::CurrentBoard[y][i].GetID() != 0)
									{
										hasAObstacleX = i;
										break;
									}
								}
							}
							if (hasAObstacleX == x)
							{
								printWhereToGoRed(y, x, pos);
								temp.beShown[x][y] = 1;
							}
							else if (abs(x - previousCursonX) < abs(previousCursonX - hasAObstacleX) && y == previousCursonY && y != 5)
							{

								printWhereToGoRed(y, x, pos);
								temp.beShown[x][y] = 1;
							}
						}
						
					}
				}
			}
		}
		else if (ID == 12)
		{
			for (int x = 0; x <= 8; x++)
			{
				for (int y = 0; y <= 9; y++)
				{
					if (x != -1 && y != -1 && (abs(x - previousCursonX) + abs(y - previousCursonY) == 3) && abs(x - previousCursonX) != 0 && abs(y - previousCursonY) != 0)
					{
						if (x - previousCursonX == 2)
						{
							if (Board::CurrentBoard[previousCursonY][previousCursonX + 1].GetID() == 0)
							{


								printWhereToGoRed(y, x, pos);
								temp.beShown[x][y] = 1;

							}
							
						}
						else if (x - previousCursonX == -2)
						{
							if (Board::CurrentBoard[previousCursonY][previousCursonX - 1].GetID() == 0)
							{


								printWhereToGoRed(y, x, pos);
								temp.beShown[x][y] = 1;

							}
							
						}
						if (y - previousCursonY == 2)
						{
							if (Board::CurrentBoard[previousCursonY + 1][previousCursonX].GetID() == 0)
							{

								printWhereToGoRed(y, x, pos);
								temp.beShown[x][y] = 1;

							}
							
						}
						else if (y - previousCursonY == -2)
						{
							if (Board::CurrentBoard[previousCursonY - 1][previousCursonX].GetID() == 0)
							{


								printWhereToGoRed(y, x, pos);
								temp.beShown[x][y] = 1;
							}
							
						}

					}

					


				}
			}
		}
		else if (ID == 13)
		{
		for (int x = 0; x <= 8; x++)
		{
			for (int y = 0; y <= 9; y++)
			{
				if (x == previousCursonX && y == previousCursonY)continue;


				if ((x != -1) && (y != -1))
				{

					int hasAObstacleX = x;
					int hasAObstacleY = y;
					//走直的
					if (x == previousCursonX)
					{
						if (y - previousCursonY < 0)
						{
							for (int i = previousCursonY - 1; i > y; i--)
							{
								if (Board::CurrentBoard[i][x].GetID() != 0)
								{
									hasAObstacleY = i;
									break;
								}
							}
						}
						else if (y - previousCursonY > 0)
						{
							for (int i = previousCursonY + 1; i < y; i++)
							{
								if (Board::CurrentBoard[i][x].GetID() != 0)
								{
									hasAObstacleY = i;
									break;
								}
							}
						}
						if (hasAObstacleY == y)
						{
							if (Board::CurrentBoard[y][x].GetID() != 0)
							{
								Board temp;
								pos = temp.ConvertToConsolePoint(x, y);
								HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
								if (Board::CurrentBoard[y][x].GetTeam() == true)
								{
									SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY);
								}
								else
								{
									SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY | FOREGROUND_RED);
								}


								SetConsoleCursorPosition(hin, pos);
								wcout << Board::CurrentBoard[y][x].GetText();
							}
							else
							{
								printWhereToGo(y, x, pos);
								temp.beShown[x][y] = 1;
							}

						}
						else if ((abs(y - previousCursonY) < abs(previousCursonY - hasAObstacleY) && x == previousCursonX))
						{
							printWhereToGo(y, x, pos);
							temp.beShown[x][y] = 1;
						}

					}
					else if (y == previousCursonY) //走橫的
					{
						if (x - previousCursonX < 0)
						{
							for (int i = previousCursonX - 1; i > x; i--)
							{
								if (Board::CurrentBoard[y][i].GetID() != 0)
								{
									hasAObstacleX = i;
									break;
								}
							}
						}
						else if (x - previousCursonX > 0)
						{
							for (int i = previousCursonX + 1; i < x; i++)
							{
								if (Board::CurrentBoard[y][i].GetID() != 0)
								{
									hasAObstacleX = i;
									break;
								}
							}
						}
						if (hasAObstacleX == x)
						{
							if (Board::CurrentBoard[y][x].GetID() != 0)
							{
								Board temp;
								pos = temp.ConvertToConsolePoint(x, y);
								HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
								if (Board::CurrentBoard[y][x].GetTeam() == true)
								{
									SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY);
								}
								else
								{
									SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY | FOREGROUND_RED);
								}


								SetConsoleCursorPosition(hin, pos);
								wcout << Board::CurrentBoard[y][x].GetText();
							}
							else
							{
								printWhereToGo(y, x, pos);
								temp.beShown[x][y] = 1;
							}
						}
						else if (abs(x - previousCursonX) < abs(previousCursonX - hasAObstacleX) && y == previousCursonY)
						{

							printWhereToGo(y, x, pos);
							temp.beShown[x][y] = 1;
						}
					}





				}
			}
		}
		}
		else if (ID == 14)
		{
			for (int x = 0; x <= 8; x++)
			{
				for (int y = 0; y <= 9; y++)
				{
					if (y >= 5 && y <= 6)
					{
						if (abs(x - previousCursonX) != 0)
						{

						}
						else if (y > previousCursonY)
						{

						}

						else if (abs(y - previousCursonY) == 1)
						{
							printWhereToGoRed(y, x, pos);
							temp.beShown[x][y] = 1;
						}
						
					}
					else if (y <= 4 && x != -1 && y != -1)
					{

						if ((abs(x - previousCursonX) + abs(y - previousCursonY) > 1))
						{

						}
						else if (y > previousCursonY)
						{

						}
						else
						{
							printWhereToGoRed(y, x, pos);
							temp.beShown[x][y] = 1;
						}
					}
					
				}
				
				}
			}
		}
	
}
void ChessWalking::clearWhereCanGO()
{
	
	HANDLE hin;
	COORD pos;
	hin = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int x = 0; x < 9; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			
		
			if (beShown[x][y] == 1)
			{
				
				if (Board::CurrentBoard[y][x].GetID() == 0)
				{
				
					Board temp;
					pos = temp.ConvertToConsolePoint(x, y);
					HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | 0x00);
					SetConsoleCursorPosition(hin, pos);
				
					wcout << Board::CurrentBoard.GetGraphicStr(x, y);

				}
				else if (Board::CurrentBoard[y][x].GetID() != 0 && Board::CurrentBoard[y][x].GetTeam() == true)
				{
					
					Board temp;
					pos = temp.ConvertToConsolePoint(x, y);
					HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY);
					SetConsoleCursorPosition(hin, pos);
				
					wcout << Board::CurrentBoard[y][x].GetText();
				}
				else if (Board::CurrentBoard[y][x].GetID() != 0 && Board::CurrentBoard[y][x].GetTeam() == false)
				{
					
					Board temp;
					pos = temp.ConvertToConsolePoint(x, y);
					HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY | FOREGROUND_RED);
					SetConsoleCursorPosition(hin, pos);
					wcout << Board::CurrentBoard[y][x].GetText();
				}
			}
			
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			beShown[i][k] = 0;
		}
	}
}
void ChessWalking::printText(int y, int x, wchar_t text, COORD post, Chess temp)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hin;
	int winID= Board::CurrentBoard[y][x].GetID();
	
	Board::CurrentBoard[y][x] = temp;
	hin = GetStdHandle(STD_OUTPUT_HANDLE);
	
	if (temp.GetTeam()) {
		SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY);
	}
	else {
		SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY | FOREGROUND_RED);
	}

	SetConsoleCursorPosition(hin, post);
	wcout << text;
	if (winID== 1)
	{
		Menu temp;
		temp.redWins();
	}
	else if (winID == 8)
	{
		Menu temp;
		temp.blackWins();
	}
	clearWhereCanGO();
}
ChessWalking::~ChessWalking()
{
}
