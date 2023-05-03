#pragma once 
#include <ostream>

class Node 
{
    friend class Stack;
private:
    Node* next= nullptr;
    int data = 0;
};

class Stack
{

private:
    Node* head;
    int size;
public:
    Stack();
    Stack(int, int);
    Stack(const Stack&);
    ~Stack();
    void push(int);
    void add(int data, int pos);
    int pop();
    int del(int);
    int searchElem(int );
    Stack& operator= (Stack& s);
    friend std::ostream& operator<< (std::ostream& out, const Stack s);
};