#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "OOP 5.h"
#include <time.h>

using namespace std;

void UI()
{
	char input;
	int index;
	int data;
	List list;
	List list1;
	List list2;

	srand(time(NULL));
	for (int i = 0; i < 20; i++) {
		list.push_back(rand() % 30);
	}

	/*list.push_back(5);
	list.push_back(7);
	list.push_back(1);
	list.push_back(3);
	list.push_back(4);
	list.push_back(9);
	list.push_back(2);
	list.push_back(8);
	list.push_back(0);
	list.push_back(6);*/

	cout << "Начальный список: \n";
	list.printList();

	cout << "'0' - добавить узел\n";
	cout << "'1' - вставить узел\n";
	cout << "'2' - удалить узел\n";
	cout << "'3' - разделить, сравнив с N\n";
	cout << "'4' - удалить списки и завершить\n";


	while (true)
	{
		cout << "Нажмите: ";
		cin >> input;
		switch (input) {
		case '0':
			cout << "Введите значение: ";
			int newData;
			cin >> newData;
			list.push_back(newData);
			list.printList();
			break;
		case '1':
			cout << "Введите индекс: ";
			cin >> index;
			cout << "Введите значение: ";
			cin >> data;
			list.insert(data, index);
			list.printList();
			break;
		case '2':
			cout << "Введите индекс: ";
			cin >> index;
			list.deleteByIndex(index);
			list.printList();
			break;
		case '3':
			cout << "Введите N: ";
			int N;
			cin >> N;
			list.split(&list, &list1, &list2, N);
			cout << "> N:\n";
			list1.printList();
			cout << "<= N:\n";
			list2.printList();
			break;
		case '4':
			list.deleteList();
			list1.deleteList();
			list2.deleteList();
			return;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	UI();
	system("pause");
	return 0;
}