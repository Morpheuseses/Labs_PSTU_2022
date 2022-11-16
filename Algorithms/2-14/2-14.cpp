#include<iostream>
using namespace std;

int main()
{
    int n, a, f, q, p, sum;
    cin >> n;
    a = n;
    f = 1;
    sum = 0;
    while (n > 0)
    {
        n = n / f;
        p = n % 10;
        f *= 10;
        sum += p;
    }
    sum += a / (f / 10);
    cout << "sum = " << sum << endl;
    return 0;
}