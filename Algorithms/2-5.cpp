#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n < 2)
	{
		cout << "Нельзя построить такой квадрат" << endl;
		return 0;
	}
	cout << endl;
	cout << "    ";
	for (int i = 1; i <= n; i++)
	{
		cout << "*";
	}
	for (int j = 2; j < n; j++)
	{
		cout << "    ";
		cout << "*" << endl;
	}
	cout << "    ";
	for (int i = 1; i <= n; i++)
	{
		cout << "*";
	}
	return 0;
}