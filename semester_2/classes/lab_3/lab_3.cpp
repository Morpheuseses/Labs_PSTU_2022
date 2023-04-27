#include<iostream>
#include ".\pair.h"
using namespace std; 

int main()
{
	Pair p;
	Pair p2;
	cin>>p;
	cin>>p2;

	cout << p << endl << endl;
	cout << p2 << endl;
	p2 = p+1;
	cout << p2 + 1 << endl;
	cout << p2 - p << endl;
	return 0;
}