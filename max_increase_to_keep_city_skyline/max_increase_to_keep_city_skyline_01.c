
/* This is the most intuitive method to obtain the maximum total sum that the height of
 * the buildings can be increased.
 */
int maxIncreaseKeepingSkyline(int** grid, int gridRowSize, int *gridColSizes)
{
	int i, j, ans = 0;
	int * array_row = (int *) calloc( gridRowSize, sizeof(int) );
	int * array_col = (int *) calloc( *gridColSizes, sizeof(int) );

	int ** new_grid = (int **) calloc( gridRowSize, sizeof(int*) );
	for ( i = 0; i < gridRowSize; i++ ){
		new_grid[i] = (int *) calloc ( *gridColSizes, sizeof(int) );
	}

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

	/* Fill each new grid with the allowed highest floors */
	for(i = 0; i< gridRowSize; i++ )
		for( j = 0; j < *gridColSizes; j++ )
			new_grid[i][j] = array_row[i] < array_col[j] ? array_row[i] : array_col[j];

	/* Use the new grid to substract the original grid to obtain the total sum. */
	for(i = 0; i< gridRowSize; i++ )
		for( j = 0; j < *gridColSizes; j++ )
			ans += new_grid[i][j] - grid[i][j];

	return ans;
}
