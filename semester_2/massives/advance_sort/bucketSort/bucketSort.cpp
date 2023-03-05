#include<iostream>
#include<ctime>

using namespace std;

void fullArray(int* arr, int size)
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
void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}
void bucketSort(int* arr, int size)
{
	int cnt_b = 2; // >10, <10 - 2 buckets 
	int** bucket = new int*[cnt_b];
	for (int i = 0; i < size; i++)
	{
		bucket[i] = new int[cnt_b];
	}
	int* sizes = new int[cnt_b];
	for (int i = 0; i < cnt_b; i++)
	{
		sizes[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		int bucketindex = arr[i] / cnt_b;
		bucket[bucketindex][sizes[bucketindex]] = arr[i];
		sizes[bucketindex]++;
	}
	for (int i = 0; i < cnt_b; i++)
	{
		for (int j = 0; j < sizes[i]; j++)
		{
			for (int k = j; k > 0 && bucket[j][k-1] > bucket[j][k]; k--)
			{
				swap(bucket[j][k - 1], bucket[j][k]);
			}
		}
	}
	int index = 0;
	for (int i =0; i < cnt_b; i++)
		for (int j = 0; j < sizes[i]; j++)
		{
			arr[index++] = bucket[i][j];
		}
}


int main()
{
	srand(time(NULL));
	int size = 10;
	int* a = new int[size];
	fullArray(a, size);
	showArray(a, size);
	bucketSort(a, size);
	showArray(a, size);
	return 0;
}