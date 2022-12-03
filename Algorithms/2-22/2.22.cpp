#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n, max, pos_first, pos_last; float a; 
    
    cin >> n;

    max = sin(n + 1/n);

    for (int i = 0; i <= n; i++)
    {
        a = sin(n+(i/n));
        if (a > max)
        {
            max = a;
            pos_first = i;
            pos_last = i;
        }
        else if (a == max)
        {
            pos_last = i;
        }
    }
    cout << "max = " << max << endl;
    cout << "№ Превого элемента с этим значением: " << pos_first << endl;
    cout << "№ Последнего элемента с этим значением: " << pos_last << endl;
    return 0;
}