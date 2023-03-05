#include<iostream>
#include<ctime>
using namespace std;

void fillArray(int** a, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
	{
        for (int j =0; j < cols; j++)
		arr[i] = rand() % 10;
	}
}
void showArray(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
        for (int j = 0; j < cols; j++)
		{
            cout << arr[i] << " ";
        }
        cout << endl;
	}
	cout << endl;
}
int* delMax(int* a, int rows, int cols, int max_i, int max_j)
{
    int** tmp = new int*[row - 1];
    for (int i = 0; i < row - 1; i++)
    {
        tmp = new int[cols-1];
    }
    for (int i = 0; i < i_max; i++)
    {
        for (int j = 0; j  <  j_max; j++)
        {
            tmp[i] = a[i];
        }
    }
    for (int i = i_max + 1; i < row - 1; i++)
    {
        for (int j = max_j + 1; j  <  cols - 1; j++)
        {
            tmp[i] = a[i];
        }
    }
    return tmp;
}
int main()
{
    int rows, cols;
    cout << "Enter rows and columns of array: ";
    cin >> rows >> cols;
    int** arr = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }
    fillArray(a, rows, cols);
    showArray(a,rows,cols);
    int max = arr[0][0];
    int max_i = 0, max_j = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }
    arr = delMax(arr, rows, cols, max_i, max_j);
    rows--; 
    cols--;
    showArray(a,rows,cols);
    return 0;
}
