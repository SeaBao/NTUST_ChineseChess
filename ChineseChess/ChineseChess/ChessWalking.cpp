#include "ChessWalking.h"
#include"Chess.h"
#include <windows.h>
#include"Board.h"
#include<iostream>
#include"Utility.h"
#include<math.h>
using namespace std;

void printText(int y, int x, wchar_t text, COORD post, Chess temp)
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	HANDLE hin;
	SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
	Board::CurrentBoard[y][x] = temp;
	hin = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hin, post);
	wcout << text;
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
//Chess(1, L'�N', true), Chess(2, L'�h', true), Chess(3, L'�H', true), Chess(4, L'��', true), Chess(5, L'��', true), Chess(6, L'�]', true), Chess(7, L'��', true),
//Chess(8, L'��', false), Chess(9, L'�K', false), Chess(10, L'��', false), Chess(11, L'��', false), Chess(12, L'�X', false), Chess(13, L'��', false), Chess(14, L'�L', false)
int ChessWalking::walk(int id, int x, int y, int previousCursonX, int previousCursonY, wchar_t text, Chess temp)
{
	Board temp1;
	hin = GetStdHandle(STD_OUTPUT_HANDLE);
	pos = temp1.ConvertToConsolePoint(x, y);
	if (id == 1)
	{
		if (Board::CurrentBoard[y][x].GetID() == 0 && (x >= 3 && x <= 5) && (y != -1) && y <= 2 && (abs(x - previousCursonX) + abs(y - previousCursonY) <= 1))
		{
			printText(y, x, text, pos, temp);
			return 1;
		}
		else return 0;
	}
		else if (id == 2)
		{
			if (Board::CurrentBoard[y][x].GetID() == 0 && (x >= 3 && x <= 5) && (y >=0) && (y <= 2) && (abs(x - previousCursonX)==1 && abs(y - previousCursonY) == 1))
			{
				printText(y, x, text, pos, temp);
				return 1;
			}
			else return 0;
		}
		else if (id == 3)
		{
			if (Board::CurrentBoard[y][x].GetID() == 0 && Board::CurrentBoard[abs(y + previousCursonY) /2][abs(x + previousCursonX)/2].GetID() == 0&& x!=-1 &&y != -1 && (abs(x - previousCursonX) == 2 && abs(y - previousCursonY) == 2)&&y<5)
			{
				printText(y, x, text, pos, temp);
				return 1;
			}
			else return 0;
		}
		else if (id == 4)
	{

		if (Board::CurrentBoard[y][x].GetID() == 0 && (x != -1) && (y != -1))
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
				if (hasAObstacleY == y && y != 5)
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
				if (hasAObstacleX == x && y != 5)
				{
					HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
					Board::CurrentBoard[y][x] = temp;
					SetConsoleCursorPosition(hin, pos);
					wcout << text;
					return 1;
				}
				else if (abs(x - previousCursonX) < abs(previousCursonX - hasAObstacleX) && y == previousCursonY && y != 5)
				{

					HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
					Board::CurrentBoard[y][x] = temp;
					SetConsoleCursorPosition(hin, pos);
					wcout << text;
					return 1;
				}
			}
			else return 0;
		}
		}
		else if (id == 5)
		{
		if (Board::CurrentBoard[y][x].GetID() == 0 && x != -1 && y != -1 && (abs(x - previousCursonX)+abs(y - previousCursonY) == 3)&& abs(x - previousCursonX)!=0&& abs(y - previousCursonY)!=0)
		{
			if (x - previousCursonX == 2)
			{
				if (Board::CurrentBoard[previousCursonY][previousCursonX + 1].GetID() == 0)
				{
				
					if (y - previousCursonY < 0&&previousCursonY==6&&y!=4)
					{
						return 0;
					}
					else if (y - previousCursonY > 0 && previousCursonY == 4 && y != 6)
					{
						return 0;
					}
					else
					{
						printText(y, x, text, pos, temp);
						return 1;
					}
					
				}
				else return 0;
			}
			else if (x - previousCursonX == -2)
			{
				if (Board::CurrentBoard[previousCursonY][previousCursonX - 1].GetID() == 0)
				{

					if (y - previousCursonY < 0 && previousCursonY == 6 && y != 4)
					{
						return 0;
					}
					else if (y - previousCursonY > 0 && previousCursonY == 4 && y != 6)
					{
						return 0;
					}
					else
					{
						printText(y, x, text, pos, temp);
						return 1;
					}

				}
				else return 0;
			}
			if (y - previousCursonY == 2)
			{
				if (Board::CurrentBoard[previousCursonY][previousCursonX - 1].GetID() == 0)
				{

					if (y - previousCursonY < 0 && previousCursonY == 7 && y != 4)
					{
						return 0;
					}
					else if (y - previousCursonY > 0 && previousCursonY == 4 && y != 7)
					{
						return 0;
					}
					else
					{
						printText(y, x, text, pos, temp);
						return 1;
					}

				}
				else return 0;
			}
			else if (y - previousCursonY == -2)
			{
				if (Board::CurrentBoard[previousCursonY][previousCursonX - 1].GetID() == 0)
				{

					if (y - previousCursonY < 0 && previousCursonY == 7 && y != 4)
					{
						return 0;
					}
					else if (y - previousCursonY > 0 && previousCursonY == 4 && y != 7)
					{
						return 0;
					}
					else
					{
						printText(y, x, text, pos, temp);
						return 1;
					}

				}
				else return 0;
			}
		
		}
		else return 0;
		}
		else if (id == 6)
		{
		if (Board::CurrentBoard[y][x].GetID() == 0 && (x != -1) && (y != -1))
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
				if (hasAObstacleY == y && y != 5)
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
				if (hasAObstacleX == x && y != 5)
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
		else if (id == 7)
		{
			 if (Board::CurrentBoard[y][x].GetID() == 0   && y >=3 && y<=4 )
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
			 else if (Board::CurrentBoard[y][x].GetID() == 0 && y >= 6 && x!=-1&&y!=-1)
			 {
				 if (y == 6 && previousCursonY == 4)
				 {
					
					 printText(y, x, text, pos, temp);
					 return 1;
				 }
				 else if ((abs(x - previousCursonX) + abs(y - previousCursonY) > 1))return 0;
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
			 if (Board::CurrentBoard[y][x].GetID() == 0 && (x >= 3 && x <= 5) && (y != -1) && y <= 10&&y>=8&&(abs(x - previousCursonX) + abs(y - previousCursonY) <= 1))
			 {
				 HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				 SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
				 Board::CurrentBoard[y][x] = temp;
				 SetConsoleCursorPosition(hin, pos);
				 wcout << text;
				 return 1;
			 }
			 else return 0;
		}
		else if (id == 9)
		{
			if (Board::CurrentBoard[y][x].GetID() == 0 && (x >= 3 && x <= 5) && (y >= 8) && (y <= 10) && (abs(x - previousCursonX) == 1 && abs(y - previousCursonY) == 1))
			{
				HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
				Board::CurrentBoard[y][x] = temp;
				SetConsoleCursorPosition(hin, pos);
				wcout << text;
				return 1;
			}
			else return 0;
		}
		else if (id == 10)
		{
		if (Board::CurrentBoard[y][x].GetID() == 0 && Board::CurrentBoard[abs(y + previousCursonY) / 2][abs(x + previousCursonX) / 2].GetID() == 0 && x != -1 && y != -1 && (abs(x - previousCursonX) == 2 && abs(y - previousCursonY) == 2) && y > 5)
		{
			HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
			Board::CurrentBoard[y][x] = temp;
			SetConsoleCursorPosition(hin, pos);
			wcout << text;
			return 1;
		}
		else return 0;
		}
		else if (id == 11)
		{
			if (Board::CurrentBoard[y][x].GetID() == 0 && (x != -1) && (y != -1))
			{
				int hasAObstacleX = x;
				int hasAObstacleY = y;
				if (x == previousCursonX)
				{
					if (y - previousCursonY < 0)
					{
						for (int i = previousCursonY-1; i > y; i--)
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
					if (hasAObstacleY == y && y != 5)
					{
						HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
						Board::CurrentBoard[y][x] = temp;
						SetConsoleCursorPosition(hin, pos);
						wcout << text;
						return 1;
					}
					else if ((abs(y - previousCursonY) < abs(previousCursonY - hasAObstacleY) && x == previousCursonX) && y != 5)
					{
						HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
						Board::CurrentBoard[y][x] = temp;
						SetConsoleCursorPosition(hin, pos);
						wcout << text;
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
					if (hasAObstacleX == x && y != 5)
					{
						HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
						Board::CurrentBoard[y][x] = temp;
						SetConsoleCursorPosition(hin, pos);
						wcout << text;
						return 1;
					}
					else if (abs(x - previousCursonX) < abs(previousCursonX - hasAObstacleX) && y == previousCursonY && y != 5)
					{
						
						HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
						Board::CurrentBoard[y][x] = temp;
						SetConsoleCursorPosition(hin, pos);
						wcout << text;
						return 1;
					}
				}
				else return 0;
			}	
		}
		else if (id == 12)
		{
		if (Board::CurrentBoard[y][x].GetID() == 0 && x != -1 && y != -1 && (abs(x - previousCursonX) + abs(y - previousCursonY) == 3) && abs(x - previousCursonX) != 0 && abs(y - previousCursonY) != 0)
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
		if (Board::CurrentBoard[y][x].GetID() == 0 && (x != -1) && (y != -1))
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
				if (hasAObstacleY == y && y != 5)
				{
					HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
					Board::CurrentBoard[y][x] = temp;
					SetConsoleCursorPosition(hin, pos);
					wcout << text;
					return 1;
				}
				else if ((abs(y - previousCursonY) < abs(previousCursonY - hasAObstacleY) && x == previousCursonX) && y != 5)
				{
					HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
					Board::CurrentBoard[y][x] = temp;
					SetConsoleCursorPosition(hin, pos);
					wcout << text;
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
				if (hasAObstacleX == x && y != 5)
				{
					HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
					Board::CurrentBoard[y][x] = temp;
					SetConsoleCursorPosition(hin, pos);
					wcout << text;
					return 1;
				}
				else if (abs(x - previousCursonX) < abs(previousCursonX - hasAObstacleX) && y == previousCursonY && y != 5)
				{

					HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
					Board::CurrentBoard[y][x] = temp;
					SetConsoleCursorPosition(hin, pos);
					wcout << text;
					return 1;
				}
			}
			else return 0;
		}
		}
		else if (id == 14)
		{
			if (Board::CurrentBoard[y][x].GetID() == 0 && y >= 6 && y <= 7)
			{
				if (abs(x - previousCursonX) != 0)return 0;
				else if (y > previousCursonY)return 0;
				else if (abs(y - previousCursonY) == 1)
				{
					HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
					SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
					Board::CurrentBoard[y][x] = temp;
					SetConsoleCursorPosition(hin, pos);
					wcout << text;
					return 1;
				}
				else return 0;
			}
			else if (Board::CurrentBoard[y][x].GetID() == 0 && y <= 4 && x != -1 && y != -1)
			{
					if (y == 4 && previousCursonY ==6 )
					{

						HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
						Board::CurrentBoard[y][x] = temp;
						SetConsoleCursorPosition(hin, pos);
						wcout << text;
						return 1;
					}
					else if ((abs(x - previousCursonX) + abs(y - previousCursonY) > 1))return 0;
					else if (y > previousCursonY)return 0;
					else
					{
						HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
						SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
						Board::CurrentBoard[y][x] = temp;
						SetConsoleCursorPosition(hin, pos);
						wcout << text;
						return 1;
					}
				}
				else return 0;
			}
	
}
void ChessWalking::printWhereCanGO()
{

	if (blackOrRed == true)
	{
		if (ID == 1)
		{
			hin = GetStdHandle(STD_OUTPUT_HANDLE);
			pos = GetCursorPosition();
			pos.X = pos.X - 2;
			if (Board::CurrentBoard[currentY][currentX + 1].GetID() == 0 && (currentX + 1 >= 3 && currentX + 1 <= 5))
			{
				HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0xff);
				pos.X = pos.X + 4;
				SetConsoleCursorPosition(hin, pos );
				wcout <<" ";
			}
			else if (Board::CurrentBoard[currentY + 1][currentX].GetID() == 0 && currentY + 1 != -1 && currentY + 1 <= 2)
			{

				HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0xff);
				pos.Y = pos.Y + 2;
				SetConsoleCursorPosition(hin, pos);
				wcout << " ";
			}
			else if (Board::CurrentBoard[currentY][currentX - 1].GetID() == 0 && (currentX - 1 >= 3 && currentX - 1 <= 5))
			{
				HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0xff);
				pos.X = pos.X - 4;
				SetConsoleCursorPosition(hin, pos);
				wcout << " ";
			}
			else if (Board::CurrentBoard[currentY - 1][currentX].GetID() == 0 && currentY - 1 != -1 && currentY - 1 <= 2)
			{
				HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0xff);
				pos.Y = pos.Y - 2;
				SetConsoleCursorPosition(hin, pos);
				wcout << " ";
			}

		}
		else if (ID == 2)
		{

		}
		else if (ID == 3)
		{

		}
		else if (ID == 4)
		{

		}
		else if (ID == 5)
		{

		}
		else if (ID == 6)
		{

		}
		else if (ID == 7)
		{

		}
	}
	else
	{
		if (ID == 1)
		{

		}
		else if (ID == 2)
		{

		}
		else if (ID == 3)
		{

		}
		else if (ID == 4)
		{

		}
		else if (ID == 5)
		{

		}
		else if (ID == 6)
		{

		}
		else if (ID == 7)
		{

		}
	}
}
ChessWalking::~ChessWalking()
{
}
