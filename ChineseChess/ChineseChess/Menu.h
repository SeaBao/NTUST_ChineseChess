#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Board.h"
#include "ShowD.h"
#include "LogPanel.h"
using namespace std;

class Menu
{
public:
	bool redFirst;
	void printMenu();
	void printWord(int y);
	void EnterOne();//繼續遊戲
	void EnterTwo();//重新開始
	void EnterThree();//回主選單
	void EnterFour();//離開遊戲
	void blackWins();
	void redWins();
	void wantNext();
private:
	const int MenuWidth = 16, MenuHeight = 12;
	char command;
	HANDLE hin;
};
