#include<iostream>
#include "vec.h"
#include ".\student.h"
using namespace std;

int main()
{
	Vector v(5);

	Person p;
	cin >> p;
	Student s;
	cin >> s;
	s.showBadMark();
	Object *ptr = &p;
	v.Add(ptr);
	ptr = &s;
	v.Add(ptr);
	cout << v;

	return 0;
}