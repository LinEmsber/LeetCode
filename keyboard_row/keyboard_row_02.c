#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

char** findWords(char** words, int wordsSize, int* returnSize)
{
	int i;
	int row;
	char * word, *p;
	bool is_in_one_row;

	/* The row index of the letters from a to z. */
	int key[26] = {2,3,3,2,1,2,2,2,1,2,2,2,3,3,1,1,1,1,2,1,1,3,1,3,1,3};
	/* The table to record the keywords which their letters are only on one row. */
	char ** result_words = (char **) malloc(sizeof(char *) * wordsSize);

	for (i = 0; i < wordsSize; i++) {

		/* The next words. */
		word = *(words + i);
		p = word;
		is_in_one_row = true;

		/* Obtain the low of the first letter. And use tolower() to force all
		 * letters to lowercase.
		 */
		row = key[tolower(*p) - 'a'];
		p++;

		while (*p) {
			if (row != key[tolower(*p) - 'a']) {
				is_in_one_row = false;
				break;
			}
			p++;
		}

		if (is_in_one_row) {
			result_words[*returnSize] = word;
			(*returnSize)++;
		}
	}

	return result_words;
}


int main()
{
	int i;
	int return_size;

	char ** result_words;
	char ** input_words = (char **) malloc( sizeof(char *) * 5);

	input_words[0] = strdup("Hello");
	input_words[1] = strdup("Alaska");
	input_words[2] = strdup("Dad");
	input_words[3] = strdup("Peace");
	input_words[4] = strdup("You");


	result_words = findWords(input_words, 5, &return_size);

	for (i = 0; i < return_size; i++)
		printf("result_words: %s\n", result_words[i]);

	for (i = 0; i < 5; i++)
		free(input_words[i]);

	free(input_words);
	free(result_words);

	return 0;
}
