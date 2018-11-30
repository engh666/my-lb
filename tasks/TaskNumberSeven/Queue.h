//Реализовать работу динамической структуры : ОЧЕРЕДЬ Добавление элемента·Удаление·Сортировка :
//В работе использовать два метода сортировки : быструю и вставками.Сравнить эффективность.
#include <iostream>
#pragma once

class Node {
	friend class Queue;
public:
	Node();
	Node(int newData, int newIndex);
private:
	int data;
	int index;
	Node* next;
	Node* prev;
};

class Queue {
private:
	Node* first = nullptr;
	Node* last;
	bool isEmpty() {
		return first == nullptr;
	}
	void swap(int&,int&);
	Node* at(int index);
	int partition(int low, int hi);
public:
	int dequeue();
	void enqueue(int item);
	void insertionSort();
	void quickSort(int low, int hi);
	void printQueue();
};