#include<iostream>
#include ".\Prog.h"
using namespace std;

int main()
{
	Prog a;

	cout << "Enter first element of sequence and constant division" << endl;
	a.Read(); 
	cout << "Enter number of element, you want" << " ";
	int j;
	cin >> j;
	a.Show();
	cout << "Here your a_j element: " << a.element(j) << endl;
	return 0;
}