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
	void printMenu();
	void printWord(int y);
	void EnterOne();//�~��C��
	void EnterTwo();//���s�}�l
	void EnterThree();//�^�D���
	void EnterFour();//���}�C��
private:
	const int MenuWidth = 16, MenuHeight = 12;
	char command;
	HANDLE hin;
};
