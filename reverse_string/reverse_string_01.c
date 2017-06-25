/* Reverse String */

char* reverseString(char* s)
{

        char *start, *end;
        char tmp;

        // the starting position.
        start = s;

    	// find the last char position.
    	end = s + strlen(s) -1;

    	// reverse
    	while( start < end ){
        	tmp = *start;
        	*start = *end;
        	*end = tmp;
	        start++;
    		end--;
    	}

	return s;

}
