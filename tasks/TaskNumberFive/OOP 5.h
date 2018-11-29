#pragma once

#include <iostream>

class Node
{
	friend class List;

private:
	Node();
	Node(int newData);
	Node* next;
	int data;

};

#pragma once

class List
{
public:

	List();

	void insert(int newData, int index);
	void push_back(int newData);
	void deleteByIndex(int index);
	void deleteList();
	void printList();
	void split(List* mainList, List* list1, List* list2, int N);

private:
	Node* head;
};