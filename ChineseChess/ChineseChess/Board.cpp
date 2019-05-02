#include "Board.h"
#include "Utility.h"
#include <Windows.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>

Board Board::CurrentBoard = Board();

Board::Board()
{
	chessMap = vector<vector<Chess>>(11, vector<Chess>(9, Chess(0, L'\0', false)));
}

void Board::PrintMap()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x5d);
	SetCursorPosistion(WindowWidth / 3, 1);
	wcout << L"１  ２  ３  ４  ５  ６  ７  ８  ９";

	SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x00);
	for (int i = 0; i < BoardHeight; i++) {		
		for (int j = 0; j < BoardWidth * 2; j+=2) {
			SetCursorPosistion(WindowWidth / 3 + j, 2 + i);
			if (j == 0) {
				if (i == 0) {
					wcout << L"╔ ";
				}
				else if (i == BoardHeight - 1) {
					wcout << L"╚ ";
				}
				else {
					wcout << L"║ ";
				}
			}
			else if (j + 2 >= BoardWidth * 2) {
				if (i == 0) {
					wcout << L"╗ ";
				}
				else if (i == BoardHeight - 1) {
					wcout << L"╝ ";
				}
				else {
					wcout << L"║ ";
				}
			}
			else {
				if (i == 9 || i == 11) {
					wcout << L"  ";
				}
				else if (i == 10) {
					wcout << L"  ";
				}
				else if (i == 0 || i == BoardHeight - 1) {
					wcout << L"═ ";
				}
				else if (j % 4 == 0) {
					if (i % 2 == 0) {
						if (i == 8) {
							wcout << L"┴ ";
						}
						else if (i == 12) {
							wcout << L"┬ ";
						}
						else {
							wcout << L"┼ ";
						}
					}
					else {
						wcout << L"│ ";
					}
				}
				else if (i % 2 == 0) {
					wcout << L"─ ";
				}
				else {
					wcout << L"  ";
				}
			}
		}
	}
	SetCursorPosistion(WindowWidth / 3 + 6, 2 + 10);
	wcout << L"楚 河";
	SetCursorPosistion(WindowWidth / 3 + 22, 2 + 10);
	wcout << L"漢 界";
	SetCursorPosistion(WindowWidth / 3 + 14, 2 + 1);
	wcout << L"╲";
	SetCursorPosistion(WindowWidth / 3 + 14, 2 + 3);
	wcout << L"╱";
	SetCursorPosistion(WindowWidth / 3 + 18, 2 + 1);
	wcout << L"╱";
	SetCursorPosistion(WindowWidth / 3 + 18, 2 + 3);
	wcout << L"╲";

	SetCursorPosistion(WindowWidth / 3 + 14, 2 + 17);
	wcout << L"╲";
	SetCursorPosistion(WindowWidth / 3 + 14, 2 + 19);
	wcout << L"╱";
	SetCursorPosistion(WindowWidth / 3 + 18, 2 + 17);
	wcout << L"╱";
	SetCursorPosistion(WindowWidth / 3 + 18, 2 + 19);
	wcout << L"╲";


	SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x5d);
	SetCursorPosistion(WindowWidth / 3, 23);
	wcout << L"九  八  七  六  五  四  三  二  一";

	SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
	for (size_t y = 0; y < chessMap.size(); y++) {
		for (size_t x = 0; x < chessMap[y].size(); x++) {
			if (chessMap[y][x].GetID() == 0) {
				continue;
			}
			
			SetCursorPosistion(WindowWidth / 3 + 4 * x, 2 + 2 * y);
			wcout << chessMap[y][x].GetText();
		}
	}
}

void Board::ReadFile(string path)
{
	ifstream file;
	file.open(path);

	string line;

	int row = 0;
	while (getline(file, line)) {
		vector<string> splitStrArr;
		Split(line, splitStrArr, ' ');

		for (size_t i=0; i < splitStrArr.size(); i++) {
			int id = atoi(splitStrArr[i].c_str());
			Chess myChess = Chess::GetChessByID(id);
			chessMap[row][i] = myChess;
		}
		row++;
	}

	PrintMap();
}

void Board::WriteFile(string path)
{
	ofstream outStream;
	outStream.open(path);

	if (outStream.is_open()) {
		stringstream ss;
		for (int y = 0; y < chessMap.size(); y++) {
			for (int x = 0; x < chessMap[y].size(); x++) {
				ss << chessMap[y][x].GetID() << " ";
			}
			ss << endl;
		}

		outStream << ss.str();
		outStream.close();
	}
}

COORD Board::ConvertToConsolePoint(int x, int y)
{
	COORD p;
	p.X = x * 4 + 26;
	p.Y = (y + 1) * 2;
	return p;
}

vector<Chess>& Board::operator[](int row)
{
	return chessMap[row];
}

Chess& Board::GetChessByPoint(int x, int y)
{
	if (x < 0 || x >= (int)chessMap[0].size() || y < 0 || y >= (int)chessMap.size()) {
		throw exception("The Coordinate is invalid.");
	}
	else {
		return chessMap[y][x];
	}
}

vector<Board::ChessPos> Board::SearchByChessName(int ID)
{
	vector<Board::ChessPos> arr;
	for (size_t y = 0; y < chessMap.size(); y++) {
		for (size_t x = 0; x < chessMap[y].size(); x++) {
			if (chessMap[y][x].GetID() == ID) {
				Board::ChessPos cp;
				cp.Chess = chessMap[y][x];
				cp.Point.x = x;
				cp.Point.y = y;
				arr.push_back(cp);
			}
		}
	}
 	return arr;
}

// Intent: Convert current console cursor position to Board coordinate for easy programming.
// Post: If Point's X and Y are both -1 means the current cursor position is invalid on the board.
POINT Board::ConvertToBoardPoint()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	POINT p;
	p.x = (csbi.dwCursorPosition.X - 26) / 4;
	p.y = csbi.dwCursorPosition.Y / 2 - 1;

	if (csbi.dwCursorPosition.X < Board::CurrentBoard.WindowWidth / 3 || csbi.dwCursorPosition.X > Board::CurrentBoard.WindowWidth / 3 + Board::CurrentBoard.BoardWidth * 2 
		|| p.y < 0 || csbi.dwCursorPosition.Y - 1 > Board::CurrentBoard.BoardHeight) {
		p.x = -1;
		p.y = -1;
		return p;
	}	
	return p;
}

Board::ChessPos::ChessPos()
{
	Point.x = -1;
	Point.y = -1;
}
