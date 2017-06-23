#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int ** matrixReshape(int ** nums, int nums_m, int nums_n, int r, int c, int ** columnSizes, int* returnSize)
{
	if (r * c != nums_m * nums_n) {
		r = nums_m;
		c = nums_n;
	}

        int i;

        /* Return an array of arrays of size *returnSize. */
	*returnSize = r;

        /* The sizes of the arrays are returned as *columnSizes array. */
	*columnSizes = (int*) malloc(r * sizeof(int));

        int ** result = (int **) malloc(r * sizeof(int*));
        /* The sizes of the arrays are returned as *columnSizes array. */
	for (i = 0; i < r; ++i) {
		result[i] = (int*) malloc(c * sizeof(int));
		(*columnSizes)[i] = c;
	}

	for (i = 0; i < nums_m * nums_n; ++i)
		result[i / c][i % c] = nums[i / nums_n][i % nums_n];

	return result;
}


int main()
{
        // int integer_array[2][6] = {
        //         {0, 1, 2, 3, 4, 5} ,
        //         {24, 25, 26, 27, 28, 29} };

        int i, j;
        int k;
        int rows = 2;
        int columns = 6;

        int **integer_array = malloc(rows * sizeof (int *) );

        for (k = 0; k < rows; k++) {
            integer_array[k] = malloc( columns * sizeof(int) );
        }

        for (i = 0; i < rows; i++){
                for (j = 0; j < columns; j++){

                        *(integer_array + (i * rows) + columns) = i * j;
                }
        }


        int ** result_array;
        int * col_size;
        int * result_size;

        result_array = matrixReshape(integer_array, 2, 6, 3, 4, &col_size, result_size);

        return 0;
}
