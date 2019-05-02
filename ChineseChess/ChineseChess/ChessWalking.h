#pragma once
#include<Windows.h>
#include "Chess.h"
class ChessWalking
{
private:
	int ID;
	bool blackOrRed;
	int currentX;
	int currentY;

public:
	ChessWalking(int id, bool blackorred, int x, int y);
	void printWhereCanGO();
	int walk(int id, int x, int y, int previousCursonX, int previousCursonY, wchar_t text, Chess temp);
	~ChessWalking();
	HANDLE hin;
	COORD pos;
};

