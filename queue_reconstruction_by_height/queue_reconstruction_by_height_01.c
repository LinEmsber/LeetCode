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

// using linked list since it is the easiest way of inserting a new element without memory copy
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

	if(a[0] > b[0])
		return 0;
	else if(a[0] < b[0])
		return 1;
	else
		return (a[1] < b[1]? 0 : 1);
}

int ** reconstructQueue(int ** people, int peopleRowSize, int peopleColSize, int * returnSize)
{
	int i, j;
	int ** result = (int **) malloc(sizeof(int*) * peopleRowSize);

	list * tmp, * tmp2;
	list * head = (list *) malloc( sizeof(list) );
	head->height = 0;
	head->position = 0;
	head->next = NULL;

        /* Original: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
         * After qsort: [[7,0], [7,1], [6,1], [5,0], [5,2], [4,4]]

         */

        /* void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*)) */
	qsort(people, peopleRowSize, sizeof(int*), cmp_function);

	*returnSize = peopleRowSize;

	/* Sort the people's height. */
	for(i = 0; i < peopleRowSize; i++){

		tmp = head;
		for(j = 0; j < people[i][1]; j++){
			if (!tmp)
				break;
			tmp = tmp->next;
		}

		tmp2 = (list*) malloc ( sizeof(list) );
		tmp2->height = people[i][0];
		tmp2->position = people[i][1];
		tmp2->next = tmp->next;
		tmp->next = tmp2;
	}

	for(i = 0; i < peopleRowSize; i++){
		result[i] = (int*) malloc( sizeof(int) * 2 );
		result[i][0] = head->next->height;
		result[i][1] = head->next->position;
		head = head->next;
	}

	return result;
}


int ** rand_matrix_generator_int( int row, int col, int max, int min)
{
        int i, j;
        int range = max - min;

        int ** matrix = matrix = (int **) malloc( row * sizeof(int*) );

        srand( (unsigned) time(NULL) );

        /* Generate the matrix. */
        for ( i = 0; i < row; i++ ){

                matrix[i] = (int *) malloc( col * sizeof(int) );

                for ( j = 0; j < col; j++ ){
                        matrix[i][j] = (rand() % range) + min;
                }
        }

        return matrix;
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
        // int ** matrix = rand_matrix_generator_int(5, 2, 100, 0);
        int ** matrix = matrix = (int **) malloc( 6 * sizeof(int*) );

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


        reconstructQueue(matrix, 6, 2, &return_size);

        free_matrix(matrix, 6);

        return 0;
}
