#pragma once
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

size_t Split(const std::string& txt, std::vector<std::string>& strs, char ch);
COORD GetCursorPosition();
void SetCursorPosistion(int x, int y);
void SetWindow(int Width, int Height);
void ShowConsoleCursor(bool showFlag);