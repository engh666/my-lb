#include "stdafx.h"
#include "OOP 3.h"
#include <iostream>
#include <Windows.h>
#include <vector>

using namespace std;

vector<bool> inputFolds()
{
	vector<bool> v;
	char input;
	cout << "к - выпуклый сгиб, о - впуклый, другое - завершить ввод: ";
	while (true)
	{
		cin >> input;
		switch (input) {
		case 'к':
			v.push_back(true);
			break;
		case 'о':
			v.push_back(false);
			break;
		default:
			return v;
		}
	}
}

void inputBigFolds(Tape &t)
{
	char input;
	cout << "п - согнуть к себе, з - от себя, другое - завершить ввод: ";
	while (true)
	{
		cin >> input;
		switch (input) {
		case 'п':
			t.fold(true);
			break;
		case 'з':
			t.fold(false);
			break;
		default:
			return;
		}
	}
}

void UI()
{
	char input, input1;
	Tape t, t1;
	cout << "'0' - согнуть (П или З)\n";
	cout << "'1' - вывести сгибы (О или К)\n";
	cout << "'2' - ввести сгибы (О или К)\n";
	cout << "'3' - вывести сгибания (П или З)\n";
	cout << "остальное - завершить\n";

	while (true)
	{
		cout << "Введите: ";
		cin >> input;
		switch (input) {
		default:
			return;
		case '0':
			inputBigFolds(t);
			break;
		case '1':
			t.print();
			break;
		case '2':
			t1 = Tape(inputFolds());
			break;
		case '3':
			t1.printBig();
			break;
		}
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	UI();
	system("pause");
	return 0;
}
