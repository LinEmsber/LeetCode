int numJewelsInStones(char* J, char* S)
{
	int i, ans = 0;
	// ASCII table, z: 122, A: 65
	int cache_arr['z' - 'A' + 1] = {0};
	unsigned int J_len = strlen(J);
	unsigned int S_len = strlen(S);

	for ( i = 0; i < J_len; i++ ){
		cache_arr[*J - 'A'] = 1;
		J++;
	}

	for ( i = 0; i < S_len; i++ ){
		ans += cache_arr[*S - 'A'] & 1;
		S++;
	}

	return ans;
}
