#pragma once
#include<iostream>
using namespace std;

class Node;
class List;
class Iterator;
class Node
{
	friend class List;
	friend class Iterator;
private:
	int data = 0;
	Node* next = nullptr;
};
class Iterator
{
	friend class List;
private:
	Node* elem = nullptr;
public:
	Iterator() {elem = nullptr;}
	Iterator(const Iterator& it) {elem = it.elem;}
	bool operator == (const Iterator& it) {return elem == it.elem;}
	bool operator != (const Iterator& it) {return elem != it.elem;}
	void operator ++ () { elem = elem->next;};
	void operator ++ (int) {elem = elem->next;};
	Iterator& operator + (int n) {
		for (int i =0; i < n && elem->next != nullptr; i++)
			elem = elem->next;
		return *this;
	}
	int operator*() const { return elem->data;}
};
class List
{
	friend class Iterator;
private:
	int size;
	Iterator beg;
	Iterator end;
	Node* front;
	Node* back;
public:
	List();
	List(int n, int data);
	List(const List& l);
	~List();
	int& operator[](int index) const;
	List& operator= (const List& list);
	List operator * (List& list);
	int operator()();
	void push(int );
	int pop();
	void output(Node* n) const;
	void show() const;
	friend ostream& operator<< (ostream& out, const List& l);
	friend istream& operator>> (istream& in, List& l);
	Iterator first() { return beg;}
	Iterator last() {return end;}
};