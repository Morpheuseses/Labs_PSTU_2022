#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    float a, b, c, d, x1, x2;
    cin >> a >> b >> c;
    d = b*b - 4*a*c;
    
    
    if (d > 0)
    {
        x1 = (-b + sqrt(d)) / 2;
        x2 = (-b - sqrt(d)) / 2;   
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x1 << endl; 
    }
    if (d == 0)
    {
        x1 = (-b + sqrt(d)) / 2;
        cout << "x1=x2= " << x1 << endl;
    }
    if (d < 0)
    {
        cout << "Рациональных корней нет" << endl;
    }
}