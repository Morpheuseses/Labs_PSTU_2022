#include<iostream>
using namespace std;

int main()
{
	int n; 
	cin >> n;
	if (n < 2)
	{
		cout << "Число N  должно быть > 2" << endl;
		return 0;
	}
	for (int i = 1; i <= n; i++)
	{
		cout << "     ";
		for (int j = 1; j <= i; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}

