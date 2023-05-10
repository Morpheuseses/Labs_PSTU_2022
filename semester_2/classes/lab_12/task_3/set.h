#pragma once
#include <set>
#include<algorithm>
#include <iostream>
using namespace std;

template <typename T>
class Set
{
private:
	int size = 0;
	multiset<T> set;
public:
	Set() { size = set.size(); }
	void make_set(int n);
	void print_set();
	void average();
	void removeInrange(T begin, T end);
	void min_max_addition();
	int size() { return size; }
};

template<typename T>
void Set<T>::make_set(int n)
{
	for (int i = 0; i < n; i++)
	{
		T data;
		cout << "next data?";
		cin >> data;
		set.insert(data);
	}
}
template<typename T>
void Set<T>::print_set()
{
	for (auto& i : set)
	{
		cout << i << ' ';
	}
	cout << endl;
}
template<typename T>
void Set<T>::average()
{
	T avrg;
	for (auto& i : set)
	{
		avrg = avrg + i;
	}
	set.insert(avrg)
	size++;
}
template<typename T>
void Set<T>::removeInrange(T begin, T end)
{
	auto left = set.lower_bound(begin);
	auto right = set.upper_bound(end);
	set.erase(left, right);
	size = set.size();
}
template<typename T>
void Set<T>::min_max_addition()
{
	multiset<T> tmp;
	T min = *set.begin(), max = *set.end();
	for (auto& i : set)
	{
		if (i < min)
		{
			min = i;
		}
		else if (i > max)
		{
			max = i;
		}	
	}
	for (auto& i : set)
	{
		tmp.insert(i + min + max);
	}
	tmp.swap(set);
}