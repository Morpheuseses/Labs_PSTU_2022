#include "list.h"
#include<iostream>
using namespace std;

List::List()
{
	size = 0;
	front = back = nullptr;
}
List::List(int n, int data) {

	front = new Node;
	front->data = data;
	Node* tmp;
	Node* prev = front;
	for (int i = 0; i < n-1; i++)
	{
		tmp = new Node;
		tmp->data = data;
		prev->next = tmp;
		prev = tmp;
	}
	back = prev;
	beg.elem = front;
	end.elem = back;
	size = n;
}
List::List(const List& l) {

	size = l.size;
	front = l.front;
	back = l.back;
	beg = l.beg;
	end = l.end;
}
void List::push(int data) {

	if (size == 0)
	{
		front = new Node;
		front->data = data;
		back = front;
		beg.elem = front;
	}
	else
	{
		Node* tmp = new Node;
		tmp->data = data;
		back->next = tmp;
		back = tmp;
	}
	end.elem = back;
	size++;
}
int List::pop() {

	int data = front->data;
	Node* tmp = front;
	front = front->next;
	size--;
	delete tmp;
	beg.elem = front;
	return data;
}
List::~List() {

	while (front != nullptr)
		pop();
}
int& List:: operator[](int index) const {

	Node* curr = front;
	for (int i =0; i < index - 1; i++)
	{
		curr = curr->next;
	}
	return curr->data;
}
List& List::operator= (const List& list) {

	int size_tmp = size;
	for (int i = 0; i < size_tmp; i++)
	{
		this->pop();
	}
	for(int i = 0; i < list.size; i++)
	{
		this->push(list[i]);
	}
	return *this;
}
List List::operator * (List& list) {

	List new_list(max(size, list.size), 0);
	for (int i = 0; i < min(size, list()); i++)
	{
		new_list[i] = (*this)[i] * list[i];
	}
	return new_list;
}
int List::operator()() {

	return size;
}
void List::output(Node* n) const {

	cout << n->data << " ";
	if (n == back) {return;}
	output(n->next);
}
void List::show() const {

	if (size == 0) cout << "List is empty " << endl;
	else output(front);
}
ostream& operator<< (ostream& out, const List& l) {

	l.show();
	return out;
}
istream& operator>> (istream& in, List& l) {

	int data;
	in >> data;
	l.push(data);
	return in;
}