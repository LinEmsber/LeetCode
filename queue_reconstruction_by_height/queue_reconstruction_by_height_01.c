#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


/* A safe free function.  */
void _safe_free(void **pp)
{
	if (pp != NULL && *pp != NULL){
		free(*pp);
		*pp = NULL;
	}
}
#define safe_free(p) _safe_free( (void**) &p )

/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct LinkedNode {
	int height;
	int position;
	struct LinkedNode * next;
} list;

int cmp_function(const void * first, const void * second)
{
	int * a = *(int**) first;
	int * b = *(int**) second;

	if (a[0] > b[0])
		return 0;
	else if (a[0] < b[0])
		return 1;
	/* If if (a[0] == b[0]), then compare the second element. */
	else
		return ( a[1] < b[1] ) ? 0 : 1;
}

int ** reconstructQueue(int ** people, int peopleRowSize, int peopleColSize, int * returnSize)
{
	int i, j;
	int ** result = (int **) malloc(sizeof(int*) * peopleRowSize);

	list * current, * tmp;
	list * head = (list *) malloc( sizeof(list) );

	*returnSize = peopleRowSize;
	head->height = 0;
	head->position = 0;
	head->next = NULL;

	/* 1. According the people's height to sort the array. If two people are the same height,
         * then compare the number of people who have a height greater than or equal to (e.g. the
         * second element).
         * 2. Find the proper position for them be stored into the queue (e.g. the number of the
         * people higher or equal than this person).
         *
         * Original: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
	 * After qsort: [[7,0], [7,1], [6,1], [5,0], [5,2], [4,4]]
	 * After reconstruction: [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
	 */

	qsort(people, peopleRowSize, sizeof(int *), cmp_function);

	/* Sort the people's height. Store them in to a linked list. */
	for(i = 0; i < peopleRowSize; i++){

		current = head;
		/* Find the proper position for this node. */
		for(j = 0; j < people[i][1]; j++){
			if (!current)
				break;
			current = current->next;
		}

		tmp = (list*) malloc ( sizeof(list) );
		tmp->height = people[i][0];
		tmp->position = people[i][1];

		/* Insert this new node into the proper position. */
		tmp->next = current->next;
		current->next = tmp;
	}

	current = head;
	/* Restore the sorted linked list to the array. */
	for(i = 0; i < peopleRowSize; i++){

		result[i] = (int*) malloc( sizeof(int) * 2 );
		result[i][0] = current->next->height;
		result[i][1] = current->next->position;

		current = current->next;
	}

	/* free the linked list. */
	current = head;

	while (current){
		tmp = current;
		current = current->next;
		free(tmp);
	}

	return result;
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
	int ** matrix = (int **) malloc( 6 * sizeof(int*) );
	int ** result_matrix;

	int return_size = 0;

	for ( i = 0; i < 6; i++ )
		matrix[i] = (int *) malloc( 2 * sizeof(int) );

	matrix[0][0] = 7;
	matrix[0][1] = 0;
	matrix[1][0] = 4;
	matrix[1][1] = 4;
	matrix[2][0] = 7;
	matrix[2][1] = 1;
	matrix[3][0] = 5;
	matrix[3][1] = 0;
	matrix[4][0] = 6;
	matrix[4][1] = 1;
	matrix[5][0] = 5;
	matrix[5][1] = 2;

	print_matrix(matrix, 6, 2);
	result_matrix = reconstructQueue(matrix, 6, 2, &return_size);
	print_matrix(result_matrix, 6, 2);

	free_matrix(matrix, 6);
	free_matrix(result_matrix, 6);

	return 0;
}
