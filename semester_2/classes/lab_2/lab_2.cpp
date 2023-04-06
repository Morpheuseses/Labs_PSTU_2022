#include<iostream>
#include ".\payment.h"
using namespace std;


int main()
{
	cout << "First constructor: " << endl;
	payment p;
	cout << p.getName() << endl;
	cout << p.getSalary() << endl;
	cout << p.getBonus() << endl << endl;
	p.setName("Sasha");
	p.setSalary(40000);
	p.setBonus(4000);
	cout << "Second constructor: " << endl;
	payment* p2 = new payment("Leha", 30000, 4000);
	cout << "This guy called "<< p2->getName() <<" has a salary, which equal to "<< p2->getSalary() << ", and he got a bonus, which is " << p2->getBonus() << endl << endl;
	payment p3(p);
	cout << "And the third constructor(copy): " << endl;
	cout << p.getName() << endl;
	cout << p.getSalary() << endl;
	cout << p.getBonus() << endl << endl;
	return 0;
}