#include "stdafx.h"
#include <iostream>
#include "OOP 12.h"

using namespace std;

Node::Node()
{
}

Node::Node(int x, int y, int data)
{
	this->x = x;
	this->y = y;
	this->data = data;
	nextX = NULL;
	nextY = NULL;
}

Matrix::Matrix()
{
	headX = NULL;
	headY = NULL;
}

Matrix::Matrix(int length, int width)
{
	this->length = length;
	this->width = width;
	headX = NULL;
	headY = NULL;
}

void Matrix::filmwareY(Node *n)
{
	Node *cur = n;
	Node *tmp = headY;
	if (!headY)
		headY = cur;
	else if ((cur->x == headY->x) && (cur->y == headY->y))
	{
		cur->nextY = headY->nextY;
		headY = cur;
	}
	else if (cur->x < headY->x)
	{
		cur->nextY = headY;
		headY = cur;
	}
	else if ((cur->y < tmp->y) && (cur->x == tmp->x))
	{
		cur->nextY = headY;
		headY = cur;
	}
	else
	{
		while (tmp->nextY)
		{
			if ((cur->x < tmp->nextY->x))
			{
				cur->nextY = tmp->nextY;
				tmp->nextY = cur;
				return;
			}
			else if ((cur->y < tmp->nextY->y) && (cur->x == tmp->nextY->x))
			{
				cur->nextY = tmp->nextY;
				tmp->nextY = cur;
				return;
			}
			else if ((cur->x == tmp->nextY->x) && (cur->y == tmp->nextY->y))
			{
				cur->nextY = tmp->nextY->nextY;
				tmp->nextY = cur;
				return;
			}
			else if (!tmp->nextY)
			{
				tmp->nextY = cur;
				return;
			}
			tmp = tmp->nextY;
		}
		tmp->nextY = cur;
	}
}

void Matrix::put(int x, int y, int data)
{
	if ((x >= length) || (y >= width))
	{
		cout << "wrong coords\n";
		return;
	}
	Node *cur = new Node(x, y, data);
	Node *tmp = headX;
	if (!headX)
	{
		headX = cur;
		filmwareY(cur);
	}
	else if ((cur->x == headX->x) && (cur->y == headX->y))
	{
		cur->nextX = headX->nextX;
		headX = cur;
		filmwareY(cur);
	}
	else if ((cur->x < tmp->x) && (cur->y == tmp->y))
	{
		cur->nextX = headX;
		headX = cur;
		filmwareY(cur);
	}
	else if (cur->y < headX->y)
	{
		cur->nextX = headX;
		headX = cur;
		filmwareY(cur);
	}
	else
	{
		while (tmp->nextX)
		{
			if ((cur->y < tmp->nextX->y))
			{
				cur->nextX = tmp->nextX;
				tmp->nextX = cur;
				filmwareY(cur);
				return;
			}
			else if ((cur->x < tmp->nextX->x) && (cur->y == tmp->nextX->y))
			{
				cur->nextX = tmp->nextX;
				tmp->nextX = cur;
				filmwareY(cur);
				return;
			}
			else if ((cur->x == tmp->nextX->x) && (cur->y == tmp->nextX->y))
			{
				cur->nextX = tmp->nextX->nextX;
				tmp->nextX = cur;
				filmwareY(cur);
				return;
			}
			else if (!tmp->nextX)
			{
				tmp->nextX = cur;
				filmwareY(cur);
				return;
			}
			tmp = tmp->nextX;
		}
		tmp->nextX = cur;
		filmwareY(cur);
	}
}

void Matrix::printX()
{
	int counterX = 0, counterY = 0;
	Node *tmp = headX;
	while (tmp)
	{
		for (; (counterX < tmp->x) || (counterY < tmp->y); counterX++)
		{
			if (counterX > length - 1)
			{
				cout << endl;
				counterX = 0;
				counterY++;
			}
			cout << "0\t";
			if (counterX >= length-1)
			{
				cout << endl;
				counterX = -1;
				counterY++;
			}
		}
		cout << tmp->data << "\t";
		counterX++;
		tmp = tmp->nextX;
	}
	while (counterY < width)
	{
		for (;counterY < width; counterX++)
		{
			if (counterX > length - 1)
			{
				cout << endl;
				counterX = -1;
				counterY++;
			}
			else if (counterX == length - 1)
			{
				cout << "0\t";
				cout << endl;
				counterX = -1;
				counterY++;
			}
			else cout << "0\t";
		}
	}
}

void Matrix::printY()
{
	int counterX = 0, counterY = 0;
	Node *tmp = headY;
	while (tmp)
	{
		for (; (counterX < tmp->x) || (counterY < tmp->y); counterY++)
		{
			if (counterY > width - 1)
			{
				cout << endl;
				counterY = 0;
				counterX++;
			}
			cout << "0\t";
			if (counterY == width - 1)
			{
				cout << endl;
				counterY = -1;
				counterX++;
			}
		}
		cout << tmp->data << "\t";
		counterY++;
		tmp = tmp->nextY;
	}
	while (counterX < length)
	{
		for (; counterX < length; counterY++)
		{
			if (counterY > width - 1)
			{
				cout << endl;
				counterY = -1;
				counterX++;
			}
			else if (counterY == width - 1)
			{
				cout << "0\t";
				cout << endl;
				counterY = -1;
				counterX++;
			}
			else cout << "0\t";
		}
	}
}

Node* Matrix::findMax()
{
	Node *tmp = headX;
	Node *max = tmp;
	while (tmp->nextX)
	{
		if (tmp->nextX->data > max->data) max = tmp->nextX;
		tmp = tmp->nextX;
	}
	return max;
}

void Matrix::deleteMax()
{
	Node *tmp = headX;
	Node *max = findMax();
	int x = max->x;
	int y = max->y;

	width--;
	length--;
	while (true) {
		if ((headX->x == x) || (headX->y == y))
			headX = headX->nextX;
		else break;
	}
	while (tmp->nextX)
	{
		if ((tmp->nextX->x == x) || (tmp->nextX->y == y))
			tmp->nextX = tmp->nextX->nextX;
		else tmp = tmp->nextX;
	}
	tmp = headX;
	headY = NULL;
	while (tmp)
	{
		tmp->nextY = NULL;
		if (tmp->x > x)
			tmp->x--;
		if (tmp->y > y)
			tmp->y--;
		filmwareY(tmp);
		tmp = tmp->nextX;
	}
}

void Matrix::dataX()
{
	Node *tmp = headX;
	cout << "X: ";
	while (tmp)
	{
		cout << tmp->data << "--";
		tmp = tmp->nextX;
	}
	cout << endl;
}

void Matrix::dataY()
{
	Node *tmp = headY;
	cout << "Y: ";
	while (tmp)
	{
		cout << tmp->data << "--";
		tmp = tmp->nextY;
	}
	cout << endl;
}