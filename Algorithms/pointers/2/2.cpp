#include<iostream>
using namespace std;

int main()
{
    int a, b, sum;
    cin >> a >> b;
    
    int *ptr_a = &a;
    int *ptr_b =&b;

    sum = *ptr_a + *ptr_b;

    cout << "sum = " << sum << endl;
    return 0;
}