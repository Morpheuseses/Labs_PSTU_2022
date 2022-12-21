#include<iostream>
#include<math.h>
#include<cmath>

int main()
{
	//10 вариант: 0,1x^2 - xlnx = 0
	double a, b, c, eps = 0.000001, fA, fB, fC;
	a = 1; b = 2;
	while (b - a > eps)
	{
		c = (a + b) / 2;
		fA = pow(a,2)*0.1 - a * log(a);
		fB = pow(b,2)*0.1 - b * log(b);
		fC = pow(c,2)*0.1 - c * log(c);
		if (fA * fC < 0) { b = c; }
		else if (fB*fC < 0) { a = c; }
		else { std::cout << "Something gone wrong..." << std::endl; }
	}
	std::cout << "Roots: " << a <<"; "<< b << std::endl;
	return 0;
}