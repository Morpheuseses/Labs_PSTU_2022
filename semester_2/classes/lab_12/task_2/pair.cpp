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
	first += x;
	return *this;
}
Pair& Pair::operator+ (double x)
{
	second += x;
	return *this;
}
ostream& operator<< (ostream& out, const Pair& p)
{
	return (out << p.first << " : " << p.second);
}
istream& operator>> (istream& in, Pair& p)
{

	cout << "first?"; in >> p.first;
	cout << "second?"; in >> p.second;
	return in;
}
void Pair::randomize()
{
	first = rand() % 100 + 50;
	double f = (double)rand();
	second = 50 + f;
}
Pair& Pair::operator+= (const Pair& p)
{
	first += p.first;
	second += p.second;
	return *this;
}
bool Pair::operator < (const Pair& p) const
{
	if (first + second < p.first + p.second) return true;
	else return false;
}
bool Pair::operator > (const Pair& p)
{
	if (first + second > p.first + p.second) return true;
	else return false;
}
Pair& Pair::operator+ (Pair& p)
{
	first += p.getFirst();
	second += p.getSecond();
	return *this;
}
Pair& Pair::operator+ (const Pair& p)
{
	first += p.first;
	second += p.second;
	return *this;
}
bool Pair::operator!= (Pair& p)
{
	if (first != p.first && second != p.second) return true;
	else return false;
}
Pair& Pair::operator/ (int n)
{
	first /= n;
	second /= n;
	return *this;
}