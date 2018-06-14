#include <stdio.h>
#include <stdlib.h>

int maxIncreaseKeepingSkyline(int** grid, int gridRowSize, int *gridColSizes)
{
	int i, j, ans = 0;
	int * array_row = (int *) calloc( gridRowSize, sizeof(int) );
	int * array_col = (int *) calloc( *gridColSizes, sizeof(int) );

	/* Find the highest buildings in the line of each rows. */
	for( i = 0; i < gridRowSize; i++ )
		for( j = 0; j < *gridColSizes; j++ )
			if( array_row[i] < grid[i][j] )
				array_row[i] = grid[i][j];

	/* Find the highest buildings in the line of each columns. */
	for( j = 0; j < *gridColSizes ; j++ )
		for( i = 0; i < gridRowSize; i++ )
			if( array_col[j] < grid[i][j] )
				array_col[j] = grid[i][j];

	/* 1. The allowed increased floors is the less value between its highest value of row and column.
	 * 2. Sum of each differece value between the original grid and the new grid.
	 */
	for(i = 0; i< gridRowSize; i++ )
		for( j = 0; j < *gridColSizes; j++ )
			ans += (array_row[i] < array_col[j] ? array_row[i] : array_col[j]) - grid[i][j];

	return ans;
}

int main()
{
	int i;
	int col_size = 4;
	int row = 4;
	int * row_size;
	row_size = &row;


	int ** city_map = (int **) calloc( 4, sizeof(int*) );
	for ( i = 0; i < 4; i++ ){
		city_map[i] = (int *) calloc ( 4, sizeof(int) );
	}

	city_map[0][0] = 3;
	city_map[0][1] = 0;
	city_map[0][2] = 8;
	city_map[0][3] = 4;
	city_map[1][0] = 2;
	city_map[1][1] = 4;
	city_map[1][2] = 5;
	city_map[1][3] = 7;
	city_map[2][0] = 9;
	city_map[2][1] = 2;
	city_map[2][2] = 6;
	city_map[2][3] = 3;
	city_map[3][0] = 0;
	city_map[3][1] = 3;
	city_map[3][2] = 1;
	city_map[3][3] = 0;

	printf("maxIncreaseKeepingSkyline(city_map, 4, 4): %d\n", maxIncreaseKeepingSkyline( city_map, col_size, row_size));

	return 0;
}
