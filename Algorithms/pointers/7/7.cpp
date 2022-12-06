#include<iostream>
using namespace std;

int main()
{
    int n, n_new;
    int *ptr = &n;
    
    cout << "Введите значение переменной n:" << endl;
    cin >> n;

    cout << "Ввежите новое значение переменной:" << endl;
    cin >> n_new;
    *ptr = n_new;

    cout << "Новое значение переменной n = " << n << endl;
    return 0;
}