#include<iostream>
using namespace std;

int main()
{
    float a, b, sum;
    cin >> a >> b;

    float *ptr_a = &a;
    float *ptr_b = &b;

    sum = *ptr_a + *ptr_b;

    cout << "sum = " << sum  << endl;
     
    return 0;
}