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

	int beShown[9][10];
	void printWhereToGoRed(int y, int x, COORD pos);
	void printWhereToGo(int y, int x, COORD pos);
public:
	ChessWalking();
	ChessWalking(int id, bool blackorred, int x, int y);
	void printWhereCanGO(int ID, int previousCursonX, int previousCursonY, ChessWalking& temp);
	void clearWhereCanGO();
	void setbeShown(int x, int y)
	{
		beShown[x][y] = 1;
	}
	void printText(int y, int x, wchar_t text, COORD post, Chess temp);
	int walk(int id, int x, int y, int &previousCursonX, int& previousCursonY, wchar_t text, Chess temp, int powx, int powy,int powflag);
	~ChessWalking();
	HANDLE hin;
	COORD pos;
};

