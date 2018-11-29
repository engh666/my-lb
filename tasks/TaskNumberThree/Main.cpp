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
	cout << "� - �������� ����, � - �������, ������ - ��������� ����: ";
	while (true)
	{
		cin >> input;
		switch (input) {
		case '�':
			v.push_back(true);
			break;
		case '�':
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
	cout << "� - ������� � ����, � - �� ����, ������ - ��������� ����: ";
	while (true)
	{
		cin >> input;
		switch (input) {
		case '�':
			t.fold(true);
			break;
		case '�':
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
	cout << "'0' - ������� (� ��� �)\n";
	cout << "'1' - ������� ����� (� ��� �)\n";
	cout << "'2' - ������ ����� (� ��� �)\n";
	cout << "'3' - ������� �������� (� ��� �)\n";
	cout << "��������� - ���������\n";

	while (true)
	{
		cout << "�������: ";
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
