#include <stdio.h>

int numJewelsInStones(char* J, char* S)
{
	/* Check the string */
	if(J == NULL || S == NULL)
		return 0;

	int i, ans = 0;
	/* The sizeof long long int is 8 byte, e.g. 64 bits. */
	unsigned long long int cache_arr = 0;

	for ( i = 0; J[i] != '\0'; i++){
		cache_arr |= (unsigned long long int)1 << (J[i] - 'A');
	}

	for ( i = 0; S[i] != '\0'; i++){
		if(cache_arr & (unsigned long long int)1 << (S[i] - 'A') ){
			ans++;
		}
	}

	return ans;
}

int main()
{
	char * J_arr = "aAa";
	char * S_arr = "aAAbbbb";

	printf("numJewelsInStones: %d\n", numJewelsInStones(J_arr, S_arr) );

	return 0;
}
