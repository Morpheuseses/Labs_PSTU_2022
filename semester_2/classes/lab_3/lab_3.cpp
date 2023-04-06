#include<iostream>
#include ".\pair.h"
using namespace std; 



int main()
{
	Pair p;
	Pair p1(4,9.0);
	Pair p2(p);
	cout << "There is first constructor(without parameters)\n" << p << endl;
	cout << "There is second constroctor p1(4,9.0)\n" << p1 << endl;
	cout << "There is copy constructor p2(p)\n" << p2 << endl;
	p = p1;
	cout << "This is how '=' operation works\n" << p1 << endl;
	cout << "This is how output works\n " << p << endl;
	cin >> p;
	cout << "This is how input works\n" << p << endl;
	cout << "This is how addition works\n" << p + 1 << '\n' << p + 1.5 << endl;
	cout << "This is how subtraction works\n" << p1 - 2 << endl;
}