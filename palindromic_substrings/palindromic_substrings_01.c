#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countSubstrings(char * s)
{
        int i, j;
        int count = 0, len = strlen(s);

        for( i = 0; i < len; i++ ) {

                for( j = 0; i-j >= 0 && i+j < len && s[i-j] == s[i+j]; j++ )
                        count++; //substring s[i-j, ..., i+j]

                for( j = 0; i-1-j >= 0 && i+j < len && s[i-1-j] == s[i+j]; j++ )
                        count++; //substring s[i-1-j, ..., i+j]
        }

        return count;
}

int main()
{
        printf("countSubstrings(abc): %d\n", countSubstrings("abc"));
        printf("countSubstrings(aaa): %d\n", countSubstrings("aaa"));

        return 0;
}
