/* find the majority element of an array */

#include <stdio.h>

int majority_element(int* nums, int nums_size)
{
	int i;
	int counter = 1;
	int major = nums[0];

	for (i = 1; i < nums_size; i++){

		if (nums[i] == major){
			counter ++;
		}else if (counter == 0){
			major = nums[i];
			counter ++;
		}else{
			counter --;
		}
	}
	return major;
}

int main()
{
	int num_list[10] = {8, 3, 3, 3, 1, 5, 5, 6, 5, 5};

	printf("the majority element of an array: %d\n", majority_element(num_list, 10) );

	return 0;
}
