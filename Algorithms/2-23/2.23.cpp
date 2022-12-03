#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n, max; int count = 0; float a;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        a = sin(n + (i/n));
        if (a > max)
        {
            max = a;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        a = sin(n + (i/n));
        if (a == max)
        {
            count += 1;
        }
    }
    cout << "Максимальный элемент "<< max << " Его количество " << count << endl;
    return 0;
}