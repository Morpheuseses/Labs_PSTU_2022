#ifndef LIST_H
#define LIST_H

#pragma once
#include<iostream>
#include "pair.h"
using namespace std;

template <class T>
class Node
{
	template <typename> friend class List;
private:
	T data = 0;
	Node<T>* next = nullptr;
};

template <class T>
class List
{

private:
	int size;
	Node<T>* front;
	Node<T>* back;
public:
	List();
	List(int n, T data);
	List(const List<T>& l);
	~List();
	T& operator[](int index) const;
	List<T>& operator= (const List<T>& list);
	List<T> operator * (List<T>& list);
	int operator()();
	void push(Pair data);
	T pop();
	void output(Node<T>* n) const;
	void show() const;
	template <class T2>
	friend ostream& operator<< (ostream& out, const List<T2>& l);
	template <class T2>
	friend istream& operator>> (istream& in, List<T2>& l);
};

#endif