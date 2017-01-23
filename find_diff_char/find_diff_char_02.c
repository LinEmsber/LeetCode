// 3 ms, XOR method

// int a = 60;				// 60 = 0011 1100
// int b = 13;				// 13 = 0000 1101
//
// a ^ b = 49;				// 49 = 0011 0001
// a ^ b ^ a = 49 ^ a = 60			// 60 = 0000 1101

char find_diff_char(char* s, char* t)
{
	char c = t[0];
	int i = 0;

	while( s[i] )
		c = c ^ s[i] ^ t[++i];

	return c;
}
