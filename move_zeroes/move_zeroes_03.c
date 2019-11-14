#include <stdio.h>
#include <stdlib.h>

void swap_zero(int* non_zero, int* zero)
{
	*zero = *non_zero;
	*non_zero = 0;
}

void moveZeroes(int* n, int numsSize)
{
	for( int i = 0, j = 0; i < numsSize; j++, i++)
	{
		// Skip nonzero number.
		while( i < numsSize && !n[i])
			i++;
		// The end of element.
		if( i == numsSize )
			break;
		// Find the index i is a zero, and the index j hold the first nonzero number.
		if( !n[j] )
			swap_zero(n+i, n+j);
	}
}

void print_array(int *arr, int arr_len)     
{
	int i;
	for (i = 0; i < arr_len; i++){
		printf("%d ", *(arr + i ) );
	}

	printf("\n");
}

int main()
{
	int arr_1[15] = {0, 8, 0, 0, 1, 2, 7, 10, 3, 5, 0, 8, 1, 0, 39};
	print_array(arr_1, 15);
	moveZeroes(arr_1, sizeof(arr_1) / sizeof(arr_1[0]));
	print_array(arr_1, 15);
	return 0;
}
