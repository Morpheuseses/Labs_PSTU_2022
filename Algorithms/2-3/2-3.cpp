#include<iostream>
using namespace std;

int main()
{
	int n, s,p;
	cin >> n;
	s = 0;
	for (int i = 1; i <= n; i++)
	{
		p = 1;
		for (int j = i; j <= i*2; j++)
		{
			p *= j;
			
		}
		cout << p << endl;
		s += p;
	}
	cout << s << endl;
} // n = 5   s = 1*2 + 2*3*4 + 3*4*5*6 + 4*5*6*7*8 + 5*6*7*8*9*10