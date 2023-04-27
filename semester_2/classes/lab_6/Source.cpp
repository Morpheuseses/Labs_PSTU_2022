#include<iostream>
#include "list.h"
using namespace std;

int main()
{
	List l(5, 0);
	Iterator* it = l.first();
	cout << *(*it) << endl;
	cout << l << endl;
	Iterator* i = l.first();
	i++;
	cout << *(*i) << endl;
	for (i = l.first(); i != l.last(); i++) cout << *(*i) << endl;
	return 0;
}