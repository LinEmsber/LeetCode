#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int is_in_row(char * row, int row_len, char letter)
{
	int i, alphabet;
	for (i = 0; i < row_len; i++) {
		alphabet = row[i];
		/* For lowercase and uppercase. */
		if (alphabet == letter || (alphabet == letter + 32)) {
			return 1;
		}
	}
	return 0;
}

char ** findWords(char ** words, int wordsSize, int * returnSize)
{
	char row_1[10] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
	char row_2[9] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
	char row_3[7] = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};

	int i, j;
	int row, is_in_one_row;
	int size = 0;
	char * word;
	char ** result_words = (char **) malloc(sizeof(char *) * wordsSize);

	for (i = 0; i < wordsSize; i++) {

		word = words[i];
		j = 0;
		row = 0;
		is_in_one_row = 1;

		while (word[j] != '\0') {

			/* Start from the first letter, and check the row of the first letter. */
			if (row == 0) {

				if (is_in_row(row_1, 10, word[j])) {
					row = 1;
				}
				if (is_in_row(row_2, 9, word[j])) {
					row = 2;
				}
				if (is_in_row(row_3, 7, word[j])) {
					row = 3;
				}
				continue;

			/* After we ensure the row, we only need to check the specific row. */
			} else if ( row == 1 && (is_in_row(row_1, 10, word[j]) != 1) ) {
				is_in_one_row = 0;
				break;
			} else if ( row == 2 && (is_in_row(row_2, 9, word[j]) != 1) ) {
				is_in_one_row = 0;
				break;
			} else if ( row == 3 && (is_in_row(row_3, 7, word[j]) != 1) ) {
				is_in_one_row = 0;
				break;
			}
			j++;
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
