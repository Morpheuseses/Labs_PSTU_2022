#include<iostream>
using namespace std;

int main()
{
	int m[]{ 9,0,6,4,6,1,67,8,45,-5};
	int size = sizeof(m) / sizeof(m[0]);
	for (int i = size - 1; i > 0; i--)
	{
		for (int j = size - 1; j >= size - i; j--)
		{
			if (m[j - 1] > m[j])
			{
				int tmp = m[j];
				m[j] = m[j - 1];
				m[j - 1] = tmp;
			}
		}
	}
	for (int i = 0; i < sizeof(m) / sizeof(m[0]); i++)
	{
		cout << m[i] << endl;
	}
	return 0;
}