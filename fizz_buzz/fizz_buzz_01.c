/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize)
{
        int i;                  // iteration
        char **ret;             // pointer to pointer for strings

        // memory allocation for pointer to pointer
        ret = (char ** ) malloc ( n * sizeof (char **) );
        for (i = 0; i < n; i++){
                ret[i] = (char *) malloc ( sizeof (char *) );
        }

        // according to the condition to save string into pointer to char.
        for (i = 0; i < n; i++){

                if ( (i+1) % 15 == 0 ){
                        ret[i] = strdup("FizzBuzz");

                }else if ( (i+1) % 3 == 0 ){
                        ret[i] = strdup("Fizz");

                }else if ( (i+1) % 5 == 0 ){
                        ret[i] = strdup("Buzz");

                }else{
                        sprintf(ret[i], "%d", i + 1);
                }
        }

        *returnSize = n;
        return ret;
}
