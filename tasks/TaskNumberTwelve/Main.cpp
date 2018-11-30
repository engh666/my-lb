#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "OOP 12.h"

using namespace std;

void UI()
{
	int i;
	Matrix m;
	setlocale(LC_ALL, "Russian");
	
	while (true) {
		cout << "1 - сгенерировать случайную матрицу MxN\n";
		cout << "2 - добавить элемент в матрицу\n";
		cout << "3 - вывести матрицу на экран в порядке Х-обхода и Y-обхода\n";
		cout << "4 - вывести значния в порядке Х-обхода и Y-обхода\n";
		cout << "5 - удалить строку и столбец, содержащие максимальный элемент\n";
		cout << "6 - завершить работу\n";
		cout << "Введите число: ";
		cin >> i;
		switch (i)
		{
		case 1:
			int N, M, K;
			cout << "Введите длину: ";
			cin >> M;
			cout << "Введите ширину: ";
			cin >> N;
			cout << "Введите количество ненулевых элементов: ";
			cin >> K;
			m = Matrix(M, N);
			for (int j = 0; j < K; j++) {
				srand(j);
				m.put(rand() % M, rand() % N, rand() % 50 + 1);
			}
			cout << endl;
			break;
		case 2:
			int x, y, d;
			cout << "Введите координату x: ";
			cin >> x;
			cout << "Введите координату y: ";
			cin >> y;
			cout << "Введите значение элемента: ";
			cin >> d;
			m.put(x, y, d);
			cout << endl;
			break;
		case 3:
			m.printX();
			cout << "------------------\n";
			m.printY();
			cout << endl;
			break;
		case 4:
			m.dataX();
			m.dataY();
			cout << endl;
			break;
		case 5:
			cout << "Максимальное значение: " << m.findMax()->data << endl;
			m.deleteMax();
			cout << "Удалены\n\n";
			break;
		case 6:
			return;
		default: cout << "Неверное число\n\n";
			break;
		}
	}
}

int main()
{
	UI();
	system("pause");
	return 0;
}