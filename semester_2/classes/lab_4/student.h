#include ".\person.h"

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
	friend istream& operator>>(istream& in, Student& s)
	{
		cout << "Name? "; cin >> s.fullName;
		cout << "Age? "; cin >> s.age;
		cout << "Subject? "; cin >> s.subject;
		cout << "Mark? "; cin >> s.mark;
		return in;
	}
	friend ostream& operator<<(ostream& out, const Student& s)
	{
		out << "Student's Name:" << s.fullName << endl;
		out << "Student's age: " << s.age << endl;
		out << "Student's subject: " << s.subject << endl;
		out << "Student's mark: " << s.mark << endl;
		return out;

	}
	void showBadMark()
	{
		if (mark < 4 && mark != -1)
			cout << this->fullName << ", disguisting, how you dare. Your mark is " << mark << endl;
	}
};