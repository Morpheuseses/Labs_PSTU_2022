#include<iostream>
using namespace std;

int main()
{
	int n; int side = 0;
	cin >> n;
	if (n < 2)
	{
		cout << "���������� ��������� ����� �������" << endl;
		return 0;
	}
	for (int i = 1; i <= n / 2 + 1; i++)
	{
		if (i * i == n)
		{
			side = i;
			break;
		}
	}
	if (side == 0)
	{
		cout << "������ ��������� ������� �� ����� ���������� ���������" << endl;
		return 0;
	}
	for (int i = 1; i <= side; i++)
	{
		cout << "    ";
		for (int j = 1; j <= side; j++)
		{
			cout << "* ";
		}
		cout << endl;
	}
	return 0;
}

