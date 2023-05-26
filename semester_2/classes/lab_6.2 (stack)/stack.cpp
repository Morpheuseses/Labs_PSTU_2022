#pragma once
#include <iostream>
#include "stack.h"

Stack::Stack()
{
    head = nullptr;
    size = 0;
}
Stack::Stack(int n, int data)
{
    head = new Node;
    head->data = data;
    Node* prev = head;
    for (int  i = 0; i < n; i++)
    {
        head = new Node;
        head->data = data;
        head->next = prev;
        prev = head;
    }
    size = n;
}
Stack::Stack(const Stack& s)
{
    head = s.head;
    size = s.size;
}
void Stack::push(int data)
{
    Node* tmp = new Node;
	tmp->data = data;
	tmp->next = head;
	head = tmp;
	size++;
}
int Stack::pop()
{
    int data = head->data;
    head = head->next;
    size--;
    return data;
}
void Stack::add(int data, int pos)
{
    Stack* tmp = new Stack;
	
	int init_size = size; // size of element after it was initialized 
	for (int i = 1; i <= init_size - pos + 1; i++)
	{
		tmp->push(head->data);
		pop();
	}
	push(data);
	init_size = tmp->size; // size of tmp stack after it was initialized 
	for (int i = 1; i <= init_size; i++)
	{
		push(tmp->head->data);
		tmp->pop();
	}
	delete tmp;
}
int Stack::del(int pos)
{
    int data;
    Stack* tmp = new Stack;
	int init_size = size;
	for (int i = 1; i <= init_size - pos + 1; i++)
	{
		tmp->push(head->data);
		pop();
	}
    data = tmp->head->data;
	tmp->pop();
	init_size = tmp->size;
	for (int i = 1; i <= init_size; i++)
	{
		push(tmp->head->data);
		tmp->pop();
	}
	delete tmp;
    return data;
}
int Stack::searchElem(int value)
{
    int i = size;
	Stack* curr = new Stack;
    while (head != nullptr)
    {
        if (head->data == value)
        {
            return i;
        }
    }
    return -1;
}
Stack& Stack::operator= (Stack& s)
{
    Stack* tmp = new Stack;
    Node* curr = s.head;
    for (int i = 0; i < s.size && curr != nullptr; i++)
    {
        tmp->push(curr->data);
        curr = curr->next;
    }
    Stack* tmp2 = new Stack;
    int tmp_size = tmp->size;
    for (int i = 0; i< tmp_size; i++)
    {
        tmp2->push(tmp->head->data);
        tmp->pop();
    }
    return *tmp2;
}
std::ostream& operator<< (std::ostream& out, const Stack s)
{
    if (s.size == 0) {std::cout << "Stack is empty" << std::endl; return out;}
    Node* curr = s.head;
    out << "Top-> ";
    for (int i =0; i < s.size; i++)
    {
        out << curr->getData() << " ";
        curr = curr->getNode();
    }
    out << "-> Bottom\n";
    return out;
}