#include "pair.h"
#include <list>
#include <algorithm>
#include <iostream>

typedef list<Pair> list_Pair;


list_Pair makeList(int s)
{
	list_Pair list;
	for (auto i = 0; i < s; i++)
	{
		Pair data;
		data.randomize();
		list.push_back(data);
	}
	return list;
}
Pair push_backAvrg(list_Pair& l)
{
	Pair summ;
	for_each(l.begin(), l.end(), [&summ](Pair& p) {summ += p;});
	Pair avrg;
	avrg.setFirst(summ.getFirst() / l.size());
	avrg.setSecond(summ.getSecond() / l.size());
	l.push_back(avrg);
	return avrg;
}
void removeInrange(list_Pair l, Pair p1, Pair p2)
{
	list_Pair::iterator s = remove_if(l.begin(), l.end(), [=](Pair& p) {return p > p1 && p < p2; });
	l.erase(s, l.end());
}
void addMinMax(list_Pair& l)
{
	Pair min(100000, 1000000);
	Pair max(0, 0);
	list_Pair::iterator i;
	for (i = l.begin(); i != l.end(); i++)
	{
		if (*i > max) max = *i; else if (*i < min) min = *i;
	}
	for (i = l.begin(); i != l.end(); i++)
	{
		*i += max;
		*i += min;
	}
}
std::ostream& operator<< (ostream& out, list_Pair& l)
{
	for_each(l.begin(), l.end(), [&](Pair& p) {out << p << ' '; });
	return out;
}

int main()
{
	srand(time(NULL));
	try
	{
		list_Pair l;
		list_Pair::iterator li = l.begin();
		int n;
		cout << "How much? ";
		cin >> n;
		l = makeList(n);
		cout << l << endl;
		Pair k = push_backAvrg(l); if (k != *(--l.end())) throw 1;
		cout << "Push Back Average - \n" << l << endl;
		cout << "range? "; 
		Pair p1, p2;
		cin >> p1 >> p2;
		removeInrange(l, p1, p2);
		cout << "Remove elements in range - \n" << l << endl;
		addMinMax(l);
		cout << "Add Min and Max to each element - \n" << l << endl;
	}
	catch (int)
	{
		cout << "\nError!";
	}
}