void store_int_to_string(char * str, int number)
{
	int i, remainder, length = 0, n = number;
	// Obtain the number of digits of the integer
	while (n != 0) {
		length++;
		n /= 10;
	}
	for (i = 0; i < length; i++) {
		remainder = number % 10;
		number = number / 10;
		str[length - (i + 1)] = remainder + '0';
	}
	str[length] = '\0';
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize)
{
	char ** result = (char **) malloc( sizeof(char*) * n );
	for (int i = 0; i < n; i++ ) {
		result[i] = (char*) malloc(16 * sizeof(char));
	}

	for( int i = 0; i < n; i++ ) {
		if ( (i+1) % 3 != 0 && (i+1) % 5 != 0 ) {
			store_int_to_string(result[i], i+1);
			continue;
		}

		if ( (i+1) % 3 == 0 && (i+1) % 5 != 0 ) {
			result[i] = "Fizz";
		} else if ( (i+1) % 3 != 0 && (i+1) % 5 == 0 ) {
			result[i] = "Buzz";
		} else {
			result[i] = "FizzBuzz";
		}
	}
	*returnSize = n;
	return result;
}
