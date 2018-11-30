#include "heapSort.h" 
#include <conio.h>
#include <time.h>

using std::cout;
using std::endl;
using std::vector;

int main() {

	vector<int> newVector1 = { 3, 10, 7, 6, 4, 1 };
	vector<int> newVector2;
	srand(time(NULL));
	for (int i(0); i < 100000; i++)
		newVector2.push_back(rand() % 100 + 1);

	Heap heap1(newVector2);
	heap1.printVector();
	clock_t time = clock();
	heap1.heapSort();
	time = clock() - time;
	cout << endl;
	heap1.printVector();
	cout << endl << "Running time: " << (float)time / CLOCKS_PER_SEC << endl;
	_getch();
}