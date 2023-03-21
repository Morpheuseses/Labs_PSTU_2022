#include<iostream>
#include<ctime>

using namespace std;

int find(int* a, int key, int left, int right)
{
	while ((a[left] < key) && (a[right] > key))
	{
		if (a[left] == a[right]) 
			break;
	    int mid = left + ((key - a[left]) * (right - left)) / (a[right] - a[left]);
		if (a[mid] < key) { left = mid + 1; }
		if (a[mid] > key) { right = mid - 1;  }
		if (a[mid] == key) { return mid; }
	}
	if (a[left] == key) { return left; }
	if (a[right] == key) { return right; }
	return -1;
}
void sort(int* a, int size)
{
	int j, tmp;
	for (int i = 1; i < size; i++)
	{
		tmp = a[i];
		for (j = i - 1; j >= 0 && a[j] > tmp; j--)
		{
			a[j + 1] = a[j];
			a[j] = -999;
		}
		a[j + 1] = tmp;
	}
}
void fillArray(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		a[i] = rand() % 10;
	}
}
void showArray(int* a, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << a[i] << " ";
	}
	std::cout << std::endl;
}
int main()
{
	srand(time(NULL));
	int size = 10, toFind, left = 0, right = size;
	int* a = new int[size];
	cout << "Enter the number you want to find: " << endl;
	cin >> toFind;
	fillArray(a, size);
	cout << "Unsorted Array" << endl;
	showArray(a, size);
	sort(a, size);
	cout << "Sorted Array" << endl; 
	showArray(a, size);
	cout << "Position of the element:\n" << find(a, toFind, left, right-1) + 1 << endl;
	return 0;
}