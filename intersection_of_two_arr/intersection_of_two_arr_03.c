/* Given two arrays, write a function to compute their intersection. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MIN(x, y) y ^ ( ( x ^ y ) & -( x < y ) )

/* structure and typedef */
typedef struct _hash_node {
	int key;
	int data;
	struct _hash_node * next;
} hash_node_t;

typedef struct _hash_table {
	struct _hash_node ** array;
	int size;
} hash_table_t;

/* function declaration */
void hash_table_init(hash_table_t * ht, int size);
int hash_func(int key, int size);
bool hash_table_insert(hash_table_t * ht, int key);
int hash_table_find(hash_table_t * ht, int key);
bool hash_table_remove(hash_table_t * ht, int key);


/* function */
void hash_table_init(hash_table_t * ht, int size)
{
	int i = 0;
	memset(ht, 0, sizeof(hash_table_t));

	ht->size = size;
	ht->array = (hash_node_t **) malloc(sizeof(hash_node_t *) * size);

	for(i = 0; i < size; i++) {
		ht->array[i]= NULL;
	}
}

int hash_func(int key, int size)
{
	if(key < 0) {
		key = 0 - key;
	}

	return key % size;
}

bool hash_table_insert(hash_table_t * ht, int key)
{
	if(ht->size == 0)
		return -1;

	int index = hash_func(key, ht->size);
	hash_node_t * list = ht->array[index];
	hash_node_t * prev = NULL;

	while(list != NULL) {

		if(list->key == key) {
			(list->data) ++ ;
			return true;
		}
		prev = list;
		list = list->next;
	}

	list = malloc(sizeof(hash_node_t));
	list->key = key;
	list->data = 1;
	list->next = NULL;

	if(prev == NULL) {
		ht->array[index] = list;
		return true;
	}
	prev->next = list;

	return true;
}

int hash_table_find(hash_table_t * ht, int key)
{
	if(ht->size == 0)
		return -1;

	int index = hash_func(key, ht->size);
	hash_node_t * list = ht->array[index];
	hash_node_t * prev = NULL;

	while(list != NULL) {
		if(list->key == key) {
			return list->data;
		}
		prev = list;
		list = list->next;
	}

	return -1;
}

bool hash_table_remove(hash_table_t * ht, int key)
{
	if(ht->size ==0)
		return -1;

	int index = hash_func(key, ht->size);
	hash_node_t * list = ht->array[index];
	hash_node_t * prev = NULL;

	while(list != NULL) {
		if(list->key == key) {
			break;
		}
		prev = list;
		list = list->next;
	}

	if(list == NULL)
		return false;

	hash_node_t * next = list->next;
	free(list);
	list = NULL;
	if(prev == NULL) {
		ht->array[index] = next;
		return true;
	}
	prev->next = next;

	return true;
}

/* intersection of two array */
int * intersection(int * nums1, int nums1Size, int * nums2, int nums2Size, int * returnSize)
{
	int i, j;

	/* Find the longer and the shorter arrays. */
	int short_array_len = nums1Size > nums2Size ? nums2Size : nums1Size;
	int long_array_len = nums1Size > nums2Size ? nums1Size : nums2Size;
	int * long_array = nums1Size > nums2Size ? nums1 : nums2;
	int * short_array = nums1Size > nums2Size ? nums2 : nums1;

	/* Create the hash table with the size of short array. */
	hash_table_t ht;
	hash_table_init(&ht, short_array_len);

	/* The maximum length of the same_array is equal the length of short array. */
	int * same_array = malloc(sizeof(int) * short_array_len);
	*returnSize = 0;

	/* Insert the elements of short array into hash table. */
	for(i = 0; i < short_array_len; i++) {
		hash_table_insert(&ht, short_array[i]);
	}

	for(j = 0; j < long_array_len; j++) {

		/* If find the same element in the hash table, remove it from hash talbe and store it into same_array. */
		if( hash_table_find(&ht, long_array[j]) > 0 ) {
			same_array[(*returnSize)] = long_array[j];
			(*returnSize)++;
			hash_table_remove(&ht, long_array[j]);
		}
	}

	return same_array;
}

/* print out the array with specific length
 *
 * @arr: the array we want to print
 * @arr_len: the specific length of array we want to print
 */
void print_array(int *arr, int arr_len)
{
	int i;
	for (i = 0; i < arr_len; i++){
		printf("%d ", *(arr + i ) );
	}

	printf("\n");
}

int main()
{
	int * result_array;
	int ret_len;

	int a_1[] = {111, 3, 7 ,30, 4, 3, 500, 5, 100, 3, 6, 4, 7, 500};
	int a_2[] = {500, 2, 3, 30, 1000, 3, 5, 500, 60, 4, 7};

	int a_1_len = sizeof(a_1) / sizeof( int );
	int a_2_len = sizeof(a_2) / sizeof( int );

	int min_len = MIN(a_1_len, a_2_len);

	printf("arr_1: ");
	print_array(a_1, a_1_len);

	printf("arr_2: ");
	print_array(a_2, a_2_len);

	result_array = intersection(a_1, a_1_len, a_2, a_2_len, &ret_len);

	printf("arr intersection: ");
	print_array(result_array, min_len );

	free(result_array);

	return 0;
}
