#include<iostream>
#include<ctime>

int leneanSearch(int* a, int size, int find)
{
	int res = -1;

	for (int i = 0; i < size; i++)
	{
		if (a[i] == find)
		{
			res = i + 1;
		}
	}
	return res;
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
	int size = 10;
	int* a = new int[size];
	fillArray(a, size);
	std::cout << "Array of integer numbers " << std::endl;
	showArray(a, size);
	int find;
	std::cout << "Enter a number, you want to find: ";
	std::cin >> find;
	std::cout << "Here position of your number:" << std::endl;
	std::cout << leneanSearch(a, size, find) << std::endl;
	return 0;
}