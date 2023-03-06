#include<iostream>
#include<ctime>
using namespace std;

void fillArray(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            arr[i][j] = rand() % 10;
    }
}
void showArray(int** arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void delMax(int** a, int& rows, int& cols, int max_i, int max_j)
{
    int** tmp = new int*[rows-1];
    for (int i = 0; i < rows; i++)
    {
        tmp[i] = new int[cols-1];
    }
    for (int i = 0; i < rows-1; i++)
    {
        for (int j = 0; j < cols-1; j++)
        {
            if (i < max_i and j < max_j)
            {
                tmp[i][j] = a[i][j];
            }
            if (i > max_i and j < max_j)
            {
                tmp[i][j] = a[i+1][j];
            } 
            if (i < max_i and j > max_j)
            {
                tmp[i][j] = a[i][j + 1];
            }
            if (i > max_i and j > max_j)
            {
                tmp[i][j] = a[i+1][j+1];
            }
        }
    }
    rows--;
    cols--;
    a = tmp;
}
int main()
{
    srand(time(NULL));
    int rows, cols;
    cout << "Enter rows and columns of array: ";
    cin >> rows >> cols;
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++)
    {
        arr[i] = new int[cols];
    }
    fillArray(arr, rows, cols);
    showArray(arr, rows, cols);
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
    delMax(arr, rows, cols, max_i, max_j);
    showArray(arr, rows, cols);
    delete[] arr;
    return 0;
}
