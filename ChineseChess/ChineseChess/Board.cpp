#include "Board.h"
#include <Windows.h>
#include <iostream>

void SetCursorPosistion(int x, int y) {
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD Position;
	Position.X = x;
	Position.Y = y;
	SetConsoleCursorPosition(hOut, Position);
}


Board::Board()
{
	chessMap = vector<vector<int>>(Height, vector<int>(Width, 0));
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
	cout << "╔";
	for (int i = 0; i < boardWidth  -2; i++) {
		cout << "═";
	}
	cout << "╗" << endl;

	for (int i = 0; i < boardHeight - 2; i++) {
		for (int j = 0; j < boardWidth; j++) {
			if (j == 0 || j == boardWidth - 1) {
				cout << "║";

				if (j == boardWidth - 1) {
					cout << endl;
				}
			}
			else {
				cout << " ";
			}
		}
	}

	cout << "╚";
	for (int i = 0; i < boardWidth - 2; i++) {
		cout << "═";
	}
	cout << "╝" << endl;
	SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x5d);
	SetCursorPosistion(boardWidth / 3, 1);
	cout << "１  ２  ３  ４  ５  ６  ７  ８  ９";

	SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x00);
	for (int i = 0; i < Height; i++) {		
		for (int j = 0; j < Width * 2; j+=2) {
			SetCursorPosistion(boardWidth / 3 + j, 2 + i);
			if (j == 0) {
				if (i == 0) {
					cout << "╔ ";
				}
				else if (i == Height - 1) {
					cout << "╚ ";
				}
				else {
					cout << "║ ";
				}
			}
			else if (j + 2 >= Width * 2) {
				if (i == 0) {
					cout << "╗ ";
				}
				else if (i == Height - 1) {
					cout << "╝ ";
				}
				else {
					cout << "║ ";
				}
			}
			else {
				if (i == 9 || i == 11) {
					cout << "  ";
				}
				else if (i == 10) {
					cout << "  ";
				}
				else if (i == 0 || i == Height - 1) {
					cout << "═ ";
				}
				else if (j % 4 == 0) {
					if (i % 2 == 0) {
						if (i == 8) {
							cout << "┴ ";
						}
						else if (i == 12) {
							cout << "┬ ";
						}
						else {
							cout << "┼ ";
						}
					}
					else {
						cout << "│ ";
					}
				}
				else if (i % 2 == 0) {
					cout << "─ ";
				}
				else {
					cout << "  ";
				}
			}
		}
	}
	SetCursorPosistion(boardWidth / 3 + 6, 2 + 10);
	cout << "楚 河";
	SetCursorPosistion(boardWidth / 3 + 22, 2 + 10);
	cout << "漢 界";
	SetCursorPosistion(boardWidth / 3 + 14, 2 + 1);
	cout << "╲";
	SetCursorPosistion(boardWidth / 3 + 14, 2 + 3);
	cout << "╱";
	SetCursorPosistion(boardWidth / 3 + 18, 2 + 1);
	cout << "╱";
	SetCursorPosistion(boardWidth / 3 + 18, 2 + 3);
	cout << "╲";

	SetCursorPosistion(boardWidth / 3 + 14, 2 + 17);
	cout << "╲";
	SetCursorPosistion(boardWidth / 3 + 14, 2 + 19);
	cout << "╱";
	SetCursorPosistion(boardWidth / 3 + 18, 2 + 17);
	cout << "╱";
	SetCursorPosistion(boardWidth / 3 + 18, 2 + 19);
	cout << "╲";


	SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x5d);
	SetCursorPosistion(boardWidth / 3, 23);
	cout << "九  八  七  六  五  四  三  二  一";
	SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x00);
}

void Board::SetChess(int x, int y)
{
}
