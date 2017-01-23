/* assign cookie */

/* merge arrays L and R into arr.
 * @lefCount: number of elements in L
 * @right_length: number of elements in R.
 */
void merge_array(int *arr, int *L, int left_length, int *R, int right_length)
{
        // i: the index of left aubarray, L
        // j: the index of right sub-raay, R
        // k: the index of merged subarray, arr
        int i = 0, j = 0, k = 0;

        // compare the two sub array and fill the larger element into the array, until
        // one of array's elements are filled out.
        while(i < left_length && j < right_length) {
                if( L[i] < R[j] )
                        arr[k++] = L[i++];
                else
                        arr[k++] = R[j++];
        }

        while(i < left_length)
                arr[ k++ ] = L[ i++ ];

        while(j < right_length)
                arr[ k++ ] = R[ j++ ];

}

/* Recursive function to sort an array of integers.
 * @arr: integer array
 * @len: length of array
 */
void meger_sort(int *arr, int len)
{
        int i;                  // iteration
        int mid, *L, *R;        // middle element, left and right sub-array.

        // base condition. If the array has less than two element, do nothing.
        if(len < 2)
                return;

        // find the mid index. ( even number / 2 = (even number - 1) / 2 )
        mid = len / 2;

        // create left and right subarrays
        // left sub-array: mid elements, from index 0 till mid-1
        // right sub-array: (len-mid) elements, from mid to len-1
        L = (int*) malloc ( mid * sizeof(int) );
        R = (int*) malloc ( (len - mid) * sizeof(int) );

        // creating left subarray
        for(i = 0; i < mid; i++)
                L[i] = arr[i];

        // creating right subarray
        for(i = mid; i < len; i++)
                R[i-mid] = arr[i];

        // sorting the left subarray
        meger_sort(L, mid);
        // sorting the right subarray
        meger_sort(R, len-mid);

        // Merging L and R into arr as sorted list.
        merge_array(arr, L, mid, R, len-mid);

        free(L);
        free(R);
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
        // iteration
        int i = 0, j = 0;

        // sort the both array
        meger_sort(g, gSize);
        meger_sort(s, sSize);

        // compare the integer of both array
        for(i = 0, j = 0; i < gSize && j < sSize; j++){
        	if (g[i] <= s[j]){
        		i++;
        	}
        }

        return i;
}
