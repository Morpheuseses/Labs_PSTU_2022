#include<iostream>
using namespace std;

int main()
{
    int n, a, max, min;
    cin >> n;
    cin >> a;
    max = a;
    min = a;
    for (int i = 1; i <n; i++)
    {
        cin >> a;
        if (a > max)
        {
            max = a;
        }
        if (a < min)
        {
            min = a;
        }
    }
    cout << "max + min = " << min + max;
    return 0;
}