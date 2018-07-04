#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

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

int ** allPathsSourceTarget(int ** graph, int graphRowSize, int * graphColSizes, int ** columnSizes, int * returnSize)
{
	int i, count = 0;
	int ** answer = (int**) malloc( sizeof(int*) * 7000 );
	int * path = (int*) malloc( sizeof(int) * graphRowSize );

	*columnSizes = (int*) malloc( sizeof(int) * 7000 );

	for( i = 0; i < 7000; ++i )
		answer[i] = (int*) malloc( sizeof(int) * graphRowSize );
	path[0] = 0;

	dfs(graph, graphRowSize, graphColSizes, &count, columnSizes, path, answer, 0);
	*returnSize = count;

	return answer;
}

int main()
{
	int * graph_object_ptr = NULL;
	int graph_object[4][3] = { {1, 2, 0}, {3, 0, 0}, {3, 0, 0}, {0, 0, 0} };
	graph_object_ptr = &graph_object[0][0];

	int graph_row_size = 3;

	int * graph_col_size_ptr = NULL;
	int graph_col_size = 3;
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
