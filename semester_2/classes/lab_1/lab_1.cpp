#include<iostream>
#include<ctime>
using namespace std;

class Prog
{
public:
	float first;
	int second;
	float element(int j)
	{
		return first * pow(second,j);
	}
};

int main()
{
	Prog a;
	int j;
	cout << "Enter first element of sequence, constant division and power of it: ";
	cin >> a.first >> a.second >> j;
	cout << "Here your a_j element: " << a.element(j) << endl;
	return 0;
}