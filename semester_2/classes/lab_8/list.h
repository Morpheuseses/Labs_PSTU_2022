#pragma once
#include "magazine.h"
#include<iostream>
using namespace std;


class Node
{
	friend class List;
protected:
	Object* data;
	Node* next = nullptr;
};
class List
{
	friend class Iterator;
protected:
	int size;
	Node* front;
	Node* back;
public:
	List();
	List(int n, Object* data);
	List(const List& l);
	~List();
	void Make(int);
	Object*& operator[](int index) const;
	List& operator= (const List& list);
	int operator()();
	void push(Object*);
	void Add();
	void Del();
	Node* getFront()
	{
		return front;
	}
	Node* getBack()
	{
		return back;
	}
	Object* pop();
	void output(Node* n) const;
	void show() const;
	void HandleEvent(const TEvent& e);
	friend ostream& operator<< (ostream& out, const List& l);

};