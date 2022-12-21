#include<iostream>
#include<math.h>
#include<cmath>

int main()
{
	//10 вариант: 0,1x^2 - xlnx = 0 [1,2]
	// y' = 0,2x-lnx-1
	// y'' = 0.2 - 1/x
	double x, xPrev, eps = 0.000001;
	//f(b) * f''(b) > 0
	// (0.2 - 0 - 1) * (0.2 - 0.5) > 0 => x0 = b
	x = 2;
	xPrev = 0;
	while (abs(xPrev-x) > eps)
	{
		xPrev = x;
		x = xPrev - (0.1*pow(xPrev,2)-x*log(xPrev))/(0.2*xPrev-log(x)-1);
	}
	std::cout << "Root: " << x << std::endl;
	return 0;
}