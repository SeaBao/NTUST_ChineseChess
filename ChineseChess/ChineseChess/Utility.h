#pragma once
#include <string>
#include <vector>
using namespace std;

size_t Split(const std::string& txt, std::vector<std::string>& strs, char ch);
void SetCursorPosistion(int x, int y);
void SetWindow(int Width, int Height);