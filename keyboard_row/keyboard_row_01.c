/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int is_in_row(char * row, int length, char row_3)
{
	int i;
	int alphabet;
	for (i = 0; i < length; i++) {
		alphabet = row[i];
		if (alphabet == row_3 || (alphabet == row_3 + 32)) {
			return 1;
		}
	}
	return 0;
}

char** findWords(char** words, int wordsSize, int* returnSize)
{
	char row_1[10] = {'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'};
	char row_2[9] = {'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'};
	char row_3[7] = {'z', 'x', 'c', 'v', 'b', 'n', 'm'};

	int i, j;
	int row, is_in_one_row;
	char * word;
	int size = 0;
	char ** rows = (char **) malloc(sizeof(char *) * wordsSize);

	for (int i = 0; i < wordsSize; i++) {

		word = words[i];
		j = 0;
		row = 0;
		is_in_one_row = 1;

		while (word[j] != '\0') {

			if (row == 0) {

				if (is_in_row(row_1, 10, word[j])) {
					row = 1;
					continue;
				}
				if (is_in_row(row_2, 9, word[j])) {
					row = 2;
					continue;
				}
				if (is_in_row(row_3, 7, word[j])) {
					row = 3;
					continue;
				}

			} else {

				if ((is_in_row(row_1, 10, word[j]) && row != 1) || (is_in_row(row_2, 9, word[j]) && row != 2) || (is_in_row(row_3, 7, word[j]) && row != 3)) {
					is_in_one_row = 0;
					break;
				}

			}
			j++;
		}

		if (is_in_one_row) {
			rows[size] = word;
			size++;
		}

	}
	
	*returnSize = size;
	return rows;
}


