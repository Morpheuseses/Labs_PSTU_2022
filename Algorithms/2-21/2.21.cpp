#include<iostream>
using namespace std;

int main()
{
    int num, prenum; bool ordered = true;
    cin >> prenum;
    while (num != 0)
    {
        cin >> num;
        if ((num < prenum) && (num != 0))
        {
         ordered = false;
        }
        prenum = num;
    }
    if  (ordered) {cout << "Числа упорядочены по возрастанию" << endl;}
    else {cout << "Числа не упорядочены" << endl;}
    return 0;
}