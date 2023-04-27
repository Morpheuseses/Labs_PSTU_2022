#include<iostream>
#include "Pair.h"
#include "list.h"
using namespace std;

int main()
{
    Pair p(5, 1.0);
    List<Pair> l(5, p);
    cout << p << endl;
    cout << l << endl;
    return 0;
}