#pragma once
class LogPanel
{
public:
	LogPanel();
	
	void AddLog(wchar_t ChessName, int fromX, int fromY, int toX, int toY, bool Team);

private:
	int _LogIndex;
};

