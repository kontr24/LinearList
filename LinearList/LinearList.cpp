//#include "stdafx.h"
#include "iostream"
#include <stdlib.h>
#include <time.h>
using namespace std;
struct list
{
	int inf = NULL;
	list* next = 0;
};
list* temp = new list;
list* tempFirst = new list;
list* tempSecond = new list;
list* first = new list;
list* p = first;


void inputList(int n) {            //1.Построение линейного списка
	p = first;
	cin >> p->inf;
	for (int i = 0; i < n - 1; i++) {
		p->next = new list;
		p = p->next;
		cin >> p->inf;
	}
	p->next = 0;
	int c = 1;
}

void print(list* p) {                   //2.печать списка
	p = first;
	while (p) {
		cout << p->inf << " ";
		p = p->next;
	}
	cout << endl;
}

void add() {                          //3.вставка элемента в начало списка
	cout << "Введите элемент: \n";
	list* q = new list;
	cin >> q->inf;
	q->next = first;
	first = q;
}

void inputAfterElement(int k) {      //4.Включение элемента в середину (после i-го элемента)

	p = first;

	for (int i = 0; i < k; i++)
		p = p->next;
	list* w = new list;
	cout << "Введите элемент: \n";
	cin >> w->inf;
	w->next = p->next;
	p->next = w;
}

void inputBeforeElement(int n) {    //6. Включение элемента в середину (перед i-ым элементом)

	p = first;

	for (int i = 0; i < n; i++)
		p = p->next;
	list* w = new list;
	cout << "Введите элемент: \n";
	cin >> w->inf;
	w->next = p->next;
	p->next = w;
}

void addEnd(int t) {                  //5.добавление элемента в конец списка.
	list* q = new list;
	p = first;
	while (p->next) {
		p = p->next;
	}
	q->inf = t;
	q->next = NULL;
	p->next = q;
}

