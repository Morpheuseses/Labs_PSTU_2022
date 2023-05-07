#pragma once
#include "pair.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream) return -1;
	int n;
	Pair p;
	cout << "n?"; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		stream << p << '\n';
	}
	stream.close();
	return n;
}
int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p; int i = 0;
	while (stream >> p)
	{
		cout << p << '\n';
		i++;
	}
	stream.close();
	return i;
}
int del_file(const char* f_name, int k)
{
	fstream tmp("tmp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	int i = 0; Pair p;
	while (stream >> p)
	{
		if (stream.eof()) break;
		i++;
		if (i != k) tmp << p;
	}
	stream.close(); tmp.close();
	remove(f_name);
	rename("tmp", f_name);
	return i;
}
int add_file(const char* f_name, int k, Pair pp)
{
	fstream tmp("tmp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p; int i = 0, l = 0;
	while (stream >> p)
	{
		if (stream.eof()) break;
		i++;
		if (i == k)
		{
			tmp << pp;
			l++;
		}
		tmp << p;
	}
	stream.close(); tmp.close();
	remove(f_name);
	rename("tmp",f_name);
	return l;
}
int add_end(const char* f_name, Pair p)
{
	fstream stream(f_name, ios::app);
	if (!stream) return -1;
	stream << p;
	return 1;
}
int change_file(const char* f_name, int k, Pair pp)
{
	fstream tmp("tmp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)return -1;
	Pair p; 
	int i = 0, l = 0;
	char x;
	while (stream >> p)
	{
		if (stream.eof())break;
		i++;
		if (i == k)
		{
			cout << p << " - is changing...Continue?[Y/n]\n";
			cin >> x;
			if (x == 'n' || x == 'N')break;
			tmp << pp;
			l++;
		}
		else tmp << p;
	}
	stream.close(); tmp.close();
	remove(f_name);
	rename("tmp", f_name);
	return l;
}
int delete_lessThan(const char* f_name, Pair pp)
{
	fstream tmp("tmp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p;
	int i = 0, l = 0;
	while (stream >> p)
	{
		if (stream.eof()) break;
		i++;
		if (p.getFirst() < pp.getFirst() && p.getSecond() < pp.getSecond())
		{
			l++;
		}
		else tmp << p;
	}
	stream.close(); tmp.close();
	remove(f_name);
	rename("tmp", f_name);
	return l; // count of removed elements
}
int addConst(const char* f_name, int l)
{
	fstream tmp("tmp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p;
	int i = 0, n = 0;
	while (stream >> p)
	{
		if (stream.eof()) break;
		i++;
		try {
			p.setFirst(p.getFirst() + l);
			p.setSecond(p.getSecond() + l);
			tmp << p;
			n++;
		}
		catch (exception& ex)
		{
			cout << ex.what() << endl;
		}
		
	}
	stream.close(); tmp.close();
	remove(f_name);
	rename("tmp", f_name);
	return n;
}
int addRecords(const char* f_name, int q, int pos)
{
	int k; Pair p;
	for (auto i = 0; i < q; i++)
	{
		cout << "Next pair ";
		cin >> p;
		k = add_file(f_name, pos + i, p);
		if (k < 0) { cout << "Can't read file"; return -1; }
		if (k == 0) { add_end(f_name, p); }
	}
}
