#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */

char ** findWords(char ** words, int wordsSize, int* returnSize)
{
	int i, j;
	char c;
	int len;
	int row, row_1_letter;
	char ** result_words = calloc(sizeof(char *), wordsSize);
	*returnSize = 0;

	for(i = 0; i < wordsSize; ++i){

		len = strlen(words[i]);
		for( j = 0, row_1_letter = -1; j < len ;++j){

			c = words[i][j];
			/* Force all letters to uppercase. */
			if( c >= 'a' )
				c -= 32;

			switch(c){
				case 'Q':
				case 'W':
				case 'E':
				case 'R':
				case 'T':
				case 'Y':
				case 'U':
				case 'I':
				case 'O':
				case 'P':
					row = 1;
					break;
				case 'A':
				case 'S':
				case 'D':
				case 'F':
				case 'G':
				case 'H':
				case 'J':
				case 'K':
				case 'L':
					row = 2;
					break;
				case 'Z':
				case 'X':
				case 'C':
				case 'V':
				case 'B':
				case 'N':
				case 'M':
					row = 3;
					break;
				default:
					break;
			}

			/* Record the row of the first letter. */
			if( row_1_letter == -1 ){
				row_1_letter = row;

			/* If the next the row of the first letter is not consistent the first letter's row,
			 * reset the row of the first letter and break the loop.
			 */
			}else if( row_1_letter != row ){
				row_1_letter = -1;
				break;
			}
		}

		if( row_1_letter != -1 ){
			result_words[*returnSize] = words[i];
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
