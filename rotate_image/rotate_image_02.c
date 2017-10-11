#include <stdio.h>
#include <stdlib.h>

#include <time.h>

void swap(int * a, int * b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void rotate(int ** matrix, int row, int col)
{
	unsigned int i, j;
	unsigned int n = row;

	if (!matrix || !row || col == 1)
		return;

	for(i = 0; i<= n / 2; i++){
		for(j = i + 1; j < n - i; j++){
                     int temp = matrix[i][j];
		     matrix[i][j] = matrix[n-j-1][i];
		     matrix[n-j-1][i] = matrix[n-1-i][n-1-j];
	             matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
		     matrix[j][n-1-i] = temp;
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
                        // printf("%d ", matrix[i][j] );
			printf("%d ", *(*(matrix+i)+j) );
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
	int ** image = rand_matrix_generator_int(4, 4, 99, 10);
	print_matrix(image, 4, 4);

	rotate(image, 4, 4);
	print_matrix(image, 4, 4);

	return 0;
}
