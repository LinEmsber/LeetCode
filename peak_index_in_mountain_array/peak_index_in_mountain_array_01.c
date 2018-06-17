int peakIndexInMountainArray(int* A, int ASize)
{
	// Use binary search to find the index of the largest number.
	int i = 0, j = ASize - 1, mid;

        while (i < j) {

                mid = i + (j - i) / 2;

		if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) {
			return mid;
		} else if (A[mid] > A[mid - 1]) {
			i = mid;
		} else {
			j = mid;
		}
	}
	return -1;
}
