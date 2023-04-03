#include<iostream>
using namespace std;

class payment
{
	string fullName;
	double salary;
	int bonus;
public:
	payment()
	{
		fullName = "None";
		salary = 0;
		bonus = 0;
	}
	payment(string fullName, double salary, int bonus)
	{
		this->fullName = fullName;
		this->salary = salary;
		this->bonus = bonus;
	}
	payment(const payment& p)
	{
		fullName = p.fullName;
		salary = p.salary;
		bonus = p.bonus;
	}
	~payment(){}
	//selectors(getters)
	string getName()
	{
		return this->fullName;
	}
	double getSalary()
	{
		return this->salary;
	}
	int getBonus()
	{
		return this->bonus;
	}
	//modifiers(setters)
	void setName(string fullName)
	{
		this->fullName = fullName;
	}
	void setSalary(double salary)
	{
		this->salary = salary;
	}
	void setBonus(int bonus)
	{
		this->bonus = bonus;
	}
};

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