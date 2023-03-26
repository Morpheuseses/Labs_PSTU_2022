#include<iostream>
#include<fstream>
#include<ctime>
#include<string>
using namespace std;

void distribution(string name1, string name2, string main)
{
	ofstream f1, f2;
	ifstream mainf;
	string tmp, curr;
	int itmp, icurr;
	mainf.open(main);
	f1.open(name1);
	f2.open(name2);
	if (!f1.is_open() || !f2.is_open()) { cout << "Oops, some file didn't open" << endl; return; }
	bool firstfile = true;
	mainf >> curr;
	while (!mainf.eof())
	{
		if (firstfile)
		{
			f1 << curr << "\n";
			tmp = curr;
			mainf >> curr;
			if (mainf.eof())
			{
				f1 << "/" << "\n";
				return;
			}
			itmp = stoi(curr);
			icurr = stoi(curr);

			while (itmp <= icurr)
			{
				if (mainf.eof())
				{
					f1 << "/" << "\n";
					return;
				}
				f1 << curr << "\n";
				tmp = curr;
				mainf >> curr;
				itmp = stoi(tmp);
				icurr = stoi(curr);
			}
			f1 << "/" << "\n";
			firstfile = false;
		}
		else
		{
			f2 << curr << "\n";
			tmp = curr;
			mainf >> curr;
			if (mainf.eof())
			{
				f2 << "/" << "\n";
				return;
			}
			itmp = stoi(tmp);
			icurr = stoi(curr);
			while (itmp <= icurr)
			{
				if (mainf.eof())
				{
					f2 << "/" << "\n";
					return;
				}
				f2 << curr << "\n";
				tmp = curr;
				mainf >> curr;
				itmp = stoi(tmp);
				icurr = stoi(curr);
			}
			f2 << "/" << "\n";
			firstfile = true;
		}
	}
	f1.close();
	f2.close();
	mainf.close();
}
void Merge(string name1, string name2, string main)
{
	distribution(name1, name2, main);
	ifstream f1, f2;
	ofstream mainf;
	string tmp1, tmp2;
	int itmp1, itmp2;
	f1.open(name1);
	f2.open(name2);
	mainf.open(main);
	if (!f1.is_open() || !f2.is_open() || !mainf.is_open()) { cout << "Oops, some file didn't open" << endl; return; }
	int i = 0, j = 0;
	while (!(f1.eof()))
	{
		f1 >> tmp1;
		f2 >> tmp2;
		if (tmp2 == "") return;
		while (tmp1 != "/" || tmp2 != "/")
		{
			if (tmp1 == "/")
			{
				mainf << tmp2 << "\n";
				f2 >> tmp2;
			}
			else if (tmp2 == "/")
			{
				mainf << tmp1 << "\n";
				f1 >> tmp1;
			}
			else
			{
				itmp1 = stoi(tmp1);
				itmp2 = stoi(tmp2);
				if (itmp1 <= itmp2)
				{
					mainf << tmp1 << "\n";
					f1 >> tmp1;
				}
				else
				{
					mainf << tmp2 << "\n";
					f2 >> tmp2;
				}
			}
		}

	}
	f1.close();
	f2.close();
	mainf.close();
	Merge(name1, name2, main);
}
int main()
{
	srand(time(NULL));
	int size, current;
	string result = "result.txt", buff = "buffer.txt", datafile = "data.txt", tmp;
	ofstream data;
	ifstream res;
	cout << "Size of an array: ";
	cin >> size;
	cout << "unsorted data" << endl;
	data.open(datafile);
	for (int i = 0; i < size; i++)
	{
		current = rand() % 100;
		cout << current << " ";
		data << current << "\n";
	}
	data.close();
	cout << endl << endl;
	Merge(result, buff, datafile);
	cout << "sorted data" << endl;
	res.open(result);
	for (int i = 0; i < size; i++)
	{
		res >> tmp;
		cout << tmp << " ";
	}
	res.close();
	cout << endl;
	return 0;
}