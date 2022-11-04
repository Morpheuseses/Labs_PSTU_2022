#include<iostream>
using namespace std;


int main()
{
    int side_length = 11;
    cout << endl;
    cout << "    ";
    for (int i = 1; i <= side_length; i++)
    {
        cout << "*";
    }
    cout << endl;
    cout << "    ";
    for (int i = 1; i <= side_length+1; i++)
    {
        if (! (i == 1 || i == 2 || i == side_length + 1))
        {
            cout << " ";
        }
        else cout << "*";
    }
    cout << endl;
    cout << "    ";
    for (int i = 1; i <= side_length + 2; i++)
    {
        if (! (i == 1 || i == 3 || i == side_length + 2))
        {
            cout << " ";
        }
        else cout << "*";
    }
    cout << endl;
    cout << "    ";
    for (int i = 1; i <= side_length+3; i++)
    {
        if (! (i == 2 || i == 3))
        {
            cout << "*";
        }
        else cout << " ";
    }
    cout << endl;
    cout << "    ";
    for (int j = 0; j < 2; j++)
    {
        for (int i = 1; i <= side_length + 3; i++)
        {
            if (! (i == 1 || i == 4 || i == side_length + 3))
            {
                cout << " ";
            }
            else cout << "*";
        }
        cout << endl;
        cout << "    ";
    }
    cout << " ";
   for (int i = 1; i <= side_length + 3; i++)
    {
        if (! (i == 1 || i == 3 || i == side_length + 2))
        {
            cout << " ";
        }
        else
        {
            cout << "*";
        }
    }
   cout << endl;
   cout << "      ";
   for (int i = 1; i <= side_length + 3; i++)
   {
       if (! (i == 1 || i == 2 || i == side_length + 1))
       {
           cout << " ";
       }
       else
       {
           cout << "*";
       }
   }
   cout << endl;
   cout << "       ";
   for (int i = 1; i <= side_length ; i++)
   {
       cout << "*";
   }
    return 0;
}