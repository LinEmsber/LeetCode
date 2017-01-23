/* assign cookie */

#define XOR_SWAP_2(a, b)	( ( (a) == (b) ) || ( ( (a) ^= (b) ), ( (b) ^= (a) ), ( (a) ^= (b) ) ) )

void quick_sort( int v[], int left, int right)
{
        int i, last;

        if (left >= right)
                return;

        XOR_SWAP_2( v[left], v[(left + right) / 2] );
        last = left;

        for (i = left + 1; i <= right; i++){

                if (v[i] < v[left]){
                    last = last + 1;
                    XOR_SWAP_2(v[last], v[i]);
                }
        }

        XOR_SWAP_2(v[left], v[last]);
        quick_sort(v, left, last-1);
        quick_sort(v, last+1, right);

}

int findContentChildren(int* g, int gSize, int* s, int sSize)
{
        // iteration
        int i = 0, j = 0;

        // sort the both array
        quick_sort(g, 0, gSize - 1);
        quick_sort(s, 0, sSize - 1);

        // while loop method
        // compare the integer of both array
        while (  i < gSize && j < sSize ){
                if (g[i] <= s[j]){
        		i++;
        	}
        	j++;
        }

        return i;
}
