#include<iostream>
#include<string>
using namespace std;

int main()
{
    int countC, countV;
    countC = countV = 0;

    string s;
    cin >> s;

    const char* sptr = s.c_str();
    for (int i = 0; i < s.length(); i++)
    {
        switch (*sptr)
        {
            case 'А':
            case 'Е':
            case 'И':
            case 'О':
            case 'У':
            case 'Э':
            case 'Ю':
            case 'Ы':
            case 'Я':
            case 'а':
            case 'е':
            case 'и':
            case 'о':
            case 'у':
            case 'э':
            case 'ю':
            case 'ы':
            case 'я':
                countV++;
                break;
            default:
                countC++;
                break;
        }
        *sptr++;
    }
    cout << "Количество гласных= " << countV << endl;
    cout << "Количество согласных= " << countC << endl;

    return 0;
}