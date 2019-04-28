#pragma once
#include<stdio.h>
#include<conio.h>
#include <windows.h>
class OperatingChess
{
private:
	char command;
	bool isChoosed;
	int previousChessID;
	HANDLE hin;
	DWORD WriteWord;
	COORD pos;
public:
	OperatingChess();
	void gameStart();
	~OperatingChess();
};

