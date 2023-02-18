#include<iostream>
#include<ctime>
using namespace std;

void fullarray(int a[][100], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			a[i][j] = rand() % 10;
		}
	}
}

void showarray(int a[][100], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << " " << a[i][j];
		}
		cout << endl;
	}
}

int main()
{
	srand(time(NULL));
	int a[100][100];
	int row, col;
	cout << "Write down row and column size: " << endl;
	cin >> row >> col;
	fullarray(a, row, col);
	int max = -1000000000;
	cout << "Sums at columns: ";
	for (int j = 0; j < col - 1; j++)
	{
		int sum = 0;
		for (int i = 0; i < row - j - 1; i++)
		{
			sum += a[i][j];
		}
		for (int i = row; i >= row - j - 1; i--)
		{
			a[i][j] = 0; // обнуляем элементы, которые не учавствуют в суммировании
		}
		if (sum > max)
		{
			max = sum;
		}
		cout << sum << " ";
	}
	cout << endl;
	showarray(a, row, col);
	cout << "Max sum: " << max << endl;
	return 0;
}