/* Partition Array by Odd and Even. */

#include <stdio.h>
#include <stdlib.h>

void partitionArray(int * num_array, int length)
{
	if (num_array == NULL)
		return;

	int left = 0;
	int right = length - 1;

	while (left < right) {

		/* Find the most left odd number. */
		while (left < right && num_array[left] % 2 != 0)
			left++;
		
		/* Find the most right even number. */
		while (left < right && num_array[right] % 2 == 0)
			right--;

		/* Swap. */
		if (left < right) {
			int temp = num_array[left];
			num_array[left] = num_array[right];
			num_array[right] = temp;
		}
	}
}


int main()
{
        int i;
        int arr[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
        int arr_length = ( sizeof(arr) / sizeof(arr[0]) ) - 1;
        printf("len: %d\n", arr_length);

        printf("Origin: \n");
        for(i = 0; i < arr_length; i++)
                printf("%d ",arr[i]);
        printf("\n");

        partitionArray(arr, arr_length);

        printf("After: \n");
        for(i = 0; i < arr_length; i++)
                printf("%d ",arr[i]);
        printf("\n");

        return 0;
}

