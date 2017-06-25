/* minimum move to equal array elements */

#include <stdio.h>

// Adding 1 to (n-1) elements is equivalent to subtracting 1 from one of the elements and adding 1 to all elements.
// We must find the min number of (subtract 1 from any element) operations.
// The only way to make all elements equal this way is to make them all equal to the min element of the array.
// Hence, number of moves = sum(array) - n * min_element.

int minMoves(int* num_arr, int numsSize)
{
        if (numsSize <= 1)
                return 0;

        int i;
        int min_num = num_arr[0];
        long sum = num_arr[0];

        for(i = 1; i < numsSize; i++){

                if ( min_num > num_arr[i] ){
                        min_num = num_arr[i];
                }

                sum += num_arr[i];
        }
        return sum - min_num * numsSize;
}

int main()
{
        int int_arr[3] = {1, 1, 2147483647};
        printf("minMoves( [1,1,2147483647] ): %d\n", minMoves(int_arr, 3) );
}
