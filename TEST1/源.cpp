#include<stdio.h>
#include <math.h>

double F(double a, double b, double c, double d, double x)//�������ʽ
{
	return (((a * x + b) * x) * x + d) / c;
}

double Function(double a, double b, double c, double d, double low, double high, double e)
{
	double mid = (low + high) / 2;
	if (F(a, b, c, d, mid) == 0)
		return mid;
	while ((high - low) >= e)
	{
		mid = (low + high) / 2;
		if (F(a, b, c, d, mid) == 0)
			return mid;
		if (F(a, b, c, d, low) * F(a, b, c, d, mid) < 0)
			high = mid;
		else
			low = mid;
	}
	return low;
}