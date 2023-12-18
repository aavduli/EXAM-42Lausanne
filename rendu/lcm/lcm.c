#include <stdio.h>

unsigned int	gcd(unsigned a, unsigned int b)
{
	while (b != 0)
	{
		unsigned int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

unsigned int	lcm(int a,int b)
{
	if (a <= 0 || b <= 0)
		return 0;
	return (a / gcd(a, b)) * b;
}
