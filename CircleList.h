#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T data;
	Node<T>* next;
};
template <typename T>
class CircleList
{
private:
	
	int Size;
	Node<T>* rear;
public:
	CircleList() { Size = 0; }
	Node<T>* getRear() const { return rear; }
	void show() const;
	void push_back(const T &x);
	void pop(Node<T>* p);
};
template <typename T>
void CircleList<T>::push_back(const T &x)
{
	Node<T>* p = new Node<T>;
	p->data = x;
	if (Size == 0)
	{
		rear = p;
		p->next = rear;
	}
	else
	{
		p->next = rear->next;
		rear->next = p;
		rear = p;
	}
	Size++;
}
template <typename T>
void CircleList<T>::pop(Node<T>* p)
{
	if (p == rear)
	{
		rear = rear->next;
	}
	Node<T>* q = p;
	while (q->next != p)
	{
		q = q->next;
	}
	q->next = p->next;
	delete p;
	Size--;
}
template <typename T>
void CircleList<T>::show() const
{
	Node<T>* p = rear;
	while (p->next != rear)
	{
		cout << p->next->data<<" ";
		p = p->next;
	}
	cout << p->next->data << endl;
}