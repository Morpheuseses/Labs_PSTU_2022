#ifndef LIST_H
#define LIST_H

#pragma once
#include "pair.h"
#include<iostream>
using namespace std;

template <class T>
class Node
{
	template <typename> friend class List;
private:
	T data;
	Node<T>* next = nullptr;
public:
	Node()
	{
	}
};

template <class T>
class List
{

private:
	int size;
	Node<T>* front;
	Node<T>* back;
public:
	List()
	{
		size = 0;
		front = back = nullptr;
	}
	List(int n, T data)
	{

		front = new Node<T>;
		front->data = data;
		Node<T>* tmp;
		Node<T>* prev = front;
		for (int i = 0; i < n - 1; i++)
		{
			tmp = new Node<T>;
			tmp->data = data;
			prev->next = tmp;
			prev = tmp;
		}
		back = prev;
		size = n;
	}
	List(const List<T>& l)
	{

		size = l.size;
		front = l.front;
		back = l.back;
	}
	~List()
	{
		while (front != nullptr)
			pop();
	}
	T& operator[](int index) const
	{

		Node<T>* curr = front;
		for (int i = 0; i < index - 1; i++)
		{
			curr = curr->next;
		}
		return curr->data;
	}
	List<T>& operator= (const List<T>& list)
	{

		int size_tmp = size;
		for (int i = 0; i < size_tmp; i++)
		{
			this->pop();
		}
		for (int i = 0; i < list.size; i++)
		{
			this->push(list[i]);
		}
		return *this;
	}
	List<T> operator * (List<T>& list)
	{
		T data();
		int new_size = max(size, list());
		List<T> new_list(new_size, data);
		for (int i = 0; i < min(size, list()); i++)
		{
			new_list[i] = (*this)[i] * list[i];
		}
		return new_list;
	}

	int operator()() {
		return size;
	}

	void push(T data)
	{

		if (size == 0)
		{
			front = new Node<T>;
			front->data = data;
			back = front;
		}
		else
		{
			Node<T>* tmp = new Node<T>;
			tmp->data = data;
			back->next = tmp;
			back = tmp;
		}
		size++;
	}
	T pop()
	{
		T data = front->data;
		Node<T>* tmp = front;
		front = front->next;
		size--;
		delete tmp;
		return data;
	}
	void output(Node<T>* n) const
	{
		cout << n->data << " ";
		if (n == back) { return; }
		output(n->next);
	}
	void show() const
    {
		if (size == 0) cout << "List is empty " << endl;
		else output(front);
	}
	template <class T2>
	friend ostream& operator<< (ostream& out, const List<T2>& l)
	{
		l.show();
		return out;
	}
	template <class T2>
	friend istream& operator>> (istream& in, List<T2>& l)
	{

		T data;
		in >> data;
		l.push(data);
		return in;
	}
};


#endif

