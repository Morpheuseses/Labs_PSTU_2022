#include <iostream>
#include "list.h"
using namespace std;

int main()
{
	try {	
		List x(2, 5);
		List y;
		cout << x;
		cout << "\nPosition? ";
		int p;
		cin >> p;
		cout << x[p] << endl;
		Node* n = x + 2;
		cout << x;
		x.pop();
		x.pop();
		cout << x;
		x.pop();
	}
	catch (int)
	{
		cout << "ERROR" << endl;
	}
	return 0;
}
