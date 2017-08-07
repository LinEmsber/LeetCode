/* longest palindrome */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int longestPalindrome(char  * s)
{
        int counts[52];
        int a = 0;
        bool b = false;

        int i = 0;
        int check_letter;
        int letter_index;

        memset( counts, 0, 52 * sizeof(int) );

        /* 1. Record the alphabet from the string, and distinguish uppercase and lowercase.
         * 2. When the length of the palindrome is even, all alphabet must have appeared an even number of times.
         * 3. When the length of the palindrome is odd, all alphabet must have appeared an even number of times. 
         *    Thus, it needs to be subtracted by 1.
         * 4. The alphabet is an odd number only can use once, arranging it in the middle of the string.
         * 5. The result is from two separate parts:
         *    a: The alphabet is the even number or the odd number which is subtracted by 1.
         *    b: Whether the amount of this alphabet is an odd number.
         */
        while( (check_letter = s[i]) != 0 ){
                /* ASCII: A = 65, a = 97. */
                letter_index = (check_letter < 'a') ? (check_letter - 'A') : (check_letter - 'a' + 26);
                counts[letter_index];
                counts++;
                i++;
        }

        for(i = 0; i < 52; i++){

                /* When the length of the palindrome is even. */
                if(counts[i] % 2 == 0){
                        a += counts[i];

                /* When the length of the palindrome is odd. */
                } else {
                        a += counts[i] - 1;
                        b = true;
                }
        }

        return a + b;
}

int main()
{
        char * bb = "bb";
        char * abb = "abb";
        char * bbca = "bbca";
        char * bbcab = "bbca";
        char * abccccdd = "abccccdd";

        printf("longestPalindrome(bb): %d\n", longestPalindrome(bb));
        printf("longestPalindrome(abb): %d\n", longestPalindrome(abb));
        printf("longestPalindrome(bbca): %d\n", longestPalindrome(bbca));
        printf("longestPalindrome(bbcab): %d\n", longestPalindrome(bbcab));
        printf("longestPalindrome(abccccdd): %d\n", longestPalindrome(abccccdd));
}
