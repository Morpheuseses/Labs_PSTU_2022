#include<iostream>
#include<ctime>

using namespace std;

void fullArray(int* arr, int size)
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
void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void bucketSort(int* arr)
{
	const int SIZE_ARRAY = 10;
	const int CNT_B = 2;

	int buckets[CNT_B][SIZE_ARRAY];

	int bucketSizes[CNT_B]{ 0 };

	for (int i = 0; i < SIZE_ARRAY; i++)
	{
		if (arr[i] > 10)
		{
			buckets[1][bucketSizes[1]] = arr[i];
			bucketSizes[1]++;
		}
		if (arr[i] < 10)
		{
			buckets[0][bucketSizes[0]] = arr[i];
			bucketSizes[0]++;
		}
	}
	for (int i = 0; i < CNT_B; i++) {    
		int k, tmp;
		for (int j = 0; j < bucketSizes[i]; j++)
		{
			tmp = buckets[i][j];
			for (k = j - 1; k >= 0 && buckets[i][k] > tmp; k--)
			{
				buckets[i][k + 1] = buckets[i][k];
				buckets[i][k] = -999;
			}
			buckets[i][k + 1] = tmp;
		}
	}
	int idx = 0;
	for (int i = 0; i < CNT_B; i++)
	{
		for (int j = 0; j < bucketSizes[i]; j++)
		{
			arr[idx++] = buckets[i][j];
		}
	}
}


int main()
{
	srand(time(NULL));
	int size = 10;
	int* a = new int[size];
	fullArray(a, size);
	showArray(a, size);
	bucketSort(a);
	showArray(a, size);
	return 0;
}