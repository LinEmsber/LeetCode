#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int lengthOfLongestSubstring(char * string)
{
	int len = 0;
	char * string_end = string;
	char * tmp;
	char * char_table[128] = {0};

	while(*string_end){
	
		/* Does this character is shown or not. */
		tmp = char_table[*string_end];

		/* Store the address of this char. */
		char_table[*string_end] = string_end;

		if(tmp >= string){

			/* If the length of this substring is longer than the last one, we
			 * store the length of this longest substring,
			 */
			len = string_end - string > len ? string_end - string : len;
			string = tmp + 1;
		}

		string_end++;
	}

	/* If the string only has one letter. */
	len = string_end - string > len ? string_end - string : len;

	return len;
}


int main()
{
	lengthOfLongestSubstring("cccccc");

	return 0;
}


