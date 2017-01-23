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

                                // add 1
                                perimeter++;

                                // check the next row exist, and check down
                                if ( i < gridRowSize-1 && grid[i+1][j] == 1 )
                                        border++;

                                // check the next column exist, and check right
                                if ( j < gridColSize-1 && grid[i][j+1] == 1 )
                                        border++;
                        }
                }
        }
        return (perimeter * 4) - (border * 2);
}
