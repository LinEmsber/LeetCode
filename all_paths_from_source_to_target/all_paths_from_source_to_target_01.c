#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

/* The depth-first search. */
void dfs(int ** graph, int row, int * col, int * count, int ** columnSizes, int * a, int ** num, int pos)
{
	int i;
	if( a[pos] == row - 1 )	{
		*( (*columnSizes) + (*count) ) = pos + 1;
		for( i = 0 ; i <= pos; ++i ) {
			num[*count][i] = a[i];
		}
		*count = *count + 1;
	} else {
		for( i = 0; i < col[a[pos]]; ++i ) {
			a[pos + 1] = graph[ a[pos] ][i];
			dfs(graph, row, col, count, columnSizes, a, num, pos + 1);
		}
	}
}

int ** allPathsSourceTarget(int ** graph, int graphRowSize, int * graphColSizes, int ** columnSizes, int * returnSize)
{
	int i, count = 0;
	int ** num = (int**) malloc( sizeof(int*) * 9000 );
	int * a = (int*) malloc( sizeof(int) * graphRowSize );

	*columnSizes = (int*) malloc( sizeof(int) * 9000 );

	for( i = 0; i < 9000; ++i )
		num[i] = (int*) malloc( sizeof(int) * graphRowSize );
	a[0] = 0;

	dfs(graph, graphRowSize, graphColSizes, &count, columnSizes, a, num, 0);
	*returnSize = count;

	return num;
}

int main()
{
	int * graph_object_ptr = NULL;
	int graph_object[3][3] = { {1, 2}, {3}, {3} };
	graph_object_ptr = &graph_object[0][0];

	int graph_row_size = 3;

	int * graph_col_size = NULL;
	int a = 3;

	graph_col_size = &a;
	int ** col_size = 0;
	int * return_size = 0;

	int ** return_array = allPathsSourceTarget(&graph_object_ptr, graph_row_size, graph_col_size, col_size, return_size);

	for ( int i = 0; i < **col_size; i++ ){
		for ( int j = 0; j < *return_size; j++ ){
			printf("%d ", return_array[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return 0;
}
