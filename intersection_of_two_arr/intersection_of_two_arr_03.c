/* Given two arrays, write a function to compute their intersection. */

#include <stdio.h>
#include <stdlib.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

 //typedef boolean bool;
typedef struct hash_node_ {

        int key;
        int data;
        struct hash_node_ *next;
} hash_node;
typedef struct hash_table_ {

        hash_node **array;
        int size;
        //hash_func_t hash_func;
} hash_table_t;



void hash_table_init(hash_table_t *ht,int size) {
        memset(ht,0,sizeof(hash_table_t));

        ht->size = size;
        ht->array = (hash_node **)malloc(sizeof(hash_node *) * size);
        int i=0;
        for(i=0;i<size;i++) {

                ht->array[i]= NULL;
        }
}

int hash_func(int key, int size) {

        if(key <0) {
            key = 0-key;
        }
        return key%size;

}

bool hash_table_insert(hash_table_t *ht,int key) {

        if(ht->size ==0) {

                return -1;
        }

        int index = hash_func(key,ht->size);
        hash_node *list  = ht->array[index], *prev = NULL;

        while(list != NULL) {

                if(list->key == key) {
                        (list->data) ++ ;
                        return true;
                }
                prev = list;
                list = list->next;

        }

        list = malloc(sizeof(hash_node));
        list->key = key;
        list->data = 1;
        list->next = NULL;

        if(prev ==NULL) {

                ht->array[index] = list;
                return true;
        }
        prev->next = list;
        return true;

}

int hash_table_find(hash_table_t *ht,int key) {

        if(ht->size ==0) {

                return -1;
        }

        int index = hash_func(key,ht->size);
        hash_node *list  = ht->array[index], *prev = NULL;

        while(list != NULL) {

                if(list->key == key) {
                        return list->data;
                }
                prev = list;
                list = list->next;

        }

        return -1;

}

bool hash_table_remove(hash_table_t *ht,int key) {

        if(ht->size ==0) {

                return -1;
        }

        int index = hash_func(key,ht->size);
        hash_node *list  = ht->array[index], *prev = NULL;
        while(list!=NULL) {

                if(list->key == key) {
                        break;
                }
                prev = list;
                list = list->next;

        }

        if(list == NULL) {
                return false;
        }

        hash_node *next = list->next;
        free(list);
        list = NULL;
        if(prev ==NULL) {
                ht->array[index] = next;
                return true;
        }

        prev->next = next;
        return true;

}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    //Find the smallest array
    int hash_size = nums1Size>nums2Size? nums2Size:nums1Size;
    int big = nums1Size>nums2Size? nums1Size:nums2Size;
    int *big_array = nums1Size>nums2Size? nums1:nums2;
    int* array = nums1Size>nums2Size? nums2:nums1;
    hash_table_t ht;
    hash_table_init(&ht,hash_size);
    int *nums = malloc(sizeof(int)*hash_size);
    *returnSize =0;
    for(int i=0;i<hash_size;i++) {

        hash_table_insert(&ht,array[i]);

    }

    for(int j=0;j<big;j++) {

        if(hash_table_find(&ht,big_array[j]) > 0) {
            nums[(*returnSize)++] = big_array[j];
            hash_table_remove(&ht,big_array[j]);
        }
    }

    return nums;

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

	// int a_1[] = {111};
	// int a_2[] = {111};

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
