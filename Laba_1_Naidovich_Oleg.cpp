#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

/*

2.4. Очередь. Элемент списка структура.
Структура содержит информацию о владельцах номеров телефонов, поля: номер телефона, фамилия.
(short, char*, double)



Для обработки стека(дека, очереди) реализовать методы в классе:
1.	Создание списка (чтение данных из файла) +
2.	Добавить элемент  +
3.	Удаление  элемента  +
4.	Удаление всех элементов
5.	Вывод списка на консоль или в файл
6.	Запросы на выполнение операций оформить в виде меню.


*/

using namespace std;

int kol_vo = 0;

struct queue
{
	int number;
	char name[20];
	queue* next;
	queue* prev;
};

queue* head, * tail;

bool isEmpty()
{
	return head == 0 ? true : false;
}

void InitQueue()
{
	head = 0;
	tail = 0;
}

void push(int data_number, char* data_name) // добавить в очередь
{
	queue* tmp = new queue;
	strcpy(tmp->name, data_name);
	tmp->number = data_number;
	tmp->next = 0;
	if (head == 0)
	{
		head = tmp;
		tail = head;
		return;
	}
	tail->next = tmp;
	tail = tmp;
	tail->next = 0;
}

void Add_from_file()
{
	ifstream file;
	file.open("gift.txt");

	if (!file.is_open()) // проверка на открытие файла
	{
		cout << "Ошибка открытия файла, проверьте наличие файла в папке!" << endl;
		return;
	}

	int count = 0;

	int data_number;
	char data_name[20];

	char* pch;
	char* line = new char[50];

	cout << "Файл gift.txt открыт!" << endl;
	while (file.getline(line, 200)) // в line вся строка
	{
		pch = strtok(line, " _-:");
		while (pch != NULL)
		{
			if (count++ % 2 == 0)
			{
				strcpy(data_name, pch);
				pch = strtok(NULL, line); // берет следующее значение в строке
				continue;
			}
			data_number = atoi(pch);
			push(data_number, data_name);		
			pch = strtok(NULL, line); // берет следующее значение в строке
		}
	}
}

void Pop() // вытащить из файла
{
	if (!isEmpty())
	{
		char data_name[20];
		queue* tmp = head;
		int data_number = head->number;
		strcpy(data_name, head->name);
		head = head->next;
		delete tmp;
		cout << "Мы удалили первый элемент: \nИмя: " << data_name << " Номер: " << data_number;
	}
	else
		return;
}

void Add_from_user()
{
	int data_number;
	char data_name[20];

	cout << "\nВведите номер телефона: "; cin >> data_number;
	cout << "Введите имя владельца: "; cin >> data_name;
	push(data_number, data_name);
}


void Print()
{
	if (isEmpty() == true)
	{
		cout << "Очередь пустая. Добавьте новые элементы\n"; 
		return;
	}
	while (!isEmpty())
	{
		cout << "\nИмя: " << head->name << " Номер: " << head->number << "\n";
		head = head->next;
	}
	return;
}

void Delete_all_elements()
{

}

void Panel()
{
	int user_data = 123;
	cout << "\nДля выхода введите 111\n";
	cout << "\n0. Инициализация очереди - без этого работать не будет";
	cout << "\n1. Добавить в очередь элементы из файла";
	cout << "\n2. Добавить элемент с консоли";
	cout << "\n3. Удаление последнего элемента";
	cout << "\n4. Удаление всех элементов";
	cout << "\n5. Вывод все на экран";

	while (user_data != 111)
	{
		cout << "\nВведите номер операции: ";  cin >> user_data;
		switch (user_data)
		{
			case(111):
				return;
			case(0):
			{
				InitQueue();
				break;
			}
			case(1):
			{
				Add_from_file();
				break;
			}
			case(2):
			{
				Add_from_user();
				break;
			}
			case(3):
			{
				Pop();
				break;
			}
			case(4):
			{
				Delete_all_elements();
				break;
			}
			case(5):
			{
				Print();
				break;
			}
			default:
			{
				cout << "\nВы ввели неверное значение: ";
				break;
			}
		}
	}
}

int main(void)
{
	setlocale(LC_ALL, "RUS");

	Panel();
}