#include<iostream>
#include "list.h"
#include "pair.h"
using namespace std;

int main()
{
	Pair pair(5,1.0);
	List<Pair> l(5, pair);

	return 0;
}