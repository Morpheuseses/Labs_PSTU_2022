#include<iostream>
using namespace std; 

void fillArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 20;
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
void shellSort(int* arr, int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{


		for (int i = gap; i < n; i++)
		{

			int tmp = arr[i];

			int j;
			for (j = i; j >= gap && arr[j - gap] > tmp; j -= gap)
			{
				arr[j] = arr[j - gap];
			}

			arr[j] = tmp;

		}
	}
}

int main()
{
	srand(time(NULL));
	int size = 10;
	int* a = new int[size];
	fillArray(a,size);
	cout << "Before sorting: ";
	showArray(a, size);
	shellSort(a, size);
	cout << "After sorting: ";
	showArray(a, size);
	return 0; 
}