#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool detectCapitalUse(char* word)
{
	int i;
	int upper_count = 0;
	int length = strlen(word);
	for ( i = 0; i < length; ++i) {
		if(word[i] <= 'Z' && word[i] >= 'A')
                        upper_count++;
	}

	// All letters in this word are not capitals, or all letters in this word are capitals.
	if(upper_count == 0 || upper_count == length)
                return true;

	// Only the first letter is capital.
	else if(upper_count == 1 && (word[0] <= 'Z' && word[0] >= 'A'))
                return true;

	else return false;
}




int main()
{
        printf("detectCapitalUse(USA): %d\n", detectCapitalUse("USA"));
        printf("detectCapitalUse(leetcode): %d\n", detectCapitalUse("leetcode"));
        printf("detectCapitalUse(Google): %d\n", detectCapitalUse("Google"));
        printf("detectCapitalUse(HelloWorld): %d\n", detectCapitalUse("HelloWorld"));

        return 0;
}
