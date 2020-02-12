
#include "Header_1.h"


//queue::queue() {};
void queue::push(int data_number, char* data_name) // добавить в очередь
{
	human* tmp = new human;
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
	tmp->prev = tail;
	tail = tmp;
	tail->next = 0;
	head->prev = 0;
}

void queue::Add_from_file()
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

void queue::Add_from_user(queue q)
{
	int data_number;
	char data_name[20];

	cout << "\nВведите номер телефона: "; cin >> data_number;
	cout << "Введите имя владельца: "; cin >> data_name;
	push(data_number, data_name);
}

void queue::Pop(queue q)
{

	if (!isEmpty())
	{
		char data_name[20];
		human* tmp = head;
		int data_number = head->number;
		strcpy(data_name, head->name);
		if (head->next == 0)
		{
			delete tmp;
			head = 0;
			tail = 0;
			cout << "\nСписок пустой!";
			return;
		}
		head = head->next;
		head->prev = 0;
		delete tmp;
		cout << "Мы удалили первый элемент: \nИмя: " << data_name << " Номер: " << data_number;
	}
	else
	{
		cout << "\nНету элементов!";
		return;
	}
		
}

void queue::Print(queue q)
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
		head->prev = 0;
	}
	return;
}

bool queue::isEmpty()
{
	return head == 0 ? true : false;
}

void queue::Delete_all_elements(queue q)
{
	if (isEmpty() == true)
	{
		cout << "Очередь уже пустая\n";
		return;
	}
		//head = head->next;
		//human* tmp = head;

		cout << "\nУдаляем элементы";
		
		while(tail->prev != NULL)
		{
			tail = tail->prev;

			if (tail->prev == NULL)
			{
				return;
			}
			delete tail->next;
		}
}

void queue::Panel(queue q)
{
	int user_data = 123;
	cout << "\nДля выхода введите 111\n";
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
		case(1):
		{
			Add_from_file();
			break;
		}
		case(2):
		{
			Add_from_user(q);
			break;
		}
		case(3):
		{
			Pop(q);
			break;
		}
		case(4):
		{
			Delete_all_elements(q);
			break;
		}
		case(5):
		{
			Print(q);
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

//queue::~queue() {};