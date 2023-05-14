#include "pair.h"
#include <list>
#include <algorithm>
#include <iostream>

typedef list<Pair>  l_Pair; 

l_Pair makeList(int n)
{
	Pair p;
	l_Pair l;
	for (auto i = 0; i < n; i++)
	{
		std::cin >> p;
		l.push_back(p);
	}
	return l;
}

void printList(l_Pair l)
{
	auto it = l.begin();
	for (it; it != l.end(); it++)
	{
		std::cout << (*it) << ' ';
	}
	std::cout << endl;
}
void arithmetic_mean(l_Pair& l)
{
	Pair sum;
	for_each(l.begin(), l.end(), [&](Pair p) { sum += p; });
	l.push_back(sum / l.size());
}
void removeInrange(l_Pair l, Pair p)
{
	auto it = remove(l.begin(),l.end(), p);
	l.erase(it, l.end());
}
void MinMax_addition(l_Pair l)
{
	Pair max = *max_element(l.begin(),l.end());
	Pair min = *min_element(l.begin(), l.end());
	for_each(l.begin(), l.end(), [&](Pair& p) {p += max; p += min; });
}
int main()
{
	l_Pair l;
	std::cout << "How much? ";
	int n; 
	std::cin >> n;
	l = makeList(n);
	printList(l);
	std::cout << "After push average " << std::endl;
	arithmetic_mean(l);
	printList(l);

	std::cout << "element?"; 
	Pair p;
	std::cin >> p;
	removeInrange(l,p);
	std::cout << "After removing elements " << std::endl;
	printList(l);

	MinMax_addition(l);
	std::cout << "After min and max element addition" << std::endl;
	printList(l);

	return 0;
}