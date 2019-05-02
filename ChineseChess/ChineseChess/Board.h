#pragma once
#include "Chess.h"
#include <vector>
#include <string>
#include <Windows.h>
using namespace std;

class Board
{
public:
	typedef struct ChessPos {
		ChessPos();
		Chess Chess;
		POINT Point;
	} ChessPos;

	Board();
	static Board CurrentBoard;
	static POINT ConvertToBoardPoint();

	void PrintMap();
	void ReadFile(string path);
	vector<Chess>& operator[](int row);
	Chess& GetChessByPoint(int x, int y);
	vector<ChessPos> SearchByChessName(int ID);
private:
	const int BoardWidth = 17, BoardHeight = 21, WindowWidth = 80, WindowHeight = 25;
	vector<vector<Chess>> chessMap;
};