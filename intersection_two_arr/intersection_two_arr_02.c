/* Given two arrays, write a function to compute their intersection. */

#include <stdio.h>
#include <stdlib.h>

#define MIN(x, y)	y ^ ( ( x ^ y ) & -( x < y ) )
#define SWAP(a, b)	( ( (a) == (b) ) || ( ( (a) ^= (b) ), ( (b) ^= (a) ), ( (a) ^= (b) ) ) )

/* quick sort
 *
 * @numbers: the number of integer want to sort
 * @begin: the begin index of array
 * @end: the end index of array
 */
void sort(int* numbers, int begin, int end)
{
	int l = begin;
	int r = end;
	int v = numbers[l+(r-l)/2];

	while(l <= r)
	{
		while(numbers[l] < v) l++;
		while(numbers[r] > v) r--;
		if(l <= r)
		{
			SWAP(*(numbers + l), *(numbers + r));
			l++;
			r--;
		}
	}

	if(begin < r)
		sort(numbers, begin, r);

	if(l < end)
		sort(numbers, l, end);
}


/* intersection, find the intersection of two integer array
 * Using quick sort to two arrays.
 *
 * @arr_1: the first array
 * @arr_1_len: the length of array_1
 * @arr_2: the first array
 * @arr_2_len: the length of array_2
 * @return_len: the length of return array
 */
int *intersection(int* arr_1, int arr_1_len, int* arr_2, int arr_2_len, int *return_len)
{

	int len = MIN(arr_1_len, arr_2_len);
	int* arr = (int *) malloc( sizeof(int) * len ); //the size of the result will at most be size;
	int ret_arr_index = -1;
	int index_1 = 0, index_2 = 0;

	// sort arrays
	sort(arr_1, 0, arr_1_len-1);
	sort(arr_2, 0, arr_2_len-1);

	while(index_1 < arr_1_len && index_2 < arr_2_len)
	{
		// compare the integers of two arrays
		if(arr_1[index_1] > arr_2[index_2]){
			index_2++;

		}else if(arr_1[index_1] < arr_2[index_2]){
			index_1++;

		// only collect the equal integers
		}else{
			//avoid duplicates;
			if(ret_arr_index==-1 || arr[ret_arr_index] != arr_1[index_1]){
				arr[++ret_arr_index] = arr_1[index_1];
			}

			// the index of two arrays move forward one.
			index_1++;
			index_2++;
		}
	}

	*return_len = ret_arr_index+1;
	return arr;
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
