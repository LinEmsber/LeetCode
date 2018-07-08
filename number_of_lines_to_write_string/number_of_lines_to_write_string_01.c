/* Use while loop. */
int numberOfLines(int * widths, int widthsSize, char * S, int * returnSize)
{
        int i = 0;
	int lines = 0, total = 0;

	while(S[i]) {
		total += widths[S[i] - 'a'];
		if (total > 100) {
			lines = lines + 1;
			total = widths[S[i] - 'a'];
		}
		i++;
	}

	*returnSize = 2;
	int * ans = (int *)malloc(sizeof(int) * (*returnSize));

	ans[0] = lines + 1;
	ans[1] = total;

	return ans;
}
