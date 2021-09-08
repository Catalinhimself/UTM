#include <stdio.h>
#include <math.h>

int fib1(int n)
{
	if (n < 2)
		return n;
	else
		return fib1(n - 1) + fib1(n - 2);
}

int fib2(int n)
{
	int i = 1,j = 0;
	for (int k = 1; k <= n; k++)
	{
		j = i + j;
		i = j - i;
	}
	return j;
}

int fib3(int n)
{
	int i = 1, j = 0, k = 0, h = 1;
	while (n > 0)
	{
		int t;
		if (n % 2 != 0)
		{
			t = j * h;
			j = i * h + j * k + t;
		}
		i = i * k + t;
		t = pow(h, 2);
		h = 2 * k * h + t;
		k = pow(k, 2) + t;
		n = n / 2;
	}
	return j;
}

int main()
{
	printf("%d\n", fib1(7));
	printf("%d\n", fib2(7));
	printf("%d\n", fib3(7));
	return 0;
}
