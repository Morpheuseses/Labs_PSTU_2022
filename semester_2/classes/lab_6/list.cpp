#include "list.h"
#include<iostream>
using namespace std;

List::List()
{
	size = 0;
	Iterator* it = new Iterator;
	it->elem = nullptr;
	front = it;
	end = it;
	delete it;
}
List::List(int n, int data)
{
	size = n;
	Node* tmp = new Node();
	tmp->data = data;
	Iterator* it = new Iterator;
	Node* prev = tmp;
	tmp = new Node();
	tmp->data = data;
	prev->next = tmp;
	tmp->prev = prev;
	prev = tmp;
	it->elem = prev;
	front = it;
	for (int i = 0; i < n; i++)
	{
		tmp = new Node();
		tmp->data = data;
		tmp->prev = prev;
		prev->next = tmp;
		prev = tmp;

	}
	it->elem = prev;
	end = it;
	delete it; 
}
List::List(int n)
{
	int data;
	size = n;
	Node* tmp = new Node();
	cout << "data?";  cin >> data;
	tmp->data = data;
	Iterator* it = new Iterator;
	it->elem = tmp;
	front = it;
	Node* prev = tmp;
	for (int i = 0; i < n; i++)
	{
		tmp = new Node();
		cout << "next?";  cin >> data;
		tmp->data = data;
		tmp->prev = prev;
		prev->next = tmp;
		prev = tmp;

	}
	it->elem = prev;
	end = it;
	delete it;
}
List::List(const List& l)
{
	size = l.size;
	front = l.front;
	end = l.end;
}
List::~List()
{

}
List& List::operator= (const List& l) {

	front = l.front;
	end = l.end;
	return *this;
}
int& List::operator[] (int index) {

	Iterator* it;
	if (size - index < size / 2)
	{
		it = front;
		for (int i = 0; i < size - index; i++)
		{
			++it;
		}
	}
	else
	{
		it = end;
		for (int i = 0; i < size - index; i++)
		{
			--it;
		}
	}
	return *(*it);
}
int& List::operator()() {

	return size;
}
List& List::operator*(const List& l) {

	Iterator* it = front;
	Iterator* it_l = l.front;
	for (int i = 0; i < size; i++)
	{
		*(*it) = *(*it) * *(*it_l);
		it++; it_l++;
	}
	return *this;
}
Iterator* List::first() {

	return front;
}
Iterator* List::last() {

	return end;
}
ostream& operator<<(ostream& out, const List& l) {

	List list = l;
	Iterator* it = list.first();
	out << *(*it) << " ";
	for (int i = 0; i < list()-1; i++)
	{
		out << *(*it) << " ";
		it++;
	}
	return out;
}
istream& operator>>(istream& in, List& l)
{
	int s;
	cout << "elements?"; cin >> s;
	List list(s);
	l = list;
	return in;
}
void Iterator::operator+=(const int n) {

	Iterator* it = this;
	int i = n;
	for (i; i > 0 && it->elem != nullptr; i--)
	{
		it++;
	}
	if (i == 0) return;
	it->elem = nullptr;
}