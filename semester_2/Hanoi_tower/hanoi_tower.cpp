#include<iostream>
using namespace std;

void move(char begin, char end)
{
    cout << begin << "->" << end <<endl;
}
void moveTower(int n, char begin, char end, char tmp)
{
    if (n == 0)
    {
        return;
    }
    moveTower(n-1, begin, tmp, end);
    move(begin,end);
    moveTower(n-1, tmp, end, begin);
}
int main()
{
    int n = 3; // amount of discs
    moveTower(n,'A','B','C');
    return 0;
}