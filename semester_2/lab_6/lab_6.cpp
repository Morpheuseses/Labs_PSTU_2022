#include<iostream>
#include<string>

using namespace std; 

int main()
{
	string s, res ="";
	getline(cin, s);
	s+=' ';
	int i = s.find(' ');
	while (s != "")
	{
		i = s.find(' ');
		bool chr = false, num = false;
		for (int j = i; j > 0; j--)
		{
			if ('9' >= s[j] && s[j] >= '0')
			{
				num = true;
			}
			if ('Z' >= s[j] && s[j] >= 'A' or 'z' >= s[j] && s[j] >= 'a')
			{
				chr = true;
			}
		}
		if (chr && num)
		{
			for (int j = 0; j < i; j++)
			{
				res += s[j];
			}
			res += ' ';
		}
		s.erase(0, i+1);
	}
	cout << res << endl;
	return 0;
}