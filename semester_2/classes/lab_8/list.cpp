#include "list.h"
#include<iostream>
using namespace std;

List::List()
{
	size = 0;
	front = back = nullptr;
}
List::List(int n, Object* data) {

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
void List::push(Object* data) {

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
Object* List::pop() {

	Object* data = front->data;
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
void List::Add()
{
	Object* p;
	cout << "1.Print" << endl;
	cout << "2.Magazine" << endl;
	int c;
	cin >> c;
	if (c==1)
	{
		Print* print = new Print;
		print->input();
		p = print;
		push(p);
		size++;
	}
	else if (c == 2)
	{
		Magazine* mag = new Magazine;
		mag->input();
		p = mag;
		push(p);
		size++;
	}
}
void List::Del()
{
	if (size == 0) return;
	pop();
}
void List::Make(int s)
{
	size = s;
	Print* data = new Print();
	List* l = new List(size, data);
	front = l->getFront();
	back = l->getBack();
	delete l;
	delete data;
}
Object*& List:: operator[](int index) const {

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
int List::operator()() {

	return size;
}
void List::output(Node* n) const {

	n->data->show();
	if (n == back) { return; }
	output(n->next);
}
void List::show() const {

	if (size == 0) cout << "List is empty " << endl;
	else output(front);
}
void List::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		for (int i = 0; i < size; i++)
		{
			Object* p = (*this)[i];
			p->HandleEvent(e);
		}
	}
}
ostream& operator<< (ostream& out, const List& l) {

	l.show();
	return out;
}