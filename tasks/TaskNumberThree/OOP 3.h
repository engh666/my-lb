#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Fold
{
	friend class Tape;

private:
	Fold();
	Fold(bool newDir);
	char getDir();
	Fold* next;
	bool dir; // 0 - back, 1 - front
};

#pragma once

class Tape
{
public:
	Tape();
	Tape(vector<bool> f);
	void insert(bool newDir, Fold *fold);
	void fold(bool newDir);
	void print();
	void printBig();

private:
	int foldCount;
	vector<char> bigFolds;
	Fold* head;
};