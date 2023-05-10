#include "list.h"
#include "pair.h"
#include <iostream>


int main()
{
	std::cout << "How much? "; int n;  std::cin >> n;
	List<Pair> l;
	for (int i = 0; i < n; i++)
	{
		Pair data;
		data.randomize();
		l.push(data);
	}
	std::cout << l << std::endl;
	std::cout << l.Avrg() << std::endl;
	l.push(l.Avrg());
	std::cout << "After push average" << std::endl;
	std::cout << l << std::endl;
	cout << "range?"; Pair p1, p2;
	std::cin >> p1 >> p2;
	List<Pair> tmp;
	for (int i = 0; i < l(); i++)
	{
		if (!(l[i] > p1 && l[i] < p2)) tmp.push(l[i]);
	}
	l = tmp;
	std::cout << "Remove in range" << std::endl;
	std::cout << l << std::endl;
	std::cout << "Minmax addition" << std::endl;
	Pair max = l.Max();
	Pair min = l.Min();
	for (int i = 0; i < l(); i++)
	{
		l[i] += min;
		l[i] += max;
	}
	cout << l << endl;
	return 0;
}