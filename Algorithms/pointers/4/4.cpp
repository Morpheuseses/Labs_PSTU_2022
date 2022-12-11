#include<iostream>
using namespace std;

int main()
{
    int tmp, max, min, num;
    int* ptr = &tmp;

    cout << "Введите длину последовательности: " << endl;
    cin >> num;
    
    cin >> *ptr;
    max = *ptr;
    min = *ptr;
   
    for (int i = 2; i <= num; i++)
    {
        cin >> *ptr;
        if (*ptr > max)
        {
            max = *ptr;
        }
        else if (*ptr < min)
        {
            min = *ptr;
        }
    }

    cout << "max = " << max <<  endl;
    cout << "min = " << min << endl;

    return 0;
}