#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool repeatedSubstringPattern(char * s)
{
	int i = 1, j = 0;
	int n = strlen(s);

#ifdef _DEBUG
	int k;
#endif
	/* Create an mark array to store the mark of the string. */
	int * mark_array = malloc( sizeof(int) * (n + 1) );
	memset(mark_array, 0, sizeof(int) * (n + 1));

	while( i < n ){

		/* Find the first char of the sencond substring, s[i] == s[j]. */
		if( s[i] == s[j] )
			mark_array[++i] = ++j;

		/* If s[i] is not equal s[j] and j is equal 0 (e.g. We not yet find the
		 * fisrt s[i] == s[j] ), only move the position of i.
		 */
		else if( j == 0 )
			i++;

		/* If s[i] is not equal s[j] and j is not equal 0, then we set the j as the pervious
		 * mark number.
		 */
		else
			j = mark_array[j];

#ifdef _DEBUG
		printf("mark_array:");
		for (k = 0; k < n + 1; k++)
			printf(" %d", mark_array[k]);
		printf("\n");
#endif

	}

	return mark_array[n] && ( ( mark_array[n] % (n - mark_array[n]) ) == 0 );
}

int main()
{
	printf("repeatedSubstringPattern(abc): %d\n", repeatedSubstringPattern("abaababcaab"));
	printf("repeatedSubstringPattern(hellohello): %d\n", repeatedSubstringPattern("hellohello"));
	printf("repeatedSubstringPattern(dddddddd): %d\n", repeatedSubstringPattern("ddddQdddd"));
	printf("repeatedSubstringPattern(coolabccool): %d\n", repeatedSubstringPattern("barZbbbbar"));
	printf("repeatedSubstringPattern(foofoofoofoo): %d\n", repeatedSubstringPattern("foofoofoofoo"));

	return 0;
}
