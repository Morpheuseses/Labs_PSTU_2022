#include<iostream>
#include ".\Prog.h"
using namespace std;

int main()
{
	Prog a;
	int j;
	cout << "Enter first element of sequence, constant division and power of it: ";
	cin >> a.first >> a.second >> j;
	cout << "Here your a_j element: " << a.element(j) << endl;
	return 0;
}