#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

class Menu
{
public:
	Menu();
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