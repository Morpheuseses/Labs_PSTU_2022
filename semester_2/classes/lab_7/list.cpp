#include "list.h"
#include "pair.h"
#include<iostream>
using namespace std;

template <class T>
List<T>::List()
{
	size = 0;
	front = back = nullptr;
}
template <class T>
List<T>::List(int n, T data) {

	front = new Node<T>;
	front->data = data;
	Node<T>* tmp;
	Node<T>* prev = front;
	for (int i = 0; i < n-1; i++)
	{
		tmp = new Node<T>;
		tmp->data = data;
		prev->next = tmp;
		prev = tmp;
	}
	back = prev;
	size = n;
}
template <class T>
List<T>::List(const List<T>& l) {

	size = l.size;
	front = l.front;
	back = l.back;
}
template <class T>
void List<T>::push(Pair data) {

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
template <class T>
T List<T>::pop() {

	T data = front->data;
	Node<T>* tmp = front;
	front = front->next;
	size--;
	delete tmp;
	return data;
}
template <class T>
List<T>::~List() {

	while (front != nullptr)
		pop();
}
template <class T>
T& List<T>:: operator[](int index) const {

	Node<T>* curr = front;
	for (int i =0; i < index - 1; i++)
	{
		curr = curr->next;
	}
	return curr->data;
}
template <class T>
List<T>& List<T>::operator= (const List<T>& list) {

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
template <class T>
List<T> List<T>::operator * (List<T>& list) {

	List<T> new_list(max(size, list()), 0);
	for (int i = 0; i < min(size, list()); i++)
	{
		new_list[i] = (*this)[i] * list[i];
	}
	return new_list;
}
template <class T>
int List<T>::operator()() {

	return size;
}
template <class T>
void List<T>::output(Node<T>* n) const {

	cout << n->data << " ";
	if (n == back) {return;}
	output(n->next);
}
template <class T>
void List<T>::show() const {

	if (size == 0) cout << "List is empty " << endl;
	else output(front);
}
template <class T>
ostream& operator<< (ostream& out, const List<T>& l) {

	l.show();
	return out;
}
template <class T>
istream& operator>> (istream& in, List<T>& l) {

	T data;
	in >> data;
	l.push(data);
	return in;
}