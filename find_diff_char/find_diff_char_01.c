// 0 ms, normal sum method

#include <stdio.h>


char find_diff_char(char* s, char* t)
{
	int sum = 0;
	int i = 0;

	// while( s[i] !='\0' ){
	// 	sum += t[i] - s[i];
	// 	i++;
	// }

	while( s[i] !='\0' ){

		sum += t[i] - s[i++];
		printf("sum: %d\n", sum);
	}

	printf("t[%d]: %d\n", i, t[i]);


	return sum + t[i];
}


int main()
{
	char *str_1 = "abcd";
	char *str_2 = "abecd";

	printf("find_diff_char: %d\n", find_diff_char(str_1, str_2) );
	printf("find_diff_char: %c\n", find_diff_char(str_1, str_2) );

	return 0;
}
