int numJewelsInStones(char* J, char* S) 
{
	int i;
	int ans = 0;
	int f[256] = {0};
	unsigned int J_len = strlen(J);
	unsigned int S_len = strlen(S);

	for ( i = 0; i < J_len; i++ ){
		f[*J] = 1;
		J++;
	}

	for ( i = 0; i < S_len; i++ ){
		ans += f[*S] & 1;
		S++;
	}

	return ans;
}
