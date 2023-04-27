#include<iostream>
#include "pair.h"
using namespace std;

Pair::Pair()
{
	first = 0;
	second = 0; 
}
Pair::Pair(int f, double s)
{
	first = f;
	second = s;
}
Pair::Pair(const Pair& p)
{
	first = p.first;
	second = p.second;
}
void Pair::setFirst(int first)
{
    this->first = first;
}
void Pair::setSecond(double second)
{
    this->second = second;
}
int Pair::getFirst()
{
	return first;
}
double Pair::getSecond()
{
	return second;
}
Pair& Pair::operator= (const Pair& p)
{
	this->first = p.first;
	this->second = p.second;
    return *this;
}
Pair& Pair::operator- (const Pair& p)
{
	first -= p.first;
	second -= p.second;
    return *this; // Pair(this->first-p.first,this->second - p.second)
}
Pair& Pair::operator+ (int x)
{
	first +=x;
	return *this;
}
Pair& Pair::operator+ (double x)
{
	second +=x;
	return *this;
}
ostream& operator<< (ostream& out, const Pair& p)
{
	return (out << p.first << " : "<<  p.second << endl);
}
istream& operator>> (istream& in,  Pair& p)
{
	int first; double second;
	cout << "first?"; in >> p.first;
	cout << "second?"; in >> p.second;
	return in; 
}