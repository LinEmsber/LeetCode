#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool judge_even(char * str, int len)
{
	int i = len / 2;
	int j = 0;

	while(j < i) {

		if(str[j] != str[i+j])
			return false;
		++j;
	}
	
	return true;
}

bool judge_odd(char * str, int len)
{
	int i = len / 3;
	int j = 2 * i;
	int k = 0;

	while(k < i) {

		if( str[k] != str[k+i] || str[k] != str[k+j] )
			return false;
		++k;
	}

	return true;
}

bool judge_prime(char * str, int len)
{
	int i;
	char pre = str[0];

	for(i = 1; i < len; ++i) {

		if(str[i] != pre)
			return false;
		pre = str[i];
	}

	return true;
}

bool repeatedSubstringPattern(char * str)
{
	int len = strlen(str);

	if(1 == len)
		return false;

	if(len % 3 == 0 && len % 2 == 0) {

		// if(judge_even(str, len))
		// 	return true;
		// return judge_odd(str, len);

		if(judge_odd(str, len))
			return true;

		return judge_even(str, len);
	}

	if(len % 3 == 0) {
		return judge_odd(str, len);
	}

	if(len % 2 == 0) {
		return judge_even(str, len);
	}

	return judge_prime(str, len);
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
