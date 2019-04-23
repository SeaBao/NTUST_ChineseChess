#include "OperatingChess.h"
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
		
		hin = GetStdHandle(STD_OUTPUT_HANDLE);
		if (command == 75)
		{
			
			pos.X = pos.X - 4;
			SetConsoleCursorPosition(hin, pos);
		}
		else if (command == 72)
		{
			
			pos.Y = pos.Y - 2;
			SetConsoleCursorPosition(hin, pos);
		}
		else if (command == 77)
		{
			
			pos.X = pos.X + 4;
			SetConsoleCursorPosition(hin, pos);
		}
		else if (command == 80)
		{
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
