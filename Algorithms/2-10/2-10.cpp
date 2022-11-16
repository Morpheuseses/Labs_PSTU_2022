#include<iostream>
using namespace std;

int main()
{
    int n, max, a;
    cin >> n;
    cin >> max;
    for (int i = 2; i <=n; i++)
    {
        cin >> a;
        if (a > max)
        {
            max = a;
        }
    } 
    cout << max << endl;
    return 0;
}