#include<iostream>
using namespace std;


void fillArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}
void showArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl << endl;
}
void countSort(int* arr, int size)
{
	int* count;
	int* output = new int[size];

	int max =arr[0];

	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	count = new int[max + 1];
	for (int i = 0; i < max + 1; i++)
	{
		count[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		count[arr[i]]++;
	}
	for (int i = 1; i < max + 1; i++)
	{
		count[i] += count[i - 1];
	}
	for (int i = size - 1; i >= 0; i--)
	{
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}
	for (int i = 0; i < size; i++)
	{
		arr[i] = output[i];
	}
	delete[] count;
	delete[] output;
}

int main()
{
	srand(time(NULL));
	int size = 10;
	int* a = new int[size];
	fillArray(a, size);
	showArray(a,size);
	countSort(a, size);
	showArray(a, size);
	return 0;
}