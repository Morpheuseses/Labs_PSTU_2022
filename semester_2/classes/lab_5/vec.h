#pragma once
#include "object.h"
#include<iostream>
using namespace std;

class Vector {
private:
	Object** beg;
	int size;
	int cur;
public:
	Vector(void);
	Vector(int );
public:
	~Vector(void);
	void Add(Object *);
	friend ostream& operator<< (ostream& out, const Vector&);
};

