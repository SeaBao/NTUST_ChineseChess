#pragma once
#include <iostream>
#include <Windows.h>
#include "Utility.h"
#include "Board.h"
#include "regret.h"
using namespace std;

class ShowD
{
public:
	void showTurn();
	void printRight();
	void blackShowCheckmate();
	void blackCancelCheckmate();
	void redShowCheckmate();
	void redCancelCheckmate();
	static int roundCount;
private:

};