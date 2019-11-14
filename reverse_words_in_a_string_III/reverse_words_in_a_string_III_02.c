#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define XOR_SWAP(a, b)   ( &(a) == &(b) ) ? (a) : ( (a) ^= (b), (b) ^= (a), (a) ^= (b) )

inline int get_length(char * s)
{
	int length = 0;
	char * c = s;
	while(*c != '\0')
	{
		c = c + 1;
		length = length + 1;
	}
	return length;
}

inline void reverse_string(int b, int e, char * s)
{
	while(b < e) {
		XOR_SWAP(b, e);
		b++;
		e--;
	}
}

char * reverseWords(char* s)
{
	int i, index = 0;
        int len = get_length(s);

	for(i = 0; i <= len; i++) {

		/* When we find the space or null byte, we reverse the previous word. */
		if( (s[i] == ' ') || (s[i] == '\0') ){
			reverse_string(index, i - 1, s);
			index = i + 1;
		}

	}
	return s;
}


int main()
{
	char * input = "Let's take LeetCode contest";
	char * output = strdup(input);

	printf("Input: %s\n", input);
	output = reverseWords(output);
	printf("Onput: %s\n", output);

	return 0;
}
