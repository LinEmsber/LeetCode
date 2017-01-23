int islandPerimeter(int** grid, int gridRowSize, int gridColSize)
{
        if ( grid == NULL || gridRowSize == 0 || gridColSize == 0 ){
                return 0;
        }

        int i, j;
        int num;
        int perimeter = 0;

        for ( i = 0; i < gridRowSize; i++ ) {
                for ( j = 0; j < gridColSize; j++ ) {

                        if ( grid[i][j] == 1 ) {

                                // initial primeter
                                int num = 4;

                                // check up
                                if ( (i > 0 && grid[i-1][j] > 0) )
                                        num--;
                                // check left
                                if ( j > 0 && grid[i][j-1] > 0)
                                        num--;

                                // check the next row exist, and check down
                                if ( i < gridRowSize-1 && grid[i+1][j] > 0 )
                                        num--;

                                // check the next column exist, and check right
                                if ( j < gridColSize-1 && grid[i][j+1] > 0 )
                                        num--;
                                perimeter += num;
                        }
                }
        }
        return perimeter;
}
