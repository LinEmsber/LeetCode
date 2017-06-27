#define EMPTY '.'
#define TAKEN 'X'

int countBattleships(char** board, int boardRowSize, int boardColSize)
{
        int row, col;
        int num_of_ships = 0;

        for ( row = 0; row < boardRowSize; row++) {
                for ( col = 0; col < boardColSize; col++) {

                        if (board[row][col] == TAKEN)

                                /* 1XN, Index of the row is a boundary, or its south position is empty. */
                                if ( (row == boardRowSize - 1) || (board[row + 1][col] == EMPTY) )

                                        /* NX1, Index of the column is a boundry, or its east position is empty. */
                                        if ( (col == boardColSize - 1) || (board[row][col + 1] == EMPTY) )
                                                num_of_ships ++;

                }
        }

        return num_of_ships;
}
