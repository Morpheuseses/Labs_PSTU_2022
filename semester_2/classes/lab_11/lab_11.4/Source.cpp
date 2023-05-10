#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
#include "pair.h"
#include <cstdlib>
#include "Windows.h"

typedef std::priority_queue<Pair> pri_queue;
typedef std::list<Pair> list_Pair;

pri_queue make_queue(int n)
{
	pri_queue q;
	Pair p;
	for (int i = 0; i < n; i++)
	{
		cout << "next data?";  cin >> p;                                                                                                                                            
		q.push(p);
	}
	return q;
}
list_Pair copy_queue_to_list(pri_queue q)
{
	list_Pair l;
	while (!q.empty())
	{
		l.push_back(q.top());
		q.pop();
	}
	return l;
}
pri_queue copy_list_to_queue(list_Pair l)
{
	pri_queue q;
	while (!l.empty())
	{
		q.push(l.front());
		l.pop_front(); 
	}
	return q;
}
Pair average(pri_queue &q)
{
	list_Pair l = copy_queue_to_list(q);
	int n = 0;
	Pair avg = q.top();
	q.pop();
	while (!q.empty())
	{
		n++;
		avg += q.top();
		q.pop();
	}
	q = copy_list_to_queue(l);
	return avg / n;
}
pri_queue removeInrange(pri_queue q, int begin, int end)
{
	pri_queue tmp;
	Pair p;
	int n = 1;
	for (n; n <= begin; n++)
	{
		p = q.top();
		q.pop();
		tmp.push(p);
	}
	for (n; n <= end; n++)
	{
		q.pop();
	}
	for (n; n <= q.size(); n++)
	{
		p = q.top();
		q.pop();
		tmp.push(p);
	}
	return tmp;
}
std::ostream& operator << (std::ostream& out, pri_queue q)
{
	out << "Front <- \n";
	while (!q.empty())
	{
		out << q.top()<< " <- \n";
		q.pop();
	}
	out << " <- end";
	return out;
}
pri_queue add_average(pri_queue q)
{
	q.push(average(q));
	return q;
}
pri_queue minmaxAddition(pri_queue q)
{
	list_Pair l = copy_queue_to_list(q);
	Pair min_p(1000000, 1000000);
	Pair max_p(0, 0);
	while (!l.empty())
	{
		if (l.front() > max_p) max_p = l.front();
		else if (l.front() < min_p) min_p = l.front();
		l.pop_front();
	}
	l = copy_queue_to_list(q);
	for_each(l.begin(), l.end(), [&](Pair& p) {p += min_p; p += max_p; });
	return copy_list_to_queue(l);
}
int main()
{
	Pair p;
	pri_queue q;
	int n;
	std::cout << "How much?"; std::cin >> n;
	q = make_queue(n);
	std::cout << q << std::endl;
	q = add_average(q);
	std::cout << "After average push " << std::endl;
	std::cout << q << std::endl;
	int begin, end;
	std::cout << "begin?";
	std::cin >> begin;
	std::cout << "end?";
	std::cin >> end;
	q = removeInrange(q, begin, end);
	std::cout << "After elements in range were removed " << std::endl;
	std::cout << q << std::endl;
	std::cout << "After min and max elements addition" << std::endl;
	q = minmaxAddition(q);
	std::cout << q << std::endl;
	return 0;
}