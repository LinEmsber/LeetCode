#include <stdio.h>
#include <stdlib.h>

#include <ctype.h>
#include <string.h>
#include <stdbool.h>

bool detectCapitalUse(char const *p)
{
        // The first letter is capital.
	if (0 != isupper(*p++)) {

                // All letters in this word are capitals.
		if (0 != isupper(*p++))
			while (0 != *p && 0 != isupper(*p))
				++p;

                // Only the first letter is capital.
		else
			while (0 != *p && 0 != islower(*p))
				++p;

	}else{
                // All letters in this word are not capitals.
                while (0 != *p && 0 != islower(*p))
                        ++p;
        }

        // If the *p is null byte means that all letters of this word are under the correct usage of capitals.
	return (0 == *p);
}

int main()
{
        printf("detectCapitalUse(USA): %d\n", detectCapitalUse("USA"));
        printf("detectCapitalUse(leetcode): %d\n", detectCapitalUse("leetcode"));
        printf("detectCapitalUse(Google): %d\n", detectCapitalUse("Google"));
        printf("detectCapitalUse(HelloWorld): %d\n", detectCapitalUse("HelloWorld"));

        return 0;
}
