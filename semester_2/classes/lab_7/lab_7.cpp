#include<iostream>
#include "list.h"
#include "pair.h"
using namespace std;

int main()
{
	Pair pair(5,1.0);
	List<Pair> l(5, pair);
	cout << l << endl;
	cout << l[0] << endl;
	cout << l() << endl;
	List<Pair> l1(5,pair);
	List<Pair> l_new = l * l1;
	cout << l_new << endl;
	return 0;
}