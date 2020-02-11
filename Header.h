#pragma once
struct queue
{
	int number;
	char name[20];
	queue* next;
	queue* prev;
};

bool isEmpty();
void InitQueue();
void push(int, char*); // �������� � �������
void Add_from_file();
void Pop(); // �������� �� �����
void Add_from_user();
void Print();
void Delete_all_elements();
void Panel();