/* Given two arrays, write a function to compute their intersection. */

#include <stdio.h>
#include <stdlib.h>

// #define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MIN(x, y) y ^ ( ( x ^ y ) & -( x < y ) )


/* intersection, find the intersection of two integer array
 *
 * @arr_1: the first array
 * @arr_1_len: the length of array_1
 * @arr_2: the first array
 * @arr_2_len: the length of array_2
 * @return_len: the length of return array
 */
int *intersection(int* arr_1, int arr_1_len, int* arr_2, int arr_2_len, int *return_len)
{
	int i, j;					// iteration
	int token;					// a token to check the target number is in another array

	int len = MIN(arr_1_len, arr_2_len);
	int *ret_arr = (int *)malloc( sizeof(int) * len );
	int ret_arr_index = -1;

	// check each element in arr_1;
	for( i = 0; i < arr_1_len; i++){

		// initial token
		token = 0;

		// check whether the arr_1[i] in array, arr_2;
		for( j = 0; j < arr_2_len; j++){
			// printf("j: %d\n", j);

			// find the same integer
			if(arr_1[i] == arr_2[j]){
				token = 1;
				break;
			}
		}


		// save arr_1[i] into return array, ret_arr
		if ( token == 1 ){

			// avoid duplicate, compare with return array
			for(j = 0; j <= ret_arr_index; j++){
				if(ret_arr[j] == arr_1[i]) {
					break;
				}
			}

			// if j > ret_arr_index represents that arr_1[i] is not exist at return array,
			// so we save it into retrun array.
			if ( j > ret_arr_index ){
				ret_arr[++ret_arr_index] = arr_1[i];
			}
		}
	}

	// return len
	*return_len = ret_arr_index + 1;

	return ret_arr;
}


/* print out the array with specific length
 *
 * @arr: the array we want to print
 * @arr_len: the specific length of array we want to print
 */
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
	int i;
	int ret_len;

	int a_1[] = {111, 3, 7 ,30, 4, 3, 500, 5, 100, 3, 6, 4, 7, 500};
	int a_2[] = {2, 30, 1000, 3, 5, 500, 60, 4, 7};

	// int a_1[] = {111};
	// int a_2[] = {111};

	int a_1_len = sizeof(a_1) / sizeof( int );
	int a_2_len = sizeof(a_2) / sizeof( int );

	int min_len = MIN(a_1_len, a_2_len);

	printf("arr_1: ");
	print_array(a_1, a_1_len);

	printf("arr_2: ");
	print_array(a_2, a_2_len);

	printf("arr intersection: ");
	print_array(intersection(a_1, a_1_len, a_2, a_2_len, &ret_len), min_len );

	return 0;
}
