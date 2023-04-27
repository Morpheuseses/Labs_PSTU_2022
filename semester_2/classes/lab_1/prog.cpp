#include<iostream>
#include<cmath>
#include ".\Prog.h"
using namespace std;

void Prog::Init(int f, double s)
{
	first = f;
	second = s;
}
void Prog::Read()
{
	cout << "first?"; cin >> first;
	cout << "second?"; cin >> second;
}
void Prog::Show()
{
	cout << "first: "<< first << endl;
	cout << "second: "<< second << endl;
}
double Prog::element(int j)
{
	return first * pow(second, j);
}