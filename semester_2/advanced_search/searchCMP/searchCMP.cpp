#include <iostream>
#include <string>

using namespace std;

int find(string str, string substr)
{
    int strSize, substrSize;
    strSize = str.size();
    substrSize = substr.size();

    int* pref = new int[substrSize];

    int i = 1;
    int j = 0;
    pref[0] = -1;

        if (substr[i] == substr[j])
        {
            pref[i] = pref[j];
        }
        else
        {
            pref[i] = j;
        }

        for (i = 0, j = 0; (i <= strSize - 1) && (j <= substrSize - 1); i++, j++)
        {
            while ((j >= 0) && (substr[j]) != str[i])
            {
                j = pref[j];
            }
        }
        delete[] pref;
        if (j == substrSize) { return i - j; }
        else return -1;
    
}

int main()
{
    string inputStr, subStr;
    cout << "Enter string: ";
    cin >> inputStr;
    cout << "Enter substring, which you want to find: ";
    cin >> subStr;
    int idx = find(inputStr, subStr);
    if (idx == -1) { cout << "Substring was not found:(" << endl; }
    else { cout << "Position of first symbol of substring: " << idx << endl; }
    return 0;
}