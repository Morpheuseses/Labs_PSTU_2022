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
	~Pair() {}
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
	Pair& operator= (const Pair& p)
	{
		this->first = p.first;
		this->second = p.second;
		return *this;
	}
	Pair& operator- (const Pair& p)
	{
		first -= p.first;
		second -= p.second;
		return *this;
	}
	Pair& operator+ (int x)
	{
		first += x;
		return *this;
	}
	Pair& operator+ (double x)
	{
		second += x;
		return *this;
	}
	friend ostream& operator<< (ostream& out, const Pair& p)
	{
		return (out << p.first << " : " << p.second << endl);
	}
	friend istream& operator>> (istream& in, const Pair& p)
	{
		int first; double second;
		cout << "first?"; in >> first;
		cout << "second?"; in >> second;
		return in;
	}
};


int main()
{
	Pair p;
	Pair p1(4, 9.0);
	Pair p2(p);
	cout << p << endl;
	cout << p1 << endl;
	cout << p2 << endl;
	p = p1;
	cout << p << endl;
	p = p1 - p2;
	cout << p << endl;

	cin >> p;
	cout << p << endl;

}