#include <stdio.h>
#include <stdlib.h>

int hammingDistance(int x, int y) 
{
	int xor = x ^ y, count = 0;

	while(xor) {
		if(xor & 1) 
			count++;
		xor >>= 1;
	}

	return count;
}

int main()
{
	printf("hammingDistance(54321, 5566): %d\n", hammingDistance(54321, 5566));

	return 0;
}
