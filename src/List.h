#pragma once
#ifndef LIST_H	
#define LIST_H
#include <iostream>

template <class T>
class List {
private:
	struct node {
		T data;
		node* next;
	};
	node* head;
	node* temp;
	int counter = 0;
public:
	List();
	//~List();
	void pushFront(T);
	void popFront();
	void pushBack(T);
	void popBack();
	void print();
	T getData(int);
	int size();
	List<T>& operator+=(const T&);
};

template <class T>
List<T>::List() {
	head = NULL;
};

/*
template <class T>
List<T>::~List() {
	
	while (head)
	{
		node * p = head;
		head = head->next;
		delete p;
	}
	counter = 0;
};
*/

template <class T>
void List<T>::pushFront(T data)
{
	node *p = new node;
	p->data = data;
	p->next = head;
	head = p;
	counter++;
	
}

template <class T>
void List<T>::popFront()
{
	node *p = head;
	if (p)
	{
		head = p->next;
		delete p;
		counter--;
	}
}

template <class T>
void List<T>::pushBack(T data)
{
	node *e = new node;
	e->next = NULL;
	e->data = data;
	node *p = head;
	if (p)
	{
		while (p->next) p = p->next;
		p->next = e;
	}
	else head = e;
	counter++;
}

template <class T>
void List<T>::popBack()
{
	node *p = head;
	if (p)
	{
		if (p->next)
		{
			while (p->next->next) p = p->next;
			delete p->next;
			p->next = NULL;
		}
		else
		{
			delete p;
			head = NULL;
		}
		counter--;
	}
}

template <class T>
T List<T>::getData(int number)
{
	node * p;
	if (number < 0 || number > counter - 1) return T();
	else if (number == 0) return head->data;
	else
	{
		p = head;
		while (number--) p = p->next;
		return p->data;
	}
}

template <class T>
int List<T>::size() 
{
	return counter;
}

template <class T>
void List<T>::print()
{
	unsigned i;
	node * p = head;
	for (i = 0; p; p = p->next)
		std::cout << "Element #" << i++ << " = " << p->data << std::endl;
	std::cout << std::endl;
}

template <class T>
List<T>& List<T>::operator+=(const T &data) {
	pushBack(data);
	return *this;
}
#endif