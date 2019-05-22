/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize)
{
	int i;
	char ** result = (char**) malloc( sizeof(char*) * n );

	for( i = 0; i < n; i++ ) {

                if ( (i+1) % 15 == 0 ) {
			result[i] = (char*) malloc (9);
			strcpy(result[i], "FizzBuzz");

		} else if( (i+1) % 3 == 0 ) {
			result[i] = (char*) malloc (5);
			strcpy(result[i], "Fizz");

		} else if ( (i+1) % 5 == 0 ) {
			result[i] = (char*) malloc (5);
			strcpy(result[i], "Buzz");

		} else {
			result[i] = (char*) malloc ( ((i+1)/10) + 2 );
			sprintf(result[i], "%d", (i+1)); 
		}
	}

	*returnSize = n;
	return result;
}
