#include "Chess.h"

vector<Chess> chessList = {
		Chess(0, L'\0', false),
		Chess(1, L'�N', true), Chess(2, L'�h', true), Chess(3, L'�H', true), Chess(4, L'��', true), Chess(5, L'��', true), Chess(6, L'�]', true), Chess(7, L'��', true),
		Chess(8, L'��', false), Chess(9, L'�K', false), Chess(10, L'��', false), Chess(11, L'��', false), Chess(12, L'�X', false), Chess(13, L'��', false), Chess(14, L'�L', false)
};


Chess::Chess()
{
	ID = chessList[0].GetID();
	Text = chessList[0].GetText();
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
	for (Chess c : chessList) {
		if (c.ID == id) return c;
	}
	return chessList[0];
}