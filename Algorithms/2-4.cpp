#include<iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int n, space_count;
	cin >> n;
	if (n <= 3 || n % 2 == 0)
	{
		cout << "Число N  должно быть нечетным и > 3  " << endl;
		return 1;
	}
	space_count = n / 2+1;
	
	for (int i = 1; i <= n; i++, space_count--)
	{
		for (int j = 0; j < n+space_count; j++)
		{
			cout << " ";
		}
		for (int j = 0; j < n - space_count * 2; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}

