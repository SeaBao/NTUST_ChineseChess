#include "Board.h"
#include "Utility.h"
#include <Windows.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>

Board Board::CurrentBoard = Board();
int Board::ChessSteps = 0;

Board::Board()
{
	chessMap = vector<vector<Chess>>(11, vector<Chess>(9, Chess(0, L'\0', false)));

	for (int y = 0; y < 21; y++) {
		vector<wstring> tempArr;
		for (int x = 0; x < 33; x++) {
			if (y == 0) {
				if (x == 0) {
					tempArr.push_back(L"╔ ");
				}
				else if (x == 32) {
					tempArr.push_back(L"╗ ");
				}
				else {
					tempArr.push_back(L"═ ");
				}
			}
			else if (y == 20) {
				if (x == 0) {
					tempArr.push_back(L"╚ ");
				}
				else if (x == 32) {
					tempArr.push_back(L"╝ ");
				}
				else {
					tempArr.push_back(L"═ ");
				}
			}
			else {
				if (x == 0 || x == 32) {
					tempArr.push_back(L"║ ");
				}
				else {
					if (y == 9 || y == 10 || y == 11) {
						tempArr.push_back(L"  ");
					}
					else if (y % 2 == 0 && x != 1 && x != 31) {
						if (x % 4 == 0) {;
							if (y == 8) {
								tempArr.push_back(L"┴ ");
							}
							else if (y == 12) {
								tempArr.push_back(L"┬ ");
							}
							else {
								tempArr.push_back(L"┼ ");
							}
						}
						else {
							tempArr.push_back(L"─ ");
						}
					}
					else {
						if (x % 4 == 0) {
							tempArr.push_back(L"│ ");
						}
						else {
							tempArr.push_back(L"  ");
						}
					}
				}
			}
		}
		boardMap.push_back(tempArr);
	}

	boardMap[10][5] = L"";
	boardMap[10][6] = L"楚";
	boardMap[10][7] = L"";
	boardMap[10][9] = L"";
	boardMap[10][10] = L"河";
	boardMap[10][11] = L"";
	boardMap[10][21] = L"";
	boardMap[10][22] = L"漢";
	boardMap[10][23] = L"";
	boardMap[10][25] = L"";
	boardMap[10][26] = L"界";
	boardMap[10][27] = L"";

	boardMap[1][14] = L"╲ ";
	boardMap[1][18] = L"╱ ";
	boardMap[3][14] = L"╱ ";
	boardMap[3][18] = L"╲ ";

	boardMap[17][14] = L"╲ ";
	boardMap[17][18] = L"╱ ";
	boardMap[19][14] = L"╱ ";
	boardMap[19][18] = L"╲ ";
}

void Board::PrintMap()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hOut, &csbi);
	auto cursorPos = csbi.dwCursorPosition;

	SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x5d);
	SetCursorPosistion(WindowWidth / 3, 1);
	wcout << L"１  ２  ３  ４  ５  ６  ７  ８  ９";

	SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x00);
	for (size_t y = 0; y < boardMap.size(); y++) {
		for (size_t x = 0; x < boardMap[0].size(); x++) {
			SetCursorPosistion(WindowWidth / 3 + x, 2 + y);
			wcout << boardMap[y][x];
		}
	}

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
	SetCursorPosistion(cursorPos.X, cursorPos.Y);
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

void Board::WriteFile(string FileName, string FolderName)
{
	CreateDirectory(FolderName.c_str(), NULL);
	ofstream outStream(FolderName + "/" + FileName);
	if (outStream.is_open()) {
		stringstream ss;
		for (size_t y = 0; y < chessMap.size(); y++) {
			for (size_t x = 0; x < chessMap[y].size(); x++) {
				ss << chessMap[y][x].GetID() << " ";
			}
			ss << endl;
		}

		outStream << ss.str();
		outStream.close();
	}
}

wstring Board::GetGraphicStr(int x, int y)
{
	return boardMap[y * 2][x * 4];
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
