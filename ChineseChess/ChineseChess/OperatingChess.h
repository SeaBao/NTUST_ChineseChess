#pragma once
#include<stdio.h>
#include<conio.h>
#include <windows.h>
#include "Menu.h"
#include"Chess.h"
class OperatingChess
{
private:
	static int turn;
	char command;
	bool isChoosed;
	int previousCursonX;
	int CurrentCursonX;
	int CurrentCursonY;
	int previousCursonY;
	HANDLE hin;
	DWORD WriteWord;
	COORD pos;
	Chess previousChess;
public:
	OperatingChess();
	bool GetBlackOrRed()
	{
		if (turn % 2 == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
		
	}
	int GetPreviousCursonX()
	{
		return previousCursonX;
	}
	int GetPreviousCursonY()
	{
		return previousCursonY;
	}
	int GetCurrentCursonX()
	{
		return CurrentCursonX;
	}
	int GetCurrentCursonY()
	{
		return CurrentCursonY;
	}
	void gameStart();
	~OperatingChess();
};

