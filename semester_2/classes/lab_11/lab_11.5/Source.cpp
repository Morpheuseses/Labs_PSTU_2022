#include <iostream>
#include <cstdlib>
#include "priority_queue.h"
#include "pair.h"
using namespace std;

int main()
{
	List<Pair> l(4);
	l.print_list();
	cout << "After push average" << endl;
	l.push_average();
	l.print_list();
	cout << "After delete in range" << endl;
	int begin, end;
	cout << "begin?"; cin >> begin;
	cout << "end?"; cin >> end;
	l.delete_elem(begin, end);
	l.print_list();
	cout << "After min and max element addition" << endl;
	l.min_max_addition();
	l.print_list();
	return 0;
}