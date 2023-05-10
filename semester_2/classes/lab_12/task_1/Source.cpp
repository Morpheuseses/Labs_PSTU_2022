#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

typedef multiset<double> ms;
typedef multiset<double>::iterator ms_it;

ms make_set(int n)
{
	ms tmp;
	double data;
	for (auto i = 0; i < n; i++)
	{
		cout << "data?";
		cin >> data;
		tmp.insert(data);
	}
	return tmp;
}
void print_set(ms set)
{
	for (auto& i : set)
	{
		cout << i << " ";
	}
	cout << '\n';
}
void push_average(ms &set)
{
	double avrg = 0;
	int size = 0;
	for (auto& i : set)
	{
		avrg += i;
		size++;
	}
	set.insert(avrg / size);
}
ms removeInrange(ms set, double begin, double end)
{
	auto left = set.lower_bound(begin);
	auto right = set.upper_bound(end);
	set.erase(left, right);
	return set;
}
ms min_max_addition(ms set)
{
	double min = 1000000, max = 0;
	for (auto& i : set)
	{
		if (min > i)
		{
			min = i;
		}
		else if (max < i)
		{
			max = i;
		}
	}
	ms tmp;
	for (auto& i : set)
	{
		tmp.insert(i + max + min);
	}
	set.swap(tmp);
	return set;
}
int main()
{
	ms set;
	cout << "How much?";
	int n;
	cin >> n;
	set = make_set(n);
	print_set(set);
	cout << "After push average";
	push_average(set);
	print_set(set);
	cout << "After removing elements in range";
	cout << "Set range "; double begin, end;
	cin >> begin >> end;
	set = removeInrange(set, begin, end);
	print_set(set);
	cout << "After min and max addition " << endl;
	set = min_max_addition(set);
	print_set(set);
	return 0;
}
