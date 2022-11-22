#include<iostream>
using namespace std;

int main()
{
    int n;
    int r = 0;

    cin >> n;

    while (n > 0)
    {
        r = r * 10 + n % 10;
        n /= 10; 
    }
    cout << r << endl;
    return 0;
}
