#pragma once
#include <vector>
using namespace std;
class Board
{
public:
	Board();
	void PrintMap();
	void SetChess(int x, int y);
private:
	const int Width = 17, Height = 21;
	vector<vector<int>> chessMap;
};

