#include<iostream>
#include<ctime>

using namespace std;

void sort(int* arr, int size, int left, int right);
int partition(int* arr, int size, int left, int right);
void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void fullArray(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 10;
	}
}
void showArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
int partition(int* arr, int size, int left, int right)
{
	int pivot = arr[right];
	int m = left - 1;
	for (int i = left; i <= right - 1; i++)
	{
		if (arr[i] < pivot)
		{
			m++;
			swap(arr[i], arr[m]);
		}
	}
	swap(arr[right], arr[m + 1]);
	return m + 1;
}
void sort(int* arr, int size, int left, int right)
{
	if (right > left)
	{
		int m = partition(arr, size, left, right);

		sort(arr, size, left, m - 1);
		sort(arr, size, m + 1, right);
	}

}
int main()
{
	srand(time(NULL));
	int size = 200;
	int* a = new int[size];
	fullArray(a, size);
	showArray(a, size);
	sort(a, size, 0, size - 1);
	showArray(a, size);
	delete[] a;
	return 0;
}
