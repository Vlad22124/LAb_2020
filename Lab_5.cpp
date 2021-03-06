#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;


class Queue;

class Customer {
private:
	int number_card;
	string name;
	Customer *Next;

public:
	friend Queue;


	Customer(int number_card, string name, Customer *Next = nullptr) {
		this->number_card = number_card;
		this->name = name;
		this->Next = Next;


	}


	friend ostream & operator <<(ostream& stream, Customer&other) {
		return stream << other.number_card << " " << other.name << endl;
	}

};




class Queue
{
	friend Customer;
	friend ostream & operator <<(ostream& stream, Customer&other);

private:


	Customer *head;//голова
	Customer *tail;//хвост
	int count;

public:

	Queue() {
		head = nullptr;
		std::cout << "Вызвался конструктор " << this << std::endl;
	};

	Queue(const Queue &other) {// конструктор копирования
		Customer *current = other.head;
		while (current != nullptr) {
			this->push(current->number_card, current->name);
			current = current->Next;

		}

	}

	~Queue() {
		std::cout << "Сработал  деструктор " << this << std::endl;
		clean();

	};

	void push(int data, string str)
	{
		Customer *current = new Customer(data, str);

		if (head == nullptr) {
			head = tail = current;
		}
		else {
			tail->Next = current;
			tail = current;// хвост получает новое значение
		}

			count++;
	}


	void push_front(int data, string str) {

		head = new Customer(data, str, head);

		count++;

	}


	void  print() {
		cout << "Элементы в списке:" << std::endl << std::endl;
		cout << endl << endl;
		Customer *temp = head;
		
		while (temp) {

			cout << *temp << endl;

			temp = temp->Next;
			cout << endl << endl;
		}
		

	}

	void pop() {// память


		Customer *temp = head;// временная переменная хранящая адрес головного элемента
		head = head->Next;
		delete temp;
		count--;
	}

	void clean()
	{
		while (count != 1) // выполняется пока count != 1
		{
			pop();

		}
		Customer *temp = head;
		delete temp;
		count--;
	}

	int getsize() {
		return count;
	}

	bool isEmpty() {
		if (head = nullptr)
			return true;
		else
			return false;
	}



};





int main()
{
	setlocale(LC_ALL, "ru");
	Queue a;
	a.push(12345678, "Fred");
	a.push(1246, "Lucy");
	a.push(3547, "Peter");
	a.print();
	cout << "Элементов в очереди:  " << a.getsize() << endl << endl;
	//a.pop();
	//cout <<"Элементов в очереди:  "<< a.getsize() << endl<<endl;
	//a.print();
	//bool g;
	//g = a.isEmpty();
	//cout << g << endl;
	Queue b(a);
	//b = a;
	//b.print();
	system("pause");


}