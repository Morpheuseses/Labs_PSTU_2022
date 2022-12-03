#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n, s; float a; bool flag = false;
    cin >> n >> s;
    for (int i = 0; i <= n; i++)
    {
        a = sin(n+(i/n));
        if (a == s)
        {
            flag = true;
        }
    }
    if (flag) { cout << "Среди элементов последовательности присутствует S" << endl;}
    else {cout << "Среди элементов последовательности нет S" << endl;}
    return 0;
}