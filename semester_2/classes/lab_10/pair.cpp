#include "pair.h"


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
Pair::Pair()
{
	first = second = 0;
}
Pair Pair::operator- (Pair& p)
{
	first -= p.first;
	second -= p.second;
	return *this;
}
Pair Pair::operator+ (int c)
{
	first += c;
	return *this;
}
Pair Pair::operator+ (double c)
{
	second += c;
	return *this;
}
Pair& Pair::operator= (const Pair& p)
{
	first = p.first;
	second = p.second;
	return *this;
}
ostream& operator << (ostream& out, Pair& p)
{
	out << p.first << ":" << p.second << endl;
	return out;
}
istream& operator >> (istream& in, Pair& p)
{
	cout << "first?"; in >> p.first;
	cout << "second?"; in >> p.second;
	return in;
}

fstream& operator << (fstream &fout, Pair& p)
{
	fout << p.getFirst() << ' ' << p.getSecond() << '\n';
	return fout;
}
fstream& operator >> (fstream& fin, Pair& p)
{
	fin >> p.first;
	fin >> p.second;
	return fin;
}