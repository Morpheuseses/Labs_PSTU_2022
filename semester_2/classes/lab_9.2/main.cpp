#include <iostream>
#include "list.h"
#include "error.h"
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
	catch (error &e)
	{
		e.what();
	}
	return 0;
}
