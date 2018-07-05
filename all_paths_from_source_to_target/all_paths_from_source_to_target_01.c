#include <stdio.h>
#include <stdlib.h>


/* The depth-first search. */
void dfs(int ** graph, int row, int * col, int * count, int ** columnSizes, int * path, int ** answer, int pos)
{
	int i;
	if( path[pos] == row - 1 )	{
		*( (*columnSizes) + (*count) ) = pos + 1;
		for( i = 0 ; i <= pos; ++i ) {
			answer[*count][i] = path[i];
		}
		*count = *count + 1;
	} else {
		for( i = 0; i < col[path[pos]]; ++i ) {
			path[pos + 1] = graph[ path[pos] ][i];
			dfs(graph, row, col, count, columnSizes, path, answer, pos + 1);
		}
	}
}

/*
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int ** allPathsSourceTarget(int ** graph, int graphRowSize, int * graphColSizes, int ** columnSizes, int * returnSize)
{
	/* Create the array of arrays and count */
	int count = 0;
	int ** array_of_arrays = (int**) malloc( sizeof(int*) * 10000 );
	int * each_array = (int*) malloc( sizeof(int) * graphRowSize );

	/* Initialize the array of arrays. */
	for( int i = 0; i < 10000; i++ )
		array_of_arrays[i] = (int*) malloc( sizeof(int) * graphRowSize );
	for( int i = 0; i < graphRowSize; i++ )
		each_array[i] = NULL;

	/* The sizes of each_array are returnd as *columnSizes array. */
	*columnSizes = (int*) malloc( sizeof(int) * 10000 );

	/* Conduct DFS. */
	dfs(graph, graphRowSize, graphColSizes, &count, columnSizes, each_array, array_of_arrays, 0);

	*returnSize = count;

	return array_of_arrays;
}

int main()
{
	int i, j;
	int * graph_object_ptr = NULL;
	int graph_object[4][2] = { {1, 2}, {3, 0}, {3, 0}, {0, 0} };

	for ( i = 0; i < 4; i++ ) {
		for ( j = 0; j < 2; j++ ) {
			printf("graph_object[%d][%d] = %d\n", i,j, graph_object[i][j] );
		}
	}

	graph_object_ptr = &graph_object[0][0];

	int graph_row_size = 4;

	int * graph_col_size_ptr = NULL;
	int graph_col_size = 2;
	graph_col_size_ptr = &graph_col_size;

	int ** col_size_ptr = NULL;
	int * col_size = 0;
	col_size_ptr = &col_size;

	int * return_size_ptr = NULL;
	int return_size = 0;
	return_size_ptr = &return_size;

	int ** return_array = allPathsSourceTarget(&graph_object_ptr, graph_row_size, graph_col_size_ptr, col_size_ptr, return_size_ptr);

	// for ( int i = 0; i < **col_size; i++ ){
	// 	for ( int j = 0; j < *return_size; j++ ){
	// 		printf("%d ", return_array[i][j]);
	// 	}
	// 	printf("\n");
	// }
	// printf("\n");

	return 0;
}
