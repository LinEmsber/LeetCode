#include <stdio.h>
#include <stdlib.h>

int hammingDistance(int x, int y) 
{
	int n = x ^ y;
	int dist = 0;

	while (n) {
		++dist;
		n = n & (n - 1);
	}

	return dist;
}

int main()
{
	printf("hammingDistance(54321, 5566): %d\n", hammingDistance(54321, 5566));

	return 0;
}
