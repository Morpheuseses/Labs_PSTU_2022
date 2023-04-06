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
	
	friend istream& operator>>(istream& in, Person& p)
	{
		cout << "Name? "; cin >> p.fullName;
		cout << "Age? "; cin >> p.age;
		return in;
	}
	friend ostream operator<<(ostream& out, const Person& p)
	{
		cout << "Name: " << p.fullName << endl;
		cout << "Age: " << p.age << endl;
		return out;
	}
};
class Student : public Person
{
protected:
	string subject;
	int mark;
public:
	Student()
	{
		subject = "none";
		int mark = - 1;
	}
	Student(string sub, int mark)
	{
		this->subject = sub;
		this->mark = mark;
	}
	Student(const Student& stud)
	{
		this->subject = stud.fullName;
		this->mark = stud.mark;
	}
	~Student(){}
	void setSubject(string sub)
	{
		subject = sub;
	}
	void setMark(int m)
	{
		mark = m;
	}
	string getSubject()
	{
		return subject;
	}
	int getMark()
	{
		return mark;
	}
	friend istream& operator>>(istream& in, Person& p)
	{
		cout << "Name? "; cin >> p.fullName;
		cout << "Age? "; cin >> p.age;
		cout << "Subject? "; cin >> p.subject;
		cout << "Mark? "; cin >> p.mark;
		return in;
	}
	friend ostream operator<<(ostream& out, Person& p)
	{
		cout << "Name: " << p.fullName << endl;
		cout << "Age: " << p.age << endl;
		cout << "Subject: " << p.subject << endl;
		cout << "Mark: " << p.mark << endl;
		return out;
	}
	void showBadMark()
	{
		if (mark < 4 && mark != -1)
			cout << this->fullName << ", disguisting, how you dare. Your mark is " << mark << endl;
	}
};