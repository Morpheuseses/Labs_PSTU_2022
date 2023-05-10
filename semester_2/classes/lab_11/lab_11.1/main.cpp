#include <iostream>
#include <list>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include<ctime>
using namespace std;

typedef list<double> list_double;

list_double makeList(int s)
{
	
	list_double list;
	for (auto i = 0; i < s; i++)
	{
		double data = rand()%100+50;
		list.push_back(data);
	}
	return list;
}
double push_backAvrg(list_double& l)
{
	double summ = 0;
	for (auto i = l.begin(); i != l.end(); i++)
	{
		summ += *i;
	}
	double avrg = summ / l.size();
	l.push_back(avrg);
	return avrg;
}
void removeInrange(list_double& l, double one, double two)
{
	/*
	list_double::iterator i;
	for (i = l.begin(); i != l.end(); i++)
	{
		
	}*/
	list_double::iterator s = remove_if(l.begin(), l.end(), [=](double d){ return (d > one && d < two);});
	l.erase(s,l.end());
}
void addMinMax(list_double& list)
{
	double min = 1000000000;
	double max = -1;
	list_double::iterator i;
	for (i = list.begin(); i != list.end(); i++)
	{
		if (*i > max) max = *i;
		if (*i < min) min = *i;
	}
	for (i = list.begin(); i != list.end(); i++)
		*i += max + min;
}
std::ostream& operator<< (ostream& out,  list_double& list)
{
	list_double::iterator i;
	for ( i = list.begin(); i != list.end(); i++)
	{
		out << *i << ' ';
	}
	return out;
}

int main()
{
	srand(time(NULL));
	try
	{
		list_double l;
		list_double::iterator li = l.begin();
		int n;
		cout << "How much? "; 
		cin >> n;
		l = makeList(n);
		cout << l << endl;
		double k = push_backAvrg(l); if (k != *(--l.end())) throw 1;
		cout << "Push Back Average - " << l << endl;
		addMinMax(l);
		cout << "Add Min and Max to each element - " << l << endl;
		cout << "range of removing? " << endl;
		double one, two;
		cin >> one >> two;
		removeInrange(l,one,two);
		cout << "Delete all in range - " << l << endl;
	}
	catch (int)
	{
		cout << "\nError!";
	}
}