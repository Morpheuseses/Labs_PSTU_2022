#pragma once 
#include <ostream>

class Node 
{
    friend class Stack;
private:
    Node* next= nullptr;
    int data = 0;
public:
    void setData(int data) {this->data = data;}
    int getData() {return data;}
    Node* getNode(){ return next;}

};

class Stack
{

private:
    Node* head;
    int size;
public:
    Stack();
    Stack(int n, int data);
    Stack(const Stack&);
    ~Stack(){while (size > 0) pop();}
    void push(int);
    void add(int data, int pos);
    int pop();
    int del(int);
    int searchElem(int );
    Stack& operator= (Stack& s);
    friend std::ostream& operator<< (std::ostream& out, const Stack s);
};