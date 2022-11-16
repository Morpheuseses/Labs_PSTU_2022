#include<iostream>
using namespace std;

int main()
{
    int n, a, f, q, p, s; bool b;
    cin >> n;
    cin >> s;
    f = 1;
    b = false;
    while (n > 0 && !b)
    {
        n = n / f;
        p = n % 10;
        if (p == s)
        {
            b = true;
        }
        f *= 10;
    }
    if (b)
    {
        cout << "Присутствует число s"<< endl;
    }
    {
        cout << "Отсутствует число s"<< endl;
    }
    return 0;
}