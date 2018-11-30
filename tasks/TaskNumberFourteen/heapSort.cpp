#include "heapSort.h"

void Heap::maxHeapify(int index) {
	int max = index;
	int leftChild = 2 * index + 1;
	int rightChild = 2 * index + 2;

	if (leftChild < heapSize && heapVector[leftChild] > heapVector[max]) {
		max = leftChild;
	}

	if (rightChild < heapSize && heapVector[rightChild] > heapVector[max]) {
		max = rightChild;
	}

	// change root, put max into the root
	if (max != index) {
		swap(&heapVector[max], &heapVector[index]);
		maxHeapify(max);
	}
}

void Heap::heapSort() {
	while (heapSize > 1) {
		swap(&heapVector[0], &heapVector[heapSize - 1]);
		heapSize--;
		maxHeapify(0);
	}
}

void Heap::printVector() {
	std::cout << std::endl;
	for (int i(0); i < heapVector.size(); i++) {
		std::cout << heapVector[i] << " ";
		if (i + 1 % 15 == 0)
			std::cout << std::endl;
	}
}