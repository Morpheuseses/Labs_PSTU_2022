#pragma once 
#include<string>
using namespace std;

class payment
{
	string fullName;
	double salary;
	int bonus;
public:
	payment();
	payment(string fullName, double salary, int bonus);
	payment(const payment& p);
	~payment(){}
	//selectors(getters)
	string getName();
	
	double getSalary();
	
	int getBonus();
	//modifiers(setters)
	void setName(string n);
	void setSalary(double salary);
	void setBonus(int bonus);
	void show();
};
