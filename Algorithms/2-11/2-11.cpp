#include<iostream>
using namespace std;

int main()
{
    int n, tmp, i; 
    bool plusFirst = false; 
    bool minusFirst = false;
    cin >> n;
    i = 1;
    while (i <= n)
    {
        cin >> tmp;
        if (!plusFirst && !minusFirst)
        {
            if (tmp > 0) { plusFirst = true; }
            else if (tmp < 0) { minusFirst = true; }
        }
    }
    if (plusFirst)
    {
        cout << "Сначала ввели положительное число";
    }
    else if (minusFirst)
    {
        cout << "Сначала ввели отрицательное число";
    }
    else
    {
        cout << "Сначала ввели нуль";
    }
}