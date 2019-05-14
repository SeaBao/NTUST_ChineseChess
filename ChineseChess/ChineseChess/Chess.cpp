#include "Chess.h"
#include <vector>

Chess::Chess()
{
	ID = GetChessByID(0).GetID();
	Text = GetChessByID(0).GetText();
	Team = false;
}

Chess::Chess(int id, wchar_t text, bool team)
{
	ID = id;
	Text = text;
	Team = team;
}


int Chess::GetID()
{
	return ID;
}

bool Chess::GetTeam() {
	return Team;
}

wchar_t Chess::GetText()
{
	return Text;
}

Chess Chess::GetChessByID(int id)
{
	vector<Chess> chessList = {
		Chess(0, L'\0', false),
		Chess(1, L'將', true), Chess(2, L'士', true), Chess(3, L'象', true), Chess(4, L'車', true), Chess(5, L'馬', true), Chess(6, L'包', true), Chess(7, L'卒', true),
		Chess(8, L'帥', false), Chess(9, L'仕', false), Chess(10, L'相', false), Chess(11, L'車', false), Chess(12, L'傌', false), Chess(13, L'炮', false), Chess(14, L'兵', false)
	};

	for (Chess c : chessList) {
		if (c.ID == id) return c;
	}
	return chessList[0];
}