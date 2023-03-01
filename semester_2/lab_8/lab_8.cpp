#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;

struct Car
{
	string brand;
	int releaseYear;
	int cost;
	string color;
};

void showfilecontent(FILE* file, int size)
{
	if (file == NULL) { return; }
	Car* arr = new Car[size];
	fread(arr,sizeof(Car),size,file);
	for (int i = 0; i < size; i++)
	{
		cout << "Brand of the car: " << arr[i].brand << endl;
		cout << "Release year of the car: " << arr[i].releaseYear << endl;
		cout << "Cost of the car: " << arr[i].cost << endl;
		cout << "Color of the car: " << arr[i].color << endl;
		cout << endl;
	}
	delete[] arr;
}
int main()
{
	FILE* f = fopen("file_1.txt", "w");
	int cnt;
	cout << "Enter count of elements you want to add: ";
	cin >> cnt;
	Car* info = new Car[cnt];
	for (int i = 0; i < cnt; i++)
	{
		cout << "Enter mark of the car: ";
		cin >> info[i].brand;
		cout << "Enter release year of the car: ";
		cin >> info[i].releaseYear;
		cout << "Enter cost of the car: ";
		cin >> info[i].cost;
		cout << "Enter color of the car: ";
		cin >> info[i].color;
		cout << endl;
	}
	fwrite(info, sizeof(Car), cnt, f);
	fclose(f);
	f = fopen("file_1.txt", "r");
	showfilecontent(f, cnt);
	fclose(f);

	cout << "Enter a release year: ";  
	int targetYear;
	cin >> targetYear;

	int* idx = new int[cnt];
	int k = 0;
	for (int i = 0; i < cnt; i++)
	{
		if (info[i].releaseYear >= targetYear)
		{
			idx[i] = 1;
			k++;
		}
	}
	Car* tmp = new Car[k];
	int k_idx = 0;
	for (int i = 0; i < cnt && k_idx < k; i++)
	{
		tmp[k_idx] = info[i];
		k_idx++;
	}
	cnt = k;
	f = fopen("tmp.txt", "w");
	fwrite(tmp, sizeof(Car), cnt, f);
	fclose(f);
	remove("file_1.txt");
	rename("tmp.txt", "file_1.txt");
	//delete[] info;
	fclose(f);
	f = fopen("file_1.txt", "r");
	showfilecontent(f,cnt);
	fclose(f);
	Car elem;
	cout << "Enter info about element you want to add at the beggining" << endl;
	cout << "Enter mark of the car: ";
	cin >> elem.brand;
	cout << "Enter release year of the car: ";
	cin >> elem.releaseYear;
	cout << "Enter cost of the car: ";
	cin >> elem.cost;
	cout << "Enter color of the car: ";
	cin >> elem.color;
	cout << endl;

	f = fopen("file_1.txt", "r");

	info = new Car[cnt];
	fread(info, sizeof(Car), cnt, f);
	fclose(f);
	cnt++;
	tmp = new Car[cnt];
	for (int i = 1; i < cnt; i++)
	{
		tmp[i] = info[i - 1];
	}
	tmp[0] = elem;
	f = fopen("file_1.txt", "w");
	fwrite(tmp, sizeof(Car), cnt, f);
	fclose(f);
	f = fopen("file_1.txt", "r");
	showfilecontent(f,cnt);
	fclose(f);
	delete[] tmp;
	delete[] info;
	fclose(f);
	return 0;
}