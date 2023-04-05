#include<iostream>
using namespace std; 


class Pair
{
public:
	int first;
	double second;

	Pair()
	{
		first = 0;
		second = 0; 
	}
	Pair(int f, double s)
	{
		first = f;
		second = s;
	}
	Pair(const Pair& p)
	{
		first = p.first;
		second = p.second;
	}
	~Pair(){}
	void setFirst(int first)
	{
		this->first = first;
	}
	void setSecond(double second)
	{
		this->second = second;
	}
	int getFirst()
	{
		return first;
	}
	double getSecond()
	{
		return second;
	}
	Pair operator= (const Pair& p)
	{
		this->first = p.first;
		this->second = p.second;
	}
	Pair& operator- (const Pair& p)
	{
		first -= p.getFirst();
		second -= p.getSecond();
		return this;
	}
	Pair& operator+ (int x)
	{
		first +=x;
		return *this;
	}
	Pair& operator+ (double x)
	{
		second +=x;
		return *this;
	}
};
ostream& operator<< (ostream& out, const Pair& p)
{
	return (out << p.getFirst() << " : "<<  p.getSecond() << endl;)
}
istream& operator>> (istream& in, const Pair& p)
{
	int first; double second;
	cout << "first?"; in >> first;
	cout << "second?"; in >> second;
	return in; 
}

int main()
{
	Pair p;
	Pair p1(4,9.0);
	Pair p2(p);
	cout << "There is first constructor(without parameters)\n" << p << endl;
	cout << "There is second constroctor p1(4,9.0)\n" << p1 << endl;
	cout << "There is copy constructor p2(p)\n" << p2 << endl;
	p = p1;
	cout << "This is how '=' operation works\n" << p1 << endl;
	cout << "This is how output works\n " << p << endl;
	cin >> p;
	cout << "This is how input works\n" << p << endl;
	cout << "This is how addition works\n" << p + 1 << '\n' << p + 1.5 << endl;
	cout << "This is how subtraction works\n" << p1 - 2 << endl;
}