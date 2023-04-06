#include<iostream>
#include ".\Classes.h"
using namespace std; 

int main()
{
	Student student;
	cin >> student; 
	cout << student;

	student.showBadMark();

	return 0;
}

