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

int cmp_function(const int * first, const int * second)
{
	int * a = *(const int**) first;
	int * b = *(const int**) second;

	if(a[0] > b[0])
		return 0;
	else if(a[0] < b[0])
		return 1;
	else
		return (a[1] < b[1]? 0 : 1);
}

int ** reconstructQueue(int ** people, int peopleRowSize, int peopleColSize, int* returnSize)
{
	int i, j;
	int ** result = (int **) malloc(sizeof(int*) * peopleRowSize);

	list * tmp, * tmp2;
	list * head = (list *) malloc( sizeof(list) );
	head->height = 0;
	head->position = 0;
	head->next = NULL;

        /* void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*)) */
	qsort(people, peopleRowSize, sizeof(int*), cmp_function);

	*returnSize = peopleRowSize;

	for(i = 0; i < peopleRowSize; i++){

		tmp = head;
		for(j = 0; j < people[i][1]; j++){
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


int main()
{
        int ** array[5][2] = {{7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}};
        int * return_size;

        reconstructQueue(array, 5, 2, &return_size);

        return 0;
}
