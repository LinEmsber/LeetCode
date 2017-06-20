#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool check_substring(char * s, int substring_len)
{
	char * p = s;

	while(*p != 0){

		/* Compare each of substring. */
		if (memcmp(p, s, substring_len) != 0)
			return false;

		/* Move to the next substring. */
		p += substring_len;
	}

	return true;
}

bool repeatedSubstringPattern(char * s)
{
	if (s == NULL)
		return false;

	int i;
	int len = strlen(s);

	for (i = 2; i <= len; ++i){

		/* If the len can be divided, we check the all of substrings are the same or not. */
		if(len % i == 0) {
			if (check_substring(s, len / i))
				return true;
		}
	}

	return false;
}


int main()
{
	printf("repeatedSubstringPattern(abaababcaab): %d\n", repeatedSubstringPattern("abaababcaab"));
	printf("repeatedSubstringPattern(hellohello): %d\n", repeatedSubstringPattern("hellohello"));
	printf("repeatedSubstringPattern(ddddQdddd): %d\n", repeatedSubstringPattern("ddddQdddd"));
	printf("repeatedSubstringPattern(PPPPPPPP): %d\n", repeatedSubstringPattern("PPPPPPPP"));
	printf("repeatedSubstringPattern(barZbbbbar): %d\n", repeatedSubstringPattern("barZbbbbar"));
	printf("repeatedSubstringPattern(foofoofoofoo): %d\n", repeatedSubstringPattern("foofoofoofoo"));

	return 0;
}
