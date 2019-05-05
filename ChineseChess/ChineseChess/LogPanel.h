#pragma once
class LogPanel
{
public:
	LogPanel();
	static LogPanel CurrentPanel;

	void PrintPanel();
	void AddLog(wchar_t ChessName, int fromX, int fromY, int toX, int toY, bool Team);
private:
	const int _PanelHeight = 22, _PanelWidth = 22;
	int _LogIndex;
};