#include<iostream>
using namespace std;

int main()
{
	int m[]{ 9,0,6,4,6,1,67,8,45,5 };
	for (int i = 0; i < sizeof(m) / sizeof(m[0])-1; i++)
	{
		int min = i;
		for (int j = i; j < sizeof(m) / sizeof(m[0]); j++)
		{
			if (m[j] < m[min])
			{
				min = j;
			}
			int tmp = m[i];
			m[i] = m[min];
			m[min] = tmp;
		}
	}
	for (int i = 0; i < sizeof(m) / sizeof(m[0]); i++)
	{
		cout << m[i] << endl;
	}
	return 0;
}