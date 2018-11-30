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
		cout << "1 - ������������� ��������� ������� MxN\n";
		cout << "2 - �������� ������� � �������\n";
		cout << "3 - ������� ������� �� ����� � ������� �-������ � Y-������\n";
		cout << "4 - ������� ������� � ������� �-������ � Y-������\n";
		cout << "5 - ������� ������ � �������, ���������� ������������ �������\n";
		cout << "6 - ��������� ������\n";
		cout << "������� �����: ";
		cin >> i;
		switch (i)
		{
		case 1:
			int N, M, K;
			cout << "������� �����: ";
			cin >> M;
			cout << "������� ������: ";
			cin >> N;
			cout << "������� ���������� ��������� ���������: ";
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
			cout << "������� ���������� x: ";
			cin >> x;
			cout << "������� ���������� y: ";
			cin >> y;
			cout << "������� �������� ��������: ";
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
			cout << "������������ ��������: " << m.findMax()->data << endl;
			m.deleteMax();
			cout << "�������\n\n";
			break;
		case 6:
			return;
		default: cout << "�������� �����\n\n";
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