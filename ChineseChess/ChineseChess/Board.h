#pragma once
#include "Chess.h"
#include <vector>
#include <string>
using namespace std;
class Board
{
public:
	Board();
	void PrintMap();
	void ReadFile(string path);
private:
	const int Width = 17, Height = 21;
	vector<vector<Chess>> chessMap;
	
};

