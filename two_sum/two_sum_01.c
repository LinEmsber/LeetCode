/* two sum */

#include <stdio.h>
#include <stdlib.h>

/* typedef */
typedef struct hash_node hash_node_t;
typedef struct hash_table hash_table_t;

/* structure */
struct hash_node {
	int key;
	int val;
};
struct hash_table {
	int size;
	struct hash_node ** storage;
};

/* declaration */
hash_table_t * hash_create(int size);
void hash_destroy(hash_table_t * hash_table);
void hash_set_node(hash_table_t * hash_table, int key, int value);
hash_node_t * hash_search(hash_table_t * hash_table, int key);


/* function */

/* create a hash table
 *
 * @size: how many node in this hash table
 */
hash_table_t * hash_create(int size)
{
	hash_table_t * hash_table = malloc(sizeof(hash_table_t));

	hash_table->size = size;
	hash_table->storage = calloc(size, sizeof(hash_node_t*));

	return hash_table;
}

/* destory a hash table
 *
 * @hash_table: the target hash table
 */
void hash_destroy(hash_table_t * hash_table)
{
	int i;
	for( i = 0; i < hash_table->size; i++ ) {

		hash_node_t * node;
		if((node = hash_table->storage[i])) {
			free(node);
		}
	}

	free(hash_table->storage);
	free(hash_table);
}

/* according a key to insert a node which has key and value into a hash table.
 *
 * @hash_table: the target hash table
 * @key: the key
 * @value: the value
 */
void hash_set_node(hash_table_t * hash_table, int key, int value)
{
	hash_node_t * node;
	int hash = abs(key) % hash_table->size;

	// move in array until an empty node.
	// Since the empty node and hash_table->storage[hash] are must be NULL.
	while ( (node = hash_table->storage[hash]) ) {
		if (hash < hash_table->size - 1) {
			hash++;
		} else {
			hash = 0;
		}
	}

	node = malloc ( sizeof(hash_node_t) );
	node->key = key;
	node->val = value;

	hash_table->storage[hash] = node;
}

/* according a key to get the node from a hash_table
 *
 * @hash_table: the target hash table
 * @key: the key
 */
hash_node_t * hash_search(hash_table_t * hash_table, int key)
{
	int hash = abs(key) % hash_table->size;
	hash_node_t * node;

	// move in array until an empty node.
	while ( (node = hash_table->storage[hash]) ) {

		// find it
		if (node->key == key) {
			return node;
		}

		// move to the next node
		if (hash < hash_table->size - 1) {
			hash++;
		} else {
			hash = 0;
		}
	}

	return NULL;
}

int * twoSum(int * nums, int numsSize, int target, int* returnSize)
{
	int i;
	int rest = 0;

	hash_table_t * hash_table;
	hash_node_t * node;
	hash_table = hash_create(numsSize);

	int * result = (int *) malloc( sizeof(int) * 2 );

	for(i = 0; i < numsSize; i++) {

		rest = target - nums[i];
		node = hash_search(hash_table, rest);

		/* If we find the hash node of rest number. */
		if (node) {
			result[0] = node->val ;
			result[1] = i ;
			hash_destroy(hash_table);
			*returnSize = 2;
			break;

			/* If we dont find it, we store this num[i] into hash table. */
		} else {
			hash_set_node(hash_table, nums[i], i);
		}

	}

	return result;
}


int main()
{
	int arr[7] = {3, 5, 9, 10, 13, 7, 8};

	int * result;

	result = twoSum(arr, 7, 17);

	printf( "twoSum(arr, 7, 17): %d, %d\n", result[0], result[1] );

	free(result);
}
