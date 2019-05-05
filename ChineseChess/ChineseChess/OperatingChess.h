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
	int previousCursonY;
	HANDLE hin;
	DWORD WriteWord;
	COORD pos;
	Chess previousChess;
public:
	OperatingChess();
	
	void gameStart();
	~OperatingChess();
};

