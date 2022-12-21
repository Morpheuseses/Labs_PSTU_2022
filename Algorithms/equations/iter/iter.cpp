#include<iostream>
#include<math.h>
#include<cmath>

int main()
{
	//10 вариант: 0,1x^2 - xlnx = 0
	// y' = 0,2x-lnx-1
	// r = max(0,2-ln1-1;0,4-ln2-1) = max(0,8;2,3) = 2,3
	// -1/r < lambda < 0, f'(x) > 0
	// 0 < lambda < 1/r, f'(x) < 0
	// lambda = - 1/25
	//a=1, b=2
	double x, xPrev, lambda, eps = 0.000001;
	lambda = -(1 / (0.2 - log(2) - 1)) + 0.01;
	x = 2;
	xPrev = 0;
	while (abs(xPrev-x) > eps)
	{
		xPrev = x;
		x = lambda*(0.1*pow(xPrev,2)-x*log(xPrev)) + xPrev;
	}
	std::cout << "Root: " << x << std::endl;
	return 0;
}