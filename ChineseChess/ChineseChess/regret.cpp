#include "regret.h"
#include "Board.h"
#include <sstream>
#include <fstream>
#include <iostream>

/*int Regret::roundCount = 1;

void Regret::recordSteps()
{
	Board temp = Board::CurrentBoard;
	int count = roundCount;
	ostringstream s;
	s << "record" << count << ".txt";
	temp.WriteFile(s.str());
}

void Regret::readStore()
{
	Board temp;
	int count = roundCount - 1;
	roundCount--;
	ostringstream s;
	s << "record" << count << ".txt";
	Board::CurrentBoard.ReadFile(s.str());
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
		system("pause");
		const char* cstr = name.c_str();
		DeleteFile("record2.txt");
		s.str("");
		temp++;
		s << "record" << temp << ".txt";
		cout << s.str() << endl;
		file.open(s.str());
		if (!file.is_open())
		{
			break;
		}
	}
}

Regret::~Regret()
{

}*/