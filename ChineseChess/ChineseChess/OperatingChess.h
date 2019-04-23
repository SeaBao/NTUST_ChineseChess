#pragma once
#include<stdio.h>
#include<conio.h>
#include <windows.h>
class OperatingChess
{
private:
	char command;
	HANDLE hin;
	DWORD WriteWord;
	COORD pos;
public:
	OperatingChess();
	void gameStart();
	~OperatingChess();
};

