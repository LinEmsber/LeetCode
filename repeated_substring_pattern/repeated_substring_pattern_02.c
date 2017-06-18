#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool repeatedSubstringPattern(char * s)
{
	int substring_len, j, k;
	int substring_number = 0;
	int len = strlen(s);

	/* If a string includes substrings, the number of the substrings at least is two.
	 * Thus, the maximum of length of the first substring is len / 2.
	 */
	for( substring_len = 1; substring_len <= len / 2; substring_len++ ){

		substring_number = 0;

		/* The length of the string must be the multiple of the substring. */
		if( len % substring_len != 0 )
			continue;

		/* According to the length of the substring, we compare the letter of each substring from the
		 * first to the last. Thus, the j = j + substring_len.
		 */
		for( j = 0; j <= len - substring_len; j = j + substring_len ){

			for( k = 0; k < substring_len; k++ ){

				if( s[k] != s[j + k] )
					break;

				if( k == (substring_len - 1) )
					substring_number ++;

			}
		}

		if( substring_number == (len / substring_len) ){
			printf("substring_number: %d\n", substring_number);
			return 1;
		}
	}

	return 0;
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
