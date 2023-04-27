#include<iostream>
#include ".\student.h"

int main()
{
	Person p;
	cin >> p;
	cout <<"-----------------------------------------" << endl;
	cout << p;
	cout <<"-----------------------------------------" << endl;

	Student student;
	cin >> student; 
	cout <<"-----------------------------------------" << endl;
	cout << student;
	cout <<"-----------------------------------------" << endl;

	cout << student.getName() << endl;

	student.showBadMark();

	return 0;
}

