/* assign cookie */

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

        if (left >= right)
                return;

        swap(v, left, (left + right) / 2);
        last = left;

        for (i = left + 1; i <= right; i++){

                if (v[i]<v[left]){
                    last = last + 1;
                    swap(v, last, i);
                }
        }

        swap(v, left, last);
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

        // for loop method
        // compare the integer of both array
        for(i = 0, j = 0; i < gSize && j < sSize; j++){
        	if (g[i] <= s[j]){
        		i++;
        	}
        }

        return i;
}
