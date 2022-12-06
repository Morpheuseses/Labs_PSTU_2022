#include<iostream>
using namespace std;

int main()
{
    int a, b, c;
    
    cout << "Введите значения переменных a и b: " << endl;
    cin >> a >> b;

    int *ptr_a = &a; //pointer a
    int *ptr_b = &b;

    c = a;
    ptr_a = ptr_b;
    *ptr_a = b;
    *ptr_b = c;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl; 
    return 0;
}