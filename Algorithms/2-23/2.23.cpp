#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n, max; int num = 0; float a;
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
            num += 1;
        }
    }
    cout << num << endl;
    return 0;
}