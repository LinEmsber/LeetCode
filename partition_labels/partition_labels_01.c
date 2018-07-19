int * partitionLabels(char * S, int * returnSize)
{
	int i;
	int S_len = strlen(S);
	int record[2][26];

	int count = 0;
	int count_prev = 0;
	int * answer = (int *) malloc( sizeof(int) * S_len );

	*returnSize = 0;
	memset(record, 0, sizeof(int) * 2 * 26 );

	/* Record the first and last index of each letter from the string.
	 * record[0][x]: the first index, record[1][x]: the last index.
	 */
	for( i = 0; i < S_len; i++ ) {
		if(record[0][S[i] - 'a'] == -1) {
			record[0][S[i] - 'a'] = i;
			record[1][S[i] - 'a'] = i;
		} else {
			record[1][S[i] - 'a'] = i;
		}
	}

	/* Check the S from the first index. */
	for( i = 0; i < S_len; i++ ) {

		/* count store the last index of letter. */
		if( count < record[1][S[i] - 'a'] ) {
			count = record[1][S[i] - 'a'];
		}

		/* If count equal i, it means that is one part.
		 * The index of string is zero base, thus, each of answer needs add 1.
		 */
		if( i == count ) {
			answer[(*returnSize)] = count - count_prev + 1;
			(*returnSize)++;
			count_prev = count + 1;
		}
	}

	return answer;
}
