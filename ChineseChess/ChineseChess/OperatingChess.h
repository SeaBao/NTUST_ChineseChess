#pragma once
#include<stdio.h>
#include<conio.h>
#include <windows.h>
#include "Menu.h"
#include"Chess.h"
class OperatingChess
{
private:
	int turn=1;
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

