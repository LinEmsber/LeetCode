/* assign cookie */

#define XOR_SWAP_2(a, b)	( ( (a) == (b) ) || ( ( (a) ^= (b) ), ( (b) ^= (a) ), ( (a) ^= (b) ) ) )

/* shell sort
 * @arr: integer array
 * @len: length of array
 */
void shell_sort(int *arr, int len)
{
	int i, j;
	int gap;

	for (gap = len / 2; gap > 0; gap = gap / 2){

		for (i = gap; i < len; i++){

			for (j = i - gap; j >= 0 && arr[j] > arr[ j + gap ]; j = j - gap){

				XOR_SWAP_2( arr[j], arr[ j + gap ] );
			}

		}
	}
}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
        // iteration
        int i = 0, j = 0;

        // sort the both array
        shell_sort(g, gSize);
        shell_sort(s, sSize);

        // compare the integer of both array
        for(i = 0, j = 0; i < gSize && j < sSize; j++){
        	if (g[i] <= s[j]){
        		i++;
        	}
        }

        return i;
}
