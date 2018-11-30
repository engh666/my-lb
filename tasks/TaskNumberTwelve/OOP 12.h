#pragma once

class Node 
{
	friend class Matrix;
public:
	int data;
private:
	int x, y;
	Node *nextX, *nextY;
	Node();
	Node(int x, int y, int data);
};

class Matrix
{
private:
	int length, width;
	Node *headX, *headY;
public:
	Matrix();
	Matrix(int length, int width);
	void filmwareY(Node *n);
	void put(int x, int y, int data);
	void printX();
	void printY();
	Node* findMax();
	void deleteMax();
	void dataX();
	void dataY();
};