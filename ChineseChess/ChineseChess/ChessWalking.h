#pragma once
class ChessWalking
{
private:
	int ID;
	bool blackOrRed;
	int currentX;
	int currentY;
public:
	ChessWalking(int id, bool blackorred, int x,int y);
	void printWhereCanGO();
	~ChessWalking();
};

