#include <set>
#include <algorithm>
#include <iostream>
#include "set.h"
#include "pair.h"

int main()
{
	Set<Pair> set;
	cout << "How much?";
	int n; 
	cin >> n;
	set.make_set(n);
	set.print_set();
	return 0;
}