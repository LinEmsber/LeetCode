int numberOfLines(int * widths, int widthsSize, char * S, int * returnSize)
{
	int sum = 0;
	*returnSize = 2;
	int * ans = (int *)malloc(*returnSize * sizeof(int));
	ans[0] = 0;
	ans[1] = 0;

	for(int i = 0; S[i] != '\0'; i++){
		if( sum + widths[S[i] - 'a'] > 100 ){
			sum = widths[S[i] - 'a'];
			ans[0] += 1;
		}
		else{
			sum += widths[S[i] - 'a'];
		}
	}

	ans[0] += 1;
	ans[1] = sum % 100;

	return ans;
}
