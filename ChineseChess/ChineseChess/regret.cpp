#include "regret.h"
#include "Board.h"
#include <sstream>
#include <fstream>
#include <iostream>

int Regret::roundCount = 1;

void Regret::recordSteps()
{
	Board temp = Board::CurrentBoard;
	int count = roundCount;
	ostringstream s;
	s << "record" << count << ".txt";
	temp.WriteFile(s.str());
}

void Regret::readLastStore()
{
	Board temp;
	int count = roundCount - 1;
	roundCount--;
	ostringstream s;
	s << "record" << count << ".txt";
	Board::CurrentBoard.ReadFile(s.str());
}

void Regret::readNextStore()
{
	Board temp;
	int count = roundCount + 1;
	ostringstream s;
	s << "record" << count << ".txt";
	ifstream in;
	in.open(s.str());
	if (in.is_open())
	{
		roundCount++;
		Board::CurrentBoard.ReadFile(s.str());
	}
}

void Regret::cleanStoreFile()
{
	int temp = 2;
	ostringstream s;
	s << "record" << temp << ".txt";
	ifstream file;
	file.open(s.str());
	while (file.is_open())
	{
		string name = s.str();
		file.close();
		const char* cstr = name.c_str();
		remove(cstr);
		s.str("");
		temp++;
		s << "record" << temp << ".txt";
		file.open(s.str());
		if (!file.is_open())
		{
			break;
		}
	}
}



Regret::~Regret()
{

}