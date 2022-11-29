#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n, sidelength;
    cin >> n;
    sidelength = sqrt(n);
    for (int i = 1; i <= sidelength; i++)
    {
        for (int j = 1; j <= sidelength; j++)
        {
            cout << "* ";
        }
        cout << endl;
    }
    return 0;
}