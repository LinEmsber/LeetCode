#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_length(char * s)
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

/* Reverse String */
char* reverseString(char* s)
{
	/* The starting position. */
	int start = 0;
	/* Find the last char position. */
	int end =  get_length(s)-1;

	while( start < end ){
		*(s+start) = *(s+start) ^ *(s+end);
		*(s+end) = *(s+start) ^ *(s+end);
		*(s+start) = *(s+start) ^ *(s+end);

		start++;
		end--;
	}

	return s;
}

int main()
{
	char * original_string = "Hello World";
	char * reverse_string = strdup(original_string);

	printf("Original string: %s\n", original_string);
	printf("Reverse string: %s\n", reverseString(reverse_string));

	return 0;
}
