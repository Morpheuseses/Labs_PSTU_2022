
#include "payment.h"
#include<iostream>
#include<string>
using namespace std;

payment::payment() 
{

	fullName = "None";
	salary = 0;
	bonus = 0;
}
payment::payment(string fullName, double salary, int bonus)
{
	this->fullName = fullName;
	this->salary = salary;
	this->bonus = bonus;
}
payment::payment(const payment& p)
{
	fullName = p.fullName;
	salary = p.salary;
	bonus = p.bonus;
}
string payment::getName()
{
	return fullName;
}
double payment::getSalary()
{
	return salary;
}
int payment::getBonus()
{
    return bonus;
}
void payment::setName(string n)
{
    fullName = n;
}
void payment::setSalary(double s)
{
    salary = s;
}
void payment::setBonus(int b)
{
    bonus = b;
}
void payment::show()
{
    cout << "Full name - " << fullName << endl;
    cout << "Salary - " << salary << endl;
    cout << "Bonus - " << bonus << endl;
}