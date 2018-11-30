#include "Queue.h"
#include <time.h>

using namespace std;

int main() {

	Queue q1;
	Queue q2;
	int N = 1000;
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		q1.enqueue(rand() % 100);
		q2.enqueue(rand() % 100);
	}

	q1.printQueue();
	cout << endl;
	clock_t time = clock();
	q1.insertionSort();
	time = clock() - time;
	q1.printQueue();
	cout << endl << "Running time: " << (float)time / CLOCKS_PER_SEC << endl;
	
	q2.printQueue();
	cout << endl;
	clock_t newtime = clock();
	q2.quickSort(0, N-1);
	time = clock() - newtime;
	q2.printQueue();
	cout << endl << "Running time: " << (float)newtime / CLOCKS_PER_SEC << endl;

	system("pause");
}