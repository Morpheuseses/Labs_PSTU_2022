#include<iostream>
#include<ctime>
using namespace std;

void showarray(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void fullarray(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 10;
	}
}
void deleteElem(int a[], int size, int index) // not for last one
{
	for (int i = index; i < size - 1; i++)
	{
		a[i] = a[i + 1];
	}
}
int main()
{
	srand(time(NULL));
	const int SIZE = 100;
	int a[SIZE];
	int N;
	cout << "Write down a quantity of element: " << endl;
	cin >> N;
	fullarray(a, N);
	showarray(a, N);
	// 2 point
	int k; 
	cout << "Enter number of element K: " << endl;
	cin >> k;
	cout << "2 point: ";
	for (int i = k - 1, j = 1; i >= 0 && j <= N; --i, j++)
	{
		cout << a[i] << " ";
		if (i == 0)
		{
			i = N;
		}
	}
	cout << endl;
	// 3 point
	deleteElem(a, N, 0); // удаление первого элемента
	N -= 1;
	N -= 1; // удаление последнего элемента 
	cout << "3 point: ";
	showarray(a, N);
	// 4 point 
	cout << "4 point: ";
	for (int i = k - 1, j = 1; i < N && j <= N; ++i, j++)
	{
		cout << a[i] << " ";
		if (i == N - 1)
		{
			i = -1;
		}
	}
	cout << endl;
	return 0;
}