#include "Board.h"
#include "Utility.h"
#include "ShowD.h"
#include <Windows.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>

Board Board::CurrentBoard = Board();
int Board::ChessSteps = 0;

Board::Board()
{
	chessMap = vector<vector<Chess>>(10, vector<Chess>(9, Chess(0, L'\0', false)));

	for (int y = 0; y < 19; y++) {
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
			else if (y == 18) {
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
					if (y == 9) {
						tempArr.push_back(L"  ");
					}
					else if (y % 2 == 0 && x != 1 && x != 31) {
						if (x % 4 == 0) {;
							if (y == 8) {
								tempArr.push_back(L"┴ ");
							}
							else if (y == 10) {
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

	boardMap[9][5] = L"";
	boardMap[9][6] = L"楚";
	boardMap[9][7] = L"";
	boardMap[9][9] = L"";
	boardMap[9][10] = L"河";
	boardMap[9][11] = L"";
	boardMap[9][21] = L"";
	boardMap[9][22] = L"漢";
	boardMap[9][23] = L"";
	boardMap[9][25] = L"";
	boardMap[9][26] = L"界";
	boardMap[9][27] = L"";

	boardMap[1][14] = L"╲ ";
	boardMap[1][18] = L"╱ ";
	boardMap[3][14] = L"╱ ";
	boardMap[3][18] = L"╲ ";

	boardMap[15][14] = L"╲ ";
	boardMap[15][18] = L"╱ ";
	boardMap[17][14] = L"╱ ";
	boardMap[17][18] = L"╲ ";

	
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
	SetCursorPosistion(WindowWidth / 3, 21);
	wcout << L"九  八  七  六  五  四  三  二  一";

	for (size_t y = 0; y < chessMap.size(); y++) {
		for (size_t x = 0; x < chessMap[y].size(); x++) {
			if (chessMap[y][x].GetID() == 0) {
				continue;
			}
			
			if (chessMap[y][x].GetTeam()) {
				SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY);
			}
			else {
				
				SetConsoleTextAttribute(hOut, BACKGROUND_INTENSITY | FOREGROUND_RED);
			}

			SetCursorPosistion(WindowWidth / 3 + 4 * x, 2 + 2 * y);
			wcout << chessMap[y][x].GetText();
		}
	}
	SetCursorPosistion(cursorPos.X, cursorPos.Y);
	ShowD print;
	print.printRight();
}

void Board::StartGame()
{
	_opChess.gameStart();
}

void Board::ReadFile(string path)
{
	ifstream file;
	file.open(path);

	string line;

	bool isRedFirst = false;
	int row = 0;
	while (getline(file, line)) {
		if (row == 10) {
			if (line == "1") {
				isRedFirst = true;
			}
			break;
		}

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

	_opChess = OperatingChess();
	SetCursorPosistion(Board::CurrentBoard.ConvertToConsolePoint(4, 9).X, Board::CurrentBoard.ConvertToConsolePoint(4, 9).Y);
	_opChess.SetTurn(isRedFirst);
}

void Board::WriteFile(string FileName, string FolderName = "")
{
	if (FolderName != "") {
		CreateDirectory(FolderName.c_str(), NULL);
	}
	
	ofstream outStream(FolderName + "/" + FileName);
	if (outStream.is_open()) {
		stringstream ss;
		for (size_t y = 0; y < chessMap.size(); y++) {
			for (size_t x = 0; x < chessMap[y].size(); x++) {
				ss << chessMap[y][x].GetID();
				if (x != chessMap[y].size() - 1)
				{
					ss << " ";
				}
			}
			if (y != chessMap.size() - 1)
			{
				ss << endl;
			}
		}
		
		ss << endl << _opChess.GetBlackOrRed();
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

void Board::mainScreen()
{
	COORD pos;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = 0, pos.Y = 0;
	SetConsoleCursorPosition(hOut, pos);
	ShowConsoleCursor(false);
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	pos.X = 0, pos.Y = 0;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"         ________  ___  ___  ___  ________   _______   ________  _______                 ";
	pos.X = 0, pos.Y = 1;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"        |\\   ____\\|\\  \\|\\  \\|\\  \\|\\   ___  \\|\\  ___ \\ |\\   ____\\|\\  ___ \\              ";
	pos.X = 0, pos.Y = 2;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"        \\ \\  \\___|\\ \\  \\\\\\  \\ \\  \\ \\  \\\\ \\  \\ \\   __/|\\ \\  \\___|\\ \\   __/|               ";
	pos.X = 0, pos.Y = 3;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"         \\ \\  \\    \\ \\   __  \\ \\  \\ \\  \\\\ \\  \\ \\  \\_|/_\\ \\_____  \\ \\  \\_|/__           ";
	pos.X = 0, pos.Y = 4;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"          \\ \\  \\____\\ \\  \\ \\  \\ \\  \\ \\  \\\\ \\  \\ \\  \\_|\\ \\|____|\\  \\ \\  \\_|\\ \\          ";
	pos.X = 0, pos.Y = 5;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"           \\ \\_______\\ \\__\\ \\__\\ \\__\\ \\__\\\\ \\__\\ \\_______\\____\\_\\  \\ \\_______\\            ";
	pos.X = 0, pos.Y = 6;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"            \\|_______|\\|__|\\|__|\\|__|\\|__| \\|__|\\|_______|\\_________\\|_______|                     ";
	pos.X = 0, pos.Y = 7;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"                                                         \\|_________|                                ";
	pos.X = 0, pos.Y = 8;
	SetConsoleCursorPosition(hOut, pos);
    wcout<<L"                ________  ___  ___  _______   ________   ________                  ";
	pos.X = 0, pos.Y = 9;
	SetConsoleCursorPosition(hOut, pos);
    wcout<<L"               |\\   ____\\|\\  \\|\\  \\|\\  ___ \\ |\\   ____\\ |\\   ____\\                ";
	pos.X = 0, pos.Y = 10;
	SetConsoleCursorPosition(hOut, pos);
    wcout<<L"               \\ \\  \\___|\\ \\  \\\\\\  \\ \\   __/|\\ \\  \\___|_\\ \\  \\___|_               ";
	pos.X = 0, pos.Y = 11;
	SetConsoleCursorPosition(hOut, pos);
    wcout<<L"                \\ \\  \\    \\ \\   __  \\ \\  \\_|/_\\ \\_____  \\\\ \\_____  \\               ";
	pos.X = 0, pos.Y = 12;
	SetConsoleCursorPosition(hOut, pos);
    wcout<<L"                 \\ \\  \\____\\ \\  \\ \\  \\ \\  \\_|\\ \\|____|\\  \\\\|____|\\  \\             ";
	pos.X = 0, pos.Y = 13;
	SetConsoleCursorPosition(hOut, pos);
    wcout<<L"                  \\ \\_______\\ \\__\\ \\__\\ \\_______\\____\\_\\  \\ ____\\_\\  \\             ";
	pos.X = 0, pos.Y = 14;
	SetConsoleCursorPosition(hOut, pos);
    wcout<<L"                   \\|_______|\\|__|\\|__|\\|_______|\\_________\\\\_________\\             ";
	pos.X = 0, pos.Y = 15;
	SetConsoleCursorPosition(hOut, pos);
    wcout<<L"                                                \\|_________\\|_________|            ";
	for (int i = 16; i < 23; i++)
	{
		pos.X = 0, pos.Y = i;
		SetConsoleCursorPosition(hOut, pos);
		for (int j = 0; j < 82; j++)
		{
			wcout << L" ";
		}
	}
	SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x00);
	pos.X = 38, pos.Y = 17;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"遊戲開始";
	SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	pos.X = 38, pos.Y = 19;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L"殘局模式";
	pos.X = 39, pos.Y = 21;
	SetConsoleCursorPosition(hOut, pos);
	wcout << L" 離開";
	char command;
	command = _getch();
	pos.Y = 17;
	while (command != EOF)
	{
		if (command == 80)//down
		{
			if (pos.Y == 19 or pos.Y == 17)
			{
				pos.Y += 2;
				printWord(pos.Y); 
			}
		}
		if (command == 72)//up
		{
			if (pos.Y == 19 or pos.Y == 21)
			{
				pos.Y -= 2;
				printWord(pos.Y);
			}

		}
		if (command == 13)//enter
		{
			if (pos.Y == 21)
			{
				exit(1);
			}
			else if (pos.Y == 19) //殘局模式
			{
				
			}
			else if (pos.Y == 17) //遊戲開始
			{

			}
		}
		command = _getch();
	}
}

void Board::printWord(int y)
{
	COORD pos;
	HANDLE hOut;
	pos.Y = y;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (y== 19)
	{
		SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x00);
		pos.X = 38, pos.Y = 19;
		SetConsoleCursorPosition(hOut, pos);
		wcout << L"殘局模式";
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		pos.X = 40, pos.Y = 21;
		SetConsoleCursorPosition(hOut, pos);
		wcout << L"離開";
		pos.X = 38, pos.Y = 17;
		SetConsoleCursorPosition(hOut, pos);
		wcout << L"遊戲開始";
	}
	else if (y == 17)
	{
		SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x00);
		pos.X = 38, pos.Y = 17;
		SetConsoleCursorPosition(hOut, pos);
		wcout << L"遊戲開始";
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		pos.X = 40, pos.Y = 21;
		SetConsoleCursorPosition(hOut, pos);
		wcout << L"離開";
		pos.X = 38, pos.Y = 19;
		SetConsoleCursorPosition(hOut, pos);
		wcout << L"殘局模式";
	}
	else if (y == 21)
	{
		SetConsoleTextAttribute(hOut, BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x00);
		pos.X = 40, pos.Y = 21;
		SetConsoleCursorPosition(hOut, pos);
		wcout << L"離開";
		SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		pos.X = 38, pos.Y = 19;
		SetConsoleCursorPosition(hOut, pos);
		wcout << L"殘局模式";
		pos.X = 38, pos.Y = 17;
		SetConsoleCursorPosition(hOut, pos);
		wcout << L"遊戲開始";
	}
}