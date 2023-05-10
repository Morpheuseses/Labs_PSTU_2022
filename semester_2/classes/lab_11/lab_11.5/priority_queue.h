#pragma once
#include <iostream>
#include <list>
#include <queue>

template <class T>
class List
{
private:
	std::priority_queue<T> q;
	int size;
public:
	List() { size = 0; }
	~List() {};
	List(int n);
	void print_list();
	void delete_elem(int, int);
	int size() { return size; }
	void min_max_addition();
	void push_average();
};

template<class T>
List<T>::List(int n)
{
	T data;
	for (auto i = 0; i < n; i++)
	{
		std::cout << "\nnext data?" << std::endl;
		std::cin >> data;
		this->q.push(data);
	}
	size = n;
}
template<class T>
void List<T>::print_list()
{
	std::priority_queue<T> tmp(this->q);
	while (!tmp.empty())
	{
		std::cout << tmp.top() << std::endl;
		tmp.pop();
	}
}
template<class T>
void List<T>::push_average()
{
	std::priority_queue<T> tmp(q);
	T arvg = 0;
	while (!tmp.empty())
	{
		arvg = avrg + tmp.top();
		tmp.pop();
	}
	q.push(avrg / q.size());
	size = q.size();
}
template<class T>
void List<T>::delete_elem(int begin, int end)
{
	std::priority_queue<T> tmp;
	T t;
	int n = 1;
	int z = q.size();
	for (n; n <= begin; n++)
	{
		t = q.top();
		q.pop();
		tmp.push(t);
	}
	for (n; n <= end; n++)
	{
		q.pop();
	}
	for (n; n <= z; n++)
	{
		t = q.top();
		q.pop();
		tmp.push(t);
	}
	q = tmp;
}
template<class T>
void List<T>::min_max_addition()
{
	T min = q.top(); T max = 0;
	std::priority_queue<T> tmp(q);
	while (!tmp.empty())
	{
		if (tmp.top() < min)
		{
			min = tmp.top();
		}
		else if (tmp.top() > max)
		{
			max = tmp.top();
		}
		tmp.pop();
	}
	tmp.swap(q);
	T data;
	while (!tmp.empty())
	{
		data = tmp.top();
		data += min;
		data += max;
		q.push(data);
		tmp.pop();
	}
}