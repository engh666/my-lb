#include <iostream>
#include "Queue.h"
#include <time.h>

Node::Node() {

}
int Queue::dequeue()
{
	int data = first->data;
	Node* tmp = first;
	first = first->next;
	first->prev = nullptr;
	delete tmp;
	if (isEmpty()) last = nullptr;
	return data;
}

void Queue::enqueue(int data)
{
	Node *elem = last;
	last = new Node;
	last->data = data;
	last->next = nullptr;
	if (elem)
		last->index = elem->index + 1;
	else
		last->index = 0;
	last->prev = elem;
	if (isEmpty()) 
		first = last;
	else 
		elem->next = last;
}

void Queue::printQueue() {
	Node* curr = first;
	int k = 0;
	while (curr) {
		std::cout << curr->data << " ";
		curr = curr->next;
		k++;
		if (k == 20) {
			std::cout << std::endl;
			k = 0;
		}
	}
}

Node* Queue::at(int index) {
	Node* curr = first;
	while (curr->index != index) {
		curr = curr->next;
	}
	return curr;
}

void Queue::swap(int& first, int& second) {
	int s = first;
	first = second;
	second = s;
}

void Queue::insertionSort() {
	/*int hi = last->index+1;
	int low = 0;
	int j = low;
	for (int i = low; i < hi; i++) {
		for (int j = i; j > 0; j--) {
			Node* currentFirst = at(j - 1);
			Node* currentSecond = at(j);
			if (currentFirst->data > currentSecond->data)
				swap(currentFirst->data, currentSecond->data);
			else break;
		}
	}*/
	Node* tmpHead = first;
	while (tmpHead) {
		Node* pNode = tmpHead;
		while (pNode->prev && pNode->data < pNode->prev->data) {
			swap(pNode->data, pNode->prev->data);
			pNode = pNode->prev;
		}
		tmpHead = tmpHead->next;
	}
}


//int Queue::partition(int low, int hi)
//{
//	int i = low;
//	int j = hi;
//	while (true)
//	{
//		do    // searching item on the left
//		{
//			i++;
//			if (i == hi) break;
//		} while (at(i)->data < at(low)->data);
//
//		do   // searching number on the right
//		{
//			j--;
//			if (j == low) break;
//		} while (at(low)->data < at(j)->data);
//
//		if (i >= j) break;          // check if pointers crossed
//		swap(at(i)->data, at(j)->data);
//	}
//
//	swap(at(low)->data, at(j)->data);     // swap element with the key which is now on the right position
//	return j;
//}

void Queue::quickSort(int low, int hi)
{
	int l = low, r = hi;
	Node* lNode = at(low);
	Node* rNode = at(hi);

	int ave = at(l + (r - l) / 2)->data;

	do {
		while (lNode->data < ave) {
			l++;
			lNode = lNode->next;
		}
		while (rNode->data > ave) {
			r--;
			rNode = rNode->prev;
		}
		if (l <= r) {
			swap(lNode->data, rNode->data);
			l++;
			lNode = lNode->next;
			r--;
			rNode = rNode->prev;
		}
	} while (l < r);
	if (low < r) quickSort(low, r);
	if (l < hi) quickSort(l, hi);
}

