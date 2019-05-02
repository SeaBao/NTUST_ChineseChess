#include "ChessWalking.h"
#include"Chess.h"
#include <windows.h>
#include"Board.h"
#include<iostream>
using namespace std;


ChessWalking::ChessWalking(int id, bool blackorred, int x, int y)
{
	ID = id;
	blackOrRed = blackorred;
	currentX = x;
	currentY = y;
}

void ChessWalking::printWhereCanGO()
{

	if (blackOrRed == false)//red
	{
		if (ID == 1)
		{

			if (Board::CurrentBoard[currentY][currentX + 1].GetID() == 0 && (currentX + 1 >= 3 && currentX + 1 <= 5))
			{
				HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x60);
				wcout << Board::CurrentBoard[currentY][currentX + 1].GetText();
			}
			else if (Board::CurrentBoard[currentY + 1][currentX].GetID() == 0 && currentY + 1 != -1 && currentY + 1 <= 2)
			{

				HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x60);
				wcout << Board::CurrentBoard[currentY][currentX + 1].GetText();
			}
			else if (Board::CurrentBoard[currentY][currentX - 1].GetID() == 0 && (currentX - 1 >= 3 && currentX - 1 <= 5))
			{
				HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x60);
				wcout << Board::CurrentBoard[currentY][currentX + 1].GetText();
			}
			else if (Board::CurrentBoard[currentY - 1][currentX].GetID() == 0 && currentY - 1 != -1 && currentY - 1 <= 2)
			{
				HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
				SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x60);
				wcout << Board::CurrentBoard[currentY][currentX + 1].GetText();
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
	else//black
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
