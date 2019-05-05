#pragma once
class Regret
{
private:

public:
	static int roundCount;
	void recordSteps();
	void readLastStore();
	void cleanStoreFile();
	void readNextStore();
	~Regret();
};