#include "list.h"


#include<iostream>
using namespace std;

List::List()
{
	size = 0;
	front = back = nullptr;
}
List::List(int n, int data) {

	if (n > MAX_SIZE) throw 1;
	front = new Node;
	front->data = data;
	Node* tmp;
	Node* prev = front;
	for (int i = 0; i < n - 1; i++)
	{
		tmp = new Node;
		tmp->data = data;
		prev->next = tmp;
		prev = tmp;
	}
	back = prev;
	size = n;
}
List::List(const List& l) {

	size = l.size;
	front = l.front;
	back = l.back;
}
void List::push(int data) {
	if (size + 1 == MAX_SIZE) throw 4;
	if (size == 0)
	{
		front = new Node;
		front->data = data;
		back = front;
		
	}
	else
	{
		Node* tmp = new Node;
		tmp->data = data;
		back->next = tmp;
		back = tmp;
	}
	
	size++;
}
int List::pop() {
	if (size == 0) throw 5;
	int data = front->data;
	Node* tmp = front;
	front = front->next;
	size--;
	delete tmp;
	
	return data;
}
List::~List() {

	while (front != nullptr)
		pop();
}
int& List:: operator[](int index) const {
	if (index < 0) throw 2;
	if (index >= size) { cout << "List length less than value of the index" << endl;; throw 7; } // error doesn't work;
	Node* curr = front;
	for (int i = 0; i < index - 1; i++)
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
	for (int i = 0; i < list.size; i++)
	{
		this->push(list[i]);
	}
	return *this;
}
List List::operator * (List& list) {

	List new_list(max(size, list()), 0);
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
	if (n == back) { return; }
	output(n->next);
}
void List::show() const {

	if (size == 0) cout << "List is empty " << endl;
	else output(front);
}
Node*& List::operator+ (int n)
{
	if (n > size) throw 6;
	Node* curr = front;
	for (int i = 0; i < n-1 && curr != nullptr; i++)
	{
		curr = curr->next;
	}
	return curr;
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