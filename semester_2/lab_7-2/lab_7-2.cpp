#include<iostream>
#include<stdarg.h>
// 
void convert_oct_dec(int n, ...)
{
	va_list factor;
	va_start(factor, n);
	for (int i = 0; i < n; i++)
	{
		int tmp = va_arg(factor, int);
		int sum = 0;
		int q = 1;
		while (tmp > 0)
		{
			if (tmp % 10 == 8 or tmp % 10 == 9)
			{
				std :: cout << "You entered wrong number, try again" << std::endl;
				return;
			}
			sum += tmp % 10 * q;
			tmp /= 10;
			q *= 8;
		}
		std :: cout << sum << " ";
		
	}
	va_end(factor);
}
int main()
{	
	convert_oct_dec(2, 45, 67);
	std:: cout << std:: endl;
	convert_oct_dec(3, 70, 4, 231);
	return 0;
}
