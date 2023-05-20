#pragma once
#include<iostream>
using namespace std;
const int MAX_SIZE = 30;



class Node
{
	friend class List;
private:
	int data = 0;
	Node* next = nullptr;
};
class List
{
private:
	int size;
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
	void push(int);
	int pop();
	void output(Node* n) const;
	void show() const;
	Node*& operator+ (int n); // how to do it properly (I need to access, or get value of the element? I don't understand.)
	friend ostream& operator<< (ostream& out, const List& l);
	friend istream& operator>> (istream& in, List& l);
	
};