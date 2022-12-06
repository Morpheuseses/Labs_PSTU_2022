#include<iostream>
using namespace std;

int main()
{
    int a, num;
    cin >> a;

    int *ptr = &a;
    num = a;

    for (int i = num-1; i>1; i--)
    {
        *ptr *= i;
    }

    cout << "fact = " << a << endl;
    return 0;
}