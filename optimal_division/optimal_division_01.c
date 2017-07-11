#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * optimalDivision(int * nums, int numsSize)
{
        int i;
        short b = 0;
        char buf[5];
	char * s = calloc(100 , sizeof(char));

        /* 1. Create a long enough char array for storing numbers, parenthesis, and divide symbol.
         * 2. Store the first number into array, and start the operation from the second element.
         * 3. After strcat() the first element into array, then add parenthesis between the second
         * and the last number.
         */
	sprintf(s,"%d", nums[0]);
	for( i = 1; i < numsSize; i++ ) {

		strcat(s, "/");
		if( nums[i] > 1 ) {
			if( !b && i + 1 < numsSize ) {
				strcat(s, "(");
				b = 1;
			}
		} else {
			if( b ) {
				strcat(s, ")" );
				b = 0;
			}
		}

		sprintf(buf, "%d", nums[i]);
		strcat(s, buf);
	}

	if( b )
		strcat(s, ")");

	return s;
}


int main()
{
        // int pos_int_arr[4] = {1000, 100, 10, 2};
        int pos_int_arr[4] = {1000, 2000, 1, 2000};

        int pos_int_arr_len = sizeof(pos_int_arr) / sizeof(int);

        char * result;

        result = optimalDivision(pos_int_arr, pos_int_arr_len);

        printf("optimalDivision: %s\n", result);

        return 0;
}
