#pragma once
#include <vector>
using namespace std;

class LogPanel
{
public:
	struct Log
	{
		wchar_t ChessName;
		bool Team;
		int fromX, fromY;
		int toX, toY;
	};

	LogPanel();
	static LogPanel CurrentPanel;

	int& GetIndex();
	void PrintPanel();
	void PrintLogs();
	void ClearLogs();
	void ClearPanel(bool resetIndex);
	void AddLog(wchar_t ChessName, int fromX, int fromY, int toX, int toY, bool Team);
private:
	const int _PanelHeight = 20, _PanelWidth = 22;
	int _LogIndex;
	vector<Log> _logArr;
};