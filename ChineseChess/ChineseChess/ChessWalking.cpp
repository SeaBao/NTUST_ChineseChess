#include "ChessWalking.h"
#include"Chess.h"
#include <windows.h>
#include"Board.h"
#include<iostream>
#include"Utility.h"
using namespace std;


ChessWalking::ChessWalking(int id, bool blackorred, int x, int y)
{
	
	hin = GetStdHandle(STD_OUTPUT_HANDLE);
	ID = id;
	blackOrRed = blackorred;
	currentX = x;
	currentY = y;
}
int ChessWalking::walk(int id, int x, int y,wchar_t text, Chess temp)
{

	
	
		 if (id == 1)
		{
			

			Board temp1;
			hin = GetStdHandle(STD_OUTPUT_HANDLE);
			pos = temp1.ConvertToConsolePoint(x, y);

			if (Board::CurrentBoard[y][x].GetID() == 0 && (x >= 3 && x <= 5) && (y != -1) && y <= 2)
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
		else if (id == 2)
		{

		}
		else if (id == 3)
		{

		}
		else if (id == 4)
		{

		}
		else if (id == 5)
		{

		}
		else if (id == 6)
		{

		}
		else if (id == 7)
		{

		}
	
	
		else if (id == 8)
		{
			 Board temp1;
			 hin = GetStdHandle(STD_OUTPUT_HANDLE);
			 pos = temp1.ConvertToConsolePoint(x, y);

			 if (Board::CurrentBoard[y][x].GetID() == 0 && (x >= 3 && x <= 5) && (y != -1) && y <= 10&&y>=8)
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

		}
		else if (id == 10)
		{

		}
		else if (id == 11)
		{

		}
		else if (id == 12)
		{

		}
		else if (id == 13)
		{

		}
		else if (id == 14)
		{

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
