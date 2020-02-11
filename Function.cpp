#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;

int kol_vo = 0;

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

void push(int data_number, char* data_name) // �������� � �������
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

	if (!file.is_open()) // �������� �� �������� �����
	{
		cout << "������ �������� �����, ��������� ������� ����� � �����!" << endl;
		return;
	}

	int count = 0;

	int data_number;
	char data_name[20];

	char* pch;
	char* line = new char[50];

	cout << "���� gift.txt ������!" << endl;
	while (file.getline(line, 200)) // � line ��� ������
	{
		pch = strtok(line, " _-:");
		while (pch != NULL)
		{
			if (count++ % 2 == 0)
			{
				strcpy(data_name, pch);
				pch = strtok(NULL, line); // ����� ��������� �������� � ������
				continue;
			}
			data_number = atoi(pch);
			push(data_number, data_name);
			pch = strtok(NULL, line); // ����� ��������� �������� � ������
		}
	}
}

void Pop() // �������� �� �����
{
	if (!isEmpty())
	{
		char data_name[20];
		queue* tmp = head;
		int data_number = head->number;
		strcpy(data_name, head->name);
		head = head->next;
		delete tmp;
		cout << "�� ������� ������ �������: \n���: " << data_name << " �����: " << data_number;
	}
	else
		return;
}

void Add_from_user()
{
	int data_number;
	char data_name[20];

	cout << "\n������� ����� ��������: "; cin >> data_number;
	cout << "������� ��� ���������: "; cin >> data_name;
	push(data_number, data_name);
}

void Print()
{
	if (isEmpty() == true)
	{
		cout << "������� ������. �������� ����� ��������\n";
		return;
	}
	while (!isEmpty())
	{
		cout << "\n���: " << head->name << " �����: " << head->number << "\n";
		head = head->next;
	}
	return;
}

void Delete_all_elements()
{
	if (isEmpty() == true)
	{
		cout << "������� ��� ������\n";
		return;
	}
	while (!isEmpty())
	{
		head = head->next;
	}
}

void Panel()
{
	int user_data = 123;
	cout << "\n��� ������ ������� 111\n";
	cout << "\n0. ������������� ������� - ��� ����� �������� �� �����";
	cout << "\n1. �������� � ������� �������� �� �����";
	cout << "\n2. �������� ������� � �������";
	cout << "\n3. �������� ���������� ��������";
	cout << "\n4. �������� ���� ���������";
	cout << "\n5. ����� ��� �� �����";

	while (user_data != 111)
	{
		cout << "\n������� ����� ��������: ";  cin >> user_data;
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
			cout << "\n�� ����� �������� ��������: ";
			break;
		}
		}
	}
}