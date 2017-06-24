#include <stdio.h>
#include <stdlib.h>

typedef struct _matrix MATRIX;
struct _matrix {
	int ** matrix;
	int row;
	int column;
};

MATRIX * create_matrix( int rows, int columns, int base_number)
{
	int i, j;
	int counter = base_number;

	// Dynamically create 2D array and add data to it from input stream
	int ** matrix = (int **) calloc( rows, sizeof( int* ) );

	for( i = 0; i < rows; i++ ) {
		matrix[i] = (int *) calloc( columns, sizeof( int ) );

		for( j = 0; j < columns; j++ ) {
			matrix[i][j] = counter;
			counter++;
		}
	}

	// save the martix into MATRIX structure
	MATRIX * m = (MATRIX *) malloc( sizeof( MATRIX ) );

	m -> matrix = matrix;
	m -> row = rows;
	m -> column = columns;

	return m;
}

void print_matrix( int ** matrix, int row, int column )
{
	int i, j;
	for( i = 0; i < row; i++ ) {
		for( j = 0; j < column; j++ ) {
			printf( "%4d", matrix[i][j] );
		}
		printf("\n");
	}
}



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
	int ** matrix_reshaped;
	int * col_size;
	int result_size;

	MATRIX * matrix_orig = create_matrix(5, 6, 10);

	printf("The origin martix:\n");
	print_matrix(matrix_orig->matrix, 5, 6);

	/* *col_size@3 = {10, 10, 10};
	 * result_size = 10;
	 */
	matrix_reshaped = matrixReshape(matrix_orig->matrix, 5, 6, 3, 10, &col_size, &result_size);

	printf("The reshaped martix:\n");
	print_matrix(matrix_reshaped, 3, 10);

	return 0;
}
