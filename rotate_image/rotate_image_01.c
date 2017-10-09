#include <stdio.h>
#include <stdlib.h>

#include <time.h>

void swap(int * a, int * b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


// void rotate(int ** matrix, int row, int col)
// {
// 	int i, j;
// 	for(i = 0; i < row; i++){
// 		// for(j = 0; j < col; j++){
// 			// swap( &matrix[j][col - i], &matrix[i][j]);
// 		for(j = i + 1; j < col; j++){
// 			swap( &matrix[j][i], &matrix[i][j]);
// 		}
// 	}
// }

void rotate(int ** matrix, int row, int col)
{
	// int i, j;
	// int n = row << 1;
	// printf("h2");
	// for (i = 0; i < n / 2; ++i)
	// {
	// 	for (j = i; j < n - 1 - i; ++j)
	// 	{
	// 		int tmp = matrix[i][j];
	// 		matrix[i][j] = matrix[n-j-1][i];
	// 		matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
	// 		matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
	// 		matrix[j][n-i-1] = tmp;
	// 	}
	// }

	unsigned int r = row, c = col;

	for (r = 0; r < row; r++) {
		for (c = 0; c < col; c++) {

			// printf("c * row + (row - r - 1): %d\n", c * row + (row - r - 1));
			// *(matrix + c * row + (row - r - 1)) = *(matrix + r * col + c);
			swap((matrix + c * row + (row - r - 1)), (matrix + r * col + c));

		}
	}
}

int ** rand_matrix_generator_int( int row, int col, int max, int min)
{
        int i, j;
        int range = max - min;
        int ** matrix = matrix = (int **) malloc( row * sizeof(int*) );

	srand( (unsigned) time(NULL) );

        for ( i = 0; i < row; i++ ){
                matrix[i] = (int *) malloc( col * sizeof(int) );
                for ( j = 0; j < col; j++ ){
                        matrix[i][j] = (rand() % range) + min;
                }
        }

        return matrix;
}
void print_matrix(int ** matrix, int row, int col)
{
        int i, j;
        for ( i = 0; i < row; i++){
                for ( j = 0; j < col; j++ ){
                        printf("%d ", matrix[i][j] );
                }
                printf("\n");
        }
        printf("\n");
}

void free_matrix( int ** matrix, int row)
{
        int i;
        for (i = 0; i < row; i++)
                free(matrix[i]);

        free(matrix);
}

int main()
{
	int ** image = rand_matrix_generator_int(3, 3, 50, 0);
	print_matrix(image, 3, 3);

	rotate(image, 3, 3);
	print_matrix(image, 3, 3);

	return 0;
}
