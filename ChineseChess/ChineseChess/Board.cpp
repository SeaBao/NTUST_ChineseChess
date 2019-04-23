#include "Board.h"
#include <Windows.h>
#include <iostream>
#include <algorithm>
#include <fstream>

void SetCursorPosistion(int x, int y) {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = x;
	Position.Y = y;
	SetConsoleCursorPosition(hOut, Position);
}

size_t split(const std::string& txt, std::vector<std::string>& strs, char ch)
{
	size_t pos = txt.find(ch);
	size_t initialPos = 0;
	strs.clear();

	while (pos != std::string::npos) {
		strs.push_back(txt.substr(initialPos, pos - initialPos));
		initialPos = pos + 1;

		pos = txt.find(ch, initialPos);
	}

	strs.push_back(txt.substr(initialPos, min(pos, txt.size()) - initialPos + 1));

	return strs.size();
}



Board::Board()
{
	chessMap = vector<vector<Chess>>(11, vector<Chess>(9, Chess::GetChessByID(0)));
}

void Board::PrintMap()
{
	system("cls");
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;
	cfi.dwFontSize.Y = 30;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(hOut, FALSE, &cfi);

	CONSOLE_CURSOR_INFO	cursorInfo;
	GetConsoleCursorInfo(hOut, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(hOut, &cursorInfo);

	int boardWidth = 80;
	int boardHeight = 25;

	SetCursorPosistion(0, 0);
	wcout << L"╔";
	for (int i = 0; i < boardWidth  -2; i++) {
		wcout << L"═";
	}
	wcout << L"╗" << endl;

	for (int i = 0; i < boardHeight - 2; i++) {
		for (int j = 0; j < boardWidth; j++) {
			if (j == 0 || j == boardWidth - 1) {
				wcout << L"║";

				if (j == boardWidth - 1) {
					wcout << endl;
				}
			}
			else {
				wcout << L" ";
			}
		}
	}

	wcout << L"╚";
	for (int i = 0; i < boardWidth - 2; i++) {
		wcout << L"═";
	}
	wcout << L"╝" << endl;
	SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x5d);
	SetCursorPosistion(boardWidth / 3, 1);
	wcout << L"１  ２  ３  ４  ５  ６  ７  ８  ９";

	SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x00);
	for (int i = 0; i < Height; i++) {		
		for (int j = 0; j < Width * 2; j+=2) {
			SetCursorPosistion(boardWidth / 3 + j, 2 + i);
			if (j == 0) {
				if (i == 0) {
					wcout << L"╔ ";
				}
				else if (i == Height - 1) {
					wcout << L"╚ ";
				}
				else {
					wcout << L"║ ";
				}
			}
			else if (j + 2 >= Width * 2) {
				if (i == 0) {
					wcout << L"╗ ";
				}
				else if (i == Height - 1) {
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
				else if (i == 0 || i == Height - 1) {
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
	SetCursorPosistion(boardWidth / 3 + 6, 2 + 10);
	wcout << L"楚 河";
	SetCursorPosistion(boardWidth / 3 + 22, 2 + 10);
	wcout << L"漢 界";
	SetCursorPosistion(boardWidth / 3 + 14, 2 + 1);
	wcout << L"╲";
	SetCursorPosistion(boardWidth / 3 + 14, 2 + 3);
	wcout << L"╱";
	SetCursorPosistion(boardWidth / 3 + 18, 2 + 1);
	wcout << L"╱";
	SetCursorPosistion(boardWidth / 3 + 18, 2 + 3);
	wcout << L"╲";

	SetCursorPosistion(boardWidth / 3 + 14, 2 + 17);
	wcout << L"╲";
	SetCursorPosistion(boardWidth / 3 + 14, 2 + 19);
	wcout << L"╱";
	SetCursorPosistion(boardWidth / 3 + 18, 2 + 17);
	wcout << L"╱";
	SetCursorPosistion(boardWidth / 3 + 18, 2 + 19);
	wcout << L"╲";


	SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x5d);
	SetCursorPosistion(boardWidth / 3, 23);
	wcout << L"九  八  七  六  五  四  三  二  一";

	SetConsoleTextAttribute(hOut, BACKGROUND_RED | BACKGROUND_GREEN | 0x00);
	for (size_t y = 0; y < chessMap.size(); y++) {
		for (size_t x = 0; x < chessMap[y].size(); x++) {
			if (chessMap[y][x].GetID() == 0) {
				continue;
			}
			
			SetCursorPosistion(boardWidth / 3 + 4 * x, 2 + 2 * y);
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
		split(line, splitStrArr, ' ');

		for (int i=0; i < splitStrArr.size(); i++) {
			int id = atoi(splitStrArr[i].c_str());
			Chess myChess = Chess::GetChessByID(id);
			chessMap[row][i] = myChess;
		}
		row++;
	}

	PrintMap();
}
