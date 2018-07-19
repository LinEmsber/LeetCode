int * partitionLabels(char * S, int * returnSize)
{
	int i, j, k;
	int count = 0, count_prev = 0, first = 0;
	int record[26] = {0};

	int S_len = strlen(S);
	int * answer = (int *) malloc(sizeof(int) * S_len);

	for (i = 0; i < S_len; i++) {
		memset(record, 0, sizeof(int) * 26 );

		for (j = first; j <= count_prev; j++) {
			record[S[j] - 'a']++;
		}

		for (k = S_len - 1; k > count_prev; k--) {

			if (record[S[k] - 'a']) {
				count_prev = k;
				break;

			} else {
				if (k == count_prev + 1) {
					answer[count++] = count_prev - first + 1;
					count_prev++;
					first = count_prev;
				}
			}
		}
	}

	answer[count++] = count_prev - first + 1;
	*returnSize = count;

	return answer;
}
