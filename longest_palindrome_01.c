/* longest palindrome */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int longestPalindrome(char* s)
{
        int counts[52];
        int a = 0;
        bool b = false;

        int i = 0;
        int check_letter;
        int letter_index;

        memset( counts, 0, 52 * sizeof(int) );

        // recoard the number of each uppercase and lowercase letters
        // ASCII: A = 65, a = 97.
        while( (check_letter = s[i]) != 0 ){
                letter_index = (check_letter < 'a') ? (check_letter - 'A') : (check_letter - 'a' + 26);
                counts[letter_index]++;
                i++;
        }

        for(i = 0; i < 52; i++){

                // When the length of palindrome is even, all the characters must have appeared
                // even number of times.
                if(counts[i] % 2 == 0){
                        a += counts[i];

                // When the length of palindrome is odd, all characters must have appeared even
                // number of times, but one character would have appeared odd number of times.
                }else{
                        a += counts[i] - 1;
                        b = true;
                }
        }

        return a + b;
}

int main()
{
        char *bb = "bb";
        char *abb = "abb";
        char *bbca = "bbca";
        char *bbcab = "bbca";
        char *abccccdd = "abccccdd";

        printf("longestPalindrome(bb): %d\n", longestPalindrome(bb));
        printf("longestPalindrome(abb): %d\n", longestPalindrome(abb));
        printf("longestPalindrome(bbca): %d\n", longestPalindrome(bbca));
        printf("longestPalindrome(bbcab): %d\n", longestPalindrome(bbcab));
        printf("longestPalindrome(abccccdd): %d\n", longestPalindrome(abccccdd));
}
