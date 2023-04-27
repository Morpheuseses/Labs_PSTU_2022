#include<string>
using namespace std;

class Person
{
protected:
	string fullName;
	int age;
public:
	Person()
	{
		fullName = "none";
		age = 0;
	}
	Person(string name, int age)
	{
		this->fullName = name;
		this->age = age;
	}
	Person(const Person& p)
	{
		fullName = p.fullName;
		age = p.age;
	}
	~Person(){}
	string getName()
	{
		return fullName;
	}
	int getAge()
	{
		return age;
	}
	void setName(string name)
	{
		this->fullName = name;
	}
	void setAge(int age)
	{
		this->age = age;
	}
	Person& operator=(const Person& p)
	{
		fullName = p.fullName;
		age = p.age;
		return *this;
	}
	friend istream& operator>>(istream& in, Person& p)
	{
		cout << "Name? "; cin >> p.fullName;
		cout << "Age? "; cin >> p.age;
		return in;
	}
	friend ostream& operator<<(ostream& out, const Person& p)
	{
		out << "Person name: " << p.fullName << endl;
		out << "Person age: " << p.age << endl;
		return out;
	}
};