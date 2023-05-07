#include<iostream>
#include "list.h"
using namespace std;

int main()
{
	List l(5, 5);
	l.push(4);
	Iterator it = l.first();
	cout << l << endl;
	Iterator i = l.first();
	i++;
	cout << *i << endl;
	for (i = l.first(); i != l.last(); i++) cout << *i << ' ';
	List l1(5,5);
	cout << '\n' << l * l1 << endl;
	return 0;
}