#include <stdio.h>
#include <assert.h>

int over_the_road(int a, int n)
{
	return 2 * n - a + 1;
}

int main()
{
	assert(over_the_road(1, 3) == 6);	
	assert(over_the_road(3, 3) == 4);	
	assert(over_the_road(5, 3) == 2);
	assert(over_the_road(6, 3) == 1);
	assert(over_the_road(4, 3) == 3);
	assert(over_the_road(2, 3) == 5);

	assert(over_the_road(7, 5) == 4);
	assert(over_the_road(9, 5) == 2);

	return 0;
}
