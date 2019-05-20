void moveZeroes(int * nums, int numsSize)
{
	int i = 0, k = 0;
	for(i = 0; i < numsSize; i++) {
		if (*(nums + i) == 0) {
			k++;
		} else {
			*(nums + i - k) = *(nums + i);
			if (k) {
				*(nums + i) = 0;
			}
		}
	}
}

int main()
{
	int arr_1[6] = {8, 0, 0, 1, 2, 7};
	moveZeroes(arr_1, sizeof(arr_1) / sizeof(arr_1[0]));
}
