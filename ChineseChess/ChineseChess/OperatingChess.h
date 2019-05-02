#pragma once
#include<stdio.h>
#include<conio.h>
#include <windows.h>
#include "ChessWalking.h"
class OperatingChess
{
private:
	char command;
	bool isChoosed;
	int previousCursonX;
	int previousCursonY;
	HANDLE hin;
	DWORD WriteWord;
	COORD pos;
public:
	OperatingChess();
	void gameStart();
	~OperatingChess();
};

