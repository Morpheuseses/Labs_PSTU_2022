#pragma once
#include<iostream>
using namespace std;

class Node;
class Iterator;
class List
{
private:
	int size;
	Iterator* front;
	Iterator* end;
public:
	List();
	List(int n, int data); //
	List(int n);
	List(const List&);
	~List();
	List& operator= (const List&); //
	int& operator[] (int index);
	int& operator()();
	List& operator*(const List&);
	friend ostream& operator<<(ostream& out, const List& l);
	friend istream& operator>>(istream& in, List& l);
	Iterator* first();
	Iterator* last();
};
class Node
{
	friend class List;
	friend class Iterator;
private:
	Node* next;
	Node* prev;
	int data;
public:
	void setData(int d) { data = d; }
	Node() 
	{
		data = 0;
		next = nullptr;
		prev = nullptr;
	}
};
class Iterator
{
	friend class List;
private:
	Node* elem;
public:	
	void operator++ () { elem = elem->next; }
	void operator-- () { elem = elem->prev; }
	int& operator *() { return elem->data; }
	bool operator== (const Iterator*& it) { return it->elem == elem; }
	bool operator!= (const Iterator*& it) { return it->elem != elem; }
	void operator+= (const int n); //+n
};