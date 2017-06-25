/*
 * Given an array of integers, every element appears twice except for one.
 * Find that single one.
 */

#include <stdio.h>

int single_number(int arr[], int n)
{
	int i;
	int result = 0;

	for (i = 0; i < n; i++) {

		// result = result ^ arr[i];
		result ^= arr[i];

		// printf("results: %d\n", result);
	}

	return result;
}


int main()
{
	int arr_1[7] = {3, 6, 5, 6, 3, 9, 5};
	int arr_2[3] = {3, 6, 3};

	printf("single_number: %d\n", single_number(arr_1, 7) );
	printf("single_number: %d\n", single_number(arr_2, 3) );

}
