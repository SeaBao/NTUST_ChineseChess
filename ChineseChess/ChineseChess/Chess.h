#pragma once
#include <vector>
using namespace std;

class Chess
{
public:
	Chess();
	Chess(int ID, wchar_t text, bool team);
	int GetID();
	wchar_t GetText();
	static Chess GetChessByID(int id);
private:
	int ID;
	wchar_t Text;
	bool Team;
};

