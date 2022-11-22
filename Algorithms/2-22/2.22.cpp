#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n, max, pos = 1; float a; 
    
    for (int i = 0; i <= n; i++)
    {
        a = sin(n+(i/n));
        if (a > max)
        {
            max = a;
        }

        pos++;
    }
    cout << max << pos << endl;
    return 0;
}