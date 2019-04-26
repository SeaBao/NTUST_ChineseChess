#include "OperatingChess.h"
#include "Board.h"
#include <windows.h>
#include<iostream>

OperatingChess::OperatingChess()
{
	command = _getch();
	pos.X = 43, pos.Y = 2; // �N��m�]�b (5,5) ���a��C
	hin = GetStdHandle(STD_OUTPUT_HANDLE);
}


void OperatingChess::gameStart()
{
	
	while (command != EOF)
	{
		Board print;
		hin = GetStdHandle(STD_OUTPUT_HANDLE);
		if (command == 75)
		{
			print.PrintMap();
			pos.X = pos.X - 4;
			SetConsoleCursorPosition(hin, pos);

		}
		else if (command == 72)
		{
			print.PrintMap();
			pos.Y = pos.Y - 2;
			SetConsoleCursorPosition(hin, pos);
		}
		else if (command == 77)
		{
			print.PrintMap();
			pos.X = pos.X + 4;
			SetConsoleCursorPosition(hin, pos);
		}
		else if (command == 80)
		{
			print.PrintMap();
			pos.Y = pos.Y + 2;
			SetConsoleCursorPosition(hin, pos);
		}
		else if (command == 13)
		{

		}
		command = _getch();
		
	}
}


OperatingChess::~OperatingChess()
{
}
