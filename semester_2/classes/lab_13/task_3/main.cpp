#include <iostream>
#include "pair.h"
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

typedef std::multimap<int, Pair> tmap;

tmap make_map(int n)
{
	tmap m;
	Pair p;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		m.insert(make_pair(i,p));
	}
	return m;
}
void print_map(tmap m)
{
	for (auto i : m)
	{
		cout << i.first << ':' << i.second << endl;
	}
}
struct arithmetic_mean
{
private:
	int n{ 0 };
	Pair sum;
public:
	void operator() (pair<int, Pair> p)
	{
		++n;
		sum += p.second;
	}
	Pair get_result() { return sum / n; }
};

struct del
{
	vector<int> to_del;
	int n{0};

	void operator() (pair<int, Pair> p)
	{
		if (f < p.second && p.second < s)
			to_del.push_back(p.first);
			n++;
	}
};

Pair f, s;
int main()
{
	int n; 
	cout << "N? ";
	cin >> n;
	tmap m = make_map(n);
	print_map(m);
	cout << "Key? ";
	cin >> n;
	arithmetic_mean mn = for_each(m.begin(),m.end(), arithmetic_mean());
	Pair res = mn.get_result();
	m.insert(make_pair(n,res));
	print_map(m);
	
	Pair f, s;
	cin >> f; 
	cin >> s;
	del d = for_each(m.begin(), m.end(),del());
	for (int i = 0; i < d.n; i++)
	{
		m.erase(d.to_del[i]);
	}
	print_map(m);
	
	Pair max = (*max_element(m.begin(), m.end())).second;
	Pair min = (*min_element(m.begin(), m.end())).second;

	for_each(m.begin(), m.end(),
		[&max, &min](pair<int, Pair> p)
		{
			p.second += max;
			p.second += min;

		});
	print_map(m);
}