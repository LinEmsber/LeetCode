#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int islandPerimeter(int** grid, int gridRowSize, int gridColSize)
{
        if ( grid == NULL || gridRowSize == 0 || gridColSize == 0 ){
                return 0;
        }

        int i, j;
        int border = 0;
        int perimeter = 0;

        for ( i = 0; i < gridRowSize; i++ ) {
                for ( j = 0; j < gridColSize; j++ ) {

                        if ( grid[i][j] == 1 ) {

                                perimeter++;

                                /* Check if the right side grid is exist or not. */
                                if ( i < gridRowSize-1 && grid[i+1][j] == 1 )
                                        border++;

                                /* Check if the down side grid is exist or not. */
                                if ( j < gridColSize-1 && grid[i][j+1] == 1 )
                                        border++;
                        }
                }
        }

        return (perimeter * 4) - (border * 2);
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

/* A safe free function.  */
void _safe_free(void **pp)
{
	if (pp != NULL && *pp != NULL){
		free(*pp);
		*pp = NULL;
	}
}
#define safe_free(p) _safe_free( (void**) &p )


void free_matrix( int ** matrix, int row)
{
	int i;
	for (i = 0; i < row; i++)
		safe_free(matrix[i]);

	safe_free(matrix);
}

int main()
{
        int i;
        int row = 4;
        int col = 4;

        int ** grid = (int **) malloc( sizeof(int *) * row );
        for (i = 0; i < row; i++)
                grid[i] = (int *) malloc( sizeof(int) * col );

        grid[0][0] = 0;
        grid[0][1] = 1;
        grid[0][2] = 0;
        grid[0][3] = 0;
        grid[1][0] = 1;
        grid[1][1] = 1;
        grid[1][2] = 1;
        grid[1][3] = 0;
        grid[2][0] = 0;
        grid[2][1] = 1;
        grid[2][2] = 0;
        grid[2][3] = 0;
        grid[3][0] = 1;
        grid[3][1] = 1;
        grid[3][2] = 0;
        grid[3][3] = 0;

        print_matrix(grid, row, col);

        printf("perimeter: %d\n", islandPerimeter(grid, row, col));

        free_matrix(grid, row);

        return 0;
}
