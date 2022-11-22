#include<iostream>
using namespace std;

int main()
{
    int num, prenum; bool flag = true;
    cin >> num >> prenum;
    while (num != 0)
    {
        cin >> num;
        if ((num < prenum) && (num != 0))
        {
            flag = false;
        }
        prenum = num;
    }
    if (flag) {cout << "Числа упорядочены по возрастанию" << endl;}
    else {cout << "Числа не упорядочены" << endl;}
    return 0;
}