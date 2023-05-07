#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Pair
{
private:
	int first;
	double second;
public:
	Pair();
	Pair(int f, double s);
	Pair(const Pair&);
	~Pair() {};
	[[nodiscard]] int getFirst() { return first; }
	[[nodiscard]] double getSecond() { return second; }
	[[nodiscard]] void setFirst(int f) { first = f; }
	[[nodiscard]] void setSecond(double s) { second =  s; }
	Pair operator- (Pair&);
	Pair operator+ (int c);
	Pair operator+ (double c);
	Pair& operator= (const Pair&);
	friend std::istream& operator >> (std::istream &in, Pair& p);
	friend std::ostream& operator << (std::ostream &out, Pair&);

	friend fstream& operator>>(fstream &fin, Pair& p);
	friend fstream& operator<<(fstream &fout, Pair& p);
};