void deleteMidElement(int n) {        //7.Удаление элемента из середины (i-го элемента)
	p = first;
	list* w = new list;
	for (int i = 0; i < n - 1; i++) {
		p = p->next;
	}
	w = p->next;
	p->next = w->next;
	delete w;

	cout << "Элемент успешно удален!\n----------";
}
void deleteLastElement() {          //9.Удаление элемента из конца списка
	p = first;

	while (p->next->next) {
		p = p->next;
	}
	p->next = NULL;
	cout << "Последний элемент успешно удален!\n";
}
void deleteFirstElement() {        //8.Удаление элемента из начала списка
	p = first;
	list* w = new list;
	w = p->next;
	first = w;
	cout << "Первый элемент успешно удален!\n";
}
void countElements() {        //10.Подсчет числа элементов списка
	int i = 0;
	p = first;
	while (p) {
		i++;
		p = p->next;
	}

	cout << "В списке всего " << i << " элементов!\n";
}
void dostup(int n) {      //11
	p = first;

	for (int i = 0; i < n - 1; i++)
		p = p->next;
	cout << "Элемент с индексом [" << n << "]: " << p->inf << "\n";
}
void findElement(int n) {                    //12.Поиск образца
	p = first;
	int i = 0;
	while (p) {

		if (p->inf == n) {
			cout << "Элемент со значением \"" << n << "\" с индексом - " << i + 1 << "\n";
			return;
		}
		i++;
		p = p->next;
	}
	cout << "Не найден!" << endl;
}
void copyList(list* r) {                     //13.Создание копии списка
	temp = r;
	temp = first;
	while (temp) {
		cout << temp->inf << " ";
		temp = temp->next;
	}
	cout << endl;
}
void splitList()
{
	p = first;
	list* chet = new list;
	list* nechet = new list;
	list* p1 = chet;
	list* p2 = nechet;
	list* w1 = p1;
	list* w2 = p2;
	while (p)
	{
		if (p->inf % 2)
		{
			p2->inf = p->inf;
			p2->next = new list;
			w2 = p2;
			p2 = p2->next;
		}
		else
		{
			p1->inf = p->inf;
			p1->next = new list;
			w1 = p1;
			p1 = p1->next;
		};
		p = p->next;
	}
	w1->next = 0;
	w2->next = 0;
	p1 = chet;
	while (p1)
	{
		cout << p1->inf << " ";
		p1 = p1->next;
	}
	p2 = nechet;
	cout << " " << endl;
	while (p2)
	{
		cout << p2->inf << " ";
		p2 = p2->next;
	}
	cout << " " << endl;
}
void sortList() {                        //15.Сортировка линейного списка
	list* q = first;
	list* r = first;

	while (q) {
		r = q->next;
		while (r) {
			if (q->inf < r->inf) {
				int temp = q->inf;
				q->inf = r->inf;
				r->inf = temp;
			}
			r = r->next;
		}
		q = q->next;
	}
	cout << "Отсортированный список элементов: ";
	print(q);
	cout << "\n";
}
void deleteList() {                       //16.Удаление всего списка с освобождением памяти
	temp = new list;
	tempFirst = new list;
	tempSecond = new list;
	first = new list;
	p = first;
	cout << "Список пуст и память успешно очищена!\n";
}
int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	int num = 1;

	while (num) {

		cout << "Текущий список элементов: " << "\n";
		p = first;
		if (p->inf == NULL) {
			cout << "Сейчас список пуст!\n";
		}
		else {
			print(p);
		}
		cout << "\n 1.Построение линейного списка\n 2.Печать списка\n 3.Вставка элемента в начало списка\n 4.Включение элемента в конец списка\n 5.Включение элемента в середину (после i-го элемента)\n 6.Включение элемента в середину (перед i-ым элементом)\n 7.Удаление элемента из середины (i-го элемента)\n 8.Удаление элемента из конца списка\n 9.Удаление элемента из начала списка\n 10.Подсчитать количество элементов списка\n 11.Получение доступа к i-ому узлу для анализа\n 12.Поиск образца\n 13.Создание копии списка\n 14.Разбиение списка на два по заданному критерию\n 15.Сортировка линейного списка\n 16.Удаление всего списка с освобождением памяти\n 17.Очистка консоли\n";
		cout << "Номер операции > ";
		cin >> num;
		switch (num) {
		case 0: break;
		case 1: {
			cout << "Введите количество элементов для ввода\n";
			cin >> n;
			cout << "Начните вводить элементы: \n";
			inputList(n);
			break;
		}
		case 2: {
			p = first;
			if (p->inf == NULL) {
				cout << "Error\n";
			}
			else {
				print(p);
			}
			break;
		}
		case 3: {

			add();
			break;
		}
		case 4: {
			cout << "Введите значение элемента = ";
			cin >> n;
			addEnd(n);
			break;
		}
		case 5: {
			int n;
			cout << "i = ";
			cin >> n;
			inputAfterElement(n);
			break;
		}
		case 6: {
			int n;
			cout << "i = ";
			cin >> n;
			inputBeforeElement(n);
			break;
		}
		case 7: {
			int n;
			cout << "Индекс удаляемого элемента: ";
			cin >> n;
			deleteMidElement(n);
			break;
		}
		case 8: {
			int n;
			deleteLastElement();
			break;
		}
		case 9: {
			int n;
			deleteFirstElement();
			break;
		}
		case 10: {
			countElements();
			break;
		}
		case 11: {
			int n;
			cout << "Введите индекс элемента: ";
			cin >> n;
			dostup(n);
			break;
		}
		case 12: {
			int n;
			cout << "Введите число: ";
			cin >> n;
			findElement(n);
			break;
		}
		case 13: {
			copyList(p);
			cout << "Список скопирован!";
			break;
		}
		case 14:
		{
			splitList();
			p = first;
			cout << " Список расчленён\n ";
			break;
		}
		case 15: {
			sortList();
			system("pause");
			break;
		}
		case 16: {
			deleteList();
			break;
		}
		case 17: {
			system("cls");
		}
		default:
			break;
		}
		system("pause");
		system("cls");
	}
}

