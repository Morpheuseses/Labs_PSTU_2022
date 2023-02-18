#include<iostream>
#include<cmath>
using namespace std; 

int power(int n)
{
	return pow(n,n);
}
double power(double n)
{
	return pow(n,1/n);
}

int main()
{
	cout << power(2) << endl;

	cout << power(2.1) << endl;
	return 0;
}