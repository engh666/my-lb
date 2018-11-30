#pragma once
#include <iostream>
#include <vector>


using std::vector;

class Heap {
private:
	int heapSize;
	vector<int> heapVector;
	void maxHeapify(int index);
	void swap(int* a, int* b) {
		int c = *a;
		*a = *b;
		*b = c;
	}
public:
	Heap(vector<int> newVector) {
		heapVector = newVector;
		heapSize = newVector.size();
		for (int i((heapSize - 2) / 2); i >= 0; i--) {
			maxHeapify(i);
		}
	}
	Heap(int* newArray) {
		heapSize = sizeof(newArray) / sizeof(int);
		for (int i(0); i < heapSize; i++) {
			heapVector.push_back(newArray[i]);
		}
		for (int i((heapSize - 2) / 2); i >= 0; i--) {
			maxHeapify(i);
		}
	}
	void heapSort();
	void printVector();
};