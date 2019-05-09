#pragma once
#include <windows.h>
#include"Chess.h"

class OperatingChess
{
private:
	int turn = 1;
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
			return false;
		}
		else
		{
			return true;
		}
		
	}

	void SetTurn(int n) {
		turn = n;
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
};

