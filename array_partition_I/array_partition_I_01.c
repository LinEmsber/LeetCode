#include <stdio.h>
#include <stdlib.h>


void swap(int v[], int i, int j)
{
	int tmp;
	tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}


void quick_sort( int v[], int left, int right)
{
	int i, last;

	// if the index of left element is equal or larger than the index of right element.
	if (left >= right)
		return;

	// swap the most left element with the middle element
	swap(v, left, (left + right) / 2);
	// assign the last index as the most left index (the middle index)
	last = left;

	for (i = left + 1; i <= right; i++){

		if (v[i] < v[left]){
			// last = last + 1;
			// swap(v, last, i);
			swap(v, ++last, i);
		}
	}

	swap(v, left, last);

	// quick sort the left side array
	quick_sort(v, left, last-1);
	// quick sort the right side array
	quick_sort(v, last+1, right);

}

int arrayPairSum(int * nums, int nums_size)
{
	int i;
	int sum_min = 0;

	quick_sort(nums, 0, nums_size-1);

	for (i = 0; i < nums_size; i += 2) {
		sum_min += nums[i];
	}

	return sum_min;
}


int main()
{
	int number_array[20] = {93, 10, 40, 50, 99, 18, 24, 52, 12, 83,
				56, 11, 72, 77, 90, 15, 26, 7, 64, 82};

	int result;

	printf("sizeof(number_array): %zu\n", sizeof(number_array));

	result = arrayPairSum(number_array, 20);
	printf("result: %d\n", result);

	return 0;
}
