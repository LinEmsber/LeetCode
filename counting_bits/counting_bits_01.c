#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int num, int* returnSize)
{
        // num increament 1, since the index is zero base.
        num++;
        *returnSize = num;

        int i;
        int * arr = (int*) malloc( sizeof(int) * num );
        memset(arr, 0, sizeof(int) * num);

        /* 1. Check the number is even or odd. If the number is even, then the result is as same as i / 2.
         * 2. If the number is odd, then the result is as same as (i / 2) + 1.
         */
        for( i = 1; i < num; i++)
                arr[i] = (i & 1) ? arr[i >> 1] + 1 : arr[i >> 1];

        return arr;
}


int main()
{
        int i = 10;
        int returnSize;

        int * result = countBits(i, &returnSize);

        for (i = 0; i < returnSize; i++)
                printf("%d, ", result[i]);
        printf("\n");

        return 0;
}